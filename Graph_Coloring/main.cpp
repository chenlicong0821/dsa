#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
/*#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>*/
/*#include <boost/algorithm/string/classification.hpp>*/
#include <algorithm>
#include <unordered_map>

using namespace std;
static void split(const string& s, vector<string>& sv, const char flag = ' ') {
    sv.clear();
    istringstream iss(s);
    string temp;

    while (getline(iss, temp, flag)) {
        sv.push_back(temp);
    }
    return;
}

bool cmp(const pair<int, set<int>>& a, const pair<int, set<int>>& b) {
    return a.second.size() > b.second.size();
}

int main() {
    // Read Graph info
    ifstream infile("./data/gc_4_1");
    if (!infile)
        std::cout << "Error in opening file" << std::endl;

    int node_count;
    int edge_count;
    vector<pair<int, int>> edges;

    string graph_string;
    getline(infile, graph_string);
    vector<string> graph_info;
    // boost::split(graph_info, graph_string, boost::is_any_of(" "));
    split(graph_string, graph_info, ' ');
    node_count = stoi(graph_info[0]);
    edge_count = stoi(graph_info[1]);
    cout << "The graph has " << node_count << " nodes and " << edge_count
         << " edges" << endl;

    string edge_string;
    vector<string> edge_info;
    while (getline(infile, edge_string)) {
        // boost::split(edge_info, edge_string, boost::is_any_of(" "));
        split(edge_string, edge_info, ' ');
        int first_node = stoi(edge_info[0]);
        int second_node = stoi(edge_info[1]);
        edges.push_back(make_pair(first_node, second_node));
        edge_info.clear();
    }

    // build a trivial solution
    // every node has its own color
    vector<int> solution;
    for (int i = 0; i < node_count; i++)
        solution.push_back(i);
    auto color_count = solution.size();

    // the algorithm implementation

    // 统计各个顶点的领接点
    unordered_map<int, set<int>> mapNodeEdges;
    for (auto edge : edges) {
        set<int> s1;
        if (mapNodeEdges.count(edge.first)) {
            s1 = mapNodeEdges[edge.first];
        }
        s1.insert(edge.second);
        mapNodeEdges[edge.first] = s1;
        set<int> s2;
        if (mapNodeEdges.count(edge.second)) {
            s2 = mapNodeEdges[edge.second];
        }
        s2.insert(edge.first);
        mapNodeEdges[edge.second] = s2;
    }
    // 将map中的内容转存到vector中
    vector<pair<int, set<int>>> vecNodeEdges(mapNodeEdges.begin(),
                                             mapNodeEdges.end());
    // 按领接点数量进行排序
    sort(vecNodeEdges.begin(), vecNodeEdges.end(), cmp);
    /* for (auto node : vecNodeEdges) {
        cout << node.first << ' ';
        for (auto i : node.second)
            cout << i << ' ';
        cout << endl;
    } */
    int color_index = 0;
    while (mapNodeEdges.size() > 0) {
        set<int> c;
        // 从邻接点数量最多的接点开始变量
        for (auto node : vecNodeEdges) {
            // 试图给node的各个领接点node2着色color_index
            for (auto node2 : node.second) {
                // 该node2尚未找色，并且其各个邻接点node3也为着色为color_index，则node2可以着色为color_index
                if (mapNodeEdges.count(node2)) {
                    bool canColor = true;
                    for (auto node3 : mapNodeEdges[node2]) {
                        if (c.count(node3)) {
                            canColor = false;
                            break;
                        }
                    }
                    if (canColor) {
                        solution[node2] = color_index;
                        c.insert(node2);
                    }
                }
            }
        }
        for (auto node : c) {
            mapNodeEdges.erase(node);
        }
        color_index++;
    }
    color_count = color_index;

    // print the answer
    cout << "Solution below: " << endl;
    cout << color_count << endl;
    for (auto i : solution)
        cout << i << " ";
    cout << endl;

    // testSolution(color_count,solution);
    return 0;
}
