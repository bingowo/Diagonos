#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long N2T(long long a) {
    return (a < 9)? a: N2T(a/10)*9 + a%10;	 
}

long long f(long long a) {
    long long d0 = a%10;
    for (long long x = a - d0; x <= a; x++) {	 
        char str[100] = {0};
        sprintf(str, "%lld", x);
        if (x%9 == 0 || strchr(str, '9') != 0) d0--;
    }
    return d0 + 8*N2T(a - a%10)/9;	
}
int main()
{ unsigned long long int n,i,k,j,s,t;
   int a[1000],flag;
   scanf("%llu",&n);
   for(k=n;;k++)
   {s=k;i=0;
  while(k!=0) 
  { a[i]=k%10;
    k=k/10;
    i++;
  }
  flag=0;
  for(j=i-1;i>=0;j--)
   if(a[j]==9) {flag=1; break;}
  if(flag==1) continue;
  if(s%9!=0&&flag==0) {printf("%llu",s);break;}
   }
}



