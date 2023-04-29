# This code demonstrates pathological coupling 
def eitherOr():
    return 0

num = int(input("Input a number: "))
if num % 2 == 0:
    def eitherOr(x):
        return int(x / 2)
else:
    def eitherOr(x):
        return x * 2

print(eitherOr(num))