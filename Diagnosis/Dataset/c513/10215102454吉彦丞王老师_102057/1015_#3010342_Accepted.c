#include<stdio.h>
#include<string.h>
int main(){
    int number;
    int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    scanf("%d",&number);
    for(int i=0;i<number;i++){
        char s1[100];
        scanf("%s",s1);
        int l1=strlen(s1);
        char s2[100];
        scanf("%s",s2);
        int l2=strlen(s2);
        int a[26];
        int b[26];
        for(int j=0;j<26;j++){
            a[j]=0;
            b[j]=0;
        }
        int t=25;
        for(int j=l1-1;j>=0;j--){
            if(s1[j]-'0'>=0&&s1[j]-'0'<='9'&&(s1[j+1]==','||j==l1-1)){
            	if(j>0){
   	            	if(s1[j-1]==',')
                	{
                		a[t]=s1[j]-'0';
                		t--;
					}
					else{
						a[t]=(s1[j-1]-'0')*10+(s1[j]-'0');
						t--;
					}
				}
				else{
					a[t]=s1[j]-'0';
					t--;
				}
            }
            else{
                continue;
            }
        }
        int k=25;
        for(int j=l2-1;j>=0;j--){
            if(s2[j]-'0'>=0&&s2[j]-'0'<=9&&(s2[j+1]==','||j==l2-1)){
            	if(j>0){
            		if(s2[j-1]==',')
            		{
                		b[k]=s2[j]-'0';
                		k--;
					}
					else{
						b[k]=(s2[j-1]-'0')*10+(s2[j]-'0');
						k--;
					}
				}
				else{
					b[k]=s2[j]-'0';
					k--;
				}
            }
            else{
                continue;
            }
        }
        int c[26];
        for(int j=0;j<26;j++){
            c[j]=a[j]+b[j];
        }
        for(int j=25;j>0;j--){
            c[j-1]=c[j-1]+c[j]/prime[j];
            c[j]=c[j]%prime[j];
        }
        c[0]=c[0]/prime[0];
        int num=0;
        for(int j=0;j<26;j++){
            if(c[j]==0){
                num++;
            }
            else{
                break;
            }
        }
        printf("case #%d:\n",i);
        for(int j=num;j<25;j++){
            printf("%d,",c[j]);
        }
        printf("%d\n",c[25]);
    }
    return 0;
}