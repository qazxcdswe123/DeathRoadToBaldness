import math


def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors


def is_prime(number):
    """Returns True if number is a prime number"""
    if number < 2:
        return False
    for i in range(2, int(math.sqrt(number)) + 1):
        if number % i == 0:
            return False
    return True


def find_min_generator(p):
    # Find the prime factors of p - 1
    factors = prime_factors(p - 1)
    # Initialize a list to store the generators
    generators = []
    # Iterate through the integers from 2 to p - 1
    for g in range(2, p):
        # Assume that g is a generator
        is_generator = True
        # Check if g is a generator
        for factor in factors:
            # If g^((p - 1) / factor) is equal to 1 mod p, then g is not a generator
            if pow(g, (p - 1) // factor, p) == 1:
                is_generator = False
                break
        # If g is a generator, add it to the list of generators
        if is_generator:
            generators.append(g)
    # Return the minimum generator
    return min(generators)


# Get all prime under 10000
prime_list = []
for i in range(3, 10000):
    if is_prime(i):
        prime_list.append(i)


dict_of_primitive_roots = {}


for p in prime_list:
    dict_of_primitive_roots[p] = find_min_generator(p)


dict_of_primitive_roots = dict(
    sorted(dict_of_primitive_roots.items(), key=lambda x: x[1]))
for key, value in dict_of_primitive_roots.items():
    print(key, value)
