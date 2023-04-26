#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void F(int a[],int n)//升序
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int t = a[j];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[100001]={0};//初始化
    for(int z=0;z<n;z++)
    {
        scanf("%d",&a[z]);
    }
    F(a,n);
    int end=0;
    for(int i=0;i<n;i+=2)
    {
        end+= (a[i+1]-a[i]);
    }
    printf("%d",end);
    return 0;
}
