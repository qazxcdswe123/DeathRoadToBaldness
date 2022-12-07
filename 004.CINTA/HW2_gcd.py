import time
# Return x, y, gcd


def egcd(a, b):
    if (a == 0):
        return (0, 1, b)
    else:
        x, y, gcd = egcd(b % a, a)
        return (y - (b // a) * x, x, gcd)


def binary_egcd(a, b):
    # Finding k, which is the greatest power of 2
    # that divides both a and b.
    k = 0
    while ((a | b) & 1 == 0):
        a >>= 1
        b >>= 1
        k += 1

    r0, r1 = a, b
    s0, s1, t0, t1 = 1, 0, 0, 1

    while (r1 != 0):
        # If r0(a) is even, make it odd by dividing by 2
        while (r0 & 1 == 0):
            r0 >>= 1
            if (((s0 | t0) & 1) == 0):
                s0 >>= 1
                t0 >>= 1
            else:
                s0 = (s0 + b) >> 1
                t0 = (t0 - a) >> 1

        # If r1(b) is even, make it odd by dividing by 2
        while (r1 & 1 == 0):
            r1 >>= 1
            if (((s1 | t1) & 1) == 0):
                s1 >>= 1
                t1 >>= 1
            else:
                s1 = (s1 + b) >> 1
                t1 = (t1 - a) >> 1

        if (r1 < r0):
            r0, r1 = r1, r0
            s0, s1 = s1, s0
            t0, t1 = t1, t0
        r1 -= r0
        s1 -= s0
        t1 -= t0

    return (r0 << k, s0, t0)


# start = time.time()
# print(egcd(111, 5))
# end = time.time()
# print("Time taken for egcd: ", end - start)

# start = time.time()
# print(binary_egcd(111, 5))
# end = time.time()
# print("Time taken for binary_egcd: ", end - start)


# Calculate Modular Multiplicative Inverse
def get_modular_inverse(a, m):
    s, t, gcd = egcd(a, m)
    if (gcd != 1):
        return None
    else:
        return s % m


print(get_modular_inverse(5, 693))
print(get_modular_inverse(7, 495))
print(get_modular_inverse(9, 385))
print(get_modular_inverse(11, 315))
