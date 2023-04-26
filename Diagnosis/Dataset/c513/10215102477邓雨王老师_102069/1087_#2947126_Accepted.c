#include <stdio.h>
#include <string.h>
int noReputationTwice=1;//判断是否连续两次都是非重复数
void solve(char *num)//10**100超出整数形变量的范围，只能用字符来表示
{
    int l=strlen(num), check=0, i;
    if(l==1 && num[0]<'9') printf("%c\n",num[0]+1);//处理一位数
    else if(l==1 && num[0]=='9') printf("10\n");//处理9
    else
    {
        for(i=0; i<l-1; i++) if(num[i]==num[i+1]) break;
        if(i==l-1)//num自身不是重复数的情况
        {
            if(noReputationTwice!=0)
            {
                for(i=0; i<l; i++) printf("%c",num[i]); printf("\n");
                return;
            }
            if(num[l-1]=='9') {num[l-2]++; num[l-1]='0';}
            else num[l-1]++;
            noReputationTwice=1;
            solve(num);
            return;
        }
        else if(num[i]!='9')//处理一般情况
        {
            num[i+1]++;
            for(i+=2; i<l; i++)
            {
                if(check==0) {num[i]='0'; check=1;}
                else {num[i]='1'; check=0;}
            }
        }
        else if(i==0)//处理首位是9的情况
        {
            printf("1");
            for(i=0; i<l; i++)
            {
                if(check==0) {num[i]='0'; check=1;}
                else {num[i]='1'; check=0;}
            }
        }
        else//处理重复数是9的情况
        {
            num[i-1]++;
            for(; i<l; i++)
            {
                if(check==0) {num[i]='0'; check=1;}
                else {num[i]='1'; check=0;}
            }
        }
        noReputationTwice=0;
        for(i=0; i<l-1; i++) if(num[i]==num[i+1]) break;//再次判断是否有重复数
        if(i==l-1) //没有重复数直接输出
        {
            for(i=0; i<l; i++) printf("%c",num[i]); printf("\n");
            return;
        }
        else solve(num);//有重复数循环处理
    }
}
int main()
{
    int T, I;
    scanf("%d",&T);
    for(I=0; I<T; I++)
    {
        noReputationTwice=0;
        char num[120];
        int i;
        scanf("%s",num);
        printf("case #%d:\n",I);
        solve(num);
    }
    return 0;
}