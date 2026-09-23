CC = gcc
CFLAGS = -I../include
OBJDIR = ../obj
BINDIR = ../bin
SRCS = main.c mystrfunctions.c myfilefunctions.c
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
TARGET = $(BINDIR)/client

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)
