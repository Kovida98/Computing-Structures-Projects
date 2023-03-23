// Computing Structures Fall 2022
// Project 5

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////
// Class ArrayBTNode
////////////////////////////////////////////////////////////////////////////////////////

template <class DT>
class ArrayBTNode
{
protected:
	// Instance Variables
	DT* _info; // field to store node's information
	int _left; // field to store the left node index
	int _right; // field to store the right node index

public:
	// Constructors and Destructor
	ArrayBTNode(); // default constructor
	ArrayBTNode(DT& info); // non-default constructor
	~ArrayBTNode(); // destructor

	// getter Methods
	DT* getinfo(); // to get info of the node
	int getleft(); // to get the left index of the node
	int getright(); // to get the right index of the node

	// setter Methods
	void setInfo(DT& info); // to set the value of info
	void setInfoNull(); // Sets _info to Null
	void setLeft(int left); // to set the left index 
	void setRight(int right); // to set the right index

	// Display Method
	// Outputs data in _info, _left, _right
	void display();

	// Overloaded Comparison Operators
	// Used for comparing _info field with other ArrayBTNodes
	// Used for comparing _info field is less than the ArrayBTNodes
	bool operator<(const ArrayBTNode<DT>& x) {
		if (*_info < *x._info) {
			return true;
		}
		else {
			return false;
		}
	}
	// Used for comparing _info field is greater than the ArrayBTNodes	
	bool operator>(const ArrayBTNode<DT>& x) {
		if (*_info > *x._info) {
			return true;
		}
		else {
			return false;
		}
	}
	// Used for comparing _info field is equal to ArrayBTNodes
	bool operator==(const ArrayBTNode<DT>& x) {
		if (*_info == *x._info) {
			return true;
		}
		else {
			return false;
		}
	}
	// Used for comparing _info field is greater than or equal to ArrayBTNodes
	bool operator>=(const ArrayBTNode<DT>& x) {
		if (*_info >= *x._info) {
			return true;
		}
		else {
			return false;
		}
	}
	// Used for comparing _info field is less than or equal to ArrayBTNodes
	bool operator<=(const ArrayBTNode<DT>& x) {
		if (*_info <= *x._info) {
			return true;
		}
		else {
			return false;
		}
	}
	// Used for comparing _info field is not equal to ArrayBTNodes
	bool operator!=(const ArrayBTNode<DT>& x) {
		if (*_info != *x._info) {
			return true;
		}
		else {
			return false;
		}
	}
	// TODO: Overloaded Ostream Operator - Uses display method to output ArrayBTNode contents
	friend ostream& operator<< (ostream& s, ArrayBTNode<int>& ABTN) {
		ABTN.display();
		return s;
	}	
};

// Default constructor to initialize the values of _info,_left,_right attributes
template<class DT>
ArrayBTNode<DT>::ArrayBTNode() {
	_info = NULL;
	_left = -1;
	_right = -1;
}

// Non-Default constructor to initialize the values of _info,_left,_right attributes
template<class DT>
ArrayBTNode<DT>::ArrayBTNode(DT& info) {
	_info = new DT(info);
	_left = -1;
	_right = -1;
}

// Destructor to destroy _info,_left,_right attributes
template<class DT>
ArrayBTNode<DT>::~ArrayBTNode() {
	delete _info;
	_left = -1;
	_right = -1;
}

// This method returns the value of the protected _info attribute
template<class DT>
DT* ArrayBTNode<DT>::getinfo() {
	return _info;
}

// This method returns the value of the protected _left attribute
template<class DT>
int ArrayBTNode<DT>::getleft() {
	return _left;
}

// This method returns the value of the protected _right attribute
template<class DT>
int ArrayBTNode<DT>::getright() {
	return _right;
}

// This method takes a parameter info and assigns it to the _info attribute
template<class DT>
void ArrayBTNode<DT>::setInfo(DT& info) {
	_info = new DT(info);
}

// This method is used to set _info attribute to null 
template<class DT>
void ArrayBTNode<DT>::setInfoNull() {
	_info = NULL;
}

// This method takes a parameter left and assigns it to the _left attribute
template<class DT>
void ArrayBTNode<DT>::setLeft(int left) {
	_left = left;
}

// This method takes a parameter right and assigns it to the _right attribute
template<class DT>
void ArrayBTNode<DT>::setRight(int right) {
	_right = right;
}

//This method is used to display the node info and their left and right indexes
template<class DT>
void ArrayBTNode<DT>::display() {
	cout << this->getinfo() << this->getleft() << this->getright() << endl;
}


////////////////////////////////////////////////////////////////////////////////////////
// Class ArrayBST
////////////////////////////////////////////////////////////////////////////////////////

template <class DT>
class ArrayBST
{
protected:
	// Instance Variables
	vector<ArrayBTNode<DT> > _tree;    // Vector of ArrayBTNodes used to create a tree
	int _rootIndex;            // Index of the root node in _tree
	int _numNodes;             // Number of nodes in the tree
	int _size;                 // Maximum size of the _tree array
	stack<int> _freeLocations; // Stack containing indexes of freeLocations in the _tree array

public:
	// Constructors and Destructor
	ArrayBST();
	ArrayBST(int k); // initialize the vector with NULL nodes and fill the stack
	~ArrayBST();
	// Accessor Methods
	bool isEmpty(); // fnding whether the tree is empty or not
	int Height(); // to find height of the tree
	int Size(); // to find the size of the tree
	int rootIndex(); // to find the rootIndex of the tree
	int maxSize(); // to find the maximum size of the tree
	int findingheight(int index); // to find the height of the tree by passing index

	// Mutator Methods
	void setData(int index, DT& value); // to set the info of the node
	void setLeft(int index, int value); // to set the left index of the node
	void setRight(int index, int value); // to set the right index of the node
	//int createNode(DT object); // 

	// Display methods and traversals
	void display(ostream& os) ; // Used to display the preorder and inorder
	void displayPreOrder(ostream& os)  ; // Used to display preorder traversal of a tree
	void displayInOrder(ostream& os); // used to display inorder traversal of a tree
	void printRaw(); // Display the array and all of its contents
	void preorder(int index); // helper method used to find the preorder traversal
	void inorder(int index); // Helper method used to find the inorder traversal
	bool search(DT object, int index); // Helper method used to find the element in the tree 

	// BST Specific Methods
	void insert(DT& object); // Used to insert the node into the tree
	void Addnode(DT object, int root); // Used to add node into the tree
	bool find(DT& object); // used to find the element in the tree
	int findIndex(DT& object); // used to find the index of the element in _tree vector

	void remove(DT& object); // extra credit
	
	// TODO: Overridden ostream operator for ArrayBST - this will call the pre order and in order methods
	friend ostream& operator<< (ostream& s, ArrayBST<int>& ABST){
		ABST.display(s);
		return s;
	}
	
};

// Default constructor to initialize the values of _rootIndex,_numNodes,_size attributes
template<class DT>
ArrayBST<DT>::ArrayBST() {
	_rootIndex = -1;
	_numNodes = -1;
	_size = -1;

}

// non-default constructor to initialize _tree,_rootIndex,_numNodes,_size,_freeLocations
template<class DT>
ArrayBST<DT>::ArrayBST(int k) {
	// Reserving the size of the _tree to k
	_tree.reserve(k);
	// intializing _rootindex to k-1
	_rootIndex = k - 1;
	// intializing current number of nodes to zero
	_numNodes = 0;
	// initializing the _size attribute to k
	_size = k;
	// Using for loop, pushing the values from zero to k into stack _freeLocations.
	// Pushing k ArrayBTNode NULL objects into _tree vector
	for (int i = 0; i < k; i++) {
		_freeLocations.push(i);
		_tree.push_back(ArrayBTNode<DT>());
	}
}

// Destructor to destroy _freeLocations,_rootIndex,_numNodes,_size attributes
template<class DT>
ArrayBST<DT>::~ArrayBST() {
	for (int i = 0; i < _size; i++) {
		_freeLocations.top();
		_freeLocations.pop();
	}
	_rootIndex = -1;
	_numNodes = -1;
	_size = -1;
}
// This method returns index of root which is stored in _rootIndex attribute
template<class DT>
int ArrayBST<DT>::rootIndex() {
	return _rootIndex;
}
// This method returns the current size of the _tree attribute
template<class DT>
int ArrayBST<DT>::Size() {
	return _tree.size();
}
// This method returns the maximum size of the _tree attribute
template<class DT>
int ArrayBST<DT>::maxSize() {
	return _size;
}
// this method checks whether the _tree is empty or not and returns the status
template<class DT>
bool ArrayBST<DT>::isEmpty() {
	return _tree.empty();
}
// This method takes the parameter index and is used to find the height of the tree 
template<class DT>
int ArrayBST<DT>::findingheight(int index) {
	// intialising h to zero
	int h = 0;
	// if index is not equal to -1
	if (index != -1) {
		// finding the height of left subtree
		int leftheight = findingheight(_tree[index].getleft());
		// finding the height of right subtree
		int rightheight = findingheight(_tree[index].getright());
		// finding the maximum of the left and right subtree height
		int maxheight = max(leftheight, rightheight);
		// adding plus one to the max height
		h = maxheight + 1;
	}
	return h;
}

// This method is used to find the height of the tree
template<class DT>
int ArrayBST<DT>::Height() {
	// calling findingheight() method by passing _rootIndex value
	int height=findingheight(_rootIndex);
	return height;
}
// This method is used to find the index of that element in the _tree vector
template<class DT>
int ArrayBST<DT>::findIndex(DT& object) {
	int ind = find(*(_tree.begin()), *(_tree.end()), object);
	return ind;
}
// This method is used to addnode into the _tree vector
template<class DT>
void ArrayBST<DT>::Addnode(DT object, int root) {
	_tree[root].setInfo(object);
}
/*This method takes parameters indexand value and sets the _info attribute to 
value at that index in _tree vector*/
template<class DT>
void ArrayBST<DT>::setData(int index, DT& value) {
	_tree[index].setInfo(value);

}
/*This method takes parameters index and value and sets the left attribute to
the value at that index in _tree vector*/
template<class DT>
void ArrayBST<DT>::setLeft(int index, int value) {
	_tree[index].setLeft(value);

}
/*This method takes parameters index and value and sets the right attribute to
the value at that index in _tree vector*/
template<class DT>
void ArrayBST<DT>::setRight(int index, int value) {
	_tree[index].setRight(value);
}
/*This method takes a parameter object and is used to insert the values in to the _tree vector*/
template<class DT>
void ArrayBST<DT>::insert(DT& object) {
	/*If we are trying to insert the nodes into the _tree more than the maximum 
	_size of the tree then it will print the corresponding output*/
	/* That means checking _size is lesser than or equal to _numNodes*/
	if (_size <= _numNodes) {
		cout << "Cannot insert data, BST Full." << endl;
		return;
	}
	else {
		/* Fetching the free location from the _freeLocations stack by using
		top() method*/
		int emptyind = _freeLocations.top();
		_freeLocations.pop(); // deleting the top most element in the stack
		_numNodes++; // incrementing current number of nodes
		_tree[emptyind].setInfo(object); // setting the value of _info attibute to object by using setInfo method
		// initially assigning the _rootIndex value to this variable
		int currentindex = _rootIndex;
		/*If _rootIndex is not equal to emptyind*/
		if (_rootIndex != emptyind) { 
			/* Here it checks whether the currentindex is less than or equal to _rootIndex*/
			while (currentindex<=_rootIndex) {
				/* Here checking whether the element in currentindex is greater than the object*/
				if (_tree[currentindex] > _tree[emptyind]) {
					/*If the element in the currentindex doesnot have left index 
					then setting the emptyind as the left index to the currentindex element*/
					if (_tree[currentindex].getleft() == -1) {
						_tree[currentindex].setLeft(emptyind);
						break;
					}
					/* If the element in the currentindex have left index then changing the
					currentindex value to the left index of the previous currentindex element*/
					else {
						currentindex = _tree[currentindex].getleft();
					}
				}
				/* Here checking whether the element in currentindex is less than the object*/
				else if (_tree[currentindex] < _tree[emptyind]) {
					/*If the element in the currentindex doesnot have right index
					then setting the emptyind as the right index to the currentindex element*/
					if (_tree[currentindex].getright() == -1) {
						_tree[currentindex].setRight(emptyind);
						break;
					}
					/* If the element in the currentindex have right index then changing the
					currentindex value to the right index of the previous currentindex element*/
					else {
						currentindex = _tree[currentindex].getright();
					}
				}
			}
		}
	}
}

/* This method takes the paramater index and is used to fetch the preorder of the _tree*/
template<class DT>
void ArrayBST<DT>::preorder(int index) {
	// Printing the element at that index by fetching it from _tree vector
	cout << *(_tree[index].getinfo()) << " ";
	/* If the left of that element at that particular index is not equal to -1*/
	if (_tree[index].getleft() != -1) {
		/* Then calling the preorder() method recursively by passing the left of that element at index*/
		preorder(_tree[index].getleft());
	}
	/* If the right of that element at that particular index is not equal to -1*/
	if(_tree[index].getright()!=-1){
		/* Then calling the preorder() method recursively by passing the right of that element at index*/
		preorder(_tree[index].getright());
	}
}

/* This method takes the paramater index and is used to fetch the inorder of the _tree*/
template<class DT>
void ArrayBST<DT>::inorder(int index) {
	/* If the left of that element at that particular index is not equal to -1*/
	if (_tree[index].getleft() != -1) {
		/* Then calling the inorder() method recursively by passing the left of that element at index*/
		inorder(_tree[index].getleft());
	}
	// Printing the element at that index by fetching it from _tree vector
	cout << *(_tree[index].getinfo()) << " ";
	/* If the right of that element at that particular index is not equal to -1*/
	if (_tree[index].getright() != -1) {
		/* Then calling the inorder() method recursively by passing the right of that element at index*/
		inorder(_tree[index].getright());
	}
	
}

/* This method is used to print the raw data of _tree vector */
template<class DT>
void ArrayBST<DT>::printRaw() {
	// fetching the size of _freeLocations stack and storing in the varibale free
	int free = _freeLocations.size();
	/*Starting the for loop from free till _rootindex, Printing the 
	raw data like info,left and right index of elements in _tree vector*/
	for (int i = free; i <= _rootIndex; i++) {
			cout << "Index " << i << ": " << "Info: " << *(_tree[i].getinfo()) << ", " << "Left: " << _tree[i].getleft() << "," << "Right: " << _tree[i].getright() << endl;
	
	}
	/*Here printing the free indexes present in _freeLocations stack*/
	cout << "Free Indexes: " << endl;
	// If the elements in the _freeLocations is not empty then
	if(!_freeLocations.empty()){
		// copying the values of _freelocations stack to another stack names free2
		stack<int> free2(_freeLocations);
		// Printing the values in the stack free2 by using while loop
		while (!free2.empty()) {
			cout << free2.top() << ", ";
			free2.pop();
			if (free2.size() == 1) {
				cout << free2.top();
				free2.pop();
			}
		}
	}
	// if there are no elements in the _freeLocations then it prints None
	else {
		cout << "None" << endl;
	}
	
	
	
}

/*This method takes the parameters object, index and is used to search the particular object in _tree vector*/
template<class DT>
bool ArrayBST<DT>::search(DT object, int index) {
	/*If the element at that particular index is equal to the given object 
	then it prints the corresponding output*/
	if (*(_tree[index].getinfo()) == object) {
		cout << "Number found at index " << index << "." << endl;
		return true;
	}
	/*If the object is greater than the value of the element at that particular index*/
	if (object > *(_tree[index].getinfo())) {
		/* If the element at that index has right index and is not equal to -1 */
		if (_tree[index].getright() != -1) {
			/*calling the search method by passing the object and right index of that element*/
			return search(object, _tree[index].getright());
		}
		/* else return false*/
		return false;
		
	}
	/*If the object is lesser than the value of the element at that particular index*/
	else if (object < *(_tree[index].getinfo())) {
		/* If the element at that index has left index and is not equal to -1 */
		if (_tree[index].getleft() != -1) {
			/*calling the search method by passing the object and left index of that element*/
			return search(object, _tree[index].getleft());
		}
		/* else return false*/
		return false;
		
	}
}

/* This method takes the parameter object and is used to find the element*/
template<class DT>
bool ArrayBST<DT>::find(DT& object) {
	// calls the search() method by using object and the _rootIndex values
	return search(object, _rootIndex);
}

/* This method is used to display the preorder and Inorder */
template<class DT>
void ArrayBST<DT>::display(ostream& os)  {
	cout << "Information in Tree:" << endl;
	cout << "Pre Order Traversal: " << endl;
	// calling displayPreorder() method
	displayPreOrder(os);
	cout << endl;
	cout << "In Order Traversal: " << endl;
	// calling displayInorder() method
	displayInOrder(os);

}

/*This method is used to call the preorder() method*/
template<class DT>
void ArrayBST<DT>::displayPreOrder(ostream& os)  {	
	// calling preorder() method by passing _rootIndex value
	preorder(_rootIndex);

}

/* this method is used to call the inorder() method*/
template<class DT>
void ArrayBST<DT>::displayInOrder(ostream& os) {
	// calling inorder() method by passing _rootIndex value
	inorder(_rootIndex);
}

////////////////////////////////////////////////////////////////////////////////////////
// Main Method
////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	// Get input for the size of the tree
	int inputSize; // temp variable to store inputSize from input
	int number; // temp variable to store the int values from redirected input
	cin >> inputSize; // fetching the inputSize value from input
	cout << "Number of maximum nodes: " << inputSize << endl; 
	char command; //  temp variable to store the char values from redirected input


	// Create a BST of the size inputSize
	ArrayBST<int> myBST = ArrayBST<int>(inputSize);
	// This will take the character at the starting of all the lines from the given input.
	cin >> command;
	// This while loop ends when it reaches the end of the input file.
	while (!cin.eof()) {
		switch (command) {
		/* This switch case is for inserting the values into the _tree by taking the int values from
		the redirected input when it has 'I' at the starting of the line.*/
		case 'I': {
			// taking the value from input 
			cin >> number;
			//cout << inputSize << endl;
			cout << "Inserting " << number << endl;
			// calling the insert method in the ArrayBST class by passing the number taken from input
			myBST.insert(number);
			//cout << "finish" << endl;
			break;

		}
		/* This method is used to print the preorder and inorder traversals of the tree
		when it has 'O' at the starting of the line*/
		case 'O': {
			cout << myBST << endl;
			/*
			cout << "Information in Tree :" << endl;
			cout << "Pre Order Traversal: " << endl;
			myBST.preorder(inputSize-1);
			cout << endl;
			cout << "In Order Traversal: " << endl;
			myBST.inorder(inputSize-1);
			cout << endl;*/
			break;

		}
		/* This method is used to print the raw data of the tree when it has 'A' at the 
		starting of the input line */
		case 'A': {
			cout << "Raw Data: " << endl;
			// calling printRaw() method 
			myBST.printRaw();
			cout << endl;
			break;
		}
		/* this method is used to find the value in the tree when it has 'F' at the 
		starting of the input line */
		case 'F': {
			cin >> number;
			cout << "Finding " << number << endl;
			// calling the find() method by passing the number taken from input
			bool status = myBST.find(number);
			if (status == false) {
				// if the status is false then it prints this statement
				cout << "Number not found." << endl;
			}
			break;
		}
		/* This will come in to the picture when the starting line of the
		input character is other than 'I','O','A','F' */
		default:cout << "Holy Cow!!" << endl;

		}
		cin >> command;
	}
	//cout << "Height:" << myBST.Height() << endl;;

	// TODO: input loop for commands

	return 0;
}