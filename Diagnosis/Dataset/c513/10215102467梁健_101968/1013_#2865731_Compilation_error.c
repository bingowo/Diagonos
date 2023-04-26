#include<stdio.h>
#include<string.h>
int main()
{
    char a[32];
    int A=0,B=0,C=0;
    scanf("%s",a);
    int i=0,leng1=0,leng2=0;
    float res1=1,res2=1,resb=0;
    while(a[i++]!='.'&&i<=strlen(a)){
        leng1++;
    }
    int dotplace=i;
    leng2=strlen(a)-1-leng1;
    for(int step=1;step<leng1;step++){
        res1*=3;
    }
    if(a[0]!='0'){
        for(int step1=0;step1<=leng1;step1++){
            if(a[step1]=='1')A=A+res1;
            else if(a[step1]=='2')A=A-res1;
            res1/=3;
        }
    }
    if(dotplace!=strlen(a)){
    for(int step2=0;step2<leng2;step2++){
        if(a[dotplace+step2]=='1')resb=resb+res2/3;
        else if(a[dotplace+step2]=='2')resb=resb-res2/3;
        res2/=3;
    }
    B=resb/res2;
    C=1/res2;
    if(A==0)printf("%d %d",B,C);
    else if(B<0){
        printf("%d %d %d",A-1,C+B,C);
    }
    else printf("%d %d %d",A,B,C);
    return 0;
}
