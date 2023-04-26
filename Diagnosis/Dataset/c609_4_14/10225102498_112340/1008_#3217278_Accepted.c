#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[100]={0};
    while(scanf("%s",a) != EOF)
    {
        int flag=0;
        for(int i=0;i<100;i++)
        {
            if(a[i]=='.')
            {
                flag=1;
                break;
            }
        }
        int b=0;
        double c=0;
        if(flag==0)
        {
            b=atoi(a);
            int *p;
            p= &b;
            unsigned char *p1 =(unsigned char*)p;
            printf("%02x ",*(p1));
            printf("%02x ",*(p1+1));
            printf("%02x ",*(p1+2));
            printf("%02x\n",*(p1+3));
        }
        else if(flag==1)
        {
             c=atof(a);
             double *p;
             p=&c;
             unsigned char *p1=(unsigned char*)p;
            for(int j=0;j<7;j++)
                printf("%02x ",*(p1+j));
            printf("%02x\n",*(p1+7));

        }
        for(int k=0;k<100;k++)
            a[k]=0;
    }
    return 0;
}