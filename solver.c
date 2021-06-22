#include "towers.h"

int	is_safe(t_data *data, int x, int y, int val)
{
//	printf("x[%i]y[%i]val[%i]\n", x, y, val);
//	print_func_debug(data, data->grid);
//	if (!check_grid(data, x, y, val))
//		return (0);
	if (x == 0 && !compare_val((data->skyline[y + (data->dim * 2)] - '0'), val, data->dim))
	{
//		printf("YEPPP\n");
		return (0);//compare val with col_left
	}
	if (x == data->dim && !compare_val((data->skyline[y + (data->dim * 3)] - '0'), val, data->dim))
		return (0);//compare val with col_right
	if (y == 0 && !compare_val(data->skyline[x] - '0', val, data->dim))
		return (0);//compare val with col_up
	if (y == data->dim && !compare_val(data->skyline[x + data->dim] - '0', val, data->dim))
		return (0);//compare val with col _down
//	printf("grid\n");
	if (!check_grid(data, x, y, val))
		return (0);
//	printf("Hiero\n");
//	printf("YUP\n");
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
//			print_func_debug(data, data->grid);
			if (rec_solver(data, x + 1, y))
				return (1);
		}
		data->grid[y][x] = '0';
		i++;
	}
	return (0);
}

