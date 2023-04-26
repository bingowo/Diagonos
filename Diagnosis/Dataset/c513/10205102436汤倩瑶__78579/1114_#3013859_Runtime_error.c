#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);


}
int main()
{
    char s[100];
    scanf("%s",s);
    int l=strlen(s);
    int a=0,b=0,c=0;
    int i;
    int sum=0;
    int flag=1;
    if(s[0]=='x')a=1;
    else if(s[0]=='-'&&s[1]=='x')a=-1;
    else
    {
        for(i=0; s[i]!='x'; i++)
        {
            if(s[i]=='-')flag=-1;
            else
            {
                a=a*10+s[i]-'0';
            }
        }
        a=flag*a;
    }
    sum=0;
    flag=1;
    i=i+3;
    if(s[i]=='+'&&s[i+1]=='x')b=1;
    else if(s[i]=='-'&&s[i+1]=='x')b=-1;
    else
    {
        for(; s[i]!='x'&&i<l; i++)
        {
            if(s[i]=='-')flag=-1;
            else if(s[i]=='+');
            else
            {
                sum=sum*10+s[i]-'0';
            }
        }
        if(s[i]=='x')
        {
            i=i+1;
            b=flag*sum;
            flag=1;
            sum=0;
            for(; i<l; i++)
            {
                if(s[i]=='-')flag=-1;
                else if(s[i]=='+');
                else
                {
                    sum=sum*10+s[i]-'0';
                }
            }
            c=flag*sum;

        }
        else c=flag*sum;

    }
  //  printf("%d %d %d\n",a,b,c);
    int dalta=b*b-4*a*c;
    if(dalta<0)printf("No Answer!");
    else {
            int gh=(int)(sqrt((double)dalta));
        int ans1=b-gh;
    int ans2=b+gh;
    int ans=2*a;
    int gcd1=gcd(ans1,ans);
    if(gcd1<0)gcd1=-gcd1;
    int gcd2=gcd(ans2,ans);
    if(gcd2<0)gcd2=-gcd2;
    if(gcd1>gcd2)
    printf("%d %d %d %d",ans/gcd1,ans1/gcd1,ans/gcd2,ans2/gcd2);
    else if(gcd1<gcd2)
    printf("%d %d %d %d",ans/gcd2,ans2/gcd2,ans/gcd1,ans1/gcd1);
    else{
        if(ans1<=ans2)printf("%d %d %d %d",ans/gcd1,ans1/gcd1,ans/gcd2,ans2/gcd2);
            else    printf("%d %d %d %d",ans/gcd2,ans2/gcd2,ans/gcd1,ans1/gcd1);

    }


    }

}
