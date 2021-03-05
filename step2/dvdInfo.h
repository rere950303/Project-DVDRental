//
//  dvdInfo.h
//  step2
//
//  Created by hyungwook on 2021/03/05.
//

#ifndef _DVDINFO_H_
#define _DVDINFO_H_

#define ISBN_LEN 30
#define TITLE_LEN 30

enum {ACTION = 1, COMIC, SF, ROMANTIC};

typedef struct _dvdInfo
{
    char ISBN[ISBN_LEN];
    char title[TITLE_LEN];
    int genre;
} dvdInfo;

#endif
