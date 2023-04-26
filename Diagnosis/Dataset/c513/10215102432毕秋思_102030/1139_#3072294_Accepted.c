#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int a,m;
    scanf("%d",&a);
    m=a;
    int flag=0,i=1;
    while(flag==0 && i<10000)
    {
        i=i+1;
        m=a*i;
        int x=m,y;
        while(x!=0)
        {
            y=x%10;
            if(y>1)
            {
                flag=0;
                break;
            }
            else if(y==0||y==1) flag=1;
            x/=10;
        }
        if(flag==1)
        {
            printf("%d",m);
            break;
        }
    }
    if(flag==0) printf("-1");
    if(a==0) printf("0");
    return 0;
}

