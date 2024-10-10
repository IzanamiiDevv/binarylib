#include <stdio.h>
#include "../binarylib.h"

int main() {
    binaryWrite("test.exe", int, 10, sizeof(int));

    int x;
    binaryRead("test.exe", 0x0, &x, sizeof(int));
    
    printf("%i\n", x);

    int* y = (int*)binaryReadByValue("test.exe", 0x0, sizeof(int));
    printf("%i\n", *y);
    free(y);

    return 0;
}
