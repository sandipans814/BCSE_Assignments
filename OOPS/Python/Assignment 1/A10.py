# -*- coding: utf-8 -*-
"""
Created on Wed Mar 11 19:18:22 2020

@author: Dell
"""
from math import sqrt

lst = [4,9,16,25,36,49,64,81,100]

final_list_1= list(filter(lambda x :sqrt(x)%2!=0,lst))
final_list_2 = list(map(lambda x :sqrt(x)%2,lst))
print(final_list_1)
print(final_list_2)
 