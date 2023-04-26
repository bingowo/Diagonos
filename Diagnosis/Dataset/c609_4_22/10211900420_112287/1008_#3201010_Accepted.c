#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    unsigned int y;
    int z16,y16,fl,flag,i,len;
    double z;
    unsigned long long j;
    flag=1;
    char x[100];
    while(scanf("%s",&x)!=EOF)
    {
        fl=1;
        len=strlen(x);
        for(i=0;i<len;i++)
        {
            if(x[i]=='.')
            {
                fl=2;
            }
        }
        if(fl==1)
        {
            y=(unsigned int)atoi(x);
            for(i=0;i<4;i++)
            {
                y16=y&(255);
                y=y>>8;
                printf("%02x ",y16);
            }
            printf("\n");
        }
        else
        {
            z=atof(x);
            j=*(unsigned long long*)&z;
            for(i=0;i<8;i++)
            {
                z16=j&(255);
                j=j>>8;
                printf("%02x ",z16);
            }
            printf("\n");
        }

    }
    return 0;
}
