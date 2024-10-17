/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 00:38:41 by tkurukay          #+#    #+#             */
/*   Updated: 2024/08/26 22:05:49 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include <stdlib.h>

void	add_garbage_c(void *ptr)
{
	t_malloc	*garbage_c;

	if (!ptr)
		ft_safe_exit("Memory allocation failed");
	garbage_c = get_garbage_c();
	while (garbage_c->next)
		garbage_c = garbage_c->next;
	garbage_c->next = ft_calloc(1, sizeof(t_malloc));
	if (!garbage_c->next)
	{
		free(ptr);
		ft_safe_exit("Memory allocation failed");
	}
	*garbage_c->next = (t_malloc){.ptr = ptr, .next = NULL};
}

void	garbage_collecter(void *ptr)
{
	t_malloc	*garbage_c;
	t_malloc	*tmp;

	if (!ptr)
		return ;
	tmp = NULL;
	garbage_c = get_garbage_c();
	while (garbage_c)
	{
		if (garbage_c->ptr == ptr)
		{
			tmp->next = garbage_c->next;
			free(garbage_c);
			return ;
		}
		tmp = garbage_c;
		garbage_c = garbage_c->next;
	}
}

void	gc_free(void)
{
	t_malloc	*tmp;
	t_malloc	*garbage_c;

	tmp = NULL;
	garbage_c = get_garbage_c()->next;
	while (garbage_c)
	{
		tmp = garbage_c;
		garbage_c = garbage_c->next;
		if (tmp->ptr)
			free(tmp->ptr);
		free(tmp);
	}
}
