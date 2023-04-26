#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char Mapping[] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E','F','G','H',
        'I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','-'
};

string converse(int digital, int weight) {
    int flag = 0;
    if (digital < 0) {
        flag = 1;
        digital = -digital;
    }
    string str = "";
    int divisible;
    int remaining;
    while (digital != 0) {
        divisible = digital / weight;
        remaining = digital - divisible * weight;
        digital = divisible;
        str = Mapping[remaining] + str;
    }
    if (flag) {
        str = Mapping[36] + str;
    }
    return str;
}


int main() {
    int t,n,r;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%d",&r);
        if(r==10){
            printf("%d",n);
        }
        else
            printf("%s",converse(n,r));
    }
    return 0;

}