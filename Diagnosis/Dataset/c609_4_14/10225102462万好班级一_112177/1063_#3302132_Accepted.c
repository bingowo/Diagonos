#include <stdio.h>

long long ans[51];

unsigned long long  method(int cnt) {
    if (cnt == 0)
        return 0;
    else if (cnt == 1)
        return 1;
    else if (cnt == 2)
        return 2;
    else if(cnt == 3)
        return 4;
    else if(cnt == 4)
        return 8;
    if(!ans[cnt]){
        ans[cnt] = method(cnt - 1) + method(cnt - 2) + method(cnt - 3) + method(cnt - 4);
    }
        return ans[cnt];
}

int main(){
    int loop;
    scanf("%d",&loop);
    for (int i = 0; i < loop; ++i) {
        int tmp;
        scanf("%d",&tmp);
        printf("case #%d:\n%llu\n",i,method(tmp));
    }
}