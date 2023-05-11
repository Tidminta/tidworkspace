/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidiane <tidiane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:04:36 by tminta            #+#    #+#             */
/*   Updated: 2023/05/10 01:00:53 by tidiane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	ft_exec(t_pipe	*box, int indic)
{
	int		res;
	int		pid;

	pid = fork();
	if (pid == 0)//son
	{
		res = execve(box->path[indic], box->f_args[indic], box->envp);
		exit(0);
	}
	else//father
	{
		(void)res;
		wait(&pid);
	}
}

//if (!get_path) -> handle_error(errno);
int	processing(t_pipe *box)
{
	int indic;

	indic = -1;	
    printf("[cmd1 = %s][cmd2 = %s][path cmd 1= %s] [path cmd 2= %s]\n", box->only_cmd[0], box->only_cmd[1], box->path[0], box->path[1]);
	// ft_open2(box);
	while (indic < 2)
		ft_exec(box, indic);
	// ft_pipe();
	// ft_redirections();
	return (0);
}

//  ./pipex file1 cmd1 cmd2 file2
int	main(int argc, char **argv, char **envp)
{
	t_pipe	*box;

	(void)argc;
	// if (argc != 5)
	// {
	// 	exit (0);
	// }
	ft_parsing_step(&box, argv, envp);
	if (!box)
		exit(0);
	processing(box);
	return (0);
}