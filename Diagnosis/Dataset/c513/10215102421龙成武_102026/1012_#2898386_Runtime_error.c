#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int i,j,k,r,len;
    long long int a=0,b=0,qr=0,qi=0;
    char c[140],*res,temp,*p1,*p2,*p3;
    scanf("%s",c);
    res=(char*)malloc(sizeof(char)*1000);

    if(!strchr(c,'i'))
    {
        if(c[0]=='-')
        {
            for(i=1;i<strlen(c);i++)
            {
                a=a*10+c[i]-'0';
            }
            a*=-1;
        }
        else if(c[0]!='-')
        {
            for(i=0;i<strlen(c);i++)
            {
                a=a*10+c[i]-'0';
            }
        }
    }
    else
    {
        if(strchr(c,'+'))
        {
            p2=strchr(c,'+');
            if(c[0]=='-')
            {
                p1=c+1;
                for(;p1!=p2;p1++)
                {
                    a=a*10+*p1-'0';
                }
                a*=-1;
            }
            else
            {
                p1=c;
                for(;p1!=p2;p1++)
                {
                    a=a*10+*p1-'0';
                }
            }

            if(*(p2+1)=='i')
            {
                b=1;
            }
            else
            {
                p3=strchr(c,'i');
                for(p1=p2+1;p1!=p3;p1++)
                {
                    b=b*10+*p1-'0';
                }
            }
        }

        else
        {
            p2=strchr(c+1,'-');
            if(c[0]=='-')
            {
                p1=c+1;
                for(;p1!=p2;p1++)
                {
                    a=a*10+*p1-'0';
                }
                a*=-1;
            }
            else
            {
                p1=c;
                for(;p1!=p2;p1++)
                {
                    a=a*10+*p1-'0';
                }
            }

            if(*(p2+1)=='i')
            {
                b=-1;
            }
            else
            {
                p3=strchr(c,'i');
                for(p1=p2+1;p1!=p3;p1++)
                {
                    b=b*10+*p1-'0';
                }
                b*=-1;
            }
        }
    }

    i=0;
    do
    {
        r=(llabs(a)%2+llabs(b)%2)%2;          //取余运算可能有负数
        res[i++]=r+'0';
        qr=(r+b-a)/2;
        qi=(r-b-a)/2;

        a=qr;
        b=qi;
    }while(qr!=0||qi!=0);
    res[i]=0;

    for(i=0,len=strlen(res)-1;i<len;i++,len--)
    {
        temp=res[i];
        res[i]=res[len];
        res[len]=temp;
    }
    //res=strrev(res);

    puts(res);

    //free(res);        oj好像对free很不喜欢
    return 0;
}
