/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 02:52:41 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 11:42:22 by jacens      ###    #+. /#+    ###.fr     */
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
# define FC color
# define PA path
# define M map
# define PL player
# define R ray
# define D draw
# define K key
# define SP sprite
# define IW imgw

typedef struct		s_imgw
{
	int				*text[5];
	void			*img[5];
	int				width[5];
	int				height[5];
}					t_imgw;

typedef struct		s_sprite
{
	int				y;
	int				x;
	float			dist;
	struct s_sprite	*next;

}					t_sprite;

typedef struct		s_draw
{
	double			d;
	int				texx;
	int				texy;
	int				start;
	int				end;
	int				lineheight;
}					t_draw;

typedef struct		s_key
{
	int				up;
	int				down;
	int				left;
	int				right;
	int				mvleft;
	int				mvright;
}					t_key;

typedef struct		s_ray
{
	float			sidex;
	float			sidey;
	float			deltdistx;
	float			deltdisty;
	float			raydirx;
	float			raydiry;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	float			perpwalldist;
	int				hit;
	int				side;
}					t_ray;

typedef struct		s_player
{
	char			direction;
	float			y;
	float			x;
	float			plany;
	float			planx;
	float			dirx;
	float			diry;
	float			camx;
}					t_player;

typedef struct		s_map
{
	char			**map;
	char			*mapchar;
	int				width;
	int				height;
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
	int				save;
	struct s_path	*path;
	struct s_color	*color;
	struct s_map	*map;
	struct s_player	*player;
	struct s_ray	*ray;
	struct s_draw	*draw;
	struct s_key	*key;
	struct s_sprite	*sprite;
	struct s_imgw	*imgw;
}					t_file;

int					main(int ac, char **av);

void				ft_free_sprite(t_file *file);
void				ft_free_fil(t_file *file);

void				ft_sprit_verif_lst(t_file *file);

int					ft_init_color(t_file *file);
int					ft_init_map(t_file *file);
int					ft_init_player(t_file *file);
int					ft_init_path(t_file *file);
int					ft_init_ray(t_file *file);
int					ft_init_draw(t_file *file);
int					ft_init_key(t_file *file);
int					ft_init_imgw(t_file *file);
t_sprite			*ft_init_sprite(t_file *file, int x, int y, float dist);

int					ft_verif_color_path(t_file *file);
int					ft_verif_map(t_file *file);
int					ft_verif_reso(t_file *file);
int					ft_verif_player_config(t_file *file, char line, int nb);
int					ft_start_verif(t_file *file, char **av);
int					ft_verif_path_img(t_file *file);

int					ft_parse_cube(char	*fichier, t_file *file);
int					ft_rgbtoint(int red, int green, int blue);

void				ft_move(t_file *file);
int					ft_appui(int i, t_file *file);
int					ft_relache(int i, t_file *file);

void				ft_draw_sprite(t_file *file, double *buffer);

int					*ft_readxpm(t_file *file, char *str, int n);
void				ft_hit_wall(t_file *file);
void				ft_draw(t_file *file, int x);

void				raycast(t_file *file);
int					ft_snakeoil(t_file *file);

void				ft_resochr(char *line, t_file *file);
void				ft_colorchr(char *line, t_file *file, int p, int i);
void				ft_pathchr(char *line, t_file *file, int p);

int					ft_set_line(t_file *file, char *line, int nb, int i);
int					ft_first_line_map(char *line, int i, int nb, t_file *file);
int					ft_config_map(int fd, char *line, t_file *file);

int					ft_quit(t_file *file);

#endif
