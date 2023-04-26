#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{ char s[32];
  scanf("%s",&s);
  int num=0,i=0;
  long long int R=0;
  int len=strlen(s);
  for(int j=0;s[j]!='.';j++) num++;
  if(num==0)
  for(int m=0;m<len;m++)
    { if(s[m]=='1') R=R+pow(3,len-m-1);
      if(s[m]=='2') R=R-pow(3,len-m-1);
    }
   printf("%lld",R);
   if(num!=0)
   { for(int m=0;m<num;m++)
    { if(s[m]=='1') R=R+pow(3,len-m-1);
      if(s[m]=='2') R=R-pow(3,len-m-1);
    }
     printf("%lld ",R);
    long long int M,N=pow(3,len-num);
    for(int n=0;n<len-num;n++)
    { if(s[n+num+1]=='1') M=M+pow(3,len-num-1);
      if(s[n+num+1]=='2') M=M-pow(3,len-num-1);
    }
   int i,gcd;
     for(i=1; i <= M && i <= N; i++)
    {
            if(N%i==0 && M%i==0)
            gcd = i;
    }
   printf("%lld %lld",M/gcd,N/gcd);
   }
   return 0;
}
