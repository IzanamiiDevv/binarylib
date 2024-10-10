#pragma once
#include <stdio.h>
#include <stdlib.h>

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

void binaryWriteRef(const char* _Filename, const void* _Buffer, size_t _ElementSize) {
    FILE* fstream = fopen(_Filename, "wb");
    if(fstream == NULL) {
        printf("Error: Can't connect to the file: %s\n", _Filename);
        exit(EXIT_FAILURE);
    }
    fwrite(_Buffer, _ElementSize, 1, fstream);
    fclose(fstream);
}

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

void binaryAppendRef(const char* _Filename, const void* _Buffer, size_t _ElementSize) {
    FILE* fstream = fopen(_Filename, "ab");
    if(fstream == NULL) {
        printf("Error: Can't connect to the file: %s\n", _Filename);
        exit(EXIT_FAILURE);
    }
    fwrite(_Buffer, _ElementSize, 1, fstream);
    fclose(fstream);
}

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