CC=gcc
CFLAGS=-g
CFLAGS+=-Isrc/include

EXECUTABLE=dhanda
OBJ_PATH=.objs
SRC_PATH=src
SRCS=$(SRC_PATH)/dhanda.c $(SRC_PATH)/party_create.c $(SRC_PATH)/party_read.c $(SRC_PATH)/party_update.c $(SRC_PATH)/party_delete.c \
	 $(SRC_PATH)/txn_create.c $(SRC_PATH)/txn_read.c $(SRC_PATH)/txn_update.c $(SRC_PATH)/txn_delete.c \
	 $(SRC_PATH)/ui.c $(SRC_PATH)/list.c

dhanda:
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SRCS)
