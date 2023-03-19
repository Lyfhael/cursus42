/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:50:55 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/19 20:35:56 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lswap(t_stack *lst, char *op)
{
	int	tmp;

	if (lst && lst->next)
	{
		tmp = lst->value;
		lst->value = lst->next->value;
		lst->next->value = tmp;
		tmp = lst->end_pos;
		lst->end_pos = lst->next->end_pos;
		lst->next->end_pos = tmp;
		if (op)
		{
			ft_putstr(op);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	ft_lpush(t_stack **ldest, t_stack **lsrc, char *op)
{
	t_stack	*tmp;

	if (lsrc)
	{
		tmp = (*lsrc)->next;
		ft_lsaddfront(ldest, *lsrc);
		*lsrc = tmp;
		if (op)
		{
			ft_putstr(op);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	ft_lrotate(t_stack **lst, char *op)
{
	t_stack	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_lslast(*lst)->next = tmp;
		tmp->next = NULL;
		if (op)
		{
			ft_putstr(op);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	ft_lrrotate(t_stack **lst, char *op)
{
	t_stack	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = ft_lslast(*lst);
		ft_lsbeforelast(*lst)->next = NULL;
		ft_lsaddfront(lst, tmp);
		if (op)
		{
			ft_putstr(op);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	ft_all_stack_b_to_a_top(t_stack **a, t_stack *a_copy, t_stack **b)
{
	t_stack	*b_copy;

	b_copy = *b;
	if (a_copy)
	{
		while (b_copy)
			ft_lpush(&a_copy, &b_copy, "pa");
		*a = a_copy;
	}
	else
	{
		while (b_copy)
			ft_lpush(a, &b_copy, "pa");
	}
}
