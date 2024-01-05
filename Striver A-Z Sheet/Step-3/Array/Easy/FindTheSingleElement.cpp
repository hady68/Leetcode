// Problem Statement: Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

// Examples
// Example 1:
// Input Format: arr[] = {2,2,1}
// Result: 1
// Explanation: In this array, only the element 1 appear once and so it is the answer.

// Example 2:
// Input Format: arr[] = {4,1,2,1,2}
// Result: 4
// Explanation: In this array, only element 4 appear once and the other elements appear twice. So, 4 is the answer.

// brute force uing 2 loops Time Complexity: O(N*2)


// hash aray and find frequency 1
//Time Complexity: O(N)+O(N)+O(N), 
//Space Complexity: O(maxElement+1) where maxElement = the maximum element of the array.

int getSingleElement(vector<int> &arr) {

    //size of the array:
    int n = arr.size();

    // Find the maximum element:
    int maxi = arr[0];
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
    }

    // Declare hash array of size maxi+1
    // And hash the given array:
    vector<int> hash(maxi + 1, 0);
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    //Find the single element and return the answer:
    for (int i = 0; i < n; i++) {
        if (hash[arr[i]] == 1)
            return arr[i];
    }

    //This line will never execute
    //if the array contains a single element.
    return -1;
}

//using map
// Time Complexity: O(N*logM) + O(M), where M = size of the map i.e. M = (N/2)+1. N = size of the array.
//Space Complexity: O(M) as we are using a map data structure. Here M = size of the map i.e. M = (N/2)+1.
int getSingleElement(vector<int> &arr) {

    //size of the array:
    int n = arr.size();

    // Declare the hashmap.
    // And hash the given array:
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    //Find the single element and return the answer:
    for (auto it : mpp) {
        if (it.second == 1)
            return it.first;
    }

    //This line will never execute
    //if the array contains a single element.
    return -1;
}


// Optimal -> Using XOR
// XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
// XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ←Property 2

int getSingleElement(vector<int> &arr) {
    //size of the array:
    int n = arr.size();

    // XOR all the elements:
    int xorr = 0;
    for (int i = 0; i < n; i++) {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}


// Without any data structure
// Time Complexity: O(N)
// Space Complexity: O(1)


int getSingleElement(vector<int> &arr){
	int n = arr.size();
	int ans;
	
	// Traversing through the array.
	for(int i = 0; i < n; ++i){
		
		// Checking if 'Arr[i]' is neither equal to 'Arr[i - 1]' and 'Arr[i + 1]'.
		if((i == 0 || arr[i] != arr[i - 1]) && (i == n - 1 || arr[i] != arr[i + 1])){
			ans = arr[i];
			break;
		}
	}
	return ans;
}
