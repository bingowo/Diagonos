#include<stdio.h>
int TenToR(int b[100],int N,int R)//任意十进制转R进制，包括负数 
{
	if(N<0){
		N=-N;
	}
	int s[100],q=0;
	while(N/R>0)
	{
		s[q]=N%R;
		q=q+1;
		N=N/R;
	}
	s[q]=N;
	int j=0;
	while(q>=0)//这里不包括十六进制 
	{
		b[j++]=s[q];
		q=q-1;
	}
	return j;
}

int main()
{
	int A,B;
	scanf("%d %d",&A,&B);
	int b[100]={0};
	int j=TenToR(b,A,3);
	int i=0;
	int flg=1;
//	printf("三进制：");
	if(A<0)
	{
		A=-A;
//		printf("-");
		flg=-1;
	}
/*	for(i=0;i<j;i++)
	{
		printf("%d",b[i]);
	}
	printf("\n");*/
	if(A==0)
	{
		printf("0");
		return 0;
	}
	int k=0;
	while(B>0)
	{
		B=B/3;
		k++;
	}
	k=k-1;//一定要-1 
//	printf("k:%d\n",k);
	int a[200]={0};//用前100个记录整数，后100个记录小数 
	int z=100,cnt1=0,cnt2=0;
//	printf("j:%d\n",j); 
	for(i=j-1,z=100;i>=0;i--,z--)
	{
		a[z+k]=b[i];
		if(z+k<=100)//记录整数位数 
		{
			cnt2++;
		}
	}
	cnt1=k; 
//	printf("cnt1 cnt2:%d %d\n",cnt1,cnt2);
	int temp=0,jin=0;
	int add[200]={0};
//	printf("add:");
    if(cnt2==0)
    {
    	cnt2=cnt2+1;
	}
	for(i=100+cnt1,z=i;i>100-cnt2;i--,z--)//加全1 
	{
		temp=a[i]+1;
		add[z]=(temp+jin)%3;
		jin=(temp+jin)/3;
	}
	if(jin>0)
	{
		add[z]=jin;
		z--;
	}
/*	for(i=100+cnt1;i>z;i--)
	{
		printf("%d",add[i]);
	}
	printf("\n");*/
	
	int sub[200]={0};
	for(i=100+cnt1;i>z;i--)//减全1  
	{
		sub[i]=add[i]-1;
	}
/*	if(flg>0&&sub[z+1]==0)//正数首位为1 
	{
		sub[z+1]=1;
	}*/
	char ans[100]={0};
	int t=0; 
	for(i=z+1;i<=100+cnt1;i++)
	{
        if(sub[i]==-1)
        {
        	ans[t++]='2';
           // printf("2");
        }
        else{
        	ans[t++]=sub[i]+'0';
            //printf("%d",sub[i]);
        }
        if(i==100&&cnt1>0)
        {
        	ans[t++]='.';
          // printf(".");
        }
	}
	i=0;
	while(ans[i]=='0')
	{
		i++;
		cnt2--;
	}
	if(ans[i]=='2')//为了处理8这种数 
	{
		ans[0]='1';
	}
	if(cnt2<=0&&flg>0)//为了处理8/3 26/3 这种平衡三进制形式整数为0的负数形式 
	{
		ans[0]='1';
	}
//	printf("ans[1]:%c\n",ans[1]);
//	printf("i:%d\n",i);
	int n; 
	if(flg>0)
	{
		i=0;
		while(ans[i]=='0')//去除前导0，注意整数为0的 
		{
			i++;
		}
		//printf("i:%d\n",i);
		if(ans[i]=='.')
		{
			i--;
		}
		n=t-1;
		while(ans[n]=='0'&&cnt1>0)//去除小数后导0,注意小数点后全为零的 
		{
			n--;
		}
		if(cnt2==0)
		{
			printf("0.");
		}
		if(ans[n]=='.')//小数部分全是0 
		{
			n--;
		}
		for(i;i<=n;i++)
		{
			printf("%c",ans[i]);
		}
	}
	else{
		i=0;
		while(ans[i]=='0')
		{
			i++;
		}
		if(ans[i]=='.')
		{
			i--;
		}
		n=t-1;
		while(ans[n]=='0')
		{
			n--;
		}
		if(cnt2==0)
		{
			printf("0.");
		}
		if(ans[n]=='.')//小数部分全是0 
		{
			n--;
		}
		for(i;i<=n;i++)
		{
			if(ans[i]=='2')
			{
				printf("1");
			}
			else if(ans[i]=='1')//要加else 
			{
				printf("2");
			 }
			else{
				printf("%c",ans[i]);
			} 
		}
	}
}