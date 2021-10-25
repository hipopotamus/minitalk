/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:29:28 by sungwopa          #+#    #+#             */
/*   Updated: 2021/10/25 23:58:59 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_msg g_msg;

void	get_bit_by_bit(int bit)
{
	g_msg.c += ((bit & 1) << g_msg.size);
	g_msg.size++;
	if (g_msg.size == 7)
	{
		ft_putchar_fd(g_msg.c, 1);
		if (!g_msg.c)
			ft_putchar_fd('\n', 1);
		g_msg.c = 0;
		g_msg.size = 0;
	}
}

int	main(void)
{
	g_msg.c = 0;
	g_msg.size = 0;
	ft_putstr_fd("server pid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while(1)
	{
		signal(SIGUSR2, get_bit_by_bit);
		signal(SIGUSR1, get_bit_by_bit);
		pause();
	}
}
