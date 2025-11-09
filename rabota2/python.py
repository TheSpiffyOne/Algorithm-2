def power(x, n):
    if n == 0:
        return 1
    if n < 0:
        return 1 / power(x, -n)
    return x * power(x, n - 1)

print(f"2^5 = {power(2, 5)}")
print(f"3^-2 = {power(3, -2)}")
