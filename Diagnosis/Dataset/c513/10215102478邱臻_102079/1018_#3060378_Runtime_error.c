#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int prime[]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}; 
int main(int argc, char *argv[]) {
	int i=0,j,k,len,z,carry,max;
	char c;
	int a[26]={},r[100]={};
	do{
		scanf("%d%c",&a[i],&c);
		i++;
	}while(c==',');  //输入数字
	if(i==1)printf("%d",a[0]);
	else {
	len=i-1;
	for(j=0;j<i;j++){
		if(j==0)r[j]=a[0];
		else {
			k=0;carry=0;
			while(r[k]!=0 || carry!=0 || k<max){
				r[k]=r[k]*prime[len]+carry;
				carry=r[k]/10;
				r[k]=r[k]%10;k++;
			}
			r[0]+=a[j];len--;max=max>k?max:k;
		}
	}  //转换为十进制 
	for(z=max-1;z>=0;z--)printf("%d",r[z]);
    }
	return 0;
}