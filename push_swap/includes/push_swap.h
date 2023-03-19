/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:04:20 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/19 20:33:41 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_stack {
	int				value;
	int				end_pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	ft_argv_sanitizer(char ***argv, int *argc);
char	*ft_strjoin_sep(char *s1, char *s2, char sep);

void	ft_error(int errno, t_stack **lst, t_stack **lst2);
int		ft_locate_int(int *tab, int tablen, int num);
void	ft_parse_argv(t_stack **dest, char **argv, int argc);
int		ft_parse_and_check_number(char *num, t_stack **tab, char **argv);
long	ft_atol_ps(const char *nptr, t_stack **tab);

void	ft_lsaddback(t_stack **lst, t_stack *new);
void	ft_lsaddfront(t_stack **lst, t_stack *new);
t_stack	*ft_lsnew(int content);
t_stack	*ft_lslast(t_stack *lst);
t_stack	*ft_lschr(t_stack *lst, int to_find);
void	ft_lsfree(t_stack *lst, t_stack *lst2);
t_stack	*ft_lsbeforelast(t_stack *lst);
int		ft_lslen(t_stack *lst);

void	ft_lswap(t_stack *lst, char *op);
void	ft_lpush(t_stack **ldest, t_stack **lsrc, char *op);
void	ft_lrotate(t_stack **lst, char *op);
void	ft_lrotateboth(t_stack **lst_a, t_stack **lst_b);
void	ft_lrrotate(t_stack **lst, char *op);
void	ft_lrrotateboth(t_stack **lst_a, t_stack **lst_b);
void	ft_all_stack_b_to_a_top(t_stack **a, t_stack *a_copy, t_stack **b);

int		ft_sort_three_elements(t_stack **lst_a, int mode);
int		ft_sort_five_elements(t_stack **lst_a);
int		ft_is_sorted(t_stack *lst);
void	ft_radix_sort(t_stack **lst_a, int bit_pos);
void	ft_pre_sort(t_stack *lst);
#endif