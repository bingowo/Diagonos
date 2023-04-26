#include <stdio.h>
#include <stdlib.h>

int h[2001] = {};
int fz[2001] = {};
int fm[2001] = {};
int ls,rs;
int lres,rres;

int gcd(int m,int n)
{
    if (n>m) {m^=n; n^=m; m^=n;}
    if (m%n==0) return n;
    else return gcd(n,m%n);
}

int deall(int p)
{
    int ll = p;
    while (h[ll-1]<=h[ll]) ll--;
    int lv = 0; int lr = ll;
    while (h[lr]==h[lr+1]) lr++;
    int high = h[ll-1]<h[lr+1]?h[ll-1]:h[lr+1];
    int delta = high-h[ll];
    lv = delta*(lr-ll+1);
    if (ls>=lv)
    {
        for (int i=ll;i<=lr;i++) h[i] = high;
        ls -= lv;
        return ls;
    } 
    else
    {
        int temp = ls/(lr-ll+1);
        for (int i=ll;i<=lr;i++)
        {
            h[i] += temp;
            int temp2 = ls-temp*(lr-ll+1);
            if (lres==1)
            {
                fz[i] = temp2*2+1;
                fm[i] = 2*(lr-ll+1);
            }
            else
            {
                fz[i] = temp2;
                fm[i] = lr-ll+1;
            }
            if (fz[i])
            {
                int f = gcd(fz[i],fm[i]);
                fz[i] /= f; fm[i] /= f;
            }
        }
        lres = 0;
        return 0;
    }
}

int dealr(int p)
{
    int rr = p;
    while (h[rr+1]<=h[rr]) rr++;
    int rv = 0; int rl = rr;
    while (h[rl]==h[rl-1]) rl--;
    int high = h[rr+1]<h[rl-1]?h[rr+1]:h[rl-1];
    int delta = high-h[rr];
    rv = delta*(rr-rl+1);
    if (rs>=rv)
    {
        for (int i=rr;i>=rl;i--) h[i] = high;
        rs -= rv;
        return rs;
    }
    else
    {
        int temp = rs/(rr-rl+1);
        for (int i=rr;i>=rl;i--)
        {
            h[i] += temp;
            int temp2 = rs-temp*(rr-rl+1);
            if (rres==1)
            {
                fz[i] = temp2*2+1;
                fm[i] = 2*(rr-rl+1);
            }
            else
            {
                fz[i] = temp2;
                fm[i] = rr-rl+1;
            }
            if (fz[i])
            {
                int f = gcd(fz[i],fm[i]);
                fz[i] /= f; fm[i] /= f;
            }
        }
        rres = 0;
        return 0;
    }
}

int main()
{
    int n,s,p;
    scanf("%d %d %d",&n,&s,&p);
    h[0] = h[n+1] = 1e7;
    for (int i=1;i<=n;i++) scanf("%d",&h[i]);
    while (s>0)
    {
        int l=p,r=p;
        int lv = 0, rv = 0;
        while (h[l-1]<=h[p]) {l--; lv += h[p]-h[l];}
        while (h[r+1]<=h[p]) {r++; rv += h[p]-h[r];}
        if (lv+rv==0)
        {
            int high = h[r+1]>=h[l-1]? h[l-1]: h[r+1];
            if ((r-l+1)*(high-h[p])<=s)
            {
                s -= (r-l+1)*(high-h[p]);
                for (int i=l;i<=r;i++) h[i] = high;
            }
            else
            {
                int temp = s/(r-l+1);
                for (int i=l;i<=r;i++)
                {
                    h[i] += temp;
                    fz[i] = s%(r-l+1); 
                    fm[i] = r-l+1;
                    if (fz[i])
                    {
                        int f = gcd(fz[i],fm[i]);
                        fz[i] /= f, fm[i] /= f;
                    }
                }
                s = 0;
            }
        }
        else if (s>=lv+rv)
        {
            for (int i=l;i<=r;i++) h[i] = h[p];
            s -= lv+rv;
        }
        else if (s<lv+rv)
        {   
            if (rv==0) ls = s;
            else if (lv==0) rs = s;
            else if (s/2>=lv)
            {
                ls = lv;
                rs = s-ls;
            }
            else if (s/2>=rv)
            {
                rs = rv;
                ls = s-rs;
            }
            else
            {
                ls = rs = s/2;
                if (s&1) lres = rres = 1;
            }
            s = 0;
            while (ls>0||lres) ls = deall(p);
            while (rs>0||rres) rs = dealr(p);
        }
    }
    for (int i=1;i<=n;i++)
    {
        printf("%d%c",h[i],fz[i]?'+':' ');
        if (fz[i]) printf("%d/%d ",fz[i],fm[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}