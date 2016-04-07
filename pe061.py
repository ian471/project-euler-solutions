from __future__ import division


def figurate_number(r, n):
    if r % 2:
        a = (r - 2) / 2
        b = (4 - r) / 2
    else:
        a = r / 2 - 1
        b = -r / 2 + 2
    return int(a * n*n + b * n)


def generate_p_sets():

    p_min = 10**3
    p_max = 10**4
    r_min = 3
    r_max = 9

    # Generate all the P values we need.
    p_sets = [[] for i in xrange(r_max - r_min)]
    for r, p_set in enumerate(p_sets, r_min):
        n = 1#int(p_min**.5)
        while True:
            p = figurate_number(r, n)
            if p >= p_max:
                break
            if p >= p_min:
                p_set.append(p)
            n += 1

    return p_sets


def follows(a, b):
    return a % 100 == b // 100


# cache me!
def find_cycle(p_cycle, r_destinations):
    # needs p_sets from global scope

    if len(p_cycle) == len(p_sets):
        if follows(p_cycle[-1], p_cycle[0]):
            # we're done!
            return p_cycle
        return

    if not p_cycle:
        r = r_destinations[0]
        for p in p_sets[r]:
            c = find_cycle([p], r_destinations[1:])
            if c:
                return c
        # We failed :(
        return
    
    p_from = p_cycle[-1]
    for r in r_destinations:
        for p_to in p_sets[r]:
            if follows(p_from, p_to):
                r_dest = r_destinations[:]
                r_dest.remove(r)
                c = find_cycle(p_cycle + [p_to], r_dest)
                if c:
                    return c
    # dead end.
    return

if __name__ == '__main__':
    p_sets = generate_p_sets()
    solution = find_cycle([], range(len(p_sets)))
    print solution
    print sum(solution)
