#include<stdio.h>
#include<math.h>
int a[100]={0};
int prime(int n)
{
	int i=0;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
void sushu(int *a){//计算1-100内的素数 ,25个 
	int i=0,k=0,j=0;
	for(i=2;i<100;i++)
	{
		if(prime(i)){
			k++;
			a[j]=i;
			j++;
		}
	}
}
int main()
{
	int T;
	scanf("%d\n",&T);//！！！ 
	sushu(a);
	for(int i=0;i<T;i++)
	{
		char s[26]={'\0'};
		char c;
		int b[26]={0},d[26]={0},ans[50];
		for(int m=0;m<50;m++)ans[m]=0;
		int temp=0,j1=0,j2=0;
		int len1=0,len2=0,len=0;
		while((c=getchar())!=' ')//输入第一组数到b[]
		{
			if(c==','){
				continue;
			}
			temp=0;
			while(c!=','&&c!=' ')
			{
				temp*=10;//考虑“110，”!!
				temp+=(c-'0');
				c=getchar();
				if(c==' ')goto FLAG1;//test
			}
			FLAG1:
			b[j1++]=temp;
			//printf("b[]:%d %d\n",j1-1,b[j1-1]);
			if(c==' ')goto FLAG2; 
		}
		FLAG2://输入第二组数到d[] 
			while((c=getchar())!='\n')
			{
				if(c==','){
					continue;
				}
				temp=0;
				while(c!=','&&c!='\n')
				{
					temp*=10;
					temp+=(c-'0');
					c=getchar();
					if(c=='\n')goto FLAG3;
				}
				FLAG3:
					d[j2++]=temp;
					//printf("d[]:%d %d\n",j2-1,d[j2-1]);
				if(c=='\n'){
					goto FLAG4;
				}
			}
		FLAG4://相加 
			len1=j1,len2=j2;
			j1--,j2--;
			int k1=0,flg1=0;//flg1用于标记哪组数更长，flg1=1后一组长 
			if(len1>=len2)len=len1;
			else {
				len=len2,flg1=1;
			}
			int j3=len;
			while(len>0)
			{
				if(j1<0||j2<0){//两组数长度不一 
					if(flg1==0){
					//printf("a[]:%d %d\n",k1,a[k1]); 
					    int tep=ans[len];
						ans[len]=(ans[len]+b[j1])%a[k1];
						ans[len-1]=(tep+b[j1])/a[k1];
						//printf("ans[]:%d %d\n",len,ans[len]);
					}
					else{
						//printf("a[]:%d %d\n",k1,a[k1]);
						int tep=ans[len];
						ans[len]=(tep+d[j1])%a[k1];
						ans[len-1]=(tep+d[j1])/a[k1];
						//printf("tep:%d\n",tep);
						//printf("ans[]:%d %d\n",len,ans[len]);
						//printf("ans[]:%d %d\n",len-1,ans[len-1]);
					}
				}
				else{
				//	printf("a[]:%d %d\n",k1,a[k1]);
				int tep=ans[len];
				ans[len]=(ans[len]+b[j1]+d[j2])%a[k1];
				//printf("ans[]:%d %d\n",len,ans[len]);
				ans[len-1]=(tep+b[j1]+d[j2])/a[k1];
				//printf("ans[]:%d %d\n",len-1,ans[len-1]);
				} 
				len--;
			    k1++;
			    j1--,j2--;
			}
			printf("case #%d:\n",i);
			if(ans[0]>0)printf("%d,",ans[0]);//输出 
	        for(int j4=1;j4<j3;j4++)
            {
			   printf("%d,",ans[j4]);
	        }
	        printf("%d",ans[j3]);
	}
}