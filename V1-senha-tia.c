#include <stdio.h>

int main() {
    int n, m, a, k;
    scanf("%d %d %d %d", &n, &m, &a, &k);

    char password[1001];
    scanf("%s", password);

    int num_lower = 0, num_upper = 0, num_digits = 0, length = 0;
    for(int i=0; password[i]!='\0'; i++) {
        length++;
        if(password[i] >= 'a' && password[i] <= 'z') {
            num_lower++;
        }
        else if(password[i] >= 'A' && password[i] <= 'Z') {
            num_upper++;
        }
        else if(password[i] >= '0' && password[i] <= '9') {
            num_digits++;
        }
    }

    if(length >= n && num_lower >= m && num_upper >= a && num_digits >= k) {
        printf("Ok =/\n");
    }
    else {
        printf("Ufa :)\n");
    }

    return 0;
}
/*
PDF Informativo:
    https://drive.google.com/file/d/1UNq8sWR6D7zU_2__WxoZjXgA-B6yM2sG/view
*/