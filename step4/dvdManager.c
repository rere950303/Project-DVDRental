//
//  dvdManager.c
//  step2
//
//  Created by hyungwook on 2021/03/05.
//

#include "common.h"
#include "screenOut.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"

void RegistDvd(void)
{
    char ISBN[ISBN_LEN];
    char title[TITLE_LEN];
    int genre;

    while(1)
    {
        printf("ISBN 입력: ");
        scanf("%s", ISBN);
        
        if(IsRegistISBN(ISBN) == 1)
        {
            printf("해당 ISBN는 이미 등록됬습니다.\n");
        }
        
        else
            break;
    }

    printf("제목 입력: ");
    scanf("%s", title);
    printf("장르 입력<액션 1, 코믹 2, SF 4, 로맨틱 4>: ");
    scanf("%d", &genre);
    
    if(AddDvdInfo(ISBN, title, genre) == 0)
    {
        printf("저장할수 없습니다.\n");
    }
    else
        printf("등록이 완료되었습니다.\n");
}

void SearchDvdInfo(void)
{
    char ISBN[ISBN_LEN];
    
    printf("찾는 ISBN 입력: ");
    scanf("%s", ISBN);
    dvdInfo *ptr = GetdvdPtrByISBN(ISBN);
    
    if(ptr == NULL)
    {
        printf("찾는 dvd가 없습니다.\n");
    }
    else
        ShowDvdInfo(ptr);
}
