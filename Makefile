ROOTDIR = $(PWD)/

CPP = clang
CPP_SIMD = -m32 -msimd128 -mprefer-vector-width=128 -fvectorize -ftree-vectorize -fslp-vectorize -ftree-slp-vectorize -mbulk-memory
CPP_OPTIMIZE = -v -Oz -fno-signed-zeros -ffp-contract=fast -flto=thin -fwhole-program-vtables -ffast-math -funsafe-math-optimizations -menable-unsafe-fp-math -fno-honor-nans -fno-honor-infinities -fstrict-enums -foptimize-sibling-calls
CPP_EXPORTS = -fvisibility=hidden -nostartfiles -Wl,-O3 -Wl,--no-entry -Wl,--strip-debug -Wl,--merge-data-segments -Wl,--export-dynamic
CPP_FLAGS = --target=wasm32-unknown-unknown -g0 -mlittle-endian -fno-exceptions -fignore-exceptions -nostdlib --offload-new-driver -fnext-runtime -unwindlib=unwindlib
CPP_DEFINE = -DBROTLI_BUILD_32_BIT=1 -DBROTLI_BUILD_NO_RBIT=1 -DBROTLI_BUILD_NO_UNALIGNED_READ_FAST=1 -DBROTLI_BUILD_LITTLE_ENDIAN=1 -DBROTLI_HAVE_LOG2=1

COMMONDIR = $(ROOTDIR)c/common
ENCDIR = $(ROOTDIR)c/enc
DECDIR = $(ROOTDIR)c/dec
LIBCDIR = $(ROOTDIR)libc
SOURCE = $(ROOTDIR)pure/main.c $(wildcard $(LIBCDIR)/*.c) $(wildcard $(COMMONDIR)/*.c) $(wildcard $(DECDIR)/*.c) $(wildcard $(ENCDIR)/*.c)
INCLUDE = -I$(LIBCDIR) -I$(ROOTDIR)c/common -I$(ROOTDIR)c/enc -I$(ROOTDIR)c/include -I$(ROOTDIR)pure
LIBC = --sysroot=$(LIBCDIR)
OUTDIR = $(ROOTDIR)build/

all: build/main.wasm

build/main.wasm:
	mkdir -p build/
	$(CPP) $(CPP_OPTIMIZE) $(CPP_EXPORTS) $(CPP_DEFINE) $(CPP_FLAGS) $(CPP_SIMD) $(LIBC) $(INCLUDE) -o $(OUTDIR)main.wasm $(SOURCE)
