#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int arr[3];
char s[100];

void init_set()
{
    int i = 0;
    int len = strlen(s);
    int num = 0;
    for(;i < len;i++)
    {
        if(s[i] == 'x' && i != 0)
        {
            arr[0] = num;
            break;
        }
        if(s[0] == 'x')
        {
            arr[0]++;
            break;
        }
        num = num*10 + s[i]-'0';
    }
    num = 0;
    i += 3;
    int flag = 0,sig = 0;
    for(int j = i;j < len;j++)
    {
        if(s[j] == 'x')
        {
            flag = 1;
            break;
        }
    }
    if(s[i] == '-')
    {
        sig = 1;
    }
    i++;
    for(;i < len;i++)
    {
        if(!isdigit(s[i])){
            if(num == 0) num++;
            break;
        }
        num = num*10 + s[i]-'0';
    }
    if(sig) num = num*(-1);
    if(flag == 0)
    {
        arr[1] = 0;
        arr[2] = num;
    }
    else
    {
        arr[1] = num;
        sig = 0;
        i++;
        if(i < len)
        {
            num = 0;
            if(s[i] == '-') sig = 1;
            i++;
            for(;i < len;i++)
            {
                num = num*10 + s[i]-'0';
            }
            if(sig) num = -num;
            arr[2] = num;
        }
    }
}

int GCD(int m,int n)
{
    int mx = m > n ? m : n;
    int mn = m > n ? n : m;
    while(mx % mn)
    {
        int res = mx%mn;
        mx = mn;
        mn = res;
    }
    return mn;
}

int main()
{
    scanf("%s",s);
    init_set();
    if(arr[1] == 0)
    {
        if(arr[2] > 0)
        {
            printf("No Answer!");
        }
        else
        {
            if(((int)sqrt(arr[0]) == sqrt(arr[0])) && ((int)sqrt(-arr[2]) == sqrt(-arr[2])))
            {
                printf("%d %d %d %d",(int)sqrt(arr[0]),-(int)sqrt(-arr[2]),(int)sqrt(arr[0]),(int)sqrt(-arr[2]));
            }
        }
    }
    else if(arr[2] == 0)
    {
        if(arr[1] > 0) printf("1 0 %d %d",arr[0],arr[1]);
        else printf("%d %d 1 0",arr[0],arr[1]);
    }
    else
    {
        int deta = arr[1]*arr[1]-4*arr[0]*arr[2];
        if((int)sqrt(deta) != sqrt(deta)) printf("No Answer!");
        else
        {
            int t = (int)sqrt(deta);
            int fm = 2*arr[0];
            int fz1 = -arr[1]+t;
            int fz2 = -arr[1]-t;
            int fm1 = fm/GCD(abs(fz1),abs(fm));
            fz1 = fz1/GCD(abs(fz1),abs(fm));
            int fm2 = fm/GCD(abs(fz2),abs(fm));
            fz2 = fz2/GCD(abs(fz2),abs(fm));
            if(fm2 > fm1)
            {
                if(fz1 > 0) printf("%d %d ",fm1,fz1);
                else printf("%d %d ",fm1,-fz1);
                if(fz2 > 0) printf("%d %d",fm2,fz2);
                else printf("%d %d",fm2,-fz2);
            }
            else if(fm2 < fm1)
            {
                if(fz2 > 0) printf("%d %d ",fm2,fz2);
                else printf("%d %d ",fm2,-fz2);
                if(fz1 > 0) printf("%d %d",fm1,fz1);
                else printf("%d %d",fm1,-fz1);
            }
            else
            {
                if(fz1*fz2 < 0)
                    printf("%d %d %d %d",fm1,fz1 > 0 ? -fz1 : fz2,fm1,fz1 > 0 ? -fz2 : fz1);
                else
                    printf("%d %d %d %d",fm1,fz1 > fz2 ? fz2 : fz1,fm1,fz1 > fz2 ? fz1 : fz2);
            }
        }
    }
    return 0;
}