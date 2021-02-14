# -*- coding: utf-8 -*-
"""
Created on Wed Mar 11 17:55:10 2020

@author: Dell
"""

li = [x for x in range(51)]
final_list = list(filter(lambda x : (x%5==0),li))
print(final_list)