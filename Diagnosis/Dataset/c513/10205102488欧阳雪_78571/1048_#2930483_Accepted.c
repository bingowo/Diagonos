#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data{
	int xs;
	int zs;
	int flg;
};
struct data a[1000];
struct data b[1000];
struct data ans[1000];
char s1[1000]={0},s2[1000]={0};
int print(struct data*d,char*s)
{
		int k=0,i=0;
		while(s[i])
		{
			//printf("s[i]:%d %c\n",i,s[i]);
			int t1=0,t2=0;
			int cnt=0;
			if(s[i]=='-'||s[i]=='+')
	        {
				if(s[i]=='-'){
				//	printf("%c\n",s[i]);
					d[k].flg=-1; 
				}
				i++;
				//printf("s[i]:%d %c\n",i,s[i]);
			}
			while(s[i]>='0'&&s[i]<='9'&&s[i])//系数 
			{
				//printf("s[i]:%d %c\n",i,s[i]);
				t1*=10;
				t1+=s[i]-'0';
				i++;
				cnt++;
			}
			if(cnt>=1){
				d[k].xs =t1*d[k].flg ;
			//	printf("test:%d %d\n",k,d[k].xs);
			}
			else{
				d[k].xs=d[k].flg;
			}
			//printf("xs:%d %d\n",k,d[k].xs);
			if(s[i]=='x'){
				i++;
			}
			else{//a0 
				d[k].zs =0;
				//printf("zs:%d %d\n",k,d[k].zs);
				k++;
				break;
			}
			if(s[i]=='^'){//指数 (？？？？） 
				i++;
			//	printf("^:%c\n",s[i]);
				while(s[i]>='0'&&s[i]<='9')
				{
					//printf("s[i]:%d %c\n",i,s[i]);
				//	printf("t2:%d\n",t2);
					t2*=10;
					t2+=s[i]-'0';
					i++;
				}
				d[k].zs=t2;
				//printf("zs:%d %d\n",k,d[k].zs);
				k++;
			}
			else{
				d[k].zs =1;
				//printf("zs:%d %d\n",k,d[k].zs);
				k++;
			}
		}
		return k;
}
int cmp(const void*a,const void*b)
{
	struct data c=*(struct data*)a;
	struct data d=*(struct data*)b;
	if(c.zs >d.zs )return -1;
	else return 1;
}
int main()
{
	char temp[1000]={0};
	while(scanf("%s",temp)!=EOF)
	{
		strcpy(s1,temp);
		scanf("%s",s2);
		//printf("s1 s2:%s %s\n",s1,s2);
		for(int j=0;j<1000;j++)
		{
			a[j].flg =1,b[j].flg=1;
			a[j].zs =0,b[j].zs=0,ans[j].zs =0;
			a[j].xs =1,b[j].xs=1,ans[j].xs =1;
		}
		int len1=print(a,s1)-1;
		int len2=print(b,s2)-1;
	//	printf("len1 len2:%d %d\n",len1,len2);
		int t=0;
		for(int i=0;i<=len1;i++)
		{
			for(int k=0;k<=len2;k++)
			{
				ans[t].xs =a[i].xs *b[k].xs;
				ans[t].zs =a[i].zs +b[k].zs;
				//printf("ans[t].xs:%d %d\n",t,ans[t].xs);
				//printf("ans[t].zs:%d %d\n",t,ans[t].zs );
				t++;
			}
		}
		qsort(ans,t,sizeof(ans[0]),cmp);//按指数由高到低排序
		int z=0;
		/*for(int z=0;z<t;z++)
		{
			printf("%d ",ans[z].zs );
		}
		printf("\n");*/
		int j1=0;
		while(j1<t)
		{
			int xs=ans[j1].xs ;
			while(ans[j1].zs ==ans[j1+1].zs&&(j1+1)<t )
			{
				xs+=ans[j1+1].xs ;
				j1++;
			}
			if(xs!=0){
					printf("%d ",xs);
			}
			j1++;
		} 
		printf("\n");
		
	}
	return 0;
 } 