/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:03:41 by edforte           #+#    #+#             */
/*   Updated: 2024/08/26 16:39:04 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include "ft_printf/ft_printf.h"

# define WRONG_INPUT "Error\nYou must only enter the map path\n"
# define WRONG_EXT "Error\nMap extent is invalid, should be .ber\n"
# define FILE_ERROR "Error\nThe file could not be opened or read"
# define MAP_ERROR "Error\nThe map contains invalid characters or \
doesn't contain all valid characters"
# define MAP_ERROR2 "Error\nThe map isn't a rectangular"
# define MAP_ERROR3 "Error\nThe map is not surrounded by walls"
# define PATH_ERROR "Error\nThere is no valid path"

# define UP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100
# define ESC 65307

typedef struct s_texture
{
	void	*img_player;
	void	*img_prbk;
	void	*img_prdw;
	void	*img_prl;
	void	*img_prr;
	void	*img_ext;
	void	*img_clct;
	void	*img_brr;
	void	*img_tl_crn;
	void	*img_dl_crn;
	void	*img_tr_crn;
	void	*img_dr_crn;
	void	*img_lwall;
	void	*img_rwall;
	void	*img_wall;
	void	*img_floor;
	int		img_width;
	int		img_height;
}	t_texture;

typedef struct s_position
{
	int	px;
	int	py;
	int	ex;
	int	ey;
}	t_position;

typedef struct s_data
{
	char		**matrix;
	char		**mx_copy;
	int			max_x;
	int			max_y;
	char		*strmap;
	void		*mlx_ptr;
	void		*win_ptr;
	int			img_to_win;
	int			collect_counter;
	int			mv_counter;
	t_texture	imgs;
	t_position	player;
}	t_data;

int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);
int		valid_extension(char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*read_map(char *path);
int		check_chrs(char *str);
int		nbr_objects(char *str);
int		matrix_check(t_data *game);
char	*map_check(int ac, char **av);
char	**ft_split(char const *s, char c);
int		all_walls(t_data *game);
int		rows_check(t_data *game, int rows);
int		columns_check(t_data *game, int columns);
void	start_pos(t_position *player, t_data *game);
void	flood_fill(char **matrix, int x, int y);
int		pathfinder(char **matrix, int x, int y);
int		checker(t_data *game, t_position *player, int ac, char **av);
int		start_game(t_data *game);
int		on_destroy(t_data *game);
int		on_keypress(int keysym, t_data *data);
void	free_matrix(char **matrix);
void	set_texture(t_texture *sprt, t_data *gm);
void	part_one(t_texture *sprt, t_data *gm);
void	part_two(t_texture *sprt, t_data *gm);
void	print_map(t_data *game, t_texture sprites);
void	collect_counter(t_data *game);
void	put_floor(t_data *game, t_texture sprites);
void	put_walls(t_data *game, t_texture sprites);
void	put_right_walls(t_data *gm, t_texture sprites);
void	put_left_walls(t_data *gm, t_texture sprites);
void	put_central_walls(t_data *game, t_texture sprites);
void	put_objects(t_data *game, t_texture sprites);
void	put_objs_ctrl(t_data *game, t_texture sprites, int columns, int rows);
void	move(t_data *game, void *img, int z, int k);
void	check_collect(t_data *game);

#endif