#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct{
    char *str;
    int cnt;
}dna;
int cmp1(const void *a,const void *b){
    return strcmp((char*)a,(char*)b);
}
int cmp2(const void *a,const void *b){
    dna *data1=(dna*)a,*data2=(dna*)b;
    if(data1->cnt==data2->cnt)return (strcmp(data1->str,data2->str));
    return data1->cnt>data2->cnt?1:-1;
}
int main()
{
    int n;
    scanf("%d",&n);getchar();
    char string[200000][21];
    for(int i=0;i<n;i++){
        scanf("%s",string[i]);getchar();
    }
    qsort(string,n,sizeof(string[0]),cmp1);
    dna data[200000];
    int idx=0;
    for(int i=0;i<n;i++){
        data[idx].str=string[i];
        data[idx].cnt=1;
        while(i<n-1&&strcmp(string[i],string[i+1])==0){data[idx].cnt++;i++;}
        idx++;
    }
    qsort(data,idx,sizeof(data[0]),cmp2);
    for(int i=0;i<idx;i++){
        printf("%s\n",data[i].str);
    }
    return 0;
}
