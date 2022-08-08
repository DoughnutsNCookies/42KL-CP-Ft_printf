/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:20:20 by schuah            #+#    #+#             */
/*   Updated: 2022/07/13 18:50:04 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd, int wc)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (10);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		wc += ft_putnbr_fd(n / 10, fd, wc);
		wc += ft_putnbr_fd(n % 10, fd, wc);
	}
	else
	{
		write(fd, &"0123456789"[n], 1);
		return (1);
	}
	return (wc);
}
