#include <stdlib.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>


#define OT_LENGTH 1 // the ordertable length
#define PACKETMAX 18 // the maximum number of objects on the screen
#define SCREEN_WIDTH  320 // screen width
#define	SCREEN_HEIGHT 240 // screen height


void display();
void init_graphics();
void init_debugfont();
LINE_F2 init_line(int x0, int y0, int x1, int y1);
POLY_F4 init_rect(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3);
void move_rect(POLY_F4* poly, int x0, int y0, int velocity_x, int velocity_y);