/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:24:48 by rteles            #+#    #+#             */
/*   Updated: 2022/11/27 11:51:12 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

void	path_pig(void)
{
	(canva())->data[CRISTAL].path = "./sprite/item/cristal_collect.xpm";
	(canva())->data[CRISTALS].path = "./sprite/item/cristal.xpm";
	(canva())->data[BUSH].path = "./sprite/item/bush.xpm";
	(canva())->data[BUSH_AMORAS].path = "./sprite/item/bush_amoras.xpm";
	(canva())->data[GRASS].path = "./sprite/item/grass_3.xpm";
	(canva())->data[PIG].path = "./sprite/pig/s0.xpm";
	(canva())->data[PIG_S0].path = "./sprite/pig/s0.xpm";
	(canva())->data[PIG_S1].path = 0;
	(canva())->data[PIG_S2].path = 0;
	(canva())->data[PIG_S3].path = 0;
	(canva())->data[CHICKEN].path = 0;
	(canva())->data[CHICKEN_S0].path = 0;
	(canva())->data[CHICKEN_S1].path = 0;
	(canva())->data[CHICKEN_S2].path = 0;
	(canva())->data[CHICKEN_S3].path = 0;
}

void	ft_path_alphabet_2(void)
{
	(canva())->data[_E].path = "./sprite/alphabet/E.xpm";
	(canva())->data[_F].path = "./sprite/alphabet/F.xpm";
	(canva())->data[_G].path = "./sprite/alphabet/G.xpm";
	(canva())->data[_H].path = "./sprite/alphabet/H.xpm";
	(canva())->data[_I].path = "./sprite/alphabet/I.xpm";
	(canva())->data[_J].path = "./sprite/alphabet/J.xpm";
	(canva())->data[_K].path = "./sprite/alphabet/K.xpm";
	(canva())->data[_L].path = "./sprite/alphabet/L.xpm";
	(canva())->data[_M].path = "./sprite/alphabet/M.xpm";
	(canva())->data[_N].path = "./sprite/alphabet/N.xpm";
	(canva())->data[_O].path = "./sprite/alphabet/O.xpm";
	(canva())->data[_P].path = "./sprite/alphabet/P.xpm";
	(canva())->data[_Q].path = "./sprite/alphabet/Q.xpm";
	(canva())->data[_R].path = "./sprite/alphabet/R.xpm";
	(canva())->data[_S].path = "./sprite/alphabet/S.xpm";
	(canva())->data[_T].path = "./sprite/alphabet/T.xpm";
	(canva())->data[_U].path = "./sprite/alphabet/U.xpm";
	(canva())->data[_V].path = "./sprite/alphabet/V.xpm";
	(canva())->data[_W].path = "./sprite/alphabet/W.xpm";
	(canva())->data[_X].path = "./sprite/alphabet/X.xpm";
	(canva())->data[_Y].path = "./sprite/alphabet/Y.xpm";
	(canva())->data[_Z].path = "./sprite/alphabet/Z.xpm";
	path_pig();
}

void	ft_path_alphabet(void)
{
	(canva())->data[_BARRA].path = "./sprite/alphabet/barra.xpm";
	(canva())->data[_ZERO_].path = "./sprite/alphabet/0.xpm";
	(canva())->data[_ONE].path = "./sprite/alphabet/1.xpm";
	(canva())->data[_TWO].path = "./sprite/alphabet/2.xpm";
	(canva())->data[_THREE].path = "./sprite/alphabet/3.xpm";
	(canva())->data[_FOUR].path = "./sprite/alphabet/4.xpm";
	(canva())->data[_FIVE].path = "./sprite/alphabet/5.xpm";
	(canva())->data[_SIX].path = "./sprite/alphabet/6.xpm";
	(canva())->data[_SEVEN].path = "./sprite/alphabet/7.xpm";
	(canva())->data[_EIGHT].path = "./sprite/alphabet/8.xpm";
	(canva())->data[_NINE].path = "./sprite/alphabet/9.xpm";
	(canva())->data[_A].path = "./sprite/alphabet/A.xpm";
	(canva())->data[_B].path = "./sprite/alphabet/B.xpm";
	(canva())->data[_C].path = "./sprite/alphabet/C.xpm";
	(canva())->data[_D].path = "./sprite/alphabet/D.xpm";
	return (ft_path_alphabet_2());
}

void	ft_path_game(void)
{
	(canva())->data[MAP].path = "./sprite/item/map.xpm";
	(canva())->data[MINIMAP].path = "./sprite/item/minimap_2.xpm";
	(canva())->data[CLOUD_1].path = "./sprite/item/cloud_1.xpm";
	(canva())->data[CLOUD_2].path = "./sprite/item/cloud_2.xpm";
	(canva())->data[CLOUD_3].path = "./sprite/item/cloud_3.xpm";
	(canva())->data[TREE].path = "./sprite/item/tree_02.xpm";
	(canva())->data[WOOD_FLOOR].path = "./sprite/item/house_wall.xpm";
	(canva())->data[WINDOW].path = "./sprite/item/house_window.xpm";
	(canva())->data[DOOR].path = "./sprite/item/house_door.xpm";
	(canva())->data[DOOR_OPEN].path = "./sprite/item/house_door_open.xpm";
	(canva())->data[HAY].path = "./sprite/item/house_wall.xpm";
	(canva())->data[CAVE].path = "./sprite/item/cave.xpm";
	return (ft_path_alphabet());
}

void	ft_path_start(void)
{
	(canva())->data[N_WALL].path = all()->file->no;
	(canva())->data[E_WALL].path = all()->file->ea;
	(canva())->data[S_WALL].path = all()->file->so;
	(canva())->data[W_WALL].path = all()->file->we;
	(canva())->data[MENU].path = "./sprite/item/background_menu.xpm";
	(canva())->data[SIGN].path = "./sprite/item/sign.xpm";
	(canva())->data[WALK].path = "./sprite/wolf/wolf_walk.xpm";
	(canva())->data[AVATAR].path = "./sprite/wolf/head1.xpm";
	(canva())->data[AVATAR_2].path = "./sprite/wolf/head0.xpm";
	(canva())->data[HAND].path = "./sprite/wolf/wolf_hand.xpm";
	(canva())->data[NICE].path = "./sprite/wolf/hand_nice.xpm";
	(canva())->data[ATACK_1].path = "./sprite/wolf/atack/wolf_hand_1.xpm";
	(canva())->data[ATACK_2].path = "./sprite/wolf/atack/wolf_hand_2.xpm";
	(canva())->data[ATACK_3].path = "./sprite/wolf/atack/wolf_hand_3.xpm";
	(canva())->data[ATACK_4].path = "./sprite/wolf/atack/wolf_hand_4.xpm";
	(canva())->data[RUN].path = "./sprite/item/run_effect.xpm";
	(canva())->data[HEART].path = "./sprite/item/live.xpm";
	ft_path_game();
}
