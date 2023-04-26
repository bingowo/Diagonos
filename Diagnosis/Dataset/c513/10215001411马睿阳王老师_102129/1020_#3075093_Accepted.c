#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char name[11]={"LIST /NAME"};
char size[11]={"LIST /SIZE"};
char time[11]={"LIST /TIME"};

typedef struct
{
    char blank[27],name[67],time[57];
    int num;
}file;

int cmpname(const void*a,const void*b)
{
    file c=*(file*)a;
    file d=*(file*)b;
    if(strcmp(c.name,d.name)<0) return -1;
    else if(strcmp(c.name,d.name)>=0) return 1;
}

int cmpsize(const void*a,const void*b)
{
    file c=*(file*)a;
    file d=*(file*)b;
    if(c.num<d.num) return -1;
    else if(c.num>d.num) return 1;
    else if(strcmp(c.name,d.name)>0) return 1;
    else return -1;
}

int cmptime(const void*a,const void *b)
{
    file c=*(file*)a;
    file d=*(file*)b;
    if(strcmp(c.time,d.time)<0) return -1;
    else if(strcmp(c.time,d.time)>0) return 1;
    else if(strcmp(c.name,d.name)<0) return -1;
    else return 1;
}

int main()
{
    int i=0,j=0,k=0,r=0,n;
    char s[1007];
    file ss[107];
    while(1)
    {
        scanf("%d",&n);
        gets(s);
        if(n!=0&&i!=0) printf("\n");
        if(n==0) break;
        for(i=0;i<n;i++)
        {
            gets(s);
            for(k=0,r=0;;k++,r++)
            {
                if(isdigit(s[k])&&isspace(s[k+1])&&isspace(s[k+2]))
                {
                    ss[i].time[r++]=s[k];
                    break;
                    
                }
                else ss[i].time[r]=s[k];
            }
            ss[i].time[r]='\0';
            for(j=k+1,r=0;isspace(s[j]);j++,r++)
                ss[i].blank[r]=s[j];
            ss[i].blank[r]='\0';
            for(k=j,ss[i].num=0;!isspace(s[k]);k++)
                ss[i].num=ss[i].num*10+s[k]-'0';
            for(j=k+1,r=0;!isspace(s[j]);j++,r++)
                ss[i].name[r]=s[j];
            ss[i].name[r]='\0';
        }
        gets(s);
        if(strstr(s,name)!=0) ///strstr检索name字符串在s字符串中出现的首要位置
        {
            qsort(ss,n,sizeof(ss[0]),cmpname);
            for(i=0;i<n;i++)
                printf("%s%s%d %s\n",ss[i].time,ss[i].blank,ss[i].num,ss[i].name);
        }
        else if(strstr(s,size)!=0)
        {
            qsort(ss,n,sizeof(ss[0]),cmpsize);
            for(i=0;i<n;i++)
                printf("%s%s%d %s\n",ss[i].time,ss[i].blank,ss[i].num,ss[i].name);
        }
        else if(strstr(s,time)!=0)
        {
            qsort(ss,n,sizeof(ss[0]),cmptime);
            for(i=0;i<n;i++)
                printf("%s%s%d %s\n",ss[i].time,ss[i].blank,ss[i].num,ss[i].name);
        }
    }
   return 0;
}
