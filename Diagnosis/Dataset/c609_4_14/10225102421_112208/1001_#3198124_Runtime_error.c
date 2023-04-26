#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d",&a);
    unsigned int str[a];
    char s[40]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char x[100];
    int cnt=0;
    for (int i=0;i<a;i++)
    {
        scanf("%u %d",&str[i],&b);
        unsigned int c;
        c=str[i];
        if (c==0)
            printf("0\n");
        while (c!=0)
        {
            x[++cnt]=s[c/b];
            c=c/b;
        }
        for (int z=cnt;z>0;z--)
            printf("%c",x[z]);
    }
    return 0;
}
