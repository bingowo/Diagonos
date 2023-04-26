#include <stdio.h>
#include<string.h>
int s[127];
char sample[65];
int flag[127];
int main(){
    int set = 0;
    scanf("%d",&set);
    for(int mo= 0; mo < set;mo++){

        for(int k = 0;k<127;k++ ){
            s[k] = 0;
            flag[k] = 0;
        }
        //different sets
        scanf("%s",&sample);
        int length = strlen(sample);
        //count how many times each word appear
        for(int j = 0; j < length;j++){
            s[sample[j]] = -1;
        }

        int ttletter = 0;
        //count how many different words
        for(int k = '0';k<='9';k++){
            if(s[k]!= 0){
                ttletter++;
            }
        }

        for(int k = 'A';k<='Z';k++){
            if(s[k]!= 0){
                ttletter++;
            }
        }

        for(int k = 'a';k<='z';k++){
            if(s[k]!= 0){
                ttletter++;
            }
        }

        //s[127]used as graph//remember initialiing
        int l = length;
        int indx = 0;
        int sameini = 0;
        int rps = 2;
        int zero = 0;
        while(l>0){
            if(s[sample[indx]]==-1&&indx == 0 && flag[sample[indx]] != 1){
                s[sample[indx]] = 1;
                flag[sample[indx]] = 1;
                sameini = 1;
                l--;
                indx++;
            }else if(flag[sample[indx]] == 1 && sameini == 1 &&zero == 0){
                indx++;
                l--;
            }else if(s[sample[indx] ]== -1 && zero == 0  && flag[sample[indx]] != 1){
                s[sample[indx]] = 0;
                flag[sample[indx]] = 1;
                zero =1; l--;
                indx++;
            }else if(s[sample[indx] ]== -1 && flag[sample[indx]] != 1 &&zero ==1){
                s[sample[indx]] = rps;
                flag[sample[indx]] = 1;
                rps++;
                indx++;
                l--;
            }else if(flag[sample[indx]] == 1  &&zero ==1){
                indx++;
                l--;
            }
        }

        //calculate
        int sum = 0;
        for(int i = 0; i <length;i++){
            sum = s[sample[i]]+ttletter*sum;
        }
        printf("case #%d:\n",mo);
        printf("%d",sum);
        printf("\n");




    }

}