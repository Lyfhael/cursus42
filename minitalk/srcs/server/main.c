/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:32:01 by hateisse          #+#    #+#             */
/*   Updated: 2022/12/11 15:41:25 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_print(int signal)
{
    printf("OK %d", signal);
}

t_sigaction *init_sig_struct(void)
{
    t_sigaction *sig;

    sig = malloc(sizeof(*sig));
    sig->sa_handler = &ft_print;
    return (sig);
}

void    display_pid(void)
{
    printf("%d\n", getpid());
}

int main(void)
{
   display_pid();
   sigaction(SIGINT, init_sig_struct(), NULL);
   sleep(60);
   return (0);
}