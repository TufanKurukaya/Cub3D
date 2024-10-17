/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_arg_creat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 00:38:59 by tkurukay          #+#    #+#             */
/*   Updated: 2024/08/26 20:34:41 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../libft/libft.h"

void	create_map(t_data *data, char *map)
{
	int	i;

	i = skip_white_space(map);
	while (map[i])
	{
		i += skip_white_space(&map[i]);
		if (map[i] && !ft_strncmp(&map[i], "NO", 2))
			data->map.no_path = get_path(&i, map, data);
		else if (map[i] && !ft_strncmp(&map[i], "SO", 2))
			data->map.so_path = get_path(&i, map, data);
		else if (map[i] && !ft_strncmp(&map[i], "WE", 2))
			data->map.we_path = get_path(&i, map, data);
		else if (map[i] && !ft_strncmp(&map[i], "EA", 2))
			data->map.ea_path = get_path(&i, map, data);
		else if (map[i] && map[i] == 'F')
			get_rgb(&i, map, data->map.f_rgb, data);
		else if (map[i] && map[i] == 'C')
			get_rgb(&i, map, data->map.c_rgb, data);
		else
			ft_safe_exit("Invalid argument");
		if (check_map_arguman(data))
			break ;
		i++;
	}
	build_map(&map[i], data);
}
