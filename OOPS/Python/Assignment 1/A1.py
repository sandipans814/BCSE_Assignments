# -*- coding: utf-8 -*-
"""
Created on Wed Mar 11 12:17:32 2020

@author: Dell
"""
from math import sqrt

def is_prime(n):
    if (n <= 1):
        return False
    if (n == 2):
        return True
    if (n % 2 == 0):
        return False

    i = 3
    while i <= sqrt(n):
        if n % i == 0:
            return False
        i = i + 2

    return True


def prime_generator():
    n = 1
    while True:
        n += 1
        if is_prime(n):
            yield n


generator = prime_generator()

for i in range(5):
    print(next(generator))
    
    
    
    