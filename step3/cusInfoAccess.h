//
//  cusInfoAccess.h
//  step1
//
//  Created by hyungwook on 2021/03/05.
//

#ifndef _CUSACCESS_H_
#define _CUSACCESS_H_

#include "cusInfo.h"

int AddCusInfo(char *ID, char *name, char *num);
cusInfo *GetCusPtrByID(char *ID);
int IsRegistID(char *ID);

#endif
