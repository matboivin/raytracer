# Viewing frustum

[Wiki: Viewing frustum](https://en.wikipedia.org/wiki/Viewing_frustum)

Any object contained within the frustum (or overlapping it) is visible and will show up on the image ([source](https://www.scratchapixel.com/lessons/3d-basic-rendering/get-started)).

<p align="center">
  <img src="assets/viewdist00.png" alt="viewdist00" />
</p>

Source: [ThreeJS: Calculating FOV for perspective camera after browser window resize](https://stackoverflow.com/questions/47184264/threejs-calculating-fov-for-perspective-camera-after-browser-window-resize)

<p align="center">
  <img src="assets/viewdist01.png" alt="viewdist01" />
</p>

Source: [Perspective projection view plane distance calculation confusion?](https://stackoverflow.com/questions/36251087/perspective-projection-view-plane-distance-calculation-confusion)

## Camera

### FOV

A perspective projection demo: [Perspective Projections](http://learnwebgl.brown37.net/08_projections/projections_perspective.html)

Aspect ratio and FOV: [Sratchapixel: 3D Viewing: the Pinhole Camera Model](https://www.scratchapixel.com/lessons/3d-basic-rendering/3d-viewing-pinhole-camera/how-pinhole-camera-works-part-2)

### Orientation

<p align="center">
  <img src="assets/camera-z-axis.png" alt="camera-z-axis" />
</p>

> When you create a camera, it is by default aligned along the world coordinate system negative z-axis. This is a convention used by most 3D applications.

Source: [Scratchapixel: Camera Coordinate System and Camera Space](https://www.scratchapixel.com/lessons/3d-basic-rendering/computing-pixel-coordinates-of-3d-point/mathematics-computing-2d-coordinates-of-3d-points)

### Rotation

<p align="center">
  <img src="assets/TranslationController014.jpg" alt="TranslationController014" />
</p>

<p align="center">
  <img src="assets/TranslationController016.jpg" alt="TranslationController016" />
</p>

Source: [Interactive Techniques in Three-dimensional Scenes (Part 1)](https://www.codeproject.com/Articles/35139/Interactive-Techniques-in-Three-dimensional-Scenes)
