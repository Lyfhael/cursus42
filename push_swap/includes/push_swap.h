/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:04:20 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/15 17:02:17 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_stack {
	int				value;
	struct s_stack	*next;
}   t_stack;

void	ft_error(int errno, t_stack **tab);

int		ft_locate_int(int *tab, int tablen, int num);
void	ft_parse_argv(t_stack **dest, char **argv, int argc);
int		ft_parse_and_check_number(char *num, t_stack **tab);
long	ft_atol_ps(const char *nptr, t_stack **tab);

void	ft_swap(int *tab, int tabsize, char op);
void	ft_push(int *t1, int *t2);

void	ft_lsaddback(t_stack **lst, t_stack *new);
t_stack	*ft_lsnew(int content);
t_stack	*ft_lslast(t_stack *lst);
t_stack *ft_lschr(t_stack *lst, int to_find);
