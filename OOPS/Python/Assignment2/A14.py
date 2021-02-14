import cProfile

def gen_triplets(limit=None):

    limit = limit if limit is not None else 20
    c = 0 
    m =2 
    while c < limit:
        for n  in range( 1 , m ):
            a = m*m - n*n
            b = 2 * m * n 
            c = m*m + n*n
            if c > limit:
                break
            print( a , b , c )
        m+=1

cProfile.run('gen_triplets()')