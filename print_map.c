/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:42:33 by edforte           #+#    #+#             */
/*   Updated: 2024/08/26 16:37:31 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_floor(t_data *game, t_texture sprites)
{
	int	rows;
	int	columns;

	rows = 1;
	columns = 1;
	while (columns < game->max_y - 1)
	{
		while (rows < game->max_x - 1)
		{
			if (game->matrix[columns][rows] == '1')
			{
				game->img_to_win = mlx_put_image_to_window(game->mlx_ptr,
						game->win_ptr, sprites.img_brr,
						rows * 48, columns * 48);
			}
			else if (game->matrix[columns][rows] == '0')
				game->img_to_win = mlx_put_image_to_window(game->mlx_ptr,
						game->win_ptr, sprites.img_floor,
						rows * 48, columns * 48);
			rows ++;
		}
		rows = 1;
		columns ++;
	}
	return ;
}

void	put_walls(t_data *game, t_texture sprites)
{
	put_right_walls(game, sprites);
	put_left_walls(game, sprites);
	put_central_walls(game, sprites);
	return ;
}

void	put_objects(t_data *game, t_texture sprites)
{
	int	rows;
	int	columns;

	rows = 1;
	columns = 1;
	while (columns < game->max_y - 1)
	{
		while (rows < game->max_x - 1)
		{
			if (game->matrix[columns][rows] != '0' &&
			game->matrix[columns][rows] != '1')
			{
				put_objs_ctrl(game, sprites, columns, rows);
			}
			rows ++;
		}
		rows = 1;
		columns ++;
	}
	return ;
}

void	print_map(t_data *game, t_texture sprites)
{
	put_floor(game, sprites);
	put_walls(game, sprites);
	put_objects(game, sprites);
	return ;
}
