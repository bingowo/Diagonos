#include<stdio.h>
#include<string.h>
int remainder(const int* hex)
{
    if(hex[109]%2)return 1;
    return 0;
}
void do_div(int* hex)
{
    int i,tmp,left=0;for(i=0;i<110;++i)if(hex[i])break;
    for(i;i<110;++i)
    {
        tmp=hex[i]+left*10;
        hex[i]=tmp/2;
        left=tmp-hex[i]*2;
    }
    return;
}
int getlen(const int* hex)
{
    int i;for(i=0;i<110;++i)if(hex[i])return 110-i;
    return 0;
}
void get_reverse_binary(int* bina,int* hex,int hexlen)
{
    int i=0,flag=0,tmp;
    while(hexlen)
    {
        tmp=remainder(hex);
        if(!flag)
        {
            if(tmp){flag=1;bina[i++]=tmp;}
            do_div(hex);
        }
        else
        {
            bina[i++]=tmp;
            do_div(hex);
        }
        hexlen=getlen(hex);
    }
    return;
}
void calcu(int* ans,int i)
{
    int j,carry=0,tmp;
    for(j=109;j>-1;j--)
    {
        tmp=ans[j]*2+carry;
        ans[j]=tmp%10;
        carry=tmp/10;
    }
    carry=0;
    for(j=109;j>-1;j--)
    {
        tmp=ans[j]+i+carry;
        ans[j]=tmp%10;
        carry=tmp/10;
        if(!carry)return;
    }
    return;
}
void get_ans(const int* bina,int* ans)
{
    int i=350,j;for(i;i>-1;i--)if(bina[i])break;
    for(j=0;j<i+1;++j)calcu(ans,bina[j]);
    return;
}
int main()
{
    int T,i;scanf("%d",&T);char s[110];
    for(int cas=0;cas<T;++cas)
    {
        scanf("%s",s);
        int hex[110]={0},len=strlen(s),lenhex=len,ans[110]={0};
        for(i=len-1;i>-1;i--)hex[110-len+i]=s[i]-48;//将字符串读取到的数字存储到数组中
        int bina[10000]={0};
        get_reverse_binary(bina,hex,lenhex);//获取数字的二进制倒转值，结果存储在bina中
        get_ans(bina,ans);//获取倒转二进制表示的十进制数字，结果存储在ans中
        printf("case #%d:\n",cas);
        for(i=0;i<110;i++)if(ans[i])break;
        if(i==110)printf("0");
        for(i;i<110;++i)printf("%d",ans[i]);
        printf("\n");
    }
    return 0;
}
