#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int a=0,b=0;
    int negative=0;
    char s[50];
    scanf("%s",s);
    int i;
    int flag=0;
    int tag1=1,tag2=0;
    for(i=0;i<strlen(s);i++)
    {
       if(s[i]=='i')
        {
            if(i==0)
            {
                b=1;
            }
            else{tag2=1;}
            break;
        }

        else if(s[i]=='-'&&i==0)
        {
            negative=1;
            if(s[i+1]=='i')
            {
                a=1;
            }
        }
        else if(s[i]=='+'||s[i]=='-')
        {
            if(negative)
            {
                a=-a;
            }
            flag=1;
            tag1=0;
            if(s[i+1]=='i')
            {
                b=1;
            }
            if(s[i]=='+')
            {
                negative=0;
            }
            else if(s[i]=='-')
            {
                negative=1;
            }
        }
        else if(!flag)
        {
            a=a*10+(s[i]-'0');
        }

        else if(flag)
        {
            b=b*10+(s[i]-'0');
        }

    }
    if(!flag&&negative)
    {
        a=-a;
    }
    else if(negative)
    {
        b=-b;
    }
    if(tag1&&tag2)
    {
        b=a;
        a=0;
    }
    //printf("%lld %lld\n",a,b);
    char result[1000001];
    long long count=0;
    long long int qr,qi;
     int r;
    do{
        if((a%2==0&&b%2==0)||(a%2!=0&&b%2!=0))
        {
            r=0;
            //printf("0\n");
        }
        else{
            r=1;
            //printf("1\n");
        }
        result[count++]=r+'0';
        //printf("%c ",result[count-1]);
        qi=(r-a-b)/2;
        qr=b+qi;
        a=qr;
        b=qi;
      }while(a!=0||b!=0);
      for(i=count-1;i>=0;i--)
      {
          printf("%c",result[i]);
      }
      printf("\n");

    return 0;
}