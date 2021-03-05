//
//  dvdInfoAccess.c
//  step2
//
//  Created by hyungwook on 2021/03/05.
//

#include "common.h"
#include "dvdInfo.h"

#define MAX_DVD 100

static dvdInfo *dvdList[MAX_DVD];
static int numOfDvd = 0;

int AddDvdInfo(char *ISBN, char *title, int genre)
{
    if(numOfDvd >= 100)
        return 0;
    
    dvdList[numOfDvd] = malloc(sizeof(dvdInfo));
    
    strcpy(dvdList[numOfDvd]->ISBN, ISBN);
    strcpy(dvdList[numOfDvd]->title, title);
    dvdList[numOfDvd]->genre = genre;
    
    numOfDvd++;
    
    return numOfDvd;
}

dvdInfo *GetdvdPtrByISBN(char *ISBN)
{
    for(int i = 0; i < numOfDvd; i++)
    {
        if(!strcmp(dvdList[i]->ISBN, ISBN))
        {
            return dvdList[i];
        }
    }
    
    return NULL;
}

int IsRegistISBN(char *ISBN)
{
    for(int i = 0; i < numOfDvd; i++)
    {
        if(!strcmp(ISBN, dvdList[i]->ISBN))
        {
            return 1;
        }
    }
    
    return 0;
}
