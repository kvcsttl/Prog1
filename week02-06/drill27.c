#include "stdio.h"

void print_out(char* p, int x){
    printf("p is %s and x is %x\n", p, x);
}

int main(){
    printf("Hello World!\n");

    char egyik[] = "Hello";
    char masik[] = "World!";
    printf("%s %s\n", egyik, masik);

    print_out("foo", 7);
}