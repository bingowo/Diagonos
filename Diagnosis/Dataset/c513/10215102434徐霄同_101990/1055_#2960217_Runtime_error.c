#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000001];
    int zm[127];
    int i,j,i0,j0,l,lm;
    scanf("%s",s);
    l=strlen(s);
    memset(zm,0,sizeof(zm));
    i=0;
    i0=0;
    j=0;
    zm[s[0]]=1;
    while(j<l-1&&zm[s[j+1]]==0){
        j++;
        zm[s[j]]++;
    }
    j0=j;
    while(j<l){
        zm[s[i]]--;
        i++;
        while(j<l-1&&zm[s[j+1]]==0){
            j++;
            zm[s[j]]++;
        }
        if(j-i>j0-i0){
            i0=i;
            j0=j;
        }
    }
    for(i=i0;i<=j0;i++)
        printf("%c",s[i]);
    printf("\n");
    return 0;
}
