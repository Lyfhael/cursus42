/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:45:38 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/15 16:52:16 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int errno, t_stack **tab)
{
	if (tab)
		free(tab);
	if (errno == 1)
		ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	 ft_locate_int(int *tab, int tablen, int num)
{
	while (tablen--)
		if (tab[tablen] == num)
			return (1);
	return (0);
}

int main(int argc, char **argv)
{
	t_stack *tab;

	tab = NULL;
	if (argc < 2)
		ft_error(0, NULL);
	ft_parse_argv(&tab, argv, argc);
	while (argc--)
	{
		ft_putnbr_fd(tab->value, 1);
		ft_putchar('\n');
		tab = tab->next;
	}
	return (0);
}
