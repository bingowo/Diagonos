#include <stdio.h>
int GCD(int a, int b)
{
    if(a%b==0) return b ;
    else return GCD(b,a%b);
}

int main()
{
    char s[200];
    scanf("%s",s);
    int p=0,i;
    for( i=0; s[i]!='.'&&s[i]!=0; i++)
    {
        int temp=s[i]-'0';
        if(temp==0) p=p*3+0 ;
        else if (temp==1) p=p*3+1; 
        else p=p*3-1; 
    }
    int f1=0,f2=1;//分子，分母
    if(s[i]==0) printf("%d",p);//无小数
    else
    {
     for(int j=i+1; s[j]; j++)
     {
      int temp=s[j]-'0';
      if(temp==0) f1=f1*3+0 ; 
      else if(temp==1) f1=f1*3+1;
      else f1=f1*3-1; 
      f2=f2*3;
     }
    }
    if(f1==0&&f2!=1) printf("%d",p);//小数为0，相当于无小数
    else if(f1!=0)
     {
        int best=f1*f2/(GCD(f1,f2));
        f1=f1/best;
        f2=f2/best;
        if(p==0) printf("%d %d",f1,f2);//有且只有小数
        else printf("%d %d %d",p,f1,f2);//整数小数都有
    }
    return 0;
}