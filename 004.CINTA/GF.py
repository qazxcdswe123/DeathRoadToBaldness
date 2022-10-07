def GF_add(a, b) -> int:
    return a ^ b


def GF_mul(a, b) -> int:
    ans = 0
    for i in range(8):
        if b & 1:
            ans = GF_add(ans, a)
        highest_bit = a & 0x80
        a <<= 1
        if highest_bit:
            a ^= 0x1b
        b >>= 1
    return ans % 256


def GF_inverse_test():
    for i in range(1, 256):
        for j in range(1, 256):
            if GF_mul(i, j) == 1:
                print(i, j)


GF_inverse_test()
