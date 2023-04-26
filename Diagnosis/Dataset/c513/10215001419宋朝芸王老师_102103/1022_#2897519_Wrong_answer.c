#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char user[1000];
    char field[1000];
}EMAIL;

int cmp(const void *a, const void *b){
    EMAIL *A = (EMAIL*)a, *B = (EMAIL*)b;

    int k = strcmp(A->field, B->field);
    if(k != 0) return k;

    k = strcmp(A->user, B->user);
    return -k;
}

int main()
{
    int cases;
    scanf("%d",&cases);

    EMAIL *m = (EMAIL*)malloc(cases*sizeof(EMAIL));
    for(int i = 0; i < cases; i++){

        char c;
        int k = 0;
        while(scanf("%c",&c) && c!='@'){
            m[i].user[k++] = c;
        }
        m[i].user[k] = '\0';

        k = 0;
        while(scanf("%c",&c) && c!='\n'){
            m[i].field[k++] = c;
        }
        m[i].field[k] = '\0';

        //scanf("%s@%s",m[i].user,m[i].field);
    }

    EMAIL *p =m;
    qsort(p,cases,sizeof(EMAIL),cmp);

    for(int i = 0; i < cases; i++){
        printf("%s@%s\n",m[i].user,m[i].field);
    }


    return 0;
}
