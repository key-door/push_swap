/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:56:48 by keys              #+#    #+#             */
/*   Updated: 2022/11/26 16:04:53 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_skip(char *tmp)
{
	int	j;

	j = 0;
	while (ft_isspace(tmp[j]))
		j++;
	if (tmp[j] == '-')
		j++;
	else if (tmp[j] == '+')
		j++;
	return (j);
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
		j = ft_skip(tmp[i]);
		while (tmp[i][j])
		{
			if (ft_isdigit(tmp[i][j]))
				j++;
			else
			{
				if (flag == 1)
					ft_split_free(argv);
				ft_printf("Error\n");
				exit(EXIT_SUCCESS);
			}
		}
		i++;
	}
}

static void	ft_check_overflow(int argc, char **argv, int flag)
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
			ft_printf("Error\n");
			exit(EXIT_SUCCESS);
		}
	}
}

static void	ft_check_samenbr(t_pslist **s_sa)
{
	t_pslist	*head;
	t_pslist	*tmp;

	head = *s_sa;
	tmp = head->next;
	while (tmp)
	{
		while (tmp)
		{
			if ((head->content) == (tmp->content))
			{
				ft_pslstclear(s_sa, NULL);
				ft_printf("Error\n");
				exit(EXIT_SUCCESS);
			}
			tmp = tmp->next;
		}
		head = head->next;
		tmp = head->next;
	}
}

void	ft_error_check(t_pslist **s_sa, int argc, char **argv, int flag)
{
	ft_check_alpha(argc, argv, flag);
	ft_check_overflow(argc, argv, flag);
	ft_push_stack(s_sa, argc, argv, flag);
	ft_check_samenbr(s_sa);
	ft_coordinate_compression(*s_sa, argc);
}
