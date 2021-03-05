//
//  cusInfo.h
//  step1
//
//  Created by hyungwook on 2021/03/05.
//

#ifndef _CUSINFO_H_
#define _CUSINFO_H_

#define ID_LEN 10
#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct _cusInfo
{
    char ID[ID_LEN];
    char name[NAME_LEN];
    char phoneNum[PHONE_LEN];
} cusInfo;

#endif
