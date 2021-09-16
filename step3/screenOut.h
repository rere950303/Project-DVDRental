//
//  screenOut.h
//  step1
//
//  Created by hyungwook on 2021/03/05.
//

#ifndef _SCREENOUT_H_
#define _SCREENOUT_H_

#include "cusInfo.h"
#include "dvdInfo.h"

void ShowMenu(void);
void ShowCustomerInfo(cusInfo *pCus);
void ShowDvdInfo(dvdInfo *pDvd);
void showgenre(int n);
void ShowRentCusInfo(cusInfo *pCus);
void ShowRentCusAll(dvdRentInfo pCus);

#endif
