/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:19:34 by thloyan           #+#    #+#             */
/*   Updated: 2023/06/11 16:32:55 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>

int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

double	ft_atof(const char *nptr)
{
	double	res;
	double	sign;
	double	pow;

	res = 0;
	sign = 1;
	pow = 1;
	while (*nptr && ft_isspace(*nptr))
		nptr++;
	if (*nptr && (*nptr == '-' || *nptr == '+'))
	{
		if (*nptr == '-')
			sign = sign * -1;
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr))
	{
		res = (res * 10) + (*nptr - '0');
		nptr++;
	}
	if (*nptr == '.')
		nptr++;
	while (*nptr && ft_isdigit(*nptr))
	{
		res = (res * 10) + (*nptr - '0');
		pow = (pow * 10);
		nptr++;
	}
	return ((res * sign) / pow);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*sc1;
	unsigned char	*sc2;
	int				i;

	sc1 = (unsigned char *)s1;
	sc2 = (unsigned char *)s2;
	i = 0;
	while (sc1[i] && sc2[i] && !(sc1[i] - sc2[i]))
		i++;
	return (sc1[i] - sc2[i]);
}
