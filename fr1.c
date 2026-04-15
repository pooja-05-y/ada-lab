#include <stdio.h>

struct item{
    int p;
    int w;
    float r;
};

int main(){
    int n, c;
    printf("enter no of items");
    scanf("%d",&n);
    struct item items[n];

    for(int i=0;i<n;i++){
        printf("enter p and w for item %d",i+1);
        scanf("%d %d", &items[i].p, &items[i].w);
        items[i].r=(float)items[i].p/items[i].w;
    }
    printf("enter total capacity");
    scanf("%d",&c);

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(items[i].r<items[j].r){
                struct item temp=items[i];
                items[i]=items[j];
                items[j]=temp;
            }
        }
    }
    float totp=0.0;
    int remc=c;
    printf("selected items=");
    printf("profit\t weight\t fraction\n");

    for(int i=0;i<n;i++){
        if(remc==0)
            break;
        if(items[i].w<=remc){
            totp+=items[i].p;
            remc-=items[i].w;
            printf("%d\t %d\t1.0\n",items[i].p,items[i].w);
        }
        else{
            float f=(float)remc/items[i].w;
            totp+=items[i].p*f;
            printf("%d\t%d\t%.2f\n",items[i].p,items[i].w,f);
            remc=0;
        }
    }
    printf("max profit=%.2f\n",totp);
    return 0;
}

