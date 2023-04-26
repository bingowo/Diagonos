#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{
    int a=0,b=0,c=0,d=0;
    int flag=0;int temp=0;
    char x;
    while(1)
    {
        flag=0;
        temp=0;
        x=getchar();
        if(x=='I')
        {
            x=getchar();
            x=getchar();
            x=getchar();
            if(x=='A') flag=1;
            else if(x=='B') flag=2;
            else if(x=='C') flag=3;
            else if(x=='D') flag=4;
            x=getchar();
            x=getchar();
            x=getchar();
            while(isdigit(x))
            {
                temp=temp*10+(x-'0');
                x=getchar();
            }
            if(flag==1) a=temp;
            else if(flag==2) b=temp;
            else if(flag==3) c=temp;
            else if(flag==4) d=temp;
        }
        else if(x=='M')
        {
            x=getchar();
            if(x=='O')
            {
                x=getchar();
                x=getchar();
                x=getchar();
                if(x=='A') flag=1;
                else if(x=='B') flag=2;
                else if(x=='C') flag=3;
                else if(x=='D') flag=4;
                x=getchar();
                x=getchar();
                x=getchar();
                if(x=='A') temp=a;
                else if(x=='B') temp=b;
                else if(x=='C') temp=c;
                else if(x=='D') temp=d;
                if(flag==1) a=temp;
                else if(flag==2) b=temp;
                else if(flag==3) c=temp;
                else if(flag==4) d=temp;
                x=getchar();
            }
            else if(x=='U')
            {
                x=getchar();
                x=getchar();
                x=getchar();
                if(x=='A') flag=1;
                else if(x=='B') flag=2;
                else if(x=='C') flag=3;
                else if(x=='D') flag=4;
                x=getchar();
                x=getchar();
                x=getchar();
                if(x=='A') temp=a;
                else if(x=='B') temp=b;
                else if(x=='C') temp=c;
                else if(x=='D') temp=d;
                if(flag==1) a*=temp;
                else if(flag==2) b*=temp;
                else if(flag==3) c*=temp;
                else if(flag==4) d*=temp;
                x=getchar();
            }
        }
        else if(x=='A')
        {
            x=getchar();
            x=getchar();
            x=getchar();
            x=getchar();
            if(x=='A') flag=1;
            else if(x=='B') flag=2;
            else if(x=='C') flag=3;
            else if(x=='D') flag=4;
            x=getchar();
            x=getchar();
            x=getchar();
            if(x=='A') temp=a;
            else if(x=='B') temp=b;
            else if(x=='C') temp=c;
            else if(x=='D') temp=d;
            if(flag==1) a+=temp;
            else if(flag==2) b+=temp;
            else if(flag==3) c+=temp;
            else if(flag==4) d+=temp;
            x=getchar();
        }
        else if(x=='S')
        {
            x=getchar();
            x=getchar();
            x=getchar();
            x=getchar();
            if(x=='A') flag=1;
            else if(x=='B') flag=2;
            else if(x=='C') flag=3;
            else if(x=='D') flag=4;
            x=getchar();
            x=getchar();
            x=getchar();
            if(x=='A') temp=a;
            else if(x=='B') temp=b;
            else if(x=='C') temp=c;
            else if(x=='D') temp=d;
            if(flag==1) a-=temp;
            else if(flag==2) b-=temp;
            else if(flag==3) c-=temp;
            else if(flag==4) d-=temp;
            x=getchar();
        }
        else if(x=='D')
        {
            x=getchar();
            x=getchar();
            x=getchar();
            x=getchar();
            if(x=='A') flag=1;
            else if(x=='B') flag=2;
            else if(x=='C') flag=3;
            else if(x=='D') flag=4;
            x=getchar();
            x=getchar();
            x=getchar();
            if(x=='A') temp=a;
            else if(x=='B') temp=b;
            else if(x=='C') temp=c;
            else if(x=='D') temp=d;
            if(flag==1) a/=temp;
            else if(flag==2) b/=temp;
            else if(flag==3) c/=temp;
            else if(flag==4) d/=temp;
            x=getchar();
        }
        else if(x=='O')
        {
            x=getchar();
            x=getchar();
            x=getchar();
            x=getchar();
            if(x=='A') printf("%d\n",a);
            else if(x=='B') printf("%d\n",b);
            else if(x=='C') printf("%d\n",c);
            else if(x=='D') printf("%d\n",d);
            break;
        }
    }
    return 0;
}
