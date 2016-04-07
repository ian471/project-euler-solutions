permutations = {}
solutions = []
stop = None
base = 1
while True:
    cube = base ** 3
    if stop and cube >= stop:
        break
    digits = tuple(sorted(str(cube)))
    cubes_list = permutations.setdefault(digits, [])
    cubes_list.append(cube)
    if len(cubes_list) == 5:
        solutions.append(cubes_list)
        stop = int('1' + '0'*len(digits))
    base += 1

soln = next(s for s in solutions if len(s) == 5)
print soln
print soln[0]
