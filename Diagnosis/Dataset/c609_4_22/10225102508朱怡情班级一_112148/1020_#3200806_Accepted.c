#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char s[40];
    int dig;
}A;

int cmp(const void* a,const void* b)
{
    A x=*(A*)a;
    A y=*(A*)b;
    if(x.dig!=y.dig)return x.dig-y.dig;
    else return strcmp(x.s,y.s);
}

int main()
{
    A a[109];
    int i=0;
    while(scanf("%s",a[i].s)!=EOF){
        a[i].dig=-1;
        for(int j=0;a[i].s[j]!=0;j++){
            if(a[i].s[j]>='0'&&a[i].s[j]<='9'){
                if(a[i].dig==-1)a[i].dig=0;
                a[i].dig=a[i].dig*10+a[i].s[j]-'0';
            }
        }
        i++;
    }
    qsort(a,i,sizeof(a[0]),cmp);
    for(int j=0;j<i;j++)printf("%s ",a[j].s);
    return 0;
}
