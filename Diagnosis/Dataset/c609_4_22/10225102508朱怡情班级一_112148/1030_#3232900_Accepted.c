#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
double key[128];

int cmp(const void* a,const void* b)
{
    char x=*(char*)a;
    char y=*(char*)b;
    if(key[(int)x]!=key[(int)y])return key[(int)y]<key[(int)x]?-1:1;
    else if(toupper(x)!=toupper(y))return x-y;
    else return y-x;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        for(int j=65;j<91;j++){
            scanf("%lf",&key[j]);
            key[j+32]=key[j];
        }
        char s[109];
        scanf("%s",s);
        int len=strlen(s);
        qsort(s,len,sizeof(char),cmp);
        printf("case #%d:\n%s\n",i,s);
    }
    return 0;
}