#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getFirstPoly(int n, int expo, char curRes[]){
    if(n==0){
        return;
    }
    char coef[20];memset(coef,0,20*sizeof(char));
    sprintf(coef,"%d",n);

    if(expo == 0){
        strcat(curRes,coef);
        //printf("%d: expo = 0, curRes = %s\n",n,curRes);
        return;
    }
    else if(expo == 1){
        strcat(curRes,coef);
        strcat(curRes,"x");
        //printf("%d: expo = 1, curRes = %s\n",n,curRes);
        return;
    }
    else{
        char xToE[10];memset(xToE,0,10*sizeof(char));
        xToE[0] = 'x'; xToE[1] = '^'; xToE[2] = expo+'0';
        if(n==1){
            strcat(curRes,xToE);
            return;
        }
        else if(n==-1){
            curRes[0] = '-';
            strcat(curRes,xToE);
            return;
        }

        strcat(curRes,coef);
        strcat(curRes,xToE);
        //printf("%d: xToE = %s, curRes = %s\n",n,xToE,curRes);
    }
    return;
}

void getOnePoly(int n, int expo, char curRes[]){
    if(n==0){
        return;
    }
    char coef[20];memset(coef,0,20*sizeof(char));
    sprintf(coef,"%d",n);

    if(expo == 0){
        if(n>0){
            curRes[0] = '+';
        }
        strcat(curRes,coef);
        //printf("%d: expo = 0, curRes = %s\n",n,curRes);
        return;
    }

    else{
        char xToE[10];memset(xToE,0,10*sizeof(char));
        xToE[0] = 'x'; xToE[1] = '^'; xToE[2] = expo+'0';
        if(n==1){
            curRes[0] = '+';
            strcat(curRes,xToE);
            return;
        }
        else if(n==-1){
            curRes[0] = '-';
            strcat(curRes,xToE);
            return;
        }

        if (n>0){
            curRes[0] = '+';
        }
        strcat(curRes,coef);
        if(expo!=1){
            strcat(curRes,xToE);
        }

        else if(expo == 1){
            strcat(curRes,"x");
        }
        //printf("%d: expo = 1, curRes = %s\n",n,curRes);
        return;

        //printf("%d: xToE = %s, curRes = %s\n",n,xToE,curRes);
    }
    return;
}

void getPolynomial(int nums[], int len, char res[]){
    int notAllZero = 0;
    for(int i = 0;i<len;i++){
        if(nums[i]!=0){
            notAllZero = 1;
            break;
        }
    }
    if(notAllZero==0){//全都为0
        res[0] = '0';
        //printf("allzero\n");
        return;
    }
    int i = 0;
    while(nums[i]==0){
        i++;
    }
    char firstPoly[20];
    getFirstPoly(nums[i],len-i-1,firstPoly);
    strcat(res,firstPoly);
    //printf("firstPoly = %s, res = %s\n",firstPoly,res);//第一个不为零的多项式
    i++;

    for(;i<len;i++){
        char curRes[20];memset(curRes,0,20*sizeof(char));
        getOnePoly(nums[i],len-i-1,curRes);
        strcat(res,curRes);
        //printf("cur = %s, res = %s\n",curRes,res);
    }

}
int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++){
        int coefficient[9];memset(coefficient,0,9*sizeof(int));
        for(int j = 0;j<9;j++){
            scanf("%d",&coefficient[j]);
        }
        char res[1000];memset(res,0,1000*sizeof(char));
        getPolynomial(coefficient, 9, res);
        printf("case #%d:\n",i);
        printf("%s\n",res);
    }
    return 0;
}
