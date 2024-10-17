/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:52:56 by tkurukay          #+#    #+#             */
/*   Updated: 2024/08/26 21:52:57 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include <math.h>

void	rotate_right(t_data *data)
{
	double	dir;
	double	plane;

	dir = data->game.dir[0];
	data->game.dir[0] = data->game.dir[0] * cos(data->game.rspeed)
		- data->game.dir[1] * sin(data->game.rspeed);
	data->game.dir[1] = dir * sin(data->game.rspeed) + data->game.dir[1]
		* cos(data->game.rspeed);
	plane = data->game.plane[0];
	data->game.plane[0] = data->game.plane[0] * cos(data->game.rspeed)
		- data->game.plane[1] * sin(data->game.rspeed);
	data->game.plane[1] = plane * sin(data->game.rspeed) + data->game.plane[1]
		* cos(data->game.rspeed);
}

void	rotate_left(t_data *data)
{
	double	dir;
	double	plane;

	dir = data->game.dir[0];
	data->game.dir[0] = data->game.dir[0] * cos(data->game.rspeed)
		+ data->game.dir[1] * sin(data->game.rspeed);
	data->game.dir[1] = -dir * sin(data->game.rspeed) + data->game.dir[1]
		* cos(data->game.rspeed);
	plane = data->game.plane[0];
	data->game.plane[0] = data->game.plane[0] * cos(data->game.rspeed)
		+ data->game.plane[1] * sin(data->game.rspeed);
	data->game.plane[1] = -plane * sin(data->game.rspeed) + data->game.plane[1]
		* cos(data->game.rspeed);
}
