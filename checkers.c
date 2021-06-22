/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: zenotan <zenotan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 17:50:15 by zenotan       #+#    #+#                 */
/*   Updated: 2021/06/22 17:52:56 by zenotan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "towers.h"

int	rev_check_row(t_data *data, int y)
{
	int i;
	int check;
	int skyscraper;
	char	**str;

	i = data->dim - 1;
	check = 0;
	skyscraper = 0;
	str = data->grid;
	while (i >= 0)
	{
		if (str[y][i] > skyscraper)
		{
			skyscraper = str[y][i];
			check++;
		}
		if (check > data->skyline[y + (data->dim * 3)] - '0')
			return (0);
		i--;
	}
	if (check != data->skyline[y + (data->dim) * 3] - '0')
		return (0);
	return (1);
}

int	rev_check_collum(t_data *data, int x)
{
	int i;
	int check;
	int skyscraper;
	char	**str;

	i = data->dim - 1;
	check = 0;
	skyscraper = 0;
	str = data->grid;
	while (i >= 0)
	{
		if (str[i][x] > skyscraper)
		{
			skyscraper = str[i][x];
			check++;
		}
		if (check > data->skyline[x + data->dim] - '0')
			return (0);
		i--;
	}
	if (check != data->skyline[x + data->dim] - '0')
		return (0);
	return (1);
}

int	check_rows(t_data *data, int x, int y, int val)
{
	int i;
	int	skyscraper;
	int check;
	char	**str;

	i = 1;
	check = 1;
	str = data->grid;
	skyscraper = str[y][0];
	while (i <= x)
	{
		if (str[y][i] > skyscraper && str[y][i] > str[y][i - 1])
		{
			skyscraper = str[y][i];
			check++;
		}
		if ((str[y][i] == data->dim + '0' && check != data->skyline[y +
			 (data->dim * 2)] - '0') || (str[y][i - 1] - '0' == val))
			return (0);
		i++;
	}
	if (x == data->dim - 1 && !rev_check_row(data, y))
		return (0);
	return (1);
}

int	check_collums(t_data *data, int x, int y, int val)
{
	int i;
	int check;
	int skyscraper;
	char	**str;

	i = 1;
	check = 1;
	str = data->grid;
	skyscraper = str[0][x];
	while (i <= y)
	{
		if (str[i][x] > skyscraper && str[i][x] > str[i - 1][x])
		{
			skyscraper = str[i][x];
			check++;
		}
		if ((str[i][x] == data->dim + '0' && check != data->skyline[x] - '0')
				 || (str[i - 1][x] - '0' == val))
			return (0);
		i++;
	}
	if (y == data->dim - 1 && !rev_check_collum(data, x))
		return (0);
	return (1);
}

int	check_grid(t_data *data, int x, int y, int val)
{
	data->grid[y][x] = val + '0';
	if (!check_rows(data, x, y, val))
	{
		data->grid[y][x] = '0';
		return (0);
	}
	if (!check_collums(data, x, y, val))
	{
		data->grid[y][x] = '0';
		return (0);
	}
	return (1);
}

int	compare_val(int pov, int val, int dim)
{
	if ((val != 1 && pov == dim) || (val != dim && pov == 1))
		return (0);
	if (val < 1 || val > (dim - pov) + 1)
		return (0);//3 = 1, 2 are possible -> (4 - 3) + 1 = 2
	return (1);
}

