/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:40:13 by cstefany          #+#    #+#             */
/*   Updated: 2021/11/18 16:40:20 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	if_digit(va_list *ap)
{
	char	*s;
	int		count_ch;

	s = ft_itoa(va_arg(*ap, int));
	count_ch = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (count_ch);
}

int	ft_switch(char format, va_list *ap)
{
	int	count_ch;
	int	c;

	if (format == 'd' || format == 'i' )
		count_ch = if_digit(ap);
	else if (format == 'c')
	{
		count_ch = 1;
		c = va_arg(*ap, int);
		write (1, &c, 1);
	}
	else if (format == '%')
	{
		write(1, "%", 1);
		count_ch = 1;
	}
	else
		return (ft_switch_else(format, ap));
	return (count_ch);
}

int	ft_printf(const char *frmt, ...)
{
	va_list	arg_ptr;
	int		num;

	num = 0;
	va_start(arg_ptr, frmt);
	while (*frmt)
	{
		while (*frmt != '%' && *frmt != '\0')
		{
			write(1, frmt, 1);
			frmt++;
			num++;
		}
		if (*frmt == '%')
		{
			frmt++;
			if (*frmt == '\0')
				break ;
			num = num + ft_switch(*frmt, &arg_ptr);
			frmt++;
		}
	}
	va_end(arg_ptr);
	return (num);
}
