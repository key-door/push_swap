/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:51:41 by keys              #+#    #+#             */
/*   Updated: 2022/11/21 21:31:49 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 01:02:32 by keys              #+#    #+#             */
/*   Updated: 2022/11/21 16:01:51 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/include/ft_printf.h"

typedef struct s_pslist
{
	int				content;
	int				rank;
	struct s_pslist	*prev;
	struct s_pslist	*next;
}					t_pslist;

/*main.c*/
int					main(int argc, char **argv);

/*utils.c*/
int					ft_splitlen(char **argv);
void				ft_split_free(char **argv);
void				ft_coordinate_compression(t_pslist *s_sa, int argc);

/*ft_atol*/
int					ft_isspace(int c);
static long			ft_overlong(const char *str, unsigned long result, int base,
						long flag);
static long			ft_strtol(const char *str, int base, long flag);
long				ft_atol(const char *nptr);

/*list*/
void				ft_pslstdelone(t_pslist *lst, void (*del)(void *));
void				ft_pslstclear(t_pslist **lst, void (*del)(void *));
t_pslist			*ft_pslstnew(int content);
void				ft_pslstadd_back(t_pslist **lst, t_pslist *new);
t_pslist			*ft_pslstlast(t_pslist *lst);
void				ft_pslstadd_front(t_pslist **lst, t_pslist *new);
int					ft_pslstsize(t_pslist *lst);

/*sort*/
int					ft_sorted(t_pslist **s_sa);

/*operation*/
void				ft_sa(t_pslist **s_sa);
void				ft_ra(t_pslist **s_sa);
void				ft_rra(t_pslist **s_sa);
void				ft_ss(t_pslist **s_sa, t_pslist **s_sb);
void				ft_rr(t_pslist **s_sa, t_pslist **s_sb);
void				ft_rrr(t_pslist **s_sa, t_pslist **s_sb);
void				ft_pa(t_pslist **s_sa, t_pslist **s_sb);
void				ft_pb(t_pslist **s_sa, t_pslist **s_sb);
void				ft_sb(t_pslist **lst);
void				ft_rb(t_pslist **s_sb);
void				ft_rrb(t_pslist **s_sb);
void				ft_swap(t_pslist **lst);
void				ft_r_swap(t_pslist **lst);
void				ft_rr_swap(t_pslist **lst);
void				ft_send_to_stack(t_pslist **send, t_pslist **reception);

/*sort_utils*/
int					ft_sorted(t_pslist **s_sa);
void				ft_four_min_search(t_pslist **s_sa);
void				ft_five_min_search(t_pslist **s_sa);
void				ft_radix_sort(t_pslist **s_sa, t_pslist **s_sb);

/*sort*/
void				ft_two_sorts(t_pslist **s_sa);
void				ft_three_sorts(t_pslist **s_sa);
void				ft_five_sorts(t_pslist **s_sa, t_pslist **s_sb);

#endif
