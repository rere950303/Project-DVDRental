//
//  cusInfoAccess.c
//  step1
//
//  Created by hyungwook on 2021/03/05.
//

#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER 100

void storecus(cusInfo *cusList[]);

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
    
    storecus(cusList);

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

void storecus(cusInfo *cusList[])
{
    FILE *fp = fopen("storecus.bin", "wb");
    
    if(fp == NULL)
        return;
    
    fwrite(&numOfCustomer, sizeof(int), 1, fp);

    for(int i = 0; i < numOfCustomer; i++)
    {
        fwrite(cusList[i], sizeof(cusInfo), 1, fp);
    }
    fclose(fp);
}

void loadcus(void)
{
    FILE *fp = fopen("storecus.bin", "rb");
    
    if(fp == NULL)
        return;
    
    fread(&numOfCustomer, sizeof(int), 1, fp);

    for(int i = 0; i < numOfCustomer; i++)
    {
        cusList[i] = malloc(sizeof(cusInfo));
        fread(cusList[i], sizeof(cusInfo), 1, fp);
    }
    
    fclose(fp);
}
