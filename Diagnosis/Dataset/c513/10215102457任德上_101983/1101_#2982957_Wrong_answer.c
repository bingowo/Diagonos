#include<stdio.h>
char key[4][3]={"A","AB","B","O"};
char ke[2][2]={"+","-"};
int read(char *s,int t){
    char *s1;
    s1=s;
    if(*(s1+strlen(s1)-1)=='+')t=0;
    else if(*s1+strlen(s1)-1=='-')t=1;
    else t=-1;
    if(*s1=='?')return 4;
    if(*s1=='O')return 3;
    if(*s1=='B')return 2;
    if(*s1=='A'&&*(s1+1)!='B')return 0;
    else return 1;
}
void out(int father,int mother,int child,int *ans,int f1,int m1,int c1,int *bns){
    int sum=0,su=0;
    for(int i=0;i<4;i++)sum+=*(ans+i);
    for(int i=0;i<2;i++)su+=*(bns+i);
    if(father==4){
        if(sum==0||su==0)printf("impossible %s%s %s%s",key[mother],ke[m1],key[child],ke[c1]);
        else{
            printf("{");
            if(su==1){
                for(int i=0;i<4;i++){
                    if(ans[i]!=0&&sum>1){printf("%s-,",key[i]);sum--;}
                    else if(ans[i]!=0)printf("%s-} ",key[i]);
                }
                printf("%s%s %s%s",key[mother],ke[m1],key[child],ke[c1]);
            }
            else{
                for(int i=0;i<4;i++){
                    if(ans[i]!=0&&sum>1){printf("%s+,%s-,",key[i],key[i]);sum--;}
                    else if(ans[i]!=0)printf("%s+,%s-} ",key[i],key[i]);
                }
                if(bns[1])
                printf("%s%s %s%s",key[mother],ke[m1],key[child],ke[c1]);
            }
        }

    }
    else if(mother==4){
        if(sum==0||su==0)printf("%s%s impossible %s%s",key[father],ke[f1],key[child],ke[c1]);
        else{
            printf("%s%s {",key[father],ke[f1]);
            if(su==1){
                for(int i=0;i<4;i++){
                    if(ans[i]!=0&&sum>1){printf("%s-,",key[i]);sum--;}
                    else if(ans[i]!=0)printf("%s-} ",key[i]);
                }
                printf("%s%s",key[child],ke[c1]);
            }
            else{
                for(int i=0;i<4;i++){
                    if(ans[i]!=0&&sum>1){printf("%s+,%s-,",key[i],key[i]);sum--;}
                    else if(ans[i]!=0)printf("%s+,%s-} ",key[i],key[i]);
                }
                printf("%s%s",key[child],ke[c1]);
            }

        }
    }
    else{
        if(sum==0||su==0)printf("%s%s %s%s impossible",key[father],ke[f1],key[mother],ke[m1]);
        else{
            printf("%s%s %s%s {",key[father],ke[f1],key[mother],ke[m1]);
            if(su==1){
                for(int i=0;i<4;i++){
                    if(ans[i]!=0&&sum>1){printf("%s-,",key[i]);sum--;}
                    else if(ans[i]!=0)printf("%s-}",key[i]);
                }
            }
            else{
                for(int i=0;i<4;i++){
                    if(ans[i]!=0&&sum>1){printf("%s+,%s-,",key[i],key[i]);sum--;}
                    else if(ans[i]!=0)printf("%s+,%s-}",key[i],key[i]);
                }




            }
        }

    }
    printf("\n");
}
int main(){
    char s1[3],s2[3],s3[3];
    int t,flag=0;
    scanf("%d",&t);
    const char abc[4][4][5]={"1001","1110","1111","1001",
    "1110","1110","1110","1010",
    "1111","1110","0011","0011",
    "1001","1010","0011","0001"};
    const char zf[2][2][3]={"11","11","11","01"};
    for(int i=0;i<t;i++){
        scanf("%s%s%s",s1,s2,s3);
        int mother,father,child,m1,f1,c1;
        mother=read(s2,m1),father =read(s1,f1),child=read(s3,c1);
        int ans[4],bns[2];
        if(child==4){
            for(int i=0;i<4;i++){
                if(abc[father][mother][i]=='1')ans[i]=1;
                else ans[i]=0;
            }
            for(int i=0;i<2;i++){
                if(zf[f1][m1][i]=='1')bns[i]=1;
                else bns[i]=0;
            }
        }
        else if(mother==4){
            for(int i=0;i<4;i++){
                if(abc[father][i][child]=='1')ans[i]=1;
                else ans[i]=0;
            }
            for(int i=0;i<2;i++){
                if(zf[f1][i][c1]=='1')bns[i]=1;
                else bns[i]=0;
            }

        }
        else if(father==4){
            for(int i=0;i<4;i++){
                if(abc[i][mother][child]=='1')ans[i]=1;
                else ans[i]=0;
            }
            for(int i=0;i<2;i++){
                if(zf[i][m1][c1]=='1')bns[i]=1;
                else bns[i]=0;
            }
        }
        out(father,mother,child,ans,f1,m1,c1,bns);
    }
    return 0;
}