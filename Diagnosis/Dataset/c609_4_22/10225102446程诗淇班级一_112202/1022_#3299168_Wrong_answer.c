#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct{
    char a[1000000];
    int b[1000000];
}hhh;

int main()
{
    int T;
    scanf("%d",&T);
    hhh* xxx;
    xxx=(hhh*)malloc(T*sizeof(hhh));
    for(int i=0;i<T;i++){
        scanf("%s",xxx[i].a);
        int c;
        int k=0;
        c=strlen(xxx[i].a);
        for(int j=0;j<c;j++){
            if(xxx[i].a[j]=='@'){
                xxx[i].b[k]=xxx[i].a[j+1];
                
                
            }
            
        }
        
    }
    
    return 0;
}
