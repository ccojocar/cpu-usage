CC=gcc
CFLAGS=-O2 -Wall
LDFLAGS=
SRCDIR=.
SRC=$(foreach dir,$(SRCDIR),$(wildcard $(dir)/*.c))
OBJS=$(SRC:.c=.o)
BIN=cpu_usage

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@
%.o: %.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm -rf $(BIN) *.o

