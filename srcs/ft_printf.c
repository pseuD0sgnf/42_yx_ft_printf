/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:27:37 by yuxchen           #+#    #+#             */
/*   Updated: 2024/02/16 11:35:25 by yuxchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	putchar_len(char str, int *len)
{
	write(1, &str, 1);
	(*len)++;
}

void	putstr_len(char *str, int *len)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (str[i])
		putchar_len(str[i++], len);
}

void	putarg_len(char format, int *len, int *i, va_list args)
{
	if (format == 'c')
		putchar_len(va_arg(args, int), len);
	else if (format == 's')
		putstr_len(va_arg(args, char *), len);
	else if (format == 'p')
		putptr_len(va_arg(args, long unsigned int), len);
	else if (format == 'd' || format == 'i')
		putnbr_len(va_arg(args, int), len);
	else if (format == 'u')
		putunbr_len(va_arg(args, unsigned int), len);
	else if (format == 'x' || format == 'X')
		puthex_len(va_arg(args, unsigned int), len, format);
	else if (format == '%')
		putstr_len("%", len);
	else
		(*i)--;
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			putarg_len(str[i], &len, &i, args);
			i++;
		}
		else
			putchar_len(str[i++], &len);
	}
	va_end(args);
	return (len);
}

// #include <stdio.h>
// #include <limits.h>
// int    main()
// {
//     // char    character = 'A';
//     // char    *string = "Hello";
//     // int     integer = -42;
//     // unsigned int    uninteger = 42;
//     // void    *ptr = (void *)string;
//     // int     count;

//     // count = printf("%c\n", character);
//     // printf("count is %d\n", count);
//     // count = printf("%s\n", string);
//     // printf("count is %d\n", count);
//     // count = printf("%p\n", ptr);
//     // printf("count is %d\n", count);
//     // count = printf(" %p %p ", 0, 0);
//     // printf("count is %d\n", count);
//     // count = printf("%d\n", integer);
//     // printf("count is %d\n", count);
//     // count = printf("%i\n", integer);
//     // printf("count is %d\n", count);
//     // count = printf("%u\n", uninteger);
//     // printf("count is %d\n", count);
//     // count = printf("%x\n", uninteger);
//     // printf("count is %d\n", count);
//     // count = printf("%X\n", uninteger);
//     // printf("count is %d\n", count);
//     // count = printf("%%\n");
//     // printf("count is %d\n", count);
//     int count_ft = ft_printf(" %x ", LONG_MAX);
//     printf("count is %d\n", count_ft);
// }
