/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_structs_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:00:10 by edforte           #+#    #+#             */
/*   Updated: 2024/08/21 19:24:03 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	part_one(t_texture *sprt, t_data *gm)
{
	sprt->img_prbk = mlx_xpm_file_to_image(gm->mlx_ptr,
			"assets/knight_back.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_prdw = mlx_xpm_file_to_image(gm->mlx_ptr,
			"assets/knight_down.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_prl = mlx_xpm_file_to_image(gm->mlx_ptr,
			"assets/knight_idle_left.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_prr = mlx_xpm_file_to_image(gm->mlx_ptr,
			"assets/knight_idle.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_ext = mlx_xpm_file_to_image(gm->mlx_ptr,
			"assets/door_closed.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_clct = mlx_xpm_file_to_image(gm->mlx_ptr,
			"assets/key_g1.xpm", &(sprt->img_width), &(sprt->img_height));
	sprt->img_brr = mlx_xpm_file_to_image(gm->mlx_ptr,
			"assets/barrel.xpm", &(sprt->img_width), &(sprt->img_height));
	sprt->img_tl_crn = mlx_xpm_file_to_image(gm->mlx_ptr,
			"assets/top_left_corner.xpm",
			&(sprt->img_width), &(sprt->img_height));
	return ;
}

void	part_two(t_texture *sprt, t_data *gm)
{
	sprt->img_dl_crn = mlx_xpm_file_to_image(gm->mlx_ptr,
			"assets/bottom_left_corner.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_tr_crn = mlx_xpm_file_to_image(gm->mlx_ptr,
			"assets/top_right_corner.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_dr_crn = mlx_xpm_file_to_image(gm->mlx_ptr,
			"assets/bottom_right_corner.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_lwall = mlx_xpm_file_to_image(gm->mlx_ptr,
			"assets/wall_left_torch.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_rwall = mlx_xpm_file_to_image(gm->mlx_ptr,
			"assets/wall_right_torch.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_wall = mlx_xpm_file_to_image(gm->mlx_ptr,
			"assets/wall.xpm", &(sprt->img_width), &(sprt->img_height));
	sprt->img_floor = mlx_xpm_file_to_image(gm->mlx_ptr,
			"assets/floor.xpm", &(sprt->img_width), &(sprt->img_height));
	sprt->img_player = sprt->img_prbk;
	return ;
}
