/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 00:38:44 by tkurukay          #+#    #+#             */
/*   Updated: 2024/08/26 22:07:08 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../libft/libft.h"
#include <stdlib.h>

t_malloc	*get_garbage_c(void)
{
	static t_malloc	garbage_c = {NULL, NULL};

	return (&garbage_c);
}

void	*gc_malloc(unsigned int size)
{
	void		*ptr;
	t_malloc	*garbage_c;

	garbage_c = get_garbage_c();
	while (garbage_c->next)
		garbage_c = garbage_c->next;
	garbage_c->next = ft_calloc(1, sizeof(t_malloc));
	if (!garbage_c->next)
		ft_safe_exit("Memory allocation failed");
	ptr = ft_calloc(1, size);
	if (!ptr)
		ft_safe_exit("Memory allocation failed");
	*garbage_c->next = (t_malloc){.ptr = ptr, .next = NULL};
	return (ptr);
}

void	safe_free(void *ptr)
{
	if (!ptr)
		return ;
	garbage_collecter(ptr);
	free(ptr);
}
