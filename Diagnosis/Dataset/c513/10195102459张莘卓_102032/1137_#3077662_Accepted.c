#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[1000],b[1000],c[1000];

//返回两者较大值
int max(int a,int b){
	if(a>b)return a;
	else return b;
}

//将数组设置为0
void setZero(int*num,int len){
	for(int i=0;i<len;i++)
		num[i]=0;
}

//比较两个数组形式数字大小
int compare(int*num1,int*num2){
	int i,j;
	for(i=999;num1[i]==0;i--);
	for(j=999;num2[j]==0;j--);
	if(i<j)return -1;
	else if(i>j)return 1;
	else{
		for(;i>=0;i--){
			if(num1[i]>num2[i])
				return 1;
			else if(num1[i]<num2[i])
				return -1;
		}
		return 0;
	}
}

//将一个数组赋给另一个数组
int copy(int*num1,int*num2){
	int i,j;
	for(i=0;i<1000;i++)
		num1[i]=0;
	for(i=999;num2[i]==0;i--);
	for(j=0;j<=i;j++)
		num1[j]=num2[j];
	return i+1;
}

//大数加法
void add(char*str1,char*str2){
	setZero(a,1000);
	setZero(b,1000);
	setZero(c,1000);
	int i,carry=0;
	int len1=strlen(str1),len2=strlen(str2),len=max(len1,len2);
	for(i=0;i<len1;i++)
		a[i]=str1[len1-1-i]-'0';
	for(i=0;i<len2;i++)
		b[i]=str2[len2-1-i]-'0';
	for(i=0;i<len;i++){
		c[i]=(a[i]+b[i]+carry)%10;
		carry=(a[i]+b[i]+carry)/10;
	}


	if(carry!=0)
		c[len++]=1;
	for(i=len-1;i>=0;i--)
		printf("%d",c[i]);
	printf("\n");
}

//大数减法
void sub(char*str1,char*str2){
	setZero(a,1000);
	setZero(b,1000);
	setZero(c,1000);

	int i,borrow=0;
	int len1=strlen(str1),len2=strlen(str2),len=max(len1,len2);
	for(i=0;i<len1;i++)
		a[i]=str1[len1-1-i]-'0';
	for(i=0;i<len2;i++)
		b[i]=str2[len2-1-i]-'0';

	//初步根据位数判断两数大小
	if(len2>len1){
		printf("-");
		for(i=0;i<len;i++){
			c[i]=b[i]-a[i]-borrow;
			if(c[i]<0){
				borrow=1;
				c[i]+=10;
			}
			else
				borrow=0;
		}
	}
	else{
		for(i=0;i<len;i++){
			c[i]=a[i]-b[i]-borrow;
			if(c[i]<0&&i+1<len){
				borrow=1;
				c[i]+=10;
			}
			else
				borrow=0;
		}
	}
	//如果发现被减数小于减数，则重新计算，用减数减去被减数，输出负号
	if(c[len-1]<0){
		printf("-");
		for(i=0;i<len;i++){
			c[i]=b[i]-a[i]-borrow;
			if(c[i]<0&&i+1<len){
				borrow=1;
				c[i]+=10;
			}
			else
				borrow=0;
		}
	}


	while(c[len-1]==0&&len>1)
		len--;
	for(i=len-1;i>=0;i--)
		printf("%d",c[i]);
	printf("\n");
}
int main() {
    char a[100],b[100];
    scanf("%s",a);
    scanf("%s",b);
	if (a[0]!='-'&&b[0]!='-')
    {add(a,b);}
	else if(a[0]!='-'&&b[0]=='-')
    {
        int lenb=strlen(b);
        for(int i=0;i<lenb;i++)
            b[i]=b[i+1];
        sub(a,b);
    }
    else if(a[0]=='-'&&b[0]!='-')
    {
        int lena=strlen(a);
        for(int i=0;i<lena;i++)
            a[i]=a[i+1];
        sub(b,a);
    }
    else if(a[0]=='-'&&b[0]=='-')
    {
        int lena=strlen(a);
        for(int i=0;i<lena;i++)
            a[i]=a[i+1];
        int lenb=strlen(b);
        for(int i=0;i<lenb;i++)
            b[i]=b[i+1];
        printf("-");
        add(a,b);
    }
    return 0;
}