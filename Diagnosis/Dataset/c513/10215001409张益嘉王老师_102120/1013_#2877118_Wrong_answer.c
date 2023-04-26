#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int yueshu(int a,int b)
{
    if(a==b) return a;
    else if(a>b) return yueshu(b,a);
    else
    {
        if((b%a)==0) return a;
        else return yueshu(b%a,a);
    }
}

int main()
{
    char s[1000];
    int n[1000],m[1000];
    int i,len,pl=0,re=0;
    scanf("%s",s);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='.')break;
        pl++;
    }

    //printf("pl=%d\n",pl);
    if(pl>=len)
    {
        for(i=0;i<len;i++)
        {
            if(s[i]=='2') n[i]=-1;
            else n[i]=s[i]-'0';
        }
        for(i=len-1;i>=0;i--)
        {
            re+=n[i]*pow(3,len-i-1);
        }
        printf("%d",re);
    }
    else
    {
        int a=0,b=0,c=1,j;
        for(i=0;i<pl;i++)
        {
            if(s[i]=='2') n[i]=-1;
            else n[i]=s[i]-'0';
        }
        for(i=pl-1;i>=0;i--)
        {
            a+=n[i]*pow(3,pl-i-1);
        }
        //printf("test仅算了a时： a=%d\n",a);
        for(i=pl+1,j=0;i<len;i++,j++)
        {
            if(s[i]=='2') m[j]=-1;
            else m[j]=s[i]-'0';
        }
        for(i=pl+1,j=0;i<len;i++,j++)
        {
           b+=m[j]*pow(3,len-pl-2-j);
           c*=3;
        }
        //printf("test1未约分 未处理符号 a=%d b=%d c=%d\n",a,b,c);
        if(a==0)
        {
            int d;
            if (b<0) d=-b;
            else d=b;
            int yue=yueshu(d,c);
            b=b/yue;
            c=c/yue;
            printf("%d %d\n",b,c);
        }
        else
        {
            if (b<0)
            {
                a--;
                b=b+c;
            }
            else if(a<0)
            {
                a++;
                b=c-b;

            }
            int yue=yueshu(b,c);
        b=b/yue;
        c=c/yue;
        printf("%d %d %d\n",a,b,c);
        }


    }


    return 0;
}
