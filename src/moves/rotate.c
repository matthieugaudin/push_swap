/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:57:42 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/09 18:09:50 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack	*last_node;

	if (!head || !(*head) || !(*head)->next)
		return ;
	last_node = get_last(head);
	*head = (*head)->next;
	(*head)->prev->next = NULL;
	(*head)->prev->prev = last_node;
	(*head)->prev->prev->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	ra(t_stack **a, int show_msg)
{
	rotate(a);
	if (show_msg)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int show_msg)
{
	rotate(b);
	if (show_msg)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *to_move)
{
	while (to_move->prev && to_move->target->prev)
		rr(a, b);
	update_pos(*a);
	update_pos(*b);
}
