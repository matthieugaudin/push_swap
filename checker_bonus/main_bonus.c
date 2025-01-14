/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:46:29 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/14 12:17:53 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

// parse the data + manage errors : OK
// implement moves
// infinite loop on stdin
// at each line parse the given string
// at each line execute the operation on the list
// settle the OK / KO

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	parse_data(&a, argv + 1, argc);
	while (1)
	{
		read_moves();
	}
	free_list_a(&a);
	return (0);
}
