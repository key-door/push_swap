/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:45:28 by kyoda             #+#    #+#             */
/*   Updated: 2022/11/21 21:23:57 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_two_sorts(t_pslist **s_sa)
{
	t_pslist	*tmp;

	if (((*s_sa)->rank) > ((*s_sa)->next)->rank)
	{
		tmp = *s_sa;
		*s_sa = (*s_sa)->next;
		tmp->prev = *s_sa;
		(*s_sa)->next = tmp;
		(*s_sa)->prev = NULL;
		tmp->next = NULL;
		ft_printf("sa\n");
	}
}

void	ft_three_sorts(t_pslist **s_sa)
{
	t_pslist	*tmp;


	tmp = (*s_sa)->next;
	if (((*s_sa)->rank) < (tmp->rank))
	{
		if (ft_sorted(s_sa))
			return ;
		else if (((*s_sa)->rank) > ((tmp->next)->rank))
			ft_rra(s_sa);
		else
		{
			ft_sa(s_sa);
			ft_ra(s_sa);
		}
	}
	else
	{
		if (((*s_sa)->rank) < ((tmp->next)->rank))
			ft_sa(s_sa);
		else if ((tmp->rank) < ((tmp->next)->rank))
			ft_ra(s_sa);
		else
		{
			ft_sa(s_sa);
			ft_rra(s_sa);
		}
	}
}


void	ft_five_sorts(t_pslist **s_sa, t_pslist **s_sb)
{
	int	size;

	size = ft_pslstsize(*s_sa);
	if (size == 2)
		ft_two_sorts(s_sa);
	else if (size == 3)
		ft_three_sorts(s_sa);
	if (size == 4)
	{
		ft_four_min_search(s_sa);
		ft_pb(s_sa, s_sb);
		ft_three_sorts(s_sa);
		ft_pa(s_sa, s_sb);
	}
	if (size == 5)
	{
		ft_five_min_search(s_sa);
		ft_pb(s_sa, s_sb);
		ft_four_min_search(s_sa);
		ft_pb(s_sa, s_sb);
		ft_three_sorts(s_sa);
		ft_pa(s_sa, s_sb);
		ft_pa(s_sa, s_sb);
	}
}
