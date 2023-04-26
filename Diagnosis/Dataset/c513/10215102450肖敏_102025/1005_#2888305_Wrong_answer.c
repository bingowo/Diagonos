#include <stdio.h>
#include <string.h>

int main()
{
    int T,i,j,t,n,len,d;
    char Octal[55], decimal[155];

    scanf("%d",&T);
    for(i = 0;i < T;i ++)
    {
        scanf("%s",Octal);
        n = 0;
        len = strlen(Octal) - 1;
        for (; len != 1; --len)
        {
            d = Octal[len] - '0';
            j = 0;
            do {
                if (j < n)
                    t = d*10 + decimal[j] - '0';
                else
                t = d*10;
                decimal[j++] = t / 8 + '0';
                d = t%8;
            } while (d!=0 || j < n);
            n = j;
        }
        decimal[n] = '\0';
        printf("case #%d:\n",i);
        printf("0.");
        for(j = 0;j < n; j ++)
            printf("%d",decimal[j] - '0');
    }
    return 0;
}
