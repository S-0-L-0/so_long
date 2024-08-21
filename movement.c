/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:48:56 by edforte           #+#    #+#             */
/*   Updated: 2024/08/21 20:39:58 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_data *game, void *img, int z, int k)
{
	int	x;
	int	y;

	x = game->player.px;
	y = game->player.py;
	game->imgs.img_player = img;
	if (game->matrix[y + z][x + k] != '1')
	{
		if (game->matrix[y + z][x + k] == 'E' && game->collect_counter == 0)
			on_destroy(game);
		else if (game->matrix[y + z][x + k] == 'C')
			check_collect(game);
		if (game->matrix[y + z][x + k] != 'E')
		{
			game->matrix[y + z][x + k] = 'P';
			game->matrix[y][x] = '0';
			game->player.py += z;
			game->player.px += k;
			game->mv_counter += 1;
			ft_printf("moves: %d\n", game->mv_counter);
		}
	}
}

void	check_collect(t_data *game)
{
	game->collect_counter --;
	if (game->collect_counter == 0)
	{
		mlx_destroy_image(game->mlx_ptr, game->imgs.img_ext);
		game->imgs.img_ext = mlx_xpm_file_to_image(game->mlx_ptr,
				"assets/door_fullyopen_chest.xpm",
				&(game->imgs.img_width), &(game->imgs.img_height));
	}
}
