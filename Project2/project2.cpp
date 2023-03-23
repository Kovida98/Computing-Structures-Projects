// Computing Structures Fall 2022
// DSA 5005
// Aditya Narasimhan

#include <iostream>
#include <string>

using namespace std;

// class node to store one node's details
template <class DT>
class Node
{
protected:
    int nodeNumber;  // field to store node's number
    string nodeInfo; // field to store node's information
    DT yearCreated;  // field to store the year of the node created
    string location; // field to store the location

public:
    Node(); // default constructor

    // getters
    string getNodeInfo();
    int getNodeNumber();
    DT getYearCreated();
    string getLocation();

    // setters
    void setNodeInfo(string newInfo, DT newYearCreated, string newLoc); // V2: updated
    void setNodeNumber(int newNum);
    void setYearCreated(DT newYearCreated);
    void setLocation(string newLocation);

    void display(); // display node details

    ~Node(); // destructor
};

// Default constructor to initialize the values of nodeNumber,nodeInfo,yearCreated,location attributes
template <class DT>
Node<DT>::Node() {
    nodeNumber = -1;
    nodeInfo = "";
    yearCreated =  0 ;
    location = "";
}

// Destructor to destroy nodeNumber,nodeInfo,yearCreated,location attributes
template <class DT>
Node<DT>::~Node() {
    nodeNumber = -1;
    nodeInfo = "";
    yearCreated = 0;
    location = "";
}

// This method returns the value of the protected nodeInfo attribute
template <class DT>
string Node<DT>::getNodeInfo() {
    return nodeInfo;
}

// This method returns the value of the protected nodeNumber attribute
template <class DT>
int Node<DT>::getNodeNumber() {
    return nodeNumber;
}

// This method returns the value of protected yearCreated attribute
template <class DT>
DT Node<DT>::getYearCreated() {
    return yearCreated;
}

// This method returns the value of protected location attribute
template <class DT>
string Node<DT>::getLocation() {
    return location;
}

/*This method takes a parameters newInfo, newYearCreated, newLoc
and assigns it to the nodeInfo,yearCreated,location attributes respectively.*/
template <class DT> void
Node<DT>::setNodeInfo(string newInfo, DT newYearCreated, string newLoc) {
    nodeInfo = newInfo;
    yearCreated = newYearCreated;
    location = newLoc;   
}

// This method takes a parameter newNum and assigns it to the nodeNumber attribute
template <class DT>
void Node<DT>::setNodeNumber(int newNum) {
    nodeNumber = newNum;
    
}

// This method takes a parameter newYearCreated and assigns it to yearCreated attribute
template <class DT>
void Node<DT>::setYearCreated(DT newYearCreated) {
    yearCreated = newYearCreated;
}

// This method takes a parameter newLocation and assigns it to location attribute
template <class DT>
void Node<DT>::setLocation(string newLocation) {
    location = newLocation;
}

//This method is used to display the node's information
template <class DT> void Node<DT>::display() {
    cout << this->getNodeNumber() << ": " << this->getNodeInfo() << ", " << this->getYearCreated() << ", " << this->getLocation() << endl;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// class to store one edge's details
template <class DT>
class Edge
{
protected:
    Node<DT>* u;     // field to store source node pointer
    Node<DT>* v;     // field to store destination node pointer
    string edgeInfo; // field to store edge information
    DT yearsKnown;   // u and v - years known

public:
    Edge(); // default constructor
    // getters
    Node<DT>* getu();
    Node<DT>* getv();
    string getEdgeInfo();
    DT getYearsKnown();

    // setters
    void setu(Node<DT>* newu);
    void setv(Node<DT>* newv);
    void setEdgeInfo(string newInfo, DT newYearsKnown); // V2: updated
    void setYearsKnown(DT newYear);                     // V2: updated

    void display(); // display edge details

    ~Edge(); // destructor
};

// Default constructor to initialize the attributes u,v and edgeInfo,yearsKnown
template <class DT>
Edge<DT>::Edge() {
    u = NULL;
    v = NULL;
    yearsKnown = 0;
    edgeInfo = "";
}

// Destructor to destroy u,v,edgeInfo,yearsKnown attributes
template <class DT>
Edge<DT>::~Edge() {
    delete u;
    delete v;
    edgeInfo = "";
    yearsKnown = 0;
}

// This method returns the protected source node u
template <class DT>
Node<DT>* Edge<DT>::getu() {
    return u;
}

//This methos returns the protected destination node v
template <class DT>
Node<DT>* Edge<DT>::getv() {
    return v;
}

//This method returns the value of the protected edgeInfo attribute
template <class DT>
string Edge<DT>::getEdgeInfo() {
    return edgeInfo;
}

// This method returns the value of the protected yearsKnown attribute
template <class DT>
DT Edge<DT>::getYearsKnown() {
    return yearsKnown;
}

// This method takes a parameter newu and assigns it to the u attribute
template <class DT>
void Edge<DT>::setu(Node<DT>* newu) {
    u = newu;
}

// This method takes a parameter newv and assigns it to the v attribute
template <class DT>
void Edge<DT>::setv(Node<DT>* newv) {
    v = newv;
}

/*This method takes parameters newInfo, newYearsKnown
and assigns it to edgeInfo,yearsKnown attributes respectively.*/
template <class DT>
void Edge<DT>::setEdgeInfo(string newInfo, DT newYearsKnown) {
    edgeInfo = newInfo;
    yearsKnown = newYearsKnown;
}

// This method takes a parameter newYear and assigns it to yearsKnown attribute
template <class DT>
void Edge<DT>::setYearsKnown(DT newYear) {
    yearsKnown = newYear;
}

//This method is used to display the edge's details 
template <class DT>
void Edge<DT>::display() {
    cout << this->getu()->getNodeInfo() << " - " << this->getv()->getNodeInfo() << " " << this->edgeInfo << ", " << this->getYearsKnown() << endl;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// This class is to handle the exception when we try to add the edge with non-existing node 
class myNonExistingNodeException {

};
// class to store the graph
template <class DT>
class GraphDB
{
    friend ostream& operator<< (ostream& s, const GraphDB<int>& GB);
    // TODO: ostream operator for displaying myNodes and myEdges
protected:
    Node<DT>* myNodes; // array of nodes
    Edge<DT>* myEdges; // array of edges
    int numNodes;      // number of nodes
    int numEdges;      // number of edges
    int maxEdges;      // store the max number of edges (array size)
    
public:
    GraphDB(int nNodes, int nEdges); // non-default constructor
    //friend ostream& operator<< (ostream& s,  const GraphDB<int>& GB);
    // setters
    void setNode(Node<DT>& newNode);
    void setEdge(Edge<DT>& newEdge);
    void setNodeInfo(int u, string newInfo);
    void setEdgeInfo(int u, int v, string newInfo);

    // getters
    Node<DT>* getNode(int nodeNum);
    string getNodeInfo(int nodeNum);
    Edge<DT>* getEdgeInfo(int u, int v);

    // operations
    bool isAnEdge(int u, int v);     // is this edge existent
    void addEdge(Edge<DT>& newEdge); // add an edge
    void deleteEdge(int u, int v);   // delete the edge
    void display();                  // display the contents of the two arrays
    int* findNeighbours(int u);      // returns an integer array of neighbours' nodeNum

    ~GraphDB(); // destructor
    // This method is developed to display node's and edge's details which is instead of display method in GraphDB class.
    friend std::ostream& operator<< (std::ostream& s, GraphDB<int>& GB) {        
        GB.display(); // calls the display function to display the node's and edge's details
        return s;
    }
    
};

// Non-Default constructor to initilaize numNodes,maxEdges,myNodes,myEdges,numEdges attributes
template<class DT>
GraphDB<DT>::GraphDB(int nNodes, int nEdges) {
    numNodes = nNodes;
    maxEdges = nEdges;
    myNodes = new Node<DT>[numNodes];
    myEdges = new Edge<DT>[maxEdges];
    numEdges = 0;
}

// Destructor to destroy numNodes,maxEdges,myNodes,myEdges,numEdges attributes
template<class DT>
GraphDB<DT>::~GraphDB() {
    delete[] myNodes;
    delete[] myEdges;
    numEdges = 0;
    numNodes = -1;
    maxEdges = 0;
}

/*This method takes a parameter newNodeand assigns the values of nodeNumber,
nodeInfo,yearCreated,location to the myNodes array*/
template <class DT>
void GraphDB<DT>::setNode(Node<DT>& newNode) {
    int n = newNode.getNodeNumber(); // Fetching the nodeNumber of newNode and assigning to the variable n
    myNodes[n].setNodeNumber(n); // adding the nodeNumber to the myNodes array at position n
    string x = newNode.getNodeInfo(); // Fetching the nodeInfo of newNode and assigning to the variable x
    // adding the nodeInfo,yearCreated,location to the myNodes array at position n
    myNodes[n].setNodeInfo(x,newNode.getYearCreated(),newNode.getLocation());
}

/*This method takes a parameter newEdge and assigns the source node(u), destination node(v)
and EdgeInfo,yearsKnown to the myEdges array*/
template<class DT>
void GraphDB<DT>::setEdge(Edge<DT>& newEdge) {
        myEdges[numEdges].setu(newEdge.getu()); // Setting the source node in myEdges array
        myEdges[numEdges].setv(newEdge.getv()); // Setting the destination node in myEdges array
        // Setting the value of edgeInfo,yearsKnown in myEdges array
        myEdges[numEdges].setEdgeInfo(newEdge.getEdgeInfo(), newEdge.getYearsKnown());
        numEdges++; // increasing the current number of edges 
}

/*This method takes the parameters u, newInfo.This is used to change the NodeInfo to newInfo
for a particular node u. */
template<class DT>
void GraphDB<DT>::setNodeInfo(int u, string newInfo) {
    for (int i = 0; i < numNodes; i++) {
        if (myNodes[i].getNodeNumber() == u) {
            myNodes[i].setNodeInfo(newInfo);
        }
    }
}

/*This method takes the parameters u, v, newInfo which is used to change the edgeInfo to newInfo
for particular edge which has u and v as source and destination nodes.*/
template<class DT>
void GraphDB<DT>::setEdgeInfo(int u, int v, string newInfo) {
    for (int i = 0; i < maxEdges; i++) {
        if (myEdges[i].getu()->getNodeNumber() == u && myEdges[i].getv()->getNodeNumber() == v) {
            myEdges[i].setEdgeInfo(newInfo, myEdges[i].getYearsKnown());
        }
    }
}

/*This method takes a parameter nodeNum and returns the address of that particular node(nodeNum) by
searching in myNodes array. Here i am handling the exception when we try to add the edge which has
non-existing nodes*/
template<class DT>
Node<DT>* GraphDB<DT>::getNode(int nodeNum) {
    try
    {
        if (nodeNum < numNodes) {
            /*By using for loop, checking the node with nodeNumber nodeNum and returning the address of
            that node in myNodes array*/
            for (int i = 0; i < numNodes; i++) {
                if (myNodes[i].getNodeNumber() == nodeNum) {
                    return &myNodes[i];
                }
            }
        }
        else {
            // if it is not able to fetch the node from myNodes array, it will throw an exception
            throw myNonExistingNodeException();
        }
        
    }
    // If it throws exception, it catches it and prints the desire output
    catch (myNonExistingNodeException myException)
    {
        cout << "Node not a part of the graph";
    }
    cout << endl;   
}

/*This method takes parameter nodeNum and returns the value of nodeInfo of that particular
node(with nodeNumber as nodeNum) by searching in myNodes array*/
template<class DT>
string GraphDB<DT>::getNodeInfo(int nodeNum) {
    // By using for loop, checking the node with nodeNumber nodeNum and returning that node information
    for (int i = 0; i < numNodes; i++) {
        if (myNodes[i].getNodeNumber() == nodeNum) {
            return myNodes[i].getNodeInfo();
        }
    }
}

//This method takes parameters u,v and returns the address of that particular edge by searching in myEdges array
template<class DT>
Edge<DT>* GraphDB<DT>::getEdgeInfo(int u, int v) {
    /*By using for loop, checking the exact index of the given source(u) and destination(v) in
    myEdges array and returning the address of that Edge*/
    for (int i = 0; i < maxEdges; i++) {
        if (myEdges[i].getu().getNodeNumber() == u && myEdges[i].getv().getNodeNumber() == v) {
            return &myEdges[i].getEdgeInfo();
        }
    }
}

/*This method is used to add the edge.In this method, if the condition numEdges >= maxEdges, then
i increased the size of the myEdges array and adding the newEdge to the myEdges array*/
template<class DT>
void GraphDB<DT>::addEdge(Edge<DT>& newEdge) {
    if ((newEdge.getu()->getNodeNumber() >= 0 && newEdge.getu()->getNodeNumber()<numNodes)&& (newEdge.getv()->getNodeNumber() >= 0 && newEdge.getv()->getNodeNumber() < numNodes)) {
        /*if numEdges is greater than maxEdges then created a temporary array(temp) of type Edge
        class with greater size than before.*/
        if (numEdges >= maxEdges) {
            Edge<DT>* temp = new Edge<DT>[maxEdges + (maxEdges / 2)];
            for (int i = 0; i < maxEdges; i++) {
                temp[i] = myEdges[i]; // assigning all the values in myEdges array to temp array
            }
            myEdges = temp; // assigning the temp array to myEdges array
            maxEdges = maxEdges + (maxEdges / 2); // increasing the maxEdges
        }
        // calling the setedge method to add the edge to the myEdges array
        this->setEdge(newEdge);
    }
}

/*This method takes parameters u, v and returns the boolean value whether the edge with source
node u and destination node v exists or not by checking in myEdges array*/
template<class DT>
bool GraphDB<DT>::isAnEdge(int u, int v) {
    // By using for loop, checking the exact index of the given source (u) and destination (v) in myEdges array
    for (int i = 0; i < numEdges; i++) {
        if ((myEdges[i].getu()->getNodeNumber() == u) && (myEdges[i].getv()->getNodeNumber() == v)) {
            return true;
        }
    }
    return false;
}

// This method takes parameter u and returns an array of neighbours of particular node (u)
template<class DT>
int* GraphDB<DT>::findNeighbours(int u) {
    int* adj_array = new int[numNodes]; // created an array of type int to store the neighbours
    int index = 0; // to keep track of index
    for (int i = 0; i < numEdges; i++) {
        // This checks if the given u is present in source node in myEdges array
        if (myEdges[i].getu()->getNodeNumber() == u ) {
            // storing the v value to the array at that index 
            adj_array[index] = myEdges[i].getv()->getNodeNumber();
            index++; // incrementing index value
        }
        // This checks if the given u is present in destination node in myEdges array
        if(myEdges[i].getv()->getNodeNumber() == u ) {
            // storing the u value to the array at that index
            adj_array[index] = myEdges[i].getu()->getNodeNumber();
            index++; // incrementing index value
        }
    }
    // Here i am displaying the neighbours of given u.
    cout << "Neighbours of " << u << ": ";
    for (int i = 0; i < index ; i++) {
        cout << adj_array[i] << " ";  
    }
    cout << endl;
    return adj_array;

}

/*This method takes parameters u, v which is used to delete the particular edge with source node
u and destination node v. If numEdges becomes half of maxEdges, i am reallocating the memory for myEdges
half of the maxEdges. */
template <class DT>
void GraphDB<DT>::deleteEdge(int u, int v) {
    
    //cout << "for one" << endl;
    if (isAnEdge(u, v)) {
        int c = -1;
        // By using for loop, checking the exact index of the given source (u) and destination (v) in myEdges array
        for (int i = 0; i < numEdges; i++) {
            if ((myEdges[i].getu()->getNodeNumber() == u) && (myEdges[i].getv()->getNodeNumber() == v)) {
                /*fetching the index of the edge with source node uand destination node v
                and assigning that value to the variable c*/
                c = i;
                break;
            }
        }
        /*Deleting that particular edge in myEdges array by shifting all the elements after
        it one position to the left and hence covering up that one vacant spot*/
        for (int j = c; j < numEdges - 1; j++) {
            myEdges[j] = myEdges[j + 1];
        }
        if (c != -1) {
            numEdges--; // decreasing the numEdges
        }
        
        /* This checks if numEdges becomes half of maxEdges, i am allocating
        memory for myEdges to make it smaller i.e., to half of the maxEdges */
        if (numEdges < (maxEdges / 2)) {
            
            Edge<DT>* temp1 = new Edge<DT>[(maxEdges / 2)];
            
            for (int i = 0; i < numEdges; i++) {
                temp1[i] = myEdges[i];
            }
            myEdges = temp1;
            
        }
    }  
    // if the edge doesn't exists with u and v, then it prints the desired output
    else { 
        cout << "Edge does not exist to be deleted " << endl;
    }     
}

//This method is used to display the node's and Edge's details present in myNodes and myEdges array respectively
template<class DT>
void GraphDB<DT>::display() {
    cout << "Displaying myNodes:" << endl;
    for (int i = 0; i < numNodes; i++) {
        cout << myNodes[i].getNodeNumber() << ": " << myNodes[i].getNodeInfo() << ", " << myNodes[i].getYearCreated() << ", " << myNodes[i].getLocation() << endl;
    }
    cout << "Displaying myEdges:" << endl;
    for (int i = 0; i < numEdges; i++) {
        cout << myEdges[i].getu()->getNodeInfo() << " - " << myEdges[i].getv()->getNodeInfo() << " " << myEdges[i].getEdgeInfo() << ", " << myEdges[i].getYearsKnown() << endl;
    }
    
}




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main()
{
    int numNodes;  // temp variable to store numNodes from input
    int maxEdges;  // temp variable to store maxEdges from input
    int nodeNum;   // temp varaible to store the node number from input
    string nodeLabel, edgeLabel;  // temp variable to store the node and edge information from input
    int year;  // temp variable to store yearCreated from input
    string loc;  // temp variable to store location from input
    char command;  // temp variable to store the character(I,E,R,N,D) from the input
    cin >> numNodes >> maxEdges; // read the numNodes and maxEdges from redirected input
    int u, v, years;  // temp variable to store the source node number and destination node number,yearsKnown from the input
    // display the values read in
    cout << "numNodes: " << numNodes << endl;
    cout << "maxEdges: " << maxEdges << endl;
    GraphDB<int>* masterGraph; // pointer object of GraphDB class
    masterGraph = new GraphDB<int>(numNodes, maxEdges); // allocate memory by calling non-default constructor
    /* In this for loop, we will set the values of node number,node information,yearCreated,
    location taking from the input in to the myNodes array present in GraphDB class. */
    for (int i = 0; i < numNodes; i++) {
        cin >> nodeNum >> nodeLabel >> year >> loc;
        //cout << nodeNum << nodeLabel << year << loc << endl;
        Node<int>* temp = new Node<int>();
        temp->setNodeNumber(nodeNum);
        temp->setNodeInfo(nodeLabel, year, loc);
        masterGraph->setNode(*temp);

    }
    // This will take the character at the starting of all the lines from the given input.
    cin >> command;
    // This while loop ends when it reaches the end of the input file.
    while (!cin.eof()) {
        switch (command) {
        /*This switch case is for inserting the edges when it has 'I' at the starting of the line.
        Here it will take the values of u and v from input file.
        We will set those u and v by calling the setter methods of edge class and
        we will add the edge by calling addEdge method in GraphDB class.*/
        case 'I': {
            Edge<int>* temp_edge = new Edge<int>();
            cin >> u >> v >> edgeLabel >> years;
            cout << "Inserting " << u << " " << v << ": " << edgeLabel << ", " << years << endl;
            temp_edge->setu(masterGraph->getNode(u));      
            temp_edge->setv(masterGraph->getNode(v));
            temp_edge->setEdgeInfo(edgeLabel, years);
            masterGraph->addEdge(*temp_edge);   
            break;
        }
        /*This switch case is to check whether the edge exists between the specified node numbers
        taken from input when it has 'E' at the starting of the line in input.*/
        case 'E': {
            cin >> u >> v;
            Node<int>* u_node = masterGraph->getNode(u);
            Node<int>* v_node = masterGraph->getNode(v);
            if (masterGraph->isAnEdge(u, v)) {
                cout << "Edge exists between " << u_node->getNodeInfo() << " and " << v_node->getNodeInfo() << endl;
            }
            else {
                cout << "No edge exists between " << u_node->getNodeInfo() << " and " << v_node->getNodeInfo() << endl;
            }
            break;

        }
        /* This switch case is to fetch the neighbours of the particular node taken from input when it has
        'N' at the starting of the line in input. */
        case 'N': {
            cin >> u;
            int* temp_array = new int[numNodes];
            temp_array = masterGraph->findNeighbours(u);
            break;
        }
        /* This switch case is to display the nodesand edges details when it has
        'D' at the starting of the line in input.*/
        case 'D': {
            cout << *masterGraph << endl;
            break;
        }
        /*This switch case is to delete the specified edge from the input when it has 'R' at the
        starting of the line in input.*/
        case 'R': {
            cin >> u >> v;
            cout << "Removing the item " << u << " " << v << endl;
            masterGraph->deleteEdge(u, v);
            break;
        }
        /* This will come in to the picture when the starting line of the input character
        is other than 'I','E','R','D','N'*/
        default:cout << "No command to take from input file" << endl;
        }
        cin >> command;

    }
    return 0;
    

}