/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:13:22 by wfung             #+#    #+#             */
/*   Updated: 2018/04/22 19:22:01 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	clean_strsplit(char **buff, char *line, t_env *e, int range)
{
	int		i;

	i = range;
	free(line);
	if (!buff)
	{
		free(e);	//remove entire struct
		ft_puterror("strsplit failed\n");
	}
	while (i > -1)
	{
		free(buff[i]);
		i--;
	}
	free(buff);
	ft_puterror("strsplit failed\n");
}

/*stores coorindates for each point of the map
 */

static int		store_z(t_env *e, char **av)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**buff;

	i = 0;
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_puterror(".fdf file read for z failed\n");
	while (get_next_line(fd, &line) == 1 && i < e->col)	//e->col is safeguard
	{
		j = 0;
		if (!(buff = ft_strsplit(line, ' ')))
			clean_strsplit(buff, line, e, e->col); 
		while (j < e->col)
		{
			e->pts[i][j].z = ft_atoi(buff[j]);
			j += 1;
		}
		//clean_strsplit(buff, line, e, e->col);
		free(line);
		i += 1;
	}
	close(fd);
	return (0);
}

static void	default_values(t_env *e, int n)
{
	e->height = n;
	e->width = n;
	e->gap = 0;
	e->row >= e->col ? (e->gap = e->height / e->row) : (e->height / e->col);
}

void	store(t_env *e, int n, char **av)
{
	int		i;
	int		j;

	i = 0;
	default_values(e, n);
	store_z(e, av);
	while (i < e->row)
	{
		j = 0;
		while (j < e->col)
		{
			e->pts[i][j].x = i * e->gap;
			e->pts[i][j].y = j * e->gap;
			j += 1;
		}
		i += 1;
	}
	//test x y z coords 
	int		k = 0;
	int		b;
	while (k < e->row)
	{
		b = 0;
		while (b < e->col)
		{
			printf("pts[%i][%i].x = [%f]"
					"pts[%i][%i].y = [%f]"
					"pts[%i][%i].z = [%f]"
					"\n", k, b, e->pts[k][b].x, k, b, e->pts[k][b].y, k, b, e->pts[k][b].z);
			b += 1;
		}
		k += 1;
	}
	return ;	//if malloc survives
}
