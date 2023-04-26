#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[101];
    scanf("%s",s);
    int t,len=strlen(s);
    scanf("%d",&t);
    while(t--)
    {
        int i,a,b,x=0,y=0,row=0,col=0;
        scanf("%d%d",&a,&b);
        if(a==0&&b==0)
        {
            printf("Yes\n");
            continue;
        }
        for(i=0;i<len;i++)
        {
            if(s[i]=='U')
                row++;
            else if(s[i]=='D')
                row--;
            else if(s[i]=='L')
                col--;
            else
                col++;
        }
        if(row==0&&((col>0&&a>0)||(col<0&&a<0)))
        {
            a%=col;
        }
        else if(col==0&&((row>0&&b>0)||(row<0&&b<0)))
        {
            b%=row;
        }
        else if(((row>0&&b>0)||(row<0&&b<0))&&((col>0&&a>0)||(col<0&&a<0)))
        {
            int m1=0,m2=0;
            m1=b/row;
            m2=a/col;
            if(m1<m2)
            {
                a=a-m1*col;
                b=b-m1*row;
            }
            else
            {
                a=a-m2*col;
                b=b-m2*row;
            }
        }
        if(a==0&&b==0)
        {
            printf("Yes\n");
            continue;
        }
        for(i=0;i<len;i++)
        {
            if(s[i]=='U')
                y++;
            else if(s[i]=='D')
                y--;
            else if(s[i]=='L')
                x--;
            else
                x++;
            if(x==a&&y==b)
            {
                printf("Yes\n");
                break;
            }
        }
        if(i==len)
            printf("No\n");
    }
    return 0;
}
