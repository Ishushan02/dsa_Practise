#include <iostream>

// Mega Class Binary Search
/*
1st question is Sqrt with precision
cout only prints till 5 digits, use printf to print more digit precision

1. find precision with Normal Method as well as BS method(State Space Solution)
*/

/*
2.
Find division of 2 numbers using BS
Leetcode : 29 (https://leetcode.com/problems/divide-two-integers/)

int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        long long int tempdivd = abs(dividend);
        long long int tempdivs = abs(divisor);
        long long int s = 0;
        long long int e = tempdivd;
        long long int mid = (s + e)/2;
        long long  ans = 0;

        while(s <= e){

            if (mid * tempdivs == tempdivd){
                ans = mid ;
                break;
            }
            else if(tempdivs * mid > tempdivd){
                e = mid - 1;
            }else{
                ans = mid;
                s = mid+1;
            }
            mid = (s+e)/2;
        }

        if ((dividend < 0 && divisor>0 )||( dividend > 0 && divisor < 0 )){
            return 0 - ans ;
        }

        return ans ;
    }
*/

/*
Good IMP Question (State Space Solution)
LeetCode - 875 (https://leetcode.com/problems/koko-eating-bananas/description/)


using namespace std;
class Solution {
public:
    bool check(int k, vector<int> arr, int h){
        bool ans = false;


        double totalHours = 0;
        for(int i = 0; i < arr.size(); i++){
            totalHours += ceil(arr[i]/(double)k);
        }


        return totalHours <= h;

    }



    int minEatingSpeed(vector<int>& piles, int h) {

        int ans = 0;
        int n = piles.size();
        // if(n == 1){

        //     return (int)(ceil(((float)piles[0])/((float)h))) ;
        // }

        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int mid = (s+e)/2;

        while(s<=e){
            bool totalHours = check(mid, piles, h);
            cout<< " Total Hours " << totalHours << " low "<< s << ", high "<< e <<" and k is "<< mid<< endl;
            if(totalHours){
                e = mid-1;
                ans = mid;
            }else{
                s = mid+1;

            }
            mid = (s+e)/2;

        }

        return ans;
    }
};
*/

/*
IMP Question

Leetcode 1482 (https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/submissions/1302069667/)


class Solution {
public:

    bool checkbloom(vector<int>& bloomDay, int m, int k, int Dday){

        int counter = 0;
        for(int i = 0;i<bloomDay.size();i++){

            // check if flower is bloomed
            if (bloomDay[i]<= Dday) counter++;

            // if k flowers are counted and bloomed then make the counter 0 again

            if(counter==k){
                m--;
                counter = 0;
                if (m==0) break;
            }

            // if it's not adjacent again start from 0 ;
            if(bloomDay[i]>Dday){
                counter = 0;
            }
        }

        if (m==0){
            return true;
        }else{
            return false;
        }
    }


    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = -1;
        int n = bloomDay.size();
        double data = (double)m * (double)k;
        if (n < data ) return -1; // not possible to bloom

        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());

        int mid = (s+e)/2;

        while(s<=e){
            bool res = checkbloom(bloomDay, m, k, mid);

            if (res){
                ans = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
            mid = (s+e)/2;
        }

        return ans;

    }
};


*/

/*

K-diff Pairs (https://leetcode.com/problems/k-diff-pairs-in-an-array/submissions/1302803731/)

class Solution {
public:
bool binary_search(vector<int>& arr, int size, int key, int index){
  int start = 0;
  int end = size - 1;
  int mid = (start + ((end - start) / 2));


  while(start <= end){

    if (abs(arr[mid]) == key){
        if (mid != index){
            return true;
            }
        else{
            return false;
        }
        }else if(arr[mid] > key){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
        mid = (start + ((end - start) / 2));
    }
    return false;
}

    int findPairs(vector<int>& nums, int k) {
        int n =nums.size();
        if (n == 2 ){
            if (((nums[0]-nums[1])==k)|| (nums[1]-nums[0])==k){
                return 1;
            }else {
                return 0;
            }
        }
        sort(nums.begin(), nums.end());


        set<pair<int, int>> res;

        for(int i = 0;i<n;i++){
            int val = abs(k + nums[i]);
            int start = 0;
            int end = n-1;
            int mid = (start+end)/2;
            bool temp = binary_search(nums, n, val, i);
            if (temp){
            cout << " Nums[i] is " << nums[i] <<" and Val is " << val << endl;

            res.insert(make_pair(val, nums[i]));
            }
        }
        return res.size();
    }
};

*/

/*

IMP
Find K Closest ELement
LeetCode 658 (https://leetcode.com/problems/find-k-closest-elements/description/)


Method1
vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int mid = (low+high)/2;

        while(high - low >= k){
            int lowdiff = x - arr[low];
            int highdiff = arr[high] - x;

            if (lowdiff > highdiff){
                low++;
            }else{
                high--;
            }
        }

        cout << " low is " << low << " high is "<< high << endl;

        vector<int> ans ;
        for(int i = low;i <= high;i++){
            ans.push_back(arr[i]);
        }

        return ans;




    }


Method2
try getting the first closest window and then try increasing the window according to k


*/

/*

// EXPONENTIAL SEARCH // DOUBLING SEARCH // GALLOPING SEARCH

- It's application is when the size of Array is very Large
- The main intution of the algorithm is that instead of applying Binary Search
in the whole array only on a part BS is applied.

Algorithm

arr[0,......., n], key
{
    if arr[0] == key:
        return True

    // move exponentially
    int i = 1;
    while(i < n && arr[i] < key ):
        i = i * 2


    // now apply Binary Search in
    start index = i / 2;
    end index = min(i, n-1);

    arr_bs(arr, i / 2, min(i, n -1), key)
}

Time Complexity O(log ((2^logm) / 2))

Application 
- search in infinite size array (or) search in unbounded search
- better than BS when key is near begining

*/