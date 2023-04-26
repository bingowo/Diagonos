#include <stdio.h>
#include <string.h>

void len(char s[]);
void print(char *s); 
int main()
{
	char s[501];
	scanf("%s",s);
	int i;
	printf("0001");
	len(s);
	int res,ret;
	res=strlen(s)%3;
	ret=strlen(s)/3;
	ret*=3; 
	for (i=0;i<ret;i+=3){
		print(s+i);
	}
	return 0;
}

void len(char s[])
{
	int length=strlen(s);
	int a[10];
	int i,j,t;
	for (i=0;i<10;i++){
		a[i]=length&1;
		length>>=1;
	}
	for (i=9;i>-1;i--){
		printf("%d",a[i]);
	}

}

void print(char *s)
{
	int i,ret=0,t,length=0,res;
	int a[10];
	res=strlen(s);
	if(res>=3){
		res=3;
	} 
	for (i=0;i<res;i++){
		ret=ret*10+s[i]-'0';
	}
	res=ret;
	if (res==0){
		length=4;
	}
	else{
		while (res>0){
			res/=10;
			length+=1;
		}
		if (length==1){
			length=4;
		} 
		else if (length==2){
			length=7;
		}
		else{
			length=10;
		}
	}
	for (i=0;i<length;i++){
		a[i]=ret&1;
		ret>>=1;
	}
	for (i=length-1;i>-1;i--){
		printf("%d",a[i]);
	}
}