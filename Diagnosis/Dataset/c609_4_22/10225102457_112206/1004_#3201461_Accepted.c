#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(void)
{
    int in,n1,n2,m;
    const char *dic = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    char input[32];
    scanf("%d%s%d",&n1,input,&n2);
    char output[32] = {0};
    m = 1,in = 0;
    
    for(int v = strlen(input) - 1; v >= 0; v--){
    	if(islower(input[v])) input[v] = toupper(input[v]);
        char *temp = strchr(dic,input[v]);
        in += m*(temp-dic);
        m *= n1;
    }
    for(m = 0; in != 0; m++){
        output[m] = *(dic+in%n2);
        in /= n2;
    }
    if(m == 0){
        printf("0");
    }
    else{
        for(m--; m >= 0; m--) printf("%c",output[m]);
    }
    return 0;
}