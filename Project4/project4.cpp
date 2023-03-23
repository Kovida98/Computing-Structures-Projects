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
node::node() {
    charVariable = NULL;
    GL* down = NULL;
}
void node::setCharVariable(char var) {
    charVariable = new char(var);
    //charVariable = &var;
    //cout << charVariable;
}
char* node::getChar() {
    return charVariable;
}
void node::setDown(GL* d) {
    down = d;
}
GL* node::getDown() {
    return down;
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// class Generalized List
class GL
{
protected:
    list<node> head;
    list<char> duplist;
    //list<GL> GLlist;// head of the list - each object is of type node class

public:
    GL();                                         // default constructor
    void buildGL(string l);                       // to build the generalized list
    bool findCharInExpression(char findThisChar); // given a char, find it in a given expression
    int LCAdistance(char char1, char char2);      // find the LCA distance of two char in the expression
    int heightOfGL(string exp);                             // return the height of the GL using the GL
    int heightOfGL();
    void searchDuplicates();                      // print all the duplicates in the GL
    void display();                               // display list
    
};

GL::GL() {
    list<node> head = {};
}

void GL::buildGL(string l) {
    //cout << "b" << endl;
    int len = l.size();
    int counter_open = 0;
    int counter_close = 0;
    string subst = "";
    node* temp=new node();
    GL* GLtemp=new GL();
    //int s = 1;
    for (int i = 1; i < len; i++) {
        //cout << "l[s] " << i << endl;
        if (l[i] != '(' && l[i] != ')') {
            //cout << l[i] << endl;
            temp->setCharVariable(l[i]);
            temp->setDown(NULL);
            head.push_back(*temp);
            // to check the data
            /*for (auto elm : head) {
                cout << "first size: " << head.size() << endl;
                cout << elm.getChar() << endl;
            }*/
            //cout << "char printing" << endl;
        }
        else if (l[i] == '(') {
            //cout << "inside (" << endl;
            counter_open++;
            for (int j = i+1; j <len-1; j++) {
                if (l[j] == '(') {
                    counter_open++;
                }
                else if (l[j] == ')') {
                    counter_close++;
                    if (counter_open == counter_close) {
                        subst = l.substr(i, j - i + 1);
                        //cout << "j: " << j << endl;
                        //cout << "substring" << subst << endl;
                        int sub_len = subst.size();
                        GLtemp->buildGL(subst);
                        //cout << "after second buildgl" << endl;
                        temp->setCharVariable(NULL);
                        temp->setDown(GLtemp);
                        head.push_back(*temp);
                        //cout << "after buildgl" << endl;
                        i = j ;
                        // to check the data
                        /*for (auto elm : head) {
                            cout << "second head: " << head.size() << endl;
                            cout << elm.getChar() << endl;
                        }*/
                        //cout << "s: " << s << endl;
                        continue;
                        
                    }
                }
            }
        }
        else if (l[i] == ')') {
            continue;
        }
    }
    //cout << "for loop completed" << endl;
}
int GL::heightOfGL(string exp) {
    int height = 0;
    for (int i = 0; i < exp.size(); i++) {
        if (exp[i] == '(') {
            height++;
        }
    }
    return height;
}
void GL::display() {
    //cout << "(";
    for (auto elm : head) {
        if (*elm.getChar() != NULL) {
            cout << *elm.getChar() << " ";
        }
        else if (*elm.getChar() == NULL) {
            elm.getDown()->display();
        }
    }
    //cout << ")";
}

bool GL::findCharInExpression(char findThisChar) {
    
    for (auto elm : head) {
        int find = 0;
        if (*elm.getChar() != NULL && *elm.getChar() == findThisChar) {
            //cout << "char :" << *elm.getChar() << endl;
            //cout << "inside first" << endl;
            find = 1;
            return true;
            break;
            //if (find == 1) {
            //    //cout << " found" << endl;
            //    return true;
            //}
            //else {
            //    //cout << " not found" << endl;
            //    return false;
            //}
            
        }
        else if (*elm.getChar() == NULL) {
            //cout << "before" << endl;
            bool status =elm.getDown()->findCharInExpression(findThisChar);
            //return status;
            if (status == true) {
                find = 1;
                //cout << "found" << endl;
            }
            else {
                find = 0;
                //cout << "not found" << endl;
            }
            //cout << "after" << endl;
            
        }
    }
   //cout << "after for loop" << endl;
    
}
void GL::searchDuplicates() {
    //list<char> ls;
    //list<char> clist;
    for (auto elm : head) {
        if (*elm.getChar() != NULL) {
            //cout << "not null" << endl;
            //clist.push_back(*elm.getChar());
            duplist.push_back(*elm.getChar());
        }
        else if (*elm.getChar() == NULL) {
            //cout << "null" << endl;
            elm.getDown()->searchDuplicates();
            
            /*for (auto elm : clist) {
                cout << "inside for" << endl;
                clist.push_back(elm);
            }*/
            
        }

    }
    //for (auto elm : clist) {
    //    duplist.push_back(elm);
    //    //cout << elm << "," << endl;
    //}
    //for (auto elm : duplist) {
    //    cout << elm << ":";
    //}
    for (auto elm : duplist) {
        cout << elm << "," << endl;
  
}






    int main()
    {
        int numExpressions; // number of expressions
        char option;        // command from the input file
        string x;
        char command;
        int num;
        // read the number of expressions given
        cin >> numExpressions;
        cout << "Number of expressions: " << numExpressions << endl;
        /*cin >> x;
        cout << x;*/
        string* arr = new string[numExpressions];
        for (int i = 0; i < numExpressions; i++) {
            cin >> x;
            //cout << x << endl;;
            arr[i] = x;

        }
        GL tempGL;
        GL* expressions = new GL[numExpressions]; // an array of expressions / an array of GL objects
        for (int i = 0; i < numExpressions; i++) {
            expressions[i].buildGL(arr[i]);
            //cout << "finished one expression" << endl;
        }
        cin >> command;
        while (!cin.eof()) {
            switch (command) {
            case 'H': {
                cin >> num;
                int hei = tempGL.heightOfGL(arr[num]);
                cout << "Height of the Expression: " << hei << endl;
                break;
            }
            case 'D': {
                cout << "Displaying all expressions:" << endl;
                for (int i = 0; i < numExpressions; i++) {
                    cout << "Expression " << i << " :";
                    expressions[i].display();
                    cout << endl;
                }

                break;
            }
            case 'F': {
                cin >> num;
                cin >> option;
                cout << "Find " << option << " " << "in " << num << ":";
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
                cin >> num;
                expressions[num].searchDuplicates();
                break;
            }
            default: cout << "Holy Cow!!" << endl;

            }
            cin >> command;
        }

        // read one line/expression at a time and call the buildGL method for each expression[i]

        // read in and process all the options using switch case
        return 0;
    } // main

