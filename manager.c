#include "manager.h"
#include "product.h"


int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 별점이 4점 이상인 제품\n");
    printf("6. 별점이 2점 이하인 제품\n");
    printf("7. 저장\n");
    printf("8. 제품 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
