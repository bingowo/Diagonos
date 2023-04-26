#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef long long LL;
typedef struct 
{
	int v;
	int fz,fm;
}Valley;
Valley a[1005];
int MIN(int x,int y)
{
	if(x<y)return x;return y;
}
int gcd(int x,int y)
{
	if(y==0)return x;
	return gcd(y,x%y);
}
int cmp(const void *a,const void *b)
{
	int x=*(int*)a;int y=*(int*)b;
	if(x<y)return -1;return 1;
}
int arr[1005];
void full_final(Valley s,int l,int r,int dir)
{
	int t=0,cnt;
	for(int i=l;i!=r+dir;i+=dir)arr[t++]=a[i].v;
	qsort(arr,t,sizeof(int),cmp);
	for(int i=1;i<t;i++)
	{
		int c=(arr[i]-arr[i-1])*i;
		if(s.v<c)
		{
			cnt=i;break;
		}
		else s.v-=c;
	}
	int fz=s.v*s.fm+s.fz,fm=s.fm*cnt;
	int zs=arr[cnt-1]+fz/fm;
	fz%=fm;
	int g=gcd(fz,fm);
	fz/=g;fm/=g;
	for(int i=l;i!=r+dir;i+=dir)
	{
		if(a[i].v<=zs)
		{
			a[i].v=zs;
			a[i].fz=fz;
			a[i].fm=fm;
		}
	}
}
Valley full_sub(Valley s,int l,int r,int dir)
{
	int t=l;
	while(t!=r&&a[t+dir].v<=a[t].v)t+=dir;
	while(t!=r&&a[t+dir].v>=a[t].v)t+=dir;
	int high=MIN(a[l].v,a[t].v),v=0;
	for(int i=l;i!=t+dir;i+=dir)
	if(a[i].v<high)v+=high-a[i].v;
	if(s.v>=v)
	{
		for(int i=l;i!=t+dir;i+=dir)
		if(a[i].v<high)a[i].v=high;
		s.v-=v;return s;
	}
	full_final(s,l,t,dir);
	Valley ret;ret.v=0;ret.fz=0;ret.fm=1;
	return ret;
}
void full(Valley s,int l,int r,int dir)
{
	while(s.v>0||s.fz>0){s=full_sub(s,l,r,dir);}
}
int water_lowest(int s,int base,int lpos,int rpos)
{
	int width=rpos-lpos-1;
	int high=MIN(a[lpos].v,a[rpos].v)-base;
	int v=width*high;
	if(s>=v)
	{
		for(int i=lpos+1;i<=rpos-1;i++)a[i].v=base+high;
		return s-v;
	}
	else
	{
		int w_high=base+s/width;
		int r=s%width;
		int fz=r,fm=width;
		int g=gcd(fz,fm);
		fz/=g;fm/=g;
		for(int i=lpos+1;i<=rpos-1;i++)
		{a[i].v=w_high;a[i].fz=fz;a[i].fm=fm;}
		return 0;
	}
}
int water(int s,int p)
{
	int l=p,r=p,suml=0,sumr=0;
	while(a[l-1].v<=a[p].v){l--;suml+=a[p].v-a[l].v;}
	while(a[r+1].v<=a[p].v){r++;sumr+=a[p].v-a[r].v;}
	if(suml+sumr==0)
	return water_lowest(s,a[p].v,l-1,r+1);
	else if(suml+sumr<=s)
	{
		for(int i=l;i<=r;i++)a[i].v=a[p].v;
		return s-suml-sumr;
	} 
	else if(suml*2<=s)
	{
		for(int i=l;i<p;i++)a[i].v=a[p].v;
		Valley half;half.v=s-suml;half.fz=0;half.fm=1;
		full(half,p,r+1,1);
		return 0;
	}
	else if(sumr*2<=s)
	{
		for(int i=p+1;i<=r;i++)a[i].v=a[p].v;
		Valley half;half.v=s-sumr;half.fz=0;half.fm=1;
		full(half,p,l-1,-1);
		return 0;
	}
	else
	{
		Valley half;half.v=s/2;half.fz=s%2;half.fm=2;
		full(half,p,l-1,-1);full(half,p,r+1,1);
		return 0;
	}
}
int main()
{
	int n,s,p;
	scanf("%d%d%d",&n,&s,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].v);
		a[i].fz=0;a[i].fm=1;
	}
	a[0].v=a[n+1].v=1e6+1;
	a[0].fz=a[n+1].fz=0;
	a[0].fm=a[n+1].fm=1;
	while(s>0)
	s=water(s,p);
	for(int i=1;i<=n;i++)
	{
		if(a[i].v!=0&&a[i].fz!=0)printf("%d+%d/%d ",a[i].v,a[i].fz,a[i].fm);
		else if(a[i].fz!=0)printf("%d/%d ",a[i].fz,a[i].fm);
		else printf("%d ",a[i].v);
	}
	return 0;
} 