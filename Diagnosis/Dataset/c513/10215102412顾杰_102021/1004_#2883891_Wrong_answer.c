#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
int main() {
    char s[1000];
    double d;int i,in;
    while(scanf("%s",s)!=-1)
    {
        if(strchr(s,'.'))
        {d=atof(s);
        printf("%f\n",d);
         for(i=0;i<8;i++)printf("%02x ",*((unsigned char*)&d+i));
        }
        else {in=atoi(s);
        for(i=0;i<4;i++)printf("%02x ",*((unsigned char*)&in+i));}
        printf("\n");
    }
    return 0;
}
