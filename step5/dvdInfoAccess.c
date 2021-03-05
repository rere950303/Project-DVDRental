//
//  dvdInfoAccess.c
//  step2
//
//  Created by hyungwook on 2021/03/05.
//

#include "common.h"
#include "dvdInfo.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

void storedvd(dvdInfo *dvdList[]);

#define MAX_DVD 100

static dvdInfo *dvdList[MAX_DVD];
static int numOfDvd = 0;

int AddDvdInfo(char *ISBN, char *title, int genre)
{
    if(numOfDvd >= 100)
        return 0;
    
    dvdList[numOfDvd] = malloc(sizeof(dvdInfo));
    
    strcpy(dvdList[numOfDvd]->ISBN, ISBN);
    strcpy(dvdList[numOfDvd]->title, title);
    dvdList[numOfDvd]->genre = genre;
    dvdList[numOfDvd]->rentState = 1;
        
    numOfDvd++;
    
    storedvd(dvdList);

    return numOfDvd;
}

dvdInfo *GetdvdPtrByISBN(char *ISBN)
{
    for(int i = 0; i < numOfDvd; i++)
    {
        if(!strcmp(dvdList[i]->ISBN, ISBN))
        {
            return dvdList[i];
        }
    }
    
    return NULL;
}

int IsRegistISBN(char *ISBN)
{
    for(int i = 0; i < numOfDvd; i++)
    {
        if(!strcmp(ISBN, dvdList[i]->ISBN))
        {
            return 1;
        }
    }
    
    return 0;
}

void RentDVD(void)
{
    char ISBN[ISBN_LEN];
    unsigned int rentDay;
    char id[ID_LEN];
    
    printf("대여 DVD ISBN 입력: ");
    scanf("%s", ISBN);
    
    dvdInfo *ptr1 = GetdvdPtrByISBN(ISBN);
    
    if(ptr1->rentState == 0)
    {
        printf("대여 중이라 대여가 불가능합니다.\n");
        return;
    }
    
    printf("대여가 가능합니다. 대여 과정을 진행합니다.\n");
    
    printf("대여 고객 ID 입력: ");
    scanf("%s", id);
    
    cusInfo *ptr2 = GetCusPtrByID(id);
    
    if(ptr2 == NULL)
    {
        printf("가입고객이 아닙니다.\n");
        return;
    }
    
    printf("대여 날짜 입력: ");
    scanf("%u", &rentDay);
    
    AddRentList(ISBN, id, rentDay);
    
    printf("대여가 완료되었습니다.\n");
}

void DvdReturn(void)
{
    char ISBN[ISBN_LEN];
    
    printf("반납 DVD ISBN 입력: ");
    scanf("%s", ISBN);
    
    dvdInfo *ptr = GetdvdPtrByISBN(ISBN);
    
    if(ptr == NULL)
    {
        printf("등록되지 않은 ISBN입니다.\n");
        return;
    }
    
    if(ptr->rentState == 1)
    {
        printf("대여되지 않은 DVD입니다.\n");
    }
    
    ptr->rentState = 1;
    
    printf("반납이 완료되었습니다.\n");
}

void DvdRentInfo(void)
{
    char ISBN[ISBN_LEN];
    
    printf("찾는 ISBN 입력: ");
    scanf("%s", ISBN);
    
    PrintOutRentAllCusInfo(ISBN);
}

void CusRentInfo(void)
{
    char id[ID_LEN];
    unsigned int start = 0;
    unsigned int end = 0;

    printf("찾는 ID 입력: ");
    scanf("%s", id);
    
    printf("대여 기간 입력: ");
    scanf("%u %u", &start, &end);
    
    PrintOutCusAllRentInfo(id, start, end);
}

void storedvd(dvdInfo *dvdList[])
{
    FILE *fp = fopen("storedvd.bin", "wb");
    
    if(fp == NULL)
        return;
    
    fwrite(&numOfDvd, sizeof(int), 1, fp);

    for(int i = 0; i < numOfDvd; i++)
    {
        fwrite(dvdList[i], sizeof(dvdInfo), 1, fp);

    }
    fclose(fp);
}

void loaddvd(void)
{
    FILE *fp = fopen("storedvd.bin", "rb");
    
    if(fp == NULL)
        return;
    
    fread(&numOfDvd, sizeof(int), 1, fp);

    for(int i = 0; i < numOfDvd; i++)
    {
        dvdList[i] = malloc(sizeof(dvdInfo));
        fread(dvdList[i], sizeof(dvdInfo), 1, fp);
    }
    
    fclose(fp);
}
