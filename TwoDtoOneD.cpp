#include<bits/stdc++.h>

using namespace std;

int main()
{
  int **a,**b,ar,ac,br,bc,k;
  cout<<"no. of rows for A:";
  cin>>ar;
  cout<<"no. of coloumns for A:";
  cin>>ac;
  //cout<<"size of array B:";
  //cin>>bn;
  a=new int*[ar];
  //b=new int*[];
  for(int i=0;i<ar;i++)
  a[i]=new int[ac];
  //for(int i=0;i<br;i++)
  //b[i]=new int[bc];
  std::cout << "Matrix A:" << std::endl;
  for(int i=0;i<ar;i++)
    for(int j=0;j<ac;j++)
      cin>>a[i][j];
  //cout<<"Matrix B:"<<endl;
  /*for(int i=0;i<ar;i++)
    for(int j=0;j<bc;j++)
      cin>>b[i][j];
  */
  int *matrixA=new int[ac*ar];
  //int *matrixB=new int[bc*br];
  k=0;
  for(int i=0;i<ar;i++)
    for(int j=i;j<ac;j++)
      {
        matrixA[k]=a[i][j];
        k++;
      }
  /*
  k=0;
  for(int i=0;i<br;i++)
    for(int j=i;j<bc;j++)
      {
        matrixB[k]=b[i][j];
        k++;
      }
  */
  cout<<endl;
  int i=1,j=1,indexA,sizeOfA,sizeOfB;
  while(i!=-1&&j!=-1)
  {
    cout<<"\ni,j:";
    cin>>i;cin>>j;
    if(i==j||i<j)
    {
      if(j<=ac-1)
      {

          indexA=(ac*(i+1))-(i*(i+1))/2-(ac-j);
          sizeOfA=((ac)*(ac+1))/2;
          if(indexA<sizeOfA)
            printf("\na[%d][%d]:%d",i,j,matrixA[indexA]);
          else
            cout<<"\nerror";
      }
      else
        cout<<"\ninvalid!";
    }
    else
      {
        if(j<=ac-1&&i>j)
          printf("\na[%d][%d]:0",i,j);
        else
          cout<<"\ninvalid!!"<<j<<i;
      }
  }

  return 0;
}
