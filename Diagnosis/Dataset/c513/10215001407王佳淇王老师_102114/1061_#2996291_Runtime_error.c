#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct{
	char str[20];
	int zhi;
}data ;


long long pow1(int x,int y)
{
    int i=y;
    long long r=1;
    for(;i>0;i--)
    {r*=x;}
    return r;
}
int cmp(const void*a,const void*b){
	long long z1=((data*)a)->zhi; long long z2=((data*)b)->zhi;
	char *p1=((data*)a)->str;char *p2=((data*)b)->str;
	if(z1!=z2) return z1>z2;
	else return strcmp(p1,p2);
}
int main()
{
    int T,k;
	data d[10001];
    memset(d,0,sizeof(data)*10001);
    scanf("%d",&T);
    for(k=0;k<T;k++)
    {
        int m[128],i,j;
        for(i=0;i<128;i++) m[i]=-1;
        int len,co=1;
        scanf("%s",d[k].str);
        char*ch=d[k].str;
        len=strlen(d[k].str);
       int num=0;
        long long re=0;
        for(j=0;j<len;j++,ch++)
        {
            if(m[*ch]!=-1) continue;
            else
                {
                    if(num==1) {m[*ch]=0;num++;}
                    else {m[*ch]=co;co++;num++;}
                }
        }
        if(num==1) num=2;
        ch=d[k].str;
        for(j=0;j<len;j++,ch++)
        {
            re=(m[*ch]*pow1(num,len-1-j))+re;
        }
        d[k].zhi=re;
    }
    qsort(d,T,sizeof(d[0]),cmp);
    for(int v=0;v<T;v++){
    	printf("%s\n",d[v]);
	}
    return 0;
}