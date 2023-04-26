#include<stdio.h>
#include<stdlib.h>
int main()
{
    char s[100];
    int i=0;
    while(scanf("%s",s)==1)
    {
        for(int i=0;s[i];i++)if(s[i]=='.')break;
        if(s[i])
        {
            double temp1=atof(s);
            for(i=0;i<8;i++)
                printf("%02x ",((unsigned char*)&temp1)[i]);
        }
        else
        {
            int temp2=atoi(s);
            for(i=0;i<4;i++)
                printf("%02x ",((unsigned char*)&temp2)[i]);
        }
        printf("\n");
    }
    return 0;
}
