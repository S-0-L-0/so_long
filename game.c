/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:41:53 by edforte           #+#    #+#             */
/*   Updated: 2024/08/26 16:35:50 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	start_game(t_data *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (1);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->max_x * 48, game->max_y * 48, "so_long");
	if (!game->win_ptr)
	{
		free(game->mlx_ptr);
		return (1);
	}
	set_texture(&(game->imgs), game);
	print_map(game, game->imgs);
	collect_counter(game);
	game->mv_counter = 0;
	mlx_hook(game->win_ptr, 02, (1L << 0), &on_keypress, game);
	mlx_hook(game->win_ptr, 17, (1L << 17), &on_destroy, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}

int	on_destroy(t_data *game)
{
	free_matrix(game->matrix);
	mlx_destroy_image(game->mlx_ptr, game->imgs.img_brr);
	mlx_destroy_image(game->mlx_ptr, game->imgs.img_clct);
	mlx_destroy_image(game->mlx_ptr, game->imgs.img_dl_crn);
	mlx_destroy_image(game->mlx_ptr, game->imgs.img_dr_crn);
	mlx_destroy_image(game->mlx_ptr, game->imgs.img_ext);
	mlx_destroy_image(game->mlx_ptr, game->imgs.img_floor);
	mlx_destroy_image(game->mlx_ptr, game->imgs.img_lwall);
	mlx_destroy_image(game->mlx_ptr, game->imgs.img_prbk);
	mlx_destroy_image(game->mlx_ptr, game->imgs.img_prdw);
	mlx_destroy_image(game->mlx_ptr, game->imgs.img_prl);
	mlx_destroy_image(game->mlx_ptr, game->imgs.img_prr);
	mlx_destroy_image(game->mlx_ptr, game->imgs.img_rwall);
	mlx_destroy_image(game->mlx_ptr, game->imgs.img_tl_crn);
	mlx_destroy_image(game->mlx_ptr, game->imgs.img_tr_crn);
	mlx_destroy_image(game->mlx_ptr, game->imgs.img_wall);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}

void	free_matrix(char **matrix)
{
	int	rows;

	rows = 0;
	while (matrix[rows])
	{
		free(matrix[rows]);
		rows ++;
	}
	free(matrix);
}

int	on_keypress(int keysym, t_data *game)
{
	if (keysym == UP)
		move(game, game->imgs.img_prbk, -1, 0);
	else if (keysym == LEFT)
		move(game, game->imgs.img_prl, 0, -1);
	else if (keysym == DOWN)
		move(game, game->imgs.img_prdw, 1, 0);
	else if (keysym == RIGHT)
		move(game, game->imgs.img_prr, 0, 1);
	else if (keysym == ESC)
		on_destroy(game);
	print_map(game, game->imgs);
	return (0);
}
