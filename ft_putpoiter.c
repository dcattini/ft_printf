/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcattini <dcattini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:41:49 by dcattini          #+#    #+#             */
/*   Updated: 2022/04/04 15:23:21 by dcattini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversor(unsigned long int num, char *base, unsigned int len)
{
	int	counter;

	counter = 0;
	if (num > (len - 1))
		counter += conversor((num / len), base, len);
	counter += write(1, &base[(num % len)], 1);
	return (counter);
}

//Prints an pointer in base 16 
int	ft_putpoiter(void *point)
{
	int					counter;
	unsigned long int	a;

	counter = 0;
	a = (unsigned long int)point;
	counter += write(1, "0", 1);
	counter += write(1, "x", 1);
	counter += conversor(a, "0123456789abcdef", 16);
	return (counter);
}
