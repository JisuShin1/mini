#include "product.h"

int createProduct(Product *p){

        getchar();
    printf("제품명은? ");
    scanf("%s" , p->name);
    printf("중량은? ");
    scanf("%d" , &p->weight);
    printf("가격은? ");
    scanf("%d" , &p->price);
    printf("별점개수는? ");
    scanf("%d" , &p->num);
    printf("=>추가됨!");
    return 1;
}

void readProduct(Product p){
    printf("%8s %4d %4d" , p.name, p.weight, p.price);
    for(int i=0; i<p.num; i++)
    printf("★");


    printf("\n");
}

void listProduct(Product *p, int count){
    printf("\n제품명 중량 가격 별점\n");
    for(int i=0; i<count; i++){
        if(p[i].num==-1) continue;
        printf("%d " , i+1);
        readProduct(p[i]);
    }
}

int selectDataNo(Product *p, int count){
    int no;
    listProduct(p, count);
    printf("번호는(취소:0)?");
    scanf("%d" , &no);
    return no;
}

int UpdateProduct(Product *p){
    getchar();
    printf("제품명은? ");
    scanf("%s" , p->name);
    printf("중량은? ");
    scanf("%d" , &p->weight);
    printf("가격은? ");
    scanf("%d" , &p->price);
    printf("별점개수는? ");
    scanf("%d" , &p->num);
    printf("=> 수정완료!\n");
    return 1;
}

int deleteProduct(Product *p){
    int no;
    printf("정말로 삭제하시겠습니까?(삭제:1)");
    scanf("%d" , &no);
    if(no==1){
    p->name[0] = '\0';
    p->weight = -1;
    p->price = -1;
    p->num = -1;
    printf("=> 삭제됨!\n");
    }
    return 1;
}

void bestProduct(Product *p, int count){
    printf("별점이 4점 이상인 제품은\n");
    for(int i=0; i<count; i++){
        if(p[i].num >= 4){
                printf("%s: %d\n", p[i].name, p[i].num);
         }
    }
}

void worstProduct(Product *p, int count){
    printf("별점이 2점 이하인 제품은\n");
    for(int i=0; i<count; i++){
        if(p[i].num <= 2){
                printf("%s: %d\n", p[i].name, p[i].num);
        }
    }
}


void saveData(Product *p, int count){
        FILE *fp;
        fp = fopen("product.txt", "wt");

        for(int i =0; i<count; i++){
                if(p[i].weight == -1) continue;
                fprintf(fp, "%s %d %d %d\n", p[i].name, p[i].weight, p[i].price, p[i].num);
        }
        fclose(fp);
        printf("=>저장됨!\n");
}

int loadData(Product *p){
        int count =0, i=0;
        FILE *fp;
        fp = fopen("product.txt", "rt");
        if(fp == NULL){
                printf("=> 파일 없음\n");
        }else{
                for(; i<100; i++){
                        fscanf(fp, "%s", p[i].name);
                        if(feof(fp)) break;
                        fscanf(fp, "%d", &p[i].weight);
                        fscanf(fp, "%d", &p[i].price);
                        fscanf(fp, "%d", &p[i].num);
                }
                printf("=> 로딩성공!\n");
        }
        fclose(fp);

        return i;
}

void searchData(Product *p, int count){
    int sweight;
    int check =0;
    printf("찾는 제품의 중량은?\n");
    scanf("%d", &sweight);
    for(int i=0; i<count; i++){
        if(p[i].weight == sweight){
            printf("%s: %d\n", p[i].name, p[i].num);
            check =1;
        }
    }
    if (check ==0){
        printf("찾는 내용이 없습니다.");
    }
}
