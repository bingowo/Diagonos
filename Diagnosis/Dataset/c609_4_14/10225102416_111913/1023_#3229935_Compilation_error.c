//pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[19][7] =
{"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","mu
an","pax","koyab","cumhu","uayet"};
typedef struct{
char s[100];
char ak[10];
int month;
int day;
int year;
}node;
int cmp(const void*a,const void*b)
{
node *pa = (node*)a;
node *pb = (node*)b;
if(pa->year != pb->year)
return pa->year - pb->year;
else
{
if(pa->month != pb->month)
return pa->month - pb->month;
else
return pa->day - pb->day;
}
}
int main()
{
int n;scanf("%d",&n);
for(int i = 0;i < n;i++)
{
printf("case #%d:\n",i);
int len;scanf("%d",&len);
char c;c = getchar();
node ch[len];
for(int j = 0;j < len;j++)
{
memset(ch[j].s,'\0',sizeof(ch[j].s));
memset(ch[j].ak,'\0',sizeof(ch[j].ak));
fgets(ch[j].s,30,stdin);
sscanf(ch[j].s,"%d. %s %d",&ch[j].day,ch[j].ak,&ch[j].year);
for(int p = 0;p < 19;p++)
{
if(strcmp(ch[j].ak,s[p]) == 0)
{
ch[j].month = p+1;
break;
}
}
}
qsort(ch,len,sizeof*ch,cmp);
for(int u = 0;u < len;u++)
{
printf("%s",ch[u].s);
}
}
return 0;
}