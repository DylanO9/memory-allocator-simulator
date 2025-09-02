# memory-allocator-simulator

A custom implementation of `malloc`, `free`, `calloc` and `realloc`
to understand heap management and memory allocation strategies.

## Features
- Simulates heap with metadata headers
- First-fit allocation strategy
- Block splitting and coalescing
- Heap visualizer (`print_heap`)

## Project Structure
- `src/` - allocator implementation
- `tests/` - unit and stress tests
- `examples/` - example programs
- `docs/` - design and usage notes

## Build & Run
```bash
make
./allocator
