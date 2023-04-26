#include<stdio.h>
#include<string.h>
#include<math.h>
int f(int length,long long s[],int jin)//jin是进制,这里的值应该是m（吧）
{
    long long sum=0;
    int q;
    sum=s[0];
    for(int p=1;p<length-1;p++)
    {
        sum=sum*jin+s[p];
    }
    return sum;
}
int main()
{
    int T,i,len,j,k,m=0;
    char s[61];
    long long c[61],y;
    c[0]=1;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        scanf("%s",s);
        len=strlen(s);
        for(j=0;j<len;j++)
        {
            for(k=0;k<j;k++)
            {
                if(s[k]==s[j]){
                    c[j]=c[k];
                    break;
                }
            }//寻找相同符号 有就赋值并退出
            if(k==j){
                c[j]=m;
                if(m==0)
                m=1;
                m++;
            }
        }
        printf("%lld\n",f(len,c,m+1));

    }
    return 0;
}