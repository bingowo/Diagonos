#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int GCD(int m,int n)
{
    if(n%m && n!=m )
        return GCD(n%m,m);
    else
        return m;

}
int main()
{
    int cmp1(const void*a,const void*b)
    {
        int x=*(int*)a,y=*(int*)b;
        return x-y;
    }
    int cmp2(const void*a,const void*b)
    {
        int x=*(int*)a,y=*(int*)b;
        return y-x;
    }
    char s;
    int a[1000],i=1,j=0;
    scanf("%c",&s);
    scanf("%d",&a[0]);
    while(scanf("%d",&a[i])!=EOF){
        for(j=0;j<i+1;j++){
            if(a[j]==a[i]){
                break;
            }
        }
        if(j==i) i++;

    }
    if(s=='A') qsort(a,i,sizeof(a[0]),cmp1);
    if(s=='D') qsort(a,i,sizeof(a[0]),cmp2);
    for(int n=0;n<i;n++) printf("%d ",a[n]);
    return 0;
}