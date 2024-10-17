/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 00:38:56 by tkurukay          #+#    #+#             */
/*   Updated: 2024/08/24 00:38:57 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../inc/ft_def.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		game_quit(data);
	if (keycode == W)
		data->key.w = 1;
	if (keycode == S)
		data->key.s = 1;
	if (keycode == A)
		data->key.a = 1;
	if (keycode == D)
		data->key.d = 1;
	if (keycode == RIGHT)
		data->key.right = 1;
	if (keycode == LEFT)
		data->key.left = 1;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == W)
		data->key.w = 0;
	if (keycode == S)
		data->key.s = 0;
	if (keycode == A)
		data->key.a = 0;
	if (keycode == D)
		data->key.d = 0;
	if (keycode == RIGHT)
		data->key.right = 0;
	if (keycode == LEFT)
		data->key.left = 0;
	return (0);
}
