//
//  rentInfo.h
//  step4
//
//  Created by hyungwook on 2021/03/05.
//

#ifndef _RENTINFO_H_
#define _RENTINFO_H_

#include "dvdInfo.h"
#include "cusInfo.h"

void AddRentList(char *ISBN, char *cusID, int rentDay);
void PrintOutRentAllCusInfo(char *ISBN);
void PrintOutCusAllRentInfo(char *ID, unsigned int start, unsigned int end);

typedef struct _dvdRentInfo
{
    char cusID[ID_LEN];
    char ISBN[ISBN_LEN];
    unsigned int rentDay;
} dvdRentInfo;

#endif
