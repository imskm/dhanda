CC=gcc
CFLAGS+=-Isrc/include

EXECUTABLE=dhanda
OBJDIR=.objs
SRCDIR=src
SRCS:=$(shell find $(SRCDIR) -name '*.c')
OBJS:=$(SRCS:src/%=$(OBJDIR)/%.o)
HEADERS:=$(shell find $(SRCDIR) -name *.h)

# If built for PROD then remove debug flag and add optimize flag
ifdef PROD
	CFLAGS+=-O3
else
	CFLAGS+=-g
endif

$(EXECUTABLE): $(OBJDIR) $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJDIR):
	@mkdir $@

$(OBJDIR)/%.c.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJDIR)
