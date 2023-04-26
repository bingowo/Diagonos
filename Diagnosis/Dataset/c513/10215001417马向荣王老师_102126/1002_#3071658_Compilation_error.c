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
        int arr[1000];
        for(int i=0;i<1000;i++)
        {
            arr[i]=-1;
        }
        char *p=s;
        arr[*p]=1;
        int c=0,d=1;
        while(*(++p)) 
        {
            if(arr[*p]==-1)
            {
                arr[*p]=c;
                if(c==0) c=2;
                else c++;
                d++;
            }
        }
        if(d<2) d=2;
        long long ans=0;
        char q=s;   
        while(*q!=0)
        {
            ans=ans*d+arr[*q];
            q++;
        }
        printf("case #%d:\n",i);
        printf("%lld\n",ans);
    }
    return 0;
}
