#include<stdio.h>
int length(int a)
{
    int l=1;
    while(a>0)
    {
        a=a/2;
        l++;
    }
    return l;
}
int main()
{
    int number;
    scanf("%d",&number);
    int a[number][2];
    int result[number];
    for(int i=0;i<number;i++)
    {
        scanf("%d%d",&a[i][0],&a[i][1]);
        int s1[length(a[i][0])];
        int s2[length(a[i][1])];
        int a1=a[i][0];
        int a2=a[i][1];
        for(int k=0;k<length(a1);k++)
        {
            
        }
        int d=0;
        if(a[i][0]>=a[i][1])
        {
            for(int j=0;j<length(a[i][i]);j++)
            {
                
            }
        }
    }
    
}