formation=input()
f=0
length=len(formation)
for i in range(length//2):
    
    if formation[i] != formation[length-i-1]:
        print("weak formation")
        f=1
        break

if f==0:
    print("strong formation")