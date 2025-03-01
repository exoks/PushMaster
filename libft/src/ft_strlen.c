/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:16:13 by oezzaou           #+#    #+#             */
/*   Updated: 2025/03/01 15:39:26 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//====<[ ft_strlen: ]>==========================================================
size_t	ft_strlen(const char *s)
{
	int	len;

	len = -1;
	while (s[++len] != '\0')
		;
	return (len);
}
// size_t	ft_strlen(const char *s)
// {
// 	if (s == NULL)
// 		return (-1);
// 	if (*s)
// 		return (1 + ft_strlen(++s));
// 	return (0);
// }
