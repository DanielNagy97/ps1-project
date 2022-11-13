#include <controller.h>

void init_pad()
{
	PadInit(0);
}

void reset_pad(void)
{
	SysPad = 0;
	SysPadT = 0;
}

void update_pad(void)
{
	int pad;
	pad = PadRead(0);
	SysPadT = pad & (pad ^ SysPad);
	SysPad = pad;
}
