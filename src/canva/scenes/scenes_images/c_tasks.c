/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_tasks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:27:32 by rteles            #+#    #+#             */
/*   Updated: 2022/11/25 16:15:20 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

static int	*ft_how_many_enimies(int sprite)
{
	t_object	*aux;
	int			*kill_and_max;

	kill_and_max = malloc(sizeof(int) * 2);
	kill_and_max[0] = 0;
	kill_and_max[1] = 0;
	aux = (engine())->enemies;
	while (aux)
	{
		if (aux->title == sprite)
		{
			if (aux->life <= 0)
				kill_and_max[0]++;
			kill_and_max[1]++;
		}
		aux = aux->next;
	}
	return (kill_and_max);
}

void	ft_tasks_enimies(char *label, int sprite, double larg, double y)
{
	int	*kill_and_max;
	
	kill_and_max = ft_how_many_enimies(sprite);
	(canva())->resize((canva())->sprite(sprite), (engine())->size[X] * 0.03,\
	(engine())->size[Y] * 0.03, (engine())->size[X] * 0.03,\
	(engine())->size[Y] * (0.45 + y));
	ft_put_word(label, (engine())->size[X] * (0.07 + larg),\
		(engine())->size[Y] * 0.02, (engine())->size[X] * 0.065,\
		(engine())->size[Y] * (0.456 + y));
	ft_put_word((string()).itoa(kill_and_max[0]), (engine())->size[X] * 0.019,\
	(engine())->size[Y] * 0.02,\
	(engine())->size[X] * 0.185, (engine())->size[Y] * (0.456 + y));
	ft_put_word("/", (engine())->size[X] * 0.02, (engine())->size[Y] * 0.019,\
	(engine())->size[X] * 0.205, (engine())->size[Y] * (0.456 + y));
	ft_put_word((string()).itoa(kill_and_max[1]), (engine())->size[X] * 0.019,\
	(engine())->size[Y] * 0.02,\
	(engine())->size[X] * 0.225, (engine())->size[Y] * (0.456 + y));
	free(kill_and_max);
}

void	ft_tasks(t_scene_img *scene)
{
	(void)scene;
	ft_print_color((engine())->size[X] * 0.232, (engine())->size[Y] * 0.456,\
		(engine())->size[X] * 0.021, (engine())->size[Y] * 0.351, 0X6b4324);
	ft_print_color((engine())->size[X] * 0.225, (engine())->size[Y] * 0.444,\
		(engine())->size[X] * 0.024, (engine())->size[Y] * 0.357, 0xe6be7e);
	ft_put_word("TASKS", (engine())->size[X] * 0.12, (engine())->size[Y] *\
		0.03, (engine())->size[X] * 0.077, (engine())->size[Y] * 0.376);
	ft_tasks_enimies("PIGS", PIG_S0, 0, 0);
	//ft_tasks_enimies("CHICKENS", CHICKEN_S0, 0.04, 0.05);
	ft_tasks_enimies("CRISTALS", CRISTAL, 0.04, 0.1);
}
