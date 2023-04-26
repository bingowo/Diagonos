#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int p[128];

int cmp1(const void*a,const void*b)
{
    char c=*(char*)a;
    char d=*(char*)b;
    if(c<d) return -1;
    else return 1;
}

int cmp2(const void*a,const void*b)
{
    char *c=*(char**)a;
    char *d=*(char**)b;
    if(strcmp(c,d)<0) return -1;
    else return 1;
}

int main()
{
    int T,i=0,j=0,n=0,l=0,k=0,len=0;
    char s1[17]={0},s2[17]={0},**t;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        for(j=0;i<128;j++) p[j]=-1;
        len=0;
        scanf("%s",s1);
        l=strlen(s1);
        j=0;
        while(j<l)
        {
            if(p[s1[j]]==-1) {p[s1[j]]=0;s2[len]=s1[j];j++;len++;}
            else j++;
        }
        qsort(s2,len,sizeof(char),cmp1);
        t=(char**)malloc(pow(2,len)*sizeof(char*));
        for(j=0;j<(1<<len);j++)
            t[j]=(char*)malloc(17*sizeof(char));
        for(j=1;j<(1<<len);j++)//枚举从1到pow（2,len)
        {
            for(k=0,l=0;l<len;l++)
            {
                if((j>>l)&1)//j的二进制是1的地方存储字母，0的地方不存储
                {
                    t[j-1][k]=s2[l];
                    k++;
                }

                t[j-1][k]='\0';
            }
        }
       //用二进制枚举并记录字符排列的情况
       qsort(t,j-1,sizeof(t[0]),cmp2);
       printf("case #%d:\n",i);
       for(k=0;k<j-1;k++) printf("%s\n",t[k]);
       for(j=0;j<len;j++) s2[j]='\0';

    }
    return 0;
}
