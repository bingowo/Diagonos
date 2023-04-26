#include <stdio.h>
#include <stdlib.h>
int m,n,a[1000],b[1000];
int find(int *a,int c)
{
    int i;
    for(i = 0;i<m;i++)
    if(c==a[i]) {return i;break;}
    return -1;
}
int cmp(const void*c,const void*d)
{
    int A = *(int*)c,B = *(int*)d;
    if(find(a,A)>=0&&find(a,B)>=0) return find(a,A)-find(a,B);
    else if(find(a,A)<0&&find(a,B)<0) return A-B;
    else if(find(a,A)>=0&&find(a,B)<0) return -1;
    else return 1;

}
int main()
{
    scanf("%d",&m);
    int i;
    for(i =0;i<m;i++)
        scanf("%d",&a[i]);
    scanf("%d",&n);
    for(i = 0;i<n;i++)
        scanf("%d",&b[i]);
    qsort(b,n,sizeof(int),cmp);
    for(i = 0;i<n;i++)
        printf("%d ",b[i]);
    return 0;

}
