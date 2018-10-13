/* test.c */

#include <stdio.h>

typedef struct person {
    char family_name[16];
    char first_name[16];
    int age;
} person;

void* ptr;
void set_ptr(void* p) {
    ptr = p;
}
void* get_ptr() {
    return ptr;
}

int main(int argc, char *argv[]) {
    person p = {"Tanaka", "Taro", 10};
        
    set_ptr(&p);

    person* p2 = get_ptr();
    printf("%s %s\n", p2->family_name, p2->first_name);

    return 0;
}
