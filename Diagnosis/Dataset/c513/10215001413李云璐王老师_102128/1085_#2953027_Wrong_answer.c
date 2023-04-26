#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    char a[510],b[510];
    while(scanf("%s %s",a,b)!=EOF)
    {
        int a1=strlen(a),b1=strlen(b);

        int a2[510]={0},b2[510]={0};
        for(int i=0;i<a1;i++)
            a2[i]=a[a1-i-1]-'0';
        for(int i=0;i<b1;i++)
            b2[i]=b[b1-i-1]-'0';

        int max=(a1>b1)?a1:b1;
        int bit=0,c[510]={0},len=max;
        for(int i=0;i<max;i++)
          {
              a2[i]-=bit;
              if(a2[i]<b2[i]){c[i]=a2[i]+10-b2[i];bit=1;}
              else {bit=0;c[i]=a2[i]-b2[i];}

          }
         for(int i=max-1;i>=0;i--)
            if(c[i]==0) len--;
            else break;

        for(int i=len-1;i>=0;i--)
            printf("%d",c[i]);
            printf("\n");
        if(len==0) printf("0\n");


    }

    return 0;
}
