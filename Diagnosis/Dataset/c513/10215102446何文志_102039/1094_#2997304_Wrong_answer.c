#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct BigNum{
    char sign;
    char s[200];
    int len;
}bigNum;

bigNum init(bigNum num){
    num.sign = num.s[0]=='-' ? '-' : '+';
    for(int i = 0,j = strlen(num.s)-1;i<j;i++,j--){
        char tmp = num.s[i];
        num.s[i] = num.s[j];
        num.s[j] = tmp;
    }
    if(num.sign=='-'){
        num.s[strlen(num.s)-1] = 0;
    }
    num.len = strlen(num.s);
    return num;
}

bigNum setReverse(bigNum num){
    for(int i = 0,j = strlen(num.s)-1;i<j;i++,j--){
        char tmp = num.s[i];
        num.s[i] = num.s[j];
        num.s[j] = tmp;
    }
    return num;
}

void bigNumToString(bigNum num, char res[]){
    for(int i = 0,j = strlen(num.s)-1;i<j;i++,j--){
        char tmp = num.s[i];
        num.s[i] = num.s[j];
        num.s[j] = tmp;
    }
    if(num.sign=='-'){
        res[0] = '-';
    }
    strcat(res,num.s);
    return;
}

void bigNumPrint(bigNum num){
    char s[100];memset(s,0,100*sizeof(char));
    bigNumToString(num,s);
    printf("num.s = %s, len = %d, sign  = %c\n",s,num.len,num.sign);
}

int BigNumCmp(bigNum num1, bigNum num2){
    if(num1.sign=='-'&&num2.sign=='+'){
        return -1;
    }
    if(num1.sign=='+'&&num2.sign=='-'){
        return 1;
    }
    if(num1.sign=='+'&&num2.sign=='+'){
        if(num1.len!=num2.len){
            return num1.len>num2.len ? 1 : -1;
        }
        else{
            return strcmp(num1.s,num2.s);
        }
    }

    if(num1.sign=='-'&&num2.sign=='-'){
        if(num1.len!=num2.len){
            return num1.len>num2.len ? -1 : 1;
        }
        else{
            return -1*strcmp(num1.s,num2.s);
        }
    }
    return 0;
}

int max(int a, int b){
    return a>b ? a : b;
}

bigNum BigNumAdd(bigNum n1, bigNum n2);
bigNum BigNumSubtract(bigNum n1, bigNum n2);
bigNum BigNumMultiply(bigNum n1, bigNum n2);
bigNum BigNumDivide(bigNum n1, bigNum n2);
bigNum BigNumMod(bigNum n1, bigNum n2);


bigNum BigNumAdd(bigNum n1, bigNum n2){
    if(n1.sign=='+'&&n2.sign=='-'){
        bigNum res = BigNumSubtract(n1,n2);
        res.sign = strcmp(n1.s,n2.s)>=0 ? '+' : '-';
        return res;
    }
    else if(n1.sign=='-'&&n2.sign=='+'){
        bigNum res = BigNumSubtract(n1,n2);
        res.sign = strcmp(n1.s,n2.s)>=0 ? '-' : '+';
        return res;
    }
    else if(n1.sign=='-'&&n2.sign=='-'){
        bigNum res = BigNumAdd(n1,n2);
        res.sign = '-';
        return res;
    }
    else{//只处理正数相加的情况
        bigNum res; memset(&res,0,sizeof(bigNum));
        res.sign = '+';
        int i1 = 0, i2 = 0, up = 0;
        while(n1.s[i1]!=0||n2.s[i2]!=0||up!=0){
            int curN1 = n1.s[i1]==0 ? 0 : n1.s[i1]-'0';
            int curN2 = n2.s[i2]==0 ? 0 : n2.s[i2]-'0';
            int curSum = curN1+curN2+up;
            res.s[res.len] = curSum%10 + '0';
            up = curSum/10;
            res.len++;
            i1++;i2++;
        }

        //bigNumPrint(res);
        return res;
    }
}

bigNum BigNumSubtract(bigNum n1, bigNum n2){
    if(n1.sign=='+'&&n2.sign=='-'){
        n2.sign = '+';//结构体为值传递，不会改变原来的n2; 转化为正数相加
        bigNum res = BigNumAdd(n1,n2);
        res.sign = '+';
        return res;
    }

    else if(n1.sign=='-'&&n2.sign=='+'){
        n1.sign = '+';//结构体为值传递，不会改变原来的n1; 转化为正数相加
        bigNum res = BigNumAdd(n1,n2);
        res.sign = '-';
        return res;
    }

    else if(n1.sign=='-'&&n2.sign=='-'){
        n1.sign = '+'; n2.sign = '+';
        bigNum res = BigNumSubtract(n2,n1);
        res.sign = strcmp(n1.s,n2.s)>=0 ? '-' : '+';
        return res;
    }
    else{//只处理正数相减的情况
        bigNum res; memset(&res,0,sizeof(bigNum));
        if(strcmp(n1.s,n2.s)<0){
            res = BigNumSubtract(n2,n1);
            res.sign = '-';
            return res;
        }
        else{//只处理正数相减且结果为正的情况
            res.sign = '+';
            int i1 = 0, i2 = 0, up = 0;
            while(n1.s[i1]!=0||n2.s[i2]!=0||up!=0){
                int curN1 = n1.s[i1]==0 ? 0 : n1.s[i1]-'0';
                int curN2 = n2.s[i2]==0 ? 0 : n2.s[i2]-'0';
                int curSum = curN1-curN2+up;
                up = curSum/10;
                if(curSum<0){
                    curSum+=10;
                }
                res.s[res.len] = curSum%10 + '0';

                res.len++;
                i1++;i2++;
            }
            return res;
        }

    }
}

bigNum BigNumMultiply(bigNum n1, bigNum n2){

}

bigNum BigNumDivide(bigNum n1, bigNum n2){

}

bigNum BigNumMod(bigNum n1, bigNum n2){

}

int cmp(const void* a, const void* b){
    bigNum A = *(bigNum*)a, B = *(bigNum*)b;
    A = setReverse(A);
    B = setReverse(B);
//    bigNumPrint(A);
//    bigNumPrint(B);
    return BigNumCmp(A,B);
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    bigNum nums[n];memset(nums,0,n*sizeof(bigNum));
    for(int i = 0;i<n;i++){
        scanf("%s",nums[i].s);
        nums[i] = init(nums[i]);
    }
    qsort(nums,n,sizeof(nums[0]),cmp);

//    for(int i = 0;i<n;i++){
//        bigNumPrint(nums[i]);
//    }
    bigNum res = BigNumSubtract(nums[n-1],nums[0]);
    char resS[200];memset(resS,0,200*sizeof(char));
    bigNumToString(res,resS);
    printf("%s",resS);
    return 0;
}
