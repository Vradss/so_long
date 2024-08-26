/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradis <vradis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:38:43 by vflorez           #+#    #+#             */
/*   Updated: 2024/08/22 18:21:00 by vradis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#define ARGS_ERROR "Intenta este formato :  ./so_long maps/map1.ber \n"

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
        ft_printf("Error de mapa.ber \n");
        return (0);
    }
    return (1);
}

// int main(int argc, char **argv)
// {
//     if (!check_args(argc, argv))
//         return (1);

//     ft_printf("All args are correct\n");
//     read_map(argv[1]);
//     return (0);
// }