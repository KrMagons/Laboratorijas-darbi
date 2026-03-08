"""
B28. Dots naturals skaitis n. Atrast visus tadu naturalu
skaitlu trijniekus a, b, c,a <= b <= c <= n, lai a^2+b^2=c^2.
Risinajuma izmantot funkciju, kas par tris skaitliem noskaidro,
vai tie atbilst nosacijumam.
"""

import math #sqrt()

def is_pythagorean(a, b, c, n):
    if(a<=b and b<=c and c<=n and a*a+b*b==c*c): return True
    return False

ok=1
while(ok==1):
    while(True):
        n = int(input("Ievadi ne nulles naturalu skaitli N: "))
        if(n<1):
            print("N jabut ne nulles naturalam skaitlim! Megini velreiz")
            continue
        else: break
    if(n>4): #Lidz n=4 trijnieku neeksiste
        #Nulli neizskatam, jo tad bus n izvades ar a=0, b=i, c=b
        for a in range(1, n+1):
            for b in range (a, n+1):
                c = int(math.sqrt(a*a+b*b))
                if is_pythagorean(a,b,c,n):
                    print(f"a: {a}\nb: {b}\nc: {c}\n")
    else: print("Trijnieki a, b, c netika atrasti")

    ok=int(input("Turpinat (1) vai Beigt (0): "))