from queue import PriorityQueue

def astar(heu, graph, start):
    pq= PriorityQueue()
    visited=[]

    pq.put(heu[start],[start,0,start])
    while pq:
        y=pq.get()[1]