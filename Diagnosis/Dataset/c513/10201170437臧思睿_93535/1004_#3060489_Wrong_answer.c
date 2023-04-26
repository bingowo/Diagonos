#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,flag=0;
    char a[100];
    while (scanf("%s",a)!=EOF)
    {
        for(i=0;i<strlen(a);i++)
        {
            if(a[i]=='.')
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            double x=atof(a);
            int p=sizeof(x);
            unsigned char *m=(unsigned char *)&x;
            while(p--)
            {
                printf("%02x ",*m++);
            }
        }
        else
        {
            int x=atoi(a);
            int p=sizeof(x);
            unsigned char *m=(unsigned char *)&x;
            while(p--)
            {
                printf("%02x ",*m++);
            }
        }
        printf("\n");
    }
    return 0;
}
