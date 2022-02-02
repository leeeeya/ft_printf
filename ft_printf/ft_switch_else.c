/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch_else.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:40:39 by cstefany          #+#    #+#             */
/*   Updated: 2021/11/18 16:40:41 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_unsign(unsigned int n)
{
	int	res;

	res = 1;
	if (n >= 0 && n < 10)
	{
		ft_putchar_fd(n + 48, 1);
	}
	else
	{
		res += put_unsign(n / 10);
		ft_putchar_fd(n % 10 + 48, 1);
	}
	return (res);
}

void	putchar_hex(unsigned long long digit, int ch, int b)
{
	if (b != 'p')
		digit = (unsigned int)digit;
	if (digit > 9)
		ft_putchar_fd(digit + ch, 1);
	else
		ft_putchar_fd(digit + 48, 1);
}

int	put_hex(unsigned long long Xx, char b)
{
	int	ch;
	int	res;

	res = 1;
	if (b != 'p')
		Xx = (unsigned int)Xx;
	if (b == 'x' || b == 'p')
		ch = 87;
	else
		ch = 55;
	if (Xx >= 0 && Xx < 16)
		putchar_hex(Xx, ch, b);
	else
	{
		res += put_hex(Xx / 16, b);
		putchar_hex(Xx % 16, ch, b);
	}
	return (res);
}

int	if_string(va_list *ap)
{
	char	*s;
	int		count_ch;

	s = (va_arg(*ap, char *));
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		count_ch = 6;
	}
	else
	{
		ft_putstr_fd(s, 1);
		count_ch = ft_strlen(s);
	}
	return (count_ch);
}

int	ft_switch_else(char format, va_list *ap)
{
	int					count_ch;
	unsigned long long	u;

	if (format == 'u')
	{
		u = (va_arg(*ap, unsigned int));
		count_ch = put_unsign(u);
	}
	if (format == 'x' || format == 'X')
	{
		u = va_arg(*ap, unsigned long long);
		count_ch = put_hex(u, format);
	}
	if (format == 'p')
	{
		write(1, "0x", 2);
		u = va_arg(*ap, unsigned long long);
		count_ch = put_hex(u, 'p') + 2;
	}
	if (format == 's')
		count_ch = if_string(ap);
	return (count_ch);
}
