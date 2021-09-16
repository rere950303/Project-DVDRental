//
//  main.c
//  step1
//
//  Created by hyungwook on 2021/03/05.
//

#include "common.h"
#include "cusManager.h"
#include "screenOut.h"
#include "dvdInfo.h"
#include "dvdManager.h"
#include "dvdInfoAccess.h"

enum {CUS_REGIST = 1, CUS_SEARCH, DVD_REGIST, DVD_SEARCH, DVD_RENT, DVD_RETURN, DVD_RENTINFO, CUS_RENTINFO, QUIT};

int main(int argc, const char * argv[]) {
    // insert code here...
    int intputmMenu = 0;
    
    while(1)
    {
        ShowMenu();
        scanf("%d", &intputmMenu);
        fflush(stdin);
        
        switch(intputmMenu)
        {
            case CUS_REGIST:
                RegistCustomer();
                break;
            
            case CUS_SEARCH:
                SearchCusInfo();
                break;
            
            case DVD_REGIST:
                RegistDvd();
                break;
                
            case DVD_SEARCH:
                SearchDvdInfo();
                break;
            
            case DVD_RENT:
                RentDVD();
                break;
                
            case DVD_RETURN:
                DvdReturn();
                break;
                
            case DVD_RENTINFO:
                DvdRentInfo();
                break;
                
            case CUS_RENTINFO:
                CusRentInfo();
                break;
        }
        
        if(intputmMenu == QUIT)
        {
            puts("이용해 주셔서 고마워요~");
            break;
        }
    }
    
    return 0;
}
