#include<iostream>

using namespace std;

int binary_search_recursion(int *a, int left, int right, int val){

	//always first check the base condition
	if(left>=right)
		return -1;

	//base condition not satisfied
	//so is there the no. in the mid
	int mid=(left+right)/2;

	if(val==a[mid])
		return mid;

	else if(val<a[mid])
		return binary_search_recursion(a,left,mid-1,val);

	else if(val>a[mid])
		return binary_search_recursion(a,mid+1,right,val);
}

int binary_search_iterative(int *a, int left, int right, int val){

	//always first check the base condition
	while(left<=right){

	//base condition not satisfied
	//so is there the no. in the mid
	int mid=(left+right)/2;

	if(val==a[mid])
		return mid;

	else if(val<a[mid])
		right=mid-1;

	else if(val>a[mid])
		left=mid+1;

	}

	return(-1);
}

int main(){
	int arr[5]={1,2,3,4,5};
	cout<<binary_search_recursion(arr,0,4,12);
	cout<<binary_search_iterative(arr,0,4,12);
	return 0;
}
