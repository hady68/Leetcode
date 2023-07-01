// You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are also given an integer k that denotes the number of children to distribute all the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.

// The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.

// Return the minimum unfairness of all distributions.

//solution

class Solution {
public:
    void helper(int start, const vector<int>& cookies, vector<int>& temp, int k, int& ans) {
        int n = cookies.size();
        if (start == n) {
            int maxi = INT_MIN;
            for (int i = 0; i < k; i++) {
                maxi = max(maxi, temp[i]);
            }
            ans = min(ans, maxi);
            return;
        }

        for (int i = 0; i < k; i++) {
            temp[i] += cookies[start]; // take
            helper(start + 1, cookies, temp, k, ans);
            temp[i] -= cookies[start]; // back-track
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int ans = INT_MAX;
        vector<int> temp(k, 0);
        helper(0, cookies, temp, k, ans);
        return ans;
    }
};
