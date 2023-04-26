#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int GCD(int m,int n)
{
   if(m%n==0) return n;
   else return GCD(n,m%n);}
int main(int argc, char *argv[]) {
	int i,j,c,a[20],a1[20],num=0,num1,g=0,g1=0,k,q,m,ans=1,b;
	char s[20];
	scanf("%s",s);
	c=strlen(s);
	for(i=0;s[i]!='.';i++){
		if(s[i]=='0')
		a[i]=0;
		if(s[i]=='2')
		a[i]=-1;
		if(s[i]=='1')
		a[i]=1;
		num++;}
	for(j=0;j<num;j++){
		g+=a[j]*pow(3,num-j-1);
	}
for(k=num+1,q=0;k<c;k++,q++){
	if(s[k]=='0')
		a1[q]=0;
		if(s[k]=='2')
		a1[q]=-1;
		if(s[k]=='1')
		a1[q]=1;
		ans*=3;	
	}	
	g1=ans;
	for(m=0;m<c-num-1;m++){
		g1+=a1[m]*pow(3,c-num-2-m);}
		if(g1>0){
		if(g1/3==0)
		{printf("%d",g1/3);}
		b=g1-(g1/3)*ans;
		if(g1/3!=0) printf("%d %d %d",g1/3,b/GCD(b,ans),ans/GCD(b,ans));
}
	return 0;
}