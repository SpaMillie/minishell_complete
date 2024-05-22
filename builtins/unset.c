/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparratt <tparratt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:41:22 by tparratt          #+#    #+#             */
/*   Updated: 2024/05/22 12:25:54 by tparratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	unset(char *arg, t_data *data)
{
	char	**new_envp;
	int		i;
	int		j;

	new_envp = malloc_envp(data->envp);
	i = 0;
	j = 0;
	while (data->envp[i])
	{
		if (ft_strncmp(data->envp[i], arg, ft_strlen(arg)))
		{
			new_envp[j] = ft_strdup(data->envp[i]);
			j++;
		}
		i++;
	}
	new_envp[j] = NULL;
	free_2d(data->envp);
	data->envp = new_envp;
}

void	unset_cmd(char **args, t_data *data)
{
	int	i;

	if (!args[1])
		return ;
	i = 1;
	while (args[i])
	{
		unset(args[i], data);
		i++;
	}
}
