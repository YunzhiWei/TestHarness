######################################################################
# config
include ../config

######################################################################
# project directorys and target files

DIR_OBJ     =../_obj
DIR_LIB     =../_lib

FILE_LIB    =$(DIR_LIB)/common.a

######################################################################
# make tools and make config

CROSS_      =arm-elf-
CROSS_CC    =$(CROSS_)gcc
CROSS_AR    =$(CROSS_)ar

FLAG_GCC    = -march=armv4 -O2 
FLAG_INC    = -I../inc -I../common -I../BSP -I../MCU -I../Platform/$(PLATFORM_NAME) -I../Platform -I../Program 

######################################################################
# object

OBJECTS     =   \
              $(DIR_OBJ)/MMU.o \
              $(DIR_OBJ)/public.o \
              $(DIR_OBJ)/crc1021.o \
              $(DIR_OBJ)/xmodem.o \
              $(DIR_OBJ)/StreamOut.o \
              $(DIR_OBJ)/debug.o \
              $(DIR_OBJ)/menu.o \
              $(DIR_OBJ)/RAMDisk.o \
              $(DIR_OBJ)/FAT.o \
              $(DIR_OBJ)/FBFunction.o \
              $(DIR_OBJ)/Console.o \
              $(DIR_OBJ)/FIFO.o \

######################################################################
# make option

lib : $(FILE_LIB)

######################################################################
# create method

$(FILE_LIB) : $(OBJECTS)
	$(CROSS_AR) -rcs $@ $^
	
$(DIR_OBJ)/%.o: %.c
	$(CROSS_CC) $(FLAG_GCC) $(FLAG_INC) -c -g -o $@ $<
