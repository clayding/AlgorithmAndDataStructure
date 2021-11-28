
#ifdef MOTSA_CPP
//复杂 略过先
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1_size = nums1.size();
        int n2_size = nums2.size();

        int total_size = (n1_size + n2_size);
        if (total_size % 2) {
            m_begin =  m_end = total_size / 2 + 1;
        } else {
            m_begin = total_size / 2;
            m_end = m_begin + 1; 
        }
    }
};

#endif //MOTSA_CPP
