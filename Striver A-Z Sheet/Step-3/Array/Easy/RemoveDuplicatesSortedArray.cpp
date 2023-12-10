// Example 1: 

// Input: arr[1,1,2,2,2,3,3]

// Output: arr[1,2,3,_,_,_,_]

// Explanation: Total number of unique elements are 3, i.e[1,2,3] and 
//Therefore return 3 after assigning [1,2,3] in the beginning of the array.

// Example 2: 

// Input: arr[1,1,1,2,2,3,3,3,3,4,4]

// Output: arr[1,2,3,4,_,_,_,_,_,_,_]

// Explanation: Total number of unique elements are 4, i.e[1,2,3,4] and
//Therefore return 4 after assigning [1,2,3,4] in the beginning of the array.


// Brute force -> logic -> side by side will be duplicates as array is sorted -> take final length into a var and then reduce the var whenever a duplicated is encountered
// TC -> O(N) SC-> O(1)
int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.

		int lenCount = n;
        for (int i = 0; i < n; i++) {

		// if duplicate is there
          if (arr[i] == arr[i + 1]) {

			  lenCount--; 
			  
		  }
			}
			return lenCount;
}

// Using Hashset
//Time complexity: O(n*log(n))+O(n) Space Complexity: O(n) 

int removeDuplicates(int arr[], int n) {
  set < int > set;
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();
  int j = 0;
  for (int x: set) {
    arr[j++] = x;
  }
  return k;


// Using 2 Pointers  Time Complexity: O(N)  Space Complexity: O(1)
int removeDuplicates(int arr[], int n)
{
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}

