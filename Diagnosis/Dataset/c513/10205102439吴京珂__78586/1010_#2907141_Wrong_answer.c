#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char n[505];
    scanf("%s",n);

    int len=strlen(n);
    int a[100]= {0};
    int i=0;
    while(len!=0)
    {
        a[i]=len%2;
        len=len/2;
        i++;
    }

    printf("0001");
    for(int i=9;i>=0;i--)
    {
        printf("%d",a[i]);
    }

    len=strlen(n);
    int len1=len-len%3;
    for(int i=0;i<len1;i+=3)
    {
        int b[10]= {0};
        int x=0;
        x=(n[0+i]-48)*100+(n[1+i]-48)*10+n[2+i]-48;
        printf("%d\n",x);
        int j=0;
        while(x!=0)
        {
            b[j]=x%2;
            x=x/2;
            j++;
        }
        for(int k=9; k>=0; k--)
        {
            printf("%d",b[k]);
        }
    }
    
    //if(len%3==1) int y=(n[len-1]-48)
    return 0;
}
