/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradis <vradis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:50:21 by vradis            #+#    #+#             */
/*   Updated: 2024/09/04 17:42:33 by vradis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <math.h>

t_vec2	vec2(int x, int y)
{
	t_vec2	u;

	u.x = x;
	u.y = y;
	return (u);
}

int	vec2_cmp(t_vec2 u, t_vec2 v)
{
	int	p;

	p = (u.x == v.x && u.y == v.y);
	return (p);
}

int	maximum(int a, int b)
{
	int	c;

	c = a;
	if (a < b)
	{
		c = b;
	}
	return (c);
}

int	minimum(int a, int b)
{
	int	c;

	c = a;
	if (a > b)
	{
		c = b;
	}
	return (c);
}

int	clamp(int value, int min, int max)
{
	return (minimum(maximum(min, value), max));
}


