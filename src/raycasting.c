/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 00:39:04 by tkurukay          #+#    #+#             */
/*   Updated: 2024/08/26 22:11:54 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../inc/ft_def.h"
#include <math.h>

void	calculate_ray_direction_and_distances(t_data *data, int x)
{
	data->game.camera_x = 2 * x / (double)WIDTH - 1;
	data->game.raydir[0] = data->game.dir[0] + data->game.plane[0]
		* data->game.camera_x;
	data->game.raydir[1] = data->game.dir[1] + data->game.plane[1]
		* data->game.camera_x;
	data->game.map_pos[0] = (int)data->game.pos[0];
	data->game.map_pos[1] = (int)data->game.pos[1];
	if (data->game.raydir[0] == 0)
		data->game.delta_dist[0] = 1e30;
	else
		data->game.delta_dist[0] = fabs(1 / data->game.raydir[0]);
	if (data->game.raydir[1] == 0)
		data->game.delta_dist[1] = 1e30;
	else
		data->game.delta_dist[1] = fabs(1 / data->game.raydir[1]);
}

void	calculate_step(t_data *data)
{
	if (data->game.raydir[0] < 0)
	{
		data->game.step[0] = -1;
		data->game.side_dist[0] = (data->game.pos[0] - data->game.map_pos[0])
			* data->game.delta_dist[0];
	}
	else
	{
		data->game.step[0] = 1;
		data->game.side_dist[0] = (data->game.map_pos[0] + 1.0
				- data->game.pos[0]) * data->game.delta_dist[0];
	}
	if (data->game.raydir[1] < 0)
	{
		data->game.step[1] = -1;
		data->game.side_dist[1] = (data->game.pos[1] - data->game.map_pos[1])
			* data->game.delta_dist[1];
	}
	else
	{
		data->game.step[1] = 1;
		data->game.side_dist[1] = (data->game.map_pos[1] + 1.0
				- data->game.pos[1]) * data->game.delta_dist[1];
	}
}

void	calculate_collision_distance(t_data *data)
{
	int	nearest_wall;

	while (1)
	{
		if (data->game.side_dist[0] < data->game.side_dist[1])
			nearest_wall = 0;
		else
			nearest_wall = 1;
		if (nearest_wall == 0)
		{
			data->game.side_dist[0] += data->game.delta_dist[0];
			data->game.map_pos[0] += data->game.step[0];
		}
		else
		{
			data->game.side_dist[1] += data->game.delta_dist[1];
			data->game.map_pos[1] += data->game.step[1];
		}
		data->game.side = nearest_wall;
		if ((data->map.build[data->game.map_pos[1]][data->game.map_pos[0]])
		== '1')
			break ;
	}
}

void	calculate_wall_properties(t_data *data)
{
	data->game.perp_wall_dist = data->game.side_dist[data->game.side]
		- data->game.delta_dist[data->game.side];
	data->game.line_h = (int)(HEIGHT / data->game.perp_wall_dist);
	data->game.draw_start = (HEIGHT - data->game.line_h) / 2;
	data->game.draw_start = (data->game.draw_start >= 0)
		* data->game.draw_start;
	data->game.draw_end = (HEIGHT + data->game.line_h) / 2;
	if (data->game.draw_end >= HEIGHT)
		data->game.draw_end = HEIGHT - 1;
	data->game.wall_x = data->game.pos[!data->game.side]
		+ data->game.perp_wall_dist * data->game.raydir[!data->game.side];
	data->game.wall_x = data->game.wall_x - (int)data->game.wall_x;
	data->game.tex[0] = (int)(data->game.wall_x * 64);
	if (data->game.side == 0 && data->game.raydir[0] < 0)
		data->game.tex[0] = 64 - data->game.tex[0] - 1;
	if (data->game.side == 1 && data->game.raydir[1] > 0)
		data->game.tex[0] = 64 - data->game.tex[0] - 1;
	data->game.step_size = (double)64 / data->game.line_h;
	data->game.tex_pos = (data->game.draw_start - HEIGHT / 2 + data->game.line_h
			/ 2) * data->game.step_size;
}
