#include <stdio.h>
#include<math.h>

int main()
{
    char s[101];
    scanf("%s",s);
    char *p=s;
    int x=0,y=0;
    while(*p)
    {
        if(*p=='U')y++;
        else if(*p=='D')y--;
        else if(*p=='L')x--;
        else if(*p=='R')x++;
        p++;
    }
    p=s;
    //printf("%d %d\n",x,y);
    int count;
    scanf("%d\n",&count);
    while(count--)
    {
        int m,n,x1=0,y1=0,flag=0,t1=0,t2=0;
        scanf("%d %d",&m,&n);

        while(*p)
        {
            //printf("%d %d！！%d %d\n",x1,y1,m,n);
            if(x1==m&&y1==n){printf("Yes\n");flag=1;}
            if(*p=='U')y1++;
            else if(*p=='D')y1--;
            else if(*p=='L')x1--;
            else if(*p=='R')x1++;
            p++;
            if(flag==1){break;}
        }p=s;x1=0;y1=0;if(flag==1){continue;}

            if(x!=0)t1=m/x;
            if(y!=0)t2=n/y;
            if(t1>0&&t2>0)
            {
                if(t1>t2)t1=t2;
                else t2=t1;
            }
            if(x!=0&&m/x>0)
            x1=x*t1;
            else x1=x;
            if(y!=0&&n/y>0)
            y1=y*t2;
            else y1=y;
        //printf("%d %d！！%d %d\n",x1,y1,m,n);
        while(*p)
        {
            //printf("%d %d！！%d %d\n",x1,y1,m,n);
            if(x1==m&&y1==n){printf("Yes\n");flag=1;}
            if(*p=='U')y1++;
            else if(*p=='D')y1--;
            else if(*p=='L')x1--;
            else if(*p=='R')x1++;
            p++;
            if(flag==1){break;}
        }p=s;
        if(flag==0){printf("No\n");}
    }

}
