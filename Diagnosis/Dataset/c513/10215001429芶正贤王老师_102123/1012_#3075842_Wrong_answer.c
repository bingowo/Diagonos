#include<stdio.h>
#include<string.h>

int main()
{
    char s[505];
    scanf("%s",s);
    int len;
    len = strlen(s);
    long long int a=0,b=0;
    if(s[len-1]=='i')
    {
        if(len>1)
        {
            if(s[len-2]=='+')
                b=1;
            else if(s[len-2]=='-')
                b=-1;
        }
    }
    if(len==1)//一位
    {
        if(s[0]>'0'-1 && s[0]<'9'+1)//正数
        {
            a=s[0]-'0';
        	b=0;
        }
        else if(s[0]=='i')
        {
            a=0;
            b=1;
        }
    }
    else if(len==2 && s[0]=='-' && s[1]=='i')
    {
        a=0;
        b=-1;
    }
    int markzh=0;
    //获取a，b
    for(int i=0;i<len;i++)
    {
        if(s[i]=='+')
            markzh = i;
    }
    if(markzh != 0)//有正号
    {
        if(s[0]!='-')//a正b正
        {
            for(int i=0;i<markzh;i--)
            {
                a+=s[i]-'0';
                a = a*10;
            }
            a=a/10;
            for(int i=markzh+1;i<len-1;i++)
            {
                b+=s[i]-'0';
                b = b*10;
            }
            b=b/10;
        }
        else//a负b正
        {
            for(int i=1;i<markzh;i--)
            {
                a+=s[i]-'0';
                a = a*10;
            }
            a = a*(-1);
            a=a/10;

            for(int i=markzh+1;i<len-1;i++)
            {
                b+=s[i]-'0';
                b = b*10;
            }
            b=b/10;
        }

    }

    else if(s[0]=='-')
    {
        if(s[len-1]!='i')
        {
            for(int i=1;i<len;i++)
            {
                a+=s[i]-'0';
                a = a*10;
            }
            a=a*(-1);
            a=a/10;
            b=0;
        }
        else
        {
            int mark3;
            for(int i=1;i<len;i++)
            {
                if(s[i]=='-')
                    mark3=i;
            }
            for(int i=1;i<mark3;i++)
            {
                a+=s[i]-'0';
                a=a*10;
            }
            a=a*(-1);
            a=a/10;
            for(int i=mark3+1;i<len-1;i++)
            {
                b+=s[i]-'0';
                b=b*10;
            }
            b=b*(-1);
            b=b/10;

        }
    }
    else if(s[len-1]!='i')
    {
        for(int i=0;i<len;i++)
        {
            a+=s[i]-'0';
            a=a*10;
        }
        a=a/10;
        b=0;
    }
    else if(s[0]=='-')
    {
        a=0;
        for(int i=1;i<len-1;i++)
        {
            b+=s[i]-'0';
            b=b*10;
        }
        b=b*(-1);
        b=b/10;
    }
    int stan=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='-')
        {
            stan=i;
            break;
        }
    }
    if(stan!=0)
    {
        for(int i=0;i<stan;i++)
        {
            a+=s[i]-'0';
            a=a*10;
        }
        a=a/10;
        for(int i=stan+1;i<len-1;i++)
        {
            b+=s[i]-'0';
            b=b*10;
        }
        b=b*(-1);
        b=b/10;
    }
    else if(stan == 0)
    {
        a=0;
        for(int i=0;i<len-1;i++)
        {
            b+=s[i]-'0';
            b=b*10;
        }
        b=b/10;
    }
    int ans[505];
    int i=0,stand;
    while(1)
    {
        if(a==0)
        {
            if(b==0)
            {
                stand=i;
                break;
            }

        }
        if((a+b)%2==0)//和为偶 余0
            ans[i]=0;
        else
            ans[i]=1;
        int rr=a;
        a=(b-a)/2;
        b=(-1)*(rr+b)/2;
        i++;

    }
    for(int i=stand-1;i>-1;i--)
    {
        printf("%d",ans[i]);

    }
    return 0;
}