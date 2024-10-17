/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 00:39:02 by tkurukay          #+#    #+#             */
/*   Updated: 2024/08/26 22:11:41 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

void	check_repead_arg(t_data *data, char *map)
{
	if (data->map.no_path && !ft_strncmp(map, "NO", 2))
		ft_safe_exit("NO repeats the argument");
	if (data->map.so_path && !ft_strncmp(map, "SO", 2))
		ft_safe_exit("SO repeats the argument");
	if (data->map.we_path && !ft_strncmp(map, "WE", 2))
		ft_safe_exit("WE repeats the argument");
	if (data->map.ea_path && !ft_strncmp(map, "EA", 2))
		ft_safe_exit("EA repeats the argument");
	if (data->map.f_rgb[0] != -1 && map[0] == 'F')
		ft_safe_exit("F repeats the argument");
	if (data->map.c_rgb[0] != -1 && map[0] == 'C')
		ft_safe_exit("C repeats the argument");
}

void	get_rgb(int *i, char *map, int *rgb, t_data *data)
{
	int	start;
	int	j;

	j = 0;
	check_repead_arg(data, &map[*i]);
	*i += (skip_white_space(&map[*i + 1]) + 1);
	start = *i;
	while (map[*i] && map[*i] != '\n')
	{
		if (map[*i] == ',')
		{
			if (*i == start)
				ft_safe_exit("Invalid argument RGB");
			rgb[j++] = ft_atoi(&map[start]);
			start = *i + 1;
		}
		if (j > 2 || *i - start > 2 || !(ft_isdigit(map[*i]) || map[*i] == ','))
			ft_safe_exit("Invalid argument RGB");
		*i += 1;
	}
	if (*i == start)
		ft_safe_exit("Invalid argument RGB");
	rgb[j] = ft_atoi(&map[start]);
	check_valid_rgb(rgb);
}

char	*get_path(int *i, char *map, t_data *data)
{
	char	*path;
	int		start;
	int		j;

	j = -1;
	if (!map)
		ft_safe_exit("Memmory allocation failed");
	check_repead_arg(data, &map[*i]);
	*i += (skip_white_space(&map[*i + 2]) + 2);
	start = *i;
	while (map[*i] && map[*i] != '\n')
		(*i)++;
	path = gc_malloc((*i - start) + 1);
	path[*i - start] = '\0';
	while (++j + start < *i)
		path[j] = map[start + j];
	check_valid_path(path);
	return (path);
}

void	build_map(char *map, t_data *data)
{
	int		i;
	int		len;
	char	**tmp;

	i = 0;
	while (map[i] && map[i] == '\n')
		i++;
	while (map[++i])
		if (map[i] == '\n' && (map[i + 1] && map[i + 1] == '\n'))
			ft_safe_exit("Invalid map");
	i = -1;
	tmp = ft_split(map, '\n');
	add_garbage_c(tmp);
	while (tmp[++i])
		add_garbage_c(tmp[i]);
	data->map.build = tmp;
	i = -1;
	len = 0;
	while (data->map.build[++i])
		if (len < (int)ft_strlen(data->map.build[i]))
			len = ft_strlen(data->map.build[i]);
	build_control_map(len, data);
}

void	read_map(char *map_name, t_data *data, size_t file_len)
{
	char	*map;
	int		fd;
	char	*trim_map;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		ft_safe_exit("No such file or directory\n");
	map = gc_malloc(file_len + 1);
	if (read(fd, map, file_len) == -1)
		ft_safe_exit("Read failed");
	close(fd);
	map[file_len] = '\0';
	trim_map = ft_strtrim(map, " \t\n\r\a\v\f");
	add_garbage_c(trim_map);
	safe_free(map);
	create_map(data, trim_map);
}
