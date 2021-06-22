/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: zenotan <zenotan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 17:50:09 by zenotan       #+#    #+#                 */
/*   Updated: 2021/06/22 17:50:44 by zenotan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "towers.h"

int main(int argc, char **argv)
{
	t_data	data;
	int amount;

	data.skyline = NULL;
	data.grid = NULL;
	data.dim = 0;
	if (argc != 2)
		return (str_error("Error: arguments\n"));
	if (!(amount = check_args(argv[1], &data)))
		return (str_error("Error: parsing\n"));
	if (!(data.skyline = get_data(argv[1], amount)))
		return (str_error("Error: parsing\n"));
	if (!(data.grid = init_grid(data.dim)))
		return (clear_all(data.skyline, NULL, "Error: initializing grid\n"));
	if (!rec_solver(&data, 0, 0))
		clear_all(data.skyline, data.grid, "Error: could not solve\n");
	print_func(data.grid);
	clear_all(data.skyline, data.grid, NULL);
	return (0);
}
