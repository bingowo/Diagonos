#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>


#define INF 1000009

typedef long long int lli;

int num[101]={0};

void solve (int a,int b)
{
    scanf("%d%d",&a,&b);
    if ((num[a]==b)&&(num[b]==a));
    else if((num[a]==0)&&(num[b]==0))
    {
//        printf("pass");
        num[a]=b;
        num[b]=a;
//        printf("%d%d\n",num[a],b);
    }
    else
    {
        num[a]=-1;
        num[b]=-1;
    }
//    printf("%d",a);
//    for(int p=0;p<6;p++ ) printf("%d",num[p]);
}

int main(void)
{
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int flag = 0;

        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            int a,b;
            solve(a,b);
        }
        for(int k = 1;k<=100;k++)
        {
            if (num[k]==-1)
            {
                flag = 1;
                break;
            }
        }

        if (flag)
            printf("Poor dxw!\n");
        else
            printf("Lucky dxw!\n");
        memset(num,0,sizeof(num));
    }
    return 0;

}
