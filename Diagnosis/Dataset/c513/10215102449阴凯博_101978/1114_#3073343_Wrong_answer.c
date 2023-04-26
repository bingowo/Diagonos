#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[80]={0};
    scanf("%s",s);
    int a=0,b=0,c=0;
    int i=0;
    for (i=0;i<strlen(s);i++)
    {
        if (s[i]=='x')
        {
            if (i==0)
                a=1;
            else
            {
                for (int j=0;j<i;j++)
                   a=a*10+s[j]-'0';
            }
            break;
        }
    }
    int m=i+3,n=0;
    char s1[8]={0};
    char s2[8]={0};
    for (i=m;i<strlen(s);i++)
    {
        if (s[i]=='x')
        {
            for (int j=m;j<i;j++)
                s1[n++]=s[j];
            if (strlen(s1)==1)
            {
                if (s1[0]=='+')
                    b=1;
                else
                    b=-1;
            }
            else
                b=atoi(s1);
            break;
        }
    }
    if (i==strlen(s))
    {
        b=0;
        for (int j=m;j<i;j++)
            s1[n++]=s[j];
        c=atoi(s1);
    }
    else
    {
        if (i==strlen(s)-1)
            c=0;
        else
        {
             n=0;
            for (i=i+1;i<strlen(s);i++)
            {
                s2[n++]=s[i];
                c=atoi(s2);
            }
        }
    }

    int a1,a2,c1,c2;

    if (b==0 && a*c>0)
        printf("No Answer!\n");
    else
    {
        if (c==0)
        {
            if (a%b==0 || b%a==0)
            {
                if (a%b==0 && b%a!=0)
                {
                    if (a/b>b)
                    {
                        a1=b;
                        a2=a/b;
                        c1=0;
                        c2=1;
                    }
                    else
                    {
                        a1=a/b;
                        a2=b;
                        c1=1;
                        c2=0;
                    }
                }
                else
                {
                    a1=1;
                    a2=a;
                    c1=b/a;
                    c2=0;
                    if (a1==a2)
                    {
                        if (c1>c2)
                        {
                            int t=c1;
                            c1=c2;
                            c2=t;
                        }
                    }
                }
                printf("%d %d %d %d\n",a1,c1,a2,c2);
            }
            else
                printf("No Answer!\n");
        }
        else
        {
            int flag=0;
            for (int i=1;i<=a;i++)
            {
                if (a%i==0)
                {
                    if (a/i>i)
                    {
                        a1=i;
                        a2=a/i;
                    }
                    else
                    {
                        a2=i;
                        a1=a/i;
                    }
                }
                if (c>0)
                {
                    for (int j=1;j<=c;j++)
                    {
                        if (c%j==0)
                        {
                            c1=c/j;
                            c2=j;
                            if (a1==a2)
                            {
                                if (c1>c2)
                                {
                                    int t=c1;
                                    c1=c2;
                                    c2=t;
                                }
                            }
                            if ((a1*c2+a2*c1)==b)
                            {
                                flag=1;
                                break;
                            }
                        }
                    }
                }
                if (c<0)
                {
                    for (int j=-1;j>=c;j--)
                    {
                        if (c%j==0)
                        {
                            c1=c/j;
                            c2=j;
                            if (a1==a2)
                            {
                                if (c1>c2)
                                {
                                    int t=c1;
                                    c1=c2;
                                    c2=t;
                                }
                            }
                            if ((a1*c2+a2*c1)==b)
                            {
                                flag=1;
                                break;
                            }
                        }
                    }
                }

                if (flag==1)
                {
                    printf("%d %d %d %d\n",a1,c1,a2,c2);
                    break;
                }

            }
            if (flag==0)
                printf("No Answer!\n");
        }

    }

    return 0;
}
