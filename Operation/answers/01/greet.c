#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int hour;
    
    if (argc < 2) {
        fprintf(stderr, "時刻を指定してください\n");
        return 1;
    }

    hour = atoi(argv[1]);
    
    if (hour >= 5 && hour <= 10) {
        printf("おはようございます\n");
        return 0;
    }
    if (hour >= 11 && hour <= 17) {
        printf("こんにちは\n");
        return 0;
    }
    if (hour >= 18 && hour <= 20) {
        printf("こんばんは\n");
        return 0;
    }
    
    printf("おやすみなさい\n");
    return 0;
}
