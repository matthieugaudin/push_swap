/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheapest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:54:18 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/09 17:54:53 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*get_cheapest(t_stack *node)
{
	t_stack	*cheapest;

	cheapest = node;
	while (node->next)
	{
		if (node->next->push_cost < cheapest->push_cost)
			cheapest = node->next;
		node = node->next;
	}
	return (cheapest);
}
