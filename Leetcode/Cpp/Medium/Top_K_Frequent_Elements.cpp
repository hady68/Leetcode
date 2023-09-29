//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// brute 
// using map and priority queue ->
//// Time: O(n log k)
// Space: O(n + k)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto it = m.begin(); it != m.end(); it++) {
            pq.push({it->second, it->first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};

// Optimized
// Using Bucket sort
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
          
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        // ex -> 1,1,1,2,2,3 -> 1->3, 2->2, 3->1
       vector<vector<int>> buckets(n + 1);

        for (auto it = m.begin(); it != m.end(); it++) {

            buckets[it->second].push_back(it->first);
        }

        // buckets -> 1->3 , 2->2 , 3->1
        
        vector<int> result;

        // k = 2 -> ans ={1,2}
        //. loop from end as max bucket stores element with most frequency -> 1 

        for (int i = n; i >= 0; i--) {
            // will run only till k elements condition is fulfilled
            if (result.size() >= k) {
                break;
            }

            // it's not empty, it means there are elements with a frequency of i.
            // The elements from buckets[i] are inserted at the end of the result vector using the insert function.
            
            if (!buckets[i].empty()) {
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        
        return result;

    }
};

        
        return result;
    }
};

