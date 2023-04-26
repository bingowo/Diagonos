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
        printf("case #%d:\n",i);
        int arr[1000];//转换后的数字
        for(i=0;i<1000;i++)
        {
            arr[i]=-1;
        }
        arr[s[0]]=1;
        int c=1;
        int len=strlen(s);
        int d=1;
        for(int j=0;j<len;j++)
        {
            if(arr[s[j]==-1])
            {
                if(c!=0)
                {
                    arr[s[j]]==0;
                    c=0;
                    d++;
                }
                else
                {
                    arr[s[j]]==d++;
                }
            }
        }
        if(d==1)
        {
            d=2;
        }
        long long int minz=0;
        for(int j=1;j<len;j++)
        {
            minz=minz*2+arr[s[j]];
        }
        printf("%s",arr);//装数字的数组arr
    }
    return 0;
}