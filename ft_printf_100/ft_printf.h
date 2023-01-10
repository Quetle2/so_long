/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:54:53 by miandrad          #+#    #+#             */
/*   Updated: 2022/11/29 13:15:27 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

typedef unsigned long long	t_ull;
typedef long long			t_ll;

int	ft_printf(const char *str, ...);
int	ft_put_adress(t_ull address);
int	ft_put_nbr(t_ll n);
int	ft_len_nbr(t_ull nbr, int div_by);
int	ft_put_hex(t_ull nbr, char c);

#endif