/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreedel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 10:09:24 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/04 17:01:16 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_base/btree.h"

void				ft_btreedel(t_btree **tree, void (*del)(void *, size_t))
{
	if ((*tree)->left)
		ft_btreedel(&(*tree)->left, del);
	if ((*tree)->right)
		ft_btreedel(&(*tree)->right, del);
	ft_btreedelone(tree, del);
}

void				ft_btreedelone(t_btree **node, void (*del)(void *, size_t))
{
	if (del)
		(*del)((*node)->content, (*node)->content_size);
	free((*node)->content);
	free(*node);
	*node = NULL;
}
