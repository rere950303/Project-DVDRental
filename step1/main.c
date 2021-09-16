//
//  main.c
//  step1
//
//  Created by hyungwook on 2021/03/05.
//

#include "common.h"
#include "cusManager.h"
#include "screenOut.h"

enum {CUS_REGIST = 1, CUS_SEARCH, QUIT};

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
        }
        
        if(intputmMenu == QUIT)
        {
            puts("이용해 주셔서 고마워요~");
            break;
        }
    }
    
    return 0;
}
