/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 00:39:01 by tkurukay          #+#    #+#             */
/*   Updated: 2024/08/26 22:11:10 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../libft/libft.h"

char	*map_line_build(int len, char *line)
{
	int		i;
	char	*map_line;

	i = -1;
	map_line = gc_malloc(len + 1);
	while (line[++i])
	{
		if (valid_char(line[i]))
			map_line[i] = line[i];
		else
			map_line[i] = '#';
	}
	if (i < len)
		while (i < len)
			map_line[i++] = '#';
	map_line[i] = '\0';
	return (map_line);
}

void	find_player(char **map, t_data *data, int i, int j)
{
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
			{
				data->map.map_xy[0] = i;
				data->map.map_xy[1] = j;
				if (map[i][j] == 'N')
					data->player += 4;
				else if (map[i][j] == 'S')
					data->player += 5;
				else if (map[i][j] == 'W')
					data->player += 6;
				else if (map[i][j] == 'E')
					data->player += 7;
			}
		}
	}
	if (data->player == 0 || !(data->player >= 4 && data->player <= 7))
		ft_safe_exit("Invalid start position");
}

void	build_control_map(int len, t_data *data)
{
	char	**map;
	char	**tmp;
	int		i;

	tmp = data->map.build;
	i = ft_strslen(tmp);
	map = gc_malloc(sizeof(char *) * (i + 1));
	map[i] = NULL;
	i = -1;
	while (tmp[++i])
		map[i] = map_line_build(len, tmp[i]);
	find_player(map, data, -1, 0);
	flot_fill(map, data->map.map_xy[0], data->map.map_xy[1]);
}

void	flot_fill(char **map, int y, int x)
{
	if (x < 0 || y < 0 || y >= ft_strslen(map) || map[y][x] == '#'
		|| map[y][x] == '\0')
		ft_safe_exit("Invalid map");
	if (map[y][x] == '1')
		return ;
	map[y][x] = '1';
	flot_fill(map, y + 1, x);
	flot_fill(map, y - 1, x);
	flot_fill(map, y, x + 1);
	flot_fill(map, y, x - 1);
}
