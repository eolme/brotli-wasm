# brotli-compress-wasm

> The smallest brotli compression module for the edge.

- pure clang is used instead of emcc
- own [libc](https://github.com/eolme/brotli-wasm/libc/) with [walloc](https://github.com/wingo/walloc) for memory management

## Usage

> Note: Only synchronous processing in a single thread and in a single iteration is supported

```js
import * as brotli from 'brotli-compress-wasm';

// size of compressed buffer
const size = brotli.compress(buffer);

// ...to take output as Uint8Array
const result = brotli.output(size);
```

## Installation

Recommend to use [yarn](https://yarnpkg.com/) for dependency management:

```shell
yarn add brotli-compress-wasm
```

## License

brotli-compress-wasm is [MIT licensed](https://github.com/eolme/brotli-wasm/build/LICENSE).
