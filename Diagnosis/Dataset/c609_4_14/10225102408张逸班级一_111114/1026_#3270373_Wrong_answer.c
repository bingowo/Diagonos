#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int apha[128]={0};
int cmp(const void*a1,const void*a2){
    char*p1=*(char**)a1,*p2=*(char**)a2;
    int sum1=0,sum2=0;
     while(*p1){
        char c=*p1;
     
        if(apha[c]==0){apha[c]=1;sum1++;}
        p1++;
     }
     for(int i=0;i<128;i++){
        apha[i]=0;
     }
     while(*p2){
        if(apha[*p2]==0){apha[*p2]=1;sum2++;}
        p2++;
     }
     if(sum1!=sum2)return sum2-sum1;
     else return strcmp(p1,p2);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("case #%d:\n",i);
        int m;
        scanf("%d",&m);
        char** s;
        s=(char**)malloc(sizeof(char*)*m);
        for(int j=0;j<m;j++){
            char*p=(char*)malloc(sizeof(char)*21);
            char c[21];
            scanf("%s",c);
            strcpy(p,c);
            *(s+j)=p;
        }
        qsort(s,m,sizeof(char*),cmp);
        for(int k=0;k<m;k++){
            printf("%s\n",s[k]);
        }
        for(int l=0;l<m;l++){
            char*f=*(s+l);
            free(f);
        }free(s);
    }
    return 0;
}