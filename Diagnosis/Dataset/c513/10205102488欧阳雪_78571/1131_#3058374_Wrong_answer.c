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
	//	printf("-");
		flg=-1;
	}
/*	for(i=0;i<j;i++)
	{
		printf("%d",b[i]);
	}
	printf("\n");*/
	int k=0;
	while(B>0)
	{
		B=B/3;
		k++;
	}
	k=k-1;
//	printf("k:%d\n",k);
	int a[200]={0};//用前100个记录整数，后100个记录小数 
	int z=100,cnt1=0,cnt2=0;
	for(i=j-1,z=100;i>=0;i--,z--)
	{
		a[z+k]=b[i];
		if(z+k>100)//记录小数位数 
		{
			cnt1++;
		}
		else{
			cnt2++;
		}
	}
	int temp=0,jin=0;
	int add[200]={0};
//	printf("add:");
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
	if(flg>0&&sub[z+1]==0)
	{
		sub[z+1]=1;
	}
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
	if(flg>0)
	{
		for(i=0;i<t;i++)
		{
			printf("%c",ans[i]);
		}
	}
	else{
		for(i=0;i<t;i++)
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