#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int myMax(int a, int b){
    return a>b? a:b;
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

int BigNumCmp(char* num1, char* num2){//return Positive: num1>num2 Negative: num1<num2 Zero: num1=num2
    int len1 = strlen(num1), len2 = strlen(num2);
    if(len1!=len2){
        return len1-len2;
    }
    else{
        return strcmp(num1,num2);
    }
}

char* BigNumSub(char* num1,char* num2){
    if(BigNumCmp(num1,num2)<0){//num1<num2
        char* ans = BigNumSub(num2,num1);
        char tmp[strlen(ans) + 10];memset(tmp,0,(strlen(ans)+10)*sizeof(char));
        tmp[0] = '-';
        strcat(tmp,ans);
        strcpy(ans,tmp);
        return ans;
    }

    int i = strlen(num1)-1, j = strlen(num2)-1,up = 0;
    char* ans = (char*)malloc( (myMax(i,j)+10)*sizeof(char) );
    memset(ans,0,(myMax(i,j)+10)*sizeof(char));
    int ansLen = 0;
    while(i>=0||j>=0||up!=0){
        int x = i>=0? num1[i]-'0':0;
        int y = j>=0? num2[j]-'0':0;
        int cur = x-y+up;
        if(cur<0){
            ans[ansLen++] = cur + 10 + '0';
            up = -1;
        }
        else{
            ans[ansLen++] = cur + '0';
            up = 0;
        }
        i--;
        j--;
    }
    for(int i = ansLen-1;i>0;i--){//remove prefix0
        if(ans[i]=='0'){
            ans[i] = 0;
        }
        else{
            break;
        }
    }
    ansLen = strlen(ans);
    for(int i = 0,j = ansLen-1;i<j;i++,j--){//reverse
        char tmp = ans[i];
        ans[i] = ans[j];
        ans[j] = tmp;
    }
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

char* BigNumDivide(char* num1, char* num2){
    if(BigNumCmp(num1,num2)<0){
        char* res0 = (char*)malloc(2*sizeof(char));
        res0[0] = '0';res0[1] = 0;
        return res0;
    }
    else if(BigNumCmp(num1,num2)==0){
        char* res1 = (char*)malloc(2*sizeof(char));
        res1[0] = '1';res1[1] = 0;
        return res1;
    }
    if(BigNumCmp(num2, "0")==0){
        printf("error\n");
        return 0;
    }
    char* n1 = (char*)malloc((strlen(num1)+10)*sizeof(char));
    memset(n1,0,(strlen(num1)+10)*sizeof(char));
    strcpy(n1,num1);
    char* n2 = (char*)malloc((strlen(num2)+10)*sizeof(char));
    memset(n2,0,(strlen(num2)+10)*sizeof(char));
    strcpy(n2,num2);

    while(strlen(n1)>strlen(n2)){
        char* tmp = BigNumMultiply(n2,"10");//补0
        free(n2);
        n2 = tmp;
    }
    if(BigNumCmp(n1,n2)<0){
        n2[strlen(n2)-1] = 0;
    }
    //printf("n1 = %s,n2 = %s\n",n1,n2);

    char* res = (char*)malloc((strlen(n1)+10)*sizeof(char));
    memset(res,0,(strlen(n1)+10)*sizeof(char));
    int resCnt = 0;
    while(strlen(n2)>=strlen(num2)){//n2逐次除以10
        char curRes = '0';
        while(BigNumCmp(n1,n2)>=0){
            char* tmp = BigNumSub(n1,n2);
            free(n1);
            n1 = tmp;
            curRes++;
        }
        n2[strlen(n2)-1] = 0;//n2 /= 10
        res[resCnt++] = curRes;
        //printf("n1 = %s, n2 = %s, res = %s\n",n1,n2,res);
    }
    return res;
}

char* BigNumMod(char* num1, char* num2){
    if(BigNumCmp(num1,num2)==0){
        char* res1 = (char*)malloc(2*sizeof(char));
        res1[0] = '0';res1[1] = 0;
        return res1;
    }
    else if(BigNumCmp(num1,num2)<0){
        char* res = (char*)malloc((strlen(num1)+10)*sizeof(char));
        //注意不能直接返回num1，需要重新复制一份，防止影响num1本身
        memset(res,0,(strlen(num1)+10)*sizeof(char));
        strcpy(res,num1);
        return res;
    }

    char* n1 = (char*)malloc((strlen(num1)+10)*sizeof(char));
    memset(n1,0,(strlen(num1)+10)*sizeof(char));
    strcpy(n1,num1);
    char* n2 = (char*)malloc((strlen(num2)+10)*sizeof(char));
    memset(n2,0,(strlen(num2)+10)*sizeof(char));
    strcpy(n2,num2);

    while(strlen(n1)>strlen(n2)){
        char* tmp = BigNumMultiply(n2,"10");//补0
        free(n2);
        n2 = tmp;
    }
    if(BigNumCmp(n1,n2)<0){
        n2[strlen(n2)-1] = 0;
    }

    while(BigNumCmp(n1,num2)>=0){//注意不是比较n1和n2，而是n1和num2，因为n2已经加上了后缀0
        while(BigNumCmp(n1,n2)>=0){
            char* tmp = BigNumSub(n1,n2);
            free(n1);
            n1 = tmp;
        }
        n2[strlen(n2)-1] = 0;//n2 /= 10
        //printf("n1 = %s, n2 = %s\n",n1,n2);
    }
    return n1;
}

int isGoodNum(char* n){
    if(strchr(n,'9')!=NULL){
        return 0;
    }
    char* tmp = BigNumMod(n,"9");
    if(BigNumCmp(tmp,"0")==0){
        free(tmp);
        return 0;
    }
    return 1;
}

int main()
{
    char* n = (char*)malloc(110*sizeof(char));
    scanf("%s",n);
    char* tmp = BigNumAdd(n,"1");
    free(n);
    n = tmp;
    while(!isGoodNum(n)){
        char* tmp = BigNumAdd(n,"1");
        free(n);
        n = tmp;
    }
    printf("%s\n",n);
    return 0;
}
