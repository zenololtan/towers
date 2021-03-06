/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: zenotan <zenotan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 17:50:21 by zenotan       #+#    #+#                 */
/*   Updated: 2021/06/22 19:52:52 by zenotan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "towers.h"

int	is_val(char c)
{
	if (c > '0' && c <= '4')
		return (4);
	if (c >= '5' && c <= '9')
		return (c - '0');
	return (0);
}

int	check_dim(int highest, int amount)
{
	if (amount / 4 < highest || amount > 36)
		return (0);
	return (amount / 4);
}

int	check_args(char *str, t_data *data)
{
	int i;
	int num;
	int tmp;
	int large;
	
	i = 0;
	num = 0;
	tmp = 0;
	large = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !is_val(str[i]))
			return (0);
		if ((tmp = is_val(str[i])))
			num++;
		if (tmp > large)
			large = tmp;
		i++;
	}
	if (!(data->dim = check_dim(large, num)))
		return (0);
	return (num);
}

char	*get_data(char *str, int amount)
{
	char *tmp;
	int i;
	int j;

	tmp = NULL;
	i = 0;
	j = 0;
	if (!(tmp = (char*)malloc(sizeof(*tmp) * amount)))
		return (NULL);
	while (str[i])
	{
		if (is_val(str[i]))
			tmp[j++] = str[i];
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

