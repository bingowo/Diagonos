#include <stdio.h>
#include<math.h>
int GCD(int m,int n)

{   int a,b;
    if (m>n)
    {
        a=m;
        m=n;
        n=a;
    }

    if (n%m==0) return m;
    if (n%m!=0) return GCD(n-m,m);
    }
int main(void)
{
    int j;
    char c,str[100];


        int ans = 0;
        j=0;
        int mark=0;
        while((c=getchar())!='\n')
            {
                str[j]=c;
                if(c=='.') mark=j;
                j++;
            }
            j--;
        if(mark==0)
        {
            for(int m=0;m<=j;m++)
            {
                if(str[m]=='2') ans-=pow(3,j-m);
                else ans+=pow(3,j-m)*(str[m]-'0');
            }
            printf("%d",ans);
        }
        else
        {
            int inty=0;
            for(int m=0;m<mark;m++)
            {
                if(str[m]=='2') inty-=pow(3,mark-m-1);
                else inty+=pow(3,mark-m-1)*(str[m]-'0');
            }
            int flt=0;
            for(int m=mark+1;m<=j;m++)
            {
                if(str[m]=='2') flt-=pow(3,j-m);
                else flt+=pow(3,j-m)*(str[m]-'0');
            }
            int sig=1;
            if(flt<=0) sig=-1;
            flt=abs(flt);
            int sum=pow(3,j-mark);
            int div=GCD(flt,sum);
            flt/=div;
            sum/=div;
            if(sig==-1&&inty>0)
            {
                flt=sum-flt;
                inty-=1;
            }
            if(sig==1&&inty<0)
            {
                flt=sum-flt;
                inty+=1;
            }
            if(inty!=0) printf("%d %d %d",inty,flt,sum);
            else printf("%d %d",flt*sig,sum);
        }
        return 0;
}