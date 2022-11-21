/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:54:23 by keys              #+#    #+#             */
/*   Updated: 2022/11/21 23:39:57 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pslist	*s_sa;
	t_pslist	*s_sb;

	s_sa = NULL;
	s_sb = NULL;
	argc = ft_make_stack(argc, argv, &s_sa);
	if (!ft_sorted(&s_sa))
	{
		if (argc <= 5)
			ft_five_sorts(&s_sa, &s_sb);
		else
			ft_radix_sort(&s_sa, &s_sb);
	}
	ft_pslstclear(&s_sa, NULL);
	return (0);
}
