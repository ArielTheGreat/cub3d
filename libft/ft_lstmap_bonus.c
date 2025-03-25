/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:07:15 by mhummel           #+#    #+#             */
/*   Updated: 2024/03/20 11:08:44 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_node;
	t_list	*temp;
	void	*new_content;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_content = f(lst->content);
	new_head = ft_lstnew(new_content);
	if (!new_head)
		return (del(new_content), NULL);
	temp = new_head;
	lst = lst->next;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
			return (ft_lstclear(&new_head, del), del(new_content), NULL);
		temp->next = new_node;
		temp = temp->next;
		lst = lst->next;
	}
	return (new_head);
}
