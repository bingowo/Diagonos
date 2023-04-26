#include<stdio.h>
#define N=1e6;
typedef struct{
    int n;
    int count;
}num;
int down(const void*A,const void*B)
{
    int a=*(int*)A;
    int b=*(int*)B;
    return a>b?-1:1;
}
int up(const void*A,const void*B)
{
    int a=*(int*)A;
    int b=*(int*)B;
    return a>b?1:-1;
}
int main()
{
    int s[N],m,i=0;
    while(scanf("%d",&m)!=EOF){
      s[i++]=m;  
    }
    qsort(s,i,sizeof(int),)
    return 0;
}