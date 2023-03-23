// Computing Structures Fall 2022
// DSA 5005
// Project 1 boilerplate code
// Aditya Narasimhan

#include <iostream>
#include <string>

using namespace std;

// class node to store one node's details
class Node {
protected:
	int nodeNumber; // field to store node's number
	string nodeInfo; // field to store node's information
public:
	Node(); // default constructor
	// getters
	string getNodeInfo();
	int getNodeNumber();
	// setters
	void setNodeInfo(string newInfo);
	void setNodeNumber(int newNum);

	void display(); // display node details 
};
// Default constructor to initialize the values of nodeNumber and nodeInfo attributes
Node::Node() {
	nodeNumber = -1;
	nodeInfo = "";
}
// This method returns the value of the protected nodeInfo attribute
string Node::getNodeInfo() {
	return nodeInfo;
}
// This method returns the value of the protected nodeNumber attribute
int Node::getNodeNumber() {
	return nodeNumber;
}
//This method takes a parameter newInfo and assigns it to the nodeInfo attribute
void Node::setNodeInfo(string newInfo) {
	nodeInfo = newInfo;
}
//This method takes a parameter newNum and assigns it to the nodeNumber attribute
void Node::setNodeNumber(int newNum) {
	nodeNumber = newNum;
}
//This method is used to display node's number and the node's information
void Node::display() {
	cout << this->getNodeNumber() << ": " << this->getNodeInfo() << endl;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// class to store one edge's details
class Edge {
protected:
	Node* u; // field to store source node pointer
	Node* v; // field to store destination node pointer
	string edgeInfo; // field to store edge information
public:
	Edge(); // default constructor
	// getters 
	Node& getu();
	Node& getv();
	string getEdgeInfo();
	// setters
	void setu(Node* newu);
	void setv(Node* newv);
	void setEdgeInfo(string newInfo);

	void display(); // display edge details
};
// Default constructor to initialize the attributes u,v and edgeInfo
Edge::Edge() {
	Node* u = NULL;
	Node* v = NULL;
	edgeInfo = "";
}
//This method returns the value of the protected edgeInfo attribute
string Edge::getEdgeInfo() {
	return edgeInfo;
}
//This method returns the address of the protected source node u
Node& Edge::getu() {
	return *u;
}
//This methos returns the address of the protected destination node v
Node& Edge::getv() {
	return *v;
}
//This method takes a parameter newInfo and assigns it to the edgeInfo attribute
void Edge::setEdgeInfo(string newInfo) {
	edgeInfo = newInfo;
}
//This method takes a parameter newu and assigns it to the u attribute
void Edge::setu(Node* newu) {
	u = newu;
}
//This method takes a parameter newv and assigns it to the v attribute
void Edge::setv(Node* newv) {
	v = newv;
}
//This method is used to display the edge details 
void Edge::display() {
	if ((u != NULL) && (v != NULL)) {
		cout << this->getu().getNodeInfo() << " - " << this->getv().getNodeInfo() << " " << this->edgeInfo << endl;
	}
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// class to store the graph database
class GraphDB {
protected:
	Node* myNodes; // array of nodes 
	Edge* myEdges; // array of edges
	int numNodes; // number of nodes
	int numEdges; // current number of edges
	int maxEdges; // store the max number of edges (array size)
public:
	GraphDB(int nNodes, int mEdges); // non-default constructor
	//setters
	void setNode(Node& newNode);
	void setEdge(Edge& newEdge);
	void setNodeInfo(int u, string newInfo);
	void setEdgeInfo(int u, int v, string newInfo);

	// getters
	Node* getNode(int nodeNum);
	string getNodeInfo(int nodeNum);
	Edge* getEdgeInfo(int u, int v);

	// operations
	bool isAnEdge(int u, int v); // is this edge existent
	void addEdge(Edge& newEdge); // add an edge
	void deleteEdge(int u, int v); // delete/remove the edge
	void display_edges(); // displays edge's details
	void display_nodes(); // displays node's details
};
// Non-Default constructor to initilaize numNodes,maxEdges,myNodes,myEdges,numEdges attributes
GraphDB::GraphDB(int nNodes, int mEdges) {
	numNodes = nNodes;
	maxEdges = mEdges;
	myNodes = new Node[nNodes];
	myEdges = new Edge[mEdges];
	numEdges = 0;
}
//This method takes a parameter newNode and assigns the values of nodeNumber and nodeInfo to the myNodes array
void GraphDB::setNode(Node& newNode) {
	int n = newNode.getNodeNumber(); // Fetching the nodeNumber of newNode and assigning to the variable n
	myNodes[n].setNodeNumber(n); // adding the nodeNumber to the myNodes array at position n
	string x = newNode.getNodeInfo(); // Fetching the nodeInfo of newNode and assigning to the variable x
	myNodes[n].setNodeInfo(x); // adding the nodeInfo to the myNodes array at position n

}
/*This method takes a parameter newEdgeand assigns the address of source node(u), destination node(v)
and EdgeInfo to the myEdges array*/
void GraphDB::setEdge(Edge& newEdge) {
	myEdges[numEdges].setu(&newEdge.getu()); // Setting the address of source node in myEdges array
	myEdges[numEdges].setv(&newEdge.getv()); // Setting the address of destination node in myEdges array
	myEdges[numEdges].setEdgeInfo(newEdge.getEdgeInfo()); // Setting the value of edgeInfo in myEdges array
	numEdges++; // increasing the current number of edges 
}
/*This method takes two parameters u, newInfo and assigns the values of new NodeInfo(newInfo) and
node number u to that particular node u in myNodes array*/
void GraphDB::setNodeInfo(int u, string newInfo) {
	myNodes[u].setNodeNumber(u);
	myNodes[u].setNodeInfo(newInfo);

}
/*This method takes three parameters u, v, newInfo and sets the source node u ,
destination node v and edgeInfo with newInfo in myEdges array*/
void GraphDB::setEdgeInfo(int u, int v, string newInfo) {
	for (int i = 0; i < numNodes; i++) {
		if (myNodes[i].getNodeNumber() == u) { 
			myEdges->setu(&myNodes[i]);
		}
		if (myNodes[i].getNodeNumber() == v) {
			myEdges->setv(&myNodes[i]);
		}
	}
	myEdges->setEdgeInfo(newInfo);
}
/*This method takes a parameter nodeNumand returns the address of that particular node(nodeNum) by
searching in myNodes array*/
Node* GraphDB::getNode(int nodeNum) {
	for (int i = 0; i < numNodes; i++) {
		/*By using for loop, checking the node with nodeNumber nodeNumand returning the address of
		that node in myNodes array*/
		if (myNodes[i].getNodeNumber() == nodeNum) { 
			return &myNodes[i];
		}
	}
}
//This method takes parameters u,v and returns the address of that particular edge by searching in myEdges array
Edge* GraphDB::getEdgeInfo(int u, int v) {
	/*By using for loop, checking the exact index of the given source(u) and destination(v) in
	myEdges array and returning the address of that Edge*/
	for (int i = 0; i < maxEdges; i++) { 
		if (myEdges[i].getu().getNodeNumber() == u && myEdges[i].getv().getNodeNumber() == v) { 
			return &myEdges[i];
		}
	}
}
/*This method takes parameter nodeNumand returns the value of nodeInfo of that particular
node(with nodeNumber as nodeNum) by searching in myNodes array*/
string GraphDB::getNodeInfo(int nodeNum) {
	for (int i = 0; i < numNodes; i++) {
		// By using for loop, checking the node with nodeNumber nodeNum and returning that node information
		if (myNodes[i].getNodeNumber() == nodeNum) { 
			return myNodes[i].getNodeInfo();
		}
	}
}
/*This method takes parameters u, vand returns the boolean value whether the edge with source
node u and destination node v exists or not by checking in myEdges array*/
bool GraphDB::isAnEdge(int u, int v) {
	for (int i = 0; i < numEdges; i++) {
		// By using for loop, checking the exact index of the given source (u) and destination (v) in myEdges array
		if ((myEdges[i].getu().getNodeNumber() == u) && (myEdges[i].getv().getNodeNumber() == v)) { 
			return true;
		}
	}
	return false;

}
//This method takes parameters u,v which is used to delete the particular edge with source node u and destination node v
void GraphDB::deleteEdge(int u, int v) {
	int c = -1;
	for (int i = 0; i < numEdges; i++) {
		// By using for loop, checking the exact index of the given source (u) and destination (v) in myEdges array
		if ((myEdges[i].getu().getNodeNumber() == u) && (myEdges[i].getv().getNodeNumber() == v)) { 
			/*fetching the index of the edge with source node uand destination node vand assigning that value to
			the variable c*/
			c = i; 
			break;
		}
	}
	/*Deleting that particular edge in myEdges array by shifting all the elements after it one position to the
	  left and hence covering up that one vacant spot*/
	for (int j = c; j < numEdges - 1; j++) {
		myEdges[j] = myEdges[j + 1]; 
	}
	if (c != -1) {
		numEdges--; // decreasing the numEdges 
	}

	if (c != -1) { // if the element found and got deleted then it will print this statement
		cout << "Removing " << u << " " << v << endl;
	}
	else { // if the element if not found then it will print this.
		cout << "There is no such Edge exists to remove " << endl;
	}
}
/*This method is used to add the edge.In this method, if the condition numEdges >= maxEdges, then
i increased the size of the myEdges array and adding the newEdge to the myEdges array*/
void GraphDB::addEdge(Edge& newEdge) {
	// checking if the numEdges is less than maxEdges then it will just set the newEdge in to the myEdges array
	if (numEdges < maxEdges) { 
		this->setEdge(newEdge);
	}
	else { 
		/*if numEdges is greater than maxEdges then created a temporary array(temp) of type Edge
		  class with greater size than before*/
		Edge* temp = new Edge[maxEdges + 1]; 
		for (int i = 0; i < maxEdges; i++) {
			temp[i] = myEdges[i]; // assigning all the values in myEdges array to temp array
		}
		delete[] myEdges; // deleting the myEdges array content
		myEdges = temp; // assigning the temp array to myEdges array
		this->setEdge(newEdge); // setting the newEdge to the increased size myEdges array 
		maxEdges++; // increasing the maxEdges
	}

}

//This method is used to display the Edge's details present in myEdges array
void GraphDB::display_edges() {
	for (int i = 0; i < numEdges; i++) {
		this->myEdges[i].display();
	}
}

//This method is used to display the node's details present in myNodes array
void GraphDB::display_nodes() {
	for (int i = 0; i < numNodes; i++) {
		this->myNodes[i].display();
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main()
{
	int numNodes; // temp variable to store numNodes from input
	int maxEdges; // temp variable to store maxEdges from input
	int nodeNum; // temp varaible to store the node number from input
	string nodeLabel; // temp variable to store the node information from input
	char command; // temp variable to store the character(I,E,R) from the input
	int u, v; // temp variable to store the source node number and destination node number from the input
	GraphDB* masterGraph; // pointer object of GraphDB class

	cin >> numNodes >> maxEdges; // read the numNodes and maxEdges from redirected input

	masterGraph = new GraphDB(numNodes, maxEdges); // allocate memory by calling non-default constructor

	// display the values read in
	cout << "numNodes: " << numNodes << endl;
	cout << "maxEdges: " << maxEdges << endl;
	/* In this for loop, we will set the values of node numberand node information taking
	   from the input in to the myNodes array present in GraphDB class. */
	for (int i = 0; i < numNodes; i++) {
		cin >> nodeNum >> nodeLabel;
		Node* temp = new Node();
		temp->setNodeNumber(nodeNum);
		temp->setNodeInfo(nodeLabel);
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
			Edge* temp_edge = new Edge();
			cin >> u >> v >> nodeLabel;
			cout << "Inserting " << u << " " << v << ": " << nodeLabel << endl;

			temp_edge->setu(masterGraph->getNode(u));
			temp_edge->setv(masterGraph->getNode(v));
			temp_edge->setEdgeInfo(nodeLabel);
			masterGraph->addEdge(*temp_edge);
			break;

		}
		/*This switch case is to check whether the edge exists between the specified node numbers
		  taken from input when it has 'E' at the starting of the line in input.*/
		case 'E': {
			cin >> u >> v;
			Node* u_node = masterGraph->getNode(u);
			Node* v_node = masterGraph->getNode(v);
			if (masterGraph->isAnEdge(u, v)) {
				cout << "Edge exists between " << u_node->getNodeInfo() << " and " << v_node->getNodeInfo() << endl;
			}
			else {
				cout << "No edge exists between " << u_node->getNodeInfo() << " and " << v_node->getNodeInfo() << endl;
			}
			break;
		}
		/*This switch case is to delete the specified edge from the input when it has 'R' at the
		  starting of the line in input.*/
		case 'R': {
			cin >> u >> v;
			masterGraph->deleteEdge(u, v);
			break;
		}
		// This switch case is to display the nodes and edges details when it has 'D' at the starting of the line in input.
		case 'D': {
			cout << "Displaying Mynodes:" << endl;
			masterGraph->display_nodes();
			cout << "Displaying myEdges:" << endl;
			masterGraph->display_edges();

			break;
		}
		// This will come in to the picture when the starting line of the input character is other than 'I','E','R','D' 
		default: cout << "Holy Cow!!" << endl;
		}
		cin >> command;
	}


	return 0;
}