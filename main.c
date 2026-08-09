#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc < 2)
    {
        printf("ERR: Not enough arguments\n");
    }
else {
    printf("installing: %s\n", argv[1]);
}

    if (strcmp(argv[1], "firefox") == 0) {
        system("sudo apt install firefox");
    }
else {
    printf("program name invalid: %s\n", argv[1]);
}


    return 0;
}