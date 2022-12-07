import * as wasm from './main.wasm?module';

/**
 * @typedef {object} Brotli
 * @property {WebAssembly.Memory} memory
 * @property {(size: number) => number} alloc
 * @property {() => number} offset
 * @property {(pointer: number, size: number) => number} compress
 */

/**
 * @type {Brotli}
 */
const brotli = (new WebAssembly.Instance(wasm.default, {})).exports;

const memory = new DataView(brotli.memory.buffer);

/**
 * @param {number} pointer
 * @param {Uint8Array} buffer
 */
const store = (pointer, buffer) => {
  for (let i = pointer, j = 0, size = buffer.byteLength; j < size; ++i, ++j) {
    memory.setUint8(i, buffer[j]);
  }
};

/**
 * @param {number} pointer
 * @param {number} size
 * @returns {Uint8Array}
 */
const load = (pointer, size) => {
  const buffer = new Uint8Array(size);
  for (let i = pointer, j = 0; j < size; ++i, ++j) {
    buffer[j] = memory.getUint8(i);
  }
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
