import random

"""
m: plaintext
p: prime number
g: generator
x: private key
"""
def ElGamal_Enc(m: bytes, p, g, x):
    r = random.randint(1, p - 1)

