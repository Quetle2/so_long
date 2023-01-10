/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:29:57 by miandrad          #+#    #+#             */
/*   Updated: 2022/11/08 15:49:57 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*cabeca;

	cabeca = malloc(sizeof(struct s_list));
	if (!cabeca)
		return (0);
	cabeca->content = content;
	cabeca->next = NULL;
	return (cabeca);
}
