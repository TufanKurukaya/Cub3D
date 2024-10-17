/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 00:39:06 by tkurukay          #+#    #+#             */
/*   Updated: 2024/08/24 00:39:07 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	ft_strslen(char **strs)
{
	int	i;

	i = -1;
	while (*strs && strs[++i])
		;
	return (i);
}

int	skip_white_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == 32 || (str[i] <= 13 && str[i] >= 7)))
		i++;
	return (i);
}

int	valid_char(char chr)
{
	if (chr == '0' || chr == '1' || chr == 'E' || chr == 'S' || chr == 'N'
		|| chr == 'W')
		return (1);
	else
	{
		if ((chr == 32 || (chr <= 13 && chr >= 7)))
			return (0);
		else
			ft_safe_exit("Invalid character in map");
	}
	return (-1);
}
