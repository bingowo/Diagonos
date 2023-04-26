#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<malloc.h>

int main()
{
    int i,j,k,r;
    long long int a=0,b=0,qr=0,qi=0;
    char c[140],*res;
    scanf("%s",c);
    res=(char*)malloc(sizeof(char)*1000);

    for(i=0;i<strlen(c);i++)
    {
        if(c[i]=='i')               //如果找到i
        {
            if(strlen(c)==1)
            {
                a=0;
                b=1;
            }
            else if(strlen(c)!=1)
            {
                if(c[i-1]=='-')
                {
                    b=-1;
                    if(c[0]!='-')
                    {
                        for(j=0;j<i-1;j++)
                        {
                            a=a*10+c[j]-'0';
                        }
                    }
                    else if(c[0]=='-')
                    {
                        for(j=1;j<i-1;j++)
                        {
                            a=a*10+c[j]-'0';
                        }
                        a*=-1;
                    }
                }
                else if(c[i-1]=='+')
                {
                    b=1;
                    if(c[0]!='-')
                    {
                        for(j=0;j<i-1;j++)
                        {
                            a=a*10+c[j]-'0';
                        }
                    }
                    else if(c[0]=='-')
                    {
                        for(j=1;j<i-1;j++)
                        {
                            a=a*10+c[j]-'0';
                        }
                        a*=-1;
                    }
                }
                else
                {
                    if(c[0]=='-')
                    {
                        if(strchr(c+1,'-'))
                        {
                            k=strchr(c+1,'-')-c;
                            for(j=1;j<k;j++)
                            {
                                a=a*10+c[j]-'0';
                            }
                            a*=-1;
                            for(j=k+1;j<i;j++)
                            {
                                b=b*10+c[j]-'0';
                            }
                            b*=-1;
                        }
                        else if(strchr(c+1,'+'))
                        {
                            k=strchr(c+1,'+')-c;
                            for(j=1;j<k;j++)
                            {
                                a=a*10+c[j]-'0';
                            }
                            a*=-1;
                            for(j=k+1;j<i;j++)
                            {
                                b=b*10+c[j]-'0';
                            }
                        }
                        else
                        {
                            a=0;
                            for(j=1;j<i;j++)
                            {
                                b=b*10+c[j]-'0';
                            }
                            b*=-1;
                        }
                    }

                    if(c[0]!='-')
                    {
                        if(strchr(c+1,'-'))
                        {
                            k=strchr(c+1,'-')-c;
                            for(j=0;j<k;j++)
                            {
                                a=a*10+c[j]-'0';
                            }
                            for(j=k+1;j<i;j++)
                            {
                                b=b*10+c[j]-'0';
                            }
                            b*=-1;
                        }
                        else if(strchr(c+1,'+'))
                        {
                            k=strchr(c+1,'+')-c;
                            for(j=0;j<k;j++)
                            {
                                a=a*10+c[j]-'0';
                            }
                            for(j=k+1;j<i;j++)
                            {
                                b=b*10+c[j]-'0';
                            }
                        }
                        else
                        {
                            a=0;
                            for(j=0;j<i;j++)
                            {
                                b=b*10+c[j]-'0';
                            }
                        }
                    }
                }
            }
            break;
        }
        else if(i==strlen(c)-1&&c[i]!='i')
        {
            b=0;
            if(c[0]!='-')
            {
                for(j=0;j<i-1;j++)
                {
                    a=a*10+c[j]-'0';
                }
            }
            else if(c[0]=='-')
            {
                for(j=1;j<i-1;j++)
                {
                    a=a*10+c[j]-'0';
                }
                a*=-1;
            }
            break;
        }
    }
    i=0;
    do
    {
        r=(a%2+b%2)%2;
        res[i++]=r+'0';
        qr=(r+b-a)/2;
        qi=(r-b-a)/2;

        a=qr;
        b=qi;
    }while(qr!=0||qi!=0);
    res[i]=0;
    res=strrev(res);

    puts(res);

    free(res);
    return 0;
}
