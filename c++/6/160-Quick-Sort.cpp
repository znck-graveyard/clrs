/*
 * Quick Sort, Page 160 (CLRS section 6.4)
 * @author Anup Agarwal
 */

#include <iostream>
#include <conio.h>

using namespace std;

template <class AnyType>
void swapElements(AnyType a[],int n, int m){
    int temp = a[n];
    a[n]=a[m];
    a[m]=temp;
}

template <class AnyType>
void QuickSort(AnyType a[],int left, int right){

    //Arrange Low, Middle, High
	if(right>left){
        int middle = (left + right)/2;
        if(a[middle]<a[left])
            swapElements(a,middle,left);
        if(a[right]<a[left])
            swapElements(a,right,left);
        if(a[right]<a[middle])
            swapElements(a,right,middle);

        swapElements(a,middle,right-1);

        AnyType pivot = a[right -1];

        //BEGIN PARTITIONING
        int i = left, j = right-1;

        while(j>=0&&i<right-1){
            while(a[++i]<pivot);
            while(a[--j]>pivot);
			if(j>i)
				swapElements(a,i,j);
			else
				break;
        }

        swapElements(a,right-1,i);

        QuickSort(a,left,i-1);
        QuickSort(a,i+1,right);
	}
}

template <class AnyType>
void QuickSort(AnyType a[],int n){
    QuickSort(a,0,n-1);
}

//Test Case
int main(){

    int a[] = {5,3,6,7};
    QuickSort(a,4);

    for(int i= 0; i<4; i++){
        cout<<a[i]<<" ";
    }

    getch();
    return 0;
}
