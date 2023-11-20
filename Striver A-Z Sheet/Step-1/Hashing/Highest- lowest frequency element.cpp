

// Problem Statement


// Sample Input 1 :
// 6
// 1 2 3 1 1 4
// Sample Output 1 :
// 1 2
// Sample Explanation 1:
// Input: ‘n' = 6, 'v' = [1, 2, 3, 1, 1, 4]

// Output: 1 2

// Explanation: The element having the highest frequency is '1', and the frequency is 3. The elements with the lowest frequencies are '2', '3', and '4'. Since we need to pick the smallest element, we pick '2'. Hence we return [1, 2].
// Sample Input 2 :
// 6
// 10 10 10 3 3 3
// Sample Output 2 :
// 3 3
// Sample Explanation 2:
// Input: ‘n' = 6, 'v' = [10, 10, 10, 3, 3, 3]

// Output: 3 3

// Explanation: Since the frequency of '3' and '10' is 3. Therefore, the element with the maximum and minimum frequency is '3'.
// Expected Time Complexity :
// The expected time complexity is O(n), where n is the size of the array.
// Expected Space Complexity :
// The expected time complexity is O(n), where n is the size of the array.
// Constraints :
// 2 <=  n <= 10^4
// 1 <= v[i] <= 10^9
// There are at least two distinct elements in the array.
// Time Limit: 1 sec 



/*
    Time complexity: O( n )
    Space complexity: O( n )
    
    Where 'n' is the number of elements in the array.
*/

vector<int> getFrequencies(vector<int>& v) {
    
    // Declare a variable 'n' which is equal to the size 
    // of array 'v'.
    int n = v.size();
    
    // Declare a unordered map 'freq'
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        // Increment the frequency of the current element
        freq[v[i]]++;
    }

    // Initializing variables to determine
    // maximum frequency and minimum frequency element
    int maxFreq = 0, minFreq = n;
    int maxElement = 0, minElement = (int)1e9 + 1;
    
    // Traverse through map to find the elements.
    for (auto it : freq) {
        int count = it.second;
        int element = it.first;

        if (count > maxFreq) {
            // Found an element with frequency maximum among 
            // all elements found till now
            maxElement = element;
            maxFreq = count;
        }
        else if(count == maxFreq) {
            // Checking if the current element is smaller or not            
            maxElement = min(maxElement, element);
        }
        
        if (count < minFreq) {
            // Found an element with frequency maximum among 
            // all elements found till now
            minElement = element;
            minFreq = count;
        }
        else if(count == minFreq) {
            // Checking if the current element is smaller or not            
            minElement = min(minElement, element);
        }
    }
    
    vector<int> ans = {maxElement, minElement};
    return ans;
}
