#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DNA{
    char DNA[21];
    int times;
}dna;

int cmp(const void *a, const void *b){
    dna *A = (dna*)a, *B = (dna*)b;
    if(A->times==B->times){
        return strcmp(A->DNA, B->DNA);
    }
    return A->times - B->times;
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    dna inputs[n];
    memset(inputs, 0, n*sizeof(dna));
    dna once[n];
    memset(once, 0 , n*sizeof(dna));
    int onceCnt = 0;

    for(int i = 0;i<n;i++){
        scanf("%s",inputs[i].DNA);
        int isNew = 1;
        for(int j = 0;j<onceCnt;j++){
            if(strcmp(inputs[i].DNA, once[j].DNA)==0){
                isNew = 0;
                once[j].times++;
                break;
            }
        }
        if(isNew == 1){
            strcpy(once[onceCnt].DNA, inputs[i].DNA);
            once[onceCnt].times++;
            onceCnt++;
        }
    }

    qsort(once, onceCnt, sizeof(once[0]), cmp);

    for(int i = 0;i<onceCnt;i++){
        printf("%s\n",once[i].DNA, once[i].times);
    }


    return 0;
}
