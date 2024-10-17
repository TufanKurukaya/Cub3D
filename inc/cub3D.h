/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 00:38:07 by tkurukay          #+#    #+#             */
/*   Updated: 2024/08/26 21:53:08 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/types.h>

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*north;
	void			*south;
	void			*west;
	void			*east;
	void			*image;
}					t_mlx;

typedef struct s_addr
{
	int				*no_addr;
	int				*so_addr;
	int				*we_addr;
	int				*ea_addr;
	int				*im_addr;
}					t_addr;

typedef struct s_game
{
	double			pos[2];
	double			dir[2];
	double			plane[2];
	double			raydir[2];
	double			side_dist[2];
	double			delta_dist[2];
	double			speed;
	double			rspeed;
	double			wall_x;
	double			tex_pos;
	double			camera_x;
	double			step_size;
	double			perp_wall_dist;
	int				tex[2];
	int				step[2];
	int				map_pos[2];
	int				side;
	int				line_h;
	int				draw_end;
	int				draw_start;
}					t_game;

typedef struct s_malloc
{
	void			*ptr;
	struct s_malloc	*next;
}					t_malloc;

typedef struct s_key
{
	int				w;
	int				s;
	int				a;
	int				d;
	int				left;
	int				right;
}					t_key;

typedef struct s_map
{
	char			**build;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	int				f_rgb[3];
	int				c_rgb[3];
	int				map_xy[2];
}					t_map;

typedef struct s_data
{
	t_map			map;
	t_mlx			mlx;
	t_game			game;
	t_key			key;
	t_addr			addr;
	int				player;
}					t_data;

// exit
int					game_quit(t_data *data);
void				ft_safe_exit(char *str);
void				ft_exit_mlx(t_data *data, char *str);

// safe_malloc
void				add_garbage_c(void *ptr);
void				*gc_malloc(unsigned int size);
void				garbage_collecter(void *ptr);
void				gc_free(void);
t_malloc			*get_garbage_c(void);
void				safe_free(void *ptr);

// map_arg_control
void				check_valid_rgb(int *rgb);
void				check_valid_path(char *path);
void				map_control(char *map_name, t_data *data);
int					check_map_arguman(t_data *data);

// map_arg_creat
void				create_map(t_data *data, char *map);
// map_control
void				build_control_map(int len, t_data *data);
void				flot_fill(char **map, int x, int y);

// map_create
void				get_rgb(int *i, char *map, int *rgb, t_data *data);
char				*get_path(int *i, char *map, t_data *data);
void				build_map(char *map, t_data *data);
void				read_map(char *map_name, t_data *data, size_t file_len);

// utils
int					skip_white_space(char *str);
int					ft_strslen(char **strs);
int					valid_char(char chr);

// inti_mlx
void				ft_mlx(t_data *data, int a, int b);
void				init_ray(t_data *data);

// key
int					key_press(int keycode, t_data *data);
int					key_release(int keycode, t_data *data);

// game_loop
int					game_loop(t_data *data);

// raycasting
void				calculate_ray_direction_and_distances(t_data *data, int x);
void				calculate_step(t_data *data);
void				calculate_collision_distance(t_data *data);
void				calculate_wall_properties(t_data *data);
void				render_column(t_data *data, int x, int y);

void				rotate_right(t_data *data);
void				rotate_left(t_data *data);

#endif
