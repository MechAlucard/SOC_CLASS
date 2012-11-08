#ifndef __REG16_AVALON_INTERFACE_REGS_H__
#define __REG16_AVALON_INTERFACE_REGS_H__
#include <io.h>
#include <alt_types.h>

#define IOWR_REG16_AVALON_INTERFACE_DATA(data) 		\
		IOWR_16DIRECT(REG16_AVALON_INTERFACE_0_BASE,0,data);
#endif