/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:14:45 by keys              #+#    #+#             */
/*   Updated: 2022/11/21 23:38:52 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_stack(t_pslist **s_sa, int argc, char **argv, int flag)
{
	t_pslist	*new;
	int			i;

	i = 0;
	while (i < argc)
	{
		new = ft_pslstnew(ft_atoi(argv[i]));
		if (!new)
		{
			if (flag == 1)
				ft_split_free(argv);
			ft_pslstclear(s_sa, NULL);
			exit(EXIT_FAILURE);
		}
		ft_pslstadd_back(s_sa, new);
		i++;
	}
	if (flag == 1)
		ft_split_free(argv);
}

int	ft_make_stack(int argc, char **argv, t_pslist **s_sa)
{
	if (argc <= 1)
		exit(EXIT_SUCCESS);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			exit(EXIT_FAILURE);
		argc = ft_splitlen(argv);
		if (argc <= 1)
		{
			ft_split_free(argv);
			exit(EXIT_SUCCESS);
		}
		ft_error_check(s_sa, argc, argv, 1);
	}
	else if (argc >= 3)
		ft_error_check(s_sa, --argc, ++argv, 0);
	return (argc);
}
