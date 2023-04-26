#include<stdio.h>
char key[4][3]={"A","AB","B","O"};
int read(char *s){
    char *s1;
    s1=s;
    if(*s1=='?')return 4;
    if(*s1=='O')return 3;
    if(*s1=='B')return 2;
    if(*s1=='A'&&*(s1+1)==0)return 0;
    else return 1;
}
void out(int father,int mother,int child,int *ans){
    int sum=0;
    for(int i=0;i<4;i++)sum+=*(ans+i);
    if(father==4){
        if(sum==0)printf("impossible %s %s",key[mother],key[child]);
        else{
            printf("{");
            for(int i=0;i<4;i++){
                if(ans[i]!=0&&sum>1){printf("%s,",key[i]);sum--;}
                else if(ans[i]!=0)printf("%s} ",key[i]);
            }
            printf("%s %s",key[mother],key[child]);
        }

    }
    else if(mother==4){
        if(sum==0)printf("%s impossible %s",key[father],key[child]);
        else{
            printf("%s {",key[father]);
            for(int i=0;i<4;i++){
                if(ans[i]!=0&&sum>1){printf("%s,",key[i]);sum--;}
                else if(ans[i]!=0)printf("%s} ",key[i]);
            }
            printf("%s",key[child]);
        }
    }
    else{
        if(sum==0)printf("%s %s impossible",key[father],key[mother]);
        else{
            printf("%s %s {",key[father],key[mother]);
            for(int i=0;i<4;i++){
                if(ans[i]!=0&&sum>1){printf("%s,",key[i]);sum--;}
                else if(ans[i]!=0)printf("%s}",key[i]);
            }
        }

    }
}
int main(){
    char s1[3],s2[3],s3[3];
    scanf("%s%s%s",s1,s2,s3);
    int mother,father,child;
    mother=read(s2),father =read(s1),child=read(s3);
    const char abc[4][4][5]={"1001","1110","1111","1001",
    "1110","1110","1110","1010",
    "1111","1110","0011","0011",
    "1001","1010","0011","0001"};
    int ans[4];
    if(child==4){
        for(int i=0;i<4;i++){
            if(abc[father][mother][i]=='1')ans[i]=1;
            else ans[i]=0;
        }
    }
    else if(mother==4){
        for(int i=0;i<4;i++){
            if(abc[father][i][child]=='1')ans[i]=1;
            else ans[i]=0;
        }

    }
    else if(father==4){
        for(int i=0;i<4;i++){
            if(abc[i][mother][i]=='1')ans[i]=1;
            else ans[i]=0;
        }
    }
    out(father,mother,child,ans);
    return 0;
}