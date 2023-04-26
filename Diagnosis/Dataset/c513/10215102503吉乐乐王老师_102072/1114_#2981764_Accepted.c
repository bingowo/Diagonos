#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
typedef struct{
    int factor1,factor2;
}node;
int main(){
    int a=0,b=0,c=0;
    char s[15];
    scanf("%s",s);
    char *p;
    if(strstr(s,"^2")!=NULL){
        p=s;
        if(*p=='x')a=1;
        else if(*p=='-'&&*(p+1)=='x')a=-1;
        else sscanf(s,"%d",&a);
    }
    p=s+strlen(s)-1;
    if(*p=='x'){
        while(*p!='+'&&*p!='-'&&(p-s)>0)p--;
        if(*p=='x'||*p=='+'&&*(p+1)=='x')b=1;
        else if(*p=='-'&&*(p+1)=='x')b=-1;
        else sscanf(p,"%d",&b);
    }
    else if(isdigit(*p)){
        if((p-s)>0&&*(p-1)=='^');
        else{
            while(*p!='+'&&*p!='-'&&(p-s)>0)p--;
            sscanf(p,"%d",&c);
        }
        if(p-s>0){
            p--;
            if(*p=='x'){
            while(*p!='+'&&*p!='-'&&(p-s)>0)p--;
            if(*p=='x'||*p=='+'&&*(p+1)=='x')b=1;
            else if(*p=='-'&&*(p+1)=='x')b=-1;
            else sscanf(p,"%d",&b);
            }
        }
    }
    if(b*b-4*a*c<0){
        printf("No Answer!");
    }
    else{
        node aa[20],cc[20];
        int na=0,nc=0;
        if(a>0)for(int i=1;i<sqrt(a)+1;i++){
                if(a%i==0){
                    aa[na].factor1=i;
                    aa[na].factor2=a/i;
                    na++;
                    aa[na].factor1=-i;
                    aa[na].factor2=-a/i;
                    na++;
                }
            }
        else{
            for(int i=-1;i>-sqrt(abs(a))-1;i--){
                if(a%i==0){
                    aa[na].factor1=i;
                    aa[na].factor2=a/i;
                    na++;
                    aa[na].factor1=-i;
                    aa[na].factor2=-a/i;
                    na++;
                }
            }
        }
        if(c>0)for(int i=1;i<sqrt(c)+1;i++){
                if(c%i==0){
                    cc[nc].factor1=i;
                    cc[nc].factor2=c/i;
                    nc++;
                    cc[nc].factor1=-i;
                    cc[nc].factor2=-c/i;
                    nc++;
                }
            }
        else{
            for(int i=-1;i>-sqrt(abs(c))-1;i--){
                if(c%i==0){
                    cc[nc].factor1=i;
                    cc[nc].factor2=c/i;
                    nc++;
                    cc[nc].factor1=-i;
                    cc[nc].factor2=-c/i;
                    nc++;
                }
            }
        }
        int a1,c1,a2,c2;
        int flag=0;
        if(nc==0){
            a1=a,c1=b;
            a2=1;c2=0;
            if(a==0){
                a1=b;c1=0;
                a2=0;c2=0;
            }
        }
        for(int i=0;i<na;i++){
            for(int j=0;j<nc;j++){
                if((aa[i].factor1*cc[j].factor2+aa[i].factor2*cc[j].factor1)==b){
                    a1=aa[i].factor1;c1=cc[j].factor1;
                    a2=aa[i].factor2;c2=cc[j].factor2;
                    flag=1;break;
                }
                else if((aa[i].factor1*cc[j].factor1+aa[i].factor2*cc[j].factor2)==b){
                    a1=aa[i].factor1;c1=cc[j].factor2;
                    a2=aa[i].factor2;c2=cc[j].factor1;
                    flag=1;break;
                }
            }
            if(flag)break;
        }
        if(a1==a2){
            if(c1<c2)printf("%d %d %d %d",a1,c1,a2,c2);
            else printf("%d %d %d %d",a2,c2,a1,c1);
        }
        else{
            if(a1<a2)printf("%d %d %d %d",a1,c1,a2,c2);
            else printf("%d %d %d %d",a2,c2,a1,c1);
        }
        putchar('\n');
    }
}