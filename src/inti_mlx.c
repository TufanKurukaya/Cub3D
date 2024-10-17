/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inti_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 00:38:54 by tkurukay          #+#    #+#             */
/*   Updated: 2024/08/26 22:09:59 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../inc/ft_def.h"
#include "../minilibx/mlx.h"
#include <stdlib.h>

static int	east_west(t_data *data)
{
	if (data->player == 6)
	{
		data->game.dir[0] = -1;
		data->game.dir[1] = 0;
		data->game.plane[0] = 0;
		data->game.plane[1] = -0.66;
		return (1);
	}
	else if (data->player == 7)
	{
		data->game.dir[0] = 1;
		data->game.dir[1] = 0;
		data->game.plane[0] = 0;
		data->game.plane[1] = 0.66;
		return (1);
	}
	return (0);
}

static int	south_north(t_data *data)
{
	if (data->player == 5)
	{
		data->game.dir[0] = 0;
		data->game.dir[1] = 1;
		data->game.plane[0] = -0.66;
		data->game.plane[1] = 0;
		return (1);
	}
	else if (data->player == 4)
	{
		data->game.dir[0] = 0;
		data->game.dir[1] = -1;
		data->game.plane[0] = 0.66;
		data->game.plane[1] = 0;
		return (1);
	}
	return (0);
}

void	init_ray(t_data *data)
{
	if (!east_west(data))
		south_north(data);
	data->game.pos[0] = data->map.map_xy[1] + 0.5;
	data->game.pos[1] = data->map.map_xy[0] + 0.5;
	data->game.speed = 0.053;
	data->game.rspeed = 0.093;
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		ft_safe_exit("mlx_init failed");
	data->mlx.win = mlx_new_window(data->mlx.mlx, WIDTH, HEIGHT, "cub3D");
	if (!data->mlx.win)
		ft_exit_mlx(data, "mlx_new_window failed");
}

void	ft_mlx2(t_data *data, int c)
{
	data->addr.no_addr = (int *)mlx_get_data_addr(data->mlx.north, &c, &c, &c);
	data->addr.so_addr = (int *)mlx_get_data_addr(data->mlx.south, &c, &c, &c);
	data->addr.we_addr = (int *)mlx_get_data_addr(data->mlx.west, &c, &c, &c);
	data->addr.ea_addr = (int *)mlx_get_data_addr(data->mlx.east, &c, &c, &c);
	if (!data->addr.no_addr || !data->addr.so_addr || !data->addr.we_addr
		|| !data->addr.ea_addr)
		ft_exit_mlx(data, "mlx_get_data_addr failed");
}

void	ft_mlx(t_data *data, int a, int b)
{
	data->mlx.image = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
	if (!data->mlx.image)
		ft_exit_mlx(data, "mlx_new_image failed");
	data->addr.im_addr = (int *)mlx_get_data_addr(data->mlx.image, &a, &a, &a);
	if (!data->addr.im_addr)
		ft_exit_mlx(data, "mlx_get_data_addr failed");
	data->mlx.north = mlx_xpm_file_to_image(data->mlx.mlx, data->map.no_path,
			&b, &b);
	data->mlx.south = mlx_xpm_file_to_image(data->mlx.mlx, data->map.so_path,
			&b, &b);
	data->mlx.west = mlx_xpm_file_to_image(data->mlx.mlx, data->map.we_path, &b,
			&b);
	data->mlx.east = mlx_xpm_file_to_image(data->mlx.mlx, data->map.ea_path, &b,
			&b);
	if (!data->mlx.north || !data->mlx.south || !data->mlx.west
		|| !data->mlx.east)
		ft_exit_mlx(data, "mlx_xpm_file_to_image failed");
	ft_mlx2(data, b);
}
