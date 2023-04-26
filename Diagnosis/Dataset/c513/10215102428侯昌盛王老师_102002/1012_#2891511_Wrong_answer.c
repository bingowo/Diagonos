#include <stdio.h>
#include <string.h>
//   qr=(b-a+r)/2;qi=(r-a-b)/2;
int main()
{
	char s[1000];
	int w[1000],k=0;
	scanf("%s",s);
	int len=strlen(s);

	int a,b,qr,qi,r;
	if(len==1) {
		a=(s[0]-'0');
		b=0;
	}
		
	if(len==2){
		a=0-(s[1]-'0');
		b=0;
	}
	
	if(len==3){
		a=s[0]-'0';
		if(s[1]=='-') b=-1;
		else b=1;
	}
	if(len==4)
	{
		if(s[0]=='-'){
			
 			a=0-(s[1]-'0');
			if(s[2]=='-') b=-1;
			if(s[2]=='+') b=1;
		}
		else {
			a=s[0]-'0';
			if(s[1]=='-') b=0-(s[2]-'0');
			else b=s[2]-'0';
		}
		
		
		}
	if(len==5){
		a=0-(s[1]-'0');
		if(s[2]=='-') b=0-(s[3]-'0');
		else b=s[3]-'0';
	}	
	
	qr=a;qi=b;
	if((a+b)%2==0) r=0;
	else r==1;

	w[k]=r;
	

		
	while(qr || qi)	
	{
		qr=(b-a+r)/2;
		qi=(r-a-b)/2;
		//printf("qr=%d\n",qr);
		//printf("qi=%d\n",qi);
		a=qr;b=qi;
		//printf("(=%d\n",(a+b)%2);
		if((a+b)%2==0) r=0;
		else r=1;
		k++;
		w[k]=r;
		//printf("%d\n",w[k]);

		
	}
	int m=k-1;
	for(m;m>=0;m--) printf("%d",w[m]);
	return 0;
}