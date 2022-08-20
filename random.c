#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COUNT          15

int main()
{
    int data[MAX_COUNT], i, sub_i;

    srand((unsigned int)time(NULL));

    for (i = 0; i < MAX_COUNT; i++) {
        data[i] = rand() % MAX_COUNT + 1;
        for (sub_i = 0; sub_i < i; sub_i++) {
            if (data[i] == data[sub_i]) {
                i--;
                break;
            }
        }
    }

    for (i = 0; i < MAX_COUNT; i++) printf("%d ", data[i]);
    printf("\n");
    return 0;
}