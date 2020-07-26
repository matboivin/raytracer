# Process

## Working principle

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
- Initialize scene struct
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
- Trace a ray from camera position
- Identify nearest object
  - Identify shape (sphere, plane, square, cylinder, triangle)
  - At intersection, define light, shadows, texture, ...
  - Retrieve the color of the pixel
- Else
  - Default color

### MLX images

- 1 image = char pointer
- 1 pixel = 4 char = RED, GREEN, BLUE, ALPHA

MLX is in BGRA so we change the order of values to RGBA.

`x position * 4 + 4 * size_line * y position`

Create a new image:
```
img_ptr = mlx_new_image(mlx_ptr, width, height);
```

Get the image data (pixels):
```
img_data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
```

Display the image:
```
mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
```

## TODO

- [ ] Ray tracing rendering
- [ ] Handle misconfigured scene descriptions
- [ ] Save the rendered image in bmp format when "--save" is passed
- [ ] Close window when pressing ESC or clicking red cross
- [ ] Window size is never greater than the display resolution and cannot be < 1
- [ ] If more than 1 camera, switch between cameras pressing a key
- [ ] In case of error, program prints "Error\n" followed by an explicit error message
