#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()

{   int a1=0xf,a2=0xff;
    int k=0;
    double j=1.0;
    double b;
    char c;
    char*r;
    char six[16]="0123456789abcdef",s[620];
    while(scanf("%s",s)!=0)
    {
        int l=strlen(s);
        double o;
        k=0;
        b=0.0;
        j=1.0;
        if (strchr(s,'.')!=NULL){
            int q=0;
            if (s[q]=='-') {j=-1.0;q++;}
            while (s[q]!='.')
                b=b*10.0+(s[q++]-'0');
            q=q+1;
            o=0.1;
            while (s[q]!=0)
            {
                b=b+(s[q++]-'0')*o;
                o*=0.1;
            }
            b=b*j;
            r=&b;
            for (int i=0;i<8;i++)
            {
                printf("%c%c%c",six[((int)*r>>4)&a1],six[((int)*(r))&a1],c=i==7?'\n':' ');
                r=r+1;
            }
        }
        else {
            int w=1,a2=0;
            if (s[a2]=='-') {w=-1;a2++;}
            for (int i=a2;i<l;i++)
                k=k*10+s[i]-'0';
            k=k*w;
            for (int i=0;i<4;i++)
            {
                printf("%c%c%c",six[(k>>4)&a1],six[k&a1],c=i==3?'\n':' ');
                k=k>>8;
            }
        }
    }

    return 0;
}
