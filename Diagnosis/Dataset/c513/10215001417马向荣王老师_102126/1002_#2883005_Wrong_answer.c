#include<stdio.h>
#include<string.h>
int main()
{
    int t;//问题数
    scanf("%d\n",&t);
    for(int i=0;i<t;i++)
    {
        char s[61];
        scanf("%s",s);//信息
        int arr[128];//转换后的数字
        for(int j=0;j<128;j++)
        {
            arr[j]=-1;
        }
        int c=0,d=1;
        char *p=s;
        arr[*p]=1;
        while(*++p!=0)
        {
            if(arr[*p]==-1)//第一个arr[*p]与首个不一样
            {
                arr[*p]=c;//赋为0
                if(c!=0)
                {
                    c=c+1;
                }
                else
                {
                    c=2;
                }
                d++;
            }
            if(d<2)
            {
                d=2;
            }
        }
        long long int minz=0;
        p=s;
        while(*p!=0)
        {
            minz=minz*d+arr[*p++];
        }
        printf("case #%d:\n",i);
        printf("%lld\n",minz);//装数字的数组arr
    }
    return 0;
}