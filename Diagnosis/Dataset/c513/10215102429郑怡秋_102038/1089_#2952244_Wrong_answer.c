#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int mul(int *num1, int *num2, int *res,int n1,int n2) 
{ //乘法函数
	int num=n1+n2-1;
    for (int i = 0; i < n1; i++) 
	{ //逐位相乘
        for (int j = 0; j < n2; j++) 
		{
            res[i + j] += num1[i] * num2[j];//printf("res %d :%d\n",i+j,res[i+j]);
        }
    }
    int carry=0;
    for (int i = 0; i < num; i++) 
	{//处理进位
        int k=res[i]+carry;
        if(k>=10) res[i]=k%10,carry=k/10;
        else res[i]=k,carry=0;
    }
    if(carry>0) res[num++]=carry;
    return num;
}


int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int B,N;
		char s[100001];
		scanf("%s%d%d",s,&B,&N);
		int l=strlen(s);
		int a[100001],b[100001],c[100001];
		for(int j=0;j<100001;j++) a[j]=0;
		for(int j=0;j<100001;j++) b[j]=0;
		for(int j=0;j<100001;j++) c[j]=0;
		for(int j=l-1,k=0;j>=0;j--,k++) b[k]=s[j]-'0',c[k]=s[j]-'0';
		
		int num=l;//printf("num:%d\n",num);
		for(int k=1;k<B;k++)
		{
			for(int j=0;j<num;j++) a[j]=0;
			num=mul(b,c,a,num,l);
			for(int d=0;d<num;d++) b[d]=a[d];
		}
		printf("case #%d:\n",i);
		for(int d=N-1;d>=0;d--) printf("%d",a[d]);
		printf("\n");
	}
	return 0;
}