#include<stdio.h>
#include<stdlib.h>
int main()
{
    int T,n=0;
    char c;
    int i,j;
    int s[4]={0};
    int str[100]={0};
    int r=0,y=0,g=0,b=0;
    scanf("%d",&T);
    c=getchar();
    for(j=0;j<T;j++)
    {
        n=0;
        r=0;
        y=0;
        g=0;
        b=0;
        for(i=0;i<4;i++)
        {
            s[i]=0;
        }
        while((c=getchar())!='\n')
        {
            if(c=='!')
            {
                str[n]=1;
                n++;
            }
            else if(c=='R')
            {
                str[n]=2;
                n++;
            }
            else if(c=='Y')
            {
                str[n]=3;
                n++;
            }
            else if(c=='G')
            {
                str[n]=4;
                n++;
            }
            else if(c=='B')
            {
                str[n]=5;
                n++;
            }
        }
        for(i=0;i<n;i=i+4)
        {
            if((str[i]!=1)&&(i<n))
            {
                s[0]=str[i];
            }
            if((str[i+1]!=1)&&(i+1<n))
            {
                s[1]=str[i+1];
            }
            if((str[i+2]!=1)&&(i+2<n))
            {
                s[2]=str[i+2];
            }
            if((str[i+3]!=1)&&(i+3<n))
            {
                s[3]=str[i+3];
            }
        }
        if((s[0]+s[1]+s[2]+s[3])!=14)
        {
            for(i=0;i<4;i++)
            {
                if(s[i]==0)
                {
                    s[i]=14-(s[0]+s[1]+s[2]+s[3]);
                    break;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            if(str[i]==1)
            {
                if(s[i%4]==2)
                    r++;
                else if(s[i%4]==3)
                    y++;
                else if(s[i%4]==4)
                    g++;
                else if(s[i%4]==5)
                    b++;
            }
        }
        printf("case #%d:\n",j);
        printf("%d %d %d %d\n",r,b,y,g);
    }
    return 0;
}