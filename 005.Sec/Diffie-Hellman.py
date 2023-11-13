import random

def generate_key(p, g, a):
    A = pow(g, a, p)
    return A

def compute_secret_key(p, B, a):
    s = pow(B, a, p)
    return s

# Example usage
# P should have 512 bits or more
p = 23
g = 5
a = random.randint(1, p-1)
b = random.randint(1, p-1)

A = generate_key(p, g, a)
B = generate_key(p, g, b)

s1 = compute_secret_key(p, B, a)
s2 = compute_secret_key(p, A, b)

assert s1 == s2
print("Shared secret key:", s1)