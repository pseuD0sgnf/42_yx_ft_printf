/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:35:19 by yuxchen           #+#    #+#             */
/*   Updated: 2024/02/15 16:20:30 by yuxchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	putunbr_len(unsigned int num, int *len)
{
	if (num >= 10)
		putunbr_len(num / 10, len);
	putchar_len(num % 10 + '0', len);
}

void	putnbr_len(int num, int *len)
{
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (num < 0)
	{
		putchar_len('-', len);
		putnbr_len(num * -1, len);
	}
	else
	{
		if (num >= 10)
			putnbr_len(num / 10, len);
		putchar_len(num % 10 + '0', len);
	}
}

void	puthex_len(unsigned int ptr, int *len, char format)
{
	if (ptr >= 16)
		puthex_len(ptr / 16, len, format);
	ptr = ptr % 16;
	if (ptr < 10)
		putchar_len(ptr + '0', len);
	else
	{
		if (format == 'x')
			putchar_len(ptr - 10 + 'a', len);
		if (format == 'X')
			putchar_len(ptr - 10 + 'A', len);
	}
}

void	putptr(uintptr_t ptr, int *len)
{
	if (ptr >= 16)
		putptr(ptr / 16, len);
	ptr = ptr % 16;
	if (ptr < 10)
		putchar_len(ptr + '0', len);
	else
		putchar_len(ptr - 10 + 'a', len);
}

void	putptr_len(long unsigned int ptr, int *len)
{
	if (ptr == 0)
	{
		putstr_len("(nil)", len);
		return ;
	}
	else
	{
		(*len) += write(1, "0x", 2);
		putptr(ptr, len);
	}
}
