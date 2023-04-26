#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
int main()
{
  	long long int i=0,j,qr=0,qi=0,a=0,b=0,r;
	char* t=(char*)malloc(sizeof(char)*200);
	char*s=(char*)malloc(sizeof(char)*200); 
	memset(s,'\0',200);
	memset(t,'\0',200);
	scanf("0x%s",s);
//	printf("%s\n",s); 
	int k=0;
	for(i=0;i<strlen(s);i++)
	{
//		printf("%c",s[i]);
		int d=0;
		if(s[i]>='A') d=s[i]-'A'+10;
		else d=s[i]-'0';
		unsigned int flag=8;
		while(flag)
		{
			if(flag&d) t[k++]='1';
			else t[k++]='0';
			flag=flag>>1;
		}
	}
//	printf("%s\n",t);
	for(j=0;j<k;j++)
  	{
		r=t[j]-'0';
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
	free(t);
  return 0;
}