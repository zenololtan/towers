/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: zenotan <zenotan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 17:50:26 by zenotan       #+#    #+#                 */
/*   Updated: 2021/06/22 17:50:27 by zenotan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "towers.h"

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int	str_error(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	return (1);
}

void	*free_grid(char **grid, int current)
{
	int i;

	i = 0;
	while (i >= current)
		free(grid[i++]);
	free(grid);
	return (NULL);
}

int clear_all(char *data, char **grid, char *str)
{
	int i;

	i = 0;
	if (data)
		free(data);
	if (grid)
	{
		while (grid[i])
			free(grid[i++]);
		free(grid);
	}
	if (str)
		str_error(str);
	return (1);
}

void	print_func(char **str)
{
	int i = 0;

	while (str[i])
	{	
		write(1, str[i], ft_strlen(str[i]));
		write(1, "\n", 1);
		i++;
	}
}

void	print_func_debug(t_data *data, char **str)
{
	int i = 0;

	write(1, "-------------------\n", 20);
	while (str[i])
	{
		if (i == 0)
		{
			write(1, "  ", 2);
			write(1, data->skyline, data->dim);
			write(1, "\n--------", 9);
			write(i, "\n", 1);
		}
		write(1, data->skyline + (data->dim * 2) + i, 1);
		write(1, "|", 1);
		write(1, str[i], ft_strlen(str[i]));
		write(1, "|", 1);
		write(1, data->skyline + (data->dim * 3) + i, 1);
		write(1, "\n", 1);
		if (i == data->dim - 1)
		{
			write(1, "--------\n", 9);
			write(1, "  ", 2);
			write(1, data->skyline + data->dim, data->dim);
			write(1, "\n", 1);
		}
		i++;
	}
}

char	**init_grid(int amount)
{
	int i;
	int j;
	char	**tmp;

	i = 0;
	if (!(tmp = malloc(sizeof(*tmp) * (amount + 1))))
		return (NULL);
	while (i < amount)
	{
		j = 0;
		if (!(tmp[i] = (char*)malloc(sizeof(**tmp) * (amount + 1))))
			return (free_grid(tmp, i));
		while (j < amount)
			tmp[i][j++] = '0';
		tmp[i][j] = '\0';
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

