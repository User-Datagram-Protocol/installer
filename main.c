#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("ERR: Not enough arguments\n");
        return -1;
    }
else {
    printf("installing: %s\n", argv[1]);
}
if (strcmp(argv[1], "spotify") == 0) {
    system("sudo apt install curl -y");
    system("curl -sS https://download.spotify.com/debian/pubkey_5384CE82BA52C83A.asc | sudo gpg --dearmor --yes -o /etc/apt/trusted.gpg.d/spotify.gpg");
    system("echo \"deb http://repository.spotify.com stable non-free\" | sudo tee /etc/apt/sources.list.d/spotify.list");
    system("sudo apt update && sudo apt install spotify-client -y");
}
    else if (strcmp(argv[1], "firefox") == 0) {
        system("sudo apt install firefox");
    }
    else if (strcmp(argv[1], "google_chrome") == 0) {
        system("wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb");
        system("sudo apt install ./google-chrome-stable_current_amd64.deb");
    }


    else {
    printf("program name invalid: %s\n", argv[1]);
}

    size_t len0 = strlen(argv[1]);
    if (len0 >= 4 &&
        argv[1][len0 - 4] == '.' &&
        argv[1][len0 - 3] == 'd' &&
        argv[1][len0 - 2] == 'e' &&
        argv[1][len0 - 1] == 'b') {
        char *buffer = malloc(
            strlen("sudo apt install ") +
            strlen(argv[1]) +
            1
            );
        if (buffer  == NULL) {
            return -1;
        }

        strcpy(buffer, "sudo apt install ");
        strcat(buffer, argv[1]);
        system(buffer);


        free(buffer);
    }

    size_t len1 = strlen(argv[1]);
    if (len >= 9 &&
        argv[1][len1 - 9] == '.' &&
        argv[1][len1 - 8] == 'A' &&
        argv[1][len1 - 7] == 'p' &&
        argv[1][len1 - 6] == 'p' &&
        argv[1][len1 - 5] == 'I' &&
        argv[1][len1 - 4] == 'm' &&
        argv[1][len1 - 3] == 'a' &&
        argv[1][len1 - 2] == 'g' &&
        argv[1][len1 - 1] == 'e') {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "sudo chmod +x %s", argv[1]);
        system(buffer);

    }


    size_t len2 = strlen(argv[1]);
    if (len >= 7 &&
        argv[1][len2 - 7] == '.' &&
        argv[1][len2 - 6] == 't' &&
        argv[1][len2 - 5] == 'a' &&
        argv[1][len2 - 4] == 'r' &&
        argv[1][len2 - 3] == '.' &&
        argv[1][len2 - 2] == 'g' &&
        argv[1][len2 - 1] == 'z') {

     FILE *fp = fopen("Makefile", "r");
     FILE *fp2 = fopen("configure", "r");

        if (fp != NULL) {
            printf("make file found\n");
            char buffer[256];
            snprintf(buffer, sizeof(buffer), "sudo make && sudo make install");
            system(buffer);
        }
        else if (fp2 != NULL) {
            printf("configure file found\n");
            char buffer[256];
            snprintf(buffer, sizeof(buffer), "sudo ./configure && sudo make && sudo make install");
            system(buffer);
        }
        else {
            printf("no make file or config file found");
            return -1;
        }
     if (fp != NULL) fclose(fp);
        if (fp2 != NULL) fclose(fp2);
        }
    return 0;
}