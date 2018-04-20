/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:25:55 by vlay              #+#    #+#             */
/*   Updated: 2018/01/25 14:53:30 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_list	*option(int ac, char **av, char *opt, t_champ *champs)
{
	int				i;
	unsigned char	n_champ;
	t_list			*allprocess;

	i = 1;
	n_champ	= 0;
	allprocess = NULL;
	while (i < ac)
	{
		if ((n_champ == MAX_PLAYERS) && (ft_printf("Too many champions.\n"))) // Straight forward
			return (NULL);
		else if (!ft_strcmp(STEALTH, av[i]) && !ft_strchr(opt, '-')) // Adds '-' to opt if stealth is activated
		{
			ft_printf("Stealth mode activated : %s\n", av[i]);
			ft_strpush(opt, '-');
		}
		else if (av[i][0] == '-' && ft_strlen(av[i]) == 2 && ft_strchr(OPTION, av[i][1]))
			ft_strpush(opt, av[i][1]);
		else if (ischamp(av[i], &champs[n_champ], n_champ))
		{
			ft_lstadd(&allprocess, ft_lstlink(createproc(&champs[n_champ], 1, NULL), sizeof(t_process)));
			ft_printf("Process has been added.\n");
			n_champ++;
			ft_printf("Champion has been added.\n");
		}
		else {
			ft_printf("Option unknown.\n");
			return (NULL);
		}
		i++;
	}
	champs[n_champ].name = NULL;
	champs[n_champ].num = -1;
	return (allprocess);
}
