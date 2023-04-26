#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
char date[11];
char time[6];
int size;
char name[70];
}message;
int cmptime(const void*a, const void*b)
{
message *p1=(message*)a, *p2=(message*)b;
if(!strcmp(p1->date, p2->date))
{
if(!strcmp(p1->time, p2->time))
return strcmp(p1->name, p2->name);
return strcmp(p1->time, p2->time);
}
return strcmp(p1->date, p2->date);
}
int cmpname(const void*a, const void*b)
{
message *p1=(message*)a, *p2=(message*)b;
return strcmp(p1->name, p2->name);
}
int cmpsize(const void*a, const void*b)
{
message *p1=(message*)a, *p2=(message*)b;
if(p1->size==p2->size) return strcmp(p1->name, p2->name);
return p1->size-p2->size;
}
int main()
{
int n;
scanf("%d",&n);
while(n != 0)
{
message *ch = malloc(n * sizeof * ch);
for(int i = 0;i < n;i++) {
scanf("%s %s %d %s"
, ch[i].date
, ch[i].time
, &ch[i].size
, ch[i].name);
}
char std1[10] = {0},std2[10] = {0};
scanf("%s %s",std1,std2);
if(std2[1] == 'N'){
qsort(ch,n,sizeof*ch,cmpname);
}
else if(std2[1] == 'S'){
qsort(ch,n,sizeof*ch,cmpsize);
}
else{
qsort(ch,n,sizeof*ch,cmptime);
}
for(int j = 0;j < n;j++){
printf("%s %s %16d %s\n"
,ch[j].date
,ch[j].time
,ch[j].size
,ch[j].name);
}
printf("\n");
scanf("%d",&n);
}
return 0;
}