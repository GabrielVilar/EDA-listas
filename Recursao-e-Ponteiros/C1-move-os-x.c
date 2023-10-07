#include <stdio.h>
#include <string.h>
void move_x(char *str, int len, int i, int j) {
    if (i >= len) {
        str[i] = '\0';
        return;
    }
    
    if (str[i] == 'x') {
        move_x(str, len, i + 1, j);
        str[j + len - i - 1] = 'x'; 
        
    } else {
        str[j] = str[i];
        move_x(str, len, i+1, j+1);
    }
}

int main() {
    char str[1001];
    scanf("%s", str);
    
    int len = strlen(str);
    move_x(str, len, 0, 0);
    
    printf("%s", str);
    
    return 0;
}