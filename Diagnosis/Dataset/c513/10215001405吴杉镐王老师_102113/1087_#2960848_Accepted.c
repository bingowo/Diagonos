#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int T,num[10005],cnt;
char s[10005];
int main()
{
    scanf("%d",&T);
    for(int c=0;c<T;c++)
    {
        scanf("%s",s); //字符串形式处理
        cnt=0;
        int l=strlen(s);
        for(int i=l-1;i>=0;i--)
            num[++cnt]=s[i]-'0';
        num[0]=num[cnt+1]=num[cnt+2]=0; //再将字符串中元素赋给整形数组，更好处理每个位
        int f=1;
        for(int i=1;i<cnt;i++)
            if(num[i]==num[i+1])
            {
                f=0;
                break; //应该可以吧？
            }
        if(f==1)
        {
            num[1]++;
            for(int i=1;i<=cnt;i++)
            {
                num[i+1]+=num[i]/10;
                num[i]%=10;
            }
            if(num[cnt+1]>0)
                cnt++;
        }
        for(int i=cnt;i>1;i--)
        {
            if(num[i]==num[i-1])
            {
                if(num[i-1]!=9)
                {
                    num[i-1]++;
                    for(int j=i-2;j;j--)
                        if((j-i+1)%2)
                            num[j]=0;
                        else
                            num[j]=1;
                }
                else
                {
                    num[i]=num[i-1]=0;
                    num[i+1]++;
                    i+=3;
                }
                for(int j=i-1;j<=cnt;j++)
                {
                    num[j+1]+=num[j]/10;
                    num[j]%=10;
                }
                if(num[cnt+1]>0)
                    cnt++;
            }
        }
        printf("case #%d:\n",c);
        for(int i=cnt;i;i--)
            printf("%d",num[i]);
        puts("");
    }
    return 0;
}