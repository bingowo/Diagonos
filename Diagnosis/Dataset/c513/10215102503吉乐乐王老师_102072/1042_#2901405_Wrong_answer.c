#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b){
    return *(char*)a-*(char*)b;
}
int scmp(const void *a,const void *b){
    char*x=*(char**)a;
    char*y=*(char**)b;
    return strcmp(x,y);
}
int dfs(char **ret,char alb[],int id,int cnt,char temp[]){
    static int ri=0;
    if(alb[id]=='\0'){
        temp[cnt]='\0';
        if(strlen(temp)>0){
            strcpy(ret[ri],temp);ri++;
        }
        return ri;
    }
    else {
        dfs(ret,alb,id+1,cnt,temp);
        temp[cnt]=alb[id];
        dfs(ret,alb,id+1,cnt+1,temp);
    }
}
int main(){
    int t;scanf("%d",&t);getchar();int cas=0;
    while(t--){
        char table[128];
        memset(table,0,128);
        char s[20];char *p=s;int n=0;
        scanf("%s",s);
        while(*p){
            if(table[*p]==0){
                table[*p]=1;
                n++;}
            p++;
        }
        char *alb=(char *)malloc(n+1);p=alb;
        for(int i=0;i<128;i++){
            if(table[i]){
                *p=i;p++;
            }
        }
        qsort(alb,n,sizeof(alb[0]),cmp);
        alb[n]='\0';
        char *temp=(char*)malloc(n+1);
        char **ret=(char**)malloc(sizeof(char*)*100);
        for(int i=0;i<100;i++){
            ret[i]=(char*)malloc(100);
        }
        int ri;
        ri=dfs(ret,alb,0,0,temp);
        qsort(ret,ri,sizeof(ret[0]),scmp);
        printf("case #%d:\n",cas++);
        for(int i=0;i<ri;i++){
            printf("%s\n",ret[i]);
        }
    }
}