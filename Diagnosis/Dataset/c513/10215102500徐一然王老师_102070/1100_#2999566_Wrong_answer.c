#include <stdio.h>
#include<math.h>

int main()
{
    char s[101];
    scanf("%s",s);
    char *p=s;
    int x=0,y=0,sum1;
    while(*p)
    {
        if(*p=='U')y++;
        else if(*p=='D')y--;
        else if(*p=='L')x--;
        else if(*p=='R')x++;
        p++;
    }
    p=s;
    sum1=abs(x)+abs(y);
    printf("%d\n",sum1);
    int count;
    scanf("%d\n",&count);
    while(count--)
    {
        int m,n,sum,x1=0,y1=0,flag=0;
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
        }p=s;x1=0;y1=0;

        sum=abs(m)+abs(n);
        if(sum1!=0)
        {
            x1=x*(sum/sum1);
            y1=y*(sum/sum1);
        }
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
