/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:25:17 by keys              #+#    #+#             */
/*   Updated: 2022/11/21 21:24:31 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_pslist **lst)
{
	t_pslist	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	tmp->prev = (*lst);
	((tmp->next)->prev) = tmp;
	(*lst)->next = tmp;
	(*lst)->prev = NULL;
}

void	ft_r_swap(t_pslist **lst)
{
	t_pslist	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	(*lst)->prev = NULL;
	tmp->next = NULL;
	ft_pslstadd_back(lst, tmp);
}

void	ft_rr_swap(t_pslist **lst)
{
	t_pslist	*last;
	t_pslist	*tmp;

	last = ft_pslstlast(*lst);
	tmp = last->prev;
	tmp->next = NULL;
	last->prev = NULL;
	last->next = NULL;
	ft_pslstadd_front(lst, last);
}

void	ft_send_to_stack(t_pslist **send, t_pslist **reception)
{
	t_pslist	*tmp;

	tmp = *send;
	*send = (*send)->next;
	if (*send)
		(*send)->prev = NULL;
	ft_pslstadd_front(reception, tmp);
}
