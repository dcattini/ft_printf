/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcattini <dcattini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:09:14 by dcattini          #+#    #+#             */
/*   Updated: 2022/04/04 15:23:10 by dcattini         ###   ########.fr       */
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

//Prints an integer in base 10 %i 
int	ft_putnbrun(unsigned int nb)
{
	int	counter;

	counter = 0;
	counter += conversor(nb, "0123456789", 10);
	return (counter);
}
