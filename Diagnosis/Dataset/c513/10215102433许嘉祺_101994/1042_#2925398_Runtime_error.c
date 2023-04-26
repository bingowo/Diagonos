#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b){
    char*p1=*(char(*)[16])a,*p2=*(char(*)[16])b;
    if(strcmp(a,b)>0) return 1;
    else return -1;
}

int main()
{
    int n;
    scanf("%d",&n);
    char s[100];
    char s1[26];
    int a[255];
    char s2[30000][16];
    for (int i=0;i<n;i++){
        int count=0;
        memset(a,0,sizeof(a));
        scanf("%s",s);
        for(int j=0;j<strlen(s);j++)
            a[s[j]]++;
        for (int j=0;j<244;j++)
        if (a[j]>0) s1[count++]=j;
        s1[count]=0;
        int sum=1;
        for (int j=0;j<count;j++)sum*=2;
        printf("case #%d:\n",i);
        for(int j=1;j<sum;j++)
        {   int num=0;
            for (int k=0;k<count;k++)
            {
                if((j>>k)&1==1) s2[j-1][num++]=s1[k];
            }
            s2[j-1][num]=0;

        }
        qsort(s2,sum-1,sizeof(s2[0]),cmp);
        for (int j=0;j<sum-1;j++)
            printf("%s\n",s2[j]);
    }


    return 0;
}