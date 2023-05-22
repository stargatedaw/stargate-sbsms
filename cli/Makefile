#!/usr/bin/make -f

CXX     ?= c++
DESTDIR ?=
PREFIX  ?= /usr

INCLUDE_FLAGS ?= -Isrc -I../include -I../src
EXTRA_FLAGS ?=
# Default flags are x86 specific
PLAT_FLAGS  ?= -msse -msse2 -msse3 -mfpmath=sse -DENABLE_SSE=1
CFLAGS      ?= -ffast-math  -Wall -Wno-enum-compare
OPT_FLAGS   ?= -O3
LINK_CFLAGS ?= -lpthread -lm \
	$(shell pkg-config --libs sndfile 2>/dev/null || echo -lsndfile)

# --------------------------------------------------------------

all: sbsms

debug: clean
	OPT_FLAGS="-O0 -g" make

sbsms: clean
	$(CXX) $(INCLUDE_FLAGS) $(EXTRA_FLAGS) \
		$(OPT_FLAGS) $(CFLAGS) $(PLAT_FLAGS) \
		src/*.cpp ../src/*.cpp \
		$(LINK_CFLAGS) -o $@

macos_arm:
	PLAT_FLAGS= EXTRA_FLAGS='-I/opt/homebrew/include' make

install:
	install -d $(DESTDIR)$(PREFIX)/bin
	install -m 755 sbsms $(DESTDIR)$(PREFIX)/bin

clean:
	rm -f src/*.o sbsms

