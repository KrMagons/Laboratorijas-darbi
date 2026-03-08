"""
A8. Dots naturals skaitlis n. Izdrukat tos skaitla n reizinatajus,
kuri ir kada naturala skaitla kvadrati.
"""

ok = 1
while ok==1:
    while True:
        n = int(input("Ievadi ne nulles naturalu skaitli N: "))
        if n<1:
            print("N ir jabut ne nulles naturalam skaitlim! Megini velreiz")
            continue
        else: break
    for i in range(1, n+1):
        if(n%i==0):
            for j in range(1, i+1):
                if j*j==i:
                    print(f"Reizinatajs {i} ir {j}^2")
    ok = int(input("Turpinat (1) vai Beigt (0): "))