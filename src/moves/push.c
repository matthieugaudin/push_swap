/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:57:49 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/09 17:02:32 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/push_swap.h"

static void	push(t_stack **head_src, t_stack **head_dst)
{
	t_stack	*to_push;

	if (!head_src || !head_dst || !(*head_src))
		return ;
	to_push = *head_src;
	*head_src = (*head_src)->next;
	if (*head_src)
		(*head_src)->prev = NULL;
	to_push->prev = NULL;
	to_push->next = *head_dst;
	if (*head_dst)
		(*head_dst)->prev = to_push;
	*head_dst = to_push;
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
