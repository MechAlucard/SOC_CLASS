#include "system.h"
#include "io.h"
#include "alt_types.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
//#define FOPEN_WAY
void waste();
int main()
{
	/*alt_u16 i = 0;
	IOWR_32DIRECT(REG16_AVALON_INTERFACE_0_BASE,0,5);
	for(i = 0; i < 4096; i++)
	{
		IOWR_16DIRECT(REG16_AVALON_INTERFACE_0_BASE,0,i);
		waste();
	}
	for(i = 0; i <= 255; i++)
	{
		IOWR_8DIRECT(REG16_AVALON_INTERFACE_0_BASE,0,i);
		waste();
		IOWR_8DIRECT(REG16_AVALON_INTERFACE_0_BASE,1,i);
		waste();
	}
	return 0;
	*/
	alt_u8 num = 0;
#ifdef FOPEN_WAY
	FILE* fp;
#else
	int fd;
#endif

	{
#ifdef FOPEN_WAY
					fp = fopen("/dev/reg16_avalon_interface_0" , "w");
					while(1)
					{
						fprintf(fp, "%c", num);
						fflush(fp);
						num++;
						waste();
						if(num > 0x0F)
						num = 0;
					}

#else
					alt_u8 str[6] = {'0x01','0x02','0x03','0x04','0x05','0x06'};
					fd = open("/dev/reg16_avalon_interface_0" , O_WRONLY, 0);
						write(fd,str,0);
						waste();
						write(fd,str,1);
						waste();
						write(fd,str,2);
						waste();
						write(fd,str,3);
						waste();
						write(fd,str,4);
						waste();
						write(fd,str,6);
					while(1)
					{
						write(fd, &num, 1);
						num++;
						waste();
						if(num > 0x0F)
						num = 0;
					}

#endif

	//	fprintf(fp, "%s", "ABCDEFG");
	}

}
void waste()
{
 int i = 0;
 for(i=0; i<500000; i++);
}
