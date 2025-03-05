/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:35:12 by wbardzin          #+#    #+#             */
/*   Updated: 2024/07/04 13:40:37 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clear_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	char	*buf;
	int		i;
	int		k;

	if (!list || !*list)
		return ;
	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (!buf || !clean_node)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		++i;
	while (last_node->str_buf[i] && last_node->str_buf[++i])
		buf[k++] = last_node->str_buf[i];
	buf[k] = '\0';
	clean_node->str_buf = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);
}

char	*get_line(t_list *list)
{
	char	*next_str;
	int		str_len;

	if (!list)
		return (NULL);
	str_len = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (!next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	if (!list || !buf)
		return ;
	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buf;
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	char	*buf;
	int		char_read;

	if (!list)
		return ;
	while (!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		append(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	next_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	create_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = get_line(list);
	clear_list(&list);
	return (next_line);
}

/*#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open the file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
