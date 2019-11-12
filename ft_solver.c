/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnawrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:09:42 by jnawrock          #+#    #+#             */
/*   Updated: 2019/11/11 16:09:46 by jnawrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	min(int a, int b, int c)
{
    if (a < b && a < c)
        return (a);
    else if (b < c)
        return (b);
    else
        return (c);
}

int	up(char **a, int i, int j)
{
    if ((i < 0) || (j < 0) || a[i][j] != '.')
        return (0);
    else
    {
        return (min(up(a, i - 1, j), up(a, i, j - 1), up(a, i - 1, j - 1)) + 1);
    }
}

int	ft_solver(char **matrix, int size_x, int size_y)
{
    char		**dup;
    short		i;
    int			j;

    i = size_x - 1;
    dup = matrix;
    while (i > -1)
    {
        j = size_y - 1;
        while (j > -1)
        {
            dup[i][j] = up(matrix, i, j);
            j--;
        }
        i--;
    }
    return (0);
}