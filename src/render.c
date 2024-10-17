/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:42:37 by tkurukay          #+#    #+#             */
/*   Updated: 2024/08/26 21:43:17 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../inc/ft_def.h"

void	render_wall(t_data *data, int x, int y)
{
	if (data->game.side == 1 && data->game.raydir[1] < 0)
		data->addr.im_addr[y * WIDTH + x] = data->addr.no_addr[64
			* data->game.tex[1] + data->game.tex[0]];
	else if (data->game.side == 1 && data->game.raydir[1] >= 0)
		data->addr.im_addr[y * WIDTH + x] = data->addr.so_addr[64
			* data->game.tex[1] + data->game.tex[0]];
	if (data->game.side == 0 && data->game.raydir[0] < 0)
		data->addr.im_addr[y * WIDTH + x] = data->addr.we_addr[64
			* data->game.tex[1] + data->game.tex[0]];
	else if (data->game.side == 0 && data->game.raydir[0] >= 0)
		data->addr.im_addr[y * WIDTH + x] = data->addr.ea_addr[64
			* data->game.tex[1] + data->game.tex[0]];
	data->game.tex_pos += data->game.step_size;
}

void	render_column(t_data *data, int x, int y)
{
	while (++y < HEIGHT)
	{
		if (!(data->game.tex_pos >= 64 || data->game.tex_pos < 0))
			data->game.tex[1] = (int)data->game.tex_pos;
		if (y < data->game.draw_start)
			data->addr.im_addr[y * WIDTH
				+ x] = data->map.f_rgb[0] << 16
				| data->map.f_rgb[1] << 8 | data->map.f_rgb[2];
		else if (y > data->game.draw_end)
			data->addr.im_addr[y * WIDTH
				+ x] = data->map.c_rgb[0] << 16
				| data->map.c_rgb[1] << 8 | data->map.c_rgb[2];
		else
			render_wall(data, x, y);
	}
}
