#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{char s[51]; int i=0,a[128]={0},j;
long long int data[51],sum=0;
scanf("%s",s);
a['I']=1; a['V']=5; a['X']=10; a['L']=50; a['C']=100; a['D']=500;
a['M']=1000;
long long int ans=1,k=0;
while(s[i])
{ switch(s[i])
  {
      case '(': ans=ans*1000;break;
      case ')': ans=ans/1000;break;
      default: data[k++]=ans*a[s[i]];break;
  }
  i++;
}
for(j=0;j<k-1;j++)
{ if (data[j]<data[j+1]) sum-=data[j];
  else sum+=data[j];
}
sum+=data[k-1];
printf("%lld",sum);

}