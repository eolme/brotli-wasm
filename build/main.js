import * as brotli from './main.wasm?module';

/**
 * @param {number} pointer
 * @param {Uint8Array} buffer
 */
const store = (pointer, buffer) => {
  let bufferMemory = new Uint8Array(brotli.memory.buffer);
  for (let i = pointer, j = 0, length = buffer.byteLength; pointer < length; ++i, ++j) {
    bufferMemory[i] = buffer[j];
  }
  bufferMemory = null;
};

/**
 * @param {number} pointer
 * @param {number} size
 * @returns {Uint8Array}
 */
const load = (pointer, size) => {
  let bufferMemory = new Uint8Array(brotli.memory.buffer);
  const buffer = new Uint8Array(size);
  for (let i = pointer, j = 0; j < size; ++i, ++j) {
    buffer[j] = bufferMemory[i];
  }
  bufferMemory = null;
  return buffer;
};

/**
 * @param {Uint8Array} buffer
 * @returns {number} size
 */
export const compress = (buffer) => {
  const pointer = brotli.alloc(buffer.byteLength);
  store(pointer, buffer);
  return brotli.compress(pointer, buffer.byteLength);
};

/**
 * @param {number} size
 * @returns {Uint8Array} compressed
 */
export const output = (size) => {
  return load(brotli.offset(), size);
};
