#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main()
{
    char f[20];
    char map[41][42];
    do{
        scanf("%s",f);

        for(int i=0;i<42;i++)
            map[i][41]=0;

        for(int i=0;i<41;i++)
            for(int j=0;j<41;j++)
                map[i][j]='.';

        for(int i=0;i<41;i++)map[20][i]='-';

        for(int i=0;i<41;i++)map[i][20]='|';

        map[20][20]='+';map[0][20]='^';map[20][40]='>';
        int x3=0,x2=0,x=0,t=0;
        char s3[10]="x^3",s2[10]="x^2";
        if(strstr(f,s3)!=NULL){//确定x3系数
            int p3=strstr(f,s3)-f;
            //printf("p3=%d ",p3);
            if(p3==0)x3=1;
            else{
                char c[4];
                for(int i=5;i<p3;i++){
                    c[i-5]=f[i];
                }
                x3=atoi(c);
                if(strlen(c)==1&&c[0]=='-')x3=-1;
                if(strlen(c)==0)x3=1;
                if(strlen(c)==1&&c[0]=='+')x3=1;
                //printf("x3=%d\n",x3);
            }
        }
        if(strstr(f,s2)!=NULL){//确定x2系数
            int s2p=0,p2=strstr(f,s2)-f;
            for(int i=p2-1;i>=4;i--)
                if(!isdigit(f[i])){
                    if(f[i]=='+'||f[i]=='-')s2p=i;
                    else s2p=i+1;
                    break;
                }
            if(s2p==0)x2=1;
            else{
                char c[4];
                for(int i=s2p;i<p2;i++){
                    c[i-s2p]=f[i];
                }
                x2=atoi(c);
                if(strlen(c)==1&&c[0]=='-')x2=-1;
                if(strlen(c)==0)x2=1;
                if(strlen(c)==1&&c[0]=='+')x2=1;
                //printf("x2=%d\n",x2);
            }
        }
        //判断x系数；
        int xp=0;
        for(int i=5;i<strlen(f);i++){
            if(f[i]=='x'&&f[i+1]!='^'){
                xp=i;break;
            }
        }
        if(xp){
            x=1;
            int sxp=0;
            for(int i=xp-3;i<xp;i++){
                if(f[i]=='-'||f[i]=='+'){
                    sxp=i;break;
                }
            }
            char c[3];
            for(int i=sxp;i<xp;i++){
                c[i-sxp]=f[i];
            }
            x=atoi(c);
            if(strlen(c)==0)x=1;
            if(strlen(c)==1&&c[0]=='+')x=1;
            if(strlen(c)==1&&c[0]=='-')x=-1;
            //printf("x=%d\n",x);
        }
        //判断常数项系数；
        int len=strlen(f);
        if(f[len-1]!='x'&&f[len-2]!='^'){
            int scp=0;
            for(int i=len-1;i>=4;i--){
                if(!isdigit(f[i])){
                    if(f[i]=='+'||f[i]=='-')scp=i;
                    else scp=i+1;
                    break;
                }
            }
            char c[4];
            for(int i=scp;i<len;i++){
                c[i-scp]=f[i];
            }
            t=atoi(c);
            //printf("t=%d\n",t);
        }
        //printf("x3=%d x2=%d x=%d t=%d\n",x3,x2,x,t);
        long res[42];
        for(int i=-20;i<=20;i++){
            res[i+20]=x3*i*i*i+x2*i*i+x*i+t;
            //printf("x=%d,y=%ld\n",i,res[i+20]);
        }
        for(int i=0;i<=40;i++){
            if(abs(res[i])<=20){
                  map[20-res[i]][i]='*';
                  //printf("x=%d,y=%ld\n",i-20,res[i]);
            }
        }
        for(int i=0;i<=40;i++){
            printf("%s\n",map[i]);
        }
    }while(f!=EOF);
    return 0;
}
