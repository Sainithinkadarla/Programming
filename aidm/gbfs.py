from queue import PriorityQueue

def gbfs(start, goal , graph, n):
    visited=[]
    pq=PriorityQueue()
    pq.put((0,start))
    visited.append(start)
    while pq:
        u=pq.get()[1]
        print(u,end="")
        if u == goal:
            break
        else:
            for v in graph[u].keys():
                if v not in visited:
                    visited.append(v)
                    pq.put((graph[u][v],v))
    print()
    return visited

nodes=int(input("nodes: "))
graph={}
for i in range(nodes):
    root = input("enter node: ")
    ch={}
    nc=int(input("no of: "))
    for j in range(nc):
        child=input("child : ")
        cost = int(input("cost: "))
        ch[child]=cost
    graph[root]=ch
print(graph)
start = input("start node: ")
goal = input("goal: " )
gbfs(start, goal , graph, nodes)