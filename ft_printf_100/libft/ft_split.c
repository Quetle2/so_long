/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:50:42 by miandrad          #+#    #+#             */
/*   Updated: 2022/11/10 17:01:55 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <mcheck.h>

static size_t	ft_tamnhoplavra(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

static size_t	ft_ctp(char const *s, char c)
{
	size_t	i;
	size_t	ctp;

	i = 0;
	ctp = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		ctp++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (ctp);
}

static char	**ft_putmatrix(char **matrix, char const *s, char c, size_t	ctp)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*s && *s == c)
		s++;
	while (ctp)
	{
		matrix[j] = (char *)malloc(sizeof(char) * (ft_tamnhoplavra(s, c) + 1));
		i = 0;
		while (*s && *s != c)
		{
			matrix[j][i] = *s;
			i++;
			s++;
		}
		matrix[j][i] = '\0';
		while (*s && *s == c)
			s++;
		j++;
		ctp--;
	}
	matrix[j] = 0;
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;

	if (!s)
		return (0);
	matrix = (char **)malloc(sizeof(char *) * (ft_ctp(s, c) + 1));
	if (!matrix || !s)
		return (0);
	matrix = ft_putmatrix(matrix, s, c, ft_ctp(s, c));
	return (matrix);
}

// int main ()
// {
// 	char	**tabstr;

// 	tabstr = ft_split("tripoulishdw", ' ');
// 	mcheck(*tabstr, sizeof(char *) * 2);
// 	if (!tabstr[0])
// 		printf("ok\n");
//     while (*tabstr)
//     {
//             printf("%s\n", *tabstr);
//             tabstr++;
//     }
// }
