/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashakhky <ashakhky@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:25:36 by ashakhky          #+#    #+#             */
/*   Updated: 2022/01/24 16:25:38 by ashakhky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	const char	*end;

	if (!str)
		return (0);
	end = str;
	while (*end)
		end++;
	return (end - str);
}
