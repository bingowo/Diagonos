#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 100000

int ansm;
int ansn;
int x,y;
int m[N];
int n[N];

int find(int a,int b)
{
    int sum = a+b;
    a = a > b ? a : b;
    b = sum-a;
    if(b == 0) return 1;
    while(a % b)
    {
        int res = a%b;
        a = b;
        b = res;
    }
    return b;
}

void reverse(int *a)
{
    int res = ansm/2;
    for(int i = 0;i < res;i++)
    {
        int tmp  = a[i];
        a[i] = a[ansm-1-i];
        a[ansm-1-i] = tmp;
    }
}

void put(int num)
{
    while(num)
    {
        m[ansm++] = num%3;
        num /= 3;
    }
}

void dput(int a,int b)
{
    for(int i = 1;;i++)
    {
        if(a == 0) break;
        int res = (int)pow(3,i);
        int times = b/res;
        if(a < times)
        {
            n[ansn++] = 0;
        }
        else if(a == times)
        {
            n[ansn++] = times;
            break;
        }
        else
        {
            n[ansn++] = a/times;
            a -= (a/times)*times;
        }
    }
//    ansn--;
}

int main()
{
//    dput(5,9);
//    for(int i = 0;i < ansn;i++) printf("%d ",n[i]);
    scanf("%d %d",&x,&y);
    int tmp = find(x,y);
    x /= tmp;
    y /= tmp;
    if(x == 0)
    {
        printf("0");
        return 0;
    }
    if(x == y){
        printf("1");
    }
    else if(x > y){
        if(x % y == 0)
        {
            put(x/y);
            for(int i = 0;i < ansm;i++)
            {
                int res = m[i]+1;
                m[i] = res%3;
                if(res >= 3)
                {
                    m[i+1]++;
                }
                else
                {
                    continue;
                }
            }
            int fu = 0;
            if(m[ansm] != 0)
            {
                ansm++;
                fu = 1;
            }
            if(fu) ansm--;
            for(int i = 0;i < ansm;i++)
            {
                m[i]--;
                if(m[i] == -1) m[i] = 2;
            }
            if(fu) ansm++;
            reverse(m);
            for(int i = 0;i < ansm;i++) printf("%d",m[i]);
        }
        else
        {
            int a = x/y;
            put(a);
//            for(int i = 0;i < ansm;i++) printf("%d~",m[i]);
            x -= a*y;
            dput(x,y);
//            printf("%d\n",ansn);
//            for(int i = 0;i < ansn;i++) printf("%d ",n[i]);
            int flag = 0;
            for(int i = ansn-1;i >= 0;i--)
            {
                int res = n[i]+1;
                n[i] = res%3;
                if(res >= 3)
                {
                    if(i != 0)
                    {
                        n[i-1]++;
                    }
                    else
                    {
                        flag = 1;
                    }
                }
                else
                {
                    continue;
                }
            }
            for(int i = 0;i < ansm;i++)
            {
                if(flag)
                {
                    m[i]++;
                    flag = 0;
                }
                int res = m[i]+1;
                m[i] = res%3;
                if(res >= 3)
                {
                    m[i+1]++;
                }
                else
                {
                    continue;
                }
            }
            int fu = 0;
            if(m[ansm] != 0)
            {
                ansm++;
                fu = 1;
            }
            if(fu) ansm--;
            for(int i = 0;i < ansm;i++)
            {
                m[i]--;
                if(m[i] == -1) m[i] = 2;
            }
            if(fu) ansm++;
            reverse(m);
            for(int i = 0;i < ansm;i++) printf("%d",m[i]);
            printf(".");
            for(int i = 0;i < ansn;i++)
            {
                n[i]--;
                if(n[i] == -1) n[i] = 2;
                printf("%d",n[i]);
            }
        }
    }
    else
    {
        dput(x,y);
//        printf("%d\n",ansn);
//        for(int i = 0;i < ansn;i++) printf("%d ",n[i]);
        int flag = 0;
        for(int i = ansn-1;i >= 0;i--)
        {
            int res = n[i]+1;
            if(res >= 3)
            {
                n[i] = (n[i]+1)%3;
                if(i == 0)
                {
                    flag = 1;
                }
                else
                {
                    n[i-1]++;
                }
            }
            else
            {
                n[i]++;
            }
        }
        if(flag)
        {
            printf("1.");
        }
        else
        {
            printf("0.");
        }
        for(int i = 0;i < ansn;i++)
        {
            if(n[i]-1 == -1)printf("2");
            else printf("%d",n[i]-1);
        }
    }
}