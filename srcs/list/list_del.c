/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:34:49 by keys              #+#    #+#             */
/*   Updated: 2022/11/21 20:45:42 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pslstdelone(t_pslist *lst, void (*del)(void *))
{
	if (lst)
	{
		if (del)
			del(&(lst->content));
		free(lst);
	}
}

void	ft_pslstclear(t_pslist **lst, void (*del)(void *))
{
	t_pslist	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_pslstdelone(tmp, del);
	}
}
