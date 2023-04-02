#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binary(int num) {
    int result[32], i = 0;
    int mask = 1;
    while (num > 0) {
        if (num & mask) {
            result[i] = mask;
            i++;
            num -= mask;
        }
        mask <<= 1;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d ", result[j]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    char *file_name = NULL;
    FILE *fp;

    if (argc > 2 && strcmp(argv[1], "-f") == 0) {
        file_name = argv[2];
        fp = fopen(file_name, "r");
        if (fp == NULL) {
            perror("Error: Could not open file");
            exit(EXIT_FAILURE);
        }
    } else {
        fp = stdin;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        line[strcspn(line, "\n")] = 0; // remove newline character
        char *endptr;
        long num = strtol(line, &endptr, 10);
        if (*endptr == '\0') {
            binary(num);
        } else {
            fprintf(stderr, "Warning: %s is not a number\n", line);
        }
    }

    if (file_name) {
        fclose(fp);
    }

    return 0;
}

