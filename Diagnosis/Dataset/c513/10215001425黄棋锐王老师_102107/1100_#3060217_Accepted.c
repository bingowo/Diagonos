#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct point
{
	int x,y;
}; 

int solution(int r,int t)//-mx0=x-a,mt=r;
{
	if(t==0&&r!=0) return -2;//无解 
	else if(t==0&&r==0) return -1;//任意解
	else if(r%t!=0||r/t<0) return -2;//负数和分数解，不合法
	return r/t;//r/t为自然数解 
}
int main() {
	struct point pos[200];//记录第一轮命令中会经过的点 (x,y);  (a,b)=(mx0+x,myo+y),枚举x，y看是否有解 
	pos[0].x=0,pos[0].y=0;//初始位置(0,0)
	char s[200]={'\0'};
	scanf("%s",s);
	int i,j,l=strlen(s);
	for(i=0;i<l;i++)//记录（x,y）
	{	
	switch(s[i])
	{
		case 'U': pos[i+1].x=pos[i].x,pos[i+1].y=pos[i].y+1;break;
		case 'D': pos[i+1].x=pos[i].x,pos[i+1].y=pos[i].y-1;break;
		case 'L': pos[i+1].x=pos[i].x-1,pos[i+1].y=pos[i].y;break;
		case 'R': pos[i+1].x=pos[i].x+1,pos[i+1].y=pos[i].y;break;
	}
	}
	int m1,m2;
	int q;
	scanf("%d",&q);
	while(q--)
{	int a,b,flag=0;
	scanf("%d%d",&a,&b);
	for(i=0;i<=l;i++)//枚举(x,y) 
	{	m1=solution(pos[i].x-a,(-1)*pos[l].x);//-mx0=x-a,mt=r;
		m2=solution(pos[i].y-b,(-1)*pos[l].y);//-my0=y-b,mt=r;
		if(m1==-2||m2==-2) continue;//无解枚举下一个点 
		else if(m1==m2||m1==-1||m2==-1)//有解 
		{flag=1;break;}
	}
	if(flag) printf("Yes\n");
		else printf("No\n");
}	 
	
    return 0;
}
