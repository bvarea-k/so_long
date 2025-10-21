/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:02:36 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/08/07 11:17:05 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	cleanup_gnl(void)
{
	static char	*buffer;

	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
}

char	*ft_strjoin_so_long(char *s1, char *s2)
{
	char	*string;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s2)
		return (s1);
	if (!s1)
		return (ft_strdup(s2));
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = (char *)ft_calloc(size, sizeof(char));
	if (!string)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0' && i < size - 1)
		string[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0' && j < size - 1)
		string[j++] = s2[i++];
	string[j] = '\0';
	free(s1);
	return (string);
}
