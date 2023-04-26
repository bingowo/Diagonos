#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    int a,b,z=0,i,j,n,m,x,y,k,dot,sign=0,flag=0;;
    int num[100000]={};
    scanf("%d%d",&a,&b);
    if(b==1){
    	while(a!=0){
    		if(a%3==2){
    			a++;
				num[z++]=2;
				a=a/3;
			}
			else {
				num[z++]=a%3;
				a=a/3;
			}
		}
		j=z-1;
		while(num[j]==0)j--;
		while(j>=0){
			printf("%d",num[j]);
			j--;
		}
	}  //只有整数部分
	else {
		k=0;
		z=b;x=a/b;y=a-x*b;  //化为带分数形式
		while(x!=0){
			num[k]=x%3;x=x/3;
			k++;
		}  //整数部分
		for(i=0,j=k-1;i<=j;i++,j--){n=num[i];num[i]=num[j];num[j]=n;}
		dot=k;
		while(y!=z){
			z=z/3;
			if(z==1){
				num[k]=y;y=1;
			}
			else if(y>z){
				num[k]=y/z;y=y%z;
			}
			k++;
		}
		for(i=0;i<k;i++){
			num[i]+=1;j=0;
			while(num[i-j]>=3){
				num[i-j]-=3;
				if(i==j)sign=1;
				else num[i-j-1]+=1;
				j++;
			}  //进位计算 
		} 
		j=k;
		while(j!=0 && j>=dot)j--;
		if(j==dot-1)flag=1;
		if(dot==0){
			if(sign==1)printf("1.");
			else printf("0.");
		}
		for(i=0;i<=j;i++){
			if(sign==1 && i==0 && dot!=0)printf("1");
			num[i]-=1;
			if(num[i]==-1)num[i]=2;
			printf("%d",num[i]);
			if(i==dot-1 && flag!=1)printf(".");
		}
	} 
	return 0;
}