#include <stdio.h>
#include <string.h>

void substituir(char *str) {
    if (*str == '\0') {
        return;
    }
    if (*str == 'x') {
        *str = 'y';
    }
    substituir(str + 1);
}

int main() {
    char str[100];
    printf("");
    fgets(str, 100, stdin);
    substituir(str);
    printf("%s\n", str);
    return 0;
}
