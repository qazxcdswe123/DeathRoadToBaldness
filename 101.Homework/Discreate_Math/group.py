"""
Description

给定一张 n x n 的二元运算表 f, 其中 f_i,j 表示 ij = f_ij，问该二元运算是否构成群，如果是，输出每个数的逆元。

Input
第一行一个正整数 t ，表示数据组数。

每组数据第一行一个正整数 n ，表示表的大小。

接下来 n 行，每行 n 个整数，表示 f_i,j, 1 < f_i,j < n

Output
对于每组数据，如果不构成群，输出一行 "NO" ， 否则第一行输出 "YES"，第二行输出每个数的逆元。

Sample Input
3
3
1 2 3
2 3 1
3 1 2
6
1 4 3 1 5 2
3 5 2 5 4 3
2 3 3 4 1 4
2 5 1 1 2 5
6 5 4 5 1 5
6 1 3 2 1 2
6
1 2 3 4 5 6
2 4 6 1 3 5
3 6 2 5 1 4
4 1 5 2 6 3
5 3 1 6 4 2
6 5 4 3 2 1

Sample output
YES
1 3 2
NO
YES
1 4 5 2 3 6

注意每组数据输出逆元时不要输出行末空格！
"""

def is_group(f):
    n = len(f)
    # Check identity
    for i in range(n):
        if f[i][i] != i:
            return False

    # Check commutativity
    # Check inverse
