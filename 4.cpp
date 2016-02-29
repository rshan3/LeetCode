#include <bits/stdc++.h>

using namespace std;
 
    double findk(vector<int>::iterator a1,int n1,vector<int>::iterator a2,int n2,int k){
        if(n1<n2) 
            return findk(a2,n2,a1,n1,k);
        if(n2==0)
            return a1[k-1];

        if(k==1)
            return min(a1[0],a2[0]);

            
        int nn2 = min(k/2,n2);
        int nn1 = k-nn2;

        double m1 = a1[nn1-1],m2 = a2[nn2-1];

        if(m1==m2)
            return m1;
        else if(m1<m2)
            return findk(a1+nn1,n1-nn1,a2,nn2,k-nn1);
        else {
            return findk(a1,nn1,a2+nn2,n2-nn2,k-nn2);
        }
        
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if((n1+n2)&1)
            return findk(nums1.begin(),n1,nums2.begin(),n2,(n1+n2)/2+1);
        else {
            double ans1 = findk(nums1.begin(),n1,nums2.begin(),n2,(n1+n2)/2);
            double ans2 = findk(nums1.begin(),n1,nums2.begin(),n2,1+(n1+n2)/2);
            return (ans1+ans2)/2;
        }
    }
        
   
int main(){
	static const int arr1[] = {3};
	static const int arr2[] = {1,2};
	vector<int> s1 (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
	vector<int> s2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
	//vector<int> s1{1,1,3,3};
	//vector<int> s2{1,1,3,3};

	cout << findMedianSortedArrays(s1,s2) << endl;
	return 0;
}