table = {}

N,Q = input().split()

for i in range(int(N)):
    nama,nomor = input().split()
    table[nama] = nomor

for i in range(int(Q)):
    saha = input()
    if saha in table:
        print(table[saha])
    else:
        print("NIHIL")
