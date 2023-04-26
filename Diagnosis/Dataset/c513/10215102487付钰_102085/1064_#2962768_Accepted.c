#include <stdio.h>
#include <stdlib.h>
double caculate(){
    char num[11];
    scanf("%s",num);
    double ret;
    switch (num[0]) {
        case '+':
            ret  = caculate()+caculate();
            break;
        case '-':
            ret = caculate() - caculate();
            break;
        case '*':
            ret = caculate() * caculate();
            break;
        case'/':
            ret = caculate() / caculate();
            break;
        default:
            return atof(num);
    }
    return ret;

}
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        double ret=0;
        char c;
        do{
            ret =  caculate();
        }while ((c=getchar())&&(c!='\n'));
        printf("case #%d:\n%lf\n",i,ret);
    }
    return 0;
}
