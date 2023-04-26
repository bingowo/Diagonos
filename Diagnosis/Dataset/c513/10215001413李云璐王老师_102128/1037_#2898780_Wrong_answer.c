#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void sort(int*s,int m)
{
    int cmp(const void*a1,const void*a2)
    {
        int a=*(int*)a1;
        int b=*(int*)a2;
        return a-b;
    }
    qsort(s,m,sizeof(int),cmp);
}
int main()
{
    int n,m;
    scanf("%d%d\n",&n,&m);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    sort(a,n);
    int b[m];
    strncpy(b,a,m);
    int max=b[m-1],data=0;
    for(int k=0;k<m-1;k++)
    data+=max-b[k];
    printf("%d",data);
    return 0;
    
    
}