#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int cmp(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
void tran(int*a)//根据数字英语独有的字母分类然后++-- 
{  int pa[100]={0};
	int cn=0,i;
	while(a['Z'])//0
	{    a['Z']--;a['E']--;a['R']--;a['O']--;
		 pa[cn++]=0;
	}
	while(a['W'])//2
	{ a['T']--;a['W']--;a['O']--;
		pa[cn++]=2;
	}
	while(a['U'])//4
	{ a['F']--;a['O']--;a['U']--;a['R']--;
		pa[cn++]=4;
	}
	while(a['X'])//6
	{ a['S']--;a['I']--;a['X']--;
		pa[cn++]=6;
	}
	while(a['G'])//8
	{ a['E']--;a['I']--;a['G']--;a['H']--;a['T']--;
		pa[cn++]=8;
	}
	while(a['R'])//3
	{ a['T']--;a['H']--;a['R']--;a['E']-=2;
		pa[cn++]=3;
	}
	while(a['F'])//5
	{ a['F']--;a['I']--;a['V']--;a['E']--;
		pa[cn++]=5;
	}
	while(a['V'])//7
	{ a['S']--;a['E']--;a['V']--;a['E']--;a['N']--;
		pa[cn++]=7;
	}
	while(a['O'])//1
	{ a['O']--;a['N']--;a['E']--;
		pa[cn++]=1;
	}
	while(a['I'])//9
	{ a['N']--;a['I']--;a['N']--;a['E']--;
		pa[cn++]=9;
	}
	qsort(pa,cn,sizeof(int),cmp);
	for(i=0;i<cn;i++) printf("%d",pa[i]);
	printf("\n");
}
int main()
{  int k,T;
	scanf("%d\n",&T);
	for(k=0;k<T;k++)
	{  	 int i,cn=0;
		char s[25]={'\0'};
		gets(s);
		int alpha[200]={0};//记录对应字符个数，相当于也自动qsort了 
		int l=strlen(s);
		printf("case #%d:\n",k);
        for(i=0;i<l;i++) alpha[s[i]]++;
	    tran(alpha);
	}
	return 0;
}