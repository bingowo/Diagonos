#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
int main()
{
  long long int i=0,j,qr=0,qi=0,a=0,b=0,r;
  long long int x;
  char*s=(char*)malloc(sizeof(s[0])*1000);
  memset(s,'\0',1000);
  scanf("%x",&x);
//  printf("%d\n",x);
//  i=0;
  while(x!=0)
  {
  	s[i++]=(x&1)+'0';
//  	printf("%c",s[i-1]);
  	x=(unsigned int )x>>1;
  }
  for(j=i-1;j>=0;j--)
  {
  	r=s[j]-48;
  	a=(-qr-qi+r);
  	b=(qr-qi);
  	qr=a;qi=b;
  }
  if(qi>0&&qr!=0) printf("%lld+%lldi",qr,qi);
  else if(qi<0&&qr!=0) printf("%lld%lldi",qr,qi);
  else if(qi==0) printf("%lld",qr);
  else if(qr==0) printf("%lldi",qi);
  free(s);
  return 0;
}
