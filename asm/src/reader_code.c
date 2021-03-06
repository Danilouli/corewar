/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 15:49:01 by dsaadia           #+#    #+#             */
/*   Updated: 2018/05/29 17:23:06 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

static int	add_space_at(char **l, int i)
{
	char	*new;
	size_t	j;

	j = i;
	if (!(new = ft_strnew(ft_strlen(*l) + 1)))
		return ((int)super_herror("Malloc error", 0, 0));
	ft_strncpy(new, *l, i);
	new[i] = ' ';
	while (j < ft_strlen(*l))
	{
		new[j + 1] = (*l)[j];
		j++;
	}
	ft_strdel(l);
	*l = new;
	return (1);
}

static int	change_line_if_needed(char **l)
{
	int		i;
	char	*new;
	int		j;
	int		labpass;

	i = 0;
	new = 0;
	j = -1;
	labpass = 0;
	while ((*l)[i])
	{
		if ((*l)[i] && (((*l)[i] == DIRECT_CHAR && i > 0
		&& (*l)[i - 1] != SEPARATOR_CHAR && !ISSPTB((*l)[i - 1]))
		|| ((*l)[i] == LABEL_CHAR && (*l)[i + 1] && !ISSPTB((*l)[i + 1])
		&& i > 0 && (*l)[i - 1] != DIRECT_CHAR
		&& (*l)[i - 1] != SEPARATOR_CHAR && !ISSPTB((*l)[i - 1]) && !labpass)))
		{
			if (!add_space_at(l, i + ((*l)[i] == LABEL_CHAR)))
				return ((int)super_herror("Malloc error\n", 0, 0));
		}
		if ((*l)[i] == LABEL_CHAR)
			labpass = 1;
		i++;
	}
	return (1);
}

static int	label_case(char *l, char **spl, int nbp, t_list **new)
{
	t_list	*newla;

	newla = NULL;
	LASTC(spl[0]) = 0;
	LAST_LABEL = spl[0];
	if (!(newla = alloc_label(spl[0], spl)))
		return (0);
	if (!g_labels)
		g_labels = newla;
	else
		ft_lstpushback(g_labels, newla);
	if ((nbp > 1 && !is_op_name(spl[1])))
		return ((int)super_herror("Bad instr.", gce(spl[1], l), spl[1]));
	if (nbp > 1)
	{
		if (!(*new = alloc_line(spl, spl[0], nbp, l)))
			return (0);
		ft_lstpushback(g_lines, *new);
	}
	else
		ft_strdel(&l);
	return (1);
}

int			read_code_helper(char **spl, int nbp, t_list **new, char *l)
{
	t_list	*newla;

	newla = NULL;
	if (is_label(spl[0]))
	{
		if (!label_case(l, spl, nbp, new))
			return (0);
	}
	else if (!is_label(spl[0]) && is_op_name(spl[0]))
	{
		if (!(newla = alloc_label(NULL, spl)))
			return (0);
		if (!g_labels)
			g_labels = newla;
		else
			ft_lstpushback(g_labels, newla);
		if (!is_op_name(spl[0]))
			return ((int)super_herror("Bad instr.", gce(spl[0], l), spl[0]));
		if (!(*new = alloc_line(spl, 0, nbp, l)))
			return (0);
		ft_lstpushback(g_lines, *new);
	}
	else
		return ((int)super_herror("Inval. instr.", gce(spl[0], l), spl[0]));
	return (1);
}

int			read_code(char *l)
{
	char		**spl;
	t_list		*new;
	int			nbp;
	char		seps[3];

	seps[0] = ' ';
	seps[1] = '\t';
	seps[2] = SEPARATOR_CHAR;
	new = NULL;
	change_line_if_needed(&l);
	spl = ft_strsplit_mult(l, seps, &nbp);
	if (!nbp)
	{
		ft_strdel(&l);
		free(spl);
		return (1);
	}
	return (read_code_helper(spl, nbp, &new, l));
}
