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

1. Compute the normal at hit point
2. Get the view direction normalized vector (- ray dir)
3. Facing ratio: `dot(N, view_dir)`

> Lambert's Cosine Law. The amount of light that a surface receives is directly proportional to the angle between the surface normal N and the light direction L. This angle can be define mathematically as: cos(angle) = dot(normal, light dir)  
Source: [Scratchapixel 2.0: Diffuse and Lambertian Shading](https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-shading/diffuse-lambertian-shading)

```
light dir = hit point - light pos
light amount = light color * light intensity
```

Formula to compute sphere's normal at hit point:

```
hit point – sphere center
```

Formula to compute cylinder's normal at hit point:

```
(hit point – cyl center)  - (z_axis dot(hit point – cyl center) ) z_axis)
```
