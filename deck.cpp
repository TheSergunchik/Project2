/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 1, Part B
 * Function definition for deck class.
 */

#include "deck.h"

deck::deck()
{
    int faces[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};\

    for(int i = 0; i< fullDeck; i++)
    {
        append(&head, faces[i % 13], suits[i / 13]);
    }

    cout<<"Created Linked list is: ";
    printDeck(head);
}

/* Given a reference (pointer to pointer)
to the head of a list and an int, inserts
a new node on the front of the list. */
void deck::push(card** head_ref, int value, string suit)
{
    /* 1. allocate node */
    card* new_node = new card();

    /* 2. put in the data */
    new_node->setValue(value);
    new_node->setSuit(suit);

    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);

    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Given a node prev_node, insert a new node after the given
prev_node */
void deck::insertAfter(card* prev_node, int value, string suit)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        cout<<"the given previous node cannot be NULL";
        return;
    }

    /* 2. allocate new node */
    card* new_node = new card();

    /* 3. put in the data */
    new_node->setValue(value);
    new_node->setSuit(suit);

    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
}

/* Given a reference (pointer to pointer) to the head
of a list and an int, appends a new node at the end */
void deck::append(card** head_ref, int value, string suit)
{
    /* 1. allocate node */
    card* new_node = new card();

    card *last = *head_ref; /* used in step 5*/

    /* 2. put in the data */
    new_node->setValue(value);
    new_node->setSuit(suit);

    /* 3. This new node is going to be
    the last node, so make next of
    it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty,
    then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;

    return;
}

// This function prints contents of
// linked list starting from head
void deck::printDeck(card *node)
{
    while (node != NULL)
    {
        cout<<" Value: "<< node->getValue() << " Suit: " << node->getSuit() << endl;
        node = node->next;
    }
}

ostream& operator<<(ostream &out, deck &A)
{

    A.printDeck(A.head);

    return out;
}

void push(card** head_ref, int new_data)
{

}




/*
ostream



void deck::printDeck()
{
    for(int i = 0; i < fullDeck; i++)
    {
        cout << deck[i].print();
    }
}

void deck::shuffle()
{
    for(int i = 0; i < fullDeck; i++)
    {
        int next = (rand() + time(0)) % fullDeck;
        card hold = deck[i];
        deck[i] = deck[next];
        deck[next] = hold;
    }
}
*/

