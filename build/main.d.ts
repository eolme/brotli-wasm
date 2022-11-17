/**
 * @param {Uint8Array} buffer
 * @returns {number} size
 */
export const compress: (buffer: Uint8Array) => number;

/**
 * @param {number} size
 * @returns {Uint8Array} compressed
 */
export const output: (size: number) => Uint8Array;
