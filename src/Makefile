CC=/usr/bin/gcc
AR=/usr/bin/ar
CP=/bin/cp
MKDIR=/bin/mkdir
RM=/bin/rm

CFLAGS=-g3 -Wall -lm

BUILD_DIR=../build


all: init accel.o
	${AR} -rsc ${BUILD_DIR}/libimu.a ${BUILD_DIR}/accel.o

accel.o:
ifeq ($(board),mma7660fc)
	${CC} ${CFLAGS} -c $(board)/$(board).c -D${board}_get=accel_get -o ${BUILD_DIR}/accel.o -I.
else
	@echo "*********************************************************************"
	@echo "* WARNING YOU HAVE TO SELECT AT LEAST ONE BOARD (board=mma7660fc)   *"
	@echo "*********************************************************************"
endif

init:
	${MKDIR} -p ${BUILD_DIR}

clean:
	${RM} ${BUILD_DIR}/*

