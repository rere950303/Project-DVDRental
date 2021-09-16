//
//  screenOut.c
//  step1
//
//  Created by hyungwook on 2021/03/05.
//

#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "screenOut.h"
#include "cusInfoAccess.h"

void ShowMenu(void)
{
    printf("----------메 뉴---------- \n");
    printf(" 1. 신규가입 \n");
    printf(" 2. 고객검색 \n");
    printf("------------------------ \n");
    printf(" 3. DVD 등록 \n");
    printf(" 4. DVD 검색 \n");
    printf("------------------------ \n");
    printf(" 5. DVD 대여 \n");
    printf(" 6. DVD 반납 \n");
    printf("------------------------ \n");
    printf(" 7. DVD 대여고객 전체 조회 \n");
    printf(" 8. 종료 \n");
    printf("------------------------ \n");
    printf("선택>> ");
}

void ShowCustomerInfo(cusInfo *pCus)
{
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n");
    printf("┃ ▶ ID: %s \n", pCus->ID);
    printf("┃ ▶ 이름: %s \n", pCus->name);
    printf("┃ ▶ 전화번호: %s \n", pCus->phoneNum);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n\n");
}

void ShowDvdInfo(dvdInfo *pDvd)
{
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n");
    printf("┃ ▶ ISBN: %s \n", pDvd->ISBN);
    printf("┃ ▶ 타이틀: %s \n", pDvd->title);
    printf("┃ ▶ 장르: "); showgenre(pDvd->genre);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n\n");
}

void showgenre(int n)
{
    switch(n)
    {
        case 1:
            printf("액션\n");
            break;
        case 2:
            printf("코믹\n");
            break;
        case 3:
            printf("SF\n");
            break;
        case 4:
            printf("로맨틱\n");
            break;
    }
}

void ShowRentCusAll(dvdRentInfo pCus)
{
    cusInfo *ptr = GetCusPtrByID(pCus.cusID);
    printf("대여일: %u\n", pCus.rentDay);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n");
    printf("┃ ▶ ID: %s \n", pCus.cusID);
    printf("┃ ▶ 이름: %s \n", ptr->name);
    printf("┃ ▶ 전화번호: %s \n", ptr->phoneNum);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n\n");
}
