/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 00:38:51 by tkurukay          #+#    #+#             */
/*   Updated: 2024/08/26 22:09:18 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

int	game_quit(t_data *data)
{
	printf("Exit\n");
	ft_exit_mlx(data, NULL);
	return (0);
}

void	ft_safe_exit(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	gc_free();
	exit(0);
}

void	ft_exit_mlx(t_data *data, char *str)
{
	if (str)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd(str, 2);
	}
	if (data->mlx.win)
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	if (data->mlx.north)
		mlx_destroy_image(data->mlx.mlx, data->mlx.north);
	if (data->mlx.south)
		mlx_destroy_image(data->mlx.mlx, data->mlx.south);
	if (data->mlx.west)
		mlx_destroy_image(data->mlx.mlx, data->mlx.west);
	if (data->mlx.east)
		mlx_destroy_image(data->mlx.mlx, data->mlx.east);
	if (data->mlx.image)
		mlx_destroy_image(data->mlx.mlx, data->mlx.image);
	if (data->mlx.mlx)
		free(data->mlx.mlx);
	gc_free();
	exit(0);
}
