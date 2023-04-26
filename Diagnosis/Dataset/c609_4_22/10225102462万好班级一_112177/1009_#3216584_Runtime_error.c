#include <stdio.h>

int main(){
    int loop;
    scanf("%d",&loop);getchar();
    for (int i = 0; i < loop; ++i) {

        char c;int numb = 0;int sum = 0;
        while((c = getchar()) != '\n' ){
            numb++;int count = 0;
            int num = (int)c;
            while(num){
                if(num %2 == 1)count ++;
                num/= 2;
            }sum = sum + count;
        }
        int a,b,q;
        b = sum;
        a = numb * 8;
        q = a % b;
        while (q != 0)
        {
            a = b;
            b = q;
            q = a % b;
        }printf("%d/%d\n",sum/b,(8*numb)/b);
    }

}