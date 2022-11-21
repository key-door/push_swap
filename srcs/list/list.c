/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:33:25 by keys              #+#    #+#             */
/*   Updated: 2022/11/21 21:45:28 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pslist	*ft_pslstnew(int content)
{
	t_pslist	*new_node;

	new_node = malloc(sizeof(t_pslist));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->rank = -1;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_pslist	*ft_pslstlast(t_pslist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_pslstadd_back(t_pslist **lst, t_pslist *new)
{
	t_pslist	*tmp;

	if (lst)
	{
		if (*lst)
		{
			tmp = ft_pslstlast(*lst);
			tmp->next = new;
			new->prev = tmp;
		}
		else
			*lst = new;
	}
}

void	ft_pslstadd_front(t_pslist **lst, t_pslist *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
	{
		new->next = *lst;
		(*lst)->prev = new;
	}
	*lst = new;
}

int	ft_pslstsize(t_pslist *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
