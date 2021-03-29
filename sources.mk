SRC_FILES	=	main.c						\
				check_max_display.c			\
				check_null_light.c			\
				check_null_vector.c			\
				get_hit_point.c				\
				get_pixel_coord.c			\
				get_obj_color.c				\
				get_specular.c				\
				hit.c						\
				hit_cylinder.c				\
				hit_plane.c					\
				hit_sphere.c				\
				hit_square.c				\
				hit_triangle.c				\
				look_at.c					\
				parsing.c					\
				parsing_ambient.c			\
				parsing_cam.c				\
				parsing_light.c				\
				parsing_obj.c				\
				parsing_objadd.c			\
				parsing_resolution.c		\
				parsing_values.c			\
				parsing_utils.c				\
				put_pixel.c					\
				render.c					\
				rescale_color.c				\
				set_ray_dir.c				\
				set_ray_origin.c			\
				trace_ray.c					\
				trace_ray_to_lights.c		\
				trace_ray_to_objs.c

# MATH UTILS #

SRC_FILES	+=	ft_percent.c				\
				get_cylinder_normal.c		\
				get_obj_normal.c			\
				get_quad_coef.c				\
				get_quad_roots.c			\
				get_sphere_normal.c			\
				get_triangle_normal.c

# DISPLAY AND EVENT HANDLING #

SRC_FILES	+=	dispatch_events.c			\
				display_render.c			\
				handle_key.c				\
				open_window.c				\
				put_image_to_window.c		\
				reload_image.c				\
				run_loop.c					\
				switch_cam.c

# STRUCTS #

SRC_FILES	+=	ambient.c					\
				camera.c					\
				image.c						\
				image_list.c				\
				lights.c					\
				minirt_env.c				\
				objects.c					\
				ray.c						\
				resolution.c

# UTILS #

SRC_FILES	+=	check_params.c				\
				exit.c						\
				save_bmp.c

# DEBUG #

SRC_FILES	+=	map_normal2.c				\
				map_normal2_rev.c			\
				map_normal.c
