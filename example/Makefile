CC = gcc
CFLAGS = -std=c99 -I SLACKer

SRCS = example.c SLACKer/slacker_runtime.c
OBJS = $(SRCS:.c=.o)
TARGET = example

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)