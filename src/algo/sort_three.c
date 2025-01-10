/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:06:31 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/09 17:27:21 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*max;

	max = get_max(*a);
	if (*a == max)
		ra(a, 1);
	else if ((*a)->next == max)
		rra(a, 1);
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}
