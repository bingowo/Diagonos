    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>

    int main()
    {
        char A[200]={'\0'},B[200]={'\0'};
        scanf("%s %s",A,B);
        int flagA=1,flagB=1;
        if(A[0]=='-') {for(int i=0;i<strlen(A);i++) A[i]=A[i+1];flagA=-1;}//前移一位 由于最后是\0所以结束符号也前移了 不用但是影响string 
        if(B[0]=='-') {for(int i=0;i<strlen(B);i++) B[i]=B[i+1];flagB=-1;}
        if(strcmp(A,B)==-1 && flagA==1 && flagB==-1) printf("-");//绝对值a<b,b为负 则结果为负 
        if(strcmp(A,B)==1 && flagA==-1 && flagB==1) printf("-");//同上 
        if(flagA==-1 && flagB==-1) printf("-");//都为负 
        if(strcmp(A,B)==-1) {char tmp[200];strcpy(tmp,A);strcpy(A,B);strcpy(B,tmp);}
        char tmpA[200]={'\0'};strcpy(tmpA,A);for(int i=0;i<strlen(tmpA);i++) A[strlen(tmpA)-1-i]=tmpA[i];//字符串倒置 
        char tmpB[200]={'\0'};strcpy(tmpB,B);for(int i=0;i<strlen(tmpB);i++) B[strlen(tmpB)-1-i]=tmpB[i];
        if(strlen(A)>strlen(B))
			for(int i=strlen(B);i<strlen(A);i++) B[i]='0';
		if(strlen(A)<strlen(B))
			for(int i=strlen(A);i<strlen(B);i++) A[i]='0';	//数位对齐 
        char res[200]={'\0'};
        int c=0,i=0; 
        if(flagA*flagB>0)
            for(int i=0;i<strlen(A);i++)
            {
                res[i]=(A[i]-'0'+B[i]-'0'+c)%10+'0';
                c=(A[i]-'0'+B[i]-'0'+c)/10;
            }
        else
		{
            if(strcmp(tmpA,tmpB)==1) 
			for(int i=0;i<strlen(A);i++)
            {
                if(A[i]<B[i]) {res[i]=10+A[i]-'0'-(B[i]-'0')+'0';A[i+1]--;}
                else res[i]=A[i]-'0'-(B[i]-'0')+'0';//A-B,但也有可能是B-A 
            }
            else 
			for(int i=0;i<strlen(A);i++)
            {
                if(B[i]<A[i]) {res[i]=10+B[i]-'0'-(A[i]-'0')+'0';B[i+1]--;}
                else res[i]=B[i]-'0'-(A[i]-'0')+'0';//B-A 
            }
        }
        i=strlen(res)-1;
        for(;i>=0;i--) if(res[i]!='0') break;//从后往前输出，省略最前面的0 
        for(;i>=0;i--) printf("%c",res[i]);
        return 0;
    }