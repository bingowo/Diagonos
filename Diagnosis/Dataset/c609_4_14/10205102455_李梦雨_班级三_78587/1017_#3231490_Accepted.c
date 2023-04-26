#include <stdio.h>
#include <stdlib.h>

void asort(int a[],int n)//升序
{
    for(int i=0;i<n-1;i++)
    {
        int flag=0;//flag未改变仍为0说明此时数组已有序
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
                flag=1;
            }
        }
        if(flag==0) break;
    }
}

void dsort(int a[],int n)//降序
{
    for(int i=0;i<n-1;i++)
    {
        int flag=0;//flag未改变仍为0说明此时数组已有序
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]<a[j+1])
            {
                int tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
                flag=1;
            }
        }
        if(flag==0) break;
    }
}

int main()//输出时进行判断，相同的元素仅输出一次
{
    char c=getchar();
    int a[1000];
    int n=0;
    while(1)
    {
        scanf("%d",&a[n]);
        n++;
        if(getchar()=='\n') break;
    }
    if(c=='A') asort(a,n);
    else dsort(a,n);
    printf("%d",a[0]);
    for(int i=0;i<n-1;i++)
    {
        if(a[i]!=a[i+1])
            printf(" %d",a[i+1]);
    }
    printf("\n");
    return 0;
}
