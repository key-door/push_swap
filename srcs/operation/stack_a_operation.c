/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:22:50 by keys              #+#    #+#             */
/*   Updated: 2022/11/21 21:27:32 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_pslist **s_sa)
{
	ft_swap(s_sa);
	ft_printf("sa\n");
}

void	ft_ra(t_pslist **s_sa)
{
	ft_r_swap(s_sa);
	ft_printf("ra\n");
}

void	ft_rra(t_pslist **s_sa)
{
	ft_rr_swap(s_sa);
	ft_printf("rra\n");
}
