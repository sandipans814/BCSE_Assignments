def fib():
    a = 0
    b = 1
    i = 1
    while i<=7 :
        c = a + b
        a = b
        b = c
        yield b
        i = i + 1
fibonacci = fib()
while True:
    try:
        print(next(fibonacci),end = " ")
    except StopIteration:
        break