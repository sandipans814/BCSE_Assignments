# -*- coding: utf-8 -*-
"""
Created on Wed Mar 11 15:56:24 2020

@author: Dell
"""

def mat(n):
    lst = []
    for i in range(n):
        temp = []
        for j in range(n):
            ele = int(input("Enter element : "))
            temp.append(ele)
        lst.append(temp)
    return lst

n = int(input("Enter the number of rows and columns : "))
A = mat(n)
B = mat(n)
result = [[sum(a * b for a, b in zip(A_row, B_col))  
                        for B_col in zip(*B)] 
                                for A_row in A] 
  
for r in result: 
    print(r) 