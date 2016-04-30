######################################################################
# config
include ../config

######################################################################
# project directorys and target files

DIR_OBJ     =../_obj
DIR_LIB     =../_lib

FILE_LIB    =$(DIR_LIB)/BSP.a

######################################################################
# make tools and make config

CROSS_      =arm-elf-
CROSS_CC    =$(CROSS_)gcc
CROSS_AR    =$(CROSS_)ar

FLAG_GCC    = -march=armv4 -O0 
FLAG_INC    = -I../inc -I../common -I../BSP -I../MCU -I../Platform/$(PLATFORM_NAME) -I../Platform -I../Program 

######################################################################
# object

OBJECTS     =   \
              $(DIR_OBJ)/PIN.o \
              $(DIR_OBJ)/GPIO.o \
              $(DIR_OBJ)/PWRMode.o \
              $(DIR_OBJ)/Freq.o \
              $(DIR_OBJ)/Clock.o \
              $(DIR_OBJ)/Timer.o \
              $(DIR_OBJ)/RTC.o \
              $(DIR_OBJ)/Interrupt.o \
              $(DIR_OBJ)/PWM.o \
              $(DIR_OBJ)/SSP.o \
              $(DIR_OBJ)/UART.o \
              $(DIR_OBJ)/NTIM.o \
              $(DIR_OBJ)/NAND.o \
              $(DIR_OBJ)/BadBlockManager.o \
              $(DIR_OBJ)/FAL.o \
              $(DIR_OBJ)/Flash.o \
              $(DIR_OBJ)/Update.o \
              $(DIR_OBJ)/MMCSD.o \
              $(DIR_OBJ)/UDC.o \
              $(DIR_OBJ)/U2D.o \
              $(DIR_OBJ)/USBDisk.o \
              $(DIR_OBJ)/USBMSSync.o \
              $(DIR_OBJ)/USBSerial.o \
              $(DIR_OBJ)/USBComposite.o \
              $(DIR_OBJ)/Keypad.o \
              $(DIR_OBJ)/LCD.o \
              $(DIR_OBJ)/Panel.o \
              $(DIR_OBJ)/I2C.o \
              $(DIR_OBJ)/PMIC.o \
              $(DIR_OBJ)/Touch.o \
              $(DIR_OBJ)/QCI.o \
              $(DIR_OBJ)/Camera.o \
              $(DIR_OBJ)/Audio.o \
              $(DIR_OBJ)/DMA.o \

######################################################################
# make option

lib : $(FILE_LIB)

######################################################################
# create method

$(FILE_LIB) : $(OBJECTS)
	$(CROSS_AR) -rcs $@ $^

$(DIR_OBJ)/%.o: %.c
	$(CROSS_CC) $(FLAG_GCC) $(FLAG_INC) -c -g -o $@ $<
