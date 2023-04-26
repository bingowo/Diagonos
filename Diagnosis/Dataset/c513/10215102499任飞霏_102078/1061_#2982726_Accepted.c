#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char s[16];
    long long d;
}A;

long long s2i(char *str)
{
    int table[130];
    for(int i=0;i<130;i++)table[i]=-1;
    int len=0;
    table[str[len]]=1;
    while(str[len+1]==str[len])len++;
    table[str[len+1]]=0;
    int p=2;
    for(int j=len+1;str[j];j++){
        len++;
        if(table[str[j]]==-1)table[str[j]]=p++;
    }
    long long mul=1;
    long long ans=0;
    for(int j=len;j>=0;j--){
        ans+=table[str[j]]*mul;
        mul*=p;
    }
    return ans;
}

int cmp(const void*a,const void* b)
{
    A x=*((A*)a);
    A y=*((A*)b);
    if(x.d>y.d)return 1;
    if(x.d<y.d)return -1;
    else
        return strcmp(x.s,y.s);
}


int main()
{
    int N;
    scanf("%d",&N);
    A str[10000];
    int i=0;
    for(i=0;i<N;i++){
        scanf("%s",str[i].s);
        str[i].d = s2i(str[i].s);
    }
    qsort(str,i,sizeof(A),cmp);
    for(int j=0;j<i;j++){
        printf("%s\n",str[j].s);
    }
    return 0;
}
