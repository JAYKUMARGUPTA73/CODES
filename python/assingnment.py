import heapq

class Node:
    def __init__(self, identifier, heuristic):
        self.id = identifier
        self.heuristic = heuristic
        self.neighbors = []

    def add_neighbor(self, dest, cost):
        self.neighbors.append((dest, cost))

def a_star_search(graph, start, goal):
    priority_queue = [(0, start)]
    dist = {node.id: float('inf') for node in graph}
    dist[start] = 0
    
    while priority_queue:
        current_cost, current = heapq.heappop(priority_queue)
        
        if current == goal:
            return dist[current]  # Found the goal node, return its distance
        
        for neighbor_id, edge_cost in graph[current].neighbors:
            new_dist = dist[current] + edge_cost
            if new_dist < dist[neighbor_id]:
                dist[neighbor_id] = new_dist
                priority = new_dist + graph[neighbor_id].heuristic  # A* heuristic
                heapq.heappush(priority_queue, (priority, neighbor_id))
    
    # Goal node not reachable
    return -1

def main():
    # Example graph representation
    graph = [
        Node(0, 7),
        Node(1, 6),
        Node(2, 2),
        Node(3, 1)
    ]
    
    # Adding edges to the graph
    graph[0].add_neighbor(1, 1)
    graph[0].add_neighbor(2, 2)
    graph[1].add_neighbor(3, 5)
    graph[2].add_neighbor(1, 3)
    graph[2].add_neighbor(3, 3)
    
    start = 0
    goal = 3
    
    distance = a_star_search(graph, start, goal)
    if distance != -1:
        print(f"Shortest distance from node {start} to node {goal}: {distance}")
    else:
        print("Goal node is not reachable from the start node.")

if __name__ == "__main__":
    main()
