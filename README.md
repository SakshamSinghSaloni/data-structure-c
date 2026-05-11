# Data Structures in C

Collection of classic data structure implementations in C.

## Implemented Structures

- Singly Linked List

## Features

### Linked List
- Sentinel node design
- Tail pointer optimization
- Encapsulated API
- Dynamic memory management
- Callback-based traversal

## Project Structure

```text
data-structures-c/
├── include/
│   └── list.h
├── src/
│   └── list.c
├── examples/
│   └── main.c
└── README.md
```

## Build

```bash
gcc src/list.c examples/main.c -o main
```

## Run

### Linux/macOS/Git Bash

```bash
./main
```

### Windows CMD

```bash
main.exe
```

## Time Complexities

| Operation      | Complexity |
|----------------|------------|
| push_front     | O(1)       |
| push_back      | O(1)       |
| pop_front      | O(1)       |
| pop_back       | O(n)       |
| insert         | O(n)       |
| remove         | O(n)       |
| find           | O(n)       |

## Future Additions

- Red-Black Tree
- Stack
- Queue
- Hash Table