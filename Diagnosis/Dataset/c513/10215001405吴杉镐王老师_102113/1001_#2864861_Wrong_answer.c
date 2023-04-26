#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a,b,i=0;
    while(i<n)
    {
        i++;
        scanf("%d %d",&a,&b);
        if(a<0)
        {
            printf("-");
            a=-a;
        }
        int k=0;
        char d[32]={'\0'};
        while(a!=0)
        {
            int c=a%b;
            if(c==0 && i==1);
            else if(c<10) d[k]=c+'0';
            else
            {
                d[k]=c+'A'-10;
            }
            k++;
            a=a/b;
        }
        while(k>=0)
        {
            printf("%c",d[k]);
            k--;
        }
        printf("\n");
    }
}
