/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 00:38:53 by tkurukay          #+#    #+#             */
/*   Updated: 2024/08/26 21:51:07 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../inc/ft_def.h"
#include "../minilibx/mlx.h"
#include <math.h>

void	movement_2(t_data *data)
{
	if (data->key.a)
	{
		if (data->map.build[(int)(data->game.pos[1])][(int)(data->game.pos[0]
				- data->game.plane[0] * data->game.speed)] != '1')
			data->game.pos[0] -= data->game.plane[0] * data->game.speed;
		if (data->map.build[(int)(data->game.pos[1] - data->game.plane[1]
				* data->game.speed)][(int)(data->game.pos[0])] != '1')
			data->game.pos[1] -= data->game.plane[1] * data->game.speed;
	}
	if (data->key.d)
	{
		if (data->map.build[(int)(data->game.pos[1])][(int)(data->game.pos[0]
				+ data->game.plane[0] * data->game.speed)] != '1')
			data->game.pos[0] += data->game.plane[0] * data->game.speed;
		if (data->map.build[(int)(data->game.pos[1] + data->game.plane[1]
				* data->game.speed)][(int)(data->game.pos[0])] != '1')
			data->game.pos[1] += data->game.plane[1] * data->game.speed;
	}
}

void	movement(t_data *data)
{
	if (data->key.w)
	{
		if (data->map.build[(int)(data->game.pos[1])][(int)(data->game.pos[0]
				+ data->game.dir[0] * data->game.speed)] != '1')
			data->game.pos[0] += data->game.dir[0] * data->game.speed;
		if (data->map.build[(int)(data->game.pos[1] + data->game.dir[1]
				* data->game.speed)][(int)(data->game.pos[0])] != '1')
			data->game.pos[1] += data->game.dir[1] * data->game.speed;
	}
	if (data->key.s)
	{
		if (data->map.build[(int)(data->game.pos[1])][(int)(data->game.pos[0]
				- data->game.dir[0] * data->game.speed)] != '1')
			data->game.pos[0] -= data->game.dir[0] * data->game.speed;
		if (data->map.build[(int)(data->game.pos[1] - data->game.dir[1]
				* data->game.speed)][(int)(data->game.pos[0])] != '1')
			data->game.pos[1] -= data->game.dir[1] * data->game.speed;
	}
	movement_2(data);
}

void	rotate(t_data *data)
{
	if (data->key.right)
		rotate_right(data);
	if (data->key.left)
		rotate_left(data);
}

static void	raycast(t_data *data)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		calculate_ray_direction_and_distances(data, x);
		calculate_step(data);
		calculate_collision_distance(data);
		calculate_wall_properties(data);
		render_column(data, x, -1);
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.image, 0,
		0);
}

int	game_loop(t_data *data)
{
	movement(data);
	rotate(data);
	raycast(data);
	return (0);
}
