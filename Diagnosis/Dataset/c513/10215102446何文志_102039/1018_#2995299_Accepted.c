#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct BigNum{
    int n[100];
    int digit;
}bigNum;

//int prime[30] = {2,3,5,7,11
//                ,13,17,19,23,29
//                ,31,37,41,43,47
//                ,53,59,61,67,71
//                ,73,79,83,89,97
//                ,101,103};
char prime[30][10] = {"1","2","3","5","7","11"
                ,"13","17","19","23","29"
                ,"31","37","41","43","47"
                ,"53","59","61","67","71"
                ,"73","79","83","89","97"
                ,"101","103"};
bigNum readBigNum(bigNum num,char s[]){
    int len = strlen(s), cnt = 0;
    while(cnt<len){
        char curNum[11];memset(curNum,0,11*sizeof(char));
        int tmpCnt = 0;
        while(isdigit(s[cnt])){
            curNum[tmpCnt] = s[cnt];
            tmpCnt++;cnt++;
        }
        //printf("curNum = %s\n",curNum);
        sscanf(curNum,"%d",&num.n[num.digit++]);
        cnt++;
    }
    return num;
}

int myMax(int a, int b){
    return a>b? a:b;
}

int BigNumCmp(char* num1, char* num2){//return Positive: num1>num2 Negative: num1<num2 Zero: num1=num2
    int len1 = strlen(num1), len2 = strlen(num2);
    if(len1!=len2){
        return len1-len2;
    }
    else{
        return strcmp(num1,num2);
    }
}

char* BigNumAdd(char* num1, char* num2){
    int i = strlen(num1)-1, j = strlen(num2)-1, up = 0;
    char* ans = (char*)malloc( (myMax(i,j)+10)*sizeof(char) );
    memset(ans,0,(myMax(i,j)+10)*sizeof(char));
    int ansLen = 0;
    while(i>=0||j>=0||up!=0){
        int x = i>=0? num1[i]-'0':0;
        int y = j>=0? num2[j]-'0':0;
        int cur = x+y+up;
        ans[ansLen++] = cur%10 + '0';
        up = cur/10;
        i--;
        j--;
    }
    for(int i = 0,j = ansLen-1;i<j;i++,j--){
        char tmp = ans[i];
        ans[i] = ans[j];
        ans[j] = tmp;
    }
    ans[ansLen++] = 0;
    return ans;
}

char* BigNumMultiply(char* num1,char* num2){
    int n = strlen(num1), m = strlen(num2);

    if( num1[0]=='0'|| num2[0]=='0' ){//有一个为零
        char* res0 = (char*)malloc(2*sizeof(char)); res0[0] = '0'; res0[1] = 0;
        return res0;//res0必须用malloc，否则无法返回
    }
    char* res = (char*)malloc((n+m+10)*sizeof(char));
    memset(res,0,(n+m+10)*sizeof(char));
    for(int i = m-1;i>=0;i--){//num1与num2从右向左逐位相乘,先遍历num2
        char* curRes = (char*)malloc((n+m+10)*sizeof(char));
        memset(curRes,0,(n+m+10)*sizeof(char));
        int curResLen = 0;
        for(int j = 0;j<m-i-1;j++){//num1与num2右边第i位相乘时要补上m-i-1个0
            curRes[curResLen++] = '0';
        }

        int curNum2 = num2[i] - '0';//此时num2上的值
        //printf("curNum2 = %d\n",curNum2);
        //printf("curNum2 = %d, curRes = %s\n",curNum2,curRes);
        int up = 0, index = n-1;//指向num1的一位
        while(index>=0||up!=0){//遍历num1
            int curNum1 = index>=0? num1[index]-'0':0;//此时num1上的值
            int curProduct = curNum1*curNum2 + up;//此时的乘积加上进位
            //printf("curNum1 = %d, up = %d, curProduct = %d ",curNum1,up,curProduct);
            curRes[curResLen++] = curProduct%10 + '0';
            //printf("curRes = %d\n",curRes[curResLen-1]);
            up = curProduct/10;
            index--;
        }

        for(int i1 = 0,j1 = curResLen-1;i1<j1;i1++,j1--){//reverse
            char tmp = curRes[i1];
            curRes[i1] = curRes[j1];
            curRes[j1] = tmp;
        }

        curRes[curResLen++] = 0;
        //printf("curNum2 = %d, curRes = %s\n",curNum2,curRes);
        res = BigNumAdd(res,curRes);//累加
        free(curRes);
    }
    return res;
}

int main()
{
    char s[500];memset(s,0,500*sizeof(char));
    scanf("%s",s);
    bigNum num; memset(num.n,0,100*sizeof(int)); num.digit = 0;
    num = readBigNum(num,s);

//    int i1 = num.digit-1;
//    while(num.n[i1]==0){
//        num.digit--;
//        i1--;
//    }
//    printf("digit = %d\n",num.digit);
//    for(int i = 0;i<num.digit;i++){
//        printf("%d,",num.n[i]);
//    }


    for(int i = 0,j = num.digit-1;i<j;i++,j--){
        int tmp = num.n[i];
        num.n[i] = num.n[j];
        num.n[j] = tmp;
    }
//    for(int i = 0;i<num.digit;i++){
//        printf("%d,",num.n[i]);
//    }
    char* res = (char*)malloc(500*sizeof(char));
    memset(res,0,500*sizeof(char));
    res[0] = '0';
    char* product = (char*)malloc(100*sizeof(char));
    memset(product,0,100*sizeof(char));
    product[0] = '1';
    for(int i = 0;i<num.digit;i++){
        char* tmpPro = BigNumMultiply(product,prime[i]);
        //free(product);
        product = tmpPro;
        //printf("product = %s\n",product);

        char curNum[10];memset(curNum,0,10*sizeof(char));
        sprintf(curNum,"%d",num.n[i]);
        //printf("curNum = %s\n",curNum);
        //printf("product = %s\n",product);
        char* sum = BigNumMultiply(product,curNum);
        //printf("sum = %s\n",sum);
        char* res1 = BigNumAdd(sum,res);
        //free(res);
        res = res1;
        //free(product);
        //free(sum);
        //printf("res = %s\n",res);
    }
    printf("%s\n",res);
    return 0;
}
