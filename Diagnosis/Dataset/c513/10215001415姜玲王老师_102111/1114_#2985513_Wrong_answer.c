#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
int gcd(int a,int b)
{
    if(a%b) return(b,a%b);
    else return b;
}
int main()
{
    int k=0,num,a,b,c,detal,p1,p2,q1,q2;
    char s[20];
    scanf("%s",s);
    while(k<strlen(s))
   {   num=0;
       if(s[k]>='0'&&s[k]<='9')
       {
        for(;s[k]>='0'&&s[k]<='9';k++)
        num=num*10+s[k]-'0';
        a=num;k+=3;continue;
        }

        if(s[k]=='x')
            {a=1;k+=3;continue;}
        if(s[k]=='+')
        {   k++;
            if(s[k]=='x')
            {k++;b=1;continue;}
            for(;s[k]>='0'&&s[k]<='9';k++)
            {num=num*10+s[k]-'0';}
            if(k==strlen(s)){c=num;continue;}
            if(s[k]=='x'){k++;b=num;continue;}
        }
       if(s[k]=='-')
        {
            k++;
            if(s[k]=='x')
            {k++;
             if(s[k]=='^')
                {k++;
                if(s[k]=='2'){a=-1;k++;continue;}}
            else{b=-1;continue;}}
            for(;s[k]>='0'&&s[k]<='9';k++)
            {num=num*10+s[k]-'0';}
            if(k==strlen(s)){c=-num;continue;}
            if(s[k]=='x')
            {k++;
             if(s[k]=='^')
                {k++;
                if(s[k]=='2'){a=-num;k++;continue;}}
            else{b=-num;continue;}}
            }
   }
   detal=a*a-4*b*c;
   double x=sqrt(detal);
   int y=(int) x,l1,l2;
   if(detal<0) printf("No Answer!");
   if(x!=(int)x) printf("No Answer!");
   p1=y-b;
   q1=2*a;
   p2=-y-b;
   q2=2*a;
   l1=gcd(p1,q1);
   l2=gcd(p2,q2);
   p1/=l1;
   q1/=l1;
   p2/=l2;
   q2/=l2;
   if(q1>q2) printf("%d %d %d %d",q2,p2,q1,p1);
   if(q1<q2) printf("%d %d %d %d",q1,p1,q2,p2);
   if(q1==q2&&p1>p2) printf("%d %d %d %d",q2,p2,q1,p1);
   if(q1==q2&&p1<=p2) printf("%d %d %d %d",q1,p1,q2,p2);



}
