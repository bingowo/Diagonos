#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    char s[100];
    char a[100];
    scanf("%s",s);
    int len=strlen(s);
    int k=0;
    int h;
    for(int j=0;j<len;j++)
    {
        if(s[j]>='A')
            h=s[j]-'A'+10;
        else
            h=s[j]-'0';
        unsigned int ex=0x8;
        while(ex)
        {
            if(h&ex) a[k++]='1';
            else a[k++]='0';
            ex=ex>>1;
        }
        long long int qr=0,qi=0;
        long long int c,d;
        for(int x=0;x<k;x++)
        {
            int v=a[x]-'0';
            c=-qr-qi+v;
            d=qr-qi;
            qr=c;
            qi=d;
        }
        if(qi==0)
        {
            printf("%lld\n",qr);
        }
        else 
        {
            if(qr!=0)
            {
                printf("%lld",qr);
                if(qi>0) printf("+");
            }
            if(qi==1) printf("i\n");
            else if(qi==-1) printf("-i\n");
            else {printf("%lld",qi);printf("i\n");}
        }
}