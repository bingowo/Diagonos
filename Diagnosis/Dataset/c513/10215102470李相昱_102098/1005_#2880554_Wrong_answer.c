#include <stdio.h>
void output(int num,double x,int bit){
    printf("case #%d:\n",num);
    printf("0.");
    int sign = 0;
    for(int i = 0;i<3 *bit;i++){
        int n;
        n = (int)(x*10);
        x = x*10-n;
        if(n!=0||i<=sign){
            printf("%d",n);
        }
        else {
            int rmd = i;
            double y = x;
            for (; rmd < 3 * bit; rmd++) {
                int exm = (int) (y * 10);
                y = y * 10 - exm;
                if (exm) {
                    sign = rmd;
                    printf("%d",n);
                    break;
                }
            }
        }
    }
    printf("\n");
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0;i<t;i++){
        double ret=0;
        char s[60];
        double r = 1.0/8;
        scanf("%s",s);
        int j = 2;
        for(;s[j];j++){
            ret = ret + (s[j]-'0')*r;
            r = r/8;
        }
        output(i,ret,j-2);
    }

    return 0;
}