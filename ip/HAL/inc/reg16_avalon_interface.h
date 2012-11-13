//Author: Tyler Martin
//Filename:  reg16_avalon_interface.h
//Date: 11/13/2012
//Description: this contains the file open and writing function prototypes for the 7seg display
#ifndef __REG16_AVALON_INTERFACE_H__
#define __REG16_AVALON_INTERFACE_H__
#include <stddef.h>
#include <alt_types.h>
#include<sys/alt_dev.h>

#ifdef __cplusplus
extern "C"
{
#endif /*__cplusplus */

typedef struct reg16_avalon_interface_dev {
	alt_dev dev;
	unsigned int base;
	alt_u16 buffer;
}reg16_avalon_interface_dev;

//////////////////////////////////////////////////////////////////////////
// file-like operation functions
int reg16_avalon_interface_write_fd (alt_fd* fd, const char* ptr, int len);

//////////////////////////////////////////////////////////////////////////
// direct operation functions

/**
 * @brief Open the reg16 device according to device name 
 *
 * @param name -- the device name in SOPC Builder
 *
 * @return the \c reg16_dev device structure
 **/
//reg16_avalon_dev* reg16_avalon_open_dev(const char* name);

/*
 * Macros used by alt_sys_init 
 */
#define REG16_AVALON_INTERFACE_INSTANCE(name, device)	\
  static reg16_avalon_interface_dev device =		\
  {                                                 	\
    {                                               	\
      ALT_LLIST_ENTRY,                              	\
      name##_NAME,                                  	\
      NULL , /* open */									\
      NULL , /* close */								\
      NULL , /* read */					\
      reg16_avalon_interface_write_fd , /* write */				\
      NULL , /* lseek */								\
      NULL , /* fstat */								\
      NULL , /* ioctl */								\
    },                                              	\
    name##_BASE, 										\
	(alt_u16) 0,										\
  }

#define REG16_AVALON_INTERFACE_INIT(name, device)  \
  {															\
	/* make the device available to the system */			\
    alt_dev_reg(&device.dev);								\
  }



#ifdef __cplusplus
}
#endif /* __cplusplus */
	
#endif
