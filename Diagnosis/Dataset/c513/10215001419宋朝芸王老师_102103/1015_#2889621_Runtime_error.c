#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(int * a, int len){
    int *pa = a;
    int tempReverse;
    for(int l = 0; l < len/2 ; l++){
        tempReverse = *(pa + l);
        *(pa + l) = *(pa + len - l - 1);
        *(pa + len - l -1) = tempReverse;
    }
}


void readnum(char *tempC, int *a, int* numOfA){
    char *pc = tempC;
    int num = 0, j = 0; //a has lenA elements, a[n] = num;

    while(*pc) {
        if(*pc == ','){
            a[j++] = num;
            num = 0;
        }
        else {num = num * 10 + *pc - '0';}
        *pc = '\0';
        pc++;
    }

    a[j++] = num;
    *numOfA = j;

}

int main()
{
    int prime[26]={2,3,5,7,11,
        13,17,19,23,29,31,37,41,43,47,
        53,59,61,67,71,73,79,83,89,97,101};

    int T,R;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        printf("case #%d:\n",R);


        /***input***/
        char tempC[26] = {'\0'};
        int a[26] = {'0'}, b[26] = {'0'}, ans[36] = {'0'};
        int numOfA[1],numOfB[1];
        int lenMax;

        scanf("%s",tempC);
        readnum(tempC,a,numOfA);
        reverse(a,numOfA[0]);

        scanf("%s",tempC);
        readnum(tempC,b,numOfB);
        reverse(b,numOfB[0]);

        lenMax = numOfA[0] > numOfB[0] ? numOfA[0] :numOfB[0];


        /***operate***/
        int add = 0;
        int i = 0;
        while(i < lenMax){

            int temp = a[i] + b[i];

            if(add != 0) {
                temp = temp + add;
                add = 0;
            }

            if(temp < prime[i]) ans[i] = temp;
            else{
                ans[i] = temp % prime[i];
                add = add + temp / prime[i];
            }

            i++;
        }

        if(add != 0 ) {
            ans[i] = add % prime[i];
            lenMax++;
        }

        while(ans[lenMax-1]==0) lenMax--;


        /***output***/
        printf("%d",ans[lenMax-1]);

        if(lenMax == 1) return 0;

        for(int k = lenMax-2; k >= 0; k--){
            printf(",%d",ans[k]);
        }
        printf("\n");

    }

    return 0;
}
