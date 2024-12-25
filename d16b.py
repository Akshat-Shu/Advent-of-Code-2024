import fileinput, heapq

graph = { ( x, y ): c
      for y, r in enumerate( fileinput.input() )
      for x, c in enumerate( r.strip( '\n' ) ) }
start = min( k for k, v in graph.items() if v == 'S' )

q = [(0, start, 0)]
b = {(start, 0 ): 0}
r = {(start, 0 ): []}
while len(q)>0:
    c, point, dist = heapq.heappop(q)
    if graph[point] == 'E':
        s = set([(point, dist)])
        while True:
            u = set(o for n in s for o in r[n])
            if u.issubset(s):
                break
            s.update(u)
        print(c, len(set(p for p, d in s)))
        break
    if b[(point, dist)] < c:
        continue
    for nc, np, nd in [(c + 1000, point, (dist + 3) % 4),
                        (c + 1000, point, (dist + 1) % 4),
                        (c + 1, (point[0] + (1, 0, -1, 0)[dist], point[1] +  (0, 1, 0, -1)[dist]), dist)]:
        if graph[np] != '#':
            if (np, nd) not in b or b[ ( np, nd ) ] > nc:
                b[(np, nd)] = nc
                r[(np, nd)] =  [(point, dist)]
                heapq.heappush(q, (nc, np, nd))
            elif b[(np, nd)] == nc:
                r[(np, nd)].append((point, dist))