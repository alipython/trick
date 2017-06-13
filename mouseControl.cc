/* ************************************
 *
 * @Author         Noxaean
 * @Email          noxaean@gmail.com
 * @Description  
 * @Created        2017-01-06 15:37:38
 * @Last Modified  2017-06-13 13:27:33
 *
 * ****************************************/
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <vector>
using namespace std;

int extrajobCount = 0;
int WAIT_CONFIRM_MILI_SEC   =   70 * 1000;
int WAIT_REFRESH_MILI_SEC   =   40 * 1000;
vector<int> jobs = {813,1000,1200,1400,1430,1500,1530,1600,1800,1900,1930,2000,2100,2140};

struct Pos{
    int x;
    int y;
};

/*
   init icon

*/

Pos duoren				= {950,100};
Pos quickJoin			= {3,3};  //need modified
Pos danren				= {1010,100};
Pos swithDanren			= {1085,400};
vector<Pos> singlFB		= { {405,617},{681,617},{957,617}};

Pos huodong				=       {1065,100};
Pos joinHD				=       {1000,645};
Pos joinHD2				=       {687,578}; //  kua fu zhanchang
Pos autoMission			=       {1248,342};
Pos quora				=       {355,164};
Pos revive				=		{768,504};
Pos guildTask			=		{1153,524};
Pos battle				=		{700,500};
vector<Pos> mission		=		{ {1313,430}, {1318,428} , {} , {}};

/*
   init Boss Pos

*/
vector<Pos> Bosses      =       { {821,466},{1071,466},{437,613},{688,613},{940,613},{444,319},{691,319},{938,319},{567,467},{823,467},{1072,467} };
Pos swithBoss			=       {1085,400};
Pos bossItem			=       {337,160};
Pos killBoss			=       {1343,327};
Pos leaveBoss			=       {1328,265};
/*

   Init refresh Pos

*/
Pos refresh				=       {645,51};
vector<Pos> confirms    =       { {724,714}, {724,704},{724,694},{724,684},{724,674},{724,664},{724,654},{724,644},{724,634},{724,624},{724,614},
    {724,604},{724,594},{724,584},{724,574}};

/*
   Init Clean Page Pos

*/
Pos closeLM				=       {1150,105};
Pos closeDR				=       {1100,105};
Pos closeLB				=       {1280,425};
Pos closeWZDL			=       {735,490};

void click(Pos pos,  int repeat=1, int interval=200){
    int x = pos.x;
    int y = pos.y;
    SetCursorPos(x,y);
    for (int i = 0;i != repeat;++i){
	mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
	Sleep(interval);
    }
}

void click(vector<Pos> poses, int interval=200){
    for ( auto pos = poses.cbegin(); pos != poses.cend(); ++pos ) {
	int x = pos->x;
	int y = pos->y;
	SetCursorPos( x,y );
	mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
	Sleep(interval);
    }
}

void freshPage(){

    click(refresh,200,2);
    Sleep(WAIT_CONFIRM_MILI_SEC);

    click(confirms);
    Sleep(WAIT_REFRESH_MILI_SEC);
}

void cleanPage(bool flag=true){
    //close fresh confirm window
    if(flag){
	click(confirms);
	Sleep(WAIT_REFRESH_MILI_SEC);
    }
    //close DUOREN Complete
    click(closeWZDL,2);

    //close LONGMAI
    click(closeLM,10);


    //close DANREN
    click(closeDR,10);

    //close LIBAO
    click(closeLB,10);
}

void bossRush(){

    for(auto boss = Bosses.cbegin() ; boss != Bosses.cend(); ++boss){
	//clean Page
	cleanPage(false);
	//Click activity
	click(huodong,1,6000);
	//Click woldboss
	click(bossItem,1,3000);

	//switch page
	if(boss - Bosses.cbegin() == 5 )
	    click(swithBoss,1,1000);

	int level = boss - Bosses.cbegin();
	//Choose Boss
	click((*boss),1,5000);
	// kill boss
	click(killBoss,1,(80 + 10 * level ) * 1000 );
	click(revive,1,5000);
	//leave Boss
	click(leaveBoss,1,10 * 1000);

    }

}

void joinParty(int SLEEPTIME=30){

    cleanPage();

    if(jobs[0] == 1600 || jobs[0] == 2140 ){
	bossRush();
    }

    else{
	// click activity
	click(huodong,1,10000);
	//joint part1
	click(joinHD,1,5000);
	//joint part2
	click(joinHD2,1,10000);
	//auto mission
	click(autoMission,1,2000);
	click(quora,1,1000);
	if (jobs[0] == 1900){
	    for(int i =0; i <  SLEEPTIME ; ++i) 
		click(revive,12,5000);
	}
	else if (jobs[0] == 2000){
	    click(guildTask,1,1000);
	    for(int i = 0; i < SLEEPTIME; ++i)
		click(revive,12,5000);
	}
	else if (jobs[0] == 2100){
	    for (int i = 0;i < SLEEPTIME * 4 ; ++i){
		click(joinHD2,1,15000);
		//click(battle,1,5000);
	    }
	}
	else{
	    Sleep(1000 * 60 * (SLEEPTIME - 1) );
	}
    }

    freshPage();
    cleanPage();
}

void dailyJobs(){
    cleanPage(false);
    //click daily mission
    click(mission);
    //multi boss rush
    click(duoren,1,10 * 1000 );
    // join party
    click(quickJoin,1,2 * 60 * 1000);
}


void extraJobs(){
    cleanPage(false);
    //click single
    for (int i = 0; i !=2 ; ++i){
	for (auto fb = singlFB.cbegin(); fb != singlFB.cend(); ++fb){
	    click(danren,1,4000);

	    if(i == 1)
		click(swithDanren,2,200);

	    click((*fb),1,90 * 1000);

	    cleanPage(false);
	}
    }

    extrajobCount = 1;
}



int main(){

    Sleep(5000);
    SYSTEMTIME systime;
    extraJobs();

    for (auto item = jobs.begin();item != jobs.end(); Sleep(1000) ){

	GetLocalTime(&systime);
	int formatTime = systime.wHour * 100 + systime.wMinute ;

	if (formatTime - (*item) > 30){
	    cout << *item << " activity complete." << endl;
	    jobs.erase(item);
	    continue;
	}
	else if ( formatTime - (*item)  >= 0 && formatTime - (*item) < 30 ){
	    int leftTime = 30 - (formatTime - (*item));
	    cout << "Party time left "  << leftTime << " min. " << endl;
	    joinParty(leftTime);
	    Sleep(10000);
	}
	else {
	    int leftTime = ((*item) / 100 - formatTime / 100 ) * 60 + (*item) % 100 - (formatTime % 100);
	    cout << "daily time left " << leftTime << " min. " << endl;
	    dailyJobs();
	}
    }
    return 0;
}

