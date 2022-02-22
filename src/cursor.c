#include <stdio.h>
#include <dhanda/cursor.h>

#define CUR_OVERFLOW       1000
#define CUR_UP_CODE        "\x1b[%dA"					// console codes for moving cursor
#define CUR_RIGHT_CODE     "\x1b[%dC"
#define CUR_DOWN_CODE      "\x1b[%dB"
#define CUR_LEFT_CODE      "\x1b[%dD"
#define CUR_TOUP_CODE      "\x1b[1000A"
#define CUR_TORIGHT_CODE   "\x1b[1000C"
#define CUR_TODOWN_CODE    "\x1b[1000B"
#define CUR_TOLEFT_CODE    "\x1b[1000D"
#define CUR_HOME_CODE      "\x1b[H"
#define CUR_YX_CODE        "\x1b[%d;%dH"

#define CLEAR_SCR          "\x1b[2J"
#define CLEAR_SCR_HOME     "\x1b[2J\x1b[H"

#define CUR_HIDE     		"\x1b[25l"
#define CUR_SHOW     		"\x1b[25h"


void cur_move(unsigned int direction)
{
	if (direction < CUR_MIN || direction > CUR_MAX)
		return;

	switch(direction)
	{
		case CUR_UP    : printf(CUR_UP_CODE, 1); break;
		case CUR_DOWN  : printf(CUR_DOWN_CODE, 1); break;
		case CUR_RIGHT : printf(CUR_RIGHT_CODE, 1); break;
		case CUR_LEFT  : printf(CUR_LEFT_CODE, 1); break;
	}
}

void cur_nmove(unsigned int direction, unsigned int nstep)
{
	if (direction < CUR_MIN || direction > CUR_MAX)
		return;

	for (int i = 0; i < nstep; ++i)
		cur_move(direction);
}

void cur_up(unsigned int nstep)
{
	printf(CUR_UP_CODE, nstep);
}

void cur_right(unsigned int nstep)
{
	printf(CUR_RIGHT_CODE, nstep);
}

void cur_down(unsigned int nstep)
{
	printf(CUR_DOWN_CODE, nstep);
}

void cur_left(unsigned int nstep)
{
	printf(CUR_LEFT_CODE, nstep);
}

void cur_totop()
{
	printf(CUR_UP_CODE, CUR_OVERFLOW);
}

void cur_toright()
{
	printf(CUR_RIGHT_CODE, CUR_OVERFLOW);
}

void cur_tobottom()
{
	printf(CUR_DOWN_CODE, CUR_OVERFLOW);
}

void cur_toleft()
{
	printf(CUR_LEFT_CODE, CUR_OVERFLOW);
}

void cur_toyx(unsigned int y, unsigned int x)
{
	cur_totop();
	cur_toleft();
	cur_right(x);
	cur_down(y);
}

void clear()
{
	printf(CLEAR_SCR_HOME);
}

void cur_visibility(int visibility)
{
	if (visibility)
		printf(CUR_SHOW);
	else
		printf(CUR_HIDE);
}

void cur_hide()
{
	cur_visibility(0);
}

void cur_show()
{
	cur_visibility(1);
}
