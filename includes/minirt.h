#ifndef MINIRT_H
# define MINIRT_H

# include <errno.h>
# include <limits.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "libft.h"
# include "mlx.h"

void		put_usage(void);
void		put_error(void *s);
void		check_filename(const char *filepath);

#endif
