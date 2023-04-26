#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b){
    char*p1=*(char(*)[500])a,*p2=*(char(*)[500])b;
    
    if(strcmp(p1,p2)==1) {printf("hhhh\n");return 1;}
    else return -1;
}

int main()
{


    int n;
    scanf("%d",&n);
    getchar();
    char s[1000];
    int num=0;
    char a[501][500];
    for (int i=0;i<n;i++){
        gets(s);
        num=0;
        for (int j=0;j<strlen(s);j++){
            int len=0;

            while(s[j]!=' '&&s[j]!=','&&s[j]!='.'&&s[j]!='!'&&s[j]!='?'&&j<strlen) a[num][len++]=s[j++];
            a[num++][len]=0;
            if (strlen(a[num-1])==0) num--;
        }
        qsort(a,num,sizeof(char(*)[500]),cmp);
        printf("case #%d:\n",i);
        for (int j=0;j<num;j++) printf("%s\n",a[j]);
        for (int j=0;j<num;j++){
            while(strcmp(a[j],a[j+1])==0&&j<num-1) j++;
            if (j==num-1)
            printf("%s\n",a[j]);
            else printf("%s ",a[j]);}
    }
    return 0;
}
