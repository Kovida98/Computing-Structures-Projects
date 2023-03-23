// Project 4
// Fall 2022
// Computing Structures

#include <iostream>
#include <list>     // stl list library
#include <iterator> // to iterate through the list

using namespace std;

class GL; // prototype for class GL

// node class to store char and generalized linked list called down
class node
{
protected:
    char* charVariable; // single char variable pointer (not an array)
    GL* down;           //  going down to the next level

public:
    node(); // default constructor

    // setters
    void setCharVariable(char var);
    void setDown(GL* d);

    // getters
    char* getChar();
    GL* getDown();

    // display
    void displayChar();
};
// Default constructor to initialize the values of charVariable and down attributes
node::node() {
    charVariable = NULL;
    GL* down = NULL;
}
//This method takes a parameter var and assigns it to the charVariable attribute
void node::setCharVariable(char var) {
    charVariable = new char(var);
   
}
// This method returns the value of the protected charVariable attribute
char* node::getChar() {
    return charVariable;
}
//This method takes a parameter d and assigns it to the down attribute
void node::setDown(GL* d) {
    down = d;
}
// This method returns the protected down attribute
GL* node::getDown() {
    return down;
}
// This method is used to display the charVariable in the expressions
void node::displayChar() {
    cout << this->getChar() << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// class Generalized List
class GL
{
protected:
    list<node> head;
    //list<char> duplist;
    //int height=0;
    //list<GL> GLlist;// head of the list - each object is of type node class

public:
    GL();                                         // default constructor
    void buildGL(string l);                       // to build the generalized list
    bool findCharInExpression(char findThisChar); // given a char, find it in a given expression
    int LCAdistance(char char1, char char2);      // find the LCA distance of two char in the expression
    //int heightOfGL(string exp);                             // return the height of the GL using the GL
    int heightOfGL();
    void searchDuplicates();                      // print all the duplicates in the GL
    void display();                               // display list
    list<char> duplicatelist();                   // To get the expression from head list
    //int heightlist();

};
// Default constructor to initialize the value of h
GL::GL() {
    list<node> head = {};
    int height = 0;
}
/*This method takes parameter l and is used to build the
generalised list which stores the parenthesized expression */
void GL::buildGL(string l) {
    //cout << "b" << endl;
    int len = l.size();  // stores the length of string l
    int counter_open = 0;  // to count number of open brackets
    int counter_close = 0; // to count number of closed brackets
    string subst = "";    // to fetch the substring inside the string l
    node* temp = new node();  // node class object
    GL* GLtemp = new GL();  // GL class object
    //int s = 1;
    for (int i = 1; i < len; i++) {
        //cout << "l[s] " << i << endl;
        // By using for loop we are checking whether the element in l is not '(' and ')'
        if (l[i] != '(' && l[i] != ')') {
            //cout << l[i] << endl;
            /*After checking the condition, we are setting that character by calling setCharVariable method
            and setting down to NULL then pushing that temp node in to head list.*/
            temp->setCharVariable(l[i]);
            temp->setDown(NULL);
            head.push_back(*temp);
        }
        /*If the element is open bracket then we are fetching the substring
        and sending that substring into BuildGL method recursively. */
        else if (l[i] == '(') {
            //cout << "inside (" << endl;
            counter_open++;  // incrementing open bracket count
            for (int j = i + 1; j < len - 1; j++) {
                if (l[j] == '(') {
                    counter_open++;
                }
                else if (l[j] == ')') {
                    counter_close++; // if the element is closed bracket,incrementing the count
                    if (counter_open == counter_close) {
                        /*if that count of closed bracket and open bracket are equal then
                        fetching the corresponding substring by using substr() function */
                        subst = l.substr(i, j - i + 1);
                        //cout << "substring" << subst << endl;
                        int sub_len = subst.size();
                        // calling buildGL method passing that substring into it recursively
                        GLtemp->buildGL(subst);
                        /*Setting the charVariable to null and down to that GL object then
                        pushing that temp object in to head list*/
                        temp->setCharVariable('\0');
                        temp->setDown(GLtemp);
                        head.push_back(*temp);
                        // incrementing i value
                        i = j;
                        continue;

                    }
                }
            }
        }
        // if the element is closed bracket, then continue.
        else if (l[i] == ')') {
            continue;
        }
    }

}
/* This method is used to fetch the list of all characters from the head list
by calling this method recursively and returns tne list of characters*/
list<char> GL::duplicatelist() {
    list<char> ls;
    for (auto elm : head) {
        // if the char is not null then push that character in to that list ls
        if (*elm.getChar() != '\0') {
            ls.push_back(*elm.getChar());
        }
        else if (*elm.getChar() == '\0') {
            /*If the character is null then calling the same method by using the object
            returned by the method getDown() */
            list<char> y = elm.getDown()->duplicatelist();
            /* By using for loop push the elements present in list "y" to the list ls.*/
            for (auto e : y) {
                //cout << "e " << e << endl;
                ls.push_back(e);
            }
        }

    }

    return ls;

}
/*This method is used to search for duplicates in the list head.*/
void GL::searchDuplicates() {
    /*The method duplicatelist() is called to fetch the characters in the list head.
    The list returned from that method is stored in finallist list.*/
    list<char> finallist = this->duplicatelist();
    list<char> xlist;
    //cout << finallist.size() << endl;
    for (auto it = finallist.begin(); it != finallist.end(); it++) {
        //cout << "elm: "<< *it << endl;
        for (auto it1 = next(it, 1); it1 != finallist.end(); it1++) {
            //cout << "it:" << *it1 << endl;
            /* By using two for loops, we are checking for the duplicates and pushing those duplicates
            into list xlist*/
            if (*it == *it1) {
                xlist.push_back(*it);
                //cout << *it1 << " ";
            }
        }
    }
    // if the xlist is empty then it prints the respective message
    if (xlist.empty()) {
        cout << "No duplicates" << endl;
    }
    else {
        // By using for loop, i am printing the duplicate characters present in the list xlist
        for (auto elm : xlist) {
            cout << elm << " ";
        }
    }

}
/*This method takes the findThischar character and returns the bool status of that
character by checking in the head list.*/
bool GL::findCharInExpression(char findThisChar) {
    int find = 0;
    // Fetching the characters present in the list head and stroing in list_find list
    list<char> list_find = this->duplicatelist();
    for (auto it = list_find.begin(); it != list_find.end(); it++) {
        if (*it == findThisChar) {
            // If that findThisChar is present in that list then changing the value of find to one
            find = 1;
            //return true;
        }

    }
    /*If the value of find is one then return true*/
    if (find == 1) {
        return true;
    }
    /*If the value of find is zero then return false*/
    else {
        return false;
    }
}
/* This method is used to display the characters present in the list head by calling recursively*/
void GL::display() {

    for (auto elm : head) {
        if (*elm.getChar() != '\0') {
            /*By using for loop, if the char is not NULL then print that character*/
            cout << *elm.getChar() << " ";
        }
        else if (*elm.getChar() == '\0') {
            /*If the char is NULL, then call the method display() by using
            the object returned from getDown() method*/
            elm.getDown()->display();
        }
    }

}
// This method is used to find the height of expression and returns the height 
int GL::heightOfGL() {
    int height = 0;
    int c = 0;
    int status = 0;
    for (auto elm : head) {
        //cout << "before Height: " << height << endl;
        if (*elm.getChar() == '\0') {
            /*By using for loop, if the getChar() is NULL then call
            the heightOfGL() method recursively by using the object
            returned from getDown() method and returns the integer and is stored in s.*/
            int s = elm.getDown()->heightOfGL();
            // Incrementing the counter c
            c++;
            //cout << "after height: " << height << endl;
            // Adding the c and s and storing in the variable height 
            height = c + s;
            // Changing the value of status to one
            status = 1;
        }

    }
    // If the status is zero then the expression has no substrings then return one
    if (status == 0) {
        return 1;
    }
    // Else it returns the value of height
    else {
        return height;
    }
    
}
/* This method takes two parameters char1,char2 and returns the LCA distance between those
two characters in the expression.*/
int GL::LCAdistance(char char1, char char2) {
    // Fetching the characters present in the list head and stroing in final_list list
    list<char> final_list = this->duplicatelist();
    //list<char> LCAlist;
    string x;
    /* By using for loop, forming a string of characters present in
    final_list list. */
    for (auto it = final_list.begin(); it != final_list.end(); it++) {
        //Appending each character to form string
        x = x + *it;

    }

    int i = 0;
    int n = x.size();
    for (int i = 0; i < x.size(); i++) {
        /* If the char1 is present in the string x then break and store that index value into i.*/
        if (x[i] == char1) {
            break;
        }
    }
    //If the element char1 is the last element in the string x then return zero
    if (i >= x.size() - 1) {
        return 0;
    }
    int j;

    for (j = n - 1; j >= i + 1; j--) {
        /*From the index where the char1 is present, i am searching for other character char2 
        and then storing that char2 index in j.*/
        if (x[j] == char2) {
            break;
        }
    }
    // If the index of both the characters is same then return zero
    if (j == i) {
        return 0;
    }
    // Returning the length of the characters between the char1 and char2 from the string x.
    return (j - i - 1);
}
int main()
{
    int numExpressions; // number of expressions
    char option;        // command from the input file
    char option2;      // temp variable to store the char from input
    string x;          // To read the string given in the input file
    char command;      // temp variable to store the character(F,D,U,H) from the input
    int num;           // temp varaible to store the number from input
    // read the number of expressions given
    cin >> numExpressions;
    // Printing the number of expressions
    cout << "Number of expressions: " << numExpressions << endl;
    /* Created an array arr to store all the expressions from the input file*/
    string* arr = new string[numExpressions];
    for (int i = 0; i < numExpressions; i++) {
        // Reading the string from input file
        cin >> x;
        //cout << x << endl;;
        // Stroing those string expressions into the array
        arr[i] = x;

    }
    // Created a GL object
    GL tempGL;
    GL* expressions = new GL[numExpressions]; // an array of expressions / an array of GL objects
    for (int i = 0; i < numExpressions; i++) {
        /*Calling the buildGL method by passing each expression into that
        using the array of GL objects "expressions". */
        expressions[i].buildGL(arr[i]);
    }
    // This will take the character at the starting of all the lines from the given input.
    cin >> command;
    // This while loop ends when it reaches the end of the input file.
    while (!cin.eof()) {

        switch (command) {
        case 'D': {
            /* This switch case is for displaying the expressions given from the input file
            When it has 'D' at the starting of the line in input.*/
            cout << "Displaying all expressions:" << endl;
            for (int i = 0; i < numExpressions; i++) {
                cout << "Expression " << i << " :";
                expressions[i].display();
                cout << endl;
            }

            break;
        }
        case 'F': {
            /*This switch case is used to find the character in particular expression.
            Here it will take the values of num and option from the input file.*/
            cin >> num;
            cin >> option;
            cout << "Find " << option << " " << "in " << num << ":";
            /*Calling the findCharInExpression() method by passing the option by using
            the object in the expressions array in the index num*/
            bool status = expressions[num].findCharInExpression(option);
            if (status == true) {
                cout << " found" << endl;
            }
            else {
                cout << " not found" << endl;
            }
            break;
        }
        case 'U': {
            /*This switch case is used to search the duplicates in the particular expression
            Here it will take the values of num from the input file.*/
            cin >> num;
            cout << "Duplicates in " << num << " :";
            /* Calling the searchDuplicates() method by using the object in the expressions
            array in the index num.*/
            expressions[num].searchDuplicates();
            cout << endl;
            break;
        }
        case 'H': {
            /*This switch case is used to find the height of particular expression.
            Here it will take the value of num from the input file.
            Here, calling the heightOfGL() method by using the object in the expressions
            array in the index num.*/
            cin >> num;
            int hei = expressions[num].heightOfGL();
            //int fheight = hei + 1;
            cout << "height of expression " << num << " : " << hei << endl;
            break;
        }
        case 'L': {
            /*This switch case is used to find the LCA distance between two characters 
            in the given expression. This takes num,option,option2 values from the input file.*/
            cin >> num >> option >> option2;
            /* Calling LCAdistance() method by using the object in the expressions array
            in the index num.*/
            int d = expressions[num].LCAdistance(option,option2);
            cout << "LCA distance between " << option << " and " << option2 << " in expression " << num << " : " << d << endl;
            break;
        }
        // This will come in to the picture when the starting line of the input character is other than 'U','D','F','H'
        default: cout << "Holy Cow!!" << endl;

        }
        cin >> command;
    }

    // read one line/expression at a time and call the buildGL method for each expression[i]

    // read in and process all the options using switch case
    return 0;

}