#include<stdio.h>
#include<string.h>

int lcf(int a,int b)
{
    int tmp=(a > b) ? a : b;
    while(1)
    {
        if(tmp%a==0 && tmp%b==0) break;
        else tmp++;
    }
    return tmp;
}

int gcd(int a,int b)
{
    int tmp=(a < b) ? a : b;
    for(;tmp>0;tmp--)
    {
        if(a%tmp==0 && b%tmp==0) break;
    }
    return tmp;
}

int get_z(char*s)
{
    int l=strlen(s),num=0;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='/') break;
        else num=num*10+s[i]-'0';
    }
    return num;
}

int get_m(char*s)
{
    int l=strlen(s),num=0,f=0;
    for(int i=0;i<l;i++)
    {
        if(f) num=num*10+s[i]-'0';
        else if(s[i]=='/') f=1;
    }
    return num;
}

int main()
{
    int n;scanf("%d",&n);
    char s[100];scanf("%s",s);
    int res_z=get_z(s),res_m=get_m(s);
    for(int i=1;i<n;i++)
    {
        scanf("%s",s);
        int tmp=lcf(res_m,get_m(s));
        res_z=res_z*(tmp/res_m)+get_z(s)*(tmp/get_m(s));
        res_m=tmp;
    }
    printf("%d/%d",res_z/gcd(res_z,res_m),res_m/gcd(res_z,res_m));

    return 0;
}
