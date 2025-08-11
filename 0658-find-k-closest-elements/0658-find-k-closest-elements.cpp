class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0, r = n - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(arr[mid] < x) l = mid + 1;
            else r = mid - 1;
        }
        swap(l, r);
        while(r - l - 1 < k){
            if(l < 0 ) r++;
            else if(r >= n) l--;
            else if(abs(arr[l] - x) <= abs(arr[r] - x)) l--;
            else r++;
        }
        
        return vector<int>(arr.begin() + l + 1, arr.begin() + r);
    }
};