def calculate_p_minus_one_factorial_mod_p(p):
    res = 1
    original_p = p
    p -= 1
    while p >= 1:
        res *= p
        p -= 1
    res %= original_p
    return res


def is_prime(number):
    if number == 2:
        return True
    if number % 2 == 0:
        return False
    for i in range(3, int(number ** 0.5) + 1, 2):
        if number % i == 0:
            return False
    return True


for i in range(1, 100):
    if is_prime(i):
        print(i, calculate_p_minus_one_factorial_mod_p(i))


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def euler_phi(n):
    result = n
    for i in range(2, n + 1):
        if gcd(i, n) != 1:
            result -= 1
    return result


def print_phi_table(n):
    for i in range(1, n + 1):
        print(i, euler_phi(i))
