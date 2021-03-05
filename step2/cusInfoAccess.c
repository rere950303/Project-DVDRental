//
//  cusInfoAccess.c
//  step1
//
//  Created by hyungwook on 2021/03/05.
//

#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER 100

static cusInfo *cusList[MAX_CUSTOMER];
static int numOfCustomer = 0;

int AddCusInfo(char *ID, char *name, char *num)
{
    if(numOfCustomer >= 100)
        return 0;
    
    cusList[numOfCustomer] = malloc(sizeof(cusInfo));
    
    strcpy(cusList[numOfCustomer]->ID, ID);
    strcpy(cusList[numOfCustomer]->name, name);
    strcpy(cusList[numOfCustomer]->phoneNum, num);
    
    numOfCustomer++;
    
    return numOfCustomer;
}

cusInfo *GetCusPtrByID(char *ID)
{
    for(int i = 0; i < numOfCustomer; i++)
    {
        if(!strcmp(cusList[i]->ID, ID))
        {
            return cusList[i];
        }
    }
    
    return NULL;
}

int IsRegistID(char *ID)
{
    for(int i = 0; i < numOfCustomer; i++)
    {
        if(!strcmp(ID, cusList[i]->ID))
        {
            return 1;
        }
    }
    
    return 0;
}
