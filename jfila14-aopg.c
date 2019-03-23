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

        // printf("Iniciado na pos %d com valor %d\n", pos, value);
        (*lineUp).first = aux;

    } else {

        // printf("linkado ao endereco %d com valor %d\n", pos, value);
        (*lineUp).last->next = aux;
        // show(list[pos].first, pos);
    }
    (*lineUp).last = aux; 
}


void increaseLine(LineUp *lineUp, unsigned int id) {

    Node *linedMan = (Node *)malloc(sizeof (Node));
    
    if (!linedMan) {
        // printf("Alocations failed, memory full\n");
        exit(-1);
    }
    linedMan->id = id;
    linedMan->next = NULL;
    if ((*lineUp).first == NULL) {
        // printf("m** de du** == NULL\n");
        // printf("added node with ID: %u\n", linedMan->id);
        linedMan->prev = NULL;
        (*lineUp).first = linedMan;
        // printf("(*lineUp).first = %u\n", (*lineUp).first->id);
    } else {
        linedMan->prev = (*lineUp).last;
        (*lineUp).last->next = linedMan;
        
    }
    (*lineUp).last = linedMan;
    // printf("virou ao avesso viro gabiru\n");
    // if ((*lineUp).first->next != (*lineUp).last)
    //     printf("(*lineUp).first->next->id == %u\n", (*lineUp).first->next->id);
    if ((*lineUp).first->next != NULL) {
        for (linedMan = (*lineUp).first; linedMan->next != NULL; linedMan = linedMan->next) {
            // printf("->next->id(%u)\n", linedMan->id);
        }
    }
    // printf("(*lineUp).last = %u\n", (*lineUp).last->id);
    
    // printf("m** de duda\n");
    
    // printf("m** de duda2\n");
    // printf("cu de duda\n");
    // printf("alocated with id=%u next=%u\n", id, linedMan->next->id);
}

void giveUp(LineUp *lineUp, unsigned int id) {

    Node *chickened = (*lineUp).first;
    // printf("chicken->id ?= %u\n", id);

    for (; (*chickened).next != NULL || chickened == lineUp->last;) {

        // printf("chicken looped with id = %u\n", chickened->id);
        // printf("*chick id = %u \n chicken id = %u\n", (*chickened).id, chickened->id);
        if ((*chickened).id == id) {
            // printf("chicken found ");
            Node *temp;
            if ((*chickened).next != NULL && chickened != lineUp->first && chickened != lineUp->last) {
                // printf("and there is a next\n");
                // printf("#1 chickened->next->id == %d \n", chickened->next->id);
                // printf("#2 chickened->prev->id == %d \n", chickened->prev->id);     
                // printf("#3 chickened->prev->next->id == %d \n", chickened->prev->next->id);
                if (chickened->prev) {
                    temp = chickened->prev;
                    temp->next = chickened->next;
                    chickened->next->prev = temp;
                    chickened->prev = temp;
                    // printf("free(chicken->id == %u) \n", (*chickened).id);
                    free(chickened);
                    break;
                }
            }
            else if (chickened == lineUp->first)
            {
                // printf("pau no cu do first->id == %u\n", chickened->id);
                temp = chickened;
                chickened->next->prev = NULL;
                // (*chickened->next).prev = NULL;
                lineUp->first = temp->next;
                free(chickened);
                // lineUp->first = temp->next;
                break;
            }
            // printf("n foi o first\n");
            // printf("eh o last? = %u\n", chickened==lineUp->last);
            if (chickened == lineUp->last)
            {
                // printf("quem dorme no ponto...    last->id == %u\n", chickened->id);
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
            // printf("chiken.id = %u not chicken \n", (*chickened).id);
            chickened = (*chickened).next;
            // printf("next chicken->id == %u\n", chickened->id);
        }

        if (chickened == lineUp->last && id != lineUp->last->id)  {

            // printf("Error404: ID NOT FOUND\n");
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
    printf("\n");
}


int main()
{
    unsigned int n, aux, m;
    LineUp TheLineUp, *lineUp = &TheLineUp;
    
    init (lineUp);

    scanf("%u", &n);
    if (n > 50000 || n < 1) {

        // printf("Size_Error: too much/less linedMans\n");
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

        // printf("Size_Error: too much/less chicken\n");
    }

    for (unsigned int i = 0; i < m; i++) {

        scanf("%u", &aux);
        giveUp(lineUp, aux/*, lineUp->first*/);
    }

    print(lineUp);

    {
        // printf("lul it did enter\n");
        Node *temp = TheLineUp.first, *aux;
        // printf("duda is freeing memory already, LUL\n");
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