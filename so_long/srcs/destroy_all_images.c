/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all_images.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:08:23 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/23 16:08:42 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_all_images(t_img_ptr **lst, void *mlx_ptr)
{
	t_img_ptr	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		if ((*lst)->img_ptr)
			mlx_destroy_image(mlx_ptr, (*lst)->img_ptr);
		free(*lst);
		*lst = tmp;
	}
}
