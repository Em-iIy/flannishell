/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:50:51 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/12 12:02:31 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include <stdio.h>

# define DEBUG(msg,dq,q) printf("%s:%d    \t%-17s\t%-40s dq:%d\tq:%d\n", __FILE__, __LINE__, __func__, msg,dq,q)
# ifndef DEBUG
#  define DEBUG(msg,dq,q)
# endif

#endif