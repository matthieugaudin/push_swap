/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:09:11 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/09 17:34:39 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	update_pos(t_stack *node)
{
	int	i;

	i = 0;
	while (node)
	{
		node->pos = i;
		if (node->pos < i)
			node->above_median = 0;
		else
			node->above_median = 1;
		node = node->next;
		i++;
	}
}
