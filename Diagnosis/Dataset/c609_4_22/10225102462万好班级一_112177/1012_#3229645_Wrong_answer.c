#include <stdio.h>


int main(){
    
   int loop;
   scanf("%d",&loop);

    for (int j = 0; j < loop; ++j) {
        char s[100];
        scanf("%s",s);

        int cnt = 0;
        for (;s[cnt]; ++cnt) {}

        double ans = 0;
        for (int i = cnt - 1;s[i] != '.'; --i) {
            double num;
            num = (double)(s[i] - '0');
            ans =ans *(0.125) + num;
        }
        printf("case #%d:\n%.1000g\n",j,ans*0.125);
    }

}
