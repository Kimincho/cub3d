/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:06:31 by minchoi           #+#    #+#             */
/*   Updated: 2022/03/03 19:53:21 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

/*
** ==================
** Window Option
** ==================
*/
# define WIDTH					640
# define HEIGHT					480
# define TEXTUREWIDTH			64
# define TEXTUREHEIGHT			64

/*
** ==================
** Compass
** ==================
*/
# define NO						0
# define SO						1
# define WE						2
# define EA						3

/*
** ==================
** Error Type
** ==================
*/
# define INVALID_ARG			0
# define OPEN_ERR				1
# define INVALID_ELEMENT		2
# define NOENOUGH_ELEMENT		3
# define ALLOC_ERR				4
# define INVALID_MAP			5
# define INVALID_FILE			6

/*
** ==================
** mlx Event Type
** ==================
*/
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

/*
** ==================
** Keyboard
** ==================
*/
# define K_A	0
# define K_S	1
# define K_D	2
# define K_W	13

# define K_AR_L	123
# define K_AR_R	124
# define K_AR_D	125
# define K_AR_U	126

# define K_ESC	53

#endif