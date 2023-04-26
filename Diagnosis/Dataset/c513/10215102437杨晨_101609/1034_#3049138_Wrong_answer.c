#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, void *b);
float fre[58];
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        for(int j=0;j<26;j++){
            scanf("%f",&fre[j]);
            fre[j+32] = fre[j];
        }
        char a[100];
        scanf("%s",a);
        int len=strlen(a);
        qsort(a,len,sizeof(char),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",a);
    }
}
int cmp(const void *a, void *b){
    char a1=*(char*)a;
    char b1=*(char*)b;
    if(fre[a1-65]-fre[b1-65]!=0)
        return (fre[a1-65]>fre[b1-65])?-1:1;
    else
    {
        if(a1-b1==32)
            return a1>b1?-1:1;
        else
            return a1>b1?1:-1;
    }
    }
