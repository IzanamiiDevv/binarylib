# binarylib.h

`binarylib.h` is a C library designed to simplify operations on binary files, including writing, appending, and reading binary data. The library provides a set of macros and functions to handle various file I/O tasks with minimal code.

## Features

- **Writing Binary Files**: Easily write buffers of data to binary files.
- **Appending to Binary Files**: Append data to existing binary files.
- **Reading Binary Files**: Read binary data from files using specific addresses or return data by value.
- **Macros for convenience**: Includes macros to streamline file I/O operations.

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/binarylib.git
   ```
2. Include the header file in your project:
   ```c
   #include "binarylib.h"
   ```

3. You can install it by downloading the repository.

## Usage

### Writing to a Binary File
```c
binaryWrite("data.bin", int, 42, sizeof(int));
```
This writes the integer `42` to `data.bin`.

Alternatively, use the function version:
```c
int value = 42;
binaryWriteRef("data.bin", &value, sizeof(int));
```

### Appending to a Binary File
```c
binaryAppend("data.bin", int, 100, sizeof(int));
```
This appends the integer `100` to `data.bin`.

Alternatively, use the function version:
```c
int value = 100;
binaryAppendRef("data.bin", &value, sizeof(int));
```

### Reading from a Binary File by Address
```c
int data;
binaryRead("data.bin", 0, &data, sizeof(int));
printf("Data: %d\n", data);
```

### Reading from a Binary File by Value
```c
int* data = (int*)binaryReadByValue("data.bin", 0, sizeof(int));
printf("Data: %d\n", *data);
free(data); // Don't forget to free the allocated memory
```

## Functions and Macros

### Writing Data

- `binaryWrite(_Filename, _Type, _Buffer, _ElementSize)`
- `void binaryWriteRef(const char* _Filename, const void* _Buffer, size_t _ElementSize)`

### Appending Data

- `binaryAppend(_Filename, _Type, _Buffer, _ElementSize)`
- `void binaryAppendRef(const char* _Filename, const void* _Buffer, size_t _ElementSize)`

### Reading Data

- `void binaryRead(const char* _FileName, unsigned long _Address, void* _Location, size_t _ElementSize)`
- `void* binaryReadByValue(const char* _FileName, unsigned long _Address, size_t _ElementSize)`

## Error Handling

The library provides basic error handling for file operations and memory allocation. If an operation fails, the program will print an error message and terminate with `EXIT_FAILURE`.

## License

[MIT License](LICENSE)

## Contributions

Feel free to contribute to this project by opening issues or submitting pull requests.