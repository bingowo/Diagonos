#include <stdio.h>

int num(int num);

int main()
{
    int t, n, r, i = 0, cnt;
    scanf("%d",&t);

    int a[100];

    for(int j = 0; j < t; j++)
    {
        scanf("%d %d",&n,&r);
        if(n<0) printf("-");
        n>0?n:-n;
        do
        {
            a[i++] = num(n%r);
            n = n/r;
        }
        while(n != 0);

        cnt = i;

        for(i=cnt - 1; i > 0; i-- ) printf("%c",a[i]);
        printf("%c\n",a[0]);


    }

    return 0;

}

int num(int num)
{
    if(num >=0 && num <=9)  return num + 48;
    if(num >=10 && num <=35) return num + 55;
}
