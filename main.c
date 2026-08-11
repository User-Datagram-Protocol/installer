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

    size_t len = strlen(argv[1]);
    if (len >= 4 &&
        argv[1][len - 4] == '.' &&
        argv[1][len - 3] == 'd' &&
        argv[1][len - 2] == 'e' &&
        argv[1][len - 1] == 'b') {
        char *buffer = malloc(
            strlen("sudo apt install") +
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

    return 0;
}