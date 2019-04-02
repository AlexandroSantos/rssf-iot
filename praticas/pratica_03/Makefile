TARGET = srf06-cc26xx
BOARD = launchpad/cc1350

#all: udp-server udp-client udp-server-atividade4
all: cliente-udp servidor-udp
#all: udp-server-RSSI-LQI udp-client-RSSI-LQI

CFLAGS += -DPROJECT_CONF_H=\"project-conf.h\"
CONTIKI = ../../contiki
CONTIKI_WITH_IPV6 = 1
CFLAGS += -DUIP_CONF_ND6_SEND_NS=1
CFLAGS += -g
DEBUG = 1
#APPS += powertrace
PROJECT_SOURCEFILES += protocol.c cetic-6lbr-client.c 

include $(CONTIKI)/Makefile.include

# Force Contiki to USE CCS's compiler instead of system compiler
# You may need to adjust CC_PREFIX to point to CCS compiler binaries folder

CC_PREFIX = /opt/ti/ccsv7/tools/compiler/gcc-arm-none-eabi-4_9-2015q3/bin
#CC_PREFIX = /opt/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/bin
#CC_PREFIX = /opt/ti/ccsv9/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/bin
CC      = $(CC_PREFIX)/arm-none-eabi-gcc
CPP     = $(CC_PREFIX)/arm-none-eabi-cpp
LD      = $(CC_PREFIX)/arm-none-eabi-gcc
AR      = $(CC_PREFIX)/arm-none-eabi-ar
OBJCOPY = $(CC_PREFIX)/arm-none-eabi-objcopy
OBJDUMP = $(CC_PREFIX)/arm-none-eabi-objdump
NM      = $(CC_PREFIX)/arm-none-eabi-nm
SIZE    = $(CC_PREFIX)/arm-none-eabi-size