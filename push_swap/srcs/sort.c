/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:31:16 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/19 21:09:32 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix_sort(t_stack **lst_a, int bit_pos)
{
	int		counter;
	t_stack	*lst_a_copy;
	t_stack	*lst_b;

	lst_a_copy = *lst_a;
	lst_b = NULL;
	counter = ft_lslen(lst_a_copy);
	while (counter)
	{
		if (((lst_a_copy->end_pos >> bit_pos) & 1) == 0)
			ft_lpush(&lst_b, &lst_a_copy, "pb");
		else
			ft_lrotate(&lst_a_copy, "ra");
		counter--;
	}
	ft_all_stack_b_to_a_top(lst_a, lst_a_copy, &lst_b);
}

int	ft_sort_three_elements_reverse(t_stack **lst, int mode)
{
	if ((*lst)->end_pos == 0)
	{
		if ((*lst)->next->end_pos == 1)
			return (ft_lswap(*lst, "sb"), ft_lrrotate(lst, "rrb"), 0);
		else
			return (ft_lrotate(lst, "rb"), 0);
	}
	else if ((*lst)->end_pos == 1)
	{
		if ((*lst)->next->end_pos == 2)
			return (ft_lswap(*lst, "sb"), 0);
		else
			return (ft_lrrotate(lst, "rrb"), 0);
	}
	else
	{
		if ((*lst)->next->end_pos == 0)
			return (ft_lrrotate(lst, "rrb"), ft_lswap(*lst, "sb"), 0);
	}
	if (mode)
		ft_lsfree(*lst, NULL);
	return (0);
}

int	ft_sort_five_elements(t_stack **lst_a)
{
	t_stack	*lst_b;

	lst_b = NULL;
	while (ft_lslen(*lst_a) > 2)
	{
		if ((*lst_a)->end_pos < 3)
			ft_lpush(&lst_b, lst_a, "pb");
		else
			ft_lrotate(lst_a, "ra");
	}
	if ((*lst_a)->end_pos == 4)
		ft_lrotate(lst_a, "ra");
	ft_sort_three_elements_reverse(&lst_b, 0);
	ft_all_stack_b_to_a_top(lst_a, NULL, &lst_b);
	ft_lsfree(*lst_a, NULL);
	return (0);
}

int	ft_sort_three_elements(t_stack **lst, int mode)
{
	if ((*lst)->end_pos == 2)
	{
		if ((*lst)->next->end_pos == 0)
			ft_lrotate(lst, "ra");
		else
			return (ft_lswap(*lst, "sa"), ft_lrrotate(lst, "rra"), 0);
	}
	else if ((*lst)->end_pos == 0)
	{
		if ((*lst)->next->end_pos == 2)
			return (ft_lrrotate(lst, "rra"), ft_lswap(*lst, "sa"), 0);
	}
	else
	{
		if ((*lst)->next->end_pos == 0)
			ft_lswap(*lst, "sa");
		else
			ft_lrrotate(lst, "rra");
	}
	if (mode)
		ft_lsfree(*lst, NULL);
	return (0);
}

void	ft_pre_sort(t_stack *lst)
{
	int		i;
	t_stack	*lst_copy;
	t_stack	*first_node;

	first_node = lst;
	while (lst)
	{
		lst_copy = first_node;
		i = 0;
		while (lst_copy)
		{
			if (lst_copy->value < lst->value)
				i++;
			lst_copy = lst_copy->next;
		}
		lst->end_pos = i;
		lst = lst->next;
	}
}
