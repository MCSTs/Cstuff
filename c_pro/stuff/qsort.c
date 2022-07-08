#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char first[20];
    char last[20];
}name;


int mycp(const void *p1, const void *p2)
{
    const name *pp1 = (name *)p1;
    const name *pp2 = (name *)p2;

   /*int re = strcmp(pp1->first, pp2->first);*/
   /*if (re != 0)*/
       /*return re;*/
   /*else*/
       /*return strcmp(pp1->last, pp2->last);*/

    char h1 = pp1->first[0];
    char h2 = pp2->first[0];
    char hh1 = pp1->last[0];
    char hh2 = pp2->last[0];
    if (h1 > h2)
        return 1;
    else
        return hh1-hh2;
        

}

int main(void)
{
    int i;
    name ross, rachel, chandler, monica, joey, phoebe;
    strcpy(ross.first, "ross");
    strcpy(ross.last, "galer");

    strcpy(rachel.first, "rachel");
    strcpy(rachel.last, "green");

    strcpy(monica.first, "monica");
    strcpy(monica.last, "galer");

    strcpy(chandler.first, "chandler");
    strcpy(chandler.last, "bin");

    strcpy(joey.first, "joey");
    strcpy(joey.last, "chuibianni");

    strcpy(phoebe.first, "phoebe");
    strcpy(phoebe.last, "buffer");

    name guys[6] = {ross, rachel, chandler, monica, joey, phoebe};

    puts("source: ");
    for (i=0; i<6; i++) {
        printf("guy[%d]: %s.%s\n", i+1, guys[i].first, guys[i].last);
    }


    qsort(guys, 6, sizeof(name), mycp);
    putchar('\n');
    puts("qsort after: ");
    for (i=0; i<6; i++) {
        printf("guy[%d]: %s.%s\n", i+1, guys[i].first, guys[i].last);
    }


    return 0;
}
