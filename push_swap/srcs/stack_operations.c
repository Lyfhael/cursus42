/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:50:55 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/15 17:04:47 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pswap(int *t1, int *t2, char *op)
{
	int tmp;

	tmp = *t1;
	*t1 = *t2;
	*t2 = tmp;
	ft_putstr(op);
	ft_putchar_fd('\n', 1);
}

// void	ft_push(int *t1, int *t2)
// {
	
// }