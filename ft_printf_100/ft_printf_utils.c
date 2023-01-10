/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:14:16 by miandrad          #+#    #+#             */
/*   Updated: 2022/11/29 13:18:30 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr(t_ll n)
{
	t_ll	i;

	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
	}
	i = n;
	if (i > 9)
	{
		ft_put_nbr(i / 10);
		i %= 10;
	}
	ft_putchar_fd(i + '0', 1);
	return (ft_len_nbr(n, 10));
}

int	ft_put_hex(t_ull nbr, char c)
{
	if (nbr > 15)
	{
		ft_put_hex(nbr / 16, c);
		ft_put_hex(nbr % 16, c);
	}
	else
	{
		if (nbr < 10)
			ft_putchar_fd(nbr + '0', 1);
		else
		{
			if (c == 'x')
				ft_putchar_fd(nbr - 10 + 'a', 1);
			else
				ft_putchar_fd(nbr - 10 + 'A', 1);
		}
	}
	return (ft_len_nbr(nbr, 16));
}

int	ft_len_nbr(t_ull nbr, int div_by)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		i++;
		nbr = nbr / div_by;
	}
	return (i);
}

int	ft_put_adress(t_ull address)
{
	int	count;

	count = 0;
	if (address < 1)
		count += write(1, "(nil)", 5);
	else
	{
		count += write(1, "0x", 2);
		count += ft_put_hex(address, 'x');
	}
	return (count);
}
