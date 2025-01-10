/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:08:52 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/09 17:12:24 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*get_max(t_stack *node)
{
	t_stack	*max;

	max = node;
	while (node->next)
	{
		if (node->next->value > max->value)
			max = node->next;
		node = node->next;
	}
	return (max);
}
