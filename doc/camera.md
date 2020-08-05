# Camera

## Orientation

<p align="center">
  <img src="assets/camera-z-axis.png" alt="camera-z-axis" />
</p>

> When you create a camera, it is by default aligned along the world coordinate system negative z-axis. This is a convention used by most 3D applications.

Source: [Scratchapixel: Camera Coordinate System and Camera Space](https://www.scratchapixel.com/lessons/3d-basic-rendering/computing-pixel-coordinates-of-3d-point/mathematics-computing-2d-coordinates-of-3d-points)

## camToWorld / lookAt

<p align="center">
  <img src="assets/image018.jpg" alt="camera basis vectors 1" /> <img src="assets/image020.jpg" alt="camera basis vectors 1" />
</p>

Source: [Interactive Techniques in Three-dimensional Scenes (Part 1)](https://www.codeproject.com/Articles/35139/Interactive-Techniques-in-Three-dimensional-Scenes)

> A great thing about matrices is that if you define a coordinate space using 3 perpendicular (or non-linear) axes you can create a matrix with those 3 axes plus a translation vector and you can transform any vector to that coordinate space by multiplying it with this matrix.

<p align="center">
  <img src="assets/lookat-matrix.png" alt="lookAt OpenGL" />
</p>

Source: [Learn OpenGL: Camera](https://learnopengl.com/Getting-started/Camera)

## Rotation

<p align="center">
  <img src="assets/image022.jpg" alt="camera rotation" />
</p>

<p align="center">
  <img src="assets/TranslationController014.jpg" alt="TranslationController014" />
</p>

<p align="center">
  <img src="assets/TranslationController016.jpg" alt="TranslationController016" />
</p>

Source: [Interactive Techniques in Three-dimensional Scenes (Part 1)](https://www.codeproject.com/Articles/35139/Interactive-Techniques-in-Three-dimensional-Scenes)
