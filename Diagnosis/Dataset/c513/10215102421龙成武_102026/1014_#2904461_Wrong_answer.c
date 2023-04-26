#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void change3(int a,char *c)
{
    int i=0,j;
    char temp;
    while(a>=3)
    {
        c[i++]=a%3+'0';
        a/=3;
    }
    c[i++]=a+'0';
    c[i]=0;
    for(i=0,j=strlen(c)-1;i<j;i++,j--)
    {
        temp=c[i];
        c[i]=c[j];
        c[j]=temp;
    }
}
void threeplus(char *c,char *res)
{
    int i,len=strlen(c)-1,up=0,sum;
    for(i=len;i>=0;i--)
    {
        sum=(c[i]-'0')+1+up;
        if(sum>=3)
        {
            up=1;
            sum-=3;
        }
        else
        {
            up=0;
        }
        res[i]='0'+sum;
    }
    if(up==1)
        printf("1");
}
void threeminu(char*res)
{
    int a;
    for(int i=0;i<strlen(res);i++)
    {
        a=res[i]-'0'-1;
        if(a==-1)
        {
            res[i]='2';
        }
        else
        {
            res[i]=res[i]-1;
        }
    }
}
int main()
{
    int A,B,k=-1,temp,i;
    char c[33],res[34],*p,res2[34];
    scanf("%d %d",&A,&B);
    memset(c,0,sizeof(c));
    memset(res,0,sizeof(res));
    for(temp=B;temp!=0;temp/=3)
    {
        k++;
    }
    change3(A,c);

    res[strlen(c)]=0;
    threeplus(c,res);
    threeminu(res);

    if(k>0)     //要考虑k比现有长度要长的问题
    {
        temp=strlen(res);
        if(temp>=k+1)
            for(i=temp;i>=temp-k;i--)   //我这会改变字符串长度的
            {
                res[i+1]=res[i];
            }
        else if(temp<k+1)
        {
            for(i=temp;i>=temp-k;i--)
            {
                if(i>=0)
                    res[i+k+1-temp]=res[i];
                else if(i<0)
                {
                    res[i+k+1-temp]='0';
                }
            }//至此0填充完了
            temp=strlen(res);
            for(i=temp;i>=temp-k;i--)
            {
                res[i+1]=res[i];
            }
            res[0]='0';
        }
        res[temp-k]='.';                     //加小数点的功能
    }

    //清除前导和后导0
    temp=strlen(res);
    p=res;
    if(res[0]=='0'&&res[1]!='0'&&res[1]!='.')
    {
        for(;*p=='0';p++);
    }
    strcpy(res2,p);
    if(strchr(res2,'.'))
    {
        for(i=strlen(res2)-1;res2[i]=='0';i--);
        res2[++i]=0;
    }


    puts(res2);

    return 0;
}
