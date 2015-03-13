#include <iostream>
using namespace std;

long long int result=0;
void mergeSort(int a[], int low, int high);
void merge (int a[], int low, int high);

int main()
{
	int n,tmp=0,vec[500000],x;
	while(cin >> n){
		if(!n)
			break;
		result=0;
		tmp=0;
		while(tmp<n){
			cin >> x;
			vec[tmp++]=x;
		}
		mergeSort(vec,0,n-1);
		cout << result << endl;
	}
	return 0;
}
void mergeSort(int a[], int low, int high)
{ 
	int k;
	if ( high > low)
	{
		mergeSort(a, low, (low+high)/2);
		mergeSort(a, 1+(low+high)/2, high);
		merge(a, low, high);
	}
}
void merge (int a[], int low, int high)
{ 	
	int b[high];
	int i, j, k = -1, mid=(low+high)>>1; 
	for (i=low, j=mid+1; i<=mid || j<=high;  )
	{  
		if ( i>(low+high)/2 )  b[++k]=a[j++]; 
	    else if (j>high)         b[++k]=a[i++]; 
	    else if (a[i]>a[j]){
			result=result+mid-i+1;
			b[++k]=a[j++];
		}
	    else  		   b[++k]=a[i++]; 
	} 
	k=0; 
	for(i=low; i<=high; i++) a[i]=b[k++]; 
} 