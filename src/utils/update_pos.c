/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:09:11 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/10 11:05:30 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	update_pos(t_stack *node)
{
	int	median;
	int	i;

	median = stack_len(node) / 2;
	i = 0;
	while (node)
	{
		node->pos = i;
		if (node->pos <= median)
			node->above_median = 0;
		else
			node->above_median = 1;
		node = node->next;
		i++;
	}
}
