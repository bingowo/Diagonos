#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<math.h>
struct data{
	char s[20];
	long long int ten;
	int two[1000];
};
struct data d[10001];
int cmp(const void*a,const void*b)
{
	struct data s1=*(struct data*)a;
	struct data s2=*(struct data*)b;
	if(s1.ten !=s2.ten ){
		return(s1.ten -s2.ten);
	}
	else{
		return strcmp(s1.s,s2.s);
	}
}
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%s",d[i].s );
		d[i].ten =0;
		for(int q=0;q<1000;q++)
		{
			d[i].two[q]=0;
		} 
		int a[1000];
		memset(a,-1,1000);
		int b[200]={0},k=0;
		for(int z=0;z<strlen(d[i].s);z++)//记录不同字符个数K 
		{
			b[d[i].s [z]]++;
		}
		for(int t=0;t<200;t++)
		{
			if(b[t]>0){
				k++;
			}
		 } 
		 if(k<2)k=2;
		 //printf("k:%d\n",k);
		 
		 a[d[i].s[0]]=1;
		 d[i].two[0]=1;
		 int temp=0;
		for(int j=1;j<strlen(d[i].s );j++)//转成K进制 
		{
			if(a[d[i].s[j]]==-1)
			{
				//	printf("%c\n",d[i].s[j]);
				if(temp==1){
					temp++;
				}
				a[d[i].s [j]]=temp;
			//	printf("temp:%d %d %d\n",i,j,temp);
				temp++;
			}
			d[i].two[j]=a[d[i].s[j]];
			//printf("two:%d %d %d\n",i,j,d[i].two[j]);
		}
		
		int l=strlen(d[i].s)-1,n=0;
		//printf("l:%d\n",l);
		long long int td=1;
		for(int z=0;z<l;z++)
		{
			td*=k;
		}
		while(l>=0)//转成十进制 
		{
			 
			d[i].ten+=d[i].two[n]*td;
			//printf("test:%d\n",d[i].ten );
			l--;
			n++;
			td/=k;
		}
	//	printf("ten:%d %lld\n",i,d[i].ten );
		
	}
	qsort(d,N,sizeof(d[0]),cmp);
	//printf("ans:\n");
	for(int j1=0;j1<N;j1++)
	{
		printf("%s\n",d[j1].s );
	}
}