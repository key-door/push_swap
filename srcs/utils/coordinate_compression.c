/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:31:18 by keys              #+#    #+#             */
/*   Updated: 2022/11/23 22:11:44 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_coordinate_compression(t_pslist *s_sa, int argc)
{
	int			min;
	int			i;
	int			j;
	t_pslist	*tmp;
	t_pslist	*s_min;

	i = 0;
	while (i < argc)
	{
		j = 0;
		tmp = s_sa;
		min = INT_MAX;
		while (j < argc)
		{
			if ((tmp->rank == -1) && ((tmp->content) <= min))
			{
				s_min = tmp;
				min = tmp->content;
			}
			tmp = tmp->next;
			j++;
		}
		s_min->rank = i;
		i++;
	}
}
