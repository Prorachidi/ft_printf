/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:24:11 by murachid          #+#    #+#             */
/*   Updated: 2020/02/28 18:53:47 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_percent(t_flags flags)
{
	if (flags.minus == 1)
		ft_putchar('%');
	width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		ft_putchar('%');
}
