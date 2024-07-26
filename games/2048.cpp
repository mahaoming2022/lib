#include <bits/stdc++.h>//2048 DEV版 
using namespace std;
int a[10][10];
bool k1()
{
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			if(a[i][j]==0)
				return true;
		}
	}
	return false;
}
bool k2()
{
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=3;j++)
	    {
	    	if(a[i][j]==a[i][j+1])
	        {
	    	    return true;
	        }
	    }
	}
	return false;
}
bool k3()
{
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=4;j++)
	    {
	    	if(a[j][i]==a[j+1][i])
	    	{
	        	return true;
	        }
	    }
	}
	return false;
}
bool is()
{
	if(k1) return true;
	if(k2) return true;
	if(k3) return true;
	return false;

}
bool win()
{
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			if(a[i][j]==2024)
			{
				return true;
			}
		}
	}
	return false;
}
//--------------------------------------------------------
void fun1()
{
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			if(a[i][j]==0)
			{
				for(int w=j;w<=4;w++)
				{
					a[i][w]=a[i][w+1];
				}
			}
		}
	}
}
void fun2()
{
	for(int i=1;i<=4;i++)
	{
		for(int j=4;j>=1;j--)
		{
			if(a[i][j]==0)
			{
				for(int w=j;w>=1;w--)
				{
					a[i][w]=a[i][w-1];
				}
			}
		}
	}
}
void fun3()
{
	for(int i=1;i<=4;i++)
	{
		int ans=0;
		for(int j=1;j<=4;j++)
		{
			if(a[j][i]==0)
			{
				for(int w=j;w<=4;w++)
				{
					a[w][i]=a[w+1][i];
				}
			}
		}
	}
}
void fun4()
{
	for(int i=1;i<=4;i++)
	{
		int ans=0;
		for(int j=4;j>=1;j--)
		{
			if(a[j][i]==0)
			{
				for(int w=j;w>=1;w--)
				{
					a[w][i]=a[w-1][i];
				}
			}
		}
	}
}
void was(char c)
{
	if(c=='A')
	{
		fun1();
		for(int i=1;i<=4;i++)
			for(int j=1;j<=4;j++)
				if(a[i][j]==a[i][j+1])
					a[i][j]*=2,a[i][j+1]=0;
		fun1();
	}
	if(c=='D')
	{
		fun2();
		for(int i=1;i<=4;i++)
			for(int j=4;j>=1;j--)
				if(a[i][j]==a[i][j-1])
					a[i][j]*=2,a[i][j-1]=0;
		fun2();
	}
	if(c=='W')
	{
		fun3();
		for(int i=1;i<=4;i++)
			for(int j=1;j<=4;j++)
				if(a[j][i]==a[j+1][i])
					a[j][i]*=2,a[j+1][i]=0;
		fun3();
	}
	if(c=='S')
	{
		fun4();
		for(int i=1;i<=4;i++)
			for(int j=4;j>=1;j--)
				if(a[j][i]==a[j-1][i])
					a[j][i]*=2,a[j-1][i]=0;
		fun4();
	}
	
}
//---------------------------------------------------
void pf()
{
	
	for(int i=1;i<=4;i++)
	    {
	    	cout<<"+"<<"———"<<"+"<<"———"<<"+"<<"———"<<"+"<<"———"<<"+"<<endl;
	    	for(int j=1;j<=4;j++)
	    	{
	    		cout<<"|";
	    		if(a[i][j]!=0)//std::cout << RED << "1" << RESET << std::endl;//cout<<RED<<a[i][j]<<RESET<<"  ";
	    		{
	    		//	printf("\033[31m"); 
	    			printf("%-6d", a[i][j]);
    			//	printf("\033[0m");
	    		}
	    		else
	    		{
	    			printf("      ");
	    		}
	    	}
	    	cout<<"|"<<endl;
	    }
	    cout<<"+"<<"———"<<"+"<<"———"<<"+"<<"———"<<"+"<<"———"<<"+"<<endl;
}
void look()
{
	while(true)
	{
		int x1=rand()%4+1,x2=rand()%4+1;
		int d=rand()%4+1;
		d*=2;
		if(d==6) d=2;
		if(a[x1][x2]==0)
		{
			a[x1][x2]=d;
			break;
		}
			
	}
}
int main()
{
    srand(time(0));
    cout<<"W向上，S乡下，A向左，D向右"<<endl;
    cout<<"请输入t键开始游戏"<<endl;
    string a;
    cin>>a;
    if(a!="t")
    {
    	return 0;
    }
    look();
    int ans=0;
    while(true)
    {
    	pf();
    	char l;
    	cin>>l;
    	was(l);
    	
    	look();
    	if(!is())
    	{
    		cout<<"Game Over!"<<endl;
    		cout<<"你一共走了 "<<ans<<" 步"<<endl;
    		return 0;
    	}
    	if(win())
    	{
    		cout<<"You Win!"<<endl;
    		cout<<"你一共走了 "<<ans<<" 步"<<endl;
    		return 0;
    	}
    	
    	
    	ans++;
    }
    return 0;
}