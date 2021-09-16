//
//  rentInfoAccess.c
//  step4
//
//  Created by hyungwook on 2021/03/05.
//

#include "common.h"
#include "rentInfo.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

#define RENT_LEN 100

static dvdRentInfo rentList[RENT_LEN];
static int numOfRentCus = 0;

void AddRentList(char *ISBN, char *cusID, int rentDay)
{
    strcpy(rentList[numOfRentCus].ISBN, ISBN);
    strcpy(rentList[numOfRentCus].cusID, cusID);
    rentList[numOfRentCus].rentDay = rentDay;
    numOfRentCus++;
}

void PrintOutRentAllCusInfo(char *ISBN)
{
    for(int i = 0; i < numOfRentCus; i++)
    {
        if(!strcmp(rentList[i].ISBN, ISBN))
            ShowRentCusAll(rentList[i]);
    }
    
    printf("조회를 완료하였습니다.\n");

}

void PrintOutCusAllRentInfo(char *ID, unsigned int start, unsigned int end)
{
    for(int i = 0; i < numOfRentCus; i++)
    {
        if(!strcmp(rentList[i].cusID, ID))
           if(rentList[i].rentDay >= start && rentList[i].rentDay <= end)
               ShowRentDvdAll(rentList[i]);
    }
    
    printf("조회를 완료하였습니다.\n");
}
