/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_arg_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 00:38:57 by tkurukay          #+#    #+#             */
/*   Updated: 2024/08/26 22:10:38 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

void	check_valid_rgb(int *rgb)
{
	int	i;

	i = -1;
	while (++i < 3)
		if (rgb[i] < 0 || rgb[i] > 255)
			ft_safe_exit("Invalid RGB\n");
}

void	check_valid_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_safe_exit("Invalide path");
	close(fd);
}

size_t	get_file_len(int fd)
{
	size_t	file_len;
	char	buf;
	int		read_bit;

	read_bit = 1;
	file_len = 0;
	while (read_bit > 0)
	{
		read_bit = read(fd, &buf, 1);
		if (read_bit == -1)
			ft_safe_exit("Read failed");
		file_len++;
	}
	close(fd);
	return (file_len);
}

void	map_control(char *map_name, t_data *data)
{
	char	*line;
	int		fd;
	size_t	file_len;

	fd = 0;
	line = ft_strrchr(map_name, '.');
	if (line == NULL || ft_strncmp(line, ".cub", 5) || ft_strncmp(line, ".cub",
			ft_strlen(line)))
		ft_safe_exit("The map extension is invalid");
	else
		fd = open(map_name, O_RDONLY);
	if (fd == -1)
		ft_safe_exit("Map not found");
	file_len = get_file_len(fd);
	if (file_len >= 20000)
		ft_safe_exit("Map is too big");
	read_map(map_name, data, file_len);
}

int	check_map_arguman(t_data *data)
{
	int	count;

	count = 0;
	if (data->map.no_path)
		count++;
	if (data->map.so_path)
		count++;
	if (data->map.we_path)
		count++;
	if (data->map.ea_path)
		count++;
	if (data->map.c_rgb[0] != -1)
		count++;
	if (data->map.f_rgb[0] != -1)
		count++;
	if (count == 6)
		return (1);
	return (0);
}
