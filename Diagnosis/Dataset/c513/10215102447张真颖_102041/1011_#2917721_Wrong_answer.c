#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[20]="";
    char t[80]="";
    scanf("%s",s);
    for(int i=2;i<strlen(s);i++)
    {
        char arr[5]="";
        int d=0;
        if(s[i]>='A') d=s[i]-'A'+10;
        else d=s[i]-'0';
        for(int i=0;i<4;i++)
        {
            if((d>>i)&1) arr[3-i]='1';
            else arr[3-i]='0';
        }
        arr[4]=0;
        strcat(t,arr);
    }
    int qr=0,qi=0,a=0,b=0;
    for(int i=0;i<strlen(t);i++)
    {
        a=-qr-qi+t[i]-'0';
        b=qr-qi;
        qr=a;
        qi=b;
    }
    printf("%d",qr);
    if(qi==1) printf("+i");
    else if(qi>1) printf("+%di",qi);
    else if(qi==-1) printf("-i");
    else if(qi<-1) printf("%di",qi);
}
