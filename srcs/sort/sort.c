/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:31:07 by keys              #+#    #+#             */
/*   Updated: 2022/11/21 21:32:59 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_four_min_search(t_pslist **s_sa)
{
	t_pslist	*lst;
	int		min;
	int		i;
	int		index;

	i = 0;
	index = 0;
	lst = *s_sa;
	min = lst->rank;
	lst = lst->next;
	while (lst)
	{
		i++;
		if ((lst->rank) < min)
		{
			min = lst->rank;
			index = i;
		}
		lst = lst->next;
	}
	if (index == 0)
		return ;
	else if (index == 1)
		ft_ra(s_sa);
	else if (index == 2)
	{
		ft_ra(s_sa);
		ft_ra(s_sa);
	}
	else if (index == 3)
	{
		ft_rra(s_sa);
	}
}

void	ft_five_min_search(t_pslist **s_sa)
{
	t_pslist	*lst;
	int		min;
	int		i;
	int		index;

	i = 0;
	index = 0;
	lst = *s_sa;
	min = lst->rank;
	lst = lst->next;
	while (lst)
	{
		i++;
		if ((lst->rank) < min)
		{
			min = lst->rank;
			index = i;
		}
		lst = lst->next;
	}
	if (index == 0)
		return ;
	else if (index == 1)
		ft_ra(s_sa);
	else if (index == 2)
	{
		ft_ra(s_sa);
		ft_ra(s_sa);
	}
	if (index == 3)
	{
		ft_rra(s_sa);
		ft_rra(s_sa);
	}
	else if (index == 4)
	{
		ft_rra(s_sa);
	}
}

void	ft_radix_sort(t_pslist **s_sa, t_pslist **s_sb)
{
	int	i;
	int	size;

	i = 0;
	while (1)
	{
		if (ft_sorted(s_sa))
			break ;
		size = ft_pslstsize(*s_sa);
		while (size--)
		{
			if (((*s_sa)->rank >> i) & 1)
				ft_ra(s_sa);
			else
				ft_pb(s_sa, s_sb);
		}
		while (*s_sb)
		{
			ft_pa(s_sa, s_sb);
		}
		i++;
	}
}
