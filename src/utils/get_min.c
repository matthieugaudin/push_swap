/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:09:00 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/09 17:12:26 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*get_min(t_stack *node)
{
	t_stack	*min;

	min = node;
	while (node->next)
	{
		if (node->next->value < min->value)
			min = node->next;
		node = node->next;
	}
	return (min);
}
