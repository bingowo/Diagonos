#include<stdio.h>
#include<string.h>
int	num(char s[]){
	int sign=1,i=0,num=0;
	if(s[0]=='-'){
		sign=-1;
		i++;
	}
	if(s[0]=='+'){
		i++;
	}
	for(;i<strlen(s);i++){
		num=num*10+s[i]-'0';	
	}
	//printf("%d\n",sign*num);
	return sign*num;
}
int main()
{
	char s[100];
	scanf("%s",s);
	char A[50];
	char B[50];
	int i=0;
	int a,b;
	for(;i<strlen(s);i++){
		
		if(i>0&&(s[i]=='+'||s[i]=='-'))
			break;
		A[i]=s[i];	
		if(s[i]=='i'){
			a=0,A[0]=0,i=0;
			break;
		}
			
	}
	A[i]='\0';
	if(A[0]!=0)
		a=num(A);
	if(i==strlen(s))
		b=0,B[0]=0;
	int j=0;
	for(;i<strlen(s);i++,j++){
			
		if(s[i+1]=='i'&&(s[i]=='+'||s[i]=='-'))
			if(s[i]=='+'){
				b=1,B[0]=0;
				break;
			}				
			if(s[i]=='-'){
				b=-1,B[0]=0;
				break;
			}			
		
		if(s[i]=='i')
			break;
		B[j]=s[i];	
	}
	B[j]='\0';
	if(B[0]!=0)
		b=num(B);
	//printf("%d %d\n",a,b);
	int qr,qi,r=1,ret[1000];
	i=0;
	while(!(qr==0&&qi==0)){
		if((a+b)%2==0)
			r=0;
		else
			r=1;
		ret[i]=r;
		i++;
		qr=(a-b-r)*(-1)/2;
		qi=(a+b-r)*(-1)/2;
		a=qr,b=qi;
	}
	i--;
	for(;i>=0;i--){
		printf("%d",ret[i]);
	}
	ret[0],ret[1],ret[2],ret[3],ret[4];
	return 0;
}