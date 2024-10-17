/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 00:38:49 by tkurukay          #+#    #+#             */
/*   Updated: 2024/08/26 22:08:40 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"

void	init_data(t_data *data)
{
	data->player = 0;
	data->game = (t_game){0};
	data->mlx = (t_mlx){0};
	data->map = (t_map){0};
	data->key = (t_key){0};
	data->addr = (t_addr){0};
	data->map.c_rgb[0] = -1;
	data->map.c_rgb[1] = -1;
	data->map.c_rgb[2] = -1;
	data->map.f_rgb[0] = -1;
	data->map.f_rgb[1] = -1;
	data->map.f_rgb[2] = -1;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_putendl_fd("Error\nInvalid argument", 2), 1);
	init_data(&data);
	map_control(av[1], &data);
	init_ray(&data);
	ft_mlx(&data, 0, 0);
	mlx_hook(data.mlx.win, 2, 2, key_press, &data);
	mlx_hook(data.mlx.win, 3, 3, key_release, &data);
	mlx_hook(data.mlx.win, 17, 17, game_quit, &data);
	mlx_loop_hook(data.mlx.mlx, &game_loop, &data);
	mlx_loop(data.mlx.mlx);
	ft_exit_mlx(&data, "Exit");
}
