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

typedef struct position
{
    int x;
    int y;
    int size;
}bsq;
int	min3(int a, int b, int c)
{
    if (a < b && a < c)
        return (a);
    else if (b < c)
        return (b);
    else
        return (c);
}
int	min(int a, int b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

int	max(int a, int b)
{
    if (a < b)
        return (b);
    else
        return (a);
}
int	up2(char **a, int i, int j)
{
    if ((i < 0) || (j < 0) || a[i][j] != '.')
        return (0);
    else
    {
        return (min3(up2(a, i - 1, j), up2(a, i, j - 1), up2(a, i - 1, j - 1)) + 1);
    }
}

bsq	up(char **a, int size_x, int size_y)
{
    char *dp;
    int maxv;
    int temp;
    int i;
    int j;
    int prev;
    bsq pos;

    i = 1;
    j = 1;
    while (i < size_x)
    {
        while (j < size_y)
        {
            temp = dp[j];
            if (a[i-1][j-1] == '.')
            {
                dp[j] = max(min(dp[j - 1], prev),dp[j]) + 1;
                if(dp[j] > maxv) {
                    maxv = dp[j];
                    bsq.size = maxv;
                    bsq.x = i;
                    bsq.y = j;
                }
            } else{
                dp[j] = 0;
            }
            prev = temp;
            j++;
        }
        i++;
    }
    return pos;
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