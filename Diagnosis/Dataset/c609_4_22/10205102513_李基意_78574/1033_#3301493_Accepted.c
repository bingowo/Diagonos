#include <stdio.h>
#include <string.h>
int main()
{
    int T, I;
    scanf("%d",&T);
    for(I=0; I<T; I++)
    {
        char s[100];
        int i, n, cnt, ans[140]={0}, j;//将计算的结果存入ans数组中
        scanf("%s",s);
        int l=strlen(s);
        for(i=0, cnt=0, j=0; i<l; i++)
        {
            if(cnt==0) //处理每三个字符中的第一个
            {
                ans[j++]=s[i]/4;
                ans[j]=(s[i]%4)*16;
            }
            else if(cnt==1)//处理第二个
            {
                ans[j++]+=s[i]/16;
                ans[j]=(s[i]%16)*4;
            }
            else//处理第三个
            {
                ans[j++]+=s[i]/64;
                ans[j++]=s[i]%64;
            }
            cnt=(++cnt)%3;//注意这里要先自增再模3
        }
        if(j%4) for(j++; j%4!=0; j++) ans[j]=64;//补齐4的倍数个输出
        printf("case #%d:\n",I);
        for(i=0; i<j; i++)//处理输出
        {
            if(ans[i]<26) printf("%c",'A'+ans[i]);
            else if(ans[i]<52) printf("%c",'a'+ans[i]-26);
            else if(ans[i]<62) printf("%c",'0'+ans[i]-52);
            else if(ans[i]==62) printf("+");
            else if(ans[i]==63) printf("/");
            else printf("=");
        }
        printf("\n");
    }
    return 0;
}