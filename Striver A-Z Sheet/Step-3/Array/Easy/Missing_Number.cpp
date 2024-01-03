// Problem Statement: Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.

// Examples
// Example 1:
// Input Format: N = 5, array[] = {1,2,4,5}
// Result: 3
// Explanation: In the given array, number 3 is missing. So, 3 is the answer.

// Example 2:
// Input Format: N = 3, array[] = {1,3}
// Result: 2
// Explanation: In the given array, number 2 is missing. So, 2 is the answer.

// BRUTE FORCE -> Linear Search
// TC ->  O(N2), where N = size of the array+1. SC -> O(1)

int missingNumber(vector<int>&a, int N) {

    // Outer loop that runs from 1 to N:
    for (int i = 1; i <= N; i++) {

        // flag variable to check
        //if an element exists
        int flag = 0;

        //Search the element using linear search:
        for (int j = 0; j < N - 1; j++) {
            if (a[j] == i) {

                // i is present in the array:
                flag = 1;
                break;
            }
        }

        // check if the element is missing
        //i.e flag == 0:

        if (flag == 0) return i;
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
}


// Better -> Hashing - Using the hashing technique, we will store the frequency of each element of the given array.
// Now, the number( i.e. between 1 to N) for which the frequency will be 0, will be returned.
// TC -> O(N) + O(N) ~ O(2*N),  where N = size of the array+1.
// SC -> O(N), where N = size of the array+1. Here we are using an extra hash array of size N+1.

int missingNumber(vector<int>&a, int N) {

    int hash[N + 1] = {0}; //hash array

    // storing the frequencies:
    for (int i = 0; i < N - 1; i++)
        hash[a[i]]++;

    //checking the freqencies for numbers 1 to N:
    for (int i = 1; i <= N; i++) {
        if (hash[i] == 0) {
            return i;
        }
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
}


//Summation Approach: SUM OG -> 1-N, SUM Given -> 1-N-1, ANS -> SUM og - SUM given
// TC -> O(N) 
//SC-> O(1)

int missingNumber(vector<int>&a, int N) {

    //Summation of first N numbers:
    int sum = (N * (N + 1)) / 2;

    //Summation of all array elements:
    int s2 = 0;
    for (int i = 0; i < N - 1; i++) {
        s2 += a[i];
    }

    int missingNum = sum - s2;
    return missingNum;
}

// XOR Approach:
//XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
//XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ←Property 2
// Now, let’s XOR all the numbers between 1 to N.xor1 = 1^2^…….^N Let’s XOR all the numbers in the given array.
//xor2 = 1^2^……^N (contains all the numbers except the missing one).
//xor1 ^ xor2 = (1^1)^(2^2)^……..^(missing Number)^…..^(N^N)

// TC -> O(N) SC-> O(1)
int missingNumber(vector<int>&a, int N) {

    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < N - 1; i++) {
        xor2 = xor2 ^ a[i]; // XOR of array elements
        xor1 = xor1 ^ (i + 1); //XOR up to [1...N-1]
    }
    xor1 = xor1 ^ N; //XOR up to [1...N]

    return (xor1 ^ xor2); // the missing number
}
