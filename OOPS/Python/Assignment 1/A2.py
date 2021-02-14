# -*- coding: utf-8 -*-
"""
Created on Wed Mar 11 12:41:48 2020

@author: Dell
"""

Coupon = {'Monday' : 12,
          'Tuesday' : 10,
          'Wednesday' : 25,
          'Thursday' : 10,
          'Friday' : 20,
          'Saturday' : 12,
          'Sunday' : 5,
          }
day  = input("Enter the day of the week : ")
print("Discount for ",day," is : ",Coupon[day],"%")