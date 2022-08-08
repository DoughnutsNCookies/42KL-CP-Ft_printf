/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:30:15 by schuah            #+#    #+#             */
/*   Updated: 2022/07/16 16:30:16 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	default_flag(t_flags *flags)
{
	flags->num = 0;
	flags->neg = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->hash = 0;
	flags->spc = 0;
	flags->plus = 0;
	flags->width = 0;
	flags->prec = 0;
	flags->d = ' ';
}

int	is_format(char c)
{
	char	*formats;
	int		i;

	formats = "cspdiuxX%";
	i = -1;
	while (formats[++i])
		if (formats[i] == c)
			return (1);
	return (0);
}

int	get_space(const char *str, int *i)
{
	int	wc;

	wc = ft_atoi(str + *i);
	while (ft_isdigit(str[*i]))
		(*i)++;
	return (wc);
}

void	get_flags(const char *str, int *i, t_flags *flags)
{
	while (is_format(str[*i]) == 0 && str[*i] != '\0')
	{
		if (ft_isdigit(str[*i]) && str[*i] != '0')
		{
			flags->width = get_space(str, i);
			continue ;
		}
		if (str[*i] == '0')
			flags->zero = 1;
		else if (str[*i] == '-')
			flags->neg = 1;
		else if (str[*i] == '.' && (*i)++)
		{
			flags->dot = 1;
			flags->prec = get_space(str, i);
			continue ;
		}
		else if (str[*i] == '#')
			flags->hash = 1;
		else if (str[*i] == ' ')
			flags->spc = 1;
		else if (str[*i] == '+')
			flags->plus = 1;
		(*i)++;
	}
}
