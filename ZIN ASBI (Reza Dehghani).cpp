#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
  int m=0,n=0,k=0,p=0,t=0,i=0,j=0,mix=0;
  int flag;
  int a[20][20];
  system("cls");
  cout << "Tedad Sotoonha ra vared konid:";
  cin  >> n;
  cout << "Tedad Satrha ra vared konid:";
  cin  >> m;
  cout <<endl;
  for( i=0; i<n; i++ )
    { cout << "Satr ra varesd konid"<<i<<" : ";
      for( j=0; j<m; j++ )
       cin >> a[i][j];
    }
  for ( k=0 ; k<n ; k++ )
   {
      mix=a[k][t];  flag=1;
      for( j=1; j<m; j++ )
        if((a[k][j]<mix) && (a[k][j]!=0))
          {
            mix=a[k][j];
            t=j;  p=k;
          }
      for( i=0; i<n; i++ )
        {
          if( i!=p )
            if( a[i][t]>mix )
              {
                flag=0; t=0; break;
                }
          if( i==n-1 && flag==1){
            cout << "Noghteh zin asbi=" << mix<<endl;
			cout<<"Mokhtasat=a["<<k<<"]["<<t<<"]"<<endl;
		  }
        }
    }
  if ( flag==0)
    cout << "Noghteh zin asbi vojood nadarad! :(";
    getch();
  }
