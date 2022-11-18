ROOTDIR = ${PWD}/

CPP = clang
CPP_OPTIMIZE = -v -Oz -flto=full -Wl,--lto-O3 -fvirtual-function-elimination -fwhole-program-vtables -ffast-math -funsafe-math-optimizations
CPP_EXPORTS = -fvisibility=hidden -nostartfiles -Wl,--no-entry -Wl,--strip-all -Wl,--export-dynamic
CPP_FLAGS = --target=wasm32-unknown-unknown -fno-exceptions -nostdlib -m32
CPP_DEFINE = -DBROTLI_BUILD_32_BIT=1 -DBROTLI_BUILD_NO_RBIT=1 -DBROTLI_BUILD_NO_UNALIGNED_READ_FAST=1 -DBROTLI_BUILD_LITTLE_ENDIAN=1 -DBROTLI_HAVE_LOG2=1

COMMONDIR = ${ROOTDIR}c/common
ENCDIR = ${ROOTDIR}c/enc
DECDIR = ${ROOTDIR}c/dec
LIBCDIR = ${ROOTDIR}libc
SOURCE = ${ROOTDIR}pure/main.c $(wildcard $(LIBCDIR)/*.c) $(wildcard $(COMMONDIR)/*.c) $(wildcard $(DECDIR)/*.c) $(wildcard $(ENCDIR)/*.c)
INCLUDE = -I${LIBCDIR} -I${ROOTDIR}c/common -I${ROOTDIR}c/enc -I${ROOTDIR}c/include -I${ROOTDIR}pure
LIBC = --sysroot=${LIBCDIR}
OUTDIR = ${ROOTDIR}build/

all: build/main.wasm

build/main.wasm:
	mkdir -p build/
	$(CPP) $(CPP_OPTIMIZE) ${CPP_EXPORTS} $(CPP_DEFINE) $(CPP_FLAGS) $(LIBC) ${INCLUDE} -o ${OUTDIR}main.wasm ${SOURCE}
