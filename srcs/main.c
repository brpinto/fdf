/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:10:31 by brpinto           #+#    #+#             */
/*   Updated: 2019/03/19 02:04:57 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int ac, char **av)
{
	char	*file;
	int		fd;

	if (ac != 2)
	{
		ft_putendl("Usage: ./fdf file");
		return (-1);
	}
	file = av[1];
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_putendl("No data found");
		return (0);
	}
	else
		fdf(fd);
	return (1);
}
