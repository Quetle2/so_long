/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:21:54 by miandrad          #+#    #+#             */
/*   Updated: 2022/11/09 19:26:49 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nn;
	t_list	*head;

	head = NULL;
	while (lst)
	{
		nn = ft_lstnew(f(lst->content));
		if (!nn)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, nn);
		lst = lst->next;
	}
	return (head);
}
