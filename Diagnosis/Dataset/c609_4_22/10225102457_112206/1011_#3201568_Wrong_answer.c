#include<stdio.h>
#include<string.h>
//A trans tri;
//B,C to 1/3;
int main(void)
{
    char input[31];
    long long int A,B,C;
    long long int three = 1;
    scanf("%s",input);
    char *find = input;
    while(*find != '.' && *find != '\0'){
    	find++;
	}
	char *trans = find;
	
	if(*find == '\0'){//int
	    for(A = 0; trans >= input; trans--){
	    	switch(*trans){
	    		case '0':three *= 3;break;
	    		case '1':A += three; three *= 3; break;
	    		case '2':A -= three; three *= 3; break;
			}
		}
		printf("%lld",A);
    }
    
	else if(*(find-1) == '0' && find-1 == input){//fl
		for(B = 0,C = 1; *trans != '\0'; trans++){
			switch(*trans){
	    		case '0': C *= 3; break;
	    		case '1':B = B*3+1; C *= 3; break;
	    		case '2':B = B*3-1; C *= 3; break;
			}
		}
		printf("%lld %lld",B,C);
	}
	
	else{
	    for(A = 0; trans >= input; trans--){
	    	switch(*trans){
	    		case '0':three *= 3;break;
	    		case '1':A += three; three *= 3; break;
	    		case '2':A -= three; three *= 3; break;
			}
		}
		
		trans = find;
		for(B = 0,C = 1; *trans != '\0'; trans++){
			switch(*trans){
	    		case '0': C *= 3; break;
	    		case '1':B = B*3+1; C *= 3; break;
	    		case '2':B = B*3-1; C *= 3; break;
			}
		}
		if(A > 0 && B < 0){
			A--;
			B += C;
		}
		else if(A < 0 && B < 0) B += C;
		else if(A < 0 && B > 0){
			A++;
			B = C - B;
		}
		
		printf("%lld %lld %lld",A,B,C);
	}

    return 0;
}