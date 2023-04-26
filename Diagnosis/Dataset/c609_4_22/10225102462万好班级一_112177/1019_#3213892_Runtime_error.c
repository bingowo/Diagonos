#include <stdio.h>

#include <stdlib.h>

typedef struct num{int number;
    int ws;} numb;

int qcmp(const void * q1, const void *q2)
{
    struct num  * p1 = (struct num *) q1;
    struct num  * p2 = (struct num *) q2;
    if(p2->ws == p1->ws)return p1->number - p2->number;
    return p2->ws - p1->ws;
}


int main() {

    numb array[100000];int count = 0;int sum = 0;
    do{sum++;
        scanf("%d", &array[count].number);
        count++;

    }while(getchar() != '\n');

    for (int i = 0; i < sum; ++i) {
        int k = 0;int nut = array[i].number;
        if(nut < 0)nut = -nut;
        while (nut) {nut = nut / 10;k++;}
        array[i].ws = k;
    }
        qsort(array,sum,sizeof(numb),qcmp);

        for (int h = 0; h < sum; ++h) {
            printf("%d ",array[h].number);
        }

}


