#include <stdio.h>
#include <string.h>
#define N 50

void adjust(int *a, int i)
{ int carry=0,j,t;
  for (j=i;j>=0;j--)
    a[j]=(t=a[j]+carry)%10, carry=t/10;
}

void solve() 
{  char s[N+2]; 
   int octDigits,dec[N*3]={0},i,j,len; 
   scanf("%s",s); octDigits=strlen(s+2);
   for (i=octDigits-1;i>=0;i--)
   { dec[i*3+2]+=s[i+2]-'0';
     for (j=i*3;j<octDigits*3;j++) dec[j]*=125;
     adjust(dec,octDigits*3-1);
   }
  printf("0.");
  len=3*octDigits;
  for (i=3*octDigits-1;dec[i]==0;i--) len--;
  for (i=0;i<len;i++) printf("%d",dec[i]); printf("\n");
}


int main()
{  int i,t; 
   scanf("%d\n",&t);
   for (i=0;i<t;i++)
   { printf("case #%d:\n",i);
     solve();
   }
   return 0;
}