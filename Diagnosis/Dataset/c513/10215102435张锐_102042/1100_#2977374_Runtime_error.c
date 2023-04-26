#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[200];
    scanf("%s",s);
    int len=strlen(s);
    long long int **p1=(long long int **)malloc(len*sizeof(long long int*));
    for(int i=0;i<len;i++)
    {
        p1[i]=(long long int*)malloc(sizeof(long long int)*2);
    }
    long long int pa=0,pb=0;
    for(int f=0;f<len;f++)
    {
        if(s[f]=='U') pb++;
        if(s[f]=='D') pb--;
        if(s[f]=='L') pa--;
        if(s[f]=='R') pa++;
        p1[f][0]=pa,p1[f][1]=pb;
    }
    long long int x=p1[len-1][0],y=p1[len-1][1];
    long long int n;
    scanf("%lld",&n);
    for(long long int i=0;i<n;i++)
    {
        int bo=0;
        long long int a,b;
        scanf("%lld%lld",&a,&b);
        if(a==0&&b==0) bo=1;
        else
        {
            if(x==0)
            {
                long long int temp=0;
                if(b/y<0) temp=-b/y;
                else temp=b/y;
                b=b-y*temp;
                if(a==0&&b==0) bo=1;
                for(int f=0;f<len;f++)
                {
                    if(a==p1[f][0]&&b==p1[f][1]) {bo=1;break;}
                }
            }
            else if(y==0)
            {
                long long int temp=0;
                if(a/x<0) temp=-a/x;
                else temp=b/y;
                a=a-x*temp;
                if(a==0&&b==0) bo=1;
                for(int f=0;f<len;f++)
                {
                    if(a==p1[f][0]&&b==p1[f][1]) {bo=1;break;}
                }
            }
            else
            {
                long long int temp=a/x;
                a=a-x*temp;b=b-y*temp;
                if(a==0&&b==0) bo=1;
                for(int f=0;f<len;f++)
                {
                    if(a==p1[f][0]&&b==p1[f][1]) {bo=1;break;}
                }
            }
        }
        if(bo==1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
