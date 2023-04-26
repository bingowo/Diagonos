#include <stdio.h>
#include <stdlib.h>
char* f1(char *x,int* ret){                    //  /2存在y，余数存在ret 
	char* y=(char*)malloc(102*sizeof(char));
	int i;
	int left=0;
	for(i=0;x[i];i++){
		y[i]=(left*10+x[i]-'0')/2+'0';
		left=(left*10+x[i]-'0')%2;
	}
	y[i]='\0';
	*ret=left;
	*(ret+1)=-1;
	return y;
}
int f2(char* x){                                //if==0
	int i;
	for(i=0;x[i];i++){
		if(x[i]!='0'){
			return 1;
		}
	}
	return 0;
}
int* f4(int* x){                        // *2
	int i;
	int* y=(int*)malloc(102*sizeof(int));
	for(i=0;i<102;i++){
		y[i]=0;
	}
	int temp;
	for(i=0;x[i]!=-1;i++){
		temp=x[i]*2+y[i];
		if(temp>9){
			y[i]=temp%10;
			y[i+1]=temp/10;
		}else{
			y[i]=temp;
		}
	}
	if(y[i]==0){
		y[i]=-1;
	}
	else y[i+1]=-1;
	free(x);
	return y;
}
void f5(int* x){                            // +1
	int i;
	if(x[0]<9){
		x[0]++;
		return;
	}
	int temp=1;
	for(i=0;x[i]!=-1;i++){
		if(temp){
			int temp2=x[i];
			x[i]=(temp2+temp)%10;
			temp=(temp2+temp)/10;
		}else{
			break;
		}
	}
	if(temp){
		x[i]=temp;
		x[i+1]=-1;
	}
}
void f3(int* x){                            //将x变为十进制输出 
	int i,j;
	for(i=0;x[i]==0;i++);
	int* answ=(int*)malloc(102*sizeof(int));answ[0]=1;answ[1]=-1;
	for(j=i+1;x[j]!=-1;j++){
		answ=f4(answ);
		if(x[j]==1){
			f5(answ);
		}
    }
    for(i=0;answ[i]!=-1;i++);
    	for(j=i-1;j>=0;j--){
    		printf("%d",answ[j]);
    	}
    	printf("\n");
    	free(answ);
    	free(x);
}
int main(){
	int t;scanf("%d",&t);
	int i;
	for(i=0;i<t;i++){
	    printf("case #%d:\n",i);
		int* ret=(int*)malloc(340*sizeof(int));
		ret[0]=0;ret[1]=-1;
		char* num1=(char*)malloc(102*sizeof(char));scanf("%s",num1);
		if(num1[0]=='0'&&num1[1]=='\0'){
			printf("0\n");
			continue;
		}
		char* num2=f1(num1,ret);
		int j;
		for(j=1;f2(num2);j++){
			free(num1);
			num1=num2;
			num2=f1(num1,ret+j);
		}
		free(num1);free(num2);
		f3(ret); 
	}
	return 0;
}