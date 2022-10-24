/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:18:17 by amaria-m          #+#    #+#             */
/*   Updated: 2022/09/08 11:56:17 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

typedef struct s_line
{
	char			*line;
	long			size_line;
	long			index;
	long			size_buffer;
	long			size_read;
	struct s_line	*v;
}	t_line;

char	*get_line(char *line, char *buffer, long size_buffer, long *size_line)
{
	t_line	data;

	data.size_line = -1;
	data.index = -1;
	data.size_buffer = -1;
	data.line = line;
	*size_line += size_buffer;
	line = malloc(*size_line + 1 * sizeof(char));
	if (line)
	{
		line[*size_line] = 0;
		while (data.line && data.line[++data.size_line])
			line[++data.index] = data.line[data.size_line];
		data.size_line = -1;
		while (buffer && buffer[++data.size_line])
		{
			if (data.size_line < size_buffer)
				line[++data.index] = buffer[data.size_line];
			else
				buffer[++data.size_buffer] = buffer[data.size_line];
			buffer[data.size_line] = 0;
		}
	}
	free(data.line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	f[BUFFERSIZE + 1];
	t_line		d;

	d.line = NULL;
	d.size_buffer = 0;
	d.index = 1;
	while (fd >= 0 && f[d.size_buffer])
		d.size_buffer++;
	d.size_line = 0;
	while (fd >= 0 && d.index > 0)
	{
		if (!f[0] || !d.size_buffer)
			d.size_buffer = read(fd, f, BUFFERSIZE);
		d.index = d.size_buffer;
		if (d.size_buffer > 0)
		{
			d.size_buffer = 0;
			while (f[d.size_buffer] && f[d.size_buffer] != '\n')
				d.size_buffer++;
			d.index = (d.index == d.size_buffer);
			d.size_buffer += f[d.size_buffer] == '\n';
			d.line = get_line(d.line, f, d.size_buffer, &d.size_line);
		}
	}
	return (d.line);
}
