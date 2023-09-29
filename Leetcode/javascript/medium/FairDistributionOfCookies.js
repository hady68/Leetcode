// You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are also given an integer k that denotes the number of children to distribute all the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.

// The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.

// Return the minimum unfairness of all distributions.



// Solution
/**
 * @param {number[]} cookies
 * @param {number} k
 * @return {number}
 */
var distributeCookies = function (cookies, k) {
  const people = new Array(k).fill(0);
  const ans = { val: Infinity };
  backtrack(people, ans, cookies, 0);

  return ans.val;
};

function backtrack(people, ans, cookies, idx) {
  if (idx === cookies.length) {
    let max = -Infinity;
    for (let i = 0; i < people.length; i++) {
      max = Math.max(people[i], max);
    }
    ans.val = Math.min(ans.val, max);
    return;
  }

  for (let i = 0; i < people.length; i++) {
    people[i] += cookies[idx];
    backtrack(people, ans, cookies, idx + 1);
    people[i] -= cookies[idx];
  }
}
