/* hanoi.c */

#include <stdio.h>

#define N 20

int tower[3][N + 1];

int move(int from, int to) {
    int from_top = 0, to_top = 0;
    for(int i = 0; i <= N; i++) {
        if(tower[from][i] == 0) {
            from_top = i - 1;
            break;
        }
    }
    for(int i = 0; i <= N; i++) {
        if(tower[to][i] == 0) {
            to_top = i - 1;
            break;
        }
    }
    if(from_top < 0) {
        return 0;
    }
    if((to_top >= 0) && (tower[from][from_top] > tower[to][to_top])) {
        return 0;
    }
    printf("Moving %d : %d -> %d\n", tower[from][from_top], from, to);
    tower[to][to_top + 1] = tower[from][from_top];
    tower[from][from_top] = 0;

    return 1;
}

int hanoi(int from, int to, int height) {
    //
}

int main(int argc, char *argv[]) {
    for(int i = 0; i <= N; i++) {
        tower[0][i] = N - i;
        tower[1][i] = 0;
        tower[2][i] = 0;
    }

    if(! hanoi(0, 1, N)) {
        printf("Fail!\n");
    }
}
