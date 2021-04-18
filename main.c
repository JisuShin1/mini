#include <stdio.h>
#include <string.h>
#include "product.h"
#include "manager.h"

int main(){ 
    Product slist[20];
    int index=0;
    int count=0,index =0, menu;

    count = loadData(slist);
    index = count;

    while(1){
        menu=selectMenu();
        if(menu==0) {
          printf("종료됨!");
          break;
        }
        if(menu==1 || menu==3 || menu==4)
            if(count==0){   
                printf("데이터가 없습니다.\n");
                continue;
            }
        if(menu==2){
            createProduct(&slist[index++]); 
            count=1;
        }
        else if(menu==1) {
          if(count>0) listProduct(slist, index);
        }
        else if(menu==3) {
            int no = selectDataNo(slist, index);
            if (no>0)
            UpdateProduct(&slist[no-1]);
        }
        else if(menu==4) {
          int no = selectDataNo(slist, index);
          if (no>0)
          deleteProduct(&slist[no-1]);
          count=0;
        }
	else if(menu==5){
		bestProduct(slist, index);
	}
	else if(menu==6){
		worstProduct(slist, index);
	}
	else if(menu==7){
		saveData(slist, index);
	}
    }
    return 0;
}
