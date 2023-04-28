//各类工具整合版1.6.2 
#include<bits/stdc++.h>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

#define random(x) rand()%x
#define randomsize srand((unsigned)time(NULL));
using namespace std;
//=======================================================================================================================================================================
int lv,first_lv;
int chance=5;
char password[14];
string name,last_name;
string wyh[2],lht[2],zyc[2],wbc[3],cjb[2],newer[2],jkr[2],xjj[2];
char computer_number999[5];
//=======================================================================================================================================================================
int banben[4]={1,2,1,1};
bool bcdl,sxhcq;
int /*日期*/date_year,date_month,date_day,/*权限*/qx_taskkill,qx_while1,qx_timeinput,qx_killexplorer,qx_classcloud,qx_bluescreem,qx_devcpp;
string /*数据*/computer,timee,filename,cmdtype,cmd;
string /*账号密码*/nm,pw;
getdate()
{
	time_t timer;
	time(&timer);
	tm* t_tm = localtime(&timer);
	date_year=t_tm->tm_year+1900;
	date_month=t_tm->tm_mon+1;
	date_day=t_tm->tm_mday;
}
int joining()
{
	qx_taskkill=1;
	qx_while1=1;
	qx_timeinput=1;
	qx_killexplorer=1;
	qx_classcloud=1;
	qx_devcpp=1;
	qx_bluescreem=1;
/*	getdate();
	if(bcdl)
	{
		FILE * fil;
		string nm,pw;freopen("%userprofile%\\AppData\\Local\\chenfy\\dl.dat","r",fil);
		cin>>nm>>pw;
		fclose(fil);
	}*/
//	cout<<"请输入账号:";
//	cin>>nm;
//	cout<<"请输入密码:";
//	cin>>pw;
//	system("cls");
//	if (nm=="admin"&&pw=="abcd1234")
//	{
//		qx_taskkill=1;
//		qx_while1=1;
//		qx_timeinput=1;
//		qx_killexplorer=1;
//		qx_classcloud=1;
//		qx_devcpp=1;
//		qx_bluescreem=1;
//	}
//	else
//	{
//		system("cls");
//		cout<<"账号或密码错误"<<endl;
//		joining();
//	}
}
void gettime()
{
	if(qx_timeinput==1)
	{
		cout<<"请输入时间:";
		cin>>timee;
	}
	else
	{
	int aaa;
	system("cls");
	cout<<"[1] 10秒"<<endl;
	cout<<"[2] 20秒"<<endl;
	cout<<"[3] 30秒"<<endl;
	cout<<"[4] 40秒"<<endl;
	cout<<"[5] 50秒"<<endl;
	cout<<"[6] 60秒"<<endl;
	cout<<"[7] 70秒"<<endl;
	cout<<"[8] 80秒"<<endl;
	cout<<"[9] 90秒"<<endl;
	cout<<"[0] 直接关机"<<endl;
	cin>>aaa;
	if(aaa==1)
		timee="10";
	else if(aaa==2)
		timee="20";
	else if(aaa==3)
		timee="30";
	else if(aaa==4)
		timee="40";
	else if(aaa==5)
		timee="50";
	else if(aaa==6)
		timee="60";
	else if(aaa==7)
		timee="70";
	else if(aaa==8)
		timee="80";
	else if(aaa==9)
		timee="90";
	else if(aaa==0)
		timee="0";
	}
}
void getcomputer()
{
	system("cls");
	cout<<"请输入计算机名"<<endl;
	cin>>computer; 
}
void getfile()
{
	system("cls");
	cout<<"请输入文件名"<<endl;
	cin>>filename; 
}
void gettype()
{
	int aaa;
	system("cls");
	cout<<"[1] 解除关机"<<endl;
	cout<<"[2] 关机"<<endl;
	cin>>aaa;
	if (aaa==1)
		cmdtype="-a";
	else
		cmdtype="-s";
}
int shutdown()
{
	gettype();
	system("cls");
	if (cmdtype=="-a")
	{
		int bbb;
		cout<<"[1] 解除自己"<<endl;
		cout<<"[2] 解除别人"<<endl;
		cout<<"[3] 退出"<<endl;
		cin>>bbb;
		if(bbb==1)
			cmd="shutdown"+cmdtype;
		else if(bbb==2)
		{
			getcomputer();
			cmd="shutdown "+cmdtype+" -m "+computer;
		}
		else if(bbb==3)
			return 0;
	}
	else
	{
		getcomputer();
		gettime();
		cmd="shutdown "+cmdtype+" -m "+computer+" -t "+timee;
	}
}
void taskkill()
{
	getcomputer();
	getfile();
	cmd="taskkill -s "+computer+" -u test -im "+filename;
}
void tkill(string t)
{
	getcomputer();
	cmd="taskkill -s "+computer+" -u test -f -im "+t;
}
void command_tools()
{
	int bbb,w1=1;
	cout<<"[1] 关机"<<endl;
	if(qx_taskkill==1)
		cout<<"[2] 杀进程"<<endl;
	if(qx_bluescreem==1)
		cout<<"[3] 蓝屏"<<endl;
	cin>>bbb;
	system("cls");
	if (bbb==1)
		shutdown();
	else if(qx_taskkill==1&&bbb==2)
	{
		int ccc;
		cout<<"[0] 其它"<<endl;
		if(qx_killexplorer==1)
			cout<<"[1] 杀桌面"<<endl;
		if(qx_classcloud==1)
			cout<<"[2] 杀云课堂"<<endl;
		if(qx_devcpp==1)
			cout<<"[3] 杀c++"<<endl;
		cin>>ccc;
		if(qx_killexplorer==1&&ccc==0)
			taskkill();
		else if(qx_killexplorer==1&&ccc==1)
			tkill("explorer.exe");
		else if(qx_classcloud==1&&ccc==2)
			tkill("ClassManagerApp.exe");
		else if(qx_devcpp==1&&ccc==3)
			tkill("devcpp.exe");
	}
	else if(qx_bluescreem==1&&bbb==3)
	{
		tkill("wininit.exe");
		w1=2;
	}
	system("cls");
	const char *abc = cmd.c_str();
	if(w1==1)
	{
		cout<<"[1] 运行1次"<<endl;
		if(qx_while1==1)
			cout<<"[2] 死循环"<<endl;
		cin>>bbb;
	}
//	if(w1==2)
//		system("start \"\" resta.bat");
	if (bbb==1||w1==0||w1==2)
		system(abc);
	else if(qx_while1==1)
		{
//			system("start \"\" resta.bat");
			while (1)
				system(abc);
		}
	system("cls");
}
void randd()
{
	srand((unsigned)time( NULL ));
	int l,r,n,f;
	char b;
	cout<<"请输入区间(两个数)"<<endl;
	cin>>l>>r;
	f=abs(l-r)+1;
	system("cls");
	cout<<"请输入随机数个数"<<endl;
	cin>>n;
	system("cls");
	cout<<"是否有特殊值(Y / N)"<<endl;
	cin>>b;
	system("cls");
	if(b=='Y'||b=='y')
	{
		int t,tsz[100005],temp; 
		cout<<"请输入特殊值个数"<<endl;
		cin>>t;
		t=abs(t);
		f+=t;
		system("cls");
		cout<<"请输入特殊值"<<endl;
		for(int i=1;i<=t;i++)
			cin>>tsz[i];
		system("cls");
		for(int i=1;i<=n;i++)
		{
			temp=random(f)+l;
			if(temp>r)
				temp=tsz[temp-r];
			cout<<temp<<"  ";
		}
				
	}
	else if(b=='N'||b=='n')
	{
		for(int i=1;i<=n;i++)
			cout<<random(f)+l<<"  ";
	}
	cout<<endl<<"随机完成，按任意键退出";
	system("pause>nul");
}
void seat()
{
	int a,b,x,c;
	cout<<"请输入机房(7或8):";
	cin>>c;
	system("cls");
	cout<<"请输入行(从窗户往门数)"<<endl;
	cin>>a;
	system("cls");
	cout<<"请输入列(从前往后数)"<<endl;
	cin>>b;
	system("cls");
	if(c==7&&a*10+b>3)
	{
		x=a*10+b-2;
		if(x%10==0)
			x-=1;
	}
	else
		x=a*10+b;
	if(c==7)
		for(int i=1;i<=10;i++)
			cout<<"ta的计算机号是:s-0"<<x<<endl;
	else if(c==8)
		for(int i=1;i<=10;i++)
			cout<<"ta的计算机号是:stu-0"<<x<<endl;
	system("pause>nul");
}
void aboutus()
{
	cout<<"版本号";
	cout<<banben[0];
	for(int i=1;i<=3;i++)
		cout<<"."<<banben[i];
	cout<<endl;
	cout<<"               制作:chenfy";
	system("pause>nul");
}
/*int setting()
{
	int bbb;
	cout<<"[1] 保持登陆                   "<<endl;
	if(bcdl==true)
		cout<<"开";
	else
		cout<<"关";
	cout<<"[2] 死循环时重新运行该程序     "<<endl;
	if(sxhcq==true)
		cout<<"开";
	else
		cout<<"关";
	cout<<"[0] 退出"<<endl;
	cin>>bbb;
	if(bbb!=1&&bbb!=2)
		return 0;
	else if(bbb==1)
		bcdl=1-bcdl;
	else if(bbb==2)
		sxhcq=1-sxhcq;
	string abc,acb;
	if(bcdl)
		acb="1";
	else
		acb="0";
	abc="echo "+acb+">%userprofile%\\AppData\\Local\\chenfy\\settings.dat";
	const char *abc1 = abc.c_str();
	if(sxhcq)
		acb="1";
	else
		acb="0";
	abc="echo "+acb+">>%userprofile%\\AppData\\Local\\chenfy\\settings.dat";
	const char *abc2 = abc.c_str();
	system(abc1);
	system(abc2);
	if(bcdl)
	{
		abc="echo "+nm+">%userprofile%\\AppData\\Local\\chenfy\\dl.dat";
		const char *abc1 = abc.c_str();
		abc="echo "+pw+">>%userprofile%\\AppData\\Local\\chenfy\\dl.dat";
		const char *abc2 = abc.c_str();
	}
	
}*/
void stool()
{
	joining();
	string x;
	while(1)
	{
		cout<<"[1] 命令小工具"<<endl;
		cout<<"[2] 查询计算机号(金外机房)"<<endl;
		cout<<"[3] 随机数"<<endl;
		cout<<"[a] 关于"<<endl;
//		cout<<"[s] 设置"<<endl;
		cin>>x;
		system("cls");
		if(x=="1")
			command_tools();
		else if(x=="2")
			seat();
		else if(x=="3")
			randd();
		else if(x=="a")
			aboutus();
/*		else if(x=="s")
			setting();*/
		system("cls");
	}
}
//======================================================================================================================================================================
void gr(){
	if(computer_number999[1]==0) scanf("%s",&computer_number999);
	char qian[20]="shutdown -m stu-0";
    char hou[10]=" -s -t 0";
	system(strcat(strcat(qian,computer_number999),hou));
	gr();
}
//=======================================================================================================================================================================
void jinzz10()
{
MessageBox(NULL,"金钟罩已启动！\n 已为你防止意外关机 ","———金钟罩1.0 ———",MB_OK);   
while(1){
        system("shutdown -a");
    }
    return;
}
//=======================================================================================================================================================================
void jinzz111()
{
    
MessageBox(NULL,"金钟罩已启动！\n 已为你防止意外关机 ","———金钟罩1.1A ———",MB_OK);
    while(1){
        system("shutdown -s -t 100000");
        Sleep(1000);
        system("shutdown -a");
    }
    return;
}
//=======================================================================================================================================================================
void jinzz112() 
{
    MessageBox(NULL,"金钟罩已启动！\n 已为你防止来自小工具的关机 ","———金钟罩1.1B ———",MB_OK);
    while(1){
        system("shutdown -s -t 1000000");
    }
    return;
}
//=======================================================================================================================================================================
void jinzz113()
{
	MessageBox(NULL,"金钟罩已启动！\n 已为你防止来自小工具的关机 ","———金钟罩1.1C ———",MB_OK);
	system("shutdown -a");
	while(1){
		system("shutdown -s -t 100000000");
	}
} 
//=======================================================================================================================================================================
void f_jzz12()
{
    system("shutdown -a");
    f_jzz12();
    return;
}
//=======================================================================================================================================================================
void jinzz12()
{
    MessageBox(NULL,"金钟罩已启动！\n 已为你防止意外关机 ","———金钟罩1.2———",MB_OK);
    f_jzz12();
    return;
}

//======================================================================================================================================================================= 
void liandianqi()
{
	int now=0,k=0;    
    int time;
	printf("请输入每秒点击次数,输入-1点到极限 \n");
	cin>>time;
	if(time==-1){
		system("cls");
        printf("按 N 自动连续点击左键，按 Enter 停止\n");
        while(1){    
        if(KEY_DOWN(78)){
            now=1;        
        }
        if(KEY_DOWN(13)){
            now=0;    
        }
        if(now==1){   
            mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
            mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);  
        }     
    }
	}
	else time=1000/time;
	system("cls");
    printf("按 N 自动连续点击左键，按 Enter 停止\n");
    while(1){    
        if(KEY_DOWN(78)){
            now=1;     
            Sleep(100);   
        }
        if(KEY_DOWN(13)){
            now=0;    
            Sleep(100);
        }
        if(now==1){   
            mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
            Sleep(time);
            mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);  
        }  
        Sleep(1);    
    }    
}
//=======================================================================================================================================================================
void name_password()
{
//	C++控制台程序运行时输出框默认的文字颜色是白色，所以我常称其输出框为黑白框。但是这个文字样式不是固定不变的，是可以改变颜色的字体的。方法有两种：
//一、设置输出框的框体属性。在运行时弹出的输出框标题栏上点击右键设置它的属性，可以调节数表中使用两个属性（属性之间用，隔开）。GetStdHandle()和FOREGROUND_或BACKGROUND_。*值为INTENSITY或RED或GREEN或BLUE。第一个属性获得句柄（即要设置颜色的地方），第二个属性设置颜色。属性相加是在属性值中间加“|”隔开即可。
//GetStdHandle(STD_OUTPUT_HANDLE)获得句柄。输出框的大小、背景色、文字颜色等属性。但是这种设置只能在自己的机子上运行显示。在其他人的机子上是没有用的。这里不做重点介绍。
//二、用代码修改。这里介绍C++中用代码修改输出框显示文字的颜色。具体代码是调用一个函数SetConsoleTextAttribute(参数表)。
//SetConsoleTextAttribute()函数是一个API设置字体颜色和背景色的函数。参
//FOREGROUND_INTENSITY 表示设置前景色为高亮显示。
//FOREGROUND_RED 表示设置前景色为红色，即字体颜色为红色。
//FOREGROUND_GREEN 表示设置前景色为绿色，即字体颜色为绿色。
//FOREGROUND_BLUE 表示设置前景色为蓝色，即字体颜色为蓝色。
//BACKGROUND_INTENSITY 表示设置背景色为高亮显示。
//BACKGROUND_RED 表示设置背景色为红色。
//BACKGROUND_GREEN 表示设置背景色为绿色。
//BACKGROUND_BLUE 表示设置背景色为蓝色。
//…… …… …… …… …… ……
//说明：在使用时要在预处理中包含window.h头文件
    Sleep(300);
    printf("请输入用户名：\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY |FOREGROUND_INTENSITY);
    cin>>name;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY |FOREGROUND_INTENSITY | BACKGROUND_INTENSITY |BACKGROUND_INTENSITY |BACKGROUND_INTENSITY |FOREGROUND_INTENSITY);
    int f1=0;
    if(name==wyh[0]){
            f1=1;
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            printf("请输入密码:\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY |FOREGROUND_INTENSITY);
            cin>>password;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            if(password==wyh[1]) {
                  printf("\n====================================\n ");
                  printf("欢迎登陆 管理员 王艺涵 \n");
                  last_name="王艺涵";
                  lv=5;
                  return;
            }
            else {
                  chance=chance-1;
                  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                  printf("密码错误，1:重试（还有 %d 次机会）  2:直接进入(默认)\n",chance);  
                  int l1;
                  scanf("%d",&l1);
                  if((l1==1)&&(chance!=0)) name_password();
                  else {
                     lv=0;
                     last_name="客人用户";
                     printf("客人登陆\n");
                     return;
                  }
            }
        }
    if(name==xjj[0]){
            f1=1;
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            printf("请输入密码:\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY |FOREGROUND_INTENSITY);
            cin>>password;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            if(password==xjj[1]) {
                  printf("\n====================================\n ");
                  printf("欢迎登陆 管理员 项佳俊 \n");
                  last_name="项佳俊";
                  lv=5;
                  return;
            }
            else {
                  chance=chance-1;
                  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                  printf("密码错误，1:重试（还有 %d 次机会）  2:直接进入(默认)\n",chance);  
                  int l1;
                  scanf("%d",&l1);
                  if((l1==1)&&(chance!=0)) name_password();
                  else {
                     lv=0;
                     last_name="客人用户";
                     printf("客人登陆\n");
                     return;
                  }
            }
        }
    if(name==lht[0]) {
            f1=1; 
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            printf("请输入密码:\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY |FOREGROUND_INTENSITY);
            cin>>password;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            if(password==lht[1]) {
                printf("\n=====================================\n ");
                printf("欢迎登陆 罗浩天 \n");
                last_name="罗浩天";
                lv=5;
                return;
            }
            else {
                  chance=chance-1;
                  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                  printf("密码错误，1:重试（还有 %d 次机会）  2:直接进入(默认)\n",chance);  
                  int l1;
                  scanf("%d",&l1);
                  if((l1==1)&&(chance!=0)) name_password();
                  else {
                     lv=0;
                     last_name="客人用户";
                     printf("客人登陆\n");
                     return;
                  }
            }
        }
    if(name==zyc[0]){
            f1=1;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            printf("请输入密码:\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY |FOREGROUND_INTENSITY);
            cin>>password;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                printf("\n=====================================\n ");   
                printf("欢迎登陆 祝宇辰 \n");
                last_name="祝宇辰";
                lv=4;
                return;
            }
            else {
                  chance=chance-1;
                  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                  printf("密码错误，1:重试（还有 %d 次机会）  2:直接进入(默认)\n",chance);  
                  int l1;
                  scanf("%d",&l1);
                  if((l1==1)&&(chance!=0)) name_password();
                  else {
                     lv=0;
                     last_name="客人用户";
                     printf("客人登陆\n");
                     return;
                  }
            }
    if(name==wbc[0]){
            f1=1;
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            printf("请输入密码:\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY |FOREGROUND_INTENSITY);
            cin>>password;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            if(password==wbc[1]) {
                  printf("\n====================================\n ");
                  printf("欢迎登陆  王博诚 \n");
                  last_name="王博诚";
                  lv=4;
                  return;
            }
            else {
                  chance=chance-1;
                  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                  printf("密码错误，1:重试（还有 %d 次机会）  2:直接进入(默认)\n",chance);  
                  int l1;
                  scanf("%d",&l1);
                  if((l1==1)&&(chance!=0)) name_password();
                  else {
                     lv=0;
                     last_name="客人用户";
                     printf("客人登陆\n");
                     return;
                  }
            }
        }   
        
    /*if(name==wbc[0]){
              f1=1;
              SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            printf("请输入密码:\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY |FOREGROUND_INTENSITY);
            cin>>password;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
              if(password==wbc[1]) {
                  printf("\n====================================\n ");
                  printf("欢迎登陆 王博诚\n");
                  last_name="王博诚";
                  lv=4;
                  return;
              }
              else {
                  chance=chance-1;
                  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                  printf("密码错误，1:重试（还有 %d 次机会）  2:直接进入(默认)\n",chance);  
                  int l1;
                  scanf("%d",&l1);
                  if((l1==1)&&(chance!=0)) name_password();
                  else {
                     lv=0;
                     last_name="客人用户";
                     printf("客人登陆\n");
                     return;
                  }
            }
        }  */
    if(name==cjb[0]){
    	f1=1;
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            printf("请输入密码:\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY |FOREGROUND_INTENSITY);
            cin>>password;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    	if(password==cjb[1]){
    		printf("\n====================================\n ");
    		printf("欢迎登录 班长 陈俊博\n");
    		last_name="陈俊博";
			lv=4; 
			return;
		}
		else{
			chance=chance-1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("密码错误，1:重试（还有 %d 次机会）  2:直接进入(默认)\n",chance);
			int l1;
			scanf("%d",&l1);
			if((l1==1)&&(chance!=0)) name_password();
			else lv=0;
			last_name="客人用户";
			printf("客人登入\n"); 
			return;
		}
	}
	if(name==jkr[0]){
    	f1=1;
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            printf("请输入密码:\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY |FOREGROUND_INTENSITY);
            cin>>password;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    	if(password==jkr[1]){
    		printf("\n====================================\n ");
    		printf("欢迎登录 老金\n");
    		last_name="金凯瑞";
			lv=4; 
			return;
		}
		else{
			chance=chance-1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("密码错误，1:重试（还有 %d 次机会）  2:直接进入(默认)\n",chance);
			int l1;
			scanf("%d",&l1);
			if((l1==1)&&(chance!=0)) name_password();
			else lv=0;
			last_name="客人用户";
			printf("客人登入\n"); 
			return;
		}
	}
	if(name==newer[0]){
    	f1=1;
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            printf("请输入密码:\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY |FOREGROUND_INTENSITY);
            cin>>password;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    	if(password==newer[1]){
    		printf("\n====================================\n ");
    		printf("欢迎登录 新人\n");
    		last_name="新人临时账号";
			lv=3; 
			return;
		}
		else{
			chance=chance-1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("密码错误，1:重试（还有 %d 次机会）  2:直接进入(默认)\n",chance);
			int l1;
			scanf("%d",&l1);
			if((l1==1)&&(chance!=0)) name_password();
			else lv=0;
			last_name="客人用户";
			printf("客人登入\n"); 
			return;
		}
	}
    if(f1==0) {
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf("不存在此用户\n");
        chance=chance-1;
        printf("1:重试（还有 %d 次机会）  2:直接进入(默认)\n",chance); 
          int l2;
        scanf("%d",&l2);
        if((l2==1)&&(chance!=0)) name_password();
        else{
            lv=0;
            last_name="客人用户";
            printf("客人登入\n");
            return;
        }
    }
    if(f1==0) {
        printf("不存在此用户\n");
        printf("1:重试（还有 %d 次机会）  2:直接进入(默认)\n",chance); 
          int l2;
        scanf("%d",&l2);
        if((l2==1)&&(chance!=0)) name_password();
        else{
            lv=0;
            last_name="客人用户";
            printf("客人登入\n");
            return;
        }
    }
    return;
}
//=======================================================================================================================================================================
int main()
{
	system("color 00");
    wyh[0]="wyh2007";
    wyh[1]="070115wbb";
    lht[0]="luohaotian";
    lht[1]="2019430";
    zyc[0]="zhuyuchen";
    zyc[1]="2019447";
    wbc[0]="wangbocheng";
    wbc[1]="2019433";
    cjb[0]="chenjunbo";
    cjb[1]="2019423";
    jkr[0]="jinkairui";
    jkr[1]="2019391";
    xjj[0]="xiangjiajun";
    xjj[1]="77778888";
    newer[0]="xinren";
    newer[1]="123456";//新人临时账号 
    system("TITLE 各类工具整合版1.6.2"); 
    printf("各类工具整合版1.6.2 \n");
    Sleep(500);
    printf("1:正常登入(默认)   2:客人登入 \n");
    int g;
    scanf("%d",&g);
    system("cls");
    if(g==2){
    	lv=0;
        last_name="客人用户";
        printf("客人登入\n");
	}
	else name_password();
	Sleep(1000);
    system("cls");
	system("color 07");
	if(name==wyh[0]) system("color 0f");
	if(name==lht[0]) system("color 1a");
	if(name==zyc[0]) system("color 8c");
	if(name==wbc[0]) system("color 7f");
    printf("各类工具整合版1.6.2 \n");
    printf("\n=========================用户协议======================== \n");
    printf("                                                   (必须仔细观看）                                \n");
    Sleep(500);
    printf("     此程序仅作为威慑工具，用于维护信息课的安宁和震慑故意骚扰他人的\n");
    printf("危险分子,仅在他们有危险举动时采取强硬措施，为了防止用户滥用此程序,\n");
    printf("我们对用户提出以下要求：                                                                          \n");
    Sleep(500);
    printf("1、不随意或因私人原因攻击他人电脑，尽量不要发起大规模的攻击，防止误伤；                           \n");
    printf("2、禁止攻击老师；                                                                                 \n");
    printf("3、禁止泄露自己的账号密码；                                                                       \n");
    printf("4、在条件允许的情况下可在下课时发起任意攻击 ；                                                    \n");
    printf("5、机号查询有错误的可能，请勿只根据此发动攻击，以免误伤。                                         \n");
    Sleep(500);
    printf("    同意之后，请信守承诺。如因违反协议而被惩罚，作者拒不承担一切责任                              \n");
    printf("          1:同意（默认）   2:不同意                                                               \n");
    int xy;
    scanf("%d",&xy);
    if(xy==2) {
        printf("我们认为您不适合拥有权限，已撤除权限 \n");
        lv=0;
    }
    first_lv=lv;
    system("cls");
    printf("各类工具整合版1.6.2 \n");
//=======================================================================================================================================================================
    while(1){
    	printf("================================================\n");
        printf("\n 1:操作自己   2:攻击    3:防御    4:保护 \n 5:查询计算机号    6:个人信息与版本    7:检查账号 \n 8:个性化与设置   9:帮助   10:其他工具 \n快捷键: 0:清屏 \n");
        if((name=="wyh2007")&&(lv==5)) printf("隐藏功能: 11:备忘录   12:打印源代码   13:发消息   14:管理员空间 \n"); 
        int l3;
        scanf("%d",&l3);
        printf("================================================\n");
        switch(l3){
        	case 0:{
        		system("cls");
				break;
			}
            case 1:{
                Sleep(1000);
                printf("1:立刻关机   2:定时关机   3:注销   4:蓝屏  5:返回\n");
                int l4;
                scanf("%d",&l4);
                if(l4==1) system("shutdown -s -t 0");
                if(l4==3) system("shutdown -f");
                if(l4==4) system("taskkill /f /im csrss.exe");
                if(l4==5) break;
                if(l4==2){
                    printf("请输入关机的秒数(0～999） \n");
                    char l5[5]="0";
                    char gj[20]="shutdown -s -t ";
                    scanf("%s",&l5);
					system(strcat(gj,l5));
					printf("你的电脑将在 %s 秒后关机 \n",l5);
                }
                break;
            }
            case 2:{
                if(lv<=2) {printf("权限不够！\n");break;} 
                else {
                    Sleep(1000);
                    printf("\n 决斗时间到！ \n\n");
                    Sleep(500);
                    printf("1:远程关机   2:打开图形用户界面   3:循环关机   4:极端   5:骚扰 \n6:打开cmd  7:无限递归关机  8:自由输入指令  9:返回\n");
                    int l8;
                    scanf("%d",&l8);
                    if(l8==9) break; 
                    if(l8==2) system("shutdown -i");
                    if(l8==6) system("start cmd");
                    if(l8==8){
                    	printf("请输入cmd指令(50个字符以内,输入/结束) \n");
                    	char z[53],z1;
                    	for(int i=0;i<=49;i++){
                    		scanf("%c",&z1);
							if(z1=='/') break;
							else z[i]=z1; 
						}
                    	system(z);
					} 
                    if(l8==7) if(lv<=3) {
					    printf("权限不够！");
						break;
					}
                        else {
							printf("请输入电脑编号：\n");
                            printf("(只需输入数字部分，如stu-015只需输入15 stu-004要输入04)\n");
					        gr();
				        }
					if(l8==5) {
						printf("请输入电脑编号: \n");
						printf("(只需输入数字部分，如stu-015只需输入15,stu-004要输入04)\n");
						char computer_number[5];
						scanf("%s",&computer_number);
	                    char qian1[20]="shutdown -m stu-0";
                        char hou1[10]=" -s -t 2";
                        char hou2[5]=" -a";
                        printf("1:骚扰一次    2:循环 \n");
                        int l15;
                        scanf("%d",&l15);
                        if(l15==1){
                        	system(strcat(strcat(qian1,computer_number),hou1));
	                        Sleep(1000);
	                        system(strcat(strcat(qian1,computer_number),hou2));
						}
	                    if(l15==2){
	                    	printf("\n 请输入循环次数:(键入0死循环) \n");
	                    	int l22;
	                    	scanf("%d",&l22);
	                    	if(l22==0){
	                    		while(1){
	                    		system(strcat(strcat(qian1,computer_number),hou1));
	                            Sleep(1000);
	                            system(strcat(strcat(qian1,computer_number),hou2));
							    }
							}
	                    	else for(int i=1;i<=l22;i++){
	                    		system(strcat(strcat(qian1,computer_number),hou1));
	                            Sleep(1000);
	                            system(strcat(strcat(qian1,computer_number),hou2));
							}
						}
					}
                    if(l8==1) {
                        printf("请输入电脑编号：\n");
                        printf("(只需输入数字部分，如stu-015只需输入15,stu-004要输入04)\n");
                        char computer_number[5];
						scanf("%s",&computer_number);
	                    char qian1[20]="shutdown -m stu-0";
                        char hou1[10]=" -s -t 0";
                        char hou2[5]=" -a";
                        printf("请输入时间(秒) \n");
                        int l17;
                        scanf("%s",&l17);
                        Sleep(l17*1000);
	                    system(strcat(strcat(qian1,computer_number),hou2));
	                    system(strcat(strcat(qian1,computer_number),hou1));
	                    printf("stu-0%d 已被关机 \n",computer_number);
						Sleep(500); 
                    }
                    if(lv<=3) {printf("权限不够！");break;}
                    else if(l8==3) {
                        printf("请输入电脑编号：\n");
                        printf("(只需输入数字部分，如stu-015只需输入15,stu-004要输入04)\n");
                        printf("输入0返回\n");
                        char computer_number[5];
                        scanf("%s",&computer_number);
                        if(computer_number=="0") break;
                        char qian1[20]="shutdown -m stu-0";
                        char hou1[10]=" -s -t 0";
                        char hou2[5]=" -a"; 
                        printf("请输入时间(秒) \n");
						int l16;
						scanf("%d",&l16);
						printf("请输入循环次数: (键入0死循环)\n");
						int l21;
						scanf("%d",&l21);
						Sleep(l16*1000);
	                    system(strcat(strcat(qian1,computer_number),hou2));
	                    if(l21==0) while(1) system(strcat(strcat(qian1,computer_number),hou1));
	                    else for(int i=1;i<=l21;i++) system(strcat(strcat(qian1,computer_number),hou1));
                    }
                    if(l8==4){
                        if(lv<=3) {printf("权限不够！");break;}
                        else {
                            printf("1:关机所有   2:死循环关机所有 (包括自己,相当于同归于尽，除非打开金钟罩1.1B，不到紧要关头千万别用!)  3:返回 \n");
                            int l9;
                            scanf("%d",&l9);
                            if(l9==3) break;
                            if(l9==1){
                                if(MessageBox(NULL,"警告!确定要继续吗？\n关机所有电脑","＊＊警告＊＊",MB_ICONWARNING|MB_YESNO)==IDYES){
								
                                system("shutdown -s -t 10000000"); 
                                system("shutdown -m stu-001 -s -t 0");
                                system("shutdown -m stu-002 -s -t 0");
                                system("shutdown -m stu-003 -s -t 0");
                                system("shutdown -m stu-004 -s -t 0");
                                system("shutdown -m stu-005 -s -t 0");
                                system("shutdown -m stu-006 -s -t 0");
                                system("shutdown -m stu-007 -s -t 0");
                                system("shutdown -m stu-008 -s -t 0");
                                system("shutdown -m stu-009 -s -t 0");
                                system("shutdown -m stu-010 -s -t 0");
                                system("shutdown -m stu-011 -s -t 0");
                                system("shutdown -m stu-012 -s -t 0");
                                system("shutdown -m stu-013 -s -t 0");
                                system("shutdown -m stu-014 -s -t 0");
                                system("shutdown -m stu-015 -s -t 0");
                                system("shutdown -m stu-016 -s -t 0");
                                system("shutdown -m stu-017 -s -t 0");
                                system("shutdown -m stu-018 -s -t 0");
                                system("shutdown -m stu-019 -s -t 0");
                                system("shutdown -m stu-020 -s -t 0");
                                system("shutdown -m stu-021 -s -t 0");
                                system("shutdown -m stu-022 -s -t 0");
                                system("shutdown -m stu-023 -s -t 0");
                                system("shutdown -m stu-024 -s -t 0");
                                system("shutdown -m stu-025 -s -t 0");
                                system("shutdown -m stu-026 -s -t 0");
                                system("shutdown -m stu-027 -s -t 0");
                                system("shutdown -m stu-028 -s -t 0");
                                system("shutdown -m stu-029 -s -t 0");
                                system("shutdown -m stu-030 -s -t 0");
                                system("shutdown -m stu-031 -s -t 0");
                                system("shutdown -m stu-032 -s -t 0");
                                system("shutdown -m stu-033 -s -t 0");
                                system("shutdown -m stu-034 -s -t 0");
                                system("shutdown -m stu-035 -s -t 0");
                                system("shutdown -m stu-036 -s -t 0");
                                system("shutdown -m stu-037 -s -t 0");
                                system("shutdown -m stu-038 -s -t 0");
                                system("shutdown -m stu-039 -s -t 0");
                                system("shutdown -m stu-040 -s -t 0");
                                system("shutdown -m stu-041 -s -t 0");
                                system("shutdown -m stu-042 -s -t 0");
                                system("shutdown -m stu-043 -s -t 0");
                                system("shutdown -m stu-044 -s -t 0");
                                system("shutdown -m stu-045 -s -t 0");
                                system("shutdown -m stu-046 -s -t 0");
                                system("shutdown -m stu-047 -s -t 0");
                                system("shutdown -m stu-048 -s -t 0");
                                system("shutdown -m stu-049 -s -t 0");
                                system("shutdown -m stu-050 -s -t 0");
                                system("shutdown -m stu-051 -s -t 0");
                                system("shutdown -m stu-052 -s -t 0");
                                system("shutdown -m stu-053 -s -t 0");
                                system("shutdown -m stu-054 -s -t 0");
                                system("shutdown -m stu-055 -s -t 0");
                                system("shutdown -m stu-056 -s -t 0");
                                system("shutdown -m stu-057 -s -t 0");
                                system("shutdown -m stu-058 -s -t 0");
                                system("shutdown -m stu-059 -s -t 0");
                                system("shutdown -m stu-060 -s -t 0");
                                system("shutdown -m stu-061 -s -t 0");
                                system("shutdown -m stu-062 -s -t 0");
                                system("shutdown -m stu-063 -s -t 0");
                                system("shutdown -m stu-064 -s -t 0");
                                system("shutdown -m stu-065 -s -t 0");
                                system("shutdown -m stu-066 -s -t 0");
                                system("shutdown -m stu-067 -s -t 0");
                                system("shutdown -m stu-068 -s -t 0");
                                system("shutdown -a");
                            }
                            }
                            if(l9==2){
                                if(MessageBox(NULL,"警告!确定要继续吗？\n关机所有电脑","＊＊警告＊＊",MB_ICONWARNING|MB_YESNO)==IDYES){
								
                                while(1){
                                	system("shutdown -s -t 10000000");
                                    system("shutdown -m stu-001 -s -t 0");
                                    system("shutdown -m stu-002 -s -t 0");
                                    system("shutdown -m stu-003 -s -t 0");
                                    system("shutdown -m stu-004 -s -t 0");
                                    system("shutdown -m stu-005 -s -t 0");
                                    system("shutdown -m stu-006 -s -t 0");
                                    system("shutdown -m stu-007 -s -t 0");
                                    system("shutdown -m stu-008 -s -t 0");
                                    system("shutdown -m stu-009 -s -t 0");
                                    system("shutdown -m stu-010 -s -t 0");
                                    system("shutdown -m stu-011 -s -t 0");
                                    system("shutdown -m stu-012 -s -t 0");
                                    system("shutdown -m stu-013 -s -t 0");
                                    system("shutdown -m stu-014 -s -t 0");
                                    system("shutdown -m stu-015 -s -t 0");
                                    system("shutdown -m stu-016 -s -t 0");
                                    system("shutdown -m stu-017 -s -t 0");
                                    system("shutdown -m stu-018 -s -t 0");
                                    system("shutdown -m stu-019 -s -t 0");
                                    system("shutdown -m stu-020 -s -t 0");
                                    system("shutdown -m stu-021 -s -t 0");
                                    system("shutdown -m stu-022 -s -t 0");
                                    system("shutdown -m stu-023 -s -t 0");
                                    system("shutdown -m stu-024 -s -t 0");
                                    system("shutdown -m stu-025 -s -t 0");
                                    system("shutdown -m stu-026 -s -t 0");
                                    system("shutdown -m stu-027 -s -t 0");
                                    system("shutdown -m stu-028 -s -t 0");
                                    system("shutdown -m stu-029 -s -t 0");
                                    system("shutdown -m stu-030 -s -t 0");
                                    system("shutdown -m stu-031 -s -t 0");
                                    system("shutdown -m stu-032 -s -t 0");
                                    system("shutdown -m stu-033 -s -t 0");
                                    system("shutdown -m stu-034 -s -t 0");
                                    system("shutdown -m stu-035 -s -t 0");
                                    system("shutdown -m stu-036 -s -t 0");
                                    system("shutdown -m stu-037 -s -t 0");
                                    system("shutdown -m stu-038 -s -t 0");
                                    system("shutdown -m stu-039 -s -t 0");
                                    system("shutdown -m stu-040 -s -t 0");
                                    system("shutdown -m stu-041 -s -t 0");
                                    system("shutdown -m stu-042 -s -t 0");
                                    system("shutdown -m stu-043 -s -t 0");
                                    system("shutdown -m stu-044 -s -t 0");
                                    system("shutdown -m stu-045 -s -t 0");
                                    system("shutdown -m stu-046 -s -t 0");
                                    system("shutdown -m stu-047 -s -t 0");
                                    system("shutdown -m stu-048 -s -t 0");
                                    system("shutdown -m stu-049 -s -t 0");
                                    system("shutdown -m stu-050 -s -t 0");
                                    system("shutdown -m stu-051 -s -t 0");
                                    system("shutdown -m stu-052 -s -t 0");
                                    system("shutdown -m stu-053 -s -t 0");
                                    system("shutdown -m stu-054 -s -t 0");
                                    system("shutdown -m stu-055 -s -t 0");
                                    system("shutdown -m stu-056 -s -t 0");
                                    system("shutdown -m stu-057 -s -t 0");
                                    system("shutdown -m stu-058 -s -t 0");
                                    system("shutdown -m stu-059 -s -t 0");
                                    system("shutdown -m stu-060 -s -t 0");
                                    system("shutdown -m stu-061 -s -t 0");
                                    system("shutdown -m stu-062 -s -t 0");
                                    system("shutdown -m stu-063 -s -t 0");
                                    system("shutdown -m stu-064 -s -t 0");
                                    system("shutdown -m stu-065 -s -t 0");
                                    system("shutdown -m stu-066 -s -t 0");
                                    system("shutdown -m stu-067 -s -t 0");
                                    system("shutdown -m stu-068 -s -t 0");
                                    system("shutdown -a");
                                }
                            }
                            } 
                        }
                    }
                }
                break;
            }
            case 3:{
                Sleep(1000);
                printf("1:解除关机   2:金钟罩系列   3:返回 \n");
                int l6; 
                scanf("%d",&l6);
                if(l6==1) system("shutdown -a");
                if(l6==3) break; 
                if(l6==2){
                    if(lv<=1) {printf("权限不够！\n");break;}
                    else {
                        printf("1:金钟罩1.0(死循环版) \n");
                        printf("2:金钟罩1.1A(鬼畜版) \n");
                        printf("3:金钟罩1.1B小工具专用 \n");
                        printf("4:金钟罩1.1C升级版  \n");
                        printf("5:金钟罩1.2(无限递归)\n");
                        printf("请选择调用的版本：\n");
                        printf("6:返回\n");
                        int l7;
                        scanf("%d",&l7);
                        if(l7==6) break;
                        if(l7==1) jinzz10();
                        if(l7==2) jinzz111();
                        if(l7==3) jinzz112();
                        if(l7==4) jinzz113();
                        if(l7==5) jinzz12();
                    }
                }
                break;
            }
            case 4:{
            	if(lv<=2) printf("权限不够!\n");
            	else{
            		printf("1:保护他人    2:循环保护他人    3:保护所有   4:对他人使用金钟罩1.1B \n");
            	    int l13;
                	scanf("%d",&l13);
                	switch(l13){
                		case 1:{
                			printf("请输入要保护的电脑号:\n");
                			printf("(只需输入数字部分，如stu-015只需输入15,stu-004要输入04)");
                			char computer_number[5];
					    	scanf("%s",&computer_number);
	                        char qian1[20]="shutdown -m stu-0";
                            char hou2[5]=" -a";
	                        system(strcat(strcat(qian1,computer_number),hou2));
							break;
						}
						case 2:{
							printf("请输入要保护的电脑号:\n");
                			printf("(只需输入数字部分，如stu-015只需输入15,stu-004要输入04)");
                			char computer_number[5];
					    	scanf("%s",&computer_number);
					    	printf("请输入循环次数:(键入0死循环) \n");
					    	int l23;
					    	scanf("%d",&l23);
	                        char qian1[20]="shutdown -m stu-0";
                            char hou2[5]=" -a";
                            if(l23==0){
                            	while(1){
					    			system(strcat(strcat(qian1,computer_number),hou2));
					    			Sleep(1000);
							    }
							}
	                        else for(int i=1;i<=l23;i++){
	                        	system(strcat(strcat(qian1,computer_number),hou2));
	                        	Sleep(1000);
							}
							break;
						}
						case 4:{
							printf("请输入要保护的电脑号:\n");
                			printf("(只需输入数字部分，如stu-015只需输入15,stu-004要输入04)");
                			char computer_number[5];
					    	scanf("%s",&computer_number);
					    	printf("请输入循环次数:(键入0死循环) \n");
					    	int l23;
					    	scanf("%d",&l23);
	                        char qian1[20]="shutdown -m stu-0";
                            char hou2[25]=" -s -t 10000000 -c 保护";
                            if(l23==0){
                            	while(1) {
                            		system(strcat(strcat(qian1,computer_number),hou2));
									Sleep(1000);
								}
							}
	                        else for(int i=1;i<=l23;i++){
	                        	system(strcat(strcat(qian1,computer_number),hou2));
	                        	Sleep(1000);
							}
							break;
						}
						case 3:{
							printf("1:解除关机    2:死循环解除关机 \n");
							int l14;
							scanf("%d",&l14);
							if(l14==1){
								system("shutdown -m stu-001 -a");
                                system("shutdown -m stu-002 -a");
                                system("shutdown -m stu-003 -a");
                                system("shutdown -m stu-004 -a");
                                system("shutdown -m stu-005 -a");
                                system("shutdown -m stu-006 -a");
                                system("shutdown -m stu-007 -a");
                                system("shutdown -m stu-008 -a");
                                system("shutdown -m stu-009 -a");
                                system("shutdown -m stu-010 -a");
                                system("shutdown -m stu-011 -a");
                                system("shutdown -m stu-012 -a");
                                system("shutdown -m stu-013 -a");
                                system("shutdown -m stu-014 -a");
                                system("shutdown -m stu-015 -a");
                                system("shutdown -m stu-016 -a");
                                system("shutdown -m stu-017 -a");
                                system("shutdown -m stu-018 -a");
                                system("shutdown -m stu-019 -a");
                                system("shutdown -m stu-020 -a");
                                system("shutdown -m stu-021 -a");
                                system("shutdown -m stu-022 -a");
                                system("shutdown -m stu-023 -a");
                                system("shutdown -m stu-024 -a");
                                system("shutdown -m stu-025 -a");
                                system("shutdown -m stu-026 -a");
                                system("shutdown -m stu-027 -a");
                                system("shutdown -m stu-028 -a");
                                system("shutdown -m stu-029 -a");
                                system("shutdown -m stu-030 -a");
                                system("shutdown -m stu-031 -a");
                                system("shutdown -m stu-032 -a");
                                system("shutdown -m stu-033 -a");
                                system("shutdown -m stu-034 -a");
                                system("shutdown -m stu-035 -a");
                                system("shutdown -m stu-036 -a");
                                system("shutdown -m stu-037 -a");
                                system("shutdown -m stu-038 -a");
                                system("shutdown -m stu-039 -a");
                                system("shutdown -m stu-040 -a");
                                system("shutdown -m stu-041 -a");
                                system("shutdown -m stu-042 -a");
                                system("shutdown -m stu-043 -a");
                                system("shutdown -m stu-044 -a");
                                system("shutdown -m stu-045 -a");
                                system("shutdown -m stu-046 -a");
                                system("shutdown -m stu-047 -a");
                                system("shutdown -m stu-048 -a");
                                system("shutdown -m stu-049 -a");
                                system("shutdown -m stu-050 -a");
                                system("shutdown -m stu-051 -a");
                                system("shutdown -m stu-052 -a");
                                system("shutdown -m stu-053 -a");
                                system("shutdown -m stu-054 -a");
                                system("shutdown -m stu-055 -a");
                                system("shutdown -m stu-056 -a");
                                system("shutdown -m stu-057 -a");
                                system("shutdown -m stu-058 -a");
                                system("shutdown -m stu-059 -a");
                                system("shutdown -m stu-060 -a");
                                system("shutdown -m stu-061 -a");
                                system("shutdown -m stu-062 -a");
                                system("shutdown -m stu-063 -a");
                                system("shutdown -m stu-064 -a");
                                system("shutdown -m stu-065 -a");
                                system("shutdown -m stu-066 -a");
                                system("shutdown -m stu-067 -a");
                                system("shutdown -m stu-068 -a");
							}
							if(l14==2){
								while(1){
									system("shutdown -m stu-001 -a");
                                    system("shutdown -m stu-002 -a");
                                    system("shutdown -m stu-003 -a");
                                    system("shutdown -m stu-004 -a");
                                    system("shutdown -m stu-005 -a");
                                    system("shutdown -m stu-006 -a");
                                    system("shutdown -m stu-007 -a");
                                    system("shutdown -m stu-008 -a");
                                    system("shutdown -m stu-009 -a");
                                    system("shutdown -m stu-010 -a");
                                    system("shutdown -m stu-011 -a");
                                    system("shutdown -m stu-012 -a");
                                    system("shutdown -m stu-013 -a");
                                    system("shutdown -m stu-014 -a");
                                    system("shutdown -m stu-015 -a");
                                    system("shutdown -m stu-016 -a");
                                    system("shutdown -m stu-017 -a");
                                    system("shutdown -m stu-018 -a");
                                    system("shutdown -m stu-019 -a");
                                    system("shutdown -m stu-020 -a");
                                    system("shutdown -m stu-021 -a");
                                    system("shutdown -m stu-022 -a");
                                    system("shutdown -m stu-023 -a");
                                    system("shutdown -m stu-024 -a");
                                    system("shutdown -m stu-025 -a");
                                    system("shutdown -m stu-026 -a");
                                    system("shutdown -m stu-027 -a");
                                    system("shutdown -m stu-028 -a");
                                    system("shutdown -m stu-029 -a");
                                    system("shutdown -m stu-030 -a");
                                    system("shutdown -m stu-031 -a");
                                    system("shutdown -m stu-032 -a");
                                    system("shutdown -m stu-033 -a");
                                    system("shutdown -m stu-034 -a");
                                    system("shutdown -m stu-035 -a");
                                    system("shutdown -m stu-036 -a");
                                    system("shutdown -m stu-037 -a");
                                    system("shutdown -m stu-038 -a");
                                    system("shutdown -m stu-039 -a");
                                    system("shutdown -m stu-040 -a");
                                    system("shutdown -m stu-041 -a");
                                    system("shutdown -m stu-042 -a");
                                    system("shutdown -m stu-043 -a");
                                    system("shutdown -m stu-044 -a");
                                    system("shutdown -m stu-045 -a");
                                    system("shutdown -m stu-046 -a");
                                    system("shutdown -m stu-047 -a");
                                    system("shutdown -m stu-048 -a");
                                    system("shutdown -m stu-049 -a");
                                    system("shutdown -m stu-050 -a");
                                    system("shutdown -m stu-051 -a");
                                    system("shutdown -m stu-052 -a");
                                    system("shutdown -m stu-053 -a");
                                    system("shutdown -m stu-054 -a");
                                    system("shutdown -m stu-055 -a");
                                    system("shutdown -m stu-056 -a");
                                    system("shutdown -m stu-057 -a");
                                    system("shutdown -m stu-058 -a");
                                    system("shutdown -m stu-059 -a");
                                    system("shutdown -m stu-060 -a");
                                    system("shutdown -m stu-061 -a");
                                    system("shutdown -m stu-062 -a");
                                    system("shutdown -m stu-063 -a");
                                    system("shutdown -m stu-064 -a");
                                    system("shutdown -m stu-065 -a");
                                    system("shutdown -m stu-066 -a");
                                    system("shutdown -m stu-067 -a");
                                    system("shutdown -m stu-068 -a");
								}
							}
							break;
						}
					}
				}
				break;
			}
            case 5:{
            	if(lv<=3) printf("权限不够！ \n");
            	else{
            		printf("请输入机房号：(七年级为1，八年级为2) \n");
            		int l11;
            		scanf("%d",&l11);
            		if(l11==1){
            			printf("请输入列(从外窗户数): \n");
            			int a,b;
            			scanf("%d",&a);
            			switch(a){
            				case 1:{
            					printf("请输入行(从前往后数): \n");
            					scanf("%d",&b);
            					switch(b){
            						case 1:{
            							printf("\n stu-009 \n");
										break;
									}
									case 2:{
            							printf("\n stu-010 \n");
										break;
									}
									case 3:{
            							printf("\n stu-011 \n");
										break;
									}
									case 4:{
            							printf("\n stu-012 \n");
										break;
									}
									case 5:{
            							printf("\n stu-013 \n");
										break;
									}
									case 6:{
            							printf("\n stu-014 \n");
										break;
									}
									case 7:{
            							printf("\n stu-015 \n");
										break;
									}
									case 8:{
            							printf("\n stu-016 \n");
										break;
									}
									case 9:{
            							printf("\n stu-017 \n");
										break;
									}
									case 10:{
            							printf("\n stu-018 \n");
										break;
									}
								}
								break;
							}
							case 2:{
								printf("请输入行(从前往后数): \n");
            					scanf("%d",&b);
            					switch(b){
            						case 1:{
            							printf("\n stu-019 \n");
										break;
									}
									case 2:{
            							printf("\n stu-020 \n");
										break;
									}
									case 3:{
            							printf("\n stu-021 \n");
										break;
									}
									case 4:{
            							printf("\n stu-022 \n");
										break;
									}
									case 5:{
            							printf("\n stu-023 \n");
										break;
									}
									case 6:{
            							printf("\n stu-024 \n");
										break;
									}
									case 7:{
            							printf("\n stu-025 \n");
										break;
									}
									case 8:{
            							printf("\n stu-026 \n");
										break;
									}
									case 9:{
            							printf("\n stu-027 \n");
										break;
									}
									case 10:{
            							printf("\n stu-028 \n");
										break;
									}
								}
								break;
							}
							case 3:{
								printf("请输入行(从前往后数): \n");
            					scanf("%d",&b);
            					switch(b){
            						case 1:{
            							printf("\n stu-029 \n");
										break;
									}
									case 2:{
            							printf("\n stu-030 \n");
										break;
									}
									case 3:{
            							printf("\n stu-031 \n");
										break;
									}
									case 4:{
            							printf("\n stu-032 \n");
										break;
									}
									case 5:{
            							printf("\n stu-033 \n");
										break;
									}
									case 6:{
            							printf("\n stu-034 \n");
										break;
									}
									case 7:{
            							printf("\n stu-035 \n");
										break;
									}
									case 8:{
            							printf("\n stu-036 \n");
										break;
									}
									case 9:{
            							printf("\n stu-037 \n");
										break;
									}
									case 10:{
            							printf("\n stu-038 \n");
										break;
									}
								}
								break;
							}
							case 4:{
								printf("请输入行(从前往后数): \n");
            					scanf("%d",&b);
            					switch(b){
            						case 1:{
            							printf("\n stu-039 \n");
										break;
									}
									case 2:{
            							printf("\n stu-040 \n");
										break;
									}
									case 3:{
            							printf("\n stu-041 \n");
										break;
									}
									case 4:{
            							printf("\n stu-042 \n");
										break;
									}
									case 5:{
            							printf("\n stu-043 \n");
										break;
									}
									case 6:{
            							printf("\n stu-044 \n");
										break;
									}
									case 7:{
            							printf("\n stu-045 \n");
										break;
									}
									case 8:{
            							printf("\n stu-046 \n");
										break;
									}
									case 9:{
            							printf("\n stu-047 \n");
										break;
									}
									case 10:{
            							printf("\n stu-048 \n");
										break;
									}
								}
								break;
							}
							case 5:{
								printf("请输入行(从前往后数): \n");
            					scanf("%d",&b);
            					switch(b){
            						case 1:{
            							printf("\n stu-049 \n");
										break;
									}
									case 2:{
            							printf("\n stu-050 \n");
										break;
									}
									case 3:{
            							printf("\n stu-051 \n");
										break;
									}
									case 4:{
            							printf("\n stu-052 \n");
										break;
									}
									case 5:{
            							printf("\n stu-053 \n");
										break;
									}
									case 6:{
            							printf("\n stu-054 \n");
										break;
									}
									case 7:{
            							printf("\n stu-055 \n");
										break;
									}
									case 8:{
            							printf("\n stu-056 \n");
										break;
									}
									case 9:{
            							printf("\n stu-057 \n");
										break;
									}
									case 10:{
            							printf("\n stu-058 \n");
										break;
									}
								}
								break;
							}
							case 6:{
								printf("请输入行(从前往后数): \n");
            					scanf("%d",&b);
            					switch(b){
            						case 1:{
            							printf("\n stu-059 \n");
										break;
									}
									case 2:{
            							printf("\n stu-060 \n");
										break;
									}
									case 3:{
            							printf("\n stu-061 \n");
										break;
									}
									case 4:{
            							printf("\n stu-062 \n");
										break;
									}
									case 5:{
            							printf("\n stu-063 \n");
										break;
									}
									case 6:{
            							printf("\n stu-064 \n");
										break;
									}
									case 7:{
            							printf("\n stu-065 \n");
										break;
									}
									case 8:{
            							printf("\n stu-066 \n");
										break;
									}
								}
								break;
							}
						}
					}
					if(l11==2){
						printf("请输入列(从外窗户数): \n");
            			int a,b;
            			scanf("%d",&a);
            			switch(a){
            				case 1:{
            					printf("请输入行(从前往后数): \n");
            					scanf("%d",&b);
            					switch(b){
            						case 1:{
            							printf("\n stu-011 \n");
										break;
									}
									case 2:{
            							printf("\n stu-012 \n");
										break;
									}
									case 3:{
            							printf("\n stu-013 \n");
										break;
									}
									case 4:{
            							printf("\n stu-014 \n");
										break;
									}
									case 5:{
            							printf("\n stu-015 \n");
										break;
									}
									case 6:{
            							printf("\n stu-016 \n");
										break;
									}
									case 7:{
            							printf("\n stu-017 \n");
										break;
									}
									case 8:{
            							printf("\n stu-018 \n");
										break;
									}
									case 9:{
            							printf("\n stu-019 \n");
										break;
									}
									case 10:{
            							printf("\n stu-020 \n");
										break;
									}
								}
								break;
							}
							case 2:{
								printf("请输入行(从前往后数): \n");
            					scanf("%d",&b);
            					switch(b){
            						case 1:{
            							printf("\n stu-021 \n");
										break;
									}
									case 2:{
            							printf("\n stu-022 \n");
										break;
									}
									case 3:{
            							printf("\n stu-023 \n");
										break;
									}
									case 4:{
            							printf("\n stu-024 \n");
										break;
									}
									case 5:{
            							printf("\n stu-025 \n");
										break;
									}
									case 6:{
            							printf("\n stu-026 \n");
										break;
									}
									case 7:{
            							printf("\n stu-027 \n");
										break;
									}
									case 8:{
            							printf("\n stu-028 \n");
										break;
									}
									case 9:{
            							printf("\n stu-029 \n");
										break;
									}
									case 10:{
            							printf("\n stu-030 \n");
										break;
									}
								}
								break;
							}
							case 3:{
								printf("请输入行(从前往后数): \n");
            					scanf("%d",&b);
            					switch(b){
            						case 1:{
            							printf("\n stu-031 \n");
										break;
									}
									case 2:{
            							printf("\n stu-032 \n");
										break;
									}
									case 3:{
            							printf("\n stu-033 \n");
										break;
									}
									case 4:{
            							printf("\n stu-034 \n");
										break;
									}
									case 5:{
            							printf("\n stu-035 \n");
										break;
									}
									case 6:{
            							printf("\n stu-036 \n");
										break;
									}
									case 7:{
            							printf("\n stu-037 \n");
										break;
									}
									case 8:{
            							printf("\n stu-038 \n");
										break;
									}
									case 9:{
            							printf("\n stu-039 \n");
										break;
									}
									case 10:{
            							printf("\n stu-040 \n");
										break;
									}
								}
								break;
							}
							case 4:{
								printf("请输入行(从前往后数): \n");
            					scanf("%d",&b);
            					switch(b){
            						case 1:{
            							printf("\n stu-041 \n");
										break;
									}
									case 2:{
            							printf("\n stu-042 \n");
										break;
									}
									case 3:{
            							printf("\n stu-043 \n");
										break;
									}
									case 4:{
            							printf("\n stu-044 \n");
										break;
									}
									case 5:{
            							printf("\n stu-045 \n");
										break;
									}
									case 6:{
            							printf("\n stu-046 \n");
										break;
									}
									case 7:{
            							printf("\n stu-047 \n");
										break;
									}
									case 8:{
            							printf("\n stu-048 \n");
										break;
									}
									case 9:{
            							printf("\n stu-049 \n");
										break;
									}
									case 10:{
            							printf("\n stu-050 \n");
										break;
									}
								}
								break;
							}
							case 5:{
								printf("请输入行(从前往后数): \n");
            					scanf("%d",&b);
            					switch(b){
            						case 1:{
            							printf("\n stu-051 \n");
										break;
									}
									case 2:{
            							printf("\n stu-052 \n");
										break;
									}
									case 3:{
            							printf("\n stu-053 \n");
										break;
									}
									case 4:{
            							printf("\n stu-054 \n");
										break;
									}
									case 5:{
            							printf("\n stu-055 \n");
										break;
									}
									case 6:{
            							printf("\n stu-056 \n");
										break;
									}
									case 7:{
            							printf("\n stu-057 \n");
										break;
									}
									case 8:{
            							printf("\n stu-058 \n");
										break;
									}
									case 9:{
            							printf("\n stu-059 \n");
										break;
									}
									case 10:{
            							printf("\n stu-060 \n");
										break;
									}
								}
								break;
							}
							case 6:{
								printf("请输入行(从前往后数): \n");
            					scanf("%d",&b);
            					switch(b){
            						case 1:{
            							printf("\n stu-061 \n");
										break;
									}
									case 2:{
            							printf("\n stu-062 \n");
										break;
									}
									case 3:{
            							printf("\n stu-063 \n");
										break;
									}
									case 4:{
            							printf("\n stu-064 \n");
										break;
									}
									case 5:{
            							printf("\n stu-065 \n");
										break;
									}
									case 6:{
            							printf("\n stu-066 \n");
										break;
									}
									case 7:{
            							printf("\n stu-067 \n");
										break;
									}
									case 8:{
            							printf("\n stu-068 \n");
										break;
									}
									case 9:{
            							printf("\n stu-069 \n");
										break;
									}
									case 10:{
            							printf("\n stu-070 \n");
										break;
									}
								}
								break;
							}
						}
					}
				}
				Sleep(2000); 
				break;
			} 
            case 6:{
                Sleep(1000);
                printf("账号信息：\n");
                cout<<"当前帐号："<<last_name<<"("<<name<<")"<<endl;
                cout<<"当前权限："<<lv<<"级(最高5级)"<<endl;
                Sleep(1000);
                printf("\n 各类工具整合版   1.6 pre 2  \n 更新时间：2021.9.4 \n");
                Sleep(1000);
                printf("作者:W.Y.H   特别鸣谢:开发团队(包括TiC等人)   \n");
                Sleep(1000);
                printf("适用范围：金外机房 \n");
                Sleep(1000);
                printf("仅作为威慑手段，请勿滥用\n");
                printf("目的：压制与震慑持有＊小工具＊的危险分子\n");
                printf("维护信息课的和平！\n");
                Sleep(1000);
                printf("\n包含内容：\n");
                printf("金钟罩1.0\n");
                printf("金钟罩1.1A\n");
                printf("金钟罩1.1B\n");
                printf("金钟罩1.2\n");
                printf("攻防兼备\n");
                printf("参考：\n");
                printf("《远程关机教程》(作者相同)\n");
                printf("小工具(作者：Chenfy)\n");
                printf("部分资源来源于网络 \n");
                printf("\n源代码未公布，禁止篡改代码\n");
                printf("未经作者授权禁止私自翻录发表\n");
                printf("\n如要寻找作者,或获取账号，\n请至金外2019级11班，或联系QQ：2840622764 \n");
                Sleep(1000);
                break;
            }
            case 7:{
            	Sleep(1000);
            	if(lv<5) printf("权限不够!\n");
            	else {
            		printf("当前共有账号：5 \n");
            		printf("查询号：\n");
            		printf("1:王艺涵（管理员） \n");
            		printf("2:罗浩天 \n");
            		printf("3:王博诚 \n");
            		printf("4:祝宇辰 \n");
            		printf("5:陈俊博 \n");
            		printf("6:金凯瑞 \n");
            		printf("7:项佳俊（二代管理员） \n");
            		printf("8:新人临时账号 \n");
            		printf("请输入查询号：\n");
            		int l12;
            		scanf("%d",&l12);
            		switch(l12){
            			case 1:{
            				printf("管理员王艺涵：\n");
            				cout<<"账号："<<wyh[0]<<endl;
            				cout<<"密码：设置不可见"<<endl;
            				printf("权限:5级(最高5级) \n");
            				printf("包涵版本：1.0及以上 \n");
							break;
						}
						case 2:{
            				printf("罗浩天：\n");
            				cout<<"账号："<<lht[0]<<endl;
            				cout<<"密码："<<lht[1]<<endl;
            				printf("权限:5级(最高5级) \n");
            				printf("包涵版本：1.0及以上 \n");
							break;
						}
						case 3:{
            				printf("王博诚：\n");
            				cout<<"账号："<<wbc[0]<<endl;
            				cout<<"密码："<<wbc[1]<<endl;
            				printf("权限:4级(最高5级) \n");
            				printf("包涵版本：1.0及以上 \n");
							break;
						}
						case 4:{
            				printf("祝宇辰：\n");
            				cout<<"账号："<<zyc[0]<<endl;
            				cout<<"密码："<<zyc[1]<<endl;
            				printf("权限:4级(最高5级) \n");
            				printf("包涵版本：1.0及以上 \n");
							break;
						}
						case 5:{
            				printf("陈俊博：\n");
            				cout<<"账号："<<cjb[0]<<endl;
            				cout<<"密码："<<cjb[1]<<endl;
            				printf("权限:4级(最高5级) \n");
            				printf("包涵版本：1.0以上 \n");
							break;
						}
						case 6:{
            				printf("金凯瑞：\n");
            				cout<<"账号："<<jkr[0]<<endl;
            				cout<<"密码："<<jkr[1]<<endl;
            				printf("权限:4级(最高5级) \n");
            				printf("包涵版本：1.4.2及以上 \n");
							break;
						}
						case 7:{
							printf("项佳俊: \n");
							cout<<"账号:"<<xjj[0]<<endl;
							cout<<"密码:"<<xjj[1]<<endl;
							printf("权限:5级(最高5级) \n");
							printf("包涵版本：1.6.2及以上 \n");
							break;
						}
						case 8:{
							printf("新人临时账号: \n");
							cout<<"账号："<<newer[0]<<endl;
							cout<<"密码："<<newer[1]<<endl;
							printf("权限:3级(最高5级) \n");
							printf("包涵版本：1.3.8及以上 \n"); 
							break;
						}
					}
					Sleep(2000);
				}
				break;
			}
			case 8:{
				printf("1:更改颜色 2:更改标题 3:更改权限 4:返回 \n");
				int l30;
				scanf("%d",&l30);
				switch(l30){
					case 0:{
						break;
					}
					case 1:{
						printf("请输入颜色参数（由两个16进制数组成,分别代表背景和字体颜色)\n");
						printf("(如 07 为默认,0a/02 为经典;输入help获得用法帮助) \n");
						char color[9]="color ";
						char color_number[5];
						cin>>color_number;
						if(color_number=="help") system("HELP color"); 
						else system(strcat(color,color_number));
						break;
					}
					case 2:{
						printf("请输入标题(上限:20字符): \n");
						char title[9]="TITLE ";
						char last_title[23];
						cin>>last_title;
						system(strcat(title,last_title));
						break;
					}
					case 3:{
						if(first_lv<5){
		    			printf("权限不够! \n");
				        }
		        		else{
					        printf("请输入更改的权限级别: \n");
					        int a6;
					        scanf("%d",&a6);
					        lv=a6;
					        printf("您的权限已更改至%d级 \n",lv);
					        Sleep(300);
			        	}
						break;
					}
				}
				break;
			}
			case 9:{
				if(lv<3){
					printf("1:重新登陆   2:返回 \n");
					int g;
					scanf("%d",&g);
					if(g==1){
						
						name_password();
					}
					break;
				} 
				else{
					printf("1:cmd指令帮助   2:信息课存活攻略   3:功能查询一览表   4:重新登陆   5:返回 \n");
					int a3;
					scanf("%d",&a3);
					switch(a3){
						case 1:{
							
							break;
						}
						case 2:{
							printf("(输入1继续) \n");
							int g;
							Sleep(300);
							printf("\n          信息课存活攻略          \n");
							printf("            作者:W.Y.H            \n");
							cin>>g;
							printf("1:课前重启后先将U盘插入，立刻将此程序放上桌面\n");
							cin>>g;
							printf("2:将此程序复制多次(用于进行并行死循环)\n");
							cin>>g;
							printf("3:先用其中一个副本打开金钟罩1.1C \n"); 
							cin>>g;
							printf("4:最小化此程序并先上课 \n");
							cin>>g;
							 
							break;
						}
						case 3:{
							printf("=====操作自己=====\n");
							printf("1:立即关机自己 \n");
							printf("2:定时关机自己 \n");
							printf("3:注销\n");
							printf("4:蓝屏\n");
							Sleep(300);
							printf("======攻击======\n");
							printf("1:远程关机 \n");
							printf("2:打开图形用户界面 \n"); 
							printf("3:循环关机 \n");
							printf("4:极端 \n");
							printf("| 1:关机所有 \n");
							printf("|_2:死循环关机所有 \n");
							printf("5:骚扰 \n");
							printf("6:打开cmd\n");
							printf("7:无限递归关机 \n");
							printf("8:自由输入指令 \n");
							Sleep(300);
							printf("======防御======\n");
							printf("1:解除关机 \n");
							printf("2:金钟罩系列 \n");
							printf("| 1:金钟罩1.0\n");
							printf("| 2:金钟罩1.1A\n");
							printf("| 3:金钟罩1.1B\n");
							printf("|_4:金钟罩1.2\n");
							Sleep(300);
							printf("======保护======\n");
							printf("1:保护他人 \n");
							printf("2:死循环保护他人 \n");
							printf("3:保护所有 \n");
							printf("4:对他人使用金钟罩1.1B \n");
							Sleep(300);
							printf("==个性化与设置==\n");
							printf("1:更改颜色 \n");
							printf("2:更改标题 \n");
							Sleep(300);
							printf("======帮助======\n");
							printf("1:cmd指令帮助\n");
							printf("2:信息课存活攻略\n");
							printf("3:功能查询一览表\n");
							printf("4:重新登陆\n");
							Sleep(300);
							printf("=====其它工具=====\n");
							printf("1:打开任务管理器\n");
							printf("2:清除记录\n");
							printf("3:休眠程序\n");
							Sleep(500);
							break;
						} 
						case 4:{
							system("cls");
							name_password();
							system("cls");
							break;
						}
					}
				}
				break;
			} 
			case 10:{
				printf("1:打开Windows任务管理器   2:清除记录   3:休眠程序(屏保)   4:连点器 \n  5:聊天程序【调试中】   6:调用小工具 \n");
				int a1;
				scanf("%d",&a1);
				if(a1==1) system("start taskmgr"); 
				if(a1==2) system("cls");
				if(a1==3){
					printf("请输入休眠时间(秒) \n");
					int a2;
					scanf("%d",&a2);
					printf("是否打开屏保?(1/0)\n");
					int a3;
					scanf("%d",&a3);
					if(a3==1) {
						
					}
					else for(int i=1;i<=a2;i++){
						Sleep(1000);
						printf("******************** %d秒 \n",i);
					}
				}
				if(a1==4){
					liandianqi();
				}
				if(a1==5){
					if(lv<4) printf("权限不够! \n");
					else {
						printf("请输入对方计算机号后两位(如stu-015输入15,stu-005输入05)\n");
						char number[105],last_number[78];
						cin>>number;
		//				last_number=number;
						printf("请输入发送内容:(50字符内，英文，支持标点)\n");
						char talk[50];
						cin>>talk;
						printf("是否隐藏名称?(1/0) \n");
						int f;
						cin>>f;
						char chatname[56];
		//				if(name==wyh[0]) chatname="W.Y.H:";
		//				if(name==lht[0]) chatname="L.T-L:";
		//				if(name==wbc[0]) chatname="L.C-m:";
		//				if(name==zyc[0]) chatname="L.K:";
		//				if(f==1) chatname="*****:";
						printf("1:右下角弹窗(默认)   2:中央弹窗 \n");
						int a;
						cin>>a;
						if(a!=2){
							char m1[101]="shutdown -m stu-0";
							char m2[76]=" -s -t 100000000 -c ";
							char m3[5]=" -a";
							system(strcat(m1,strcat(number,strcat(m2,strcat(chatname,talk)))));
							cout<<"消息 "<<talk<<" 已发送给stu-0"<<number<<endl;
							Sleep(4000);
							system(strcat(m1,strcat(number,m3)));
						}
						else{
							char m1[101]="shutdown -m stu-0";
							char m2[76]=" -s -t 500 -c ";
							char m3[5]=" -a";
							system(strcat(m1,strcat(number,strcat(m2,strcat(chatname,talk)))));
							cout<<"消息 "<<talk<<" 已发送给stu-0"<<last_number<<endl;
							Sleep(4000);
							system(strcat(m1,strcat(number,m3)));
						}
					} 
				}
				if(a1==6){
					if(lv<4){
						printf("权限不够!\n");
					}
					else{
						system("cls");
						system("color 07");
						stool();
					} 
				}
				break;
			} 
			case 11:{
				if((name!="wyh2007")||(lv<5)){
					printf("权限不够! \n");
				}
				else{
					printf("暂无 \n");
				}
				break;
			}
			case 12:{
				if((name!="wyh2007")||(lv<5)){
					printf("权限不够! \n");
				}
				else{
					printf("各类工具整合版1.5.4代码: \n \n");
					
					printf("暂无 \n");
				}
				break;
			}
			case 13:{
				
				break;
			} 
			case 14:{
				if((name!="wyh2007")||(lv<5)){
					printf("权限不够! \n");
				}
				else{
					printf("\n\n");
				}
				break;
			}
        }
    }
    return 0;
}
//=======================================================================================================================================================================
