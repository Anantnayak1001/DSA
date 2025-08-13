
#include<iostream>
using namespace std;


void Create(int* arr, int n) {
	for(int i=0; i<n; i++) {
		cout<<"Enter The ith element: ";
		cin>>arr[i];
	}

}

void Display(int* arr, int n) {
	for(int i=0; i<n; i++) {
		cout<<arr[i]<<"\t";
	}
}

int Insert(int* arr, int n, int pos, int addele) {
	if(pos > n+1) {
		cout<<"Can't insert element at required position."<<endl;
		return n;
	}
	else {
		int ind=pos-1;
		for(int i=n-1; i>=ind; i--) {
			arr[i+1]=arr[i];
		}
		arr[ind]= addele;
	}
	return n+1;
}

int Delete(int* arr, int n, int pos) {
	int ind=pos-1;
	for(int i=ind; i<n-1; i++) {
		arr[i]=arr[i+1];

	}

	return n-1;
}

int Linear_Search(int* arr, int n, int ele) {
	for(int i=0; i<n; i++) {
		if(arr[i]==ele) {
			return i;
		}
	}
	return -1;
}

int Insert_by_element(int* arr,int n, int ele) {
	for(int i=0; i<n; i++) {
		if(arr[0]>ele) {
			return Insert(arr, n, 1, ele);
		}

		else if(arr[n-1]<ele) {
			return	Insert(arr,n,n+1,ele);
		}

		if(arr[i]<=ele && arr[i+1]>ele) {
			return	Insert(arr,n,i+2,ele);
		}
	}

	return -1;
}

int main() {
	int arr[10];
	int Func;
	int size;
	cout<<"Enter The No. of Elements. ";
	cin>>size;
	Create(arr,size);
	cout<<"Press 1 to display Array"<<endl;
	cout<<"Press 2 to Insert an element Array"<<endl;
	cout<<"Press 3 to Delete an element Array"<<endl;
	cout<<"Press 4 to Linear Search Array"<<endl;
	cout<<"Press 5 to Insert By element Array"<<endl;
	cout<<"Press 6 to Exit Array"<<endl;
	cin>>Func;

	switch(Func) {

	case 1: {
		Display(arr,size);
		break;
	}

	case 2: {
		int pos;
		int addele;
		cout<<"Enter the position where the element is to be added: ";
		cin>>pos;

		cout<<"Enter the the element to be added: ";
		cin>>addele;
		size=Insert(arr, size, pos, addele);
		Display(arr,size);
		break;
	}

	case 3: {
		int pos;
		cout<<"Enter the Position of element to be deleted: ";
		cin>>pos;
		size=Delete(arr, size, pos);
		Display(arr,size);
		break;
	}

	case 4: {
		int ele;
		cout<<"Enter the element to be searched: ";
		cin>>ele;
		int index=Linear_Search(arr,size,ele);
		cout<<index;
		break;
	}

	case 5: {
		int ele;
		cout<<"Enter the element to be added: ";
		cin>>ele;
		size=Insert_by_element(arr,size,ele);
		Display(arr,size);
		break;
	}

	case 6: {
		break;
	}

	default: {
		cout<<"Invalid Arguement";
		break;
	}


	}

	return 0;
}
