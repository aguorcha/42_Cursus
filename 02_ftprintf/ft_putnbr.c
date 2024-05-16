/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:47:50 by aorcha-m          #+#    #+#             */
/*   Updated: 2023/12/15 12:57:08 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char			temp_buffer[11];
	int				i;
	unsigned int	counter;

	counter = 0;
	i = 0;
	if (n == 0)
		counter += write(1, "0", 1);
	if (n == -2147483648)
		counter += write(1, "-2147483648", 11);
	else if (n < 0)
	{
		counter += write(1, "-", 1);
		n *= -1;
	}
	while (n > 0)
	{
		temp_buffer[i++] = (n % 10) + '0';
		n = n / 10;
	}
	while (i-- > 0)
		counter += write(1, &temp_buffer[i], 1);
	return (counter);
}
