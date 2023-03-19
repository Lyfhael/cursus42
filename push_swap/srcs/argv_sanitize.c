/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_sanitize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:39:23 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/19 17:47:18 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

char	*ft_strjoin_sep(char *s1, char *s2, char sep)
{
	char	*res;
	char	*tmp;

	tmp = NULL;
	if (sep)
	{
		res = ft_strjoin(s1, " ");
		tmp = res;
	}
	else
		res = s1;
	res = ft_strjoin(res, s2);
	if (tmp)
		free(tmp);
	free(s1);
	return (res);
}

void	ft_argv_sanitizer(char ***argv, int *argc)
{
	int		i;
	char	*concat_argv;

	i = 0;
	concat_argv = NULL;
	while (++i < *argc)
	{
		if (i == 1)
			concat_argv = ft_strjoin_sep(concat_argv, argv[0][i], 0);
		else
			concat_argv = ft_strjoin_sep(concat_argv, argv[0][i], ' ');
	}
	*argv = ft_split(concat_argv, ' ');
	if (concat_argv)
		free(concat_argv);
	*argc = ft_strslen(*argv);
}
