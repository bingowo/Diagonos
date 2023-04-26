#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long int llu;

int main()
{
    char w[1001];scanf("%s",w);
    llu ans=1;
    for(int i=0;i<strlen(w);i++){
        if(strlen(w)==1) break;
        if(i==0){
            if(w[0]==w[1]) ans*=1;
            else ans*=2;
        }
        else if(i==strlen(w)-1){
            if(w[i]==w[i-1]) ans*=1;
            else ans*=2;
        }
        else{
            if(w[i]==w[i-1] && w[i]==w[i+1]) ans*=1;
            else if(w[i]==w[i-1] && w[i]!=w[i+1])
                ans*=2;
            else if(w[i]!=w[i-1] && w[i]==w[i+1])
                ans*=2;
            else if(w[i]!=w[i-1] && w[i]!=w[i+1] && w[i-1]==w[i+1])
                ans*=2;
            else if(w[i]!=w[i-1] && w[i]!=w[i+1] && w[i-1]!=w[i+1])
                ans*=3;
        }
    }
    printf("%llu",ans);

    return 0;

}



