2 principles I've liked about Object-Oriented Programming is that an object's state should be hidden via delegating the management of its state to the object itself, and that one should put as much of the state of an object into it's class.

An example of the former is that, in the case of a linked list, instead of every linked list element having a pointer to the next element or null, one can have a LinkedListElement class/interface which classes called "LastLinkedListElement" and "NotLastLinkedListElement" can derive from/implement such that NotLastLinkedListElement contains a pointer/reference to another LinkedListElement and LastLinkedListElement has no data member for that. 

When implementing this in most languages including C++, when adding a new element to the end, one would have to replace the current LastLinkedListElement object with a new NotLastLinkedListElement object and would then have to modify the second last element to point to this new object because you (usually) can't change the type of an object after construction.

Technically speaking, this is not violating the first principle because the state of the object holding the last item is not being managed from outside itself, because it is being destroyed and replaced by another object. But if we think about the abstract idea of THE LinkedListElement that holds a specific piece of data, that LinkedListElement is having its state managed by the second last element.

In this example, it's relatively easy to change every pointer to this specific object to point to the new object, but in a more complex object graph, this would be quite a non-trivial problem. 

What would combine these principles is if the LastLinkedListElement could transmute itself inplace to be a NotLastLinkedListElement. 
