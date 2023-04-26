#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
    int a,b,c;
    scanf("%d %d",&a,&c);

    if (a==0) {printf("0"); return 0;}
    b = a%c, a /= c;

    if (b==0)
    {
        int stack[100] = {};
        int m = 0;
        do
        {
            stack[m++] = a%3;
            a /= 3;
        } while (a>0);
        for (int i=0;i<m;i++)
        {
            stack[i]++;
            stack[i+1] += stack[i]/3;
            stack[i] %= 3;
            stack[i]--;
            if (stack[i]==-1) stack[i] = 2;
        }
        int q = (stack[m]==0)?m-1:m;
        for (;q>=0;q--) printf("%d",stack[q]);
        return 0;
    }

    int array[50] = {0,b};
    int pd, check = 3;
    for (pd=1;check!=c;pd++) check *= 3;
    int index = pd;
    do
    {
        array[++index] = a%3;
        a /= 3;
    } while (a>0);
    for (int i=1;i<=index;i++)
    {
        array[i]++;
        array[i+1] += array[i] / 3;
        array[i] %= 3;
        array[i]--;
        if (array[i]==-1) array[i] = 2;
    }

    if (array[index+1]!=0) printf("%d",array[index+1]);
    for (;index>pd;index--) printf("%d",array[index]);
    printf(".");
    int pt = 0;
    while (array[pt++]==0);
    for (;index>=pt-1;index--) printf("%d",array[index]);
    printf("\n");

    return 0;
    
}