//
//  cusManager.c
//  step1
//
//  Created by hyungwook on 2021/03/05.
//

#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

void RegistCustomer(void)
{
    char id[ID_LEN];
    char name[NAME_LEN];
    char phonenumber[PHONE_LEN];
    
    while(1)
    {
        printf("ID 입력: ");
        scanf("%s", id);
        
        if(IsRegistID(id) == 1)
        {
            printf("해당 ID는 사용 중에 있습니다. 다른 ID를 선택해주세요.");
        }
        
        else
            break;
    }

    printf("이름 입력: ");
    scanf("%s", name);
    printf("전화번호 입력: ");
    scanf("%s", phonenumber);
    
    if(AddCusInfo(id, name, phonenumber) == 0)
    {
        printf("저장할수 없습니다.\n");
    }
    else
        printf("가입이 완료되었습니다.\n");
}

void SearchCusInfo(void)
{
    char id[ID_LEN];
    
    printf("찾는 ID 입력: ");
    scanf("%s", id);
    cusInfo *ptr = GetCusPtrByID(id);
    
    if(ptr == NULL)
    {
        printf("찾는 ID가 없습니다.\n");
    }
    else
        ShowCustomerInfo(ptr);
}
