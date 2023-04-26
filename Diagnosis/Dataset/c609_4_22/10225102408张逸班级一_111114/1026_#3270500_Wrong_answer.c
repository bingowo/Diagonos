#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int apha[128]={0};
int cmp(const void*a1,const void*a2){
    char*p1=*(char**)a1,*p2=*(char**)a2;
    char*cp1=p1,*cp2=p2;
    int sum1=0,sum2=0;
     while(*cp1){
        if(apha[*cp1]==0){apha[*cp1]=1;sum1++;}
        cp1++;
     }
     for(int i=0;i<128;i++){
        apha[i]=0;
     }
     while(*cp2){
        if(apha[*cp2]==0){apha[*cp2]=1;sum2++;}
        cp2++;
     }
     if(sum1!=sum2) return sum2-sum1;
     else if(sum1==sum2) return strcmp(p1,p2);
     return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
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
        printf("case #%d:\n",i);
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