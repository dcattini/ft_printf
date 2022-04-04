/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcattini <dcattini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:10:04 by dcattini          #+#    #+#             */
/*   Updated: 2022/04/04 15:35:56 by dcattini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversor(int num, char *base, int len)
{
	int	counter;

	counter = 0;
	if (num < -(len - 1) || num > (len - 1))
		counter += conversor((num / len), base, len);
	if (num < 0)
		counter += write(1, &base[(num % len) * (-1)], 1);
	else
		counter += write(1, &base[(num % len)], 1);
	return (counter);
}

//Prints an integer in base 10 %i 
int	ft_putnbr(int nb)
{
	int	counter;

	counter = 0;
	if (nb < 0)
		counter += write(1, "-", 1);
	counter += conversor(nb, "0123456789", 10);
	return (counter);
}
