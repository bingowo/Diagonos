#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read(char s[],int a[])
{
    int mid[26]={0},tmp=0,len=strlen(s),cnt=0;
    for(int i=0;i<len;i++){
        if(s[i]!=','){tmp=tmp*10+s[i]-48;}
        if(s[i]==',' || i==len-1){mid[cnt++]=tmp;tmp=0;}
    }
//    printf("%d\n",cnt);
//    for(int i=0;i<26;i++){printf("%d ",mid[i]);}
    int ks=26-cnt;
    for(int j=0;j<cnt;j++){
        a[ks++]=mid[j];
    }
}

void ADD(int a[],int b[],int c[])
{   int sushu[26]={0,97,89,83,79,73,71,67,61,59,53,
                47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    for(int i=25;i>0;i--){
        c[i]+=(a[i]+b[i])%sushu[i];
        c[i-1]+=(a[i]+b[i])/sushu[i];
    }
}

void output(int c[])
{
    int i=0;
    while(c[i]==0){i++;}
    if(i==26)i=25;
    for(int j=i;j<26;j++){
        printf("%d%c",c[j],(j==25)?'\n':',');
    }
}

int main()
{

    int n; scanf("%d",&n);
    for(int i=0;i<n;i++){
    char s[100];
        int a[26]={0},b[26]={0},c[26]={0};
        scanf("%s",s);
        read(s,a);
//        for(int i=0;i<26;i++){printf("%d ",a[i]);}
        scanf("%s",s);
        read(s,b);
        ADD(a,b,c);
//        for(int i=0;i<26;i++){printf("%d ",c[i]);}
        printf("case #%d:\n",i);
        output(c);
    }


    return 0;
}
