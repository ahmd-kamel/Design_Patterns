### Table of Contents

1. [Memento Description](#Description)
2. [Project Motivation](#Motivation)
3. [Intent](#Intent)
4. [Applicability](#Applicability)
5. [Structure](#Structure)
6. [Consequences](#Consequences)


## Memento Description <a name="Description"></a>
Memnto also known as Token is a well-known design pattern, categorized as a behavioral pattern it's an object scope pattern.


## Motivation <a name="Motivation"></a>
Sometimes while you work on let's say an editor to code somthing wrong happens and to avoid that you need to undo what you have done. so to do the undo mechanism you need the memento pattern.


## Intent <a name="Intent"></a>
What is memento ? memento is an object that stores a snapshot of the internal state of another object.
so that the object can be restored to this state later without violating encapsulation principal "it needs to revert the object to a previous state without exposing its internal structure and representations".



## Applicability <a name="Applicability"></a>
You can use the memento pattern when
Markup : * a snapshot of an object "state" must be saved so that you can restore it later.
         * a direct interface to get the last state would expose implementation details and break up the object's encapsulation.


## Structure <a name="Structure"></a>
Markup : 1. Memento `EditorStates()`
            1. stores internal stats of the Originator `Editor()` object.
            2. protects against access by objects other than the originator `Editor()`, only
                the originator `Editor()` that produced the memento would be permitted to access
                the memento's internal state.
         2. Originator `Editor()`
            1. use memento `EditorStates()` creates a state contatining a snapshot of its current internal state.
            2. use memento `EditorStates()` to restore its last state.
         3. Caretaker `History()`
            1. saves and retrives the mementos 'states'.
            2. never operates on or examines the contents of a memento.


## Consequences <a name="Consequences"></a>
Markup :1. Using mementos might be expensive. Mementos might incur considerable overhead
             if Originator must copy large amounts of information to store in the memento.

        2. Defining narrow and wide interfaces. It may be difficult in some languages to
            ensure that only the originator can access the memento's state.

        3. It simplifies Originator.In other encapsulation-preserving designs, Originator keeps the versions of internal
            state that clients have requested but in memento Caretaker does this job.
    


