/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:45:38 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/19 20:33:59 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int errno, t_stack **lst, t_stack **lst2)
{
	if (lst)
		ft_lsfree(*lst, NULL);
	if (lst2)
		ft_lsfree(*lst2, NULL);
	if (errno == 1)
		ft_putstr_fd("Error\n", 2);
	if (errno == 2)
		exit(0);
	exit(1);
}

int	ft_locate_int(int *tab, int tablen, int num)
{
	while (tablen--)
		if (tab[tablen] == num)
			return (1);
	return (0);
}

int	ft_determine_max_bit_pos(t_stack *lst)
{
	int	max;
	int	current;
	int	value_copy;

	max = 0;
	current = 0;
	while (lst)
	{
		value_copy = lst->end_pos;
		current = 0;
		while (value_copy)
		{
			value_copy >>= 1;
			current++;
		}
		if (current > max)
			max = current;
		lst = lst->next;
	}
	return (max);
}

int	main(int argc, char **argv)
{
	int		i;
	int		max_bit;
	t_stack	*lst;

	lst = NULL;
	if (argc < 2)
		ft_error(0, NULL, NULL);
	ft_argv_sanitizer(&argv, &argc);
	ft_parse_argv(&lst, argv, argc);
	ft_pre_sort(lst);
	if (ft_is_sorted(lst))
		return (ft_strsfree(argv), 0);
	if (ft_lslen(lst) == 3)
		return (ft_strsfree(argv), ft_sort_three_elements(&lst, 1));
	else if (ft_lslen(lst) == 5)
		return (ft_strsfree(argv), ft_sort_five_elements(&lst));
	max_bit = ft_determine_max_bit_pos(lst);
	i = 0;
	while (i < max_bit && !ft_is_sorted(lst))
		ft_radix_sort(&lst, i++);
	ft_lsfree(lst, NULL);
	ft_strsfree(argv);
	return (0);
}
