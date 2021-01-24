#ifndef EDITOR_STATE
#define EDITOR_STATE

// editorstate  class to represent the state of the editor
class EditorState{

    private:
    // the content of the state
    string content;

    public:
    // constructor
    EditorState(string content){
        this->content = content;
    }
    // getter 
    string getContent(){
        return content;
    }



};

#endif