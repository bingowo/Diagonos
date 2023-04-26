#include <stdio.h>
#include <stdlib.h>

double f[58];

int cmp(const void *a,const void *b){
    char *a1 = (char*)a,*b1 = (char*)b;
    double a2,b2;
    a2 = f[*a1 - 'A'];
    b2 = f[*b1 - 'A'];
    if(a2 == b2){
        if(abs(*a1 - *b1) == 32 || *a1 == *b1)return *b1 - *a1;
        else{
            if((*a1 - 'Z' -1) * (*b1 - 'Z' -1) > 0)return *a1 - *b1;
            else{
                if(*a1 > *b1)return *a1 - 32 - *b1;
                else return *a1 + 32 - *b1;
            }
        }
    }
    else return a2 > b2?-1:1;
}

int main()
{
    int T;
    scanf("%d",&T);
    char s[101];
    for(int i = 0;i < T;i++){
        for(int j = 0;j < 26;j++){
            scanf("%lf", &f[j]);
            f[j + 32] = f[j];
        }
        scanf("%s",s);
        qsort(s,strlen(s),sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s\n", s);
    }
    return 0;
}
