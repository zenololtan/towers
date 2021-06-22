#ifndef	TOWERS_H
# define TOWERS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_data
{
	char	*skyline;
	char	**grid;
	int		dim;
}								t_data;

//----------utils.c------------
int ft_strlen(char *str);
int	str_error(char *str);
void	*free_grid(char **grid, int currenti);
int clear_all(char *data, char **grid, char *str);
void	print_func(char **str);
void	print_func_debug(t_data *data, char **str);
char	**init_grid(int amount);
//---------checkers.c----------
int	check_grid(t_data *data, int x, int y, int val);
int	compare_val(int pov, int val, int dim);
//----------solver.c-----------
int	is_safe(t_data *data, int x, int y, int val);
int	rec_solver(t_data *data, int x, int y);
//----------parser.c-----------
int	check_args(char *str, t_data *data);
char	*get_data(char *str, int amount);

#endif
