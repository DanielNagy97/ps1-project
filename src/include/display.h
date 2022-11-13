#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdlib.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>

#define OT_LENGTH 1       // the ordertable length
#define PACKETMAX 18      // the maximum number of objects on the screen
#define SCREEN_WIDTH 320  // screen width
#define SCREEN_HEIGHT 240 // screen height

void display();
void init_graphics();
void init_debugfont();

#endif