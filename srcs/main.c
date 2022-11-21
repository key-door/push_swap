/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:54:23 by keys              #+#    #+#             */
/*   Updated: 2022/11/21 21:34:10 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	printstack(t_pslist *s_sa)
{
	// while (s_sa)
	// {
	// 	printf("content= %d\tprev= %p\tthis=%p\tnext=%p\n", s_sa->content,
	// 			s_sa->prev, s_sa, s_sa->next);
	// 	s_sa = s_sa->next;
	// }
	while (s_sa)
	{
		printf("content= %d\trank=%d\n", s_sa->content, s_sa->rank);
		s_sa = s_sa->next;
	}
}

void	ft_check_alpha(int argc, char **argv, int flag)
{
	char	**tmp;
	int		i;
	int		j;

	tmp = argv;
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (ft_isspace(tmp[i][j]))
			j++;
		if (tmp[i][j] == '-')
			j++;
		else if (tmp[i][j] == '+')
			j++;
		while (tmp[i][j])
		{
			if (ft_isdigit(tmp[i][j]))
				j++;
			else
			{
				if (flag == 1)
					ft_split_free(argv);
				exit(EXIT_SUCCESS);
			}
		}
		i++;
	}
}

void	ft_check_overflow(int argc, char **argv, int flag)
{
	long	tmp;
	int		i;

	i = 0;
	while (i < argc)
	{
		tmp = ft_atol(argv[i]);
		if ((long)INT_MIN <= tmp && tmp <= (long)INT_MAX)
			i++;
		else
		{
			if (flag == 1)
				ft_split_free(argv);
			exit(EXIT_SUCCESS);
		}
	}
}

void	ft_make_stack(t_pslist **s_sa, int argc, char **argv, int flag)
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

void	ft_error_check(t_pslist **s_sa, int argc, char **argv, int flag)
{
	ft_check_alpha(argc, argv, flag);
	ft_check_overflow(argc, argv, flag);
	ft_make_stack(s_sa, argc, argv, flag);
	ft_coordinate_compression(*s_sa, argc);
}

int	main(int argc, char **argv)
{
	t_pslist	*s_sa;
	t_pslist	*s_sb;
	int			*num_ary;
	int			i;

	s_sa = NULL;
	s_sb = NULL;
	if (argc <= 1)
		exit(EXIT_SUCCESS);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			exit(EXIT_FAILURE);
		argc = ft_splitlen(argv);
		ft_error_check(&s_sa, argc, argv, 1);
	}
	else if (argc >= 3)
		ft_error_check(&s_sa, --argc, ++argv, 0);
	if (!ft_sorted(&s_sa))
	{
		if (argc <= 5)
			ft_five_sorts(&s_sa, &s_sb);
		else
			ft_radix_sort(&s_sa, &s_sb);
	}
	printstack(s_sa);
	ft_pslstclear(&s_sa, NULL);
	return (0);
}
