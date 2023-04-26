#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int cishu;
    int xishu;
}AAA;

int cmp(const void* p3,const void* p4)
{
    AAA* p1=(AAA* )p3;
    AAA* p2=(AAA* )p4;
    if((p1->cishu)<(p2->cishu)) return 1;
    else return -1;
}

int main()
{
    char s1[101],s2[101];
    while(scanf("%s %s",s1,s2)!=EOF){
        int len1=strlen(s1),len2=strlen(s2);
        AAA* p1=(AAA* )malloc(len1*sizeof(AAA));
        AAA* p2=(AAA* )malloc(len2*sizeof(AAA));
        int num1=0,num2=0,i=0,j=0,xi=0,sig=1;
        while(i<len1){
            if(isdigit(s1[i])){
                xi=xi*10+s1[i]-'0';
                i++;
            }
            else if(s1[i]=='x'){
                if(xi==0) xi=1;
                xi*=sig;
                if(s1[i+1]=='^'){
                    (p1+num1)->xishu=xi;
                    if(isdigit(s1[i+3])){
                        (p1+num1)->cishu=(s1[i+2]-'0')*10+s1[i+3]-'0';
                        num1++;
                        i+=4;
                    }
                    else{
                        (p1+num1)->cishu=s1[i+2]-'0';
                        num1++;
                        i+=3;
                    }
                }
                else {
                    (p1+num1)->xishu=xi;
                    (p1+num1)->cishu=1;
                    num1++;
                    i++;
                }
                xi=0;
                sig=1;
            }
            else if(s1[i]=='-') {
                sig=-1;
                i++;
            }
            else if(s1[i]=='+'){
                sig=1;
                i++;
            }
            if(i==len1){
                if(xi!=0) {
                    (p1+num1)->xishu=xi*sig;
                    (p1+num1)->cishu=0;
                    num1++;
                }
            }
        }
        xi=0;
        sig=1;
        while(j<len2){
            if(isdigit(s2[j])){
                xi=xi*10+s2[j]-'0';
                j++;
            }
            else if(s2[j]=='x'){
                if(xi==0) xi=1;
                xi*=sig;
                if(s2[j+1]=='^'){
                    (p2+num2)->xishu=xi;
                    if(isdigit(s2[j+3])){
                        (p2+num2)->cishu=(s2[j+2]-'0')*10+s2[j+3]-'0';
                        num2++;
                        j+=4;
                    }
                    else{
                        (p2+num2)->cishu=s2[j+2]-'0';
                        num2++;
                        j+=3;
                    }
                }
                else {
                    (p2+num2)->xishu=xi;
                    (p2+num2)->cishu=1;
                    num2++;
                    j++;
                }
                xi=0;
                sig=1;
            }
            else if(s2[j]=='-') {
                sig=-1;
                j++;
            }
            else if(s2[j]=='+'){
                sig=1;
                j++;
            }
            if(j==len2){
                if(xi!=0) {
                    (p2+num2)->xishu=xi*sig;
                    (p2+num2)->cishu=0;
                    num2++;
                }
            }
        }
        AAA* ans=(AAA* )malloc((num1*num2)*sizeof(AAA));
        int num3=0,ci=0;
        xi=0;
        for(int ii=0;ii<num1;ii++){
            for(int jj=0;jj<num2;jj++){
                ci=((p1+ii)->cishu)+((p2+jj)->cishu);
                xi=((p1+ii)->xishu)*((p2+jj)->xishu);
                int nn=0;
                for(;nn<num3;nn++){
                    if(((ans+nn)->cishu)==ci){
                        ((ans+nn)->xishu)+=xi;
                        break;
                    }
                }
                if(nn==num3){
                    (ans+num3)->cishu=ci;
                    (ans+num3)->xishu=xi;
                    num3++;
                }
            }
        }
        qsort(ans,num3,sizeof(AAA),cmp);
        for(int ww=0;ww<num3;ww++) {
            int d=(ans+ww)->xishu;
            if(d) printf("%d ",(ans+ww)->xishu);
        }
        printf("\n");
        free(p1);
        free(p2);
        free(ans);
    }
    return 0;
}
