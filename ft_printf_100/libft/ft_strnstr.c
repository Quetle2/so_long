/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:21:28 by miandrad          #+#    #+#             */
/*   Updated: 2022/11/07 15:20:22 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_verificar(const char *big, const char *lit, size_t *i, size_t *b)
{
	while (big[*i] == lit[*b] && lit[*b])
	{
		*b = *b + 1;
		*i = *i + 1;
	}
}

char	*ft_strnstr(const char	*big, const char *lit, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	b;

	i = 0;
	b = 0;
	if (!lit[i])
		return ((char *)big);
	if (n == 0)
		return (0);
	while (big[i] && i <= n - 1)
	{
		if (big[i] == lit[b])
		{
			j = i;
			ft_verificar(big, lit, &i, &b);
			if (!lit[b] && i <= n)
				return ((char *)big + j);
			b = 0;
			i = j;
		}
		i++;
	}
	return (0);
}
