class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)

        m, n = len(nums1), len(nums2)
        left, right = 0, m
        halfLen = (m+n+1)//2
        while left<=right:
            i=(left+right)//2
            j=halfLen-i
            if (i<right) and (nums1[i] < nums2[j-1]):
                left=i+1
            elif (i>left) and (nums1[i-1] > nums2[j]):
                right=i-1
            else:
                maxLeft = 0
                if i==0:
                    maxLeft=nums2[j-1]
                elif j==0:
                    maxLeft=nums1[i-1]
                else:
                    maxLeft=max(nums1[i-1],nums2[j-1])
                if (m+n)%2 == 1:
                    return maxLeft

                minRight = 0
                if i==m:
                    minRight=nums2[j]
                elif j==n:
                    minRight=nums1[i]
                else:
                    minRight=min(nums1[i],nums2[j])
                
                return (maxLeft+minRight)/2
        
        return 0.0
