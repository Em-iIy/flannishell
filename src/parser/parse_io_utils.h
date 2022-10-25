/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_io_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:24:14 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/18 13:25:07 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_IO_UTILS_H
# define PARSE_IO_UTILS_H

//----------------------------------------Includes
# include "parser.h"

//----------------------------------------Prototypes
t_file	*io_new(int iden);
void	io_free(t_file *file);
t_file	*io_last(t_file *file);
void	io_add_back(t_file **file, t_file *new);
void	io_free_all(t_file *file);

#endif