#include<stdio.h>
#include<string.h>
typedef struct{
	int key;   //key=0表示没有循环节,key=1表示有循环节 
	int begin; //begin和end分别表示循环节的开始位置和结束位置 
	int end;
}inf;
inf div(int a[],int n,int m){
	inf x;
	x.begin=0,x.end=0,x.key=0;
	int b[m]; //用来记录余数的出现的位置
	int j;
	for(j=0;j<m;j++){
		b[j]=0;
	}
	int i=1;
	int temp=n;     //temp用来表示余数 
	while(temp){
		temp=temp*10;
		a[i]=temp/m;
		temp=temp%m;
		if(b[temp]==0) {b[temp]=i;x.end=i;}
		else {
		    x.begin=b[temp];
			x.end=i;
			x.key=1;
			if(x.end-x.begin==1){
				if(a[x.begin]==a[x.end]){
					x.end=x.begin;
				}
				else x.begin=x.end;
			}
			break;
		}
		i++;
	}
	return x;
} 
int main(){
	int chance;
	scanf("%d",&chance);
	int i,j,a[100]={0};
	for(i=0;i<chance;i++){
		int n,m;
		scanf("%d %d",&n,&m);
		inf x=div(a,n,m);
		printf("case #%d:\n",i);
		if(x.key==0) 
		{
		printf("0.");
		for(j=1;j<=x.end;j++){
			printf("%d",a[j]);}
		}
		else{
			printf("0.");
			for(j=1;j<=x.end;j++){
				printf("%d",a[j]);
			}
			printf("\n%d-%d",x.begin,x.end);
		}
		printf("\n");
	}
}