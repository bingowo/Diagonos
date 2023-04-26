#include<stdio.h>
#include<math.h>
int main()
{
    int a;
    scanf("%d",&a);
    int str[50],b[50];
    char s[40]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char x[100][100];
    int cnt=0;
    for (int i=0;i<a;i++)
    {
        scanf("%d %d",&str[i],&b[i]);
    }
    for (int y =0;y<a;y++)
    {
        unsigned int c,d;
        c=str[y];
        d=b[y];
        if （c>0)
        {
            while (c!=0)
            {
                x[y][++cnt]=s[c%d];
                c=c/d;
            }
            for (int z=cnt;z>0;z--)
                printf("%c",x[y][z]);
            cnt=0;
            printf("\n");
        }
        else
        {
            c=fabs(c);
            while (c!=0)
            {
                x[y][++cnt]=s[c%d];
                c=c/d;
            }
            printf("-")
            for (int z=cnt;z>0;z--)
                printf("%c",x[y][z]);
            cnt=0;
            printf("\n");
        }
    }
    return 0;
}
