#include<iostream>
using namespace std;

void Display(int* arr, int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<"\t";
	}
}

int Delete(int* arr, int n, int pos){
	int ind=pos-1;
	for(int i=ind; i<n-1; i++){
		arr[i]=arr[i+1];
		
	}
	
	return n-1;
} 


int main(){
    int arr[5]={38,2,7,7,38};
    int size=5;
    
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i]==arr[j]){
                size=Delete(arr,size,j+1);
                
            }
        }
    }
    
    
    Display(arr,size);
    return 0;
}
