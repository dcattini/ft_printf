/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcattini <dcattini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:47:33 by dcattini          #+#    #+#             */
/*   Updated: 2022/04/04 15:18:15 by dcattini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lookforletter(char *str, int i, va_list *argm)
{
	if (str[i] == '%')
		return (ft_putchar('%'));
	if (str[i] == 'c')
		return (ft_putchar(va_arg(*argm, int)));
	if (str[i] == 's')
		return (ft_putstr(va_arg(*argm, char *)));
	if (str[i] == 'i' || str[i] == 'd')
		return (ft_putnbr(va_arg(*argm, int)));
	if (str[i] == 'x' || str[i] == 'X')
		return (ft_putnb_base16(va_arg(*argm, unsigned int), str[i]));
	if (str[i] == 'u')
		return (ft_putnbrun(va_arg(*argm, unsigned int)));
	if (str[i] == 'p')
		return (ft_putpoiter(va_arg(*argm, void *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	argm;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	va_start(argm, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			counter += ft_lookforletter((char *)str, i, &argm);
		}
		else
			counter += write (1, &str[i], 1);
		i++;
	}
	va_end(argm);
	return (counter);
}

/*int main(void)
{ 
	int a = 10;
	int z = -10;
	unsigned int u = 12;
	int *b = &a;
	char c = 65;
	char str[11] = "%string%";
	
	//%c Prints a single character
	printf("%c\n", c);
	ft_printf("%c\n\n", c);
	//%s Prints a string
	printf("%s\n", str);
	ft_printf("%s\n\n", str);
	//%p The void * pointer argument has to be printed in hexadecimal format
	printf("%p\n",b);
	ft_printf("%p\n\n",b);
	//%d Prints a decimal (base 10) number
	printf("%d\n", a);
	ft_printf("%d\n\n", a);
	printf("%d\n", z);
	ft_printf("%d\n\n", z);
	//%i Prints an integer in base 10
	printf("%i\n", a);
	ft_printf("%i\n\n", a);
	printf("%i\n", z);
	ft_printf("%i\n\n", z);
	//%u Prints an unsigned decimal (base 10) number
	printf("%u\n", u);
	ft_printf("%u\n\n", u);
	//%x Prints a number in hexadecimal (base 16) lowercase format
	printf("%x\n", u);
	ft_printf("%x\n\n", u);
	//%X Prints a number in hexadecimal (base 16) uppercase format
	printf("%X\n", u);
	ft_printf("%X\n\n", u);
	//%% Prints a percent sign
	printf("%s\n", "%");
	ft_printf("%s\n\n", "%");
	printf("%%\n");
	ft_printf("%%\n");
	
	return (0);
}*/
