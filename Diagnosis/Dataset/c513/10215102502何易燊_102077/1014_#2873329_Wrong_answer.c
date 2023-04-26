#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main()
{
    int a,b,c;
    scanf("%d %d",&a,&c);
    int z[1000] = {};
    b = a%c, a /= c;

    int stack[100] = {};
    int m = 0;
    do
    {
        stack[m++] = a%3;
        a /= 3;
    } while (a>0);
    int rec = m;

    if (b==0)
    {
        for (int i=0;i<rec;i++)
        {
            stack[i]++;
            stack[i+1] += stack[i]/3;
            stack[i] %= 3;
            stack[i]--;
            if (stack[i]==-1) stack[i] = 2;
        }
        int q = (stack[m]==0)?m-1:m;
        for (;q>=0;q--) printf("%d",stack[q]);
        system("pause");
        return 0;
    }

    int k;
    for (k=0;(int)pow(3,k)!=c;k++) ;
    int sum = m+k;
    int h[30] = {0};
    h[k] = b;
    int p;
    for (p=k;p>0;p--)
    {
        h[p-1] = h[p]/3;
        h[p] %= 3;
    }

    int s[50] = {};
    int index = 1;
    while (m>0) s[index++] = stack[--m];
    for (p++;p<=k;p++) s[index++] = h[p];
    for (int i=index-1;i>0;i--)
    {
        s[i]++;
        s[i-1] += s[i]/3;
        s[i] %= 3;
        s[i]--;
        if (s[i]==-1) s[i] = 2;
    }

    for (int i=1;i<rec+1;i++) printf("%d",s[i]);
    printf(".");
    for (int i=rec+1;i<sum+15;i++) printf("%d",s[i]);

    system("pause");
    return 0;
    
}