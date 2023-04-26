#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int putinto(char *ori, int *co){
    char *p = ori;
    int dim = 0;
    int flag = 1;
    int temp = 0;

    while(*p){
        if(*p == '-'){
            flag = -1;
            p++;
        }
        else if(*p == '+') p++;
        while(isdigit(*p)){
            temp = temp * 10 + *p - '0';
            p++;
        }
        if(*p == 'x'){
            p++;
            if(temp == 0) temp = 1;

            if(*p == '^'){
                p++;
                int tempDim = 0;
                while(isdigit(*p)){
                    tempDim = tempDim * 10 + *p - '0';
                    p++;
                }
                co[tempDim] = temp * flag;
                dim = dim > tempDim ? dim : tempDim;
                temp = 0;
                flag = 1;
            }
            else{
                int tempDim = 1;
                co[tempDim] = temp * flag;
                dim = dim > tempDim ? dim : tempDim;
                temp = 0;
                flag = 1;
            }
        }
    }
    co[0] = temp * flag;
    return dim;
}

int main()
{
    char one[101] = {'\0'}, two[101] = {'\0'};
    while(scanf("%s%s",one,two) == 2){
        int coa[51] = {0}, cob[51] = {0};
        int dima, dimb;
        int success = 0;

        dima = putinto(one,coa);
        dimb = putinto(two,cob);

        int max = dima + dimb;
        while(max > 0){
            int temp = 0;
            for(int i = dima; i >= 0; i--){
                if(max - i >= 0) temp += coa[i] * cob[max-i];
            }
            if(temp != 0) {
                success++;
                if(success == 1) printf("%d",temp);
                else printf(" %d",temp);
            }
            max--;
        }
        if(coa[0]*cob[0] != 0) printf(" %d",coa[0]*cob[0]);
        printf("\n");
    }

    return 0;
}
