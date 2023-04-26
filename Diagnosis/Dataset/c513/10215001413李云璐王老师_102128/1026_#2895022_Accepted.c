#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void sort(int*a,int n)
{
    int compare(const void*a1,const void*a2)
    {
        int a=*(int*)a1;
        int b=*(int*)a2;
        return a-b;
    }
    qsort(a,n,sizeof(int),compare);
}
int main()
{
    int n;
    scanf("%d\n",&n);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    sort(a,n);
    int data=0;
    for(int k=0,h=0;k<n/2;k++,h+=2)
    {
        data+=a[h+1]-a[h];
    }
    printf("%d",data);
    return 0;
    
}