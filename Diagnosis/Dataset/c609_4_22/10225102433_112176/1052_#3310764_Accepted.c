#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

char s[1010];
int prime[30];
int ch[1010];
int qz[1010];
int tmp[1010];
int atmp[1010];
int ans[1010];
int cnt;
int lenq,lent,lena;

int check(int num)
{
    if(num == 1) return 0;
    else if(num == 2) return 1;
    else
    {
        int k = (int)sqrt(num)+1;
        for(int i = 2;i <= k;i++){
            if(num%i == 0) return 0;
        }
        return 1;
    }
}

void init_set_prime()
{
    int cnt = 0;
    for(int i = 2;i;i++)
    {
        if(check(i)){
            prime[cnt++] = i;
        }
        if(cnt == 30) break;
    }
}

void solve()
{
    int len = strlen(s);
    int num = 0;
    for(int i = 0;i < len;i++)
    {
        if(isdigit(s[i]))
        {
            num = num*10 + s[i]-'0';
        }
        else
        {
            ch[cnt++] = num;
            num = 0;
        }
    }
    ch[cnt++] = num;
}

void QZ(int p)
{
    int t = 0;
    for(int i = 0;i < lenq;i++)
    {
        t += qz[i]*p;
        tmp[i] = (t%10);
        t /= 10;
    }
    while(t)
    {
        tmp[lenq++] = t%10;
        t /= 10;
    }
    for(int i = 0;i < lenq;i++) qz[i] = tmp[i];
    memset(tmp,0,sizeof(tmp));
}

void gather(int num)
{
    int t = 0;
    for(int i = 0;i < lenq;i++)
    {
        t += qz[i]*num;
        tmp[lent++] = t%10;
        t /= 10;
    }
    while(t)
    {
        tmp[lent++] = t%10;
        t /= 10;
    }
}

void plus()
{
    int l = lent > lena ? lent : lena;
    int t = 0;
    for(int i = 0;i < l;i++)
    {
        t = t+ans[i]+tmp[i];
        atmp[i] = t % 10;
        t /= 10;
    }
    if(t)
    {
        atmp[l++]++;
    }
    lena = l;
    for(int i = 0;i < l;i++) ans[i] = atmp[i];
    memset(atmp,0,sizeof(atmp));
    lent = 0;
    for(int i = lena-1;lena > 1;i--)
    {
        if(ans[i] == 0) lena--;
        else break;
    }
}

int main()
{
    init_set_prime();
    scanf("%s",s);
    solve();
    qz[lenq++] = 1;
    for(int i = cnt-1,j = 0;i >= 0;i--,j++)
    {
        gather(ch[i]);
        plus();
        QZ(prime[j]);
    }
    for(int i = lena-1;i >= 0;i--) printf("%d",ans[i]);
    return 0;
}