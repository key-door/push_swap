/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab_operation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:30:22 by keys              #+#    #+#             */
/*   Updated: 2022/11/21 21:27:33 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_pslist **s_sa, t_pslist **s_sb)
{
	ft_swap(s_sa);
	ft_swap(s_sb);
	ft_printf("ss\n");
}

void	ft_rr(t_pslist **s_sa, t_pslist **s_sb)
{
	ft_r_swap(s_sa);
	ft_r_swap(s_sb);
	ft_printf("rr\n");
}

void	ft_rrr(t_pslist **s_sa, t_pslist **s_sb)
{
	ft_rr_swap(s_sa);
	ft_rr_swap(s_sb);
	ft_printf("rrr\n");
}

void	ft_pa(t_pslist **s_sa, t_pslist **s_sb)
{
	if (!((*s_sb)->next))
	{
		ft_pslstadd_front(s_sa, *s_sb);
		*s_sb = NULL;
	}
	else
		ft_send_to_stack(s_sb, s_sa);
	ft_printf("pa\n");
}

void	ft_pb(t_pslist **s_sa, t_pslist **s_sb)
{
	if (!(*s_sb))
	{
		*s_sb = *s_sa;
		*s_sa = (*s_sa)->next;
		(*s_sa)->prev = NULL;
		(*s_sb)->next = NULL;
	}
	else
		ft_send_to_stack(s_sa, s_sb);
	ft_printf("pb\n");
}
