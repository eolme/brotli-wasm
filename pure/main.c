#include "brotli/encode.h"

#define WASM __attribute__((visibility("default")))

static uint8_t* static_offset = 0;

WASM const uint8_t* offset() { return static_offset; }

WASM const uint8_t* alloc(const size_t input_size) {
  return malloc(input_size);
}

WASM const size_t compress(const uint8_t* input_buffer,
                           const size_t input_size) {
  static_offset = 0;

  size_t encoded_size = BrotliEncoderMaxCompressedSize(input_size);

  if (encoded_size == 0) {
    return 0;
  }

  uint8_t* encoded_buffer = malloc(encoded_size * sizeof(uint8_t));

  if (encoded_buffer == 0) {
    return 0;
  }

  if (BrotliEncoderCompress(BROTLI_MAX_QUALITY, BROTLI_DEFAULT_WINDOW,
                            BROTLI_MODE_TEXT, input_size, input_buffer,
                            &encoded_size, encoded_buffer)) {
    static_offset = encoded_buffer;

    return encoded_size;
  }
}

int main() { return 0; }
