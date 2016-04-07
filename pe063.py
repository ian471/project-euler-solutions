answers = []
for p in xrange(1, 22):
    for base in xrange(len(str(p)), 10):
        power = base**p
        digits = len(str(power))
        if digits == p:
            answers.append(power)
            #print base,'**',p,'=',power
        if digits > p:
            break
    if base <= 2:
        break
    p += 1

print len(answers)
