/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:33:10 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/05 20:52:51 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(va_list *arg, const char c)
{
	if (c == 'c')
		return (ft_char_fd(va_arg(*arg, int), 1));
	else if (c == 's')
		return (ft_str_fd(va_arg(*arg, char *), 1));
	else if (c == 'p')
		return (ft_pointer(va_arg(*arg, unsigned long long), 1));
	else if (c == 'd')
		return (ft_number(va_arg(*arg, int), 1));
	else if (c == 'i')
		return (ft_number(va_arg(*arg, int), 1));
	else if (c == 'u')
		return (ft_unsigned_nbr(va_arg(*arg, unsigned int), 1));
	else if (c == 'x')
		return (ft_hexlower_nbr(va_arg(*arg, unsigned int), 1));
	else if (c == 'X')
		return (ft_hexupper_nbr(va_arg(*arg, unsigned int), 1));
	else if (c == '%')
		return (ft_char_fd(c, 1));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	if (!format)
		return (0);
	i = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			i += ft_check(&ap, *format);
		}
		else
		{
			i += write (1, format, 1);
		}
		format++;
	}
	va_end(ap);
	return (i);
}
