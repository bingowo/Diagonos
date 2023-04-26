#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char a[31];
    int num;
    int flag;
}STRINGS;

int cmp(const void *a, const void *b){
    STRINGS *pa = (STRINGS*)a, *pb = (STRINGS*)b;

    if(pa->flag != pb->flag)
        return pa->flag > pb->flag ? 1: -1;

    if(strcmp(pa->a , pb->a) != 0)
        return strcmp(pa->a , pb->a);

    return (pa->num - pb->num);
}

int main()
{
    char c;
    int i = 0,j = 0;
    STRINGS str[101];

    str[0].num = 0;
    str[0].flag = 0;
    while((c = getchar()) != EOF && c != '\n'){

        if(c == ' '){
            c = getchar();
            str[i++].a[j] = '\0';
            str[i].num = 0;
            str[i].flag = 0;
            j = 0;
        }

        if(c <= '9' && c >= '0'){
            str[i].num = str[i].num*10 + c - '0';
            str[i].flag = 1;
        }

        else str[i].a[j++] = c;
    }
    str[i++].a[j] = '\0';


    qsort(str,i,sizeof(STRINGS),cmp);


    printf("%s",str[0].a);
    if(str[0].flag == 1) printf("%d",str[0].num);
    for(int k = 1; k < i; k++){
        printf(" %s",str[k].a);
        if(str[k].flag == 1) printf("%d",str[k].num);
    }
    printf("\n");


    return 0;
}
