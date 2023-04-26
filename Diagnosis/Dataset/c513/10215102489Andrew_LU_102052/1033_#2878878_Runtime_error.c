#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	int da;
	char mo[505];
	int ye;
	int mo1;
}p;
int cmp1(const void *x,const void* y){
	if((*(p*)x).ye!=(*(p*)y).ye) return (*(p*)x).ye>(*(p*)y).ye;
	else if((*(p*)x).mo1!=(*(p*)y).mo1) return (*(p*)x).mo1>(*(p*)y).mo1;
	else if((*(p*)x).da!=(*(p*)y).da) return (*(p*)x).da>(*(p*)y).da;
}
int main(){
	int n,t,i,j;
	p a[505];
	scanf("%d",&t);
	for(j=0;j<t;j++){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d.%s%d",&a[i].da,a[i].mo,&a[i].ye);
			if(a[i].mo[0]=='p'){
				if(a[i].mo[1]=='o') a[i].mo1=1;
				else if(a[i].mo[1]=='a') a[i].mo1=16;
			}
			else if(a[i].mo[0]=='n') a[i].mo1=2;
			else if(a[i].mo[0]=='z'){
				if(a[i].mo[1]=='i') a[i].mo1=3;
				if(a[i].mo[1]=='o') a[i].mo1=4;
				if(a[i].mo[1]=='a') a[i].mo1=11;
			}
			else if(a[i].mo[0]=='t') a[i].mo1=5;
			else if(a[i].mo[0]=='x') a[i].mo1=6;
			else if(a[i].mo[0]=='y'){
				if(a[i].mo[1]=='o') a[i].mo1=7;
				else if(a[i].mo[1]=='a') a[i].mo1=10;
			}
			else if(a[i].mo[0]=='m'){
				if(a[i].mo[1]=='o') a[i].mo1=8;
				else if(a[i].mo[1]=='a') a[i].mo1=13;
				else if(a[i].mo[1]=='u') a[i].mo1=15;
			}
			else if(a[i].mo[0]=='c'){
				if(a[i].mo[1]=='h') a[i].mo1=9;
				else if(a[i].mo[1]=='e') a[i].mo1=12;
				else if(a[i].mo[1]=='u') a[i].mo1=18;
			}
			else if(a[i].mo[0]=='k'){
				if(a[i].mo[1]=='a') a[i].mo1=14;
				else if(a[i].mo[1]=='o') a[i].mo1=17;
			}
			else a[i].mo1=19;
		}	
		qsort((void *)a,n,sizeof(a[0]),cmp1);
		printf("case #%d:\n",j);
		for(i=0;i<n;i++){
			printf("%d. %s %d\n",a[i].da,a[i].mo,a[i].ye);
		}
	}
	
}