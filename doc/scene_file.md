# Scene description file

A scene file is a defined data structure that contains:

- a collection of objects (objects are also called models)
- a camera
- lights
- textures (optional)
- global render settings or options such as the resolution of the image.

## Format

A scene description file must end by the .rt extension:

scene.rt

```
R   1920 1080
A   0.2                                                255,255,255

c   -50.0,0,20       0,0,1            70
l   -40.0,50.0,0.0                    0.6              10,0,255

sp  0.0,0.0,20.6     12.6                              10,0,255
pl  0.0,0.0,-10.0    0.0,1.0,0.0                       0,0,225
sq  0.0,0.0,20.6     1.0,0.0,0.0      12.6             255,0,255
cy  50.0,0.0,20.6    0.0,0.0,1.0      14.2 21.42       10,0,255
tr  10.0,20.0,10.0   10.0,10.0,20.0   20.0,10.0,10.0   0,0,255
```

### Resolution

```
R 1920 1080
```
- x render size
- y render size

Can only be declared once in a scene.

### Ambient lighting

```
A 0.2 255,255,255
```
- ambient lighting ratio in range [0.0,1.0]
- R,G,B colors in range [0,255]

Can only be declared once in a scene.

### Camera

```
c -50.0,0,20   0,0,1   70
```
- x,y,z coordinates of the view point
- 3D-normalized orientation vector in range [-1,1] for each x,y,z axis
- FOV: Horizontal field of view in degrees in range [0,180]

### Light

```
l -40.0,50.0,0.0   0.6   10,0,255
```
- x,y,z coordinates of the light point
- light brightness ratio in range [0.0,1.0]
- R,G,B colors in range [0,255]

### Sphere

```
sp 0.0,0.0,20.6   12.6   10,0,255
```
- x,y,z coordinates of the sphere center
- the sphere diameter
- R,G,B colors in range [0,255]

### Plane

```
pl 0.0,0.0,-10.0   0.0,1.0,0.0   0,0,225
```
- x,y,z coordinates
- 3D-normalized orientation vector in range [-1,1] for each x,y,z axis
- R,G,B colors in range [0,255]

### Square

```
sq 0.0,0.0,20.6   1.0,0.0,0.0 12.6   255,0,255
```
- x,y,z coordinates of the square center
- 3D-normalized orientation vector in range [-1,1] for each x,y,z axis
- side size
- R,G,B colors in range [0,255]

### Cylinder

```
cy 50.0,0.0,20.6   0.0,0.0,1.0   14.2 21.42   10,0,255
```
- x,y,z coordinates
- 3D-normalized orientation vector in range [-1,1] for each x,y,z axis
- the cylinder diameter
- the cylinder height
- R,G,B colors in range [0,255]

### Triangle

```
tr 10.0,20.0,10.0   10.0,10.0,20.0   20.0,10.0,10.0   0,0,255
```
- x,y,z coordinates of the first point
- x,y,z coordinates of the second point
- x,y,z coordinates of the third point
- R,G,B colors in range [0,255]
