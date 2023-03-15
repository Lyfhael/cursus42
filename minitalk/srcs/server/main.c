/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:32:01 by hateisse          #+#    #+#             */
/*   Updated: 2022/12/11 17:39:25 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_print(int signal)
{
    printf("OK %d", signal);
}

void    display_pid(void)
{
    printf("%d\n", getpid());
}

void handle_sig(int signal)
{
	printf("OK %d", signal);
}
int main(void)
{
	struct sigaction	sig;

	sig.sa_handler = &handle_sig;
	sigfillset(&sig.sa_mask);
	sig.sa_flags = 0;
	sigaction(SIGINT, &sig, NULL);
	sleep(60);
	return (0);
}