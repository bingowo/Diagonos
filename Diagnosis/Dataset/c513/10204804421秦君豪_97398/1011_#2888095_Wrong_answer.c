#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
int main()
{
  long long int j,k,qr=0,qi=0,r;
  long long int a=0,b=0;
  char *x[100];
  char*s=(char*)malloc(sizeof(s[0])*10000);
  memset(s,'\0',1000);
  int i =0;
  scanf("%s",&x);
  for (k=2;k<strlen(x);k++)
  {
  	int d;
  	if (x[k]>='A') d=x[k]-'A'+10;
  	else d=x[k]-'0';
  	unsigned int flag =0x8;
  	while (flag)
  	{
  		if(d&flag)s[i++]='1';
  		else s[i++]='0';
  		flag=flag>>1;
	}
  }
//  printf("%s",s);

//  printf("%s\n",s);
  for(j=i-1;j>=0;j--)
  {
  	r=s[j]-48;
  	a=(-qr-qi+r);
  	b=(qr-qi);
  	qr=a;qi=b;
  }
     if(qi==0)     //??,????
    {
        printf("%lld\n",qr);
    }
    else       //??,???
    {
        if(qr!=0)  //???
        {
            printf("%lld",qr);
            if(qi>0) printf("+");
        }
        if(qi==1) printf("i\n");
        else if(qi==-1) printf("-i\n");
        else {printf("%lld",qi);printf("i\n");}
    }

  free(s);
  return 0;
}
