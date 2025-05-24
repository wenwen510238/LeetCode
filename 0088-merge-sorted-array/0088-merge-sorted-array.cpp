class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int m_ind = m-1;
        int n_ind = n-1;
        int total = m+n-1;
        while(m_ind >= 0 && n_ind >= 0){
            if(nums1[m_ind] <= nums2[n_ind]){
                nums1[total] = nums2[n_ind];
                n_ind --;
            }
            else{
                nums1[total] = nums1[m_ind];
                m_ind --;
            }
            total--;
        }
        while(n_ind >= 0){
            nums1[total] = nums2[n_ind];
            total--;
            n_ind--;
        }
    }
};