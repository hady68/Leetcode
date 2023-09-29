// Given a valid (IPv4) IP address, return a defanged version of that IP address.

// A defanged IP address replaces every period "." with "[.]".

 

// Example 1:

// Input: address = "1.1.1.1"
// Output: "1[.]1[.]1[.]1"
// Example 2:

// Input: address = "255.100.50.0"
// Output: "255[.]100[.]50[.]0"
 

// Constraints:

// The given address is a valid IPv4 address.


// Brute -> TC -> O(N) SC -> O(N)
class Solution {
public:
    string defangIPaddr(string address) {
        string result = "";  // Create an empty string to store the result
        
        for(int i = 0; i < address.length(); i++) {
            if(address[i] == '.') {
                result += "[.]";  // Concatenate "[.]" to the result string
            } else {
                result += address[i];  // Concatenate the current character as is
            }
        }




        return result;  // Return the modified result string
    }


// Better approach -> using the substring methods in string 
class Solution {
public:
    string defangIPaddr(string address) {
        int i = 0; // Initialize a variable i to keep track of the current position in the address string
        
        // Start a loop that runs while i is less than the length of the address string
        while (i < address.length()) {
            // Check if the character at index i in the address string is a dot ('.')
            if (address[i] == '.') {
                // If the character is a dot, replace it with "[.]" using substring manipulations
                // Create a new string by combining three parts:
                // 1. The substring from the beginning up to (but not including) the dot character
                // 2. The string "[.]"
                // 3. The substring after the dot character
                address = address.substr(0, i) + "[.]" + address.substr(i + 1, -1);
                i = i + 2; // Move i two positions ahead to skip the replaced characters "[.]"
            } else {
                // If the character is not a dot, move to the next character by incrementing i
                i++;
            }
        }
        
        return address; // Return the modified address string
    }
};

};
