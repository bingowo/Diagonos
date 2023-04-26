#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[20][50]={0};
    int i=0,n;
    while (scanf("%s",s[i])!=EOF)
        i++;
    n=i;
    for (i=0;i<n;i++)
    {
        char s1[40]={0};
        sscanf(s[i],"f(x)=%s",s1);
        int xy[41][41]={0};
        int c3=0,c2=0,c1=0,c0=0;
        for (int a=0;a<strlen(s1);a++)
        {
            if (s1[a]=='x')
            {
                if (a==strlen(s1)-1)
                {
                    char c[20]={0};
                    int j,k,l;
                    for (j=a-1;j>0 && !ispunct(s1[j]);j--);
                    for (k=j,l=0;s1[k]!='x';k++,l++)
                        c[l]=s1[k];
                    c1=atoi(c);
                }
                else
                {
                    if (s1[a+1]=='^')
                    {
                        if (s1[a+2]=='2')
                        {
                            if (a==0)
                                c2=1;
                            else
                            {
                                char c[20]={0};
                                int j,k,l;
                                for (j=a-1;j>0 && !ispunct(s1[j]);j--);
                                for (k=j,l=0;s1[k]!='x';k++,l++)
                                    c[l]=s1[k];
                                if (ispunct(s1[a-1]))
                                    c[1]='1';
                                c2=atoi(c);
                            }
                        }
                        if (s1[a+2]=='3')
                        {
                            if (a==0)
                                c3=1;
                            else
                            {
                                char c[20]={0};
                                int j,k,l;
                                for (j=a-1;j>0 && !ispunct(s1[j]);j--);
                                for (k=j,l=0;s1[k]!='x';k++,l++)
                                    c[l]=s1[k];
                                if (ispunct(s1[a-1]))
                                    c[1]='1';
                                c3=atoi(c);
                            }
                        }
                    }
                    else
                    {
                        if (a==0)
                            c1=1;
                        else
                        {
                            char c[20]={0};
                            int j,k,l;
                            for (j=a-1;j>0 && !ispunct(s1[j]);j--);
                            for (k=j,l=0;s1[k]!='x';k++,l++)
                                c[l]=s1[k];
                            if (ispunct(s1[a-1]))
                                c[1]='1';
                            c1=atoi(c);
                        }

                    }
                }
            }
            else if (a==strlen(s1)-1)
            {
                if (a>0)
                {
                    if (s1[a-1]!='^')
                    {
                        char c[20]={0};
                        int j,k,l;
                        for (j=a-1;j>0 && !ispunct(s1[j]);j--);
                        for (k=j,l=0;k<strlen(s1);k++,l++)
                            c[l]=s1[k];
                        c0=atoi(c);
                    }
                }
            }

        }
        if (strchr(s1,'x')==NULL)
        {
            c0=atoi(s1);
        }
        for (int x=-20;x<=20;x++)
        {
            int y=c3*(x*x*x)+c2*(x*x)+c1*x+c0;
            if (y>=-20 && y <=20)
                xy[x+20][y+20]=1;
        }
        for (int y=40;y>=0;y--)
        {
            for (int x=0;x<=40;x++)
            {
                if (xy[x][y]==0)
                {
                    if (x==20 && y!=20)
                    {
                        if (y==40)
                            printf("^");
                        else
                            printf("|");
                    }
                    else if (y==20)
                    {
                        if (x==20 )
                            printf("+");
                        else if (x==40)
                            printf(">\n");
                        else
                            printf("-");
                    }
                    else if (x==40)
                        printf("\n");
                    else
                        printf(".");
                }
                else
                {
                    printf("*");
                    if (x==40)
                        printf("\n");
                }
            }
        }
        if (i!=n-1)
            printf("\n");
    }

    return 0;
}
