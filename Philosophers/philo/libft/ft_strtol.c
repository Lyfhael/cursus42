/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 06:30:57 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/15 13:42:46 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

static int	detect_base(char *nptr)
{
	int	base;

	base = 10;
	if (!ft_strncmp(nptr, "0x", 2) || !ft_strncmp(nptr, "0X", 2))
		base = 16;
	else if (!ft_strncmp(nptr, "0", 1))
		base = 8;
	return (base);
}

static int	check_base(char **nptr, int *base)
{
	if (*base == 0)
		*base = detect_base(*nptr);
	else if (*base < 2 || *base > 36)
		return (-1);
	if (*base == 16 && (!ft_strncmp(*nptr, "0x", 2)
			|| !ft_strncmp(*nptr, "0X", 2)))
		*nptr += 2;
	return (0);
}

static int	is_in_base(const char *nptr, int baseno)
{
	int		i;
	char	*base;

	base = "0123456789abcdefghijklmnopqrstuvwxyz";
	i = -1;
	while (++i < baseno && base[i])
		if (*nptr == base[i])
			return (i);
	return (-1);
}

static int	check_limits(long *n, short sign, int base)
{
	int		log;
	long	n2;

	n2 = *n;
	log = 0;
	while (n2 > 1)
	{
		n2 /= 10;
		log++;
	}
	log *= base;
	if (log == sizeof(long) * 8 && sign == 1)
		*n = LONG_MAX;
	else if (log == sizeof(long) * 8 && *n != LONG_MIN && sign == -1)
		*n = LONG_MIN;
	else
		return (0);
	return (-1);
}

long	ft_strtol(const char *nptr, const char **endptr, int base)
{
	long	result;
	short	sign;

	result = 0;
	if (check_base((char **)&nptr, &base) < 0)
		return (result);
	sign = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign = -1;
	if (endptr)
		*endptr = ft_strchr(nptr, 0);
	while (is_in_base(nptr, base) >= 0)
	{
		if (check_limits(&result, sign, base))
			return (result);
		result = (result * base) + is_in_base(nptr++, base);
	}
	if (endptr)
		*endptr = (char *)nptr;
	return (result * sign);
}
