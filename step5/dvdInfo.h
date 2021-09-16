//
//  dvdInfo.h
//  step2
//
//  Created by hyungwook on 2021/03/05.
//

#ifndef _DVDINFO_H_
#define _DVDINFO_H_

#include "cusInfo.h"

#define ISBN_LEN 30
#define TITLE_LEN 30
#define RENT_LEN 100

enum {ACTION = 1, COMIC, SF, ROMANTIC};
enum {RENTED, RETURNED};

typedef struct _dvdInfo
{
    char ISBN[ISBN_LEN];
    char title[TITLE_LEN];
    int genre;
    int rentState;
} dvdInfo;

#endif
