/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:51:41 by keys              #+#    #+#             */
/*   Updated: 2022/11/21 23:37:31 by keys             ###   ########.fr       */
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

/*check_arg*/
void				ft_error_check(t_pslist **s_sa, int argc, char **argv,
						int flag);

/*list*/
void				ft_pslstclear(t_pslist **lst, void (*del)(void *));
t_pslist			*ft_pslstnew(int content);
t_pslist			*ft_pslstlast(t_pslist *lst);
void				ft_pslstadd_back(t_pslist **lst, t_pslist *new);
void				ft_pslstadd_front(t_pslist **lst, t_pslist *new);
int					ft_pslstsize(t_pslist *lst);

/*make_stack*/
void				ft_push_stack(t_pslist **s_sa, int argc, char **argv,
						int flag);
int				ft_make_stack(int argc, char **argv, t_pslist **s_sa);

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

/*sort*/
int					ft_sorted(t_pslist **s_sa);
void				ft_five_sorts(t_pslist **s_sa, t_pslist **s_sb);
void				ft_four_min_search(t_pslist **s_sa);
void				ft_five_min_search(t_pslist **s_sa);
void				ft_radix_sort(t_pslist **s_sa, t_pslist **s_sb);

/*utils*/
void				ft_coordinate_compression(t_pslist *s_sa, int argc);
int					ft_isspace(int c);
long				ft_atol(const char *nptr);
void				ft_split_free(char **argv);
int					ft_splitlen(char **argv);

/*main*/
int					main(int argc, char **argv);
#endif
