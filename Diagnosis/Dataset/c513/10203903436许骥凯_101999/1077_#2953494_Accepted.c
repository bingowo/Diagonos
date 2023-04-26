#include<stdio.h>
#include<stdlib.h>

int table[1001] = {0};
int cmp(const void *p1, const void *p2){
    int b1 = *(int*)p1, b2 = *(int*)p2;
    if (table[b1] && table[b2]) return table[b1] - table[b2];
    else if (table[b1]) return -1;
    else if (table[b2]) return 1;
    else return b1 - b2;
    
}

int main(){
    int alen; scanf("%d", &alen);
    for (int i = 0; i != alen; i++){
        int temp; scanf("%d", &temp);
        table[temp] = i + 1;
    } 
    int blen; scanf("%d", &blen);
    int B[1001] = {0};
    for (int i = 0; i != blen; i++) scanf("%d", &B[i]);
    qsort(B, blen, sizeof(B[0]), cmp);
    for (int i = 0; i != blen; i++) printf("%d ", B[i]);
    printf("\n");
    return 0;
}