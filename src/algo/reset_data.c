/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:36:35 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/16 09:29:37 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	get_special_cost(t_stack *a, int len_a, int len_b)
{
	int	a_cost;
	int	b_cost;
	int	res;

	if (a->above_median && a->target->above_median)
	{
		a_cost = len_a - a->pos;
		b_cost = len_b - a->target->pos;
	}
	else
	{
		a_cost = a->pos;
		b_cost = a->target->pos;
	}
	if (a_cost < b_cost)
		res = a_cost + (b_cost - a_cost);
	else
		res = b_cost + (a_cost - b_cost);
	if (a_cost == b_cost)
		res = a_cost;
	return (res);
}

static void	calc_push_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	update_pos(a);
	update_pos(b);
	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		if ((a->above_median && a->target->above_median)
			|| (!a->above_median && !a->target->above_median))
			a->push_cost = get_special_cost(a, len_a, len_b);
		else
		{
			a->push_cost = len_a - a->pos;
			if (!(a->above_median))
				a->push_cost = a->pos;
			if (a->target->above_median)
				a->push_cost += len_b - a->target->pos;
			else if (!(a->target->above_median))
				a->push_cost += a->target->pos;
		}
		a = a->next;
	}
}

static void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*tmp_b;
	t_stack	*max_b;

	tmp_b = b;
	max_b = get_max(b);
	while (a)
	{
		b = tmp_b;
		a->target = NULL;
		while (b)
		{
			if (!(a->target) && b->value < a->value)
				a->target = b;
			else if (a->target && b->value < a->value
				&& b->value > a->target->value)
				a->target = b;
			b = b->next;
		}
		if (!a->target)
			a->target = max_b;
		a = a->next;
	}
}

static void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*tmp_a;
	t_stack	*min_a;

	tmp_a = a;
	min_a = get_min(a);
	while (b)
	{
		a = tmp_a;
		b->target = NULL;
		while (a)
		{
			if (!(b->target) && a->value > b->value)
				b->target = a;
			else if (b->target && a->value > b->value
				&& a->value < b->target->value)
				b->target = a;
			a = a->next;
		}
		if (!b->target)
			b->target = min_a;
		b = b->next;
	}
}

void	reset_data(t_stack *a, t_stack *b, char stack_name)
{
	update_pos(a);
	update_pos(b);
	if (stack_name == 'a')
	{
		set_target_a(a, b);
		calc_push_cost(a, b);
	}
	else if (stack_name == 'b')
	{
		set_target_b(a, b);
	}
}
