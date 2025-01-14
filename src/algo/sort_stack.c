/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:06:24 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/14 10:41:11 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	move_min_to_top(t_stack **a)
{
	t_stack	*min;

	min = get_min(*a);
	if (min->above_median)
	{
		while (min->prev)
			rra(a, 1);
	}
	else
	{
		while (min->prev)
			ra(a, 1);
	}
}

static void	node_to_top(t_stack **stack, t_stack *to_move, char stack_name)
{
	while (to_move->prev)
	{
		if (stack_name == 'a')
		{
			if (to_move->above_median)
				rra(stack, 1);
			else
				ra(stack, 1);
		}
		else if (stack_name == 'b')
		{
			if (to_move->above_median)
				rrb(stack, 1);
			else
				rb(stack, 1);
		}
	}
}

static void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*to_move;

	to_move = get_cheapest(*a);
	if (to_move->above_median && to_move->target->above_median)
		reverse_rotate_both(a, b, to_move);
	else if (!(to_move->target->above_median)
		&& !(to_move->above_median))
		rotate_both(a, b, to_move);
	node_to_top(a, to_move, 'a');
	node_to_top(b, to_move->target, 'b');
	pb(a, b);
}

static void	move_b_to_a(t_stack **a, t_stack **b)
{
	node_to_top(a, (*b)->target, 'a');
	pa(a, b);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		reset_data(*a, *b, 'a');
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		reset_data(*a, *b, 'b');
		move_b_to_a(a, b);
	}
	update_pos(*a);
	move_min_to_top(a);
}
