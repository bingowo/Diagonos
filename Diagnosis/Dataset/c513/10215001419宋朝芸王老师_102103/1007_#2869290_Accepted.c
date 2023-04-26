#include <stdio.h>
#include <stdlib.h>

int countNonRep(int val){
    int ans = 1, tempAns = 1;

    while(val > 0){
        int temp1, temp2, tempVal;
        tempVal = val;
        for( ;tempVal > 1;tempVal >>= 1){
            temp1 = tempVal % 2;
            temp2 = (tempVal>>1) % 2;
            if(temp1 != temp2) {
                    tempAns++;
            }
            else break;
        }

        if(tempAns > ans)
            ans = tempAns;

        tempAns = 1;
        val >>= 1;
    }

    return ans;
}

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        int val;
        scanf("%d",&val);
        printf("case #%d:\n%d\n",R,countNonRep(val));
    }
    return 0;
}
