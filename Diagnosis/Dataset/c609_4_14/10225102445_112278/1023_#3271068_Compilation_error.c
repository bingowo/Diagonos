#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct F
{char s[30];
    int day;
char month[10];
int Month;
int year;

};
int cmp(const void* a,const void *b)
{struct F*aa=(struct F*)a;
struct F*bb=(struct F*)b;
if(aa->year!=bb->year){return aa->year-bb->year;}
else if (aa->Month!=bb->Month)return aa->Month-bb->Month;
else return aa->day-bb->day;
}
void strcpy1(char*s1,char*s2,int A,int B)
{int j=0;
    for(int i=A;i<=B;i++)
{s1[j]=s2[i];j++;

}
s1[j]='\0'
return ;
}
int main()
{int T,i,g,z;
scanf("%d\n",&T);
char M[19][10]={"pop","no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
for(i=0;i<=T-1;i++)
{
    scanf("%d\n",&g);
struct F stu[g];
for(int j=0;j<=g-1;j++)
    {fgets(stu[j].s,27,stdin);}
    int hh=strlen(stu[g-1].s);
    stu[g-1].s[hh-1]='\n';
    stu[g-1].s[hh]='\0';
for(int j=0;j<=g-1;j++)
{
if(stu[j].s[1]!='.'){stu[j].day=(stu[j].s[0]-48)*10+(stu[j].s[1]-48);
for(int n=4;n<=strlen(stu[j].s)-2;n++){if(stu[j].s[n]==' '){ z=n;break;}}
strcpy1(stu[j].month,stu[j].s,4,z-1);
int k=1;stu[j].year=0;
for(int p=strlen(stu[j].s)-2;p>=z+1;p--){stu[j].year+=(stu[j].s[p]-48)*k;k*=10;}
}

else if(stu[j].s[1]=='.'){stu[j].day=stu[j].s[0]-48;
for(int n=3;n<=strlen(stu[j].s)-2;n++){if(stu[j].s[n]==' '){ z=n;break;}}
strcpy1(stu[j].month,stu[j].s,3,z-1);
int k=1;stu[j].year=0;
for(int p=strlen(stu[j].s)-2;p>=z+1;p--){stu[j].year+=(stu[j].s[p]-48)*k;k*=10;}
}
for(int e=0;e<=18;e++){if(strcmp(stu[j].month,M[e])==0){stu[j].Month=e;break;}}

}
qsort(stu,g,sizeof(stu[0]),cmp);
printf("case #%d:\n",i);
for(int u=0;u<=g-1;u++){printf("%s",stu[u].s);}
}
return 0;
}
