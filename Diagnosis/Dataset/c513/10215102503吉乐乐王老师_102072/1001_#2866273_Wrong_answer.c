#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
	int x,p; //x为十进制数，p为目标进制大小 
	scanf("%d %d",&x,&p);
	getchar();
	char a[10000]; //存放余数 
	int count=0;
	do{
        char temp=x%p;
        if(temp>=10)temp=temp-10+'A';
        else temp+='0';
		a[count++]=temp;
		x=x/p;
	}while(x!=0);//当商不为0时进行循环 
	for(int i=count-1;i>=0;i--){
		putchar(a[i]);
	}
    putchar('\n');
}
}