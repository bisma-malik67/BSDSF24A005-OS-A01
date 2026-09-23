CC = gcc
CFLAGS = -I../include
OBJDIR = ../obj
BINDIR = ../bin
LIBDIR = ../lib

LIBOBJS = $(OBJDIR)/mystrfunctions.o $(OBJDIR)/myfilefunctions.o
LIBTARGET = $(LIBDIR)/libmyutils.a
TARGET = $(BINDIR)/client_static

all: $(TARGET)

$(TARGET): $(OBJDIR)/main.o $(LIBTARGET)
	$(CC) $(OBJDIR)/main.o -L$(LIBDIR) -lmyutils -o $(TARGET)

$(LIBTARGET): $(LIBOBJS)
	ar rcs $(LIBTARGET) $(LIBOBJS)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJDIR)/*.o $(TARGET) $(LIBTARGET)
