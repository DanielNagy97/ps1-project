#include <display.h>

GsOT myOT[2];
GsOT_TAG myOT_TAG[2][1<<OT_LENGTH];
PACKET GPUPacketArea[2][PACKETMAX];

u_long __ramsize   = 0x00200000; // force 2 megabytes of RAM
u_long __stacksize = 0x00004000; // force 16 kilobytes of stack

void display()
{
	short CurrentBuffer;

	FntFlush(-1); // refresh the font
	CurrentBuffer = GsGetActiveBuff();
	GsSetWorkBase((PACKET*)GPUPacketArea[CurrentBuffer]); // setup the packet workbase
	GsClearOt(0, 0, &myOT[CurrentBuffer]);
	DrawSync(0);
	VSync(0);
	GsSwapDispBuff();
	GsSortClear(0, 110, 127, &myOT[CurrentBuffer]);
	GsDrawOt(&myOT[CurrentBuffer]); // Draw the ordering table for the CurrentBuffer
}

void init_graphics()
{
	if (*(char *)0xbfc7ff52=='E') {
		SetVideoMode(1); //PAL
	} else {
		SetVideoMode(0); //NTSC
	}
	
	GsInitGraph(SCREEN_WIDTH, SCREEN_HEIGHT, GsINTER|GsOFSGPU, 1, 0); // set the graphics mode resolutions. You may also try using 'GsNONINTER' (read LIBOVR46.PDF in PSYQ/DOCS for detailed information)
	GsDefDispBuff(0, 0, 0, SCREEN_HEIGHT); // set the top left coordinates of the two buffers in video memory

	// init the ordering tables
	myOT[0].length = OT_LENGTH;
	myOT[1].length = OT_LENGTH;
	myOT[0].org = myOT_TAG[0];
	myOT[1].org = myOT_TAG[1];

	GsClearOt(0, 0, &myOT[0]);
	GsClearOt(0, 0, &myOT[1]);
}

void init_debugfont() {
	FntLoad(960, 256); // load the font from the BIOS into VRAM/SGRAM
	SetDumpFnt(FntOpen(5, 20, 320, 240, 0, 512)); // screen X,Y | max text length X,Y | automatic background clear 0,1 | max characters
}

LINE_F2 init_line(int x0, int y0, int x1, int y1) {
	LINE_F2 line;
	SetLineF2(&line);
	setRGB0(&line, 178, 39, 39);
	setXY2(&line, x0, y0, x1, y1);
	return line;
}

POLY_F4 init_rect(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
	POLY_F4 poly;
	SetPolyF4(&poly);
	setRGB0(&poly, 238, 80, 7);
	setXY4(&poly, x0, y0, x1, y1, x2, y2, x3, y3);
	return poly;
}

void move_rect(POLY_F4* poly, int x0, int y0, int velocity_x, int velocity_y) {
	poly->x0 += (x0 * (velocity_x * 0.1));
	poly->x1 += (x0 * (velocity_x * 0.1));
	poly->x2 += (x0 * (velocity_x * 0.1));
	poly->x3 += (x0 * (velocity_x * 0.1));
	
	poly->y0 += (y0 * (velocity_y * 0.1));
	poly->y1 += (y0 * (velocity_y * 0.1));
	poly->y2 += (y0 * (velocity_y * 0.1));
	poly->y3 += (y0 * (velocity_y * 0.1));
}