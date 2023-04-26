#include<stdio.h>
#include<string.h>
#include<math.h>
//把s[i]的ASC码转成八位二进制，不够的用0充
// 
int trans(char*s,int*two,int*ten)
{
	int c[1000]={0};//存翻转前的二进制码
	int k=1;//！！！！ 
	for(int i=0;i<strlen(s);i++)//每一个字符转成二进制
	{
		int temp=s[i];
		while(temp>0)
		{
			c[k++]=temp%2;
			temp/=2;
		}
		k--;//！！！！ 
		if((k%8)!=0){//二进制位要为8位 
			int t=8-k%8;
			while(t>=0)
			{
				k++;
				t--;
			}
		}
	}
	k=8;
	int t1=1;//！！！！ 
	for(int j=0;j<strlen(s);j++)//逆转 
	{
		int temp=k;
		for(int n=0;n<8;n++)//每8位一组逆转 
		{
			two[t1]=c[temp];
			t1++;
			temp--;
		}
		k*=j;
	}
	t1--;//！！！ 
	int cnt1=t1/6;//6位一组
	int cnt2=t1%6;
	int t2=1,z=1,t3=0;
	for(int i1=0;i1<cnt1;i1++)//每六位二进制转十进制 
	{
		t3=6;
		for(k=0;k<6;k++)
		{
			ten[z]+=two[t2]*pow(2,t3-1);
			t2++;
			t3--;
		}
		z++;
	}
	if(cnt2!=0)
	{
		t3=6;
		for(k=0;k<6;k++)//继续算6位 
		{
			ten[z]+=two[t2]*pow(2,t3-1);
			t2++;
			t3--;
		}
	}
	return z;//十进制数个数 
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		char s[200]={0};
		scanf("%s",s);
		//录入表 
		char table[65]={0};
		char temp1='A';
		for(int j1=0;j1<26;j1++)//A-Z
		{
			table[j1]=temp1;
			temp1++; 
		}
		int j2=0;
		char temp2='a';
		while(j2<26)//a-z 
		{
			table[j1++]=temp2;
			temp2++;
			j2++;
		}
		int j3=0;
		char temp3='0';
		while(j3<10)
		{
			table[j1++]=temp3;
			temp3++;
			j3++;
		}
		table[j1++]='+';
		table[j1]='/';
		
		int two[1000]={0};//放二进制码 
		int ten[1000]={0};//放对应的十进制数 
		int len=trans(s,two,ten);//对应的十进制数个数 
		printf("case #%d:\n",i);
			for(int k=0;k<len;k++)
			{
				printf("%c",table[ten[k]]);
			}
		if(len<4){
			int cnt=4-len;
			for(int n=0;n<cnt;n++)
			{
				printf("=");
			}
		}
		printf("\n");
	}
}