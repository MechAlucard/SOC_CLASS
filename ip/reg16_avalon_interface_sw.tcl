# TCL File Generated by Altera University Program
# DO NOT MODIFY

# Create a new driver - this name must be different than the 
# hardware component name
create_driver reg16_avalon_interface_driver

# Associate it with some hardware
set_sw_property hw_class_name reg16_avalon_interface

# The version of this driver is "12.0"
set_sw_property version 1.0

# This driver is proclaimed to be compatible with 'component'
# as old as version "12.0". The component hardware version is set in the 
# _hw.tcl file - If the hardware component  version number is not equal 
# or greater than the min_compatable_hw_version number, the driver 
# source files will not be copied over to the BSP driver directory
set_sw_property min_compatible_hw_version 1.0

# Initialize the driver in alt_sys_init()
set_sw_property auto_initialize true

# Location in generated BSP that sources will be copied into
set_sw_property bsp_subdirectory drivers

#
# Source file listings...
#

# C/C++ source files
#add_sw_property c_source HAL/src/altera_up_avalon_rs232.c
add_sw_property c_source HAL/src/reg16_avalon_interface.c

# Include files
#add_sw_property include_source HAL/inc/altera_up_avalon_rs232.h
#add_sw_property include_source HAL/inc/altera_up_avalon_rs232_regs.h
add_sw_property include_source HAL/inc/reg16_avalon_interface.h
add_sw_property include_source HAL/inc/reg16_avalon_interface_regs.h
# This driver supports HAL type
add_sw_property supported_bsp_type HAL

# End of file

