
include sources.mk

EXE = project4

#Defining Flags common to all architectures.

CFLAGS = -O0 -Wall -g -std=c99 -I $(HDRPATH) -DBBB -DPROFILING -DDEBUG
DEPFLAGS = -M ./dep/$@.dep
LDFLAGS= -Wl,-Map=$@.map 
LINKFLAG = -Xlinker 

#Defining variables for converting .c files into object files and other assembly and linker files. 
OBJECT:= ${SOURCE:.c=.o}
PREPROCESS:= ${SOURCE:.c=.i}
ASM:= ${SOURCE:.c=.s}
DEP:= ${SOURCE:.c=.dep}
LNKOBJ:=$(LINK:.c=.o)

#Defining Platforms for compiling: whether BBB or FRDM or Host machine.
ifeq ($(ARCH), bbb)
	CC = arm-linux-gnueabihf-gcc
	CFLAGS += -march=armv7-a -mtune=cortex-a8 -mfpu=neon
	AR = arm-linux-gnueabi-ar
else 
	CC = gcc 
	AR = ar
endif


#Creating assembly, object and dependency files. 
%.dep: %.c
	$(CC) -I $(HDRPATH) -M $< -o $@

%.i : %.c 
	$(CC) -I $(HDRPATH) -E $< -o $@

#phony protection for all targets
.PHONY : asm
asm:
	make $(ASM)

%.S :  %.c
	$(CC) $(CFLAGS) -I $(HDRPATH) -S $< -o $@

%.o : %.c
	$(CC) $(CFLAGS) -I $(HDRPATH) -c $<


#Target for compiling all object files.
.PHONY : compile-all
compile-all : $(SOURCE)
	$(CC) $(CFLAGS) $(LDFLAGS) -c $^

#Target for creating all object files, .dep files and displaying size of executable files.
.PHONY : build
build : $(OBJECT)
	$(CC) $(CFLAGS) $(LDFLAGS) -o  $(EXE)  $^
	$(CC) $(CFLAGS) $(LDFLAGS) $^ --output $(EXE).map
	make $(DEP)
	size -B $(EXE)

.PHONY : Preprocess
Preprocess: $(SOURCE)
	make $(PREPROCESS)

.PHONY : assembly
assembly : $(ASM)	

#Target for transferring executable to the BBB.
.PHONY : upload
upload :
    scp $(EXE) root@192.168.7.2:/home/debian/bin

#Cleaning all files.
.PHONY : clean
clean :
	-rm -f $(EXE) $(OBJECT) $(PREPROCESS) $(ASM) $(DEP) $(EXE).map *.a *.map

#Objectdump
.PHONY : OBJDUMP
OBJDUMP:$(SOURCE)
	make clean
	$(CC) $(CFLAGS) -c $^
	objdump -s $(OBJECT)

#Creating library files of the executable.
.PHONY : build_lib
build_lib: $(LNKOBJ)
	$(AR) cr libproject1.a $^
	ranlib libproject1.a

.PHONY : link_lib
link_lib: $(OBJECT)
	$(AR) cr libproject2.a $^
	ranlib libproject2.a
	ld -o $(EXE).out libproject2.a -lc --architecture =$(AR) --entry=main
