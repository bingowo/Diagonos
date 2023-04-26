#include <stdio.h>
#include <stdlib.h>
#define num 100000007
#define el 210

int main()
{


    int n;
    scanf("%d",&n);
    for(int a=0;a<n;a++)
     {
        char s[108];
        scanf("%s",s);
        int res[101][210] ={1};
        int L =strlen(s);
    for(int i=0;i<L;i++)
    {
        int sum =0;
        for(int j=i;j<L;j++)
        {
            sum=sum*10+(s[j]-'0');
            sum%=el;
            for(int c =0;c<el;c++)
            {
                res[j+1][(c+sum)%el] = (res[j+1][(c+sum)%el] +res[i][c])%num;
                if(i)res[j+1][(c+el-sum)%el] = (res[j+1][(c+el-sum)%el] +res[i][c])%num;
            }

        }
    }
    int k =0;
    for(int i =0;i<210;i++)
    {
        if(i%2==0||i%3==0||i%5==0||i%7==0)k = (k%num +res[L][i]%num)%num;
    }
        printf("%d\n",k);
     }
    return 0;
}
