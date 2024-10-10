#include <stdio.h>
#include "../binarylib.h"

int main() {
    binaryWrite("test.exe", int, 10, sizeof(int));
    
    return 0;
}