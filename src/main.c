#include "REG52.H"
sbit buz=P2^3;
int i=8;
long int j;
// 流水灯
void flowLed(){
    P1=0x7f;
    while(--i){
        for(j=0;j<10000;j++);
        P1=~(~P1>>1);
    }
    i=8;
    while(--i){
        for(j=0;j<10000;j++);
        P1=~(~P1<<1);
    }
}
int time=0;
// c4
void c4(){
    P1=0x7f;
    i=1500;
    while(i)
    {
        buz=0;
        for(j=0;j<i;j++);
        buz=1;
        P1=~(~P1>>1);
        if(P1==0xff)
        P1=0x7f;
        for(j=0;j<i;j++);
        i-=20;
    }
    
    
}

sbit WE=P2^7;
sbit DU=P2^6;
// 数码管
int wei[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
int gy[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
void digt(){
    j=0;
    while(1){
        WE=1;
        P0=wei[j];
        WE=0;
        DU=1;
        P0=gy[j+1];
        DU=0;
        for(i=0;i<200;i++);
        j++;
        if(j==8)j=0;
    }
}

// 2023年5月29日作业
void zy1(char n[4]){
    // int arr[4];
    // arr[0]=n/1000;
    // arr[1]=n%1000/100;
    // arr[2]=n%100/10;
    // arr[3]=n%10;
    j=0;
    while(1){
        WE=1;
        P0=wei[j];
        WE=0;
        DU=1;
        P0=gy[n[j]-'0'];
        DU=0;
        for(i=0;i<200;i++);
        j++;
        if(j==4)j=0;
    }
}
void main(){
    // flowLed();
    // c4();
    zy1("2224");
}

