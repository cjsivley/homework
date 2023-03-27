// SchemeEmulator.cpp
// Codey Sivley
// Prog Lang Exam 2 Code Portion
//

#include <iostream>
#include <string>
#include <deque>

using namespace std;

//prototype
deque<char> car(deque<char>); //returns first element as a list
deque<char> cdr(deque<char>); //returns all except first element as list
deque<char> cons(deque<char>, deque<char>); //returns joined list from two arguments
void prDq(deque<char>); //prints lists
deque<char> cmdInput(string); //converts strings to lists for ease of use
deque<char> interpreter(deque<char>); //RECURSIVE, parses through nested commands

int main()
{
    cout << "Scheme Emulator\n";
    
    //testing
    prDq(interpreter(cmdInput("(car'(r s t z))")));
    prDq(interpreter(cmdInput("(cdr'(r s t z))")));
    //prDq(interpreter(cmdInput("(cons 'u '(v w x))"))); //cons expects a closing paren after u
    prDq(interpreter(cmdInput("(car(cdr(r s t u))")));
    prDq(interpreter(cmdInput("(car(cdr(cdr(r s t u))))")));
    prDq(interpreter(cmdInput("(cdr(cdr(cdr(cdr'(r s t u)))))")));
    prDq(interpreter(cmdInput("(car(cdr(car'((r s)(t v)))))")));
    prDq(interpreter(cmdInput("(cons'(rs)'((tu)))")));
    prDq(interpreter(cmdInput("(car(car'(r))'(s t u v w x)))")));
    prDq(interpreter(cmdInput("(cons(car'(rvs))(cdr'(t x)))")));

    //trying to get (sijk)
    string given = "(abcd)(ef(gsh(ijk)l)mn)op)";
    //prDq(interpreter(cmdInput("(cons(car(cdr(cdr(cdr(" + given + ")))))cdr(cdr(cdr(cdr(" + given + ")))))")));
    //breaks from mem access issues
}

//toolbox
deque<char> cmdInput(string x) {
    //load string into deque
    deque<char> cmd;
    for (auto it = x.begin(); it != x.end(); it++) {
        if (*it != ' ') { cmd.push_back(*it); }
    }
    return cmd;
}
deque<char> car(deque<char> list) {
    deque<char> output;
    //find start
    auto it = list.begin();
    output.push_back(*it); //first char should always be '('
    it++;
    if (*it != '(') { //if not compound
        output.push_back(*it);
    }
    else { //if compound
        while (*it == '(') { //skip open parens
            it++;
        }
        while (*it != ')') { //then grab until first close paren
            output.push_back(*it);
            it++;
        }
    }
    output.push_back(')');
    return output;
}
deque<char> cdr(deque<char> list) {
    deque<char> output;
    auto it = list.begin();
    it++; //first element, need to skip
    if (*it == '(') { //if compound list
        it++;
        while (*it != ')') {
            it++;
        } //skip to end paren
        it++;
    }
    if (*it != '(') { //if value
        it++; //skip first element
        output.push_back('(');
        while (*it != ')') {
            output.push_back(*it);
            it++;
        }
        output.push_back(')');
    }
    else {//if compound list
        output.push_back('('); //enclosing paren
        while (it != list.end()) {
            output.push_back(*it); //add the remainder of the list
            it++;
        }
    }
    return output;
}
void prDq(deque<char> x) {
    for (auto it = x.begin(); it != x.end(); it++) {
        cout << *it;
    }
    cout << endl;
}
deque<char> cons(deque<char>list1, deque<char>list2) {
    deque<char> output;
    //single object cases
    if (list1.size() == 3) {
        output = list2;
        output.insert(output.begin()+1,list1[1]);
    }
    else if (list2.size() == 3) {
        output = list1;
        output.insert(output.end()-1,list2[1]);
    }
    else {
        output.push_back('(');
        for (auto it = list1.begin(); it != list1.end(); it++) {
            output.push_back(*it);
        }
        for (auto it = list2.begin(); it != list2.end(); it++) {
            output.push_back(*it);
        }
        output.push_back(')');
    }
    return output;
}
deque<char> interpreter(deque<char> cmd) { //recursive
    deque<char> buffer;
    deque<char> passer = cmd;

    //load to see if there's a command
    for (int i = 0; i < 3; i++) {
        buffer.push_back(cmd[i]);
    }
    //if commands, perform then return
    if (buffer[1] == 'c' && buffer[2] == 'a') {
        passer.pop_front();
        while (passer[0] != '(') { passer.pop_front(); }
        return car(interpreter(passer));
    }
    if (buffer[1] == 'c' && buffer[2] == 'd') {
        passer.pop_front();
        while (passer[0] != '(') { passer.pop_front(); }
        return cdr(interpreter(passer));
    }
    if (buffer[1] == 'c' && buffer[2] == 'o') {
        passer.pop_front();
        while (passer[0] != '(') { passer.pop_front(); }
        deque<char> arg1;
        deque<char> arg2;
        auto it = passer.begin();
        while (*it != ')') {
            arg1.push_back(*it);
            it++;
        }
        arg1.push_back(*it);
        it++;
        while (it != passer.end()) {
            arg2.push_back(*it);
            it++;
        }
        return cons(interpreter(arg1), interpreter(arg2));
    }
    //otherwise, return
    else {
        return cmd;
    }
}
