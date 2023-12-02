/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:20:37 by momari            #+#    #+#             */
/*   Updated: 2023/12/01 22:07:00 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int main()
{
    // char  str[1024];
    int fd = open("txt.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));
    // printf("%s\n", get_next_line(fd));
    // printf("%s\n", get_next_line(fd));
    // printf("%s\n", get_next_line(fd));
    // printf("%s\n", get_next_line(fd));
}

