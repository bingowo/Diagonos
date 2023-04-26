#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct BigNum{
    int n[100];
    int digit;
}bigNum;

int prime[30] = {2,3,5,7,11
                ,13,17,19,23,29
                ,33,37,41,43,47
                ,53,59,61,67,71
                ,73,79,83,89,97
                ,101,103};

int main()
{
    int T = 0;
    scanf("%d",&T);

    for(int i = 0;i<T;i++){
        char s1[500];memset(s1,0,500*sizeof(char));
        char s2[500];memset(s2,0,500*sizeof(char));
        scanf("%s%s",s1,s2);
        bigNum num1; memset(num1.n,0,100*sizeof(int));num1.digit = 0;
        bigNum num2; memset(num2.n,0,100*sizeof(int));num2.digit = 0;
        int len1 = strlen(s1), len2 = strlen(s2);
        int cnt1 = 0, cnt2 = 0;

        ///获取数字
        while(cnt1<len1){
            char curNum[11];memset(curNum,0,11*sizeof(char));
            int tmpCnt = 0;
            while(isdigit(s1[cnt1])){
                curNum[tmpCnt] = s1[cnt1];
                tmpCnt++;cnt1++;
            }
            //printf("curNum = %s\n",curNum);
            sscanf(curNum,"%d",&num1.n[num1.digit++]);
            cnt1++;
        }
        while(cnt2<len2){
            char curNum[11];memset(curNum,0,11*sizeof(char));
            int tmpCnt = 0;
            while(isdigit(s2[cnt2])){
                curNum[tmpCnt] = s2[cnt2];
                tmpCnt++;cnt2++;
            }
            //printf("curNum = %s\n",curNum);
            sscanf(curNum,"%d",&num2.n[num2.digit++]);
            cnt2++;
        }
        ///


        for(int j1 = 0,j2 = num1.digit-1;j1<j2;j1++,j2--){
            int tmp = num1.n[j1];
            num1.n[j1] = num1.n[j2];
            num1.n[j2] = tmp;
        }
        for(int j1 = 0,j2 = num2.digit-1;j1<j2;j1++,j2--){
            int tmp = num2.n[j1];
            num2.n[j1] = num2.n[j2];
            num2.n[j2] = tmp;
        }

//        printf("digit1 = %d\n",num1.digit);
//        for(int j = 0;j<num1.digit;j++){
//            printf("%d: %d\n",j,num1.n[j]);
//        }
//        printf("digit2 = %d\n",num2.digit);
//        for(int j = 0;j<num2.digit;j++){
//            printf("%d: %d\n",j,num2.n[j]);
//        }

        ///进行运算
        bigNum res; memset(res.n,0,100*sizeof(int)); res.digit = 0;
        int up = 0;
        int i1 = 0, i2 = 0;

        while(i1<=num1.digit||i2<=num2.digit||up!=0){
            int curRes = num1.n[i1] + num2.n[i2] +up;
            res.n[res.digit] = curRes%prime[res.digit];

            up = curRes/prime[res.digit];
            //printf("curRes = %d, res.n = %d, up = %d\n",curRes,res.n[res.digit],up);
            res.digit++;
            i1++;i2++;
        }
        //printf("res: digit = %d\n",res.digit);


        for(int j1 = 0,j2 = res.digit-1;j1<j2;j1++,j2--){
            int tmp = res.n[j1];
            res.n[j1] = res.n[j2];
            res.n[j2] = tmp;
        }
        printf("case #%d:\n",i);
        for(int j = 0;j<res.digit;j++){
            if(j==res.digit-1){
                printf("%d",res.n[j]);
                break;
            }
            printf("%d,",res.n[j]);

        }
        printf("\n");
    }
    return 0;
}
