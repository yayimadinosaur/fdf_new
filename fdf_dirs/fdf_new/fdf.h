/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 17:46:24 by wfung             #+#    #+#             */
/*   Updated: 2018/04/22 19:12:47 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H__
# define __FDF_H__

#include <unistd.h> 
#include <stdlib.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "minilibx_macos/mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define WHT 0xfffafa
#define	RED 0xff0000
#define GRN 0xff00


#include <stdio.h>	//

//values for the 3 pts; not sure if needed?
typedef struct			s_pts
{
	float					x;
	float					y;
	float					z;
}						t_pts;	//malloc for (**t_pts) row * col

typedef struct			s_env
{
	void				*mlx;	//mlx needed
	void				*win;	//mlx needed window

	t_pts				**pts;	//for struct above

	int					height;	//height of window
	int					width;	//width of window
	float				gap;	//gap between points
	int					row;	//row
	int					col;	//col
}						t_env;

t_env		*parse_fdf(char **av);

t_pts		**create_struct(int row, int col);

void		store(t_env *e, int n, char **av);
//
//ttest functions
void		print_test(t_env *e);
#endif
