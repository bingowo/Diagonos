#include<stdio.h>
#include<string.h>

int main()
{
	//string f,m,c;
	char f[20],m[20],c[20];
	//cin>>f>>m>>c;
    scanf("%s %s %s",f,m,c);
	while(f=="?"||m=="?")
	{
		if(c=="A")
		{
			if(f=="?"&&(m=="A"||m=="AB"))	    //f="{A,AB,B,O}";
			    strcpy(f,"{A,AB,B,O}");
			else if(f=="?"&&(m=="B"||m=="O"))   //f="{A,AB}";
			    strcpy(f,"{A,AB}");
			else if(m=="?"&&(f=="A"||f=="AB"))	//m="{A,AB,B,O}";
			    strcpy(m,"{A,AB,B,O}");
			else if(m=="?"&&(f=="B"||f=="O"))   //m="{A,AB}";
			    strcpy(m,"{A,AB}");
		}
		else if(c=="B")
		{
			if(f=="?"&&(m=="B"||m=="AB"))	//f="{A,AB,B,O}";
			    strcpy(f,"{A,AB,B,O}");
			else if(f=="?"&&(m=="A"||m"{A,AB,B,O}"=="O")) //f="{AB,B}";
			    strcpy(f,"{AB,B}");
			else if(m=="?"&&(f=="B"||f=="AB"))	//m="{A,AB,B,O}";
			    strcpy(m,"{A,AB,B,O}");
			else if(m=="?"&&(f=="A"||f=="O"))  //m="{AB,B}";
			    strcpy(m,"{AB,B}");
		}
		else if(c=="AB")
		{
			if(f=="?"&&m=="A")	//f="{AB,B}";
			    strcpy(f,"{AB,B}");
			else if(f=="?"&&m=="B") //f="{A,AB}";
			    strcpy(f,"{A,AB}");
			else if(f=="?"&&m=="AB") //f="{A,AB,B}";
			    strcpy(f,"{A,AB,B}");
			else if(f=="?"&&m=="O") //f="impossible";
			    strcpy(f,"impossible");
			else if(m=="?"&&f=="A")	//m="{AB,B}";
			    strcpy(m,"{AB,B}");
			else if(m=="?"&&f=="B") //m="{A,AB}";
			    strcpy(m,"{A,AB}");
			else if(m=="?"&&f=="AB") //m="{A,AB,B}";
			    strcpy(m,"{A,AB,B}");
			else if(m=="?"&&f=="O") //m="impossible";
			    strcpy(m,"impossible");
		}
		else if(c=="O")
		{
			if(f=="?"&&m=="AB")	//f="impossible";
			    strcpy(f,"impossible");
			if(f=="?"&&(m=="A"||m=="B"||m=="O"))	//f="{A,B,O}";
			    strcpy(f,"{A,B,O}");
			if(m=="?"&&f=="AB")	//m="impossible";
			    strcpy(m,"impossible");
			if(m=="?"&&(f=="A"||f=="B"||f=="O"))	//m="{A,B,O}";
			    strcpy(m,"{A,B,O}");
		}
	}
	while(c=="?")
	{
		if(f=="A"&&m=="A") //c="{A,O}";
		    strcpy(c,"{A,O}");
		else if(f=="A"&&m=="B") //c="{A,AB,B,O}";
		    strcpy(c,"{A,AB,B,O}");
		else if(f=="A"&&m=="AB") //c="{A,AB,B}";
		    strcpy(c,"{A,AB,B}");
		else if(f=="A"&&m=="O") //c="{A,O}";
		    strcpy(c,"{A,O}");
		else if(f=="B"&&m=="B") //c="{B,O}";
	    	strcpy(c,"{B,O}");
		else if(f=="B"&&m=="AB") //c="{A,AB,B}";
		    strcpy(c,"{A,AB,B}");
		else if(f=="B"&&m=="O") //c="{B,O}";
		    strcpy(c,"{B,O}");
		else if(f=="AB"&&m=="AB") //c="{A,AB,B}";
		    strcpy(c,"{A,AB,B}");
		else if(f=="AB"&&m=="O") //c="{A,B}";
		    strcpy(c,"{A,B}");
		else if(f=="O"&&m=="O") //c="{O}";
		    strcpy(c,"{O}");
		
		else if(m=="A"&&f=="B") //c="{A,AB,B,O}";
		    strcpy(c,"{A,AB,B,O}");
		else if(m=="A"&&f=="AB") //c="{A,AB,B}";
		    strcpy(c,"{A,AB,B}");
		else if(m=="A"&&f=="O") //c="{A,O}";
		    strcpy(c,"{A,O}");
		else if(m=="B"&&f=="AB") //c="{A,AB,B}";
		    strcpy(c,"{A,AB,B}");
		else if(m=="B"&&f=="O") //c="{B,O}";
		    strcpy(c,"{B,O}");
		else if(m=="AB"&&f=="O") //c="{A,B}";
		    strcpy(c,"{A,B}");
	}	
	//cout<<f<<" "<<m<<" "<<c<<endl;
	printf("%s %s %s\n",f,m,c);
}