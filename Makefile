BOFNAME := WebcamBOF
CC_x64 := x86_64-w64-mingw32-gcc
CC_x86 := i686-w64-mingw32-gcc
STRIP_x64 := x86_64-w64-mingw32-strip --strip-unneeded
STRIP_x86 := i686-w64-mingw32-strip --strip-unneeded
CFLAGS := -I _include -w -Wno-int-conversion -Wno-incompatible-pointer-types -Os -DBOF -s -c
EXTRA_FLAGS := -fno-function-sections -fno-inline -fno-common -fno-data-sections

all: bof

bof: clean
	@mkdir -p _bin
	@($(CC_x64) $(CFLAGS) $(EXTRA_FLAGS) entry.c -o _bin/$(BOFNAME).x64.o && $(STRIP_x64) _bin/$(BOFNAME).x64.o) && echo '[+] $(BOFNAME) (x64)' || echo '[!] $(BOFNAME) (x64) FAILED'
	@($(CC_x86) $(CFLAGS) $(EXTRA_FLAGS) entry.c -o _bin/$(BOFNAME).x32.o && $(STRIP_x86) _bin/$(BOFNAME).x32.o) && echo '[+] $(BOFNAME) (x32)' || echo '[!] $(BOFNAME) (x32) FAILED'

clean:
	@rm -rf _bin
