#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double boolen(void) {
    char s[11];
    scanf("%s",s);
    if((s[0]>='0' && s[0]<='9') || strlen(s)>1)
        return atof(s);
    else {
        double n1 = boolen();
        double n2 = boolen();
        switch(s[0]) {
            case '+': return n1 + n2;
            case '-': return n1 - n2;
            case '*': return n1 * n2;
            default:  return n1 / n2;
        }
    }
}


int main()
{
    int T;  scanf("%d",&T);
    for(int i=0; i<T; ++i)
        printf("case #%d:\n%f\n",i,boolen());
    return 0;
}
