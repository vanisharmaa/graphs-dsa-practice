/**
 * Given a reference to a node within an undirected graph, create a deep copy (clone) ~f the
 * graph. The copied graph must be completely independent of the original one. This means
 * you need to make new nodes for the copied graph instead of reusing any nodes from the
 * original graph.
 *
 * Constraints:
 * • The value of each node is unique.
 * • Every node in the graph is reachable from the given node.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/********** GRAPH NODE **********/

class GraphNode
{
public:
    int val;
    vector<GraphNode *> neighbors;

    GraphNode(int v) : val(v) {}
};

/********** GRAPH CLASS **********/

class Graph
{
public:
    int n;
    vector<GraphNode *> nodes;

    Graph(int size) : n(size)
    {
        for (int i = 0; i < n; i++)
        {
            nodes.push_back(new GraphNode(i));
        }
    }

    void addEdge(int u, int v, bool undirected = true)
    {
        nodes[u]->neighbors.push_back(nodes[v]);
        if (undirected)
        {
            nodes[v]->neighbors.push_back(nodes[u]);
        }
    }

    void printGraph()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Node " << nodes[i]->val << " -> ";
            for (auto neighbor : nodes[i]->neighbors)
            {
                cout << neighbor->val << " ";
            }
            cout << "\n";
        }
    }
};

/********** DEEP COPY LOGIC **********/

GraphNode *helper(GraphNode *node,
                  unordered_map<GraphNode *, GraphNode *> &mp)
{
    if (!node)
        return nullptr;

    if (mp.count(node))
        return mp[node];

    GraphNode *newNode = new GraphNode(node->val);
    mp[node] = newNode;

    for (auto neighbor : node->neighbors)
    {
        newNode->neighbors.push_back(helper(neighbor, mp));
    }

    return newNode;
}

GraphNode *deepCopy(GraphNode *node)
{
    unordered_map<GraphNode *, GraphNode *> mp;
    return helper(node, mp);
}

/********** PRINT COPIED GRAPH (DFS) **********/

void dfsPrint(GraphNode *node,
              unordered_set<GraphNode *> &visited)
{
    if (!node || visited.count(node))
        return;

    visited.insert(node);

    cout << "Node " << node->val << " -> ";
    for (auto neighbor : node->neighbors)
    {
        cout << neighbor->val << " ";
    }
    cout << "\n";

    for (auto neighbor : node->neighbors)
    {
        dfsPrint(neighbor, visited);
    }
}

void printGraph(GraphNode *node)
{
    unordered_set<GraphNode *> visited;
    dfsPrint(node, visited);
}

/********** MAIN **********/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 5;
    Graph g(n);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Original Graph Address:" << g.nodes[0] << endl;
    g.printGraph();

    GraphNode *copiedRoot = deepCopy(g.nodes[0]);

    cout << "\nCloned Graph Address: " << copiedRoot << endl;
    printGraph(copiedRoot);

    return 0;
}