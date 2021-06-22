/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: zenotan <zenotan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 17:50:32 by zenotan       #+#    #+#                 */
/*   Updated: 2021/06/22 17:51:12 by zenotan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "towers.h"

int	is_safe(t_data *data, int x, int y, int val)
{
	if (x == 0 && !compare_val((data->skyline[y + (data->dim * 2)] - '0'), val, data->dim))
		return (0);//compare val with col_left
	if (x == data->dim && !compare_val((data->skyline[y + (data->dim * 3)] - '0'), val, data->dim))
		return (0);//compare val with col_right
	if (y == 0 && !compare_val(data->skyline[x] - '0', val, data->dim))
		return (0);//compare val with col_up
	if (y == data->dim && !compare_val(data->skyline[x + data->dim] - '0', val, data->dim))
		return (0);//compare val with col _down
	if (!check_grid(data, x, y, val))
		return (0);
	return (1);
}

int	rec_solver(t_data *data, int x, int y)
{
	int i;

	i = 1;
	if (y == data->dim - 1 && x == data->dim)
		return (1);
	if (x == data->dim)
	{
		y++;
		x = 0;
	}
	while (i <= data->dim)
	{
		if (is_safe(data, x, y, i))
		{
			data->grid[y][x] = (char)(i + '0');
			if (rec_solver(data, x + 1, y))
				return (1);
		}
		data->grid[y][x] = '0';
		i++;
	}
	return (0);
}

