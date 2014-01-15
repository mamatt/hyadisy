import sys
i = 0
for a in range(0,1024) :
	sys.stdout.write (str(a*2) +  ",")
	i= i+1

for a in range(1024,-1024,-1) :
        sys.stdout.write (str(a*2) +  ",")
	i = i+1

for a in range(-1024,0) :
	sys.stdout.write (str(a*2) + ",")
	i = i+1

print i
