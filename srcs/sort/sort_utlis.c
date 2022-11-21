/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utlis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:02:37 by keys              #+#    #+#             */
/*   Updated: 2022/11/21 21:05:43 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_pslist **s_sa)
{
	t_pslist	*tmp;
	t_pslist	*nex;

	tmp = *s_sa;
	while (1)
	{
		nex = tmp->next;
		if (!nex)
		{
			return 1;
		}
		else if ((tmp->content) < (nex->content))
		{
			tmp = nex;
		}
		else
			break ;
	}
	return (0);
}
