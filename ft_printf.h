/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcattini <dcattini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:35:12 by dcattini          #+#    #+#             */
/*   Updated: 2022/04/04 15:18:51 by dcattini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_putchar(char c);
int	ft_putnb_base16(unsigned int nb, char c);
int	ft_putnbrun(unsigned int nb);
int	ft_putpoiter(void *point);

#endif
