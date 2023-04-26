#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp(const void*a,const void*b)
{
	return *(char*)a-*(char*)b;
}
void solve()
{	char s[22]={'0'};//首位为0的一串数字
	scanf("%s",s+1);//不动首位的‘0’;
	int i=0,j=0,k=0,x='9'+1,xi=0,y=0,l=strlen(s);
	
	for(i=l-1;i>0&&s[i-1]>=s[i];i--); //找第一个小于后一位的数字，如12354，从4开始到3结束,s[i-1]=3
	
	y=s[i-1];//记录此数字
	
	for(j=l-1;j>=i;j--)
		if(s[j]>y&&s[j]<x) x=s[j],xi=j;//找大于y的最小数字和位置，交换是s[i-1]和是s[xi],i-1后面升序以便单增 
	
	s[i-1]=x,s[xi]=y;//交换s[i-1],s[xi] 
	qsort(s+i,l-i,sizeof(s[0]),cmp); //s[i]~s[l-1]升序排列 
	printf("%s\n",s+(s[0]=='0'));
}


int main() 
{ 	int t,T;
	scanf("%d\n",&T);
	for(t=0;t<T;t++)
	{	
		
		printf("case #%d:\n",t);
		solve();
	}
    return 0;
}
