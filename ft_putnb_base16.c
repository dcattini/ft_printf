/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb_base16.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcattini <dcattini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:08:23 by dcattini          #+#    #+#             */
/*   Updated: 2022/04/04 15:22:59 by dcattini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversor(unsigned int num, char *base, unsigned int len)
{
	int	counter;

	counter = 0;
	if (num > (len - 1))
		counter += conversor((num / len), base, len);
	counter += write(1, &base[(num % len)], 1);
	return (counter);
}

//Prints an integer in base 16 %x and %X
int	ft_putnb_base16(unsigned int nb, char c)
{
	int	counter;

	counter = 0;
	if (c == 'x')
		counter += conversor(nb, "0123456789abcdef", 16);
	else if (c == 'X')
		counter += conversor(nb, "0123456789ABCDEF", 16);
	return (counter);
}
