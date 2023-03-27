# -*- coding: utf-8 -*-
"""
Created on Tue Oct  4 19:52:17 2022

@author: Codey Sivley
For Software Engineering Midterm
Dr Maxwell Fall 2022
"""
##################### read text into array
nums = []
numbles = open("inputFile.txt", 'r')
for each in numbles:
    nums.append(int(each))

print("The numbers are: " + str(nums))

##################### sum first 14 numbers
numSum = 0
for i in range(len(nums) - 1):
    numSum += nums[i]

print("The sum of the first " + (str((len(nums)) - 1)) + " is: " + str(numSum))
print("The final number is " + str(nums[-1]))
##################### divide by last one
result = numSum / nums[-1]

##################### print result
print("The result is: " + str(result))