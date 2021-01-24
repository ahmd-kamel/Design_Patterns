#include <iostream>
#include <string>
#include <vector>

using namespace std;
#include "editorstate.h"
#include "history.h"
#include "editor.h"

int main()
{

    Editor editor;
    History history;

    // the first state editor saved in history
    editor.setContent("fist state");
    history.push(editor.createState());

    // the second state editor saved in history
    editor.setContent("second state");
    history.push(editor.createState());
    
    // here the recent editor state not saved
    editor.setContent("third state");

    // retriving second and first state to the recent state
    editor.restore(history.pop());
    editor.restore(history.pop());

    cout<< editor.getContent() << endl;

    return 0;
}
