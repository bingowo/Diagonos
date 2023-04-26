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
        num[0]=num[cnt+1]=num[cnt+2]=0; //再将字符串中元素赋给整型数组，更好处理每个位
        num[1]++;
        for(int i=1;i<=cnt;i++)
        {
            num[i+1]+=num[i]/10;
            num[i]%=10;
        }
        if(num[cnt+1]>0)
            cnt++;
        for(int i=cnt;i>1;i--)
        {
            if(num[i]==num[i-1]) //出现重复的情况
            {
                //思考 若从低位开始是办不到的
                if(num[i-1]!=9)
                {
                    num[i-1]++; //首先要不重复
                    for(int j=i-2;j;j--) //之后要符合不重复且最小！
                        if((j-i+1)%2)
                            num[j]=0;
                        else
                            num[j]=1;
                } //类比于进位
                else //都是9的情况要特殊处理！
                {
                    num[i]=num[i-1]=0;
                    num[i+1]++;
                    i+=3;
                } //特殊的进位
                //每次都要进位处理
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
//掌握算法，从高位开始处理！
