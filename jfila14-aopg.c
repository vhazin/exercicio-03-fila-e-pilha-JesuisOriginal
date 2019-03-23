#include <stdio.h>
#include <stdlib.h>

typedef struct node {

    unsigned int id;
    struct node *next, *prev;
} Node;

typedef struct {
    unsigned int size;
    Node *first, *last;
} LineUp;

void insert(LineUp *lineUp, int size, int id) {

    Node *aux = (Node *)malloc(sizeof(Node));

    aux->id = id;
    aux->next = NULL;
    if ((*lineUp).first == NULL) {

        (*lineUp).first = aux;

    } else {

        (*lineUp).last->next = aux;
        // show(list[pos].first, pos);
    }
    (*lineUp).last = aux; 
}


void increaseLine(LineUp *lineUp, unsigned int id) {

    Node *linedMan = (Node *)malloc(sizeof (Node));
    
    if (!linedMan) {
        exit(-1);
    }
    linedMan->id = id;
    linedMan->next = NULL;
    if ((*lineUp).first == NULL) {
        linedMan->prev = NULL;
        (*lineUp).first = linedMan;
    } else {
        linedMan->prev = (*lineUp).last;
        (*lineUp).last->next = linedMan;
        
    }
    (*lineUp).last = linedMan
    // if ((*lineUp).first->next != (*lineUp).last)
    //     printf("(*lineUp).first->next->id == %u\n", (*lineUp).first->next->id);
    if ((*lineUp).first->next != NULL) {
        for (linedMan = (*lineUp).first; linedMan->next != NULL; linedMan = linedMan->next) {

        }
    


}

void giveUp(LineUp *lineUp, unsigned int id) {

    Node *chickened = (*lineUp).first

    for (; (*chickened).next != NULL || chickened == lineUp->last;) {

        if ((*chickened).id == id) {

            Node *temp;
            if ((*chickened).next != NULL && chickened != lineUp->first && chickened != lineUp->last) {
    
    
    
    
                if (chickened->prev) {
                    temp = chickened->prev;
                    temp->next = chickened->next;
                    chickened->next->prev = temp;
                    chickened->prev = temp;
        
                    free(chickened);
                    break;
                }
            }
            else if (chickened == lineUp->first)
            {
    
                temp = chickened;
                chickened->next->prev = NULL;
                // (*chickened->next).prev = NULL;
                lineUp->first = temp->next;
                free(chickened);
                // lineUp->first = temp->next;
                break;
            }


            if (chickened == lineUp->last)
            {
    
                // temp = chickened;
                chickened->prev->next = NULL;
                // (*chickened->prev).next = NULL;
                lineUp->last = chickened->prev;
                free(chickened);
                // lineUp->last = temp->prev;
                break;
            }
            
                            
            
        } else
        {

            chickened = (*chickened).next;

        }

        if (chickened == lineUp->last && id != lineUp->last->id)  {


            exit(-1);
        }
        
    }

}

void init(LineUp *lineUp) {

    (*lineUp).first = NULL;
    (*lineUp).last = NULL;
    (*lineUp).size = 0;
}

void print(LineUp *lineUp)
{

    Node *temp = (*lineUp).first;
    for (; (*temp).next; ){
        printf("%u ", (*temp).id);
        temp = temp->next;
        if ((!temp->next) && temp == lineUp->last)
            printf("%u", (*temp).id);
    
}


int main()
{
    unsigned int n, aux, m;
    LineUp TheLineUp, *lineUp = &TheLineUp;
    
    init (lineUp);

    scanf("%u", &n);
    if (n > 50000 || n < 1) {

        exit(-1);
    }
    // unsigned int *inp = (unsigned int*)calloc(n, sizeof(unsigned int));

    for (unsigned int i = 0; i < n; i++) {

        // scanf("%u", &inp[i]);
        scanf("%u", &aux);
        increaseLine(lineUp, aux);
    }

    scanf("%u", &m);
    // inp = (unsigned int*)realloc(n, sizeof(unsigned int));
    if (m > 50000 || m < 1 || m > n) {

    }

    for (unsigned int i = 0; i < m; i++) {

        scanf("%u", &aux);
        giveUp(lineUp, aux/*, lineUp->first*/);
    }

    print(lineUp);

    {
        Node *temp = TheLineUp.first, *aux;
        for (temp = TheLineUp.last; temp->prev /*!= NULL*/;) {
            Node *aux = temp->prev;
            free(temp);
            if (temp->next)
                free(temp->next);
            temp = aux;
        }
        // free(lineUp);
    }
}