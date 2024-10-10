#include <stdio.h>
#include "../binarylib.h"

int main() {
    binaryWrite("test.exe", int, 10, sizeof(int));

    int x;
    binaryRead("test.exe", 0, &x, sizeof(int));
    
    printf("%i\n", x);

    return 0;
}
