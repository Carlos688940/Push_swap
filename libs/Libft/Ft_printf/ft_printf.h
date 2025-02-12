/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:33:17 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/05 18:04:06 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_char_fd(char c, int fd);
int	ft_str_fd(char *s, int fd);
int	ft_pointer(unsigned long long n, int fd);
int	ft_number(int n, int fd);
int	ft_unsigned_nbr(unsigned int n, int fd);
int	ft_hexlower_nbr(unsigned int n, int fd);
int	ft_hexupper_nbr(unsigned int n, int fd);

#endif