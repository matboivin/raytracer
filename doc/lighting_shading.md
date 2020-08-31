# Lighting & Shading

The goal is to produce a color for a hit point on a surface.

- [Wiki: List of common shading algorithms](https://en.wikipedia.org/wiki/List_of_common_shading_algorithms)
- [Introduction to Lighting](http://math.hws.edu/graphicsbook/c4/s1.html)
- [Wiki: Specular highlight](https://en.wikipedia.org/wiki/Specular_highlight)
- [Scratchapixel 2.0: Light Transport](https://www.scratchapixel.com/lessons/3d-basic-rendering/rendering-3d-scene-overview/introduction-light-transport)
- [Scratchapixel 2.0: Introduction to Shading](https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-shading/what-is-shading-light-matter-interaction)

## Lighting

In miniRT, we have two types of lighting in the scene file:

- [Ambient lighting](https://en.wikipedia.org/wiki/Shading#Ambient_lighting): Global level of illumination
- [Point lighting](https://en.wikipedia.org/wiki/Shading#Point_lighting): A light source from a point that emits outward in all directions.

<p align="center">
  <img src="assets/point-vs-directional-light.png" alt="light sources" />
</p>

Image source: [Introduction to Lighting](http://math.hws.edu/graphicsbook/c4/s1.html)

### Direct lighting

- Trace shadow ray from the hit point to all the light sources
  - If the ray intersects another object
    - Hit point is in shadow
  - Retrieve the final color

### Indirect lighting

- Trace secondary ray from the hit point to the scene
  - If the ray intersects another object
    - Recursive process -> compute direct and indirect lighting
    - Retrieve the amount of computed light

If a value > 1, re-set to 1.

## Shading

> Shading alters the colors of faces in a 3D model based on the angle of the surface to a light source or light sources.  
Source: [Wiki: Shading](https://en.wikipedia.org/wiki/Shading#Ambient_lighting)

<p align="center">
  <img src="assets/800px-Phong_components_version_4.png" alt="Phong equation" />
</p>

Image source: [Wiki: Phong reflection model](https://en.wikipedia.org/wiki/Phong_reflection_model)

> In computer graphics, a shading function is defined as a function which yields the intensity value of each point on the body of an object from the characteristics of the light source, the object, and the position of the observer.  
Bui Tuong Phong, 1975.

Phong shading is also called Phong interpolation or normal-vector interpolation shading.

Surface properties such as mirror, transparent or glossy are not handled in this project.

## Steps

Tangent plane to a sphere:

<p align="center">
  <img src="assets/440px-Image_Tangent-plane.svg.png" alt="Tangent to a sphere" />
</p>

Image source: [Wiki: Tangent](https://en.wikipedia.org/wiki/Tangent)

A normal is the orientation of an object at a point on that surface. A normal is like a perpendicular vector to the [tangent](https://en.wikipedia.org/wiki/Tangent) to the plane at a point.

<p align="center">
  <img src="assets/normal.png" alt="Normal" />
</p>

Image source: [Scratchapixel 2.0: Geometry](https://www.scratchapixel.com/lessons/mathematics-physics-for-computer-graphics/geometry)

- `P` : hit point
- `N` : normal at point `P`
- `L` : light direction (trace a line from `P` to light source)

Incoming or incident light direction is the light coming to the surface.

- **angle of incidence**: angle formed by `N` at `P` and `L`.

Outcoming light is reflected by a surface.

- **angle of reflection**: mirrors the angle of incidence.

The brightness of the object decreases as the angle of incidence increases.

> Lambert's Cosine Law. The amount of light that a surface receives is directly proportional to the angle between the surface normal N and the light direction L. This angle can be define mathematically as: cos(angle) = dot(normal, light dir)  
Source: [Scratchapixel 2.0: Diffuse and Lambertian Shading](https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-shading/diffuse-lambertian-shading)

### Compute lighting

For intersection, use Epsilon set to `0.00001` as `tmin` in order to avoid salt-and-pepper noise. Hit points can be above or below the surface of the object.

Source: [Advanced Topics in Computer Graphics: Shadows (PDF)](https://web.cs.wpi.edu/~emmanuel/courses/cs563/S10/talks/wk6_p2_sam_shadows.pdf)

1. Compute the hit point
2. Compute the normal at hit point (if the intersection is inside an object, inverse the vector: `N = -1 * N`)

Formula to compute sphere's normal at hit point:

```
hit_point – sphere_center
```

Formula to compute cylinder's normal at hit point:

```
(hit_point – cyl_center)  - (z_axis dot(hit_point – cyl_center) ) z_axis)
```

3. Get the light direction normalized vector `light dir = hit point - light pos`
4. Compute the angle of incidence: `dot(N, light_dir)` (both `N` and light_dir are normalized vectors)
5. If point not in shadow and the angle > 0
6. Model diffuse reflection with the [cosine of the angle](https://onlinemschool.com/math/library/vector/angl/)

```
cos = dot(v1, v2) / norm(v1) * norm(v2)
```

7. Add light contribution

```
add to final color: hit_color * (light_intensity * cos)
```

8. Add specular reflection

```
rev_raydir = -ray_dir
reflect = 2 * 
R = 2 * angle_incidence * N - light_dir
if dot(reflect, rev_raydir) > 0
  then add to final color: hit_color * (light_intensity * pow(cos, specular_coef))
```

Source: [Computer Graphics from scratch: Light](https://www.gabrielgambetta.com/computer-graphics-from-scratch/light.html)

### Shadow

- Hit point not in shadow is shaded with ambient and direct illumination
- Hit point in shadow is shaded with only ambient illumination
