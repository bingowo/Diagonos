v#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[1000001];
    scanf("%s",s);
    int len=strlen(s);
    int begin=0,max=0,changdu=0,l=0,r=0;
    for(r=1;r<len;r++){
        for(int i=l;i<r;i++){
            if(s[i]==s[r]) {
                changdu=r-l;
                if(changdu>max){
                    max=changdu;
                    begin=l;
                }
                l=i+1;
            }
        }
    }
    if(max==0) printf("%s",s);
    for(int j=0;j<max;j++) printf("%c",s[begin+j]);
    return 0;
}
