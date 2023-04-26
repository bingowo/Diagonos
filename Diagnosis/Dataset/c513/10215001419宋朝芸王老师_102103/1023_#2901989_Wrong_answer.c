#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char a[31];
    int num;
    int flag;
    char ori[31];
}STRINGS;


int cmp(const void *a, const void *b){
    STRINGS *paa = (STRINGS*)a, *pbb = (STRINGS*)b;
    char *pa = paa->ori, *pb = pbb->ori;

    if(paa->flag == 0 && pbb->flag == 0)
        return strcmp(pa,pb);

    if(paa->flag != pbb->flag)
        return paa->flag > pbb->flag ? 1: -1;

    while(pa || pb){
        if(isdigit(*pa) && isdigit(*pb)){
            if(paa->num != pbb->num) return (paa->num - pbb->num);

        }
        else if(isdigit(*pa) || isdigit(*pb)){
            return isdigit(*pa) > isdigit(*pb) ? -1 : 1 ;
        }
        else if(*pa != *pb)
            return (*pa - *pb);

        pa++,pb++;
    }

    if(pa == 0 && pb != 0) return -1;
    if(pb == 0 && pa != 0) return 1;
    return 0;

    /*if(pa->flag != pb->flag)
        return pa->flag > pb->flag ? 1: -1;

    if(strcmp(pa->a , pb->a) != 0)
        return strcmp(pa->a , pb->a);

    return (pa->num - pb->num);*/
}

int main()
{
    char c;
    int i = 0,j = 0, h = 0;
    STRINGS str[101];

    str[0].num = 0;
    str[0].flag = 0;
    while((c = getchar()) != EOF && c != '\n'){

        if(c == ' '){
            c = getchar();
            str[i].ori[h] = '\0';
            str[i++].a[j] = '\0';
            str[i].num = 0;
            str[i].flag = 0;
            j = 0;
            h = 0;
        }

        if(c <= '9' && c >= '0'){
            str[i].ori[h++] = c;
            str[i].num = str[i].num*10 + c - '0';
            str[i].flag = 1;
        }

        else{
            str[i].ori[h++] = c;
            str[i].a[j++] = c;
        }
    }
    str[i].ori[h] = '\0';
    str[i++].a[j] = '\0';


    qsort(str,i,sizeof(STRINGS),cmp);


    printf("%s",str[0].ori);
    for(int k = 1; k < i; k++){
        printf(" %s",str[k].ori);
    }
    printf("\n");


    return 0;
}
