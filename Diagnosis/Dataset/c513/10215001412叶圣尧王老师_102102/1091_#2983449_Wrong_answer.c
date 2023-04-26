#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int a=0,b=0,n;char s[20];
    scanf("%s",s);scanf("%d",&n);
    if(s[strlen(s)-1]!='i'){a=atoi(s);b=0;}
    else
    {
        if(s[0]=='i'){a=0;b=1;}
        else if(s[1]=='i'&&s[0]=='-'){a=0;b=-1;}
        else
        {
            int k=0,q;
            for(int i=0;i<strlen(s)-1;i++)if(!isdigit(s[i])){k++;q=i;}
            if(k==2)
            {
                int sign1=-1,sign2;if(s[q]=='-')sign2=-1;else sign2=1;
                for(int i=1;i<q;i++)
                    a=a*10+s[i]-'0';
                a=a*sign1;
                for(int i=q+1;i<strlen(s)-1;i++)
                    b=b*10+s[i]-'0';
                b=b*sign2;
                if(b==0)b=sign2;
            }
            else if(k==1)
            {
                int sign;if(s[q]=='-')sign=-1;else sign=1;
                if(q==0)
                {
                    for(int i=1;i<strlen(s)-1;i++)
                        b=b*10+s[i]-'0';
                    b=b*sign;
                    a=0;
                }
                else
                 {
                    for(int i=0;i<q;i++)a=a*10+s[i]-'0';
                    for(int i=q+1;i<strlen(s)-1;i++)b=b*10+s[i]-'0';
                    b=b*sign;
                    if(b==0)b=sign;
                 }
            }
            else
            {
                a=0;
                for(int i=0;i<strlen(s)-1;i++)b=b*10+s[i]-'0';
            }
        }
    }
    long long c=a,d=b;
    for(int i=1;i<n;i++)
    {
        c=a*c-b*d;
        d=b*c+a*d;
    }
    if(c==0&&d==0)printf("0");
    else if(c==0)printf("%lldi",d);
    else if(d==0)printf("%lld",c);
    else printf("%d%di",c,d);
}
