#include <stdio.h>
#include <stdlib.h>

char st[123][123];

int cmp(const void* x,const void* y){
    char* xx=(char**)x;
    char* yy=(char**)y;
    double a=atof(xx);
    double b=atof(yy);
    if (a-b<0) return -1;
    else return 1;
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%s",st[i]);
    }
    qsort(st+1,n,sizeof(st[0]),cmp);
    for (int i=1;i<=n;i++)
        printf("%s\n",st[i]);
    return 0;
}
