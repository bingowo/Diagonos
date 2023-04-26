#include<stdio.h>
#include<string.h>
void reverse_string(char* str)
{  
   int left = 0; 
   int right =strlen(str) - 1; 
   while (left < right)  
     {   
        char temp = str[left]; 
        str[left] = str[right];   
        str[right] = temp;   
        left++;   
        right--;  
     } 
} 



int main()
{
    int x;
    scanf("%d",&x);
    for(int i=0;i<x;i++)
    {
        int a2,b2;
        char res[1500]="1";
        scanf("%d%d",&a2,&b2);
        int f=0;
        for(int i2=0;i2<b2;i2++)
        {
            
            int lengh=strlen(res);
            int math[lengh+1];
            math[lengh]=0;
            for(int j=0;j<lengh;j++)
            {
                math[j]=res[j]-'0';
                math[j]=math[j]*a2;
            }
            for(int j=0;j<lengh;j++)
            {
                if(math[j]>9)
                {
                    math[j+1]=math[j+1]+math[j]/10;
                    math[j]=math[j]%10;
                }
                res[j]=math[j]+'0';
            }
            if(math[lengh]!=0)
            {
                res[lengh]=math[lengh]+'0';
            }
        }


        printf("case #%d\n",i);
        reverse_string(res);
        printf("%s",res);
        
        printf("\n");
    }
}