/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:41:00 by murachid          #+#    #+#             */
/*   Updated: 2020/02/28 18:45:09 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write(void)
{
	ft_putchar('0');
	ft_putchar('x');
}

void	ft_ptr_input(char *hex, t_flags flags)
{
	ft_write();
	if (flags.dot >= 0)
		width(flags.dot, ft_strlen(hex) + 2, 1);
	ft_putstr(hex, ft_strlen(hex));
}

void	ft_put_ptr(char *hex, t_flags flags)
{
	if (flags.minus == 1)
		ft_ptr_input(hex, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hex))
		flags.dot = ft_strlen(hex);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		width(flags.width - 2, 0, 0);
	}
	else
		width(flags.width, ft_strlen(hex) + 2, flags.zero);
	if (flags.minus == 0)
		ft_ptr_input(hex, flags);
}

void	ft_ptr(unsigned long long number, t_flags flags)
{
	char	*hex;
	int		k;

	k = 0;
	if ((flags.dot == 0 && number == 0) && flags.minus == 0)
	{
		width(flags.width - 2, 0, 0);
		ft_write();
		k = 1;
	}
	else if ((flags.dot == 0 && number == 0) && flags.minus == 1)
	{
		ft_write();
		width(flags.width - 2, 0, 0);
		k = 1;
	}
	if (k == 0)
	{
		hex = ft_utl_base((unsigned long long)number, 16);
		hex = ft_str_tolower(hex);
		ft_put_ptr(hex, flags);
		free(hex);
	}
}
