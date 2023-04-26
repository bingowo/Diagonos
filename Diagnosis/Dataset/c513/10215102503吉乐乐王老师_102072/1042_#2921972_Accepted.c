#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b){
    return *(char*)a-*(char*)b;
}
int scmp(const void *a,const void *b){
    return strcmp((char*)a,(char*)b);
}
void add(int bin[],int n)
{
    bin[n-1]+=1;
    for(int i=n-1;i>0;i--){
        bin[i-1]+=bin[i]/2;
        bin[i]%=2;
    }
}
int main(){
    int t;scanf("%d",&t);getchar();int cas=0;
    while(t--){
        char table[128];
        memset(table,0,128);
        char s[20];
        char *p=s;
        int n=0;
        gets(s);
        while(*p){
            if(table[*p]==0){
                table[*p]=1;
                n++;}
            p++;
        }
        char *alb=(char *)malloc(n);
        p=alb;
        for(int i=0;i<128;i++){
            if(table[i]){
                *p=i;p++;
            }
        }
        qsort(alb,n,sizeof(alb[0]),cmp);
        char ret[70000][17];int ri=0;
        int *bin=(int *)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)bin[i]=0;
        int nof=(1<<n)-1;
        for(int i=1;i<=nof;i++){
            add(bin,n);
            char temp[20];
            p=temp;
            for(int j=0;j<n;j++){
                if(bin[j]){
                    *p=alb[j];p++;
                }
            }
            *p='\0';
            strcpy(ret[ri],temp);ri++;
        }
        qsort(ret,ri,sizeof(ret[0]),scmp);
        printf("case #%d:\n",cas++);
        for(int i=0;i<ri;i++){
            printf("%s\n",ret[i]);
        }
    }
}