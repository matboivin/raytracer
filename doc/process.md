# Process

## Working principle

<p align="center">
  <img src="assets/rt-setup2.png" alt="rt-setup2" />
</p>

Image source: [Scratchapixel 2.0: An Overview of the Ray-Tracing Rendering Technique](https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-overview)

Ray tracing proceeds from camera position to objects and then to light sources.  
Ray tracing simulates optical effects, such as reflection and refraction, scattering, and dispersion phenomena.

Trace a path from an imaginary camera through each pixel in a virtual screen, and calculate the color of the nearest encountered object.

## Implementation

### Two main structures

- `s_app`: Represents an application to use MLX functions (then connects to the X server) and contains window and image as members
- `s_scene`: Stores scene description data which is used to generate images

### Control flow

- Handle errors: no parameter, invalid `.rt` file, invalid `--save` option
- Initialize scene struct
  - -> Connect to the X server with `mlx_init()`
- Parse a given scene description -> store data in the scene struct
- Generate image using scene data
- If `--save` option is used
  - Save the rendered image in BMP format
  - Program ends
- Else
  - Open a new window with `mlx_new_window()`
  - Display the rendered imaged in window with `mlx_put_image_to_window()`
  - Dispatch events
  - Run a loop -> listen to events
  - If the user presses SPACE
    - Switch active camera
  - If the user presses ESC or click on the window cross
    - Program ends

### Parsing

- Parse scene description -> fill scene struct
- Read the whole file without using `get_next_line()` (newline character is used as separator) -> store it in a char array
- Parse the input stored in the char array
  - Stop at each identifier and call the corresponding parsing function using an array of function pointers

### Ray tracing

- Create the Cam to World matrix
- For each pixel in the image:
  - Trace a primary ray from camera position
  - Loop over all the objects and keep the nearest one
    - Trace secondary ray, process shading
    - Retrieve the final color of the pixel
  - Else if no object has been intersected
    - Default color

## Pipeline

A [pipeline](https://en.wikipedia.org/wiki/Graphics_pipeline) is a series of processing stages in order. It can be seen as different vector spaces linked to each other by matrix transformations.

Usually, the pipeline is:  
`Camera <-> World <-> Object <-> Texture`

Read more: [Apprendre OpenGL moderne: Systèmes de Coordonnées](https://opengl.developpez.com/tutoriels/apprendre-opengl/?page=systemes-de-coordonnees)

A ray is created from the Camera Space coordinate system. It is then translated to the World Space in order to check for intersection with objects. For each object, the ray is translated to the Object Space.

1. Generate rays in Camera Space
2. Intersections in Object Space
3. World <-> Object is bidirectional

Absolute origin: `(0, 0, 0)`
- Camera Space: Camera position
- World Space: Reference point

```
world_to_obj = obj_to_world^(-1)
objnormal_to_world = world_to_obj^T
```

- [OpenGL Transformation](http://www.songho.ca/opengl/gl_transform.html)
- [Tutoriel 3 : matrices](http://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/)
- [OpenGL 101: Matrices - projection, view, model](https://solarianprogrammer.com/2013/05/22/opengl-101-matrices-projection-view-model/)

object_to_world or model view matrix:  
`translation*rotation*scaling(object_space point)`

[Scale](https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glScale.xml) > [Rotate](https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glRotate.xml) > [Translate](https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glTranslate.xml)

- 3x3 dir: product scale matrix and rotate matrix
- 4x4 pos: product scale matrix, rotate matrix and translate matrix

```
   c1  c2  c3  c4

x [Rx, Ux, Fx, Tx]
y [Ry, Uy, Fy, Ty]
z [Rz, Uz, Fz, Tz]
w [0., 0., 0., 1.]

// scaling

x [ s,  0,  0,  0]
y [ 0,  s,  0,  0]
z [ 0,  0,  s,  0]
w [ 0,  0,  0,  1]
```

## Limitations and possible improvements

For this school project, my pipeline is:  
`Camera <-> World`

For example, creating the obj_to_world and world_to_obj matrices for the triangle, given 3 vertices, is unfortunately more complicated than staying in World Space to check for intersection. A scale given in the scene file as a 3D vector would have made the implementation of the pipeline easier. Lacking time, that's why I didn't implement a `Camera <-> World <-> Object` pipeline.

My scene structure is simple. However, here is an interesting page about scene graph:  
- [Wiki: Scene graph](https://en.wikipedia.org/wiki/Scene_graph).

To read more about matrices:  
- [The Matrix and Quaternions FAQ](http://www.opengl-tutorial.org/assets/faq_quaternions/index.html)

To read more about CG:  
- [Wiki: Graphics pipeline](https://en.wikipedia.org/wiki/Graphics_pipeline)
- [Computer Graphics: Topology](https://www.as.uky.edu/blogs/tlha222/computer-graphics-topology)

