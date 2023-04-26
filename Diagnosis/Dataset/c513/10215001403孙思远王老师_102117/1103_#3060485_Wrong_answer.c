#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a,b,c,d,i,j;
    char order[100];
    while(gets(order)!='\0')
    {
    if(order[0]=='I')
    {
        int len,n;
        char num[100];
        len=strlen(order);
        for(i=6,j=0;i<len;i++,j++)
        {
            num[j]=order[i];
        }
        num[len-6]='\0';
        n=atoi(num);
        switch(order[3])
        {
            case 'A':a=n;break;
            case 'B':b=n;break;
            case 'C':c=n;break;
            case 'D':d=n;break;
        }
    }
    else if(order[0]=='M'&&order[1]=='O')
    {
        int n;
        switch(order[7])
        {
            case 'A':n=a;break;
            case 'B':n=b;break;
            case 'C':n=c;break;
            case 'D':n=d;break;
        }
        switch(order[4])
        {
            case 'A':a=n;break;
            case 'B':b=n;break;
            case 'C':c=n;break;
            case 'D':d=n;break;
        }
    }
    else if(order[0]=='A')
    {
        int n;
        switch(order[7])
        {
            case 'A':n=a;break;
            case 'B':n=b;break;
            case 'C':n=c;break;
            case 'D':n=d;break;
        }
        switch(order[4])
        {
            case 'A':a+=n;break;
            case 'B':b+=n;break;
            case 'C':c+=n;break;
            case 'D':d+=n;break;
        }
    }
    else if(order[0]=='S')
    {
        int n;
        switch(order[7])
        {
            case 'A':n=a;break;
            case 'B':n=b;break;
            case 'C':n=c;break;
            case 'D':n=d;break;
        }
        switch(order[4])
        {
            case 'A':a-=n;break;
            case 'B':b-=n;break;
            case 'C':c-=n;break;
            case 'D':d-=n;break;
        }
    }
    else if(order[0]=='M'&&order[1]=='U')
    {
        int n;
        switch(order[7])
        {
            case 'A':n=a;break;
            case 'B':n=b;break;
            case 'C':n=c;break;
            case 'D':n=d;break;
        }
        switch(order[4])
        {
            case 'A':a*=n;break;
            case 'B':b*=n;break;
            case 'C':c*=n;break;
            case 'D':d*=n;break;
        }

    }
    else if(order[0]=='D')
    {
        int n;
        switch(order[7])
        {
            case 'A':n=a;break;
            case 'B':n=b;break;
            case 'C':n=c;break;
            case 'D':n=d;break;
        }
        switch(order[4])
        {
            case 'A':a/=n;break;
            case 'B':b/=n;break;
            case 'C':c/=n;break;
            case 'D':d/=n;break;
        }
    }
    else
    {
         switch(order[4])
        {
            case 'A':printf("%d\n",a);break;
            case 'B':printf("%d\n",b);break;
            case 'C':printf("%d\n",c);break;
            case 'D':printf("%d\n",d);break;
        }
    }
    }
    return 0;
}
