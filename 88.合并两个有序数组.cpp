/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;++i)
        {
            nums1[m+i]=nums2[i];
        }
        std::sort(nums1.begin(),nums1.end());
    }
};



class Solution2
{
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int pa = 0, pb = 0;
        int sorted[m + n];
        int cur;
        while (pa < m || pb < n) {
            if (pa == m)
                cur = B[pb++];
            else if (pb == n)
                cur = A[pa++];
            else if (A[pa] < B[pb])
                cur = A[pa++];
            else
                cur = B[pb++];
            sorted[pa + pb - 1] = cur;
        }
        for (int i = 0; i != m + n; ++i)
            A[i] = sorted[i];
    }
};

/*
方法3：逆向双指针
算法
方法 2 中之所以要使用临时变量，是因为如果直接合并到数组 A 中，A 中的元素可能会在取出之前被覆盖。那么如何直接避免覆盖 A 中的元素呢？观察可知，A 的后半部分是空的，可以直接覆盖而不会影响结果。因此可以指针设置为从后向前遍历，每次取两者之中的较大者放进 A 的最后面。

严格来说，在此遍历过程中的任意一个时刻，A 数组中有 m-pa-1m−pa−1 个元素被放入 A 的后半部，B 数组中有 n-pb-1n−pb−1 个元素被放入 A 的后半部，而在指针 pa 的后面，A 数组有 m+n-pa-1m+n−pa−1 个位置。由于

m+n-pa-1\geq m-pa-1+n-pb-1
m+n−pa−1≥m−pa−1+n−pb−1

等价于

pb\geq -1
pb≥−1

永远成立，因此 pa 后面的位置永远足够容纳被插入的元素，不会产生 pa 的元素被覆盖的情况。
*/

class Solution3 {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int pa = m - 1, pb = n - 1;
        int tail = m + n - 1;
        int cur;
        while (pa >= 0 || pb >= 0) {
            if (pa == -1)
                cur = B[pb--];
            else if (pb == -1)
                cur = A[pa--];
            else if (A[pa] > B[pb])
                cur = A[pa--];
            else
                cur = B[pb--];
            A[tail--] = cur;
        }
    }
};
//时间复杂度：O(m+n)O(m+n)
//指针移动单调递减，最多移动 m+nm+n 次，因此时间复杂度为 O(m+n)O(m+n)。

//空间复杂度：O(1)O(1)
//直接对数组 A 原地修改，不需要额外空间。


// @lc code=end

