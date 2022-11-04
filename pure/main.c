#define WASM __attribute__((visibility("default")))
#define BROTLI_BUILD_32_BIT
#include "brotli/encode.h"

WASM uint8_t *compress(size_t input_size, const uint8_t *input_buffer,
                       size_t *encoded_size, uint8_t *encoded_buffer) {
  if (BrotliEncoderCompress(6, 16, 1, input_size, input_buffer, encoded_size,
                            encoded_buffer)) {
    return encoded_buffer;
  }

  return 0;
}

int main() { return 0; }
