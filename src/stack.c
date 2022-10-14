#include "stack.h"

#include <assert.h>

void initialize(stack* s) {
    // implement initialize here
    // Initialize skal bare være en pointer, som peger på et head, der peger mod
    // en node med værdien NULL.
    s->head = NULL;
}

void push(int x, stack* s) {
    // implement push here

    // Gemmer den nuværende øverste node som prev. Dermed kan jeg pege på den
    // senere.
    node* prev = s->head;

    // Allokerer memmory med størrelsen node.
    s->head = (node*)malloc(sizeof(node));

    // Sætter den nye nodes data til at være x.
    s->head->data = x;

    // Sætter den nye nodes next pointer til at pege på elementet under den nye
    // node.
    s->head->next = prev;
}

int pop(stack* s) {
    // implement pop here
    // Først asserter jeg, at stacken ikke er tom.
    assert(s->head != NULL);

    // Herefter definerer jeg en pointer til en node kaldet top, til at være
    // head elementet.
    node* top = s->head;
    // Da vi skal returnere dataet i top elementet, gemmer jeg dette i en
    // variabel top_data.
    int top_data = top->data;
    // Herefter forklarer jeg at det nye øverste element er elementet under top.
    // Vi har altså kun adgang til det "rigtige" øverste element gennem top.
    s->head = top->next;
    // Dermed kan vi free det memmory, som top peger på.
    free(top);

    // Vi returner til sidst top_data.
    return top_data;
}

bool empty(stack* s) {
    // implement empty here
    // Jeg tjekker om det øverste element i stacken er == NULL.
    if (s->head == NULL) {
        // Hvis det er det, så returner jeg true.
        return true;
    }
    // Ellers returner jeg false.
    return false;
}

bool full(stack* s) {
    // implement full here
    /*
    Da stack er en dynamisk liste, så kan den aldrig blive fuld. Dermed giver
    denne funktion ike mening.*/
    return false;
}
