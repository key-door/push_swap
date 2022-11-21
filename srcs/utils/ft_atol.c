/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:04:00 by keys              #+#    #+#             */
/*   Updated: 2022/11/21 23:01:53 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ');
}

static long	ft_overlong(const char *str, unsigned long result, int base,
		long flag)
{
	unsigned long	cutoff;
	unsigned long	last;

	cutoff = (unsigned long)LONG_MAX / (unsigned long)base;
	last = (unsigned long)LONG_MAX % (unsigned long)base;
	if (result > cutoff)
		return (flag);
	else if (result <= cutoff)
	{
		if (((result == cutoff) && (((unsigned long)(*str - '0')) <= last))
			|| (result < cutoff))
		{
			result *= base;
			result += *str - '0';
			str++;
			if (((result < cutoff)) && ft_isdigit(*(++str)) == 0)
				return (flag);
		}
		else
			return (flag);
	}
	if (flag == (long)LONG_MIN)
		return (-result);
	return (result);
}

static long	ft_strtol(const char *str, int base, long flag)
{
	unsigned long	result;

	result = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			if (result >= ((unsigned long)LONG_MAX / (unsigned long)base))
				return (ft_overlong(str, result, base, flag));
			result *= base;
			result += *str - '0';
			str++;
		}
		else
			break ;
	}
	if (flag == (long)LONG_MIN)
	{
		return (-result);
	}
	return (result);
}

long	ft_atol(const char *nptr)
{
	long	ans;
	long	flag;
	int		i;

	i = 0;
	flag = LONG_MAX;
	while (ft_isspace((int)nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		flag = LONG_MIN;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	ans = ft_strtol(nptr, 10, flag);
	return (ans);
}
