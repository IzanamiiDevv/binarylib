#pragma once
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Writes a buffer to a binary file.
 * 
 * This function opens/creates a file in binary, writes the contents of the buffer, 
 * and then closes the file. If the file cannot be opened, the program will exit with an error.
 * 
 * @param _Filename The name of the file to write to.
 * @param _Type The data type of the buffer being written.
 * @param _Buffer The buffer to write to the file.
 * @param _ElementSize The size of each element in the buffer.
 */
#define binaryWrite(_Filename, _Type, _Buffer, _ElementSize) { \
    FILE* fstream = fopen((_Filename), "wb"); \
    if(fstream == NULL) { \
        printf("Error: Can't connect to the file: %s\n", _Filename); \
        exit(EXIT_FAILURE); \
    } \
    _Type databuff = (_Type)(_Buffer); \
    fwrite(&(databuff), (_ElementSize), 1, (fstream)); \
    fclose(fstream); \
}

/**
 * @brief function pass a value by refference to write a buffer to a binary file.
 * 
 * This function can passed a refference of the data and opens/creates a file,
 * writes the buffer contents to it, and closes the file.
 * If the file cannot be opened, the program will exit with an error.
 * 
 * @param _Filename The name of the file to write to.
 * @param _Buffer The buffer to write to the file.
 * @param _ElementSize The size of each element in the buffer.
 */
void binaryWriteRef(const char* _Filename, const void* _Buffer, size_t _ElementSize) {
    FILE* fstream = fopen(_Filename, "wb");
    if(fstream == NULL) {
        printf("Error: Can't connect to the file: %s\n", _Filename);
        exit(EXIT_FAILURE);
    }
    fwrite(_Buffer, _ElementSize, 1, fstream);
    fclose(fstream);
}

/**
 * @brief Appends a buffer to a binary file.
 * 
 * This function opens/creates a file in binary, append the contents of the buffer, 
 * and then closes the file. If the file cannot be opened, the program will exit with an error.
 * 
 * @param _Filename The name of the file to append to.
 * @param _Type The data type of the buffer being appended.
 * @param _Buffer The buffer to append to the file.
 * @param _ElementSize The size of each element in the buffer.
 */
#define binaryAppend(_Filename, _Type, _Buffer, _ElementSize) { \
    FILE* fstream = fopen((_Filename), "ab"); \
    if(fstream == NULL) { \
        printf("Error: Can't connect to the file: %s\n", _Filename); \
        exit(EXIT_FAILURE); \
    } \
    _Type databuff = (_Type)(_Buffer); \
    fwrite(&(databuff), (_ElementSize), 1, (fstream)); \
    fclose(fstream); \
}

/**
 * @brief function to pass a refferenced value and append a buffer to a binary file.
 * 
 * This function opens a file, appends the reffereced value buffer contents to it, and closes the file.
 * If the file cannot be opened, the program will exit with an error.
 * 
 * @param _Filename The name of the file to append to.
 * @param _Buffer The buffer to append to the file.
 * @param _ElementSize The size of each element in the buffer.
 */
void binaryAppendRef(const char* _Filename, const void* _Buffer, size_t _ElementSize) {
    FILE* fstream = fopen(_Filename, "ab");
    if(fstream == NULL) {
        printf("Error: Can't connect to the file: %s\n", _Filename);
        exit(EXIT_FAILURE);
    }
    fwrite(_Buffer, _ElementSize, 1, fstream);
    fclose(fstream);
}

/**
 * @brief Reads data from a binary file at a specific address into a buffer.
 * 
 * This function opens a file, reads data from a specified address into the provided buffer, 
 * and closes the file. If the file cannot be opened or the read fails, the program will exit with an error.
 * 
 * @param _FileName The name of the file to read from.
 * @param _Address The address in the file to start reading from.
 * @param _Location The buffer where the read data will be stored.
 * @param _ElementSize The size of the data to read.
 */
void binaryRead(const char* _FileName, unsigned long _Address, void* _Location, size_t _ElementSize) {
    FILE* fstream = fopen(_FileName, "rb");
    if(fstream == NULL) {
        printf("Error: Can't connect to the file: %s\n", _FileName);
        exit(EXIT_FAILURE);
    }
    fseek(fstream, _Address, SEEK_SET);
    fread(_Location, _ElementSize, 1, fstream);
    fclose(fstream);
}

/**
 * @brief Reads data from a binary file and returns it by value.
 * 
 * This function opens a file, reads data from a specified address, allocates memory to store 
 * the data, and returns a pointer to the allocated memory. If the file cannot be opened or the 
 * memory allocation fails, the program will exit with an error.
 * 
 * @param _FileName The name of the file to read from.
 * @param _Address The address in the file to start reading from.
 * @param _ElementSize The size of the data to read.
 * @return A pointer to the allocated buffer containing the read data.
 */
void* binaryReadByValue(const char* _FileName, unsigned long _Address, size_t _ElementSize) {
    FILE* fstream = fopen(_FileName, "rb");
    if(fstream == NULL) {
        printf("Error: Can't connect to the file: %s\n", _FileName);
        exit(EXIT_FAILURE);
    }

    void* buff = malloc(_ElementSize);
    if (buff == NULL) {
        printf("Error: Memory allocation failed.\n");
        fclose(fstream);
        exit(EXIT_FAILURE);
    }

    fseek(fstream, _Address, SEEK_SET);
    size_t readCount = fread(buff, _ElementSize, 1, fstream);
    if (readCount != 1) {
        printf("Error: Failed to read data from file.\n");
        free(buff);
        fclose(fstream);
        exit(EXIT_FAILURE);
    }
    fclose(fstream);
    return buff;
}