/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:12:10 by jschreye          #+#    #+#             */
/*   Updated: 2021/11/17 08:56:59 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ret;
	char	*s;
	int		cnt;
	int		c;

	s = (char *)str;
	cnt = 0;
	c = 0;
	va_start(ret, str);
	while (s[c])
	{
		if (s[c] == '%')
		{
			cnt = flags(&s[c], ret, cnt);
			c++;
		}
		else
		{
			write(1, &s[c], 1);
			cnt++;
		}
		c++;
	}
	va_end(ret);
	return (cnt);
}

int	flags(char *str, va_list ptr, int i)
{
	if (str[1] == 'c')
		i = ft_putchar(va_arg(ptr, int), i);
	else if (str[1] == 's')
		i = ft_putstr(va_arg(ptr, char *), i);
	else if (str[1] == 'x')
		i = ft_putnbrhex(va_arg(ptr, unsigned int), "0123456789abcdef", i);
	else if (str[1] == 'X')
		i = ft_putnbrhex(va_arg(ptr, unsigned int), "0123456789ABCDEF", i);
	else if (str[1] == 'p')
		i = ft_putnbrpointeur(va_arg(ptr, void *), "0123456789abcdef", i);
	else if (str[1] == 'u')
		i = ft_putnbrnbr(va_arg(ptr, unsigned int), i);
	else if ((str[1] == 'd') || (str[1] == 'i'))
		i = ft_putnbr(va_arg(ptr, int), i);
	else if (str[1] == '%')
		i = ft_putchar('%', i);
	return (i);
}
/*int main()
{
		
	ft_printf("%d", ft_printf("%s", "hello"));
}*/
