#include<stdio.h>
int main()
{
    int A,B;
    char N[33];
    scanf("%d",&A);
    scanf("%s",&N);
    scanf("%d",&B);
    //if (N[0]=='0')  printf("0\n");

    else
    {
        int n[33];
        for(int i=0;i<33;i++)   n[i]=-1;
        int i=0;
        while(N[i]!='\000')
        {
            if(N[i]>='0' && N[i]<='9')  n[i]=N[i]-48;
            else if(N[i]>='A' && N[i]<='Z')  n[i]=N[i]-55;
            else if(N[i]>='a' && N[i]<='z')  n[i]=N[i]-87;
            i++;
        }
    
        i=1;
        int A_to_T=n[0];
        while(n[i]!=-1)
        {
            A_to_T=A_to_T*A+n[i];
            i++;
        }

        int T_to_B[33];
        i=0;
        while(A_to_T!=0)
        {
            T_to_B[i]=A_to_T%B;
            A_to_T=A_to_T/B;
            i++;
        }
        i--;

        char result[33];
        for(int j=0;j<=i;j++)
        {
            if(T_to_B[j]>=0 && T_to_B[j]<10)  result[j]=T_to_B[j]+48;
            else if(T_to_B[j]>=10)  result[j]=T_to_B[j]+55;
        }


        for(i;i>=0;i--) printf("%c",result[i]);


    }
    
    

    return 0;
}

