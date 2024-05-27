/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:56:53 by yuxchen           #+#    #+#             */
/*   Updated: 2024/02/15 12:53:43 by yuxchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	putarg_len(char format, int *len, int *i, va_list args);
void	putchar_len(char str, int *len);
void	putstr_len(char *str, int *len);
void	putptr(uintptr_t ptr, int *len);
void	putptr_len(long unsigned int ptr, int *len);
void	putnbr_len(int num, int *len);
void	putunbr_len(unsigned int num, int *len);
void	puthex_len(unsigned int ptr, int *len, char format);

#endif