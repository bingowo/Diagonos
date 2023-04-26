#include <stdio.h>
#include <stdlib.h>
#include <string,h>
typedef struct{
    int day;
    int year;
}date;

int main()
{
    int T1;
    scanf("%d",&T1);
    char table[19][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for(int i=0;i<T1;i++){
        int T2;
        scanf("%d",&T2);
        printf("case #%d",i);
        char c;
        int a;
        int b;
        int d;
        char s[20];
        for(int j=0;j<T2;j++){
            c=getchar();
            a=c-'0';
            c=getchar();
            scanf("%s",s);
            for(int k=0;k<19;k++){
                d=strcmp(table[k],s);
                if(d==0){
                    b=k+1;
                    break;
                }
                
            }
            
            
            
        } 
    }
    return 0;
}
