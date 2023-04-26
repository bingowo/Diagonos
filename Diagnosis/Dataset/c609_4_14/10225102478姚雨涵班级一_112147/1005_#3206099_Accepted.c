#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int t,i=0;
    scanf("%d",&t);
    while(i<t){
    printf("case #%d",i);
    printf(":\n");
    i++;
    char a[10000];
    scanf("%s",a);
    int answer,temp;
    answer = temp = 0;
    for(int k = 0;k<strlen(a);k++){
        if(a[k] == '-')
            temp = -1;
        if(a[k] == '0')
            temp = 0;
        if(a[k] == '1')
            temp = 1;
        answer = answer*3 + temp;
    }
    printf("%d\n",answer);
        }
return 0;
}
