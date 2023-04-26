#include<stdio.h>
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int t=0;
        int num;
        scanf("%d",&num);
        int a[num],b[num];
        for(int j=0;j<num;j++)
        {
            scanf("%d%d",&a[j],&b[j]);
        }
        for(int j=0;j<num;j++)
        {
            for(int k=0;k<num;k++)
            {
                if(b[j]==a[k])
                {
                    t++;
                }
            }
        }
        if(t>0)
        {
            printf("Poor dxw!\n");
        }
        else
        {
            printf("Lucky dxw!\n");
        }
    }
    return 0;
}