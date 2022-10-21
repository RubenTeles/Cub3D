/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:32:11 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/21 19:15:33 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

t_list	*ft_read_map(char *filename)
{
	int		fd;
	char	*str;
	t_list	*map;

	map = NULL;
	if (string().len(filename) < 5)
		return (map);
	if (!string().cmp(filename + string().len(filename) - 4, ".cub"))
		return (map);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (map);
	str = get_next_line(fd);
	while (str)
	{
		if (!map)
			map = list().new(str);
		else
			(list().add)(map, str);
		str = get_next_line(fd);
	}
	close(fd);
	return (map);
}

int	ft_check_line(char *line)
{
	if (string().contains(line, "NO") == 1)
		return (1);
	if (string().contains(line, "SO") == 1)
		return (2);
	if (string().contains(line, "WE") == 1)
		return (3);
	if (string().contains(line, "EA") == 1)
		return (4);
	if (string().contains(line, "F") == 1)
		return (5);
	if (string().contains(line, "C") == 1)
		return (6);
	else
		return (0);
}

int	ft_is_path(char *str)
{
	int	i;
	int	fd;

	if (ft_check_line(str) < 1 || ft_check_line(str) > 4)
		return (0);
	i = 0;
	while (str && str[i] && str[i] >= 'A' && str[i] <= 'Z')
		i++;
	while (str && str[i] && string().is_spc(str[i]))
		i++;
	str = &str[i];
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (i);
}

int	ft_is_color(char *str)
{
	int	i;

	if (ft_check_line(str) < 5)
		return (0);
	i = 0;
	if (str && str[i] && str[i] >= 'A' && str[i] <= 'Z')
		i++;
	while (str && str[i] && string().is_spc(str[i]))
		i++;
	str = &str[i];
	if (*str <= '9' && string().atoi(str) <= 255 && string().atoi(str) >= 0)
		str = string().strnstr(str, ",", string().len(str)) + 1;
	else
		return (0);
	if (*str <= '9' && string().atoi(str) <= 255 && string().atoi(str) >= 0)
		str = string().strnstr(str, ",", string().len(str)) + 1;
	else
		return (0);
	if (*str <= '9' && string().atoi(str) <= 255 && string().atoi(str) >= 0)
		return (i);
	else
		return (0);
}

void	ft_choose_inf_elm(t_map *map, char *line)
{
	if (ft_check_line(line) == 1 && map->no == NULL)
		map->no = string().cpy(line + ft_is_path(line));
	if (ft_check_line(line) == 2 && map->so == NULL)
		map->so = string().cpy(line + ft_is_path(line));
	if (ft_check_line(line) == 3 && map->we == NULL)
		map->we = string().cpy(line + ft_is_path(line));
	if (ft_check_line(line) == 4 && map->ea == NULL)
		map->ea = string().cpy(line + ft_is_path(line));
	if (ft_check_line(line) == 5 && map->f == NULL)
		map->f = string().split(line + ft_is_color(line), ",");
	if (ft_check_line(line) == 6 && map->c == NULL)
		map->c = string().split(line + ft_is_color(line), ",");		
}
