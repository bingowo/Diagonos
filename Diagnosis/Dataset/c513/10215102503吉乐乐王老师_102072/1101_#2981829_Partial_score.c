#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void judge(char *a,char *b){
    int n=strlen(a);
    char rh=a[n-1];
    a[n-1]='\0';
    if(strcmp("A",a)==0){
        b[0]='A',b[1]='O';
    }
    if(strcmp("AB",a)==0){
        b[0]='A',b[1]='B';
    }
    if(strcmp("B",a)==0){
        b[0]='B',b[1]='O';
    }
    if(strcmp("O",a)==0){
        b[0]='O',b[1]='O';
    }
    a[n-1]=rh;
    a[n]='\0';
}
void child(char fa[],char mo[],int ret[]){
    char f[2],m[2];
    judge(fa,f);
    judge(mo,m);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){//C代表AB血型
            if((f[i]=='A'&&m[j]=='A')||(f[i]=='A'&&m[j]=='O')||(f[i]=='O'&&m[j]=='A'))ret[0]=1;
            if((f[i]=='A'&&m[j]=='B')||(f[i]=='B'&&m[j]=='A'))ret[1]=1;
            if(f[i]=='O'&&m[j]=='O')ret[3]=1;
            if((f[i]=='B'&&m[j]=='B')||(f[i]=='B'&&m[j]=='O')||(f[i]=='O'&&m[j]=='B'))ret[2]=1;
        }
    }
    char ch1=fa[strlen(fa)-1],ch2=mo[strlen(mo)-1];
    if(ch1=='+'||ch2=='+'){ret[4]=1;ret[5]=1;}
    if(ch1=='-'&&ch2=='-'){ret[4]=0;ret[5]=1;}
}
char find(char c0,char c1,char p0,char p1){
    if(c0==p0||c0==p1)return c1;
    if(c1==p0||c1==p1)return c0;
}
void par(char ch[],char pa[],int ret[]){
    char c[2],p[2];
    judge(ch,c);
    judge(pa,p);
    if((c[0]!=p[0]&&c[0]!=p[1])&&(c[1]!=p[0]&&c[1]!=p[1]))ret[0]=-1;
    else{
        char oth=find(c[0],c[1],p[0],p[1]);
        if(oth=='A'){
            ret[0]=1;ret[1]=1;
        }
        if(oth=='B'){
            ret[1]=1;ret[2]=1;
        }
        if(oth=='O'){
            ret[3]=1;ret[0]=1;ret[2]=1;
            if(strcmp(ch,"O-")!=0&&strcmp(ch,"O+")!=0)ret[1]=1;
        }
    }
    char ch1=pa[strlen(pa)-1],ch2=ch[strlen(ch)-1];
    if(ch1=='-'&&ch2=='+'){ret[4]=1;ret[5]=0;}
    else{ret[4]=1;ret[5]=1;}
}
int main(){
    int t;
    scanf("%d",&t);getchar();
    while(t--){
        char fa[4],mo[4],ch[4];
        scanf("%s %s %s",fa,mo,ch);getchar();
        int ret[6]={0};
        char ans[10][10];int idx=0;
        if(strcmp("?",ch)==0){
            child(fa,mo,ret);int n=0;
            if(ret[0]){
                if(ret[4])strcpy(ans[idx++],"A+");
                if(ret[5])strcpy(ans[idx++],"A-");
            }
            if(ret[1]){
                if(ret[4])strcpy(ans[idx++],"AB+");
                if(ret[5])strcpy(ans[idx++],"AB-");
            }
            if(ret[2]){
                if(ret[4])strcpy(ans[idx++],"B+");
                if(ret[5])strcpy(ans[idx++],"B-");
            }
            if(ret[3]){
                if(ret[4])strcpy(ans[idx++],"O+");
                if(ret[5])strcpy(ans[idx++],"O-");
            }
            if(idx==1)printf("%s %s %s",fa,mo,ans[0]);
            else {
                printf("%s %s {",fa,mo);
                for(int i=0;i<idx;i++){
                    printf("%s",ans[i]);
                    if(i!=idx-1)putchar(',');
                }
                putchar('}');
            }
        }
        else if(strcmp("?",fa)==0){
            par(ch,mo,ret);
            if(ret[0]==-1){
                printf("impossible %s %s",mo,ch);
            }
            else{
                if(ret[0]){
                if(ret[4])strcpy(ans[idx++],"A+");
                if(ret[5])strcpy(ans[idx++],"A-");
                }
                if(ret[1]){
                    if(ret[4])strcpy(ans[idx++],"AB+");
                    if(ret[5])strcpy(ans[idx++],"AB-");
                }
                if(ret[2]){
                    if(ret[4])strcpy(ans[idx++],"B+");
                    if(ret[5])strcpy(ans[idx++],"B-");
                }
                if(ret[3]){
                    if(ret[4])strcpy(ans[idx++],"O+");
                    if(ret[5])strcpy(ans[idx++],"O-");
                }
                if(idx==1)printf("%s %s %s",ans[0],mo,ch);
                else {
                    putchar('{');
                    for(int i=0;i<idx;i++){
                        printf("%s",ans[i]);
                        if(i!=idx-1)putchar(',');
                    }
                    putchar('}');
                    printf(" %s %s",mo,ch);
                }
            }
        }
        else if(strcmp("?",mo)==0){
            par(ch,fa,ret);
            if(ret[0]==-1){
                printf("%s impossible %s",fa,ch);
            }
            else{
                    if(ret[0]){
                    if(ret[4])strcpy(ans[idx++],"A+");
                    if(ret[5])strcpy(ans[idx++],"A-");
                    }
                    if(ret[1]){
                        if(ret[4])strcpy(ans[idx++],"AB+");
                        if(ret[5])strcpy(ans[idx++],"AB-");
                    }
                    if(ret[2]){
                        if(ret[4])strcpy(ans[idx++],"B+");
                        if(ret[5])strcpy(ans[idx++],"B-");
                    }
                    if(ret[3]){
                        if(ret[4])strcpy(ans[idx++],"O+");
                        if(ret[5])strcpy(ans[idx++],"O-");
                    }
                    if(idx==1)printf("%s %s %s",fa,ans[0],ch);
                    else {
                        printf("%s {",fa);
                        for(int i=0;i<idx;i++){
                            printf("%s",ans[i]);
                            if(i!=idx-1)putchar(',');
                        }
                        printf("} %s",ch);
                    }
                }//
            }
            putchar('\n');
        }
}
