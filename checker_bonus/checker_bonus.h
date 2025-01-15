/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:02:08 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/15 11:05:29 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"

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

void	parse_data(t_stack **a, char **argv, int argc);
void	send_error(t_stack **a, t_stack **b, t_list **moves, char *line);
void	free_stack_a(t_stack **a);
void	free_tab(char **tab);
t_stack	*get_last(t_stack **head);
char	*get_next_line(int fd, int size, int to_clean);
void	ft_to_clean(char **pstash);
int		stack_sorted(t_stack *node);
void	pa(t_stack **a, t_stack **b, int show_msg);
void	pb(t_stack **a, t_stack **b, int show_msg);
void	rra(t_stack **a, int show_msg);
void	rrb(t_stack **a, int show_msg);
void	rrr(t_stack **a, t_stack **b, int show_msg);
void	ra(t_stack **a, int show_msg);
void	rb(t_stack **a, int show_msg);
void	rr(t_stack **a, t_stack **b, int show_msg);
void	sa(t_stack **a, int show_msg);
void	sb(t_stack **a, int show_msg);
void	ss(t_stack **a, t_stack **b, int show_msg);

#endif /* CHECKER_BONUS_H */