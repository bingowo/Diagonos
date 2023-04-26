#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i=0,j=0,k;
    char s[32];
    scanf("%s",s);
    int l=strlen(s);
    int m=4*(l-2);
    int x[m];
    for(int z=0;z<m;z++) x[z]=0;
    long long int a;
    long long int b;
    int temp;
    long long int qr=0,qi=0;
    int t=0;
    int r;
    for(i=2;i<l;i++)
    {
        int times=0;
        if(s[i]>'A'&&s[i]<'F') temp=(int)s[i]-55;
        else temp=s[i]-'0';
        t=t+3;
        while(temp!=0)
        {
            x[t--]=temp%2;
            temp=temp/2;
            times++;
        }
        t=t+times+1;
    }
    for(k=0;k<m;k++)
    {
        r=x[k];
        a=-qr-qi+r;
        b=qr-qi;
        qr=a;qi=b;
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
        else{printf("%lld",qi);printf("i\n");}
    }
    return 0;
}

