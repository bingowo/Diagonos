#include<stdio.h>
int main()
{
    int A=0,B=0,i=0,j=0,m=0,t=1;
    char n[32],r[50],k;
    scanf("%d",&A);
    k=getchar();
    while((n[i]=getchar())!=' '){
        i++;
    }

    scanf("%d",&B);
    //转10进制
    for(j=i-1;j>=0;j--){
        if((n[j]-'0')<10){
            m=m+(n[j]-'0')*t;
        }
        else if((n[j]-'A')<26){
            m=m+(n[j]-'A'+10)*t;
        }
        else{
            m=m+(n[j]-'a'+10)*t;
        }
        t=t*A;
    }
    //转B进制
    if(m==0){
        printf("0");
    }
    else{
        i=0;
        for(m=m;m>0;){
            t=m%B;
            m=m/B;
            if(t<10){
                r[i]=t+'0';
            }
            else{
                r[i]=t-10+'A';
            }
            i++;
        }
        for(i=i-1;i>=0;i--){
            printf("%c",r[i]);
        }
    }
    return 0;
}
