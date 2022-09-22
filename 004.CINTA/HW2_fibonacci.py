# Fibonacci sequence can be written as the power of a 2x2 matrix
# 1 1
# 1 0
# Use fast exponentiation to calculate the nth term of the sequence

def matrix_multiply(A, B):
    C = [[0, 0], [0, 0]]
    C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0]
    C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1]
    C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0]
    C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1]
    return C


def matrix_power(matrix, n):
    if n == 0:
        return [[1, 0], [0, 1]]
    elif n == 1:
        return matrix
    elif n % 2 == 0:
        return matrix_power(matrix_multiply(matrix, matrix), n // 2)
    elif n % 2 == 1:
        return matrix_multiply(matrix, matrix_power(matrix_multiply(matrix, matrix), n // 2))


fibonacci_matrix = [[1, 1], [1, 0]]
print(matrix_power(fibonacci_matrix, 10)[0][1])
