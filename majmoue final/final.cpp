#include <iostream>
#include <conio.h>
#include<time.h>
#include<string.h>
using namespace std;
//--------------------------------------FUNCTIONS-------------------------------
int power(int a,int o)
{
int k=1;
for(int i=0;i<o;i++)
k=a*k;

return k;
}
void print(char aray[][10],int s1,int ar[],int s2)
{
int h=1;
for(int i=0;i<s1;i++)
{
cout<<h<<".{";
for(int j=0;j<s2;j++)
{
if(aray[i][j]=='1')
{
cout<<ar[j]<<",";
}
}
cout<<"}"<<endl;
h++;
}
}
//-------------------------------------------------------------------------------
int **m;
long q=0;
long num=0;
long number=0;
 
long fact( long n )
{
    return ( n > 0 ? n*fact(n-1) : 1 );
}
 
long C( long n , long r )
{
    return ( fact(n)/(fact(r)*fact(n-r)) );
}
 
bool isPrinted(int *a, long n)
{
     bool is=true;
     for(long i=0;i<num;i++)
     {
             is=true;
             for(long j=0;j<n;j++)
             {
                      if(a[j]!=m[i][j])
                      {
                                is=false;
                      }
             }
             if(is)return true;
     }
     return false;
}
 
void print(int *a,long n)
{
     int swap=0;
     for(long i=0;i<n;i++)
     {
             for(long j=i;j<n;j++)
             {
                     if(a[j]<a[i])
                     {
                                  swap=a[i];
                                  a[i]=a[j];
                                  a[j]=swap;           
                     }
             }
     }
     if(!isPrinted(a,n))
     {
     number++;
     cout<<number<<".{";
     for(long i=0;i<n;i++)
     {
             cout<<a[i];
             m[q][i]=a[i];
             if(i!=n-1)
             {
                       cout<<",";
             }
     }
     q++;
     cout<<"}"<<endl;
     }
}
 
void printAll(int *a,int *b,long n,long k)
{
     if(q<num)
     {
     if(k==1)
     {
             print(a,n);
     }
     if(k==0)
     {
             print(a,n);
     }
     else if(k>0)
     {
          int *c, *d;
          long p=0;
          for(long j=0;j<k;j++)
          {
                  p=0;
                  c=new int[k-1];
                  for(long t=0;t<k;t++)
                  {
                          if(t!=j)
                          {
                                  c[p]=b[t];
                                  p++;
                          }
                  }
                  d=new int[n];
                  for(long i=-1;i<n;i++)
                  {
                          for(long t=0;t<n;t++)
                          {
                                  d[t]=a[t];
                          }
                          if(i!=-1)
                          {
                                   d[i]=b[j];
                          }
                          printAll(d,c,n,k-1);
                  }
          }
          delete c , d;
     }
     }
}
 //---------------------------------- MAIN ----------------------------------------
int main()
{
		int u, v, x[50], y[50],z;
	cout<<"Tedad ozv haye Majmoue avval ra vared konid:";
	cin>>u;
	    cout<<"A'zaye Majmoue avval ra vared konid:"<<endl;
	for(int i=0;i<u;i++){
		cin>>x[i];
	}
	int temp;
	for(int i=0; i<u-1;i++){
		for(int j=i+1;j<u;j++){
			if(x[j]<x[i]){
				temp=x[j];
				x[j]=x[i];
				x[i]=temp;
			}
		}
	}
     cout<<"Tedad ozv haye Majmoue Dovvom ra vared konid:";
     cin>>v;
     cout<<"A'zaye Majmoue Dovvom ra vared konid:"<<endl;
     for(z=0;z<v;z++){
          cin>>y[z];
	 }
	for(int i=0; i<v-1;i++){
		for(int j=i+1;j<v;j++){
			if(y[j]<y[i]){
				temp=y[j];
				y[j]=y[i];
				y[i]=temp;
			}
		}
	}
     //------------------------------------------------------------
     cout<<"Ejtama: ";
     char ch;
     int i=0;
     for(i=0;i<u;i++)
          if(x[i]!=x[i-1])
                cout<<x[i]<<"\t";
     for(z=0;z<v;z++)
          if(y[z]!=y[z-1])
          {
                ch=0;
                for(i=0;i<u;i++)
                     if(y[z]==x[i])
                     {
                          ch=1;
                          break;
                     }
                if(ch!=1)
                     cout<<y[z]<<"\t"<<"\n";
          }
     cout<<endl;
     //------------------------------------------------------------
     cout<<"Eshterak: ";
     z=0;
     for(i=0;i<u;i++)
          if(x[i]!=x[i-1])
                for(;y[z]<=x[i]&&z<v;z++)
                     if(y[z]!=y[z-1]&&x[i]==y[z])
                     {
                          cout<<x[i]<<"\t";
                          break;
                     }
					 cout<<"\n"<<"----------------------------------------------"<<endl;

	//--------------------Mohasebeh Majmoue n ozvi-------------------

	cout<<"Mohasebeh Majmoue n ozvi"<<"\n";


    time_t start , end;
    long n = 0 , k = 0;
    n = u;
    cout<<"Tedade ozv haye zir majmue:";
    cin>>k;
    int *a=new int[n];
    for(long i=0;i<n;i++)
    {
            a[i]=x[i];
    }
    int *b=new int[k];
    int *c=new int[n-k];
    for(long i=0;i<n;i++)
    {
            if(i<k)
            {
                b[i]=a[i];
            }
            else
            {
                c[n-i-1]=a[i];
            }
    }
    system("cls");
    cout<<"S={";
    for( long i = 0 ; i < n ; i++ )
    {
         cout<<a[i];
         if( i != n-1 )
             cout<<",";
    }
    cout<<"}"<<endl;
    num=C(n,k);
    m=new int*[C(n,k)];
    for(long i=0;i<C(n,k);i++)
    {
            m[i]=new int[k];
    }
    printAll(b,c,k,n-k);
    delete a , b , c;
	cout<<"\n"<<"================================================";
	//---------------------------------------Zirmajmoue-----------------------------------
	cout<<"Zirmajmoueha"<<"\n";

int size;
cout<<"Tedad Majmoue ra entekhab konid (Max=5)";
cin>>size;
int g=size;
int ar[10];
cout<<"Azayeh majmoue ra entekhab konid!"<<"\n";
for(int i=0;i<size;i++)
cin>>ar[i];

int s1;
s1=power(2,size);
char aray[50][10];
strcpy(aray[0],"0");
strcpy(aray[1],"1");
int o=0;
int j=0;
while(power(2,j+1)<s1)
{
o=0;
j++;
for(int i=0;i<power(2,j);i++)
{
for(int l=0;l<2;l++)
{
if(l==0)
{
strcpy(aray[o+power(2,j)],aray[o]);
strcat(aray[o+power(2,j)],"0");
}
else
strcat(aray[o],"1");


}
o++;
}

}
print(aray,s1,ar,size);
cout<<endl<<"Yek kelid ra brayeh khorouj bezanid!"<<endl;
getch();


}