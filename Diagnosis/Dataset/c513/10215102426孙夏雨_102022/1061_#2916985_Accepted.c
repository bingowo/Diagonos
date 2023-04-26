#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[16];
    long long int he;
}ZIF;

typedef struct
{
    char alp;
    int shuma;
}ZIM;

long long int f(int* p,int x,int leng)
{
    long long int all=0;
    for(int j=0;j<leng;j++) all=all*x+(*(p+j));
    return all;
}

int cmp(const void* p3,const void* p4)
{
    ZIF* p1=(ZIF* )p3;
    ZIF* p2=(ZIF* )p4;
    if((p1->he)>(p2->he)) return 1;
    else if((p1->he)<(p2->he)) return -1;
    else{
        if(strcmp(p1->s,p2->s)>0) return 1;
        else return -1;
    }
}

int main()
{
    int T=0;
    scanf("%d",&T);
    ZIF* p=(ZIF* )malloc(T*sizeof(ZIF));
    for(int t=0;t<T;t++){
        char s0[16];
        scanf("%s",s0);
        strcpy((p+t)->s,s0);
        int len=strlen(s0),jinzhi=2,num1=0,num2=0,max=0;
        ZIM* p1=(ZIM* )malloc(len*sizeof(ZIM));
        int* p2=(int* )malloc(len*sizeof(int));
        for(int i=0;i<len;i++){
            if(i==0){
                p1->alp=s0[i];
                p1->shuma=1;
                num1++;
                *(p2)=1;
                num2++;
            }
            else{
                int j=0;
                for(;j<num1;j++){
                    if(s0[i]==(p1+j)->alp){
                        *(p2+num2)=(p1+j)->shuma;
                        num2++;
                        break;
                    }
                }
                if(j==num1){
                    (p1+num1)->alp=s0[i];
                    (p1+num1)->shuma=max;
                    num1++;
                    *(p2+num2)=max;
                    num2++;
                    if(max==0) max+=2;
                    else max++;
                }
            }
        }
        if(max>2) jinzhi=max;
        long long int ww=f(p2,jinzhi,len);
        (p+t)->he=ww;
        free(p1);
        free(p2);
    }
    qsort(p,T,sizeof(ZIF),cmp);
    for(int ii=0;ii<T;ii++) printf("%s\n",(p+ii)->s);
    free(p);
    return 0;
}
