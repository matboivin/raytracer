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
