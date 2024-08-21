/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:29:08 by edforte           #+#    #+#             */
/*   Updated: 2024/08/21 18:09:41 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_right_walls(t_data *gm, t_texture sprites)
{
	int		rows;
	int		columns;

	rows = gm->max_x - 1;
	columns = 0;
	while (columns < gm->max_x)
	{
		if (columns == 0)
			gm->img_to_win = mlx_put_image_to_window(gm->mlx_ptr,
					gm->win_ptr, sprites.img_tr_crn, rows * 48, columns * 48);
		else if (columns == gm->max_y - 1)
			gm->img_to_win = mlx_put_image_to_window(gm->mlx_ptr,
					gm->win_ptr, sprites.img_dr_crn, rows * 48, columns * 48);
		else
			gm->img_to_win = mlx_put_image_to_window(gm->mlx_ptr,
					gm->win_ptr, sprites.img_rwall, rows * 48, columns * 48);
		columns ++;
	}
	return ;
}

void	put_left_walls(t_data *gm, t_texture sprites)
{
	int		rows;
	int		columns;

	rows = 0;
	columns = 0;
	while (columns < gm->max_y)
	{
		if (columns == 0)
			gm->img_to_win = mlx_put_image_to_window(gm->mlx_ptr,
					gm->win_ptr, sprites.img_tl_crn, rows * 48, columns * 48);
		else if (columns == gm->max_y - 1)
			gm->img_to_win = mlx_put_image_to_window(gm->mlx_ptr,
					gm->win_ptr, sprites.img_dl_crn, rows * 48, columns * 48);
		else
			gm->img_to_win = mlx_put_image_to_window(gm->mlx_ptr,
					gm->win_ptr, sprites.img_lwall, rows * 48, columns * 48);
		columns ++;
	}
	return ;
}

void	put_central_walls(t_data *game, t_texture sprites)
{
	int	rows;
	int	columns;

	rows = 1;
	columns = 0;
	while (rows < game->max_x - 1)
	{
		game->img_to_win = mlx_put_image_to_window(game->mlx_ptr,
				game->win_ptr, sprites.img_wall, rows * 48, columns * 48);
		rows ++;
	}
	rows = 1;
	columns = game->max_y - 1;
	while (rows < game->max_x - 1)
	{
		game->img_to_win = mlx_put_image_to_window(game->mlx_ptr,
				game->win_ptr, sprites.img_wall, rows * 48, columns * 48);
		rows ++;
	}
	return ;
}

void	put_objs_ctrl(t_data *game, t_texture sprites, int columns, int rows)
{
	if (game->matrix[columns][rows] == 'P')
		game->img_to_win = mlx_put_image_to_window(game->mlx_ptr,
				game->win_ptr, sprites.img_player, rows * 48, columns * 48);
	else if (game->matrix[columns][rows] == 'E')
		game->img_to_win = mlx_put_image_to_window(game->mlx_ptr,
				game->win_ptr, sprites.img_ext, rows * 48, columns * 48);
	else if (game->matrix[columns][rows] == 'C')
		game->img_to_win = mlx_put_image_to_window(game->mlx_ptr,
				game->win_ptr, sprites.img_clct, rows * 48, columns * 48);
	return ;
}
