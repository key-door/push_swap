/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:22:52 by keys              #+#    #+#             */
/*   Updated: 2022/11/21 21:15:07 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_pslist **lst)
{
	ft_swap(lst);
	ft_printf("sb\n");
}

void	ft_rb(t_pslist **s_sb)
{
	ft_r_swap(s_sb);
	ft_printf("rb\n");
}

void	ft_rrb(t_pslist **s_sb)
{
	ft_rr_swap(s_sb);
	ft_printf("rrb\n");
}
