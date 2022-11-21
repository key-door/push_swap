/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:04:56 by keys              #+#    #+#             */
/*   Updated: 2022/11/21 20:22:01 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_split_free(char **argv)
{
	int	i;

	i = 0;
	if (argv)
	{
		while (argv[i])
			i++;
		i--;
		while (i >= 0)
		{
			free(argv[i]);
			i--;
		}
		free(argv);
	}
}
int	ft_splitlen(char **argv)
{
	int	len;

	len = 0;
	while (argv[len])
		len++;
	return (len);
}
