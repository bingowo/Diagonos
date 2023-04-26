#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
    char time[50];
    unsigned char name[100];
    long long size;
}file;

file readfile(char*s)
{
    file a;
    int l=strlen(s),i=0,p=0;
    a.size=0;
    for(int j=0;j<17;j++) a.time[j]=0;
    for(int j=0;j<64;j++) a.name[j]=0;
    while(i<16) {a.time[i]=s[i];i++;}    //读取修改时间
    p=0;
    while(s[i]==' ') i++;                //跳过中间空格
    while(s[i]!=' ') {a.size=a.size*10+(s[i]-'0');i++;}    //读取文件大小
    i++;
    while(i<l) {a.name[p]=s[i];p++;i++;}         //读取文件名字
    return a;
}

int cmpname(const void*a,const void*b)
{
    file a0=*(file*)a,b0=*(file*)b;
    return strcmp(a0.name,b0.name);
}

int cmptime(const void*a,const void*b)
{
    file a0=*(file*)a,b0=*(file*)b;
    int flag=strcmp(a0.time,b0.time);
    if(flag!=0) return flag;
    else return strcmp(a0.name,b0.name);
}

int cmpsize(const void*a,const void*b)
{
    file a0=*(file*)a,b0=*(file*)b;
    if(a0.size>b0.size) return 1;
    else if(a0.size<b0.size) return -1;
    else return strcmp(a0.name,b0.name);
}

int main()
{
    int n;
    scanf("%d\n",&n);
    char order[100];
    char command[4][100]={"LIST /NAME","LIST /TIME","LIST /SIZE"};
    while(n!=0)
    {
        file File[1000];
        for(int i=0;i<n;i++)
        {
            unsigned char s[100];
            gets(s);
            File[i]=readfile(s);
        }
        gets(order);
        if(strcmp(order,command[0])==0) qsort(File,n,sizeof(File[0]),cmpname);
        else if(strcmp(order,command[1])==0) qsort(File,n,sizeof(File[0]),cmptime);
        else if(strcmp(order,command[2])==0) qsort(File,n,sizeof(File[0]),cmpsize);
        //按照指令排序
        for(int i=0;i<n;i++) printf("%s%17lld %s\n",File[i].time,File[i].size,File[i].name);
        //按照格式输出
        printf("\n");

        scanf("%d\n",&n);
        //输入下次待排序的文件个数
    }

    return 0;
}
