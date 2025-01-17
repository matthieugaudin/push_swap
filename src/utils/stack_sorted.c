/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:05:29 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/15 09:47:21 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	stack_sorted(t_stack *node)
{
	if (!node)
		return (0);
	while (node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}
