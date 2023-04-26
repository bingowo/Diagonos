#include <stdio.h>
#include <string.h>
int main(){
    int T;
    scanf("%d",&T);
        	char ch=getchar();
    for(int i = 0; i < T; i++){

    	int y=0;
        char s[61] = {'\0'};
        while((ch=getchar())!='\n'){
        	s[y]=ch;
        	y++;
		}
        int table[256];
        for(int j = 0; j < 256; j++) table[j] = -1;
        table[s[0]] = 1;
        int flag = 1;
        int R = 1;
        int length = strlen(s);
        for(int j = 1; j < length; j++){
            if(table[s[j]] == -1){
                if(flag) {table[s[j]] = 0; flag = 0; R++;}
                else table[s[j]] = R++;
            }
        }
        if(R == 1) R = 2;
        long long result = 1;
        for(int j = 1; j < length; j++){
            result = result*R + table[s[j]];
        }
        printf("case #%d:\n%lld\n",i,result);
        //cout<<"case #"<<i<<':'<<endl<<result<<endl;
    }
    return 0;
}