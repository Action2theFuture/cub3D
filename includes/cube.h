/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:30:44 by max               #+#    #+#             */
/*   Updated: 2024/11/10 22:18:18 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# ifdef DEBUG
#  define DEBUG_MODE 1
# else
#  define DEBUG_MODE 0
# endif

# ifdef BONUS
#  define BONUS 1
# else
#  define BONUS 0
# endif

# include <mlx.h>
# ifdef __linux__
#  include <X11/keysym.h>
#  include <X11/X.h>
# endif
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>

# include "libft.h"
# include "get_next_line.h"

# include "type.h"
# include "config.h"
# include "prototype.h"

#endif
