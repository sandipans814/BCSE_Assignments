# -*- coding: utf-8 -*-
"""
Created on Wed Mar 11 19:39:16 2020

@author: Dell
"""

Pythagorean_Triplet = [{'s':2,'m':3,'l':5},{'s':12,'m':13,'l':15}]

final_list = [var for var in Pythagorean_Triplet if var['s']<10]
print(final_list)