CC = gcc
CFLAGS = -I../include
OBJDIR = ../obj
BINDIR = ../bin
LIBDIR = ../lib

LIBOBJS = $(OBJDIR)/mystrfunctions.o $(OBJDIR)/myfilefunctions.o
STATICLIB = $(LIBDIR)/libmyutils.a
DYNAMICLIB = $(LIBDIR)/libmyutils.so
STATICTARGET = $(BINDIR)/client_static
DYNAMICTARGET = $(BINDIR)/client_dynamic

all: $(STATICTARGET) $(DYNAMICTARGET)

$(STATICTARGET): $(OBJDIR)/main.o $(STATICLIB)
	$(CC) $(OBJDIR)/main.o -L$(LIBDIR) -lmyutils -o $(STATICTARGET)

$(STATICLIB): $(LIBOBJS)
	ar rcs $(STATICLIB) $(LIBOBJS)

$(DYNAMICTARGET): $(OBJDIR)/main.o $(DYNAMICLIB)
	$(CC) $(OBJDIR)/main.o -L$(LIBDIR) -lmyutils -o $(DYNAMICTARGET)

$(DYNAMICLIB): mystrfunctions.c myfilefunctions.c
	$(CC) -fPIC -c mystrfunctions.c -o $(OBJDIR)/mystrfunctions.o $(CFLAGS)
	$(CC) -fPIC -c myfilefunctions.c -o $(OBJDIR)/myfilefunctions.o $(CFLAGS)
	$(CC) -shared -o $(DYNAMICLIB) $(OBJDIR)/mystrfunctions.o $(OBJDIR)/myfilefunctions.o

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJDIR)/*.o $(STATICTARGET) $(DYNAMICTARGET) $(STATICLIB) $(DYNAMICLIB)
install: $(STATICTARGET) $(DYNAMICTARGET)
	cp $(STATICTARGET) /usr/local/bin/client
	sudo mkdir -p /usr/local/share/man/man3
	cp ../man/man3/client.1 /usr/local/share/man/man3/
	mandb > /dev/null 2>&1
uninstall:
	rm -f /usr/local/bin/client
	rm -f /usr/local/share/man/man3/client.1
