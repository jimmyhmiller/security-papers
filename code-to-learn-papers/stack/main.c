#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void secret() {
   puts("Access Granted!");
}

void try_secret(char* input, int size) {
    char buff[16] = {0};
    // printf("\n%p\n", (void*)buff);
    // printf("\n%p\n", (void*)secret);
    memcpy(buff, input, size);
    if (strcmp(buff, "secret") == 0) {
        secret();
    }
}

 
char* read_file(char* filename, int size) {
    FILE *f = fopen(filename, "rb");

    char *string = malloc(size + 1);
    fread(string, size, 1, f);
    fclose(f);
    string[size] = 0;
    return string;
}


int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Arguments: <buffer input>\n");
        return 1;
    }
    // I should make some if statement
    // But get to the secret anyway
   char *p;
   int size = strtol(argv[2], &p, 10);
   try_secret(read_file(argv[1], size), size);
 
    printf("Exiting...\n");
    return 0;
}
