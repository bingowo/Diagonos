#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int a[501]={0},b[1000]={0};
	char s[501];
	scanf("%s",s);
	int len=strlen(s);
	int i=0,t=len;
    while(t)
	{
		a[i]=s[i]-'0';//数字字符变为数字  
		i++;
		t--;
	}
	int c=len/3;//3个一组
	int d=len%3;//少于3个的一组
	int j=0,temp=0,k=0;
	if(len<3){
		if(len==1){
			printf("00010000000001");
			temp=a[0];
			while(temp>0)
			{
				b[k]=temp%2;
				temp=temp/2;
				k++;
			}
			for(int z=4;z>=0;z--)printf("%d",b[z]);
			printf("\n");
		}
		if(len==2){
			printf("00010000000001");
			temp=a[0]*10+a[1];
			while(temp>0)
			{
				b[k]=temp%2;
				temp=temp/2;
				k++;
			}
			for(int z=7;z>=0;z--)printf("%d",b[z]);
			printf("\n");
		}
	}
	else{
	for(i=0;i<c;i++)
	{
		temp=a[j]*100+a[j+1]*10+a[j+2];//先转成10进制
		printf("%d\n",temp);
		j=j+3;
		k=i*10;
		printf("k:%d\n",k);
		while(temp>0)//再转成二进制倒序存在b[] 
		{
			b[k]=temp%2;
			temp=temp/2;
			k++;
		}	
	 }
	 k=c*10;
	 int cnt=d,q=k;
	 if(cnt==2){//末尾是两位数字，换成7位二进制 
	 	temp=a[j]*10+a[j+1];
	 	printf("%d\n",temp);
	 	while(temp)
	 	{
	 		b[q]=temp%2;
	 		temp=temp/2;
	 		q++;
		 }
		 k=k+7;
		 printf("k:%d\n",k);
		 q=k;
	 }
	 if(cnt==1){//末尾是一位数字转成4位二进制 
	 	temp=a[j];
	 	while(temp)
	 	{
	 		b[q]=temp%2;
	 		temp=temp/2;
	 		q++;
		 }
		 k=k+4;
		 q=k;
	 }
	 while(len)//把数字个数转成10位二进制 
	 {
	 	b[q]=len%2;
	 	len=len/2;
	 	q++;
	 }
	 k=k+10;
	 q=k;
	 b[q]=1;//把0001加入
	 k=k+3;//k指向编码的末尾
	 printf("k:%d\n",k);
	 while(k)
	 {
	 	printf("%d",b[k]);
	 	k--;
	}
}
 } 