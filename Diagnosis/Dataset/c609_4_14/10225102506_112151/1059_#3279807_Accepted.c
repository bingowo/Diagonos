#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void *b){
    char *x=(char *)a;
    char *y=(char *)b;
    long double A=atof(x);
    long double B=atof(y);
    if(A<B) return -1;
    else if(A>B)    return 1;
    else return 0;
}

int main()
{
    int n;
    scanf("%d",&n);
    char s[n][101];
    for(int i=0;i<n;i++)
        scanf("%s",&s[i]);
    qsort(s,n,sizeof(s[0]),cmp);
    for(int j=0;j<n;j++)
        printf("%s\n",s[j]);
    return 0;
}
