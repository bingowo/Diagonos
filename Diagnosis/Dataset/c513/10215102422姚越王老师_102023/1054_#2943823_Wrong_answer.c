#include<stdio.h>
#include<malloc.h>
#include<string.h> 
int main()
{
	int T,M,i,j,k,q;scanf("%d",&T);char s[2001],tmp[1001];
	for(int cas=0;cas<T;cas++)
	{
		scanf("%d\n",&M);
		gets(s);
		int fund,left,begin=0,cnt=1,cnt2,cnt3,length=0;for(i=0;s[i];i++)if(s[i]==' ')cnt++;
		char** a=(char**)malloc(sizeof(char*)*cnt); int b[cnt];
		for(i=0;i<cnt;i++)
		{
			for(j=begin;s[j];j++)if(s[j]==' ')break;
			for(k=begin,q=0;k<j;k++,q++)tmp[q]=s[k]; tmp[q]=0;
			begin=j+1;
			char *p=(char*)malloc(sizeof(char)*q); strcpy(p,tmp); a[i]=p;
		}
		for(i=0;i<cnt;i++)b[i]=strlen(a[i]);   printf("case #%d:\n",cas);
		begin=0;//记录某一行输出的第一个单词的索引
		for(i=0;i<cnt;i++)
		{
			length+=b[i]+1;
			if(length==M||length==M+1)
			{
				for(j=begin;j<=i;j++)printf("%s ",a[j]);
				printf("\n"); begin=i+1;length=0;
			}
			else if(length>M+1&&length-b[i]-1<M)
			{
				length=0;
				for(j=begin;j<i;j++)length+=b[j];
				cnt2=M-length;cnt3=i-begin-1;//cnt3个空格位，但是需要写cnt2个空格；
				fund=cnt2/cnt3;left=cnt2%cnt3;//每个位置最少空格数，多出left个
				int c[cnt3];for(k=0;k<cnt3;k++)c[k]=fund;
				for(k=cnt3-1;k>cnt3-1-left;k--)c[k]++;
				for(j=begin;j<i;j++)
				{
					printf("%s",a[j]);
					if(j!=i-1)for(k=0;k<c[j-begin];k++)printf(" ");
				}
				begin=i;length=b[i]+1;
				printf("\n");
			}
		}
		for(j=begin;j<i;j++)printf("%s ",a[j]); printf("\n");
		for(i=0;i<cnt;i++)free(a[i]); free(a);
	}
	return 0;
}