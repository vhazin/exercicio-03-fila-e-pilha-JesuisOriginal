#include <stdio.h>
#include <stdlib.h>

typedef struct node {

    unsigned int id;
    struct node *next, *prev;
} Node;

typedef struct {
    Node *first, *last;
} LineUp;


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
    (*lineUp).last = linedMan;
    
    
}

void giveUp(LineUp *lineUp, unsigned int id) {

    Node *chickened = (*lineUp).first;
    Node *next;
    

    for (; (*chickened).next != NULL || chickened == lineUp->last;) {
        printf("### loop start with chicken %u\n",chickened->id);
        if (chickened->next) next = chickened->next;
        if (chickened->id == id && chickened == lineUp->first) {
        	printf("# foi o first %u\n", chickened->id);
            lineUp->first = lineUp->first->next;
            printf("# n eh mais o first %u\n", lineUp->first->id);
            free(chickened);
            printf("libero\n");
            // break;
        }
        if (0) printf("next->id == id? %u\n", next->id == id);
        if (next->id == id){
                printf("# chk->id=%u is at next->id %u\n", chickened->id, next->id);
                chickened->next = next->next;
                printf("chicken\n");
                printf("# post change chk->id=%u is at next->id %u\n", chickened->id, chickened->next->id);
                if (next == lineUp->last) { 
                    lineUp->last = chickened; 
                    printf("#new last->%u\n", lineUp->last->id);
                }
                
                free(next);
                break;
        }
        
        
        // else {
        //     chickened = next;
        // }

        // if ((*chickened).id == id ) {
            
        //     Node *temp;
            
        //     if ((*chickened).next != NULL && chickened != lineUp->first && chickened != lineUp->last) {
          
        //             temp = chickened->prev;
        //             temp->next = chickened->next;
        //             chickened->next->prev = temp;
        //             chickened->prev = temp;
        //             free(chickened);
        //             break;
                
        //     }
        //     else if (chickened == lineUp->first)
        //     {
                 
        //         temp = chickened;
        //         chickened->next->prev = NULL;
        //         lineUp->first = temp->next;
        //         free(chickened);
                
                
        //         break;
        //     }
        //     if (chickened == lineUp->last)
        //     {
        //         chickened->prev->next = NULL;
        //         lineUp->last = chickened->prev;
        //         free(chickened);
        //         break;
        //     }
            
                            
            
        else
        {
            chickened = (*chickened).next;
        }

        if (chickened == lineUp->last && id != lineUp->last->id)  {
            break;
        }
        
    }

}

void init(LineUp *lineUp) {

    (*lineUp).first = NULL;
    (*lineUp).last = NULL;
}

void print(LineUp *lineUp)
{
    if (lineUp->last == lineUp->first) {
        printf("%u", lineUp->first->id);
    }
    Node *temp = (*lineUp).first;
    for (; (*temp).next; ){
        printf("%i ", (*temp).id);
        temp = temp->next;
        if ((!temp->next) && temp == lineUp->last)
            printf("%i ", (*temp).id);
    }
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

    for (unsigned int i = 0; i < n; i++) {

        scanf("%u", &aux);
        if (aux < 1 || aux > 100000)
        	exit(-1);
        increaseLine(lineUp, aux);
    }

    scanf("%u", &m);
    if (m > 50000 || m < 1 || m >= n) {
		exit(-1);
    }

    for (unsigned int i = 0; i < m; i++) {

        scanf("%u", &aux);
        giveUp(lineUp, aux);
    }
    print(lineUp);

    {
        Node *temp = TheLineUp.first;
        for (temp = TheLineUp.last; temp->prev;) {
            Node *aux = temp->prev;
            free(temp);
            if (temp->next)
                free(temp->next);
            temp = aux;
        }
    }
}