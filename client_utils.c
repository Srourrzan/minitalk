/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:13:37 by codespace         #+#    #+#             */
/*   Updated: 2025/01/20 11:40:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 * If the pid is written using digits, the function will return 1
 * otherwise it will return 0.
 */

int     ft_validate_pid(const char *str)
{
    size_t  iter;
    int     valid;

    iter = 0;
    valid = 0;
    while(str[iter])
    {
        if (ft_isdigit(str[iter]))
            valid = 1;
        else
            return (0);
        iter++;
    }
    return (valid);
}
