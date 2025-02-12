/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:17:41 by igngonza          #+#    #+#             */
/*   Updated: 2025/02/11 19:19:35 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H

# define CHECK_H

# include <fcntl.h>
//# include "../libft/inc/libft.h"
# include "map.h"

/* Basic checks to see if the correct file has been opened */
char	**check_params(int argc, char **argv, t_lay *lay);

/* Runs all map checker and builds map as a matrix */
char	**check_map(int fd, t_lay *lay);

#endif