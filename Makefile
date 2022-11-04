ROOTDIR = ${PWD}/

CPP = clang
CPP_OPTIMIZE = -v -Oz -flto -Wl,--lto-O3
CPP_EXPORTS = -fvisibility=hidden -nostartfiles -Wl,--no-entry -Wl,--strip-all -Wl,--export-dynamic
CPP_FLAGS = --target=wasm32 -fno-exceptions -nostdlib -Wl,-z,stack-size=33554432

COMMONDIR = ${ROOTDIR}c/common
ENCDIR = ${ROOTDIR}c/enc
LIBCDIR = ${ROOTDIR}libc
SOURCE = ${ROOTDIR}pure/main.c $(wildcard $(LIBCDIR)/*.c) $(wildcard $(COMMONDIR)/*.c) $(wildcard $(ENCDIR)/*.c)
INCLUDE = -I${LIBCDIR} -I${ROOTDIR}c/include -I${ROOTDIR}pure
LIBC = --sysroot=${LIBCDIR}
OUTDIR = ${ROOTDIR}build/

all: build/main.wasm

build/main.wasm:
	mkdir -p build/
	$(CPP) $(CPP_OPTIMIZE) ${CPP_EXPORTS} $(CPP_FLAGS) $(LIBC) ${INCLUDE} -o ${OUTDIR}main.wasm ${SOURCE}
