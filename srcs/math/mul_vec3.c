/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_vec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 11:23:28 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/22 11:33:06 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_math/vec3.h"

t_vec3				*mul_vec3(const t_vec3 *lhs, const void *rhs)
{
	t_vec3			*res;

	if (!(res = (t_vec3 *)malloc(sizeof(t_vec3))))
		return (NULL);
	res->vec3x.type = lhs->vec3x.type;
	res->vec3x.x = mul_vecnum(lhs->vec3x.type, lhs->vec3x.x, (void *)rhs);
	res->vec3x.y = mul_vecnum(lhs->vec3x.type, lhs->vec3x.y, (void *)rhs);
	res->vec3x.z = mul_vecnum(lhs->vec3x.type, lhs->vec3x.z, (void *)rhs);
	return (res);
}

t_vec3i				*mul_vec3i(const t_vec3i *lhs, const int rhs)
{
	return ((t_vec3i *)mul_vec3((t_vec3 *)lhs, &rhs));
}

t_vec3f				*mul_vec3f(const t_vec3f *lhs, const float rhs)
{
	return ((t_vec3f *)mul_vec3((t_vec3 *)lhs, &rhs));
}

t_vec3d				*mul_vec3d(const t_vec3d *lhs, const double rhs)
{
	return ((t_vec3d *)mul_vec3((t_vec3 *)lhs, &rhs));
}