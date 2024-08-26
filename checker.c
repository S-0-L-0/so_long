/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:34:05 by edforte           #+#    #+#             */
/*   Updated: 2024/08/26 16:34:52 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checker(t_data *game, t_position *player, int ac, char **av)
{
	game->strmap = map_check(ac, av);
	if (game->strmap == NULL)
		return (1);
	game->matrix = ft_split(game->strmap, '\n');
	game->mx_copy = ft_split(game->strmap, '\n');
	free (game->strmap);
	if (matrix_check(game) == 1)
	{
		free_matrix(game->mx_copy);
		free_matrix(game->matrix);
		return (1);
	}
	start_pos(player, game);
	if (pathfinder(game->mx_copy, player->px, player->py) == 1)
	{
		ft_printf("%s\n", PATH_ERROR);
		free_matrix(game->mx_copy);
		free_matrix(game->matrix);
		return (1);
	}
	free_matrix(game->mx_copy);
	return (0);
}

char	*map_check(int ac, char **av)
{
	char	*map;

	map = NULL;
	if (ac != 2)
		ft_printf("%s\n", WRONG_INPUT);
	if (ac != 2)
		return (NULL);
	if (valid_extension(av[1]) == 1)
	{
		ft_printf("%s\n", WRONG_EXT);
		return (NULL);
	}
	map = read_map(av[1]);
	if (map == NULL)
	{
		ft_printf("%s\n", FILE_ERROR);
		return (NULL);
	}
	if (check_chrs(map) == 1)
	{
		free (map);
		ft_printf("%s\n", MAP_ERROR);
		return (NULL);
	}
	return (map);
}

int	valid_extension(char *str)
{
	int		i;
	char	*ext;

	i = 0;
	while (i < (ft_strlen(str) - 4))
		i ++;
	ext = ft_substr(str, i, 4);
	if (ft_strcmp(ext, ".ber") == 0)
	{
		free(ext);
		return (0);
	}
	free(ext);
	return (1);
}

char	*read_map(char *path)
{
	int		fd;
	int		read_chr;
	char	buffer[2];
	char	*map;

	map = ft_strdup("");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	read_chr = 42;
	while (read_chr != 0)
	{
		read_chr = read(fd, buffer, 1);
		if (read_chr == -1)
			return (NULL);
		if (read_chr == 0)
			break ;
		buffer[1] = '\0';
		map = ft_strjoin(map, buffer);
	}
	return (map);
}
