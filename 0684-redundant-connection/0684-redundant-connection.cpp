class DisjointDS{
public:
  vector<int> parent; // Stores the parent of ith node
  vector<int> rank; //Stores the rank of ith node
  
  DisjointDS(int n){ //n is the number of nodes in the graph
    parent.resize(n + 1); 
    rank.resize(n + 1);  
    rank.clear(); //Initialize the rank of every node as 0
    
    for(int i = 0; i < n+1; i++){ //Inititalize the parent of node i as i itself. Meaning they are a set on their own
      parent[i] = i;
    }
  }
  
  bool Union(int u, int v){ //Union by Rank . Returns TRUE if UNION can be performed without introducing any cycle
    //Get the representatives of the vertices
    int ru = Find(u);
    int rv = Find(v);
  
    //an edge between them will create a loop since they both belong to the same set/component
    if(ru == rv) return false; 
    
    if(rank[ru] > rank[rv]){
      parent[rv] = parent[ru];
    }else if (rank[rv] > rank[ru]){
      parent[ru] = parent[rv];
    }else{
      parent[rv] = parent[ru];
      rank[ru]++;
    }
    return true;
  }
  
  int Find(int node){ //Returns the representative of this node
    if(parent[node] == node) return node; //If i am my own parent/rep
    //Find with Path compression, meaning we update the parent for this node once recursion returns
    parent[node] = Find(parent[node]); 
    return parent[node];
  }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      int numOfNodes =  edges.size();
      DisjointDS dds(numOfNodes);
      
      for(auto& edge: edges){
        int u = edge[0];
        int v = edge[1];
        
        if(dds.Union(u, v) == false) return {u, v}; // If we cannot unionize these 2 edges, means they must beling to the same
        //connected component, hence adding them will create a cycle. so we found our Redundant Edge
      }
      
      return {-1, -1};
    }
};