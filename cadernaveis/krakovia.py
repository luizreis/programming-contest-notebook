from sys import stdin, stdout
c = 0
while (1):
    n, f = stdin.readline().split()
    n = int(n)
    f = int(f)
    c += 1

    if (n == 0) and (f == 0):
        break

    ac = 0
    for i in range(0, n):
        ac += int(stdin.readline())
    stdout.write("Bill #" + str(c) + " costs " + str(ac) + ": each friend should pay " + str(int(ac/f)) + "\n\n")
