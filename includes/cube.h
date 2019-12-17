/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 02:52:41 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 18:08:37 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <math.h>
# include <time.h>

# include "../ft_printf/includes/ft_printf.h"
# include "../minilibx/mlx.h"
# include "../ft_printf/libft/include/libft.h"
# include "../ft_printf/libft/include/get_next_line.h"

# define F file
# define FC file->color
# define FP file->path
# define FM file->map
# define FS file->spawn

typedef struct		s_spawn
{
	char	direction;
	float	y;
	float	x;
	float	rotation;
}					t_spawn;

typedef struct		s_map
{
	char	**map;
	char	*mapchar;
	int		width;
	int		height;
}					t_map;

typedef struct		s_path
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*sprite;
}					t_path;

typedef struct		s_color
{
	int				f1;
	int				f2;
	int				f3;
	int				c1;
	int				c2;
	int				c3;
}					t_color;

typedef struct		s_file
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*imgdata;
	int				axe_x;
	int				axe_y;
	struct s_path	*path;
	struct s_color	*color;
	struct s_map	*map;
	struct s_spawn	*spawn;
	int				hit;
}					t_file;

int					main(int ac, char **av);
void				ft_cube();

void				ft_free_path(t_file *file);
void				ft_free_map(t_file *file);
void				ft_free_fil(t_file *file);

int   				ft_init_color(t_file *file);
int    				ft_init_map(t_file *file);
int    				ft_init_spawn(t_file *file);
int    				ft_init_path(t_file *file);

int					ft_verif_color_path(t_file *file);
int					ft_verif_map(t_file *file);
int					ft_verif_spawn_config(t_file *file, char line, int nb);
int					ft_start_verif(t_file *file, char **av);

int					ft_parse_cube(char	*fichier, t_file *file);
int					ft_snakeoil(t_file *file);
int					ft_rgbtoint(int red, int green, int blue);

void 				ft_resochr(char *line, t_file *file);
void				ft_colorchr(char *line, t_file *file, int p);
void				ft_pathchr(char *line, t_file *file, int p);
int					ft_set_line(t_file *file, char *line, int nb, int i);
int					ft_first_line_map(char *line, int i, int nb, t_file *file);
int					ft_config_map(int fd, char *line, t_file *file);

#endif