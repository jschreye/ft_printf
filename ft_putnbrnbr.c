/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr++.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 08:59:50 by jschreye          #+#    #+#             */
/*   Updated: 2021/11/16 16:01:21 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putnbrnbr(unsigned int nb, int c)
{
	if (nb >= 10)
	{
		c = ft_putnbrnbr(nb / 10, c + 1);
		ft_putnbrnbr(nb % 10, 0);
	}
	else
		c = ft_putchar(nb + '0', c);
	return (c);
}
