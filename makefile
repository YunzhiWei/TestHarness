
######################################################################
# config
include config

##########################################################################
# set compile variables

HOST_CC     = gcc
CROSS_      = arm-elf-
CROSS_CC    = $(CROSS_)gcc
CROSS_AS    = $(CROSS_)as
CROSS_LD    = $(CROSS_)ld
CROSS_NM    = $(CROSS_)nm
CROSS_OBJ   = $(CROSS_)objcopy
CROSS_DUMP  = $(CROSS_)objdump

FLAG_GCC    = -march=armv4 -O0 -fsigned-char
FLAG_INC    = -I./inc -I./common -I./BSP -I./MCU -I./Platform/$(PLATFORM_NAME) -I./Platform -I./Program

############FLAG-DEF-$(CONFIG_SUPPORT_NANDFLASH) += -DSDRAM_CONFIG=0x01000000


##########################################################################
# set directory variables

DIR_RUN     = /cygdrive/f
DIR_SRC     = ./Program
DIR_APP     = ./APP
DIR_OBJ     = ./_obj
DIR_OBJS    = ./_objs
DIR_LIB     = ./_lib
DIR_OUT     = ./_out
DIR_LST     = ./_lst
DIR_TMP     = ./_tmp

##########################################################################
# set output file variables

FILE_BIN    = $(DIR_OUT)/b
FILE_ELF    = $(DIR_TMP)/b.elf
FILE_LST    = $(DIR_TMP)/b.lst
FILE_MAP    = $(DIR_TMP)/b.map

FILE_APP    = $(DIR_OUT)/dummy.exe

##########################################################################
# set file variables

APP_BLDLST-y =
APP_BLDLST-$(CONFIG_BUILD_TESTFLASH) += $(DIR_APP)/TestFlash
APP_BLDLST-$(CONFIG_BUILD_TESTFS)    += $(DIR_APP)/TestFS
APP_BLDLST-$(CONFIG_BUILD_TESTSD)    += $(DIR_APP)/TestSD
APP_BLDLST-$(CONFIG_BUILD_TESTU2D)   += $(DIR_APP)/TestSSP
APP_BLDLST-$(CONFIG_BUILD_TESTSSP)   += $(DIR_APP)/TestU2D

LIB_GCC = \
          C:/Program\ Files/GNUARM/lib/gcc/arm-elf/4.1.1/libgcc.a \
          C:/Program\ Files/GNUARM/arm-elf/lib/libc.a

LIBRARY_y =   $(DIR_LIB)/BSP.a \
              $(DIR_LIB)/common.a \

OBJ_S = \
              $(DIR_OBJS)/start.o \
              $(DIR_OBJS)/ASMRoutines.o \

OBJ_Y = \
              $(DIR_OBJ)/startup.o \
              $(DIR_OBJ)/main.o \
              $(DIR_OBJ)/Event.o \
              $(DIR_OBJ)/FileSys.o \

LST_Y = \
              $(DIR_LST)/main.lst \

##########################################################################
# make option

bin :   $(FILE_BIN)

app :   $(FILE_APP)

lib :   $(LIBRARY_y)

lst :   $(LST_Y)

dbg :   $(FILE_MAP) $(FILE_LST)

all :   clr dir bin

dir :
	if [ ! -d $(DIR_OBJS) ]    ; then mkdir -p $(DIR_OBJS)   ; fi
	if [ ! -d $(DIR_OBJ) ]     ; then mkdir -p $(DIR_OBJ)    ; fi
	if [ ! -d $(DIR_LIB) ]     ; then mkdir -p $(DIR_LIB)    ; fi
	if [ ! -d $(DIR_OUT) ]     ; then mkdir -p $(DIR_OUT)    ; fi
	if [ ! -d $(DIR_LST) ]     ; then mkdir -p $(DIR_LST)    ; fi
	if [ ! -d $(DIR_TMP) ]     ; then mkdir -p $(DIR_TMP)    ; fi

clr :
	rm -f $(DIR_OBJS)/*
	rm -f $(DIR_OBJ)/*
	rm -f $(DIR_LIB)/*
	rm -f $(DIR_OUT)/*
	rm -f $(DIR_LST)/*
	rm -f $(DIR_TMP)/*

##########################################################################
# create option

$(FILE_BIN) : $(FILE_ELF)
	@echo convert to binary
	$(CROSS_OBJ) -O binary $(FILE_ELF) $(FILE_BIN)
	cp $(FILE_BIN) $(DIR_RUN)
	@echo success!!

$(FILE_ELF) : $(LIBRARY_y) $(OBJ_Y) $(OBJ_S)
	@echo link elf file...skip
	$(CROSS_CC) $(FLAG_GCC) -g -nostdlib -o $@ -Xlinker -T -Xlinker link.lds $(OBJ_S) $(OBJ_Y) $(LIBRARY_y) $(LIB_GCC)
	@echo link elf file finish

$(FILE_MAP) : $(FILE_ELF)
	$(CROSS_NM) $(FILE_ELF) | sort > $(FILE_MAP)

$(DIR_OBJS)/%.o : $(DIR_SRC)/%.s
	@echo assemble s file...
	$(CROSS_AS) $(FLAG_INC) -o $@ $<
	@echo compile c file finish

$(DIR_OBJ)/%.o : $(DIR_SRC)/%.c
	@echo compile c file...
	$(CROSS_CC) $(FLAG_GCC) $(FLAG_INC) $(FLAG-DEF-y) -c -g -o $@ $<
	@echo compile c file finish

$(DIR_LST)/%.lst : $(DIR_OBJ)/%.o
	@echo compile lst file...
	$(CROSS_DUMP) -D -S $< > $@
	@echo compile lst file finish

$(FILE_LST) : $(FILE_ELF)
	@echo compile lst file...
	$(CROSS_DUMP) -D -S -h -t $< > $@
	@echo compile lst file finish

$(DIR_LIB)/common.a :
	cd common; make

$(DIR_LIB)/BSP.a :
	cd BSP; make

$(DIR_OUT)/%.exe :
	for d in ${APP_BLDLST-y}; do ( cd $$d; make all); done

