/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_alpabeth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:52:20 by rteles            #+#    #+#             */
/*   Updated: 2022/11/08 00:25:08 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

#define ALPHABET 'P'

void	x_alphabet_image(t_data *img, double larg, double alt, int pos_x, int pos_y)
{
	int		x;
	int		y;
	int		color;
	double	x_red;
	double	y_red;	

	x_red = 0;
	y_red = 0;
	y = -1;
	while (++y <= img->start_pos[Y])
	{
		x = -1;
		x_red = 0;
		while (++x <= img->start_pos[X])
		{
			color = get_pixel_color(img, x_red, y_red);
			if (color > 0)
				my_mlx_pixel_put((canva())->data, x + pos_x,\
					y + pos_y, color);
			x_red += img->larg / larg;
		}
		y_red += img->alt / alt;
	}
}


void	ft_alpabeth(int	letter)
{
	(void)letter;
	/*t_data	*data;
	int		x;
	int		y;
	int		color;
	int		letter_x;
	int		letter_y;
	int		x_red;
	int		y_red;	

	//letter = 21;
	x_red = 0;
	letter_y = letter / 7;
	letter_x = letter - letter_y * 7;
	//printf("X: %i Y: %i\n", letter_x, letter_y);
	data = (canva())->sprite(ALPHABET);
	if (!data)
		return ;
	// || letter == 7 6
	if (letter >= 0 && letter <= 4)
	{
		data->start_pos[X] = data->larg / 8 + 2;
		data->start_pos[Y] = data->alt / 5 + 8;
	}
	else if (letter == 6 || letter == 12)
	{
		data->start_pos[X] = data->larg / 8;
		data->start_pos[Y] = data->alt / 5;
	}
	else if (letter == 5)
	{
		data->start_pos[X] = data->larg / 8;
		data->start_pos[Y] = data->alt / 5 + 20;
	}
	else if (letter == 9)
	{
		data->start_pos[X] = data->larg / 8;
		data->start_pos[Y] = data->alt / 5 - 6;
	}
	else if (letter >= 7 && letter <= 13)
	{
		data->start_pos[X] = data->larg / 8;
		data->start_pos[Y] = data->alt / 5 - 8;
	}
	else if (letter == 14)
	{
		data->start_pos[X] = data->larg / 8 + 10;
		data->start_pos[Y] = data->alt / 5 - 16;
	}
	else if (letter == 15 || letter == 18)
	{
		//printf("ahah");
		data->start_pos[X] = data->larg / 8;
		data->start_pos[Y] = data->alt / 5 - 14;	
	}
	else if (letter == 19 || letter == 17)
	{
		data->start_pos[X] = data->larg / 8;
		data->start_pos[Y] = data->alt / 5 - 12;	
	}
	else if (letter >= 17 && letter <= 20)
	{
		data->start_pos[X] = data->larg / 8;
		data->start_pos[Y] = data->alt / 5 - 12;	
	}
	else if (letter >= 21)
	{
		data->start_pos[X] = data->larg / 8;
		data->start_pos[Y] = data->alt / 5 - 15;
	}
	y = 20 + (data->start_pos[Y] * (letter_y));
	if (letter == 22 || letter == 25)
		y = (data->start_pos[Y] * letter_y) + 5;
	y_red = 0;
	while (++y <= data->start_pos[Y] * (1 + letter_y))
	{
		x_red = 0;
		x = 28 + (data->start_pos[X] * letter_x);
		if (letter >= 21)
			x = (data->start_pos[X] * letter_x);
		while (++x <= data->start_pos[X] * (1 + letter_x))
		{
			color = get_pixel_color(data, x, y);
			//if (color > 0)
				my_mlx_pixel_put((canva())->data, x_red, y_red, color);
			x_red++;
		}
		y_red++;
	}*/
		

		
   // 8/6
   // totalx / 8
   // totaly / 6
    //printf("Y: %i X: %i\n", data->alt/5, data->larg/8);
	/*x_alphabet_image(data, (engine())->size[X] * 0.2, (engine())->size[Y] * 0.2,\
		(engine())->size[X] * 0.31, (engine())->size[Y] * 0.35);*/
}
