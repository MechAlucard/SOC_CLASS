#include <errno.h>
#include <priv/alt_file.h>
#include "reg16_avalon_interface.h"
#include "reg16_avalon_interface_regs.h"
#define LOWER_BYTE 0x0F
#define SHIFT_BYTE 4
int reg16_avalon_interface_write_fd (alt_fd* fd, const char* ptr, int len)
{
	int count = 0;
	reg16_avalon_interface_dev *reg16 = (reg16_avalon_interface_dev*)fd->dev;
	while(len--)
	{
		reg16->buffer = ((reg16->buffer << SHIFT_BYTE)|(*ptr && LOWER_BYTE));
		IOWR_REG16_AVALON_INTERFACE_DATA(reg16->buffer);
		ptr++;
		count++;
	}
	return count;
}
/*
reg16_avalon_dev* reg16_avalon_open_dev(const char* name)
{
  // find the device from the device list 
  // (see altera_hal/HAL/inc/priv/alt_file.h 
  // and altera_hal/HAL/src/alt_find_dev.c 
  // for details)
  reg16_avalon_dev *dev = (reg16_avalon_dev*)alt_find_dev(name, &alt_dev_list);

  return dev;
}
*/
