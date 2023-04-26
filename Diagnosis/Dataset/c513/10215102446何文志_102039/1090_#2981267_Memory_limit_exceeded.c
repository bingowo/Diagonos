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

char* BigNumMultiply(char* num1,char* num2){
    int n = strlen(num1), m = strlen(num2);
    char* res0 = (char*)malloc(2*sizeof(char)); res0[0] = '0'; res0[1] = 0;
    if( num1[0]=='0'|| num2[0]=='0' ){//有一个为零
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
    int N = 0;
    while(1){
        scanf("%d",&N);
        if(N == 0){
            break;
        }
        int N1 = N;
        char* res = (char*)malloc(1000*sizeof(char));
        memset(res,0,1000*sizeof(char));
        res[0] = '1';
        char NString[10];memset(NString,0,10*sizeof(char));
        sprintf(NString,"%d",N);
        while(N1>0){
            res = BigNumMultiply(res,NString);
            N1--;
        }
        printf("%c\n",res[0]);
        free(res);
    }
    return 0;
}
