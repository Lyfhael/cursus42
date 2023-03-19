/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:50:29 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/19 19:37:42 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol_ps(const char *nptr, t_stack **tab)
{
	int		sign;
	long	res;

	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
		if (*(nptr++) == '-')
			sign = -1;
	res = 0;
	while (ft_isdigit(*nptr))
	{
		res = res * 10 + (*(nptr++) - 48);
		if (res > INT_MAX || res < INT_MIN)
			ft_error(1, tab, NULL);
	}
	if (*nptr != 0)
		ft_error(1, tab, NULL);
	return (res * sign);
}

int	ft_parse_and_check_number(char *num, t_stack **tab, char **argv)
{
	int	result;

	if (ft_strlen(num) == 1 && !ft_isdigit(num[0]))
	{
		ft_strsfree(argv);
		ft_error(1, tab, NULL);
	}
	result = ft_atol_ps(num, tab);
	if (ft_lschr(*tab, result))
	{
		ft_strsfree(argv);
		ft_error(1, tab, NULL);
	}
	return (result);
}

int	ft_is_sorted(t_stack *lst)
{
	int	tmp;
	int	is_sorted;
	int	num;

	is_sorted = 1;
	tmp = 0;
	while (lst)
	{
		num = lst->end_pos;
		if (num < tmp)
		{
			is_sorted = 0;
			break ;
		}
		tmp = num;
		lst = lst->next;
	}
	return (is_sorted);
}

void	ft_parse_argv(t_stack **dest, char **argv, int argc)
{
	int	num;

	while (argc-- > 0)
	{
		if (ft_strlen(argv[argc]) == 0)
			continue ;
		num = ft_parse_and_check_number(argv[argc], dest, argv);
		ft_lsaddfront(dest, ft_lsnew(num));
	}
}
