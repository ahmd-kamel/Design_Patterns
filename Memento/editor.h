#ifndef EDITOR_H
#define EDITOR_H

// here is the core class
class Editor{

    private:
    // content of the editor
    string content;

    public:
    // making a new state 
    EditorState createState(){

        return EditorState(content);
    }
    // it restore the previous state content in current content
    void restore(EditorState state){
        content = state.getContent();
    }
    // setter
    void setContent(string content){
        this->content = content;
    }
    // getter
    string getContent(){
        return content;
    }


};

#endif