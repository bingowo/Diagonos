#include<stdio.h>
#include<stdlib.h>
//0:ZERO 1:ONE 2:TWO 3:THREE 4:FOUR 5:FIVE 6:SIX 7:SEVEN 8:EIGHT 9:NINE 
//0:Z 1: 2:W 3: 4:U 5: 6:X 7: 8:G 9: 
//1:ONE 3:THREE 5:FIVE 7:SEVEN 9:NINE
//1:O 3:R 5:F 7:S   FOOONNEERU
int cmp(const void* a,const void* b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int T,i,j,flag;scanf("%d",&T);
	for(int cas=0;cas<T;cas++)
	{
		char s[21];scanf("%s",s);
		int a[128],ans[20],cnt=0;for(i=0;i<128;i++)a[i]=0;for(i=0;i<20;i++)ans[i]=0;
		for(i=0;s[i];i++)a[s[i]]++;
		while(1)
		{
			flag=1;
			if(a['Z'])a['Z']--,a['E']--,a['R']--,a['O']--,flag=0,ans[cnt++]=0;
			else if(a['W'])a['T']--,a['W']--,a['O']--,flag=0,ans[cnt++]=2;
			else if(a['U'])a['F']--,a['O']--,a['U']--,a['R']--,flag=0,ans[cnt++]=4; 
			else if(a['X'])a['S']--,a['I']--,a['X']--,flag=0,ans[cnt++]=6;
			else if(a['G'])a['E']--,a['I']--,a['G']--,a['H']--,a['T']--,flag=0,ans[cnt++]=8;
			if(flag)break;
		}
		while(1)
		{
			flag=1;
			if(a['O'])a['O']--,a['N']--,a['E']--,flag=0,ans[cnt++]=1;
			else if(a['R'])a['T']--,a['H']--,a['R']--,a['E']-=2,flag=0,ans[cnt++]=3;
			else if(a['F'])a['F']--,a['I']--,a['V']--,a['E']--,flag=0,ans[cnt++]=5;
			else if(a['S'])a['S']--,a['E']-=2,a['V']--,a['N']--,flag=0,ans[cnt++]=7;
			if(flag)break;
		}
		while(a['I'])a['I']--,ans[cnt++]=9;
		qsort(ans,cnt,sizeof(int),cmp);
		printf("case #%d:\n",cas);for(i=0;i<cnt;i++)printf("%d",ans[i]); printf("\n");
	}
	return 0;
}