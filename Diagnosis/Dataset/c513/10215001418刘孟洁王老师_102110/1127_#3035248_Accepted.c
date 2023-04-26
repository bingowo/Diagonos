#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{int zi,mu;}fen;

int GCD(int m,int n)
{
    if(m%n == 0)return n;
    else if(n%m == 0)return m;
    else if(m > n)m %= n;
    else  n %= m;
    return GCD(m,n);
}

int main()
{
    int n,i,j,tmp;
    char s[107];
    fen val[1007],sum,ans;
    scanf("%d",&n);
    for(i = 0,sum.mu = 1; i < n; i++)
    {
        scanf("%s",s);
        if(!strchr(s,'/')){val[i].zi = atoi(s);val[i].mu = 1;}
        else
        {
            int len = strlen(s);
            for(j = 0,val[i].zi = 0; j < len&&s[j] != '/'; j++)val[i].zi = val[i].zi*10 + s[j]-'0';
            val[i].mu = atoi(s+j+1);
        }
        tmp = GCD(val[i].mu,sum.mu);
        sum.mu = val[i].mu/tmp*sum.mu;
    }
    for(i = 0,sum.zi = 0; i < n; i++)
    {
        val[i].zi *= (sum.mu/val[i].mu);
        sum.zi += val[i].zi;
    }
    tmp = GCD(sum.zi,sum.mu);
    ans.zi = sum.zi/tmp;
    ans.mu = sum.mu/tmp;
    if(!ans.zi)printf("0");
    else printf("%d/%d",ans.zi,ans.mu);
}
