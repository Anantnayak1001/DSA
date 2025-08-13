#include <iostream>
using namespace std;

void swapnum(int &a, int &b){
    int temp= a;
    a=b;
    b=temp;
}

void Display2D(int (&arr)[][3],int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void Transpose(int (&arr)[][3],int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<3; j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
}
int main()
{
   int arr1[3][3]={0};
    int arr2[3][3]={
        {10,20,30},{44,65,96},{27,18,1}
    };
   // MatrixMult(arr1,arr2,3);
    Transpose(arr2,3);
    Display2D(arr2,3);
   // Display2D(arr1,3);
    return 0;
}
