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
    if(rh=='+'){b[2]=1;b[3]=1;}
    if(rh=='-'){b[2]=0;b[3]=1;}
    a[n-1]=rh;
    a[n]='\0';
}
void child(char fa[],char mo[],char ret[]){
    char f[4],m[4];
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
    if(f[2]||m[2])ret[4]=1;
    if(f[3]&&m[3])ret[5]=1;
}
char find(char c0,char c1,char p0,char p1){
    if(c0==p0||c0==p1)return c1;
    if(c1==p0||c1==p1)return c0;
}
void par(char ch[],char pa[],char ret[]){
    char c[4],p[4];
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
            if((pa[0]=='O'||pa[1]=='O')&&strcmp(ch,"O-")!=0&&strcmp(ch,"O+")!=0)ret[1]=1;
        }
        ret[4]=1;ret[5]=1;
    }
}
void prt(char ret[],int n){
    if(ret[0]&&n>0){
        n--;
        if(ret[4])printf("A+");
        if(ret[5]){
            if(ret[4])printf(",A-");
            else printf("A-");
        }
        printf("%c",n==0?'}':',');
    }
    if(ret[1]&&n>0){
        n--;
        if(ret[4])printf("AB+");
        if(ret[5]){
            if(ret[4])printf(",AB-");
            else printf("AB-");
        }
        printf("%c",n==0?'}':',');
    }
    if(ret[2]&&n>0){
        n--;
        if(ret[4])printf("B+");
        if(ret[5]){
            if(ret[4])printf(",B-");
            else printf("B-");
        }
        printf("%c",n==0?'}':',');
    }
    if(ret[3]&&n>0){
        n--;
        if(ret[4])printf("O+");
        if(ret[5]){
            if(ret[4])printf(",O-");
            else printf("O-");
        }
        printf("%c",n==0?'}':',');
    }
}
void prt2(char ret[]){
    for(int i=0;i<4;i++){
        if(ret[i]){
            if(i==0)printf("A-");
            if(i==1)printf("AB-");
            if(i==2)printf("B-");
            if(i==3)printf("O-");
            return;
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);getchar();
    while(t--){
        char fa[10],mo[10],ch[10];
        scanf("%s %s %s",fa,mo,ch);getchar();
        char ret[6]={0};
        if(strcmp("?",ch)==0){
            child(fa,mo,ret);int n=0;
            for(int i=0;i<4;i++){
                if(ret[i])n++;
            }
            if(n==1&&ret[4]==0){
                printf("%s %s ",fa,mo);
                prt2(ret);
            }
            else {
                printf("%s %s {",fa,mo);
                prt(ret,n);
            }
        }
        if(strcmp("?",fa)==0){
            par(ch,mo,ret);
            if(ret[0]==-1){
                printf("impossible %s %s",mo,ch);
            }
            else{
                int n=0;
                for(int i=0;i<4;i++){
                if(ret[i])n++;
                }
                putchar('{');
                prt(ret,n);
                printf(" %s %s",mo,ch);
            }
        }
        if(strcmp("?",mo)==0){
            par(ch,fa,ret);
            if(ret[0]==-1){
                printf("%s impossible %s",fa,ch);
            }
            else{
                int n=0;
                for(int i=0;i<4;i++){
                if(ret[i])n++;
                }
                printf("%s {",fa);
                prt(ret,n);
                printf(" %s",ch);
            }
        }
        putchar('\n');
    }
    return 0;
}