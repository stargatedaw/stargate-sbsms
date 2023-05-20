#!/usr/bin/make -f

CXX     ?= c++
DESTDIR ?=
PREFIX  ?= /usr

# Default flags are x86 specific
PLAT_FLAGS  ?= -msse -msse2 -msse3 -mfpmath=sse -DENABLE_SSE=1
CFLAGS      ?= -ffast-math  -Wall
OPT_FLAGS   ?= -O3
LINK_CFLAGS ?= -lpthread $(shell pkg-config --libs sndfile) -lm

# --------------------------------------------------------------

all: sbsms

sbsms:
	$(CXX) -Isrc -I../include -I../src \
		$(OPT_FLAGS) $(CFLAGS) $(PLAT_FLAGS) \
		src/*.cpp ../src/*.cpp \
		$(LINK_CFLAGS) -o $@

macos_arm:
	PLAT_FLAGS= CFLAGS+='-I/opt/homebrew/include' make

install:
	install -d $(DESTDIR)$(PREFIX)/bin
	install -m 755 sbsms $(DESTDIR)$(PREFIX)/bin

clean:
	rm -f src/*.o sbsms

