/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:55:53 by mgaudin           #+#    #+#             */
/*   Updated: 2025/10/17 16:36:22 by mgaudin          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int					value;
	int					pos;
	int					push_cost;
	int					above_median;
	struct s_stack		*target;
	struct s_stack		*prev;
	struct s_stack		*next;
}	t_stack;


/*==========ALGORITHMS==========*/
void	sort_stack(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	reset_data(t_stack *a, t_stack *b, char stack_name);

/*==========MOVES==========*/
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rra(t_stack **a, int show_msg);
void	rrb(t_stack **b, int show_msg);
void	rrr(t_stack **a, t_stack **b);
void	ra(t_stack **a, int show_msg);
void	rb(t_stack **b, int show_msg);
void	rr(t_stack **a, t_stack **b);
void	sa(t_stack **a, int show_msg);
void	sb(t_stack **b, int show_msg);
void	ss(t_stack **a, t_stack **b);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *to_move);
void	rotate_both(t_stack **a, t_stack **b, t_stack *to_move);

/*==========UTILS==========*/
void	free_stack_a(t_stack **a);
void	free_tab(char **tab);
t_stack	*get_last(t_stack **head);
t_stack	*get_min(t_stack *node);
t_stack	*get_max(t_stack *node);
void	init_stack_a(t_stack **a, char **argv, int argc);
void	send_error(t_stack **a, char **args, int argc);
int		stack_len(t_stack *node);
int		stack_sorted(t_stack *node);
void	update_pos(t_stack *node);
t_stack	*get_cheapest(t_stack *node);

#endif /* PUSH_SWAP_H */