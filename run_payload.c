#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Uso: %s <binario> <payload.bin>\n", argv[0]);
        return 1;
    }
    FILE *f = fopen(argv[2], "rb");
    if (!f) { perror("fopen"); return 1; }
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *buf = malloc(sz + 1);
    fread(buf, 1, sz, f);
    fclose(f);
    buf[sz] = '\0';

    char *args[] = { argv[1], buf, NULL };
    execv(argv[1], args);
    perror("execv");
    return 1;
}
