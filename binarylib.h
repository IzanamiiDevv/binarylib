#pragma once
#include <stdio.h>
#include <stdlib.h>

#define binaryWrite(_Filename, _Type, _Buffer, _ElementSize) { \
    if(sizeof(_Filename) != sizeof(const char*) \
    || sizeof(_ElementSize) != sizeof(size_t)) return; \
    FILE* fstream = fopen((_Filename), "ab");\
    if(fstream == NULL) {printf("Error: Cant connect to the File."); return;}\
    (_Type) databuff = (_Buffer); \
    fwrite(&(databuff), (_ElementSize), 1, (fstream)); \
}

void binaryWriteRef(const char* _Filename, const void* _Buffer, size_t _ElementSize){
    FILE* fstream = fopen(_Filename, "ab");
    if(fstream == NULL) {
        printf("Error: Cant connect to the File.");
        return;
    }

    fwrite(_Buffer, _ElementSize, 1, fstream);
    fclose(fstream);
}

void binaryRead(const char* _FileName, unsigned long _Address , void* _Location, size_t _ElementSize){
    
}