#include<stdio.h>
#include<string.h>
int main()
{
    int t;//问题数
    scanf("%d\n",&t);
    for(int i=0;i<t;i++)
    {
        char s[61];
        scanf("%s",s);//输入的神秘信息
        int arr[128];//存放数字
        for(int j=0;j<128;j++)
        {
            arr[j]=-1;
        }
        char *p=s;//把s[j]当作arr下标
        arr[*p]=1;
        int d=1,c=0;
        while(*++p)//要求进制
        {
            if(arr[*p]==-1)
            {
                arr[*p]=c;
                if(c==0) c=2;
                else c=c+1;
                d++;
            }
        }
        if(d<2) d=2;
        long long int minz=0;
        p=s;
        while(*p!=0)
        {
            minz=minz*d+arr[*p];
            p++;
        }
        printf("case #%d:\n",i);
        printf("%d\n",minz);
    }
    return 0;
}