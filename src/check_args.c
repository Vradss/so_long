/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:38:43 by vflorez           #+#    #+#             */
/*   Updated: 2024/08/27 15:54:43 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#define ARGS_ERROR "Try this format :  ./so_long maps/map1.ber"

int check_args(int argc, char **argv)
{
    if (argc != 2)
    {
        error(ARGS_ERROR);
        return (0);
    }

    char *format;
    format = ft_strrchr(argv[1], '.');

    if (!format || ft_strncmp(format, ".ber", 4) != 0)
    {
        error("Invalid map format (must be .ber)");
        return (0);
    }
    return (1);
}
