/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:08:48 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/09 17:10:37 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*get_last(t_stack **head)
{
	t_stack	*node;

	node = *head;
	while (node->next)
	{
		node = node->next;
	}
	return (node);
}
