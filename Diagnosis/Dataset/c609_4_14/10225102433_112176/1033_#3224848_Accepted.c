#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 100010

int f[N];
int k;

void put(int n)
{
    int tmp[10];
    int cnt =0;
    while(n)
    {
        tmp[cnt++] = (n&1);
        n = n>>1;
    }
    if(cnt < 8)
    {
        int res = 8-cnt;
        while(res--) f[k++] = 0;
        while(cnt--) f[k++] = tmp[cnt];
    }
}

void cputs(int b,int e)
{
    int sum = 0;
    for(int i = e;i >= b;i--) sum += (int)pow(2,e-i)*f[i];
    char A = 'A',a = 'a';
    if(sum <= 25) printf("%c",A+sum);
    else if ((sum >= 26) && (sum <= 51)) printf("%c",a+sum-26);
    else if((sum > 51) && (sum <= 61)) printf("%d",sum-52);
    else
    {
        if(sum == 62) printf("%c",'+');
        else printf("%c",'/');
    }
}

int main()
{
    int n;scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        int cnt = 0;
        printf("case #%d:\n",i);
        char s[110] = {0};
        scanf("%s",s);
        for(int j = 0;j < strlen(s);j++) put(s[j]);
        if(k%6 != 0)
        {
            k = (k/6+1)*6;
        }
        for(int j = 0;j < k;j += 6,cnt++) cputs(j,j+5);
        if(cnt % 4 != 0)
        {
            int res = (cnt/4+1)*4-cnt;
            while(res--) printf("=");
        }
        printf("\n");
        memset(f,0,sizeof(f));
        k = 0;
    }
    return 0;
}