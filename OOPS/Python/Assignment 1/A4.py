# -*- coding: utf-8 -*-
"""
Created on Wed Mar 11 13:17:06 2020

@author: Dell
"""

from itertools import permutations 

str = "ABCDE"

p = permutations(str)

for j in list(p):
    print(''.join(j),end=" ")