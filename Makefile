CC=gcc
CFLAGS=-g
CFLAGS+=-Isrc/include

EXECUTABLE=dhanda
OBJ_PATH=.objs
SRC_PATH=src
SRCS=$(SRC_PATH)/dhanda.c $(SRC_PATH)/party.c $(SRC_PATH)/txn.c

dhanda:
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SRCS)
