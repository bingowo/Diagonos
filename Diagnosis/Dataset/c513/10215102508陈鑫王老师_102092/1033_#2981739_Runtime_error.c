#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int MonthMap(char *s)
{
	int ret;
	if(strcmp(s, "pop") == 0)			{ ret = 1;}
	else if(strcmp(s, "no") == 0)		{ ret = 2;}
	else if(strcmp(s, "zip") == 0)		{ ret = 3;}
	else if(strcmp(s, "zotz") == 0)		{ ret = 4;}
	else if(strcmp(s, "tzec") == 0)		{ ret = 5;}
	else if(strcmp(s, "xul") == 0)		{ ret = 6;}
	else if(strcmp(s, "yoxkin") == 0)	{ ret = 7;}
	else if(strcmp(s, "mol") == 0)		{ ret = 8;}
	else if(strcmp(s, "chen") == 0)		{ ret = 9;}
	else if(strcmp(s, "yax") == 0)		{ ret = 10;}
	else if(strcmp(s, "zac") == 0)		{ ret = 11;}
	else if(strcmp(s, "ceh") == 0)		{ ret = 12;}
	else if(strcmp(s, "mac") == 0)		{ ret = 13;}
	else if(strcmp(s, "kankin") == 0)	{ ret = 14;}
	else if(strcmp(s, "muan") == 0)		{ ret = 15;}
	else if(strcmp(s, "pax") == 0)		{ ret = 16;}
	else if(strcmp(s, "koyab") == 0)	{ ret = 17;}
	else if(strcmp(s, "cumhu") == 0)	{ ret = 18;}
	else if(strcmp(s, "uayet") == 0)	{ ret = 19;}

	return ret;
}



typedef struct
{
    int day;
    char month[7];
    int year;
}maya;
int cmp(const void*a,const void*b)
{
    maya* x=(maya*)a;
    maya* y=(maya*)b;
    int m=x->year,n=y->year;
    int k=x->day,t=y->day;
    int index1=MonthMap(x->month),index2=MonthMap(y->month);
    if(m!=n)return m<n?-1:1;
    else if(index1!=index2) return index1<index2?-1:1;
    else
        return k<t?-1:1;

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        maya ans[n];
        for(int j=0;j<n;j++)
        {
            scanf("%d. %s %d",ans[j].day,ans[j].month,ans[j].year);
        }
        qsort(ans,n,sizeof(maya),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++)
        {
            printf("%d. %s %d\n",ans[j].day,ans[j].month,ans[j].year);
        }


    }
    return 0;
}
