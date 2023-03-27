// Exam1Scratchpad.cpp : This file contains the 'main' function. Program execution begins and ends there.
/* referenced:
* https://www.geeksforgeeks.org/vector-in-cpp-stl/
* https://stackoverflow.com/questions/571394/how-to-find-out-if-an-item-is-present-in-a-stdvector
* https://www.cplusplus.com/reference/algorithm/find/
*/


#include <iostream>
#include <vector>
#include <algorithm>

typedef int Node;

class AdjListClass {
private:
    std::vector<int> nodeVector; //list of vectors
    std::vector<std::vector<int>> edgeVector; //list of connecting points
public:
    AdjListClass() {
    }
    ~AdjListClass() {}

    //accessors
    bool plot(std::vector<int>& x) {
        int jumps = x.size();
        bool present = false;
        for (int i = 0; i < x.size() - 1; i++) { // for each position in x
            present = (std::find(edgeVector.at(x[i]).begin(), edgeVector.at(x[i]).end(), x[i + 1]) != edgeVector.at(x[i]).end());
            if (!present) {return false;} //if we haven't found the edge, the chain is broken
            
        }
        return true; //if we don't trip false before now, the path isn't there
    }
    //mutators
    void addEdge(int x, int y) {
        //if no matching edge found
        if (std::find(edgeVector.at(x).begin(), edgeVector.at(x).end(), y) != edgeVector.at(x).end()) {
            (edgeVector.at(x)).push_back(y); //add edge
        }
    }

    void deleteEdge(int x, int y) {
        std::remove(edgeVector.at(x).begin(), edgeVector.at(x).end(), y);
    }
    void addNode(Node x) {

        nodeVector.insert(nodeVector.end(), x);
        //resize edgeVector to match
        edgeVector.resize(nodeVector.size());
    }
    void deleteNode(Node x) {
        //delete all occurances of links to this node
        for (int i = 0; i < nodeVector.size(); i++) {
            std::remove(edgeVector.at(i).begin(), edgeVector.at(i).end(), x);
        }
        //then remove node
        std::remove(nodeVector.begin(), nodeVector.end(), x);
    }
};

int main()
{
    std::cout << "Hello World!\n";
    AdjListClass Graph;
    std::vector<int> route = { 0,1,2,3 };
    for (int i = 0; i < 5; i++) {
        Graph.addNode(i);
    }
    Graph.addEdge(0, 1);
    Graph.addEdge(1, 2);
    Graph.addEdge(2, 3);
    Graph.addEdge(0, 2);
    Graph.addEdge(0, 1);
    Graph.addEdge(2, 1);
    Graph.addEdge(4, 2);
    Graph.addEdge(3, 4);

    std::cout << "Pathway 1,2,3,4: ";
    std::cout << Graph.plot(route);

    Graph.deleteEdge(0, 2);

    Graph.deleteNode(1);

    std::cout << "test" << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
