class Solution:
    def sortColors(self, nums):
        colour = 0;
        nums_index = 0;
        sorted_array = [];
        while colour != 2:
            print(colour);
            for x in nums:
                if(nums_index != len(nums)):
                    if(x == colour):
                        sorted_array.append(x);
                else:
                   colour = colour + 1;
                
                nums_index = nums_index + 1;
                        
        return sorted_array;
                        

                        
        
                
                    
      

nums = [0, 1, 2, 2, 1, 1, 2, 2, 0, 0, 0, 0, 2, 1]
print("Before Sort: ")
print(nums)
# [0, 1, 2, 2, 1, 1, 2, 2, 0, 0, 0, 0, 2, 1]

nums = Solution().sortColors(nums)
print("After Sort: ")
print(nums)
# [0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2]
