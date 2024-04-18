# Data Structures Final Project

This project is currently in progess.

Will keep project requirements in this file for ease of access.

## Project Requirements
### Functionality: Here is the list of things your project should support:
1) Read the information from the dataset (a csv file) and create a weighted directed graph G. Note
   that you need to consider two weights for each edge. One is the Distance and the other is Cost.

2) Find the shortest path between the given origin airport and destination airport. The algorithm
   should output both the path and the length of the path. The algorithm should provide the
   appropriate message if such path doesn’t exist.

3) Find all shortest paths between the given origin airport and all the airports in the destination state.
   The algorithm should output all the paths and their lengths. The algorithm should provide the
   appropriate message if no such paths exist.

4) Find the shortest path between the given origin airport and destination airport with a given
   number of stops. The algorithm should provide the appropriate message if such path doesn’t exist.

5) Count and display total direct flight connections to each airport. You should consider both
   outbound and inbound flights. For instance, if you can directly fly to Tampa airport only from
   Miami, Orlando, and Atlanta, the inbound count for Tampa airport would be 3. If you can directly
   fly from Tampa airport only to New York, the outbound count for Tampa airport is 1. The total
   number of direct flight connections for Tampa airport is 4. The list of airports should be sorted
   based on the total direct flight connections count, starting with the airports having the highest
   number of direct flight connections.

6) Create an undirected graph G_u from the original directed graph G using the following rules:
   a. For each pair of vertices u and v, if there is only one directed edge(either (u,v) or (v,u))
   between them, you keep that single edge with its corresponding cost as an undirected
   weighted edge. You can ignore the distance on that edge.
   b. For each pair of vertices u and v, if there are two directed edges (u,v) and (v, u) between
   them, you keep the one with the minimum cost value as an undirected weighted edge. You
   can ignore the distance on that edge.

7) Generate a Minimal Spanning Tree utilizing Prim’s algorithm on G_u that you created in the
   previous step. The algorithm will output both the content of the constructed MST and its total cost.
   In this step, for each edge you need to consider the cost as weight to minimize the total cost. In the
   event of a disconnected graph, the algorithm will appropriately notify that an MST cannot be
   formed. Note: A connected graph is defined as one where there exists a path between every pair of
   vertices.

8) Generate a Minimal Spanning Tree using Kruskal’s algorithm on G_u that you created in the
   previous step. The algorithm will output both the content of the constructed MST and its total cost.
   In this step, for each edge you need to consider the cost as weight to minimize the total cost. If the
   graph is disconnected the algorithm should provide minimum spanning forest consisting of a
   minimum spanning tree for each connected component.

### Dataset
The dataset, named "airports.csv," consists of four columns: Origin_airport, Destination_airport,
Origin_city, Destination_city, Distance and Cost. This dataset is required for implementing all the tasks
mentioned above. The Origin_airport and Destination_airport columns use the abbreviated format for
airport names, such as PIT, ATL, ORD, etc. The Origin_city and Destination_city columns provide the
actual names of the cities and states. The dataset contains 384 entries and includes flight information for
140 different airports.

### Implementation Details
The implementation of the team must be done using any data structures, and you cannot utilize any STL
library (except for the vector class), to implement any data structures. You must implement the project
as a team.

### Sample Test Cases are in the PDF

### Tentative Rubric:

Report 20%\
Presentation 10%\
Implementing graph functionality correctly: 70%