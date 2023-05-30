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
int gya[17]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
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

/*********************** 2023年5月30日 ********************************/
// 延时
void delay(int time){
    int x,y;
    for(x=time;x>0;x--)
        for(y=114;y>0;y--);
}
// 小练习
void test(){
    int x;
    i=0;
    while(i!=8){
        // 数码管跳转
        for(j=0;j<10000;j++);
        WE=1;
        P0=wei[i];
        WE=0;
        DU=1;
        P0=gy[i+1];
        DU=0;
        // LED跳转
        P1=(0x7f>>i);
        // 蜂鸣器叫
        for(x=0;x<i+1;x++){
            for(j=0;j<500;j++)buz=0;
            for(j=0;j<500;j++)buz=1;
        }
        i++;
    }
}

// 独立键盘
sbit KEY1=P3^0;
sbit KEY2=P3^1;
void indepKey(){
    if(KEY1==0)
    {
        P1=P1>>1;
        delay(200);
        if(P1==0x00)
        P1=0xff;         
    }
    // else
    // P1=0xff;
}

// 数码管
void smg(int n){
   int num[4];
   num[0]=n/1000;
   num[1]=n%1000/100;
   num[2]=n%100/10;
   num[3]=n%10;
   for(j=0;j<4;j++){
        WE=1;
        P0=wei[j];
        WE=0;
        DU=1;
        P0=gy[num[j]];
        DU=0;
        delay(4);
   }
}

// 计数器
void counter(){
    int s=0;
    while (1)
    {
        smg(s);
        if(KEY1==0){
            delay(10);
            s++;}
        if(KEY2==0 && s!=0){
            delay(10);
            s--;}
    }
}

void main(){
    // flowLed();
    // c4();
    // zy1("0999");
    // while(1)
    // test();
    // indepKey();
    counter();
    // smg(1211);
}

