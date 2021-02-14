import numpy as np

a = np.random.randint( 0 ,20 , 15 )

print('The vector : '  , *a )
print('Most frequent element : ' , np.argmax(np.bincount(a)))
binc = np.bincount(a)

## masking to prevent counting non-present items
binc[binc == 0] = 1e9
# print(binc)
print('Least frequent element : ', np.argmin(binc))