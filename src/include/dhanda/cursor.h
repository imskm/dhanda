#ifndef _SKM_CURSOR_H_
#define _SKM_CURSOR_H_

/**
 * cursor.h
 * Date: 9-10-2018       Author: Shek Muktar
 * ------------------------------------------------------------------
 *  This file handles cursor movements
 *
 *
 *
 */

/**
 * Declaring some constants
 */
#define CUR_MIN             1
#define CUR_UP              1
#define CUR_RIGHT           2
#define CUR_DOWN            3
#define CUR_LEFT            4
#define CUR_MAX             4

/**
 * structure represent point on a plane
 * used in finding cursor position
 *
 * @var x  int   position on x-axis
 * @var y  int   position on y-axis
 */
struct point_t {
	int x, y;
};

void cur_move(unsigned int direction);					// Moving cursor from current position to given direction
void cur_nmove(unsigned int direction, unsigned int nstep);
void cur_up(unsigned int nstep);
void cur_right(unsigned int nstep);
void cur_down(unsigned int nstep);
void cur_left(unsigned int nstep);

void cur_totop();
void cur_toright();
void cur_tobottom();
void cur_toleft();
void cur_toyx(unsigned int y, unsigned int x);

void cur_centre();
struct point_t cur_position();
void clear();

void cur_visibility(int visibility);
void cur_hide();
void cur_show();

#endif
