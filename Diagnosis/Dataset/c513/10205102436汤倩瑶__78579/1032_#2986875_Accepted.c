#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
typedef struct{
	int a[55];
	int cnt;
}node;
int cmp(const void*a,const void*b)
{
	
node p1=*((node*)a);
node p2=*((node*)b);
int i=0;
while((i<p1.cnt)&&(i<p2.cnt)){
	if(p1.a[i]>p2.a[i])return -1;
	else if(p1.a[i]==p2.a[i])i++;
	else return 1;
}
if(i<p1.cnt)return -1;
else return 1; 

} 
int main()
{
	int T;
	scanf("%d",&T);
	node t[1005]={0};
	for(int i=0;i<T;i++)
	{
		int n;
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			int c=0;
			int tmp;
		while((scanf("%d",&tmp)!=EOF)&&(tmp!=-1)){t[j].a[c]=tmp;c++;}
		t[j].cnt=c; 
		}
		
		qsort(t,n,sizeof(t[0]),cmp);
		//printf("case #%d:\n",i);
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<t[j].cnt;k++)
			printf("%d ",t[j].a[k]);
			printf("\n");
		}
		
		
		
		
	}
	return 0; 
} 