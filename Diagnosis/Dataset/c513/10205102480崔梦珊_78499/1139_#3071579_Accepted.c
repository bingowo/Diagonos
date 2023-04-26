#include<stdio.h>
#include<string.h>
#include<math.h>
void f(int* m)
{

}
int main()
{
    int a;
    scanf("%d",&a);
    int m[8][200]={0};
    m[1][0]=1;
    for(int i=2;i<8;i++)
    {
        int num=pow(2,i-1);
        for(int j=0;j<num;j++)
        {
            m[i][j]=m[i-1][j/2]*10;
            j++;
            m[i][j]=m[i-1][j/2]*10+1;
        }
    }
    int ans=0;
    /*for(int i=1;i<8;i++)
    {
        int num=pow(2,i-1);
        for(int j=0;j<num;j++)
        {
            printf("%d\n",m[i][j]);
        }
    }*/
    
    for(int i=2;i<8;i++)
    {
        int num=pow(2,i-1);
        for(int j=0;j<num;j++)
        {
            if(m[i][j]!=0&&m[i][j]%a==0)
            {
                ans=m[i][j];
                if(ans<10000000)
                {
                    printf("%d",ans);
                    return 0;
                }
            }
        }
    }
    if(ans==0) printf("-1");
}
