#include <stdio.h>
#include <stdlib.h>



int main()
{
    int t;
    scanf("%d",&t);
    for(int i =0;i<t;i++)
    {
    int num1[200] ={0};
    int num2[200] ={0};
    int n;
    scanf("%d",&n);
    for(int k=0;k<n;k++)
    {
        int a;
        int b;
        scanf("%d%d",&a,&b);
        if(a==b)continue;
        else
        {
            num1[a]++;
            num2[b]++;
        }

    }
    int q;
    for(q=0;q<101;q++)
    {
        if(num1[q]&&num2[q])
        {
            printf("Poor dxw!\n");
            break;
        }
    }
    if(q==101)printf("Lucky dxw!\n");
    }
    return 0;
}
