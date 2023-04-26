#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct line{
    char s[20];
    int n;
};

int count(char s[])
{
    int table[130],n=0;;
    for(int j = 0;j < 130;j++)table[j] = -1;
    for(int i = 0;i < strlen(s);i++){
        if(table[s[i]] == -1)table[s[i]]=1;n++;
    }
    return n;
}

int cmp(const void* a,const void* b)
{
    struct line x = *((struct line*)a);
    struct line y = *((struct line*)b);
    if(x.n != y.n)return y.n-x.n;
    else
        return strcmp(x.s,y.s);
}


int main()
{

    int T,i,j,k;
    scanf("%d",&T);
    for(i = 0;i < T;i++){
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        struct line str[n];
        for(j = 0;j < n;j++){
            scanf("%s",str[j].s);
            str[j].n = count(str[j].s);
        }
        qsort(str,n,sizeof(struct line),cmp);
        for(k = 0;k < n;k++){
            printf("%s\n",str[k].s);
        }
    }
    return 0;
}
