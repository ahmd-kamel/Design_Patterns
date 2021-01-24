#ifndef HISTORY_H
#define HISTORY_H

// history of editor states 
class History{

    private:
    // a vector of states 'we could use stack instead of vector'
    vector <EditorState> states;

    public:
    // here we push a new state to the vector
    void push (EditorState state){
        states.push_back(state);
    }

    // here we retrive the last state of the editor
    EditorState pop(){
        int lastIndex = states.size() - 1;
        EditorState lastState = states[lastIndex];
        states.pop_back();

        return lastState;
    }
};

#endif