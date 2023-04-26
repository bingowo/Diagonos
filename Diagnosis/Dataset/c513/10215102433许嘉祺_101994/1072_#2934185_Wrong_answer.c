#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char s[100];
int step;
void path(long long x,long long y)
{
    if (x%2==1||x%2==-1)
    {
        if (y==0&&x==1)
            s[step++]='E';
        else if (y==0&&x==-1)
            s[step++]='W';


        else if (((x+y)%4+4)%4==1)
        {

            s[step++]='W';

            path((x+1)/2,y/2);

        }
        else
        {
            s[step++]='E';

            path((x-1)/2,y/2);

        }
    }
    else if (y%2==1||y%2==-1)
    {
        if (x==0&&y==1)
            s[step++]='N';
         else if  (x==0&&y==-1)
            s[step++]='S';


        else if (((x+y)%4+4)%4==3)
        {
            s[step++]='N';

            path(x/2,(y-1)/2);
        }
        else
        {
            s[step++]='S';

            path(x/2,(y+1)/2);
        }
    }
    else printf("\n");
}

int main()
{
    int  x,y;
    scanf("%d%d",&x,&y);
    if (((x%2+2)%2==1&&(y%2+2)%2==1)||((x%2+2)%2==0&&(y%2+2)%2==0&&(x!=0&&x!=0))) printf("-1\n");
    else
    {
        step=0;
        path(x,y);
        printf("%d\n",step);
        s[step]=0;
        printf("%s\n",s);
    }





    return 0;
}
