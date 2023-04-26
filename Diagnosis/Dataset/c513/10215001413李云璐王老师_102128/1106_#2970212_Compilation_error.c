#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

void sub(int x[],int y[],int len1,int len2)//大数减法 
{
 int i;
 for(i=0;i<len1;i++)
 {
  if(x[i]<y[i])
  {
   x[i]=x[i]+10-y[i];
   x[i+1]--;
  }
  else
   x[i]=x[i]-y[i];
 }
 for(i=len1-1;i>=0;i--)//判断减法结束之后，被除数的位数 
 {
  if(x[i])
  { 
   digit=i+1;
   break;     
  } 
 }
}
int judge(int x[],int y[],int len1,int len2)
{
 int i;
 if(len1<len2)
  return -1;
 if(len1==len2)//若两个数位数相等 
 {
  for(i=len1-1;i>=0;i--)
  {
   if(x[i]==y[i])//对应位的数相等 
    continue;
   if(x[i]>y[i])//被除数 大于 除数，返回值为1 
    return 1;
   if(x[i]<y[i])//被除数 小于 除数，返回值为-1 
    return -1;
  }
  return 0;//被除数 等于 除数，返回值为0 
 } 
}

int main()
{
    char s[1100];
    scanf("%s",s);
    int a[100000]={0},b[100000]={0},c[100000],d[100000];
    b[0]=7;b[1]=0;b[2]=[0];b[3]=0;b[4]=0;b[5]=0;b[6]=0;b[7]=0;b[8]=0;b[9]=1;
    a[0]=1;
    int wei=1,yu;
    int n=strlen(s);
    if(n==0) printf("0");
    if(n==1) printf("1");
    if(n==2) {if(s[0]==s[1]) printf("1");else printf("4");}
    if(n>2){
    for(int i=0;i<n;i++)
    {
        if(i==0&&s[i]!=s[i+1])
         {yu=0;
        for(int i=0;i<wei;i++)
    {
        int c=a[i];
        a[i]=(a[i]*2+yu)%10;
        yu=(c*2+yu)/10;
    }
        while(yu>0) {a[wei]=yu;wei++;yu/=10;}}
        else if(i==n-1&&s[i]!=s[i-1])
        {yu=0;
        for(int i=0;i<wei;i++)
    {
        int c=a[i];
        a[i]=(a[i]*2+yu)%10;
        yu=(c*2+yu)/10;
    }
        while(yu>0) {a[wei]=yu;wei++;yu/=10;}}
        if(i!=0&&i!=n-1){
        if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1])
        {
            yu=0;
            for(int i=0;i<wei;i++)
           {
             int c=a[i];
             a[i]=(a[i]*3+yu)%10;
             yu=(c*3+yu)/10;
            }
            while(yu>0) {a[wei]=yu;wei++;yu/=10;}
        }
        if(s[i]==s[i-1]&&s[i]!=s[i+1])
        {
            yu=0;
            for(int i=0;i<wei;i++)
         {
             int c=a[i];
             a[i]=(a[i]*2+yu)%10;
             yu=(c*2+yu)/10;
          }
            while(yu>0) {a[wei]=yu;wei++;yu/=10;}

        }
        if(s[i]==s[i+1]&&s[i]!=s[i-1])
        {
            yu=0;
            for(int i=0;i<wei;i++)
             {
                int c=a[i];
                a[i]=(a[i]*2+yu)%10;
                yu=(c*2+yu)/10;
              }
            while(yu>0) {a[wei]=yu;wei++;yu/=10;}

        }
        if(s[i-1]==s[i+1]&&s[i]!=s[i-1])
            {
                yu=0;
                for(int i=0;i<wei;i++)
                {
                   int c=a[i];
                   a[i]=(a[i]*2+yu)%10;
                   yu=(c*2+yu)/10;
                }
                while(yu>0) {a[wei]=yu;wei++;yu/=10;}

            }
        if(s[i]==s[i-1]&&s[i]==s[i+1]) ;
        }
    }
    int len1=wei,len2=10,len,digit,temp;
    if(len1<len2){for(int i=wei-1;i>=0;i--)
    printf("%d",a[i]);}
    else 
    {
        len=len1-len2;
        len2=len1;
        digit=len1;
        for(int j=0;j<=len;j++)
        {
            c[len-j]=0;
            while(((temp=judge(a,b,len1,len2))>=0)&&digit>=9)
            {
                sub(a,b,len1,len2);
                c[len-j]++;
                len1=digit;
                if(len1<len2&&b[len2-1]==0) len2=len1;
            }
            if(temp<0)
            {
               for(i=1;i<len2;i++)
               y[i-1]=y[i];
               y[i-1]=0;
               if(len1<len2) 
               len2--;                       
            }
        }
        for(int h=len1;h>0;h--)
        {
            if(a[i]) break;
        }
        for(;h>=0;h--)
        printf("%d",a[h];)
        printf("\n");
        }
    }
    return 0;}


