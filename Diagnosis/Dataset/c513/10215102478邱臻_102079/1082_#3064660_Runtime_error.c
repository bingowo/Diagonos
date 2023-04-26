#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void reverse(int *a,int len){
	int i,j,m;
	for(i=0,j=len-1;i<=j;i++,j--){
		m=a[i];a[i]=a[j];a[j]=m;
	}
}
int main(int argc, char *argv[]) {
	int az[10000]={},ax[10000]={},bz[10000]={},bx[10000]={},z[10000]={},x[10000]={};
	char a[1000],b[1000];
	int n,i,j,flag,max,maxx,carry,maxa,maxb,maxax,maxbx;
	scanf("%s%s%d",a,b,&n);
	flag=0;
	for(i=0;i<strlen(a);i++){
		if(a[i]=='.'){flag=1;j=1;maxa=i;}
		else if(!flag)az[i]=a[i]-'0';
        else if(flag)ax[j++]=a[i]-'0';
	}  //记录小数
	if(flag==0)maxa=strlen(a); 
	if(maxa>1)reverse(az,maxa);
	flag=0;maxax=j;
	for(i=0;i<strlen(b);i++){
		if(b[i]=='.'){flag=1;j=1;maxb=i;}
		else if(!flag)bz[i]=b[i]-'0';
        else if(flag)bx[j++]=b[i]-'0';
	}  //记录小数 
	if(flag==0)maxb=strlen(b);
	if(maxb>1)reverse(bz,maxb);
	maxbx=j;maxx=maxax>maxbx?maxax:maxbx;carry=0;
	for(i=maxx-1;i>=0;i--){
		x[i]=ax[i]+bx[i]+carry;
		carry=x[i]/10;x[i]=x[i]%10;  //进位处理 
	}  //小数部分计算 
	if(x[n+1]>=5){
		carry=1;i=n;
		while(carry){
			x[i]++;carry=x[i]/10;
			x[i]=x[i]%10;i--;
		}
	}
	max=maxa>maxb?maxa:maxb;carry=x[0];
	for(i=0;i<max;i++){
		z[i]=az[i]+bz[i]+carry;
		carry=z[i]/10;z[i]=z[i]%10;  //进位处理 
	}  //整数部分计算
	if(carry){z[i]+=carry;max++;}  //最高位进位处理 
	if(z[max-1]!=0){for(i=max-1;i>=0;i--)printf("%d",z[i]);}
	printf(".");
	for(i=1;i<=n;i++)printf("%d",x[i]);
	return 0;
}