# Process

## Working principle

<p align="center">
  <img src="assets/rt-setup2.png" alt="rt-setup2" />
</p>

Source: [Scratchapixel: An Overview of the Ray-Tracing Rendering Technique](https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-overview)

Ray tracing proceeds from camera position to objects and then to light sources.  
Ray tracing simulates optical effects, such as reflection and refraction, scattering, and dispersion phenomena.

Trace a path from an imaginary camera through each pixel in a virtual screen, and calculate the color of the nearest encountered object.

## Implementation

Two main structures:

- `s_app`: Represents an application to use MLX functions, connects to the X server, contains window and image as members
- `s_scene`: Stores scene description parsed data which is used to generate images

Control flow:

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

- Set up a virtual viewport to know if ray intersects the view frame
- For each pixel in the image:
  - Cast a primary ray from camera position
  - If a ray intersects an object (loop over all the objects)
    - At the intersection point between the ray and the object, identify the object
    - Cast secondary ray, process shading
    - Retrieve the final color of the pixel
  - Else
    - Default color

## Pipeline

A [pipeline](https://en.wikipedia.org/wiki/Graphics_pipeline) is a series of processing stages in order. It can be seen as different vector spaces linked to each other by matrix transformations.

Usually, the pipeline is:  
`Camera <-> World <-> Object <-> Texture`

In my case:  
`Camera <-> World <-> Object`

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

- [Scale](https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glScale.xml)
- [Rotate](https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glRotate.xml)
- [Translate](https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glTranslate.xml)

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

- [The Matrix and Quaternions FAQ](http://www.opengl-tutorial.org/assets/faq_quaternions/index.html)

## Object intersections

[Primitives](https://en.wikipedia.org/wiki/Geometric_primitive) are simple geometric shapes such as a cube, cylinder, sphere, ...  
A [quadric](https://en.wikipedia.org/wiki/Quadric) is a surface in a (D + 1)-dimensional space.

> The class of quadrics (surfaces that can be defined by a quadratic equation) include cylinders, cones, ellipsoids, paraboloids, etc. Note that spheres and planes are a special subclass but have faster routines as special cases. For these we will use the parametric ray formulation and the implicit surface equation for the quadratics.  
The general quadric surface equation is  
`F(x, y, z) = Ax2 + By2 + Cz2 + Dxy+ Exz + Fyz + Gx + Hy + Iz + J = 0`  
Source: [Ray - Quadric Intersection](http://skuld.bmsc.washington.edu/people/merritt/graphics/quadrics.html)

```
intersection point = ray origin + t * ray direction
```

When solving quadratic equation:

`A t^2 + B t + C = 0`

-> Discriminant: `d = sqrt(B^2 - 4 AC)`

discriminant: `b^2 - 4*a*c`

- discriminant < 0 : there is no intersection
- discriminant == 0 : only one intersection
- discriminant > 0 : two intersections

### Sphere

<p align="center">
  <img src="assets/inter_sphere.png" alt="intersect sphere" />
</p>

Source: Irisa

A sphere embedded in a 3D space:

```
x^2 + y^2 + z^2 = 1

// Xc, Yc, Zc : sphere center
// Solving quadratic equation

a = dir.x^2 + dir.y^2 + dir.z^2
b = 2 * (dir.x * (origin.x - Xc) + dir.y * (origin.y - Yc) + dir.z * (origin.z - Zc))
c = ((origin.x - Xc)^2 + (origin.y - Yc)^2 + (origin.z - Zc)^2) - r^2

root1 = (-b + sqrt(det)) / (2 * a);
root2 = (-b - sqrt(det)) / (2 * a);
```

A function that generates the radius 1 sphere would be: `f(x,y,z)=x2+y2+z2−1`

### Plane

```
Ax + By + Cz + D = 0; 

// (A, B, C) : plane normal

t = - ((A*X + B*Y + C*Z + D) / (A*DIR.x + B*DIR.y + C*DIR.z))
// (X Y Z) = (O.x-pointplaneX O.y-pointplaneY O.z-pointplane.Z)
```

### Square, triangle and disk

1. Intersect with plane
2. Use side / vertices / radius to check if point is inside shape

### Cylinder

<p align="center">
  <img src="assets/inter_cylinder.png" alt="intersect cylinder" />
</p>

Source: Irisa

#### Infinite cylinder

Same process than a sphere but set the z axis (or y according to your coordinates system) to null.

In my case: y is set to null.

```
x^2 + y^2 - r^2 = 0
```

Formula to compute cylinder's normal:

```
(inter_p – center)  - (z_axis. (inter_p – center) ) z_axis)
```

#### Finite cylinder

Use the normal to compute intersection angle with cylinder.

```
dot(ray dir, normal) > 0
```

### Cone

<p align="center">
  <img src="assets/inter_cone.png" alt="intersect cone" />
</p>

Source: Irisa
