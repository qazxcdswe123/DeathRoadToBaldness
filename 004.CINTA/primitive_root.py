import math
import sympy


def prime_factors_list(number):
    """Returns a list of prime factors of a number"""
    for i in range(2, number + 1):
        while number % i == 0:
            prime_factors.append(i)
            number //= i


def gcd(a, b):
    """Returns the greatest common divisor of a and b"""
    while b:
        a, b = b, a % b
    return a


def is_prime(number):
    """Returns True if number is a prime number"""
    if number < 2:
        return False
    for i in range(2, int(math.sqrt(number)) + 1):
        if number % i == 0:
            return False
    return True


def is_primitive_root(number, prime):
    """Returns True if number is a primitive root of the prime factors"""
    for factor in prime_factors:
        if factor > number:
            break
        if type((prime - 1) / factor) == int:
            if pow(number, (prime - 1) // factor, prime) == 1:
                return False
    return True


prime_list = []
for i in range(2, 10000):
    if is_prime(i):
        prime_list.append(i)

prime_factors = []
prime_factors_list(10000)

dict_of_primitive_roots = {}

for p in prime_list:
    for i in range(2, p):
        if is_primitive_root(i, p):
            dict_of_primitive_roots[p] = [i]
            break

dict_of_primitive_roots = dict(
    sorted(dict_of_primitive_roots.items(), key=lambda x: x[1]))
for key, value in dict_of_primitive_roots.items():
    print(key, value)
