/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:09:06 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/09 17:21:11 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	send_error(t_stack **a, char **args, int argc)
{
	if (a)
		free_stack_a(a);
	if (argc == 2)
		free_tab(args);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
