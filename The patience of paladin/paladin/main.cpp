#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>

char playername[30] = { " " };
int PlayerHP = 10, PlayerHPmax = 10, Playerpower = 1, playerPatienceSteck = 0, skillpower = 0, weapolpower = 1, blassing = 0, weapon = 0;
int EnemyHP = 1, EnemyPower = 1, enemyPatienceSteck = 0;
int gold = 10000, item = 0, activeitem = 0;
int background;

int inventoryindex[30] = { 0, };


int playerturn[15];
int enemyturn[15];

bool cangopetia = true, cangohmilla = false, can3 = false, can4 = false, can5 = false, can6 = false, can7 = false;
bool canPetiaWindmil = false, canpetiaBeach = false;


CONSOLE_CURSOR_INFO info;

//시스템

enum {
	BLACK,//검정
	DARK_BLUE,//어두운 파랑
	DARK_GREEN,//어두운 초록
	DARK_SKYBLUE,//어두운 하늘
	DARK_RED,//어두운 빨강
	DARK_VOILET,//어두운 보라
	DAKR_YELLOW,//어두운 노랑
	GRAY,//회색
	DARK_GRAY,//어두운 회색
	BLUE,//파랑
	GREEN,//초록
	SKYBLUE,//하늘
	RED,//빨강
	VIOLET,//보라
	YELLOW,//노랑
	WHITE,//하양
};

void cursorOff();
void gotoxy(int x, int y);
void setColor(int color);
void PlayerDecideOnaTurn();//플레이어의 턴을 정함
void battel();//싸움시스템
void enemyDecideOnaTurn();//적의 턴을 정함
void the_Patience_of_Paladin();//인트로
void Fight_A_Battle();//배틀 인게임화면
int FirstStart();//먼저 시작할 순서를 정하는 함수
int win_or_lose();
void shop();
void shopimage();
void playerinventoty();
void userUImain1();
void userUImain2();
void title();
void map();
void petiamap();
void petiavillage();
void petiavillageimage();
void petiachurchimage();
void petiachurch();
void petiaBeachimage();
void petiapierimage();
void petiapier();
void PetiaWindmillimage();
void PetiaWindmill();
void PetiaForestRoadimage();
void PetiaForestRoad();
void hmillamap();
void Warnings();
void story1();
void TextmainUI();
void TextmainUImini();
void Chapter1image();
void playerweaponRerode();
void gameover();
void enemyreset(int HP, int power);



void petiamapsuper();


int main() {
	cursorOff();
	system("mode con:cols=150 lines=50");
	//적용 안될경우 CMD에 행과 열을 150,50으로 변경해주세요
	the_Patience_of_Paladin();
}

void the_Patience_of_Paladin() {
	Warnings();
	title();
	story1();
}

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void cursorOff() {
	info.dwSize = 1;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void Warnings() {
	setColor(RED); gotoxy(70, 10); printf("Warnings");
	Sleep(1500);
	setColor(RED); gotoxy(48, 12); printf("인내심의 한계가 올경우 내 알빠 아니니까 알아서 쿠션같은");
	setColor(RED); gotoxy(52, 14); printf("걸 옆에다가 두고 플레이 하사는걸 추천드립니다.");
	Sleep(2000);
	setColor(RED); gotoxy(63, 30); printf("아무키나 눌러 다음으로...");
	_getch();
	system("cls");
	setColor(WHITE); gotoxy(71, 10); printf("안내");
	Sleep(1500);
	setColor(WHITE); gotoxy(58, 12); printf("대부분의 결정은 엔터키로 합니다.");
	setColor(WHITE); gotoxy(57, 14); printf("대부분의 움직임은 화살표로 합니다.");
	setColor(WHITE); gotoxy(48, 14); printf("뭐든지 키를 연타거나 꾹 누르고 있는건 추천하지 않아요...");
	Sleep(2000);
	setColor(WHITE); gotoxy(62, 30); printf("아무키나 눌러 다음으로...");
	_getch();
	system("cls");
}

void story1() {

	setColor(WHITE); gotoxy(65, 10); printf("당신의 이름은 무엇인가요?");
	setColor(WHITE); gotoxy(50, 11); printf("(이름 너무 길게 입력하면 고장날수도... 내알빠 아니지만)");
	setColor(WHITE); gotoxy(65, 13); printf("입력:");
	scanf_s("%s", playername, 30);
	system("cls");
	setColor(WHITE); gotoxy(75, 13); printf("%s", playername);
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		setColor(WHITE); gotoxy(73, 10); printf(".   "); Sleep(800);
		setColor(WHITE); gotoxy(73, 10); printf("..  "); Sleep(800);
		setColor(WHITE); gotoxy(73, 10); printf("... "); Sleep(800);
		setColor(WHITE); gotoxy(73, 10); printf("...."); Sleep(800);

	}

	TextmainUI();
	gotoxy(51, 5);  printf("엄마:일..나");
	_getch();
	gotoxy(51, 7);  printf("엄마:일..어..나");
	_getch();
	gotoxy(51, 9);  printf("엄마:일어나!");
	_getch();
	gotoxy(51, 11); printf("엄마: 언제까지 잘거야");
	_getch();
	gotoxy(51, 13); printf("엄마:너 소피아랑 논다고 하지 않았어?");
	_getch();
	gotoxy(51, 15); printf("%s:아! 맞어 늦으면 안되는데...", playername);
	_getch();
	gotoxy(51, 17); printf("(주섬주섬 옷을 챙겨 입은뒤)");
	_getch();
	gotoxy(51, 19); printf("%s:엄마 다녀올께요~", playername);
	_getch();
	gotoxy(51, 21); printf("%s:'마을에서 만나기로 했지? 얼른 가자'", playername);
	_getch();
	gotoxy(51, 23); printf("(저 멀리 쉬고있는 있는 한 소녀가 보인다.)");
	_getch();
	gotoxy(51, 25); printf("(쾅!!!)");
	_getch();

	TextmainUI();
	gotoxy(51, 5);  printf("%s:!!!", playername);
	_getch();
	gotoxy(51, 7);  printf("(그건 더이상 내가알던 소녀가 아니였다.)");
	_getch();
	gotoxy(51, 9);  printf("(눈 깜빡할 정도의 일어난 사건..)");
	_getch();
	gotoxy(51, 11); printf("(난 서둘러 집으로 향했다)");
	_getch();
	gotoxy(51, 13); printf("(하지만 그곳에 더이상 집은 없었다)");
	_getch();
	gotoxy(51, 15); printf("(그렇게 난 모든것을 잃었다)");
	_getch();
	gotoxy(51, 17); printf("(.....)");
	_getch();
	gotoxy(51, 19); printf("(난 그냥 하염없이 앞으로 걷기 시작했고)");
	_getch();
	gotoxy(51, 21); printf("(그렇게 난 교회의 기사로 거둬드려진다)");
	_getch();
	system("cls");
	Chapter1image();
	system("cls");

	TextmainUI();
	gotoxy(51, 5);  printf("(오늘은 기사 승급이 있는 날이다.)");
	_getch();
	gotoxy(51, 7);  printf("(서둘러 운동장으로 집합한다.)");
	_getch();
	gotoxy(51, 9);  printf("훈련관:다들알지?");
	_getch();
	gotoxy(51, 11); printf("훈련관:오늘은 기사승급이 있는 날이다.");
	_getch();
	gotoxy(51, 13); printf("훈련관:지금부터 옆에 있는 사람과 싸워");
	_getch();
	gotoxy(51, 15); printf("훈련관:이기는사람만 정식기사가 될수있다.");
	_getch();
	gotoxy(51, 17); printf("훈련관:실시");
	_getch();
	gotoxy(51, 19); printf("%s:'싸우는 방법이 뭐였지?'", playername);
	_getch();
	gotoxy(51, 21); printf("%s:'다시한번 생각해보자'", playername);
	_getch();
	system("cls");
	setColor(VIOLET); gotoxy(68, 5); printf("설명");
	setColor(VIOLET); gotoxy(45, 7); printf("숫자를 입력하여 행동을 결정할수 있습니다.");
	gotoxy(30, 9); printf("먼저 인내하기 행동을 할경우 인내 스택이 1개식 쌓입니다.");
	gotoxy(30, 11); printf("인내스택 (1) 당 추가 데미지가 1올라갑니다.");
	gotoxy(30, 13); printf("당신의 기본 공격력은 1입니다. 장비에 따라 공격력은 올라갈수도 내려갈수도 있습니다.	");
	gotoxy(30, 15); printf("당신이 기본으로 가지고 있는 10개의 턴이 있습니다. 상대 또한 10번의 턴을 가지고 있습니다.");
	gotoxy(30, 17); printf("당신의 10개의 모든턴을 정하면 상대와의 전투가 시작됩니다.");
	gotoxy(30, 19); printf("상대는 '방어하기' 라는 특별한 행동이 있습니다. 방어는 한턴동안 유지 됩니다");
	gotoxy(30, 21); printf("만약 상대가 방어를 사용했고 다음턴에 당신이 공격했다면 데미지가 들어가지 않습니다.");
	gotoxy(30, 21); printf("상대방과의 전투에서 승리하십시오!");
	setColor(WHITE); gotoxy(58, 35); printf("아무키나 눌러서 다음으로...");
	_getch();

	enemyreset(5, 1);
	battel();

	TextmainUI();
	gotoxy(51, 5);  printf("%s: 겨우 이겼다....", playername);
	_getch();
	gotoxy(51, 7);  printf("훈련관:축하한다 아주 훌룡하군");
	_getch();
	gotoxy(51, 9);  printf("훈련관:자네는 이제부터 정식기사야");
	_getch();
	gotoxy(51, 11); printf("훈련관:이제 들어가서 쉬어도 좋다");
	_getch();
	gotoxy(51, 13); printf("%s:이제 받으러 가볼까?", playername);
	_getch();
	gotoxy(51, 15); printf("똑똑...");
	_getch();
	gotoxy(51, 17); printf("기사단장:들어와");
	_getch();
	gotoxy(51, 19); printf("%s:약속을 지키러 왔습니다.", playername);
	_getch();
	gotoxy(51, 21); printf("기사단장:뭐였지.....아");
	_getch();
	gotoxy(51, 23); printf("기사단장:정식기사가 되면 시험을 준다고 했지?");
	_getch();
	gotoxy(51, 25); printf("기사단장:좋아 너에게 성기사의 시험을 주도록 하지");
	_getch();

	TextmainUI();
	gotoxy(51, 5);  printf("기사단장:7개의 마을에서 성기사의 자격을 받아와");
	_getch();
	gotoxy(51, 7);  printf("기사단장:그리고 최고위 신관을 찾아가라");
	_getch();
	gotoxy(51, 9);  printf("기사단장:그럼 자네는 성기사가 될수 있을거야");
	_getch();
	gotoxy(51, 11); printf("기사단장:바로 출발해도 좋지만");
	_getch();
	gotoxy(51, 13); printf("기사단장:풍차의 니가 쓸 무기를 맏겨놨다.");
	_getch();
	gotoxy(51, 15); printf("기사단장:가지고 가는게 좋을거야");
	_getch();
	gotoxy(51, 17); printf("%s:알겠습니다.", playername);
	_getch();
	gotoxy(51, 19); printf("(문을 닫고 나간다....)");
	_getch();
	gotoxy(51, 21); printf("기사단장:'성기사가 되는 날을 기대하지..'");
	_getch();

	system("cls");
	setColor(VIOLET); gotoxy(68, 5); printf("설명");
	setColor(VIOLET); gotoxy(55, 7); printf("화살표 좌우키로 이동할수 있습니다.");
	gotoxy(50, 9); printf("화살표가 이동하면서 선택지를 고를수 있습니다.");
	gotoxy(54, 11); printf("Enter 키를 눌러서 선택할수 있습니다.");
	gotoxy(58, 13); printf("이방법은 자주 사용합니다");

	setColor(WHITE); gotoxy(58, 35); printf("아무키나 눌러서 다음으로...");
	_getch();

	canPetiaWindmil = true;

	petiamap();

}


void battel() {
	srand((unsigned int)time(NULL));
	int givegold = rand() % 400;
	userUImain2();
	for (int i = 0; i < 2; i++)
	{
		gotoxy(60, 33); printf("당신의 턴을 정합니다    ");
		Sleep(500);
		gotoxy(60, 33); printf("당신의 턴을 정합니다.   ");
		Sleep(500);
		gotoxy(60, 33); printf("당신의 턴을 정합니다..  ");
		Sleep(500);
		gotoxy(60, 33); printf("당신의 턴을 정합니다...");
		Sleep(500);
	}//완전한 전투
	userUImain2();
	PlayerDecideOnaTurn();
	userUImain2();
	for (int i = 0; i < 2; i++)
	{
		gotoxy(60, 33); printf("상대의 턴을 정합니다   ");
		Sleep(500);
		gotoxy(60, 33); printf("상대의 턴을 정합니다.  ");
		Sleep(500);
		gotoxy(60, 33); printf("상대의 턴을 정합니다.. ");
		Sleep(500);
		gotoxy(60, 33); printf("상대의 턴을 정합니다...");
		Sleep(500);
	}
	enemyDecideOnaTurn();
	userUImain2();
	if (background == 1 )
	{
		petiapierimage();
	}
	else if (background == 2)
	{
		PetiaForestRoadimage();
	}
	TextmainUI();
	Fight_A_Battle();
	if (win_or_lose() == 0)
	{
		userUImain2();
		gotoxy(55, 10); printf("당신은 패배하였습니다.");
		Sleep(1500);
		gameover();
	}
	if (win_or_lose() == 1)
	{
		userUImain2();
		gotoxy(55, 10); printf("당신은 승리하였습니다.");
		gotoxy(55, 11); printf("%dgold 획득", givegold);
		gold += givegold;
		Sleep(1500);

	}
	if (win_or_lose() == 2)
	{
		userUImain2();
		gotoxy(55, 10); printf("적이 도망칩니다.");
		Sleep(1500);
	}
	system("cls");
}

void PlayerDecideOnaTurn() {
back1:

	int answer = 0;
	gotoxy(110, 5); printf("1.인내하기");
	gotoxy(110, 6); printf("2.공격하기");
	//gotoxy(110, 7); printf("3.아이템  ");
	int num = 4;
	int num1 = 0;
	for (int i = 0; i < 10; i++)// 숫자를 입력하여 자신의 행동을 정함
	{
		gotoxy(10, num); printf("%d번째 턴 입력:                                ", i + 1);
		gotoxy(24, num); scanf_s("%d", &answer);
		if (answer > 0 && answer < 3) {
			playerturn[i] = answer;
			if (answer == 1) {
				gotoxy(10, num); printf("%d번째턴:인내하기 ", i + 1);
			}
			else if (answer == 2) {
				gotoxy(10, num); printf("%d번째턴:공격하기 ", i + 1);
			}
			
		}
		else // 1,2,3 외에 입력할경우 카운터가 올라가지 않도록 해둠
		{
			gotoxy(10, num); printf("1과2만 입력할수 있습니다.");
			i--;
		}
		num++;
	}
	userUImain2();
	answer = 0;
	num = 4;
	for (int i = 0; i < 10; i++)// 자신이 정한 턴을 다시한번 보여줌
	{
		if (playerturn[i] == 1) {
			gotoxy(10, num); printf("%d번째턴:인내하기", i + 1);
		}
		else if (playerturn[i] == 2) {
			gotoxy(10, num); printf("%d번째턴:공격하기", i + 1);
		}
		else if (playerturn[i] == 3) {
			gotoxy(10, num); printf("%d번째턴:아이템", i + 1);
		}
		num++;
	}
back2:
	gotoxy(45, 5); printf("이렇게 정한게 확실합니까?\n");//확실하게 이렇게 정할지 다시한번 물어봐줌
	gotoxy(90, 6); printf("1.네      ");
	gotoxy(90, 7); printf("2.아니요\n");
	gotoxy(90, 8); printf("입력:"); scanf_s("%d", &answer);
	if (answer == 1)//맞다면 진행되고
	{
		gotoxy(55, 33); printf("전투로 돌아갑니다...");
		Sleep(3000);
	}
	if (answer == 2)//안되면 처음으로 돌아감
	{
		gotoxy(55, 33); printf("플레이어의 턴을 다시 정합니다....");
		Sleep(1500);
		userUImain2();
		goto back1;//이거 모르면 검색 ㄱㄱ
	}
	if (answer <= 0 || answer > 2)
	{
		gotoxy(55, 33); printf("1과 2중에 하나만 골라주세요.");
		Sleep(1000);
		gotoxy(60, 33); printf("                            ");
		goto back2;
	}
}

void enemyDecideOnaTurn() {
	srand((unsigned int)time(NULL));//몬스터의 행동값을 렌덤으로 정함
	for (int i = 0; i < 10; i++)//렌덤으로 정한값을 enemyturn에 넣음
	{
		int enemyaction = (rand() % 3) + 1;
		enemyturn[i] = enemyaction;
	}

}

void Fight_A_Battle() {

	int pltrn = 0;
	int enetrn = 0;

	gotoxy(55, 20); printf("플레이어의 남은 HP:%d   ", PlayerHP);

	gotoxy(55, 21); printf("적의의 남은 HP:%d   ", EnemyHP);

	if (FirstStart() % 2 == 1)
	{
		for (int i = 0; i < 20; i++)//20턴을 반복해서 싸움
		{
			if (i % 2 == 0)
			{
				gotoxy(55, 6); printf("%d번째 턴", enetrn + 1);
			}
			if (i % 2 == 0)
			{
				if (playerturn[pltrn] == 1)
				{
					gotoxy(55, 7); printf("플레이어는인내하기를사용했다          ");
					playerPatienceSteck += 1;
				}
				else if (playerturn[pltrn] == 2)
				{
					gotoxy(55, 7); printf("플레이어는공격하기를사용했다          ");

					if (enemyturn[pltrn - 1] != 3)
					{
						EnemyHP -= Playerpower + skillpower + weapolpower + playerPatienceSteck;
						playerPatienceSteck = 0;
					}
					else if (enemyturn[pltrn - 1] == 3 && i < !0)
					{
						gotoxy(55, 7); printf("그러나 막혔다.             ");
					}
				}
				/*else if (playerturn[pltrn] == 3)
				{
					gotoxy(55, 7); printf("플레이어는아이템를사용했다\          ");
				}*/
				Sleep(2000);
				pltrn++;

			}
			else {
				if (enemyturn[enetrn] == 1)
				{
					gotoxy(55, 7); printf("상대는인내하기를사용했다            ");
					enemyPatienceSteck += 1;
				}
				else if (enemyturn[enetrn] == 2)
				{
					gotoxy(55, 7); printf("상대는공격하기를사용했다                ");
					PlayerHP -= EnemyPower + enemyPatienceSteck;
					enemyPatienceSteck = 0;
				}
				else if (enemyturn[enetrn] == 3)
				{
					gotoxy(55, 7); printf("상대는방어하기를사용했다              ");

				}
				Sleep(2000);
				enetrn++;
			}
			gotoxy(55, 20); printf("플레이어의 남은 HP:%d   ", PlayerHP);

			gotoxy(55, 21); printf("적의의 남은 HP:%d   ", EnemyHP);
			if (PlayerHP <= 0 || EnemyHP <= 0)
			{
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < 20; i++)//20턴을 반복해서 싸움
		{
			if (i % 2 == 0)
			{
				gotoxy(55, 6); printf("%d번째 턴                   ", pltrn + 1);
			}
			if (i % 2 == 0)
			{
				if (enemyturn[enetrn] == 1)
				{
					gotoxy(55, 7); printf("상대는인내하기를사용했다                 ");
					enemyPatienceSteck += 1;
				}
				else if (enemyturn[enetrn] == 2)
				{
					gotoxy(55, 7); printf("상대는공격하기를사용했다                ");
					PlayerHP -= EnemyPower + enemyPatienceSteck;
					enemyPatienceSteck = 0;
				}
				else if (enemyturn[enetrn] == 3)
				{
					gotoxy(55, 7); printf("상대는방어하기를사용했다               ");

				}
				Sleep(2000);
				enetrn++;
			}
			else {
				if (playerturn[pltrn] == 1)
				{
					gotoxy(55, 7); printf("플레이어는인내하기를사용했다             ");
					playerPatienceSteck += 1;
				}
				else if (playerturn[pltrn] == 2)
				{
					gotoxy(55, 7); printf("플레이어는공격하기를사용했다                ");

					if (enemyturn[pltrn - 1] != 3)
					{
						EnemyHP -= Playerpower + skillpower + weapolpower + playerPatienceSteck;
						playerPatienceSteck = 0;
					}
					else if (enemyturn[pltrn - 1] == 3 && i < !0)
					{
						gotoxy(55, 7); printf("그러나 막혔다.                    ");
					}
				}
				/*else if (playerturn[i] == 3)
				{
					gotoxy(55, 7); printf("플레이어는아이템를사용했다                ");
				}*/
				Sleep(2000);
				pltrn++;
			}
			gotoxy(55, 20); printf("플레이어의 남은 HP:%d   ", PlayerHP);

			gotoxy(55, 21); printf("적의의 남은 HP:%d   ", EnemyHP);
			if (PlayerHP <= 0 || EnemyHP <= 0)
			{
				break;
			}
		}
	}
}


int FirstStart() {
	srand((unsigned int)time(NULL)); //  선공을 정하는 함수
	int start;
	for (int i = 0; i < 3; i++)
	{
		int number = (rand() % 10) + 1;
		if (i == 0) {
			start = number;
		}
		if (i == 1) {
			start += number;
		}
		if (i == 2) {
			start -= number;
		}
		if (i == 3) {
			start /= 2;
		}
	}
	return start;
}

int win_or_lose() {
	if (PlayerHP <= 0)
	{

		return 0;
	}
	else if (EnemyHP <= 0)
	{

		return 1;
	}
	if (PlayerHP > 0 && EnemyHP > 0)
	{
		return 2;
	}
}

void shop() {
	int page = 0, page1 = 0, page2 = 0, num = 0;
	int shopbaytext = gold;
	int textnum = 0;
	int shopnum = 0;
	const char* equipmentList[15][50] = { " " };//장비
	const char* consumptionitemList[15][50] = { " " };//소비
	const char* OtheritemList[15][30] = { " " };//기타

	equipmentList[0][0] = "나무로 만든 단도 (250gold)";
	equipmentList[1][0] = "나무로 만든 대검 (300gold)";
	consumptionitemList[0][0] = "미미한 체력회복 물약 (450gold)";
	consumptionitemList[1][0] = "조금은 효과적인 체력회복 물약 (600gold)";
	OtheritemList[0][0] = "허름한 가죽 (50gold)";
	OtheritemList[1][0] = "작은 고블린의 이빨 (80gold)";
	OtheritemList[2][0] = "사카밤파스피스 (120gold)";


	userUImain2();
	shopimage();

	gotoxy(45, 33); printf("장비");
	gotoxy(55, 33); printf("소비");
	gotoxy(65, 33); printf("기타");
	gotoxy(75, 33); printf("판매");
	gotoxy(85, 33); printf("나가기");
	gotoxy(110, 33); printf("%dgold", gold);
	int key = _getch();
	while (true)
	{
		if (shopnum == 0)
		{
			gotoxy(43, 33);
			setColor(WHITE); printf("→");
		}
		else {
			gotoxy(43, 33);
			printf("  ");
		}

		if (shopnum == 1)
		{
			gotoxy(53, 33);
			setColor(WHITE); printf("→");
		}
		else {
			gotoxy(53, 33);
			printf("  ");
		}

		if (shopnum == 2)
		{
			gotoxy(63, 33);
			setColor(WHITE); printf("→");
		}
		else {
			gotoxy(63, 33);
			printf("  ");
		}

		if (shopnum == 3)
		{
			gotoxy(73, 33);
			setColor(WHITE); printf("→");
		}
		else {
			gotoxy(73, 33);
			printf("  ");
		}

		if (shopnum == 4)
		{
			gotoxy(83, 33);
			setColor(WHITE); printf("→");
		}
		else {
			gotoxy(83, 33);
			printf("  ");
		}

		if (shopnum >= 5)
		{
			shopnum = 0;
		}
		if (shopnum < 0)
		{
			shopnum = 4;
		}

		if (key == 13)
		{
			key = 0;
			gotoxy(5, 1);
			if (shopnum == 0)
			{
				if (blassing == 0)
				{
					shopnum = 0;

					//gotoxy(45, 33); printf("                                                                                      ");

					gotoxy(95, 5); printf(equipmentList[0][0]);

					gotoxy(95, 7); printf(equipmentList[1][0]);

					gotoxy(95, 24); printf("뒤로가기");

					while (true)
					{
						if (shopnum == 0)
						{
							gotoxy(93, 5);
							setColor(WHITE); printf("→");
						}
						else {
							gotoxy(93, 5);
							printf("  ");
						}

						if (shopnum == 1)
						{
							gotoxy(93, 7);
							setColor(WHITE); printf("→");
						}
						else {
							gotoxy(93, 7);
							printf("  ");
						}

						if (shopnum == 2)
						{
							gotoxy(93, 24);
							setColor(WHITE); printf("→");
						}
						else {
							gotoxy(93, 24);
							printf("  ");
						}



						if (shopnum >= 3)
						{
							shopnum = 0;
						}
						if (shopnum < 0)
						{
							shopnum = 2;
						}

						if (key == 13)
						{
							key = 0;
							if (shopnum == 0)
							{
								if (gold < 249)
								{
									setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
									setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
									setColor(WHITE); gotoxy(17, 17); printf("|           음? 가지고 있는 돈이 부족하군          |");
									setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
									setColor(WHITE); gotoxy(17, 19); printf("   \\/");
									Sleep(500);
									setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 19); printf("                                                     ");

								}
								if (gold >= 250)
								{
									if (inventoryindex[0] != 0 && inventoryindex[1] != 0 && inventoryindex[2] != 0 && inventoryindex[3] != 0 && inventoryindex[4] != 0 && inventoryindex[5] != 0 && inventoryindex[6] != 0 && inventoryindex[7] != 0 && inventoryindex[8] != 0 && inventoryindex[9] != 0 && inventoryindex[10] != 0 && inventoryindex[11] != 0 && inventoryindex[12] != 0 && inventoryindex[13] != 0 && inventoryindex[14] != 0 && inventoryindex[15] != 0 && inventoryindex[16] != 0 && inventoryindex[17] != 0 && inventoryindex[18] != 0 && inventoryindex[19] != 0 && inventoryindex[20] != 0 && inventoryindex[21] != 0 && inventoryindex[22] != 0 && inventoryindex[23] != 0 && inventoryindex[24] != 0 && inventoryindex[25] != 0 && inventoryindex[26] != 0 && inventoryindex[27] != 0 && inventoryindex[28] != 0 && inventoryindex[29] != 0)
									{
										setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
										setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
										setColor(WHITE); gotoxy(17, 17); printf("|           가방에 공간이 모자라는것 같은데?       |");
										setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
										setColor(WHITE); gotoxy(17, 19); printf("   \\/");
										Sleep(500);
										setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
										setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
										setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
										setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
										setColor(WHITE); gotoxy(17, 19); printf("                                                     ");

									}
									else
									{
										gold -= 250;

										for (int i = 0; i < 30; i++)
										{
											if (inventoryindex[i] == 0)
											{
												inventoryindex[i] = 1;
												break;
											}
										}
										setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
										setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
										setColor(WHITE); gotoxy(17, 17); printf("|                  탁월한 선택이야                 |");
										setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
										setColor(WHITE); gotoxy(17, 19); printf("   \\/");
										Sleep(500);
										setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
										setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
										setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
										setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
										setColor(WHITE); gotoxy(17, 19); printf("                                                     ");
									}

									setColor(DAKR_YELLOW); gotoxy(110, 33); printf("%dgold", gold);
								}
							}

							if (shopnum == 1)
							{
								if (gold < 299)
								{
									setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
									setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
									setColor(WHITE); gotoxy(17, 17); printf("|           음? 가지고 있는 돈이 부족하군          |");
									setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
									setColor(WHITE); gotoxy(17, 19); printf("   \\/");
									Sleep(500);
									setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 19); printf("                                                     ");
								}
								if (gold >= 300)
								{
									if (inventoryindex[0] != 0 && inventoryindex[1] != 0 && inventoryindex[2] != 0 && inventoryindex[3] != 0 && inventoryindex[4] != 0 && inventoryindex[5] != 0 && inventoryindex[6] != 0 && inventoryindex[7] != 0 && inventoryindex[8] != 0 && inventoryindex[9] != 0 && inventoryindex[10] != 0 && inventoryindex[11] != 0 && inventoryindex[12] != 0 && inventoryindex[13] != 0 && inventoryindex[14] != 0 && inventoryindex[15] != 0 && inventoryindex[16] != 0 && inventoryindex[17] != 0 && inventoryindex[18] != 0 && inventoryindex[19] != 0 && inventoryindex[20] != 0 && inventoryindex[21] != 0 && inventoryindex[22] != 0 && inventoryindex[23] != 0 && inventoryindex[24] != 0 && inventoryindex[25] != 0 && inventoryindex[26] != 0 && inventoryindex[27] != 0 && inventoryindex[28] != 0 && inventoryindex[29] != 0)
									{
										setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
										setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
										setColor(WHITE); gotoxy(17, 17); printf("|           가방에 공간이 모자라는것 같은데?       |");
										setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
										setColor(WHITE); gotoxy(17, 19); printf("   \\/");
										Sleep(500);
										setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
										setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
										setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
										setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
										setColor(WHITE); gotoxy(17, 19); printf("                                                     ");

									}
									else
									{
										gold -= 300;

										for (int i = 0; i < 30; i++)
										{
											if (inventoryindex[i] == 0)
											{
												inventoryindex[i] = 2;
												break;
											}
										}
										setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
										setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
										setColor(WHITE); gotoxy(17, 17); printf("|                  탁월한 선택이야                 |");
										setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
										setColor(WHITE); gotoxy(17, 19); printf("   \\/");
										Sleep(500);
										setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
										setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
										setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
										setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
										setColor(WHITE); gotoxy(17, 19); printf("                                                     ");
									}


									setColor(DAKR_YELLOW); gotoxy(110, 33); printf("%dgold", gold);
								}
							}

							if (shopnum == 0)
							{
								//printf
							}
							else if (shopnum == 1) {


							}
							else if (shopnum == 2) {

								shop();
							}


							shopnum = 0;
						}

						if (_kbhit())
						{
							key = _getch();
							if (key == 224)
							{
								key = _getch();
								switch (key)
								{
								case 80:
									textnum++;
									shopnum++;//위
									break;
								case 72:
									textnum++;
									shopnum--;//아래
									break;
								}
							}
						}
					}
				}
			}
			else if (shopnum == 1) {

				if (blassing == 0)
				{
					shopnum = 0;

					//gotoxy(45, 33); printf("                                                                                      ");

					gotoxy(95, 5); printf(consumptionitemList[0][0]);

					gotoxy(95, 7); printf(consumptionitemList[1][0]);

					gotoxy(95, 24); printf("뒤로가기");
				}

				while (true)
				{
					if (shopnum == 0)
					{
						gotoxy(93, 5);
						setColor(WHITE); printf("→");
					}
					else {
						gotoxy(93, 5);
						printf("  ");
					}

					if (shopnum == 1)
					{
						gotoxy(93, 7);
						setColor(WHITE); printf("→");
					}
					else {
						gotoxy(93, 7);
						printf("  ");
					}

					if (shopnum == 2)
					{
						gotoxy(93, 24);
						setColor(WHITE); printf("→");
					}
					else {
						gotoxy(93, 24);
						printf("  ");
					}



					if (shopnum >= 3)
					{
						shopnum = 0;
					}
					if (shopnum < 0)
					{
						shopnum = 2;
					}

					if (key == 13)
					{
						key = 0;
						if (shopnum == 0)
						{


							if (gold < 449)
							{
								setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
								setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
								setColor(WHITE); gotoxy(17, 17); printf("|           음? 가지고 있는 돈이 부족하군          |");
								setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
								setColor(WHITE); gotoxy(17, 19); printf("   \\/");
								Sleep(500);
								setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
								setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
								setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
								setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
								setColor(WHITE); gotoxy(17, 19); printf("                                                     ");

							}
							if (gold >= 450)
							{

								if (inventoryindex[0] != 0 && inventoryindex[1] != 0 && inventoryindex[2] != 0 && inventoryindex[3] != 0 && inventoryindex[4] != 0 && inventoryindex[5] != 0 && inventoryindex[6] != 0 && inventoryindex[7] != 0 && inventoryindex[8] != 0 && inventoryindex[9] != 0 && inventoryindex[10] != 0 && inventoryindex[11] != 0 && inventoryindex[12] != 0 && inventoryindex[13] != 0 && inventoryindex[14] != 0 && inventoryindex[15] != 0 && inventoryindex[16] != 0 && inventoryindex[17] != 0 && inventoryindex[18] != 0 && inventoryindex[19] != 0 && inventoryindex[20] != 0 && inventoryindex[21] != 0 && inventoryindex[22] != 0 && inventoryindex[23] != 0 && inventoryindex[24] != 0 && inventoryindex[25] != 0 && inventoryindex[26] != 0 && inventoryindex[27] != 0 && inventoryindex[28] != 0 && inventoryindex[29] != 0)
								{
									setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
									setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
									setColor(WHITE); gotoxy(17, 17); printf("|           가방에 공간이 모자라는것 같은데?       |");
									setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
									setColor(WHITE); gotoxy(17, 19); printf("   \\/");
									Sleep(500);
									setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 19); printf("                                                     ");

								}
								else
								{
									gold -= 450;

									for (int i = 0; i < 30; i++)
									{
										if (inventoryindex[i] == 0)
										{
											inventoryindex[i] = 21;
											break;
										}
									}
									setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
									setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
									setColor(WHITE); gotoxy(17, 17); printf("|                  탁월한 선택이야                 |");
									setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
									setColor(WHITE); gotoxy(17, 19); printf("   \\/");
									Sleep(500);
									setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 19); printf("                                                     ");
								}

								setColor(DAKR_YELLOW); gotoxy(110, 33); printf("%dgold", gold);
							}
						}

						if (shopnum == 1)
						{
							if (gold < 599)
							{
								setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
								setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
								setColor(WHITE); gotoxy(17, 17); printf("|           음? 가지고 있는 돈이 부족하군          |");
								setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
								setColor(WHITE); gotoxy(17, 19); printf("   \\/");
								Sleep(500);
								setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
								setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
								setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
								setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
								setColor(WHITE); gotoxy(17, 19); printf("                                                     ");
							}
							if (gold >= 600)
							{
								bool Emety = false;
								for (int i = 0; i < 30; i++) {
									if (inventoryindex[i] == 0) {
										Emety = true;
										break;
									}
								}
								if (inventoryindex[0] != 0 && inventoryindex[1] != 0 && inventoryindex[2] != 0 && inventoryindex[3] != 0 && inventoryindex[4] != 0 && inventoryindex[5] != 0 && inventoryindex[6] != 0 && inventoryindex[7] != 0 && inventoryindex[8] != 0 && inventoryindex[9] != 0 && inventoryindex[10] != 0 && inventoryindex[11] != 0 && inventoryindex[12] != 0 && inventoryindex[13] != 0 && inventoryindex[14] != 0 && inventoryindex[15] != 0 && inventoryindex[16] != 0 && inventoryindex[17] != 0 && inventoryindex[18] != 0 && inventoryindex[19] != 0 && inventoryindex[20] != 0 && inventoryindex[21] != 0 && inventoryindex[22] != 0 && inventoryindex[23] != 0 && inventoryindex[24] != 0 && inventoryindex[25] != 0 && inventoryindex[26] != 0 && inventoryindex[27] != 0 && inventoryindex[28] != 0 && inventoryindex[29] != 0)
								{
									setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
									setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
									setColor(WHITE); gotoxy(17, 17); printf("|           가방에 공간이 모자라는것 같은데?       |");
									setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
									setColor(WHITE); gotoxy(17, 19); printf("   \\/");
									Sleep(500);
									setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 19); printf("                                                     ");

								}
								else
								{
									gold -= 600;

									for (int i = 0; i < 30; i++)
									{

										if (inventoryindex[i] == 0)
										{
											inventoryindex[i] = 22;
											break;
										}
									}
									setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
									setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
									setColor(WHITE); gotoxy(17, 17); printf("|                  탁월한 선택이야                 |");
									setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
									setColor(WHITE); gotoxy(17, 19); printf("   \\/");
									Sleep(500);
									setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 19); printf("                                                     ");
								}


								setColor(DAKR_YELLOW); gotoxy(110, 33); printf("%dgold", gold);
							}
						}

						if (shopnum == 2)
						{
							gotoxy(54, 33);
							printf(" ");
						}

						if (shopnum == 3)
						{
							gotoxy(59, 33);
							printf(" ");
						}

						if (shopnum == 4)
						{
							gotoxy(64, 33);
							printf(" ");
						}

						if (shopnum == 0)
						{
							//printf
						}
						else if (shopnum == 1) {


						}
						else if (shopnum == 2) {

							shop();
						}


						shopnum = 0;
					}

					if (_kbhit())
					{
						key = _getch();
						if (key == 224)
						{
							key = _getch();
							switch (key)
							{
							case 80:
								textnum++;
								shopnum++;//위
								break;
							case 72:
								textnum++;
								shopnum--;//아래
								break;
							}
						}
					}
				}
			}
			else if (shopnum == 2) {

				if (blassing == 0)
				{
					shopnum = 0;

					//gotoxy(45, 33); printf("                                                                                      ");

					gotoxy(95, 5); printf(OtheritemList[0][0]);
					gotoxy(95, 7); printf(OtheritemList[1][0]);
					gotoxy(95, 9); printf(OtheritemList[2][0]);

					gotoxy(95, 24); printf("뒤로가기");
				}

				while (true)
				{
					if (shopnum == 0)
					{
						gotoxy(93, 5);
						setColor(WHITE); printf("→");
					}
					else {
						gotoxy(93, 5);
						printf("  ");
					}

					if (shopnum == 1)
					{
						gotoxy(93, 7);
						setColor(WHITE); printf("→");
					}
					else {
						gotoxy(93, 7);
						printf("  ");
					}

					if (shopnum == 2)
					{
						gotoxy(93, 9);
						setColor(WHITE); printf("→");
					}
					else {
						gotoxy(93, 9);
						printf("  ");
					}

					if (shopnum == 3)
					{
						gotoxy(93, 24);
						setColor(WHITE); printf("→");
					}
					else {
						gotoxy(93, 24);
						printf("  ");
					}



					if (shopnum >= 4)
					{
						shopnum = 0;
					}
					if (shopnum < 0)
					{
						shopnum = 3;
					}

					if (key == 13)
					{
						key = 0;
						if (shopnum == 0)
						{
							if (gold < 49)
							{
								setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
								setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
								setColor(WHITE); gotoxy(17, 17); printf("|           음? 가지고 있는 돈이 부족하군          |");
								setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
								setColor(WHITE); gotoxy(17, 19); printf("   \\/");
								Sleep(500);
								setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
								setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
								setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
								setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
								setColor(WHITE); gotoxy(17, 19); printf("                                                     ");
							}
							if (gold >= 50)
							{
								bool Emety = false;
								for (int i = 0; i < 30; i++) {
									if (inventoryindex[i] == 0) {
										Emety = true;
										break;
									}
								}
								if (inventoryindex[0] != 0 && inventoryindex[1] != 0 && inventoryindex[2] != 0 && inventoryindex[3] != 0 && inventoryindex[4] != 0 && inventoryindex[5] != 0 && inventoryindex[6] != 0 && inventoryindex[7] != 0 && inventoryindex[8] != 0 && inventoryindex[9] != 0 && inventoryindex[10] != 0 && inventoryindex[11] != 0 && inventoryindex[12] != 0 && inventoryindex[13] != 0 && inventoryindex[14] != 0 && inventoryindex[15] != 0 && inventoryindex[16] != 0 && inventoryindex[17] != 0 && inventoryindex[18] != 0 && inventoryindex[19] != 0 && inventoryindex[20] != 0 && inventoryindex[21] != 0 && inventoryindex[22] != 0 && inventoryindex[23] != 0 && inventoryindex[24] != 0 && inventoryindex[25] != 0 && inventoryindex[26] != 0 && inventoryindex[27] != 0 && inventoryindex[28] != 0 && inventoryindex[29] != 0)
								{
									setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
									setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
									setColor(WHITE); gotoxy(17, 17); printf("|           가방에 공간이 모자라는것 같은데?       |");
									setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
									setColor(WHITE); gotoxy(17, 19); printf("   \\/");
									Sleep(500);
									setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 19); printf("                                                     ");

								}
								else
								{
									gold -= 50;

									for (int i = 0; i < 30; i++)
									{
										if (inventoryindex[i] == 0)
										{
											inventoryindex[i] = 41;
											break;
										}
									}
									setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
									setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
									setColor(WHITE); gotoxy(17, 17); printf("|                  탁월한 선택이야                 |");
									setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
									setColor(WHITE); gotoxy(17, 19); printf("   \\/");
									Sleep(500);
									setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 19); printf("                                                     ");
								}

								setColor(DAKR_YELLOW); gotoxy(110, 33); printf("%dgold", gold);
							}
						}

						if (shopnum == 1)
						{
							if (gold < 79)
							{
								setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
								setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
								setColor(WHITE); gotoxy(17, 17); printf("|           음? 가지고 있는 돈이 부족하군          |");
								setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
								setColor(WHITE); gotoxy(17, 19); printf("   \\/");
								Sleep(500);
								setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
								setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
								setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
								setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
								setColor(WHITE); gotoxy(17, 19); printf("                                                     ");
							}
							if (gold >= 80)
							{
								bool Emety = false;
								for (int i = 0; i < 30; i++) {
									if (inventoryindex[i] == 0) {
										Emety = true;
										break;
									}
								}
								if (inventoryindex[0] != 0 && inventoryindex[1] != 0 && inventoryindex[2] != 0 && inventoryindex[3] != 0 && inventoryindex[4] != 0 && inventoryindex[5] != 0 && inventoryindex[6] != 0 && inventoryindex[7] != 0 && inventoryindex[8] != 0 && inventoryindex[9] != 0 && inventoryindex[10] != 0 && inventoryindex[11] != 0 && inventoryindex[12] != 0 && inventoryindex[13] != 0 && inventoryindex[14] != 0 && inventoryindex[15] != 0 && inventoryindex[16] != 0 && inventoryindex[17] != 0 && inventoryindex[18] != 0 && inventoryindex[19] != 0 && inventoryindex[20] != 0 && inventoryindex[21] != 0 && inventoryindex[22] != 0 && inventoryindex[23] != 0 && inventoryindex[24] != 0 && inventoryindex[25] != 0 && inventoryindex[26] != 0 && inventoryindex[27] != 0 && inventoryindex[28] != 0 && inventoryindex[29] != 0)
								{
									setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
									setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
									setColor(WHITE); gotoxy(17, 17); printf("|           가방에 공간이 모자라는것 같은데?       |");
									setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
									setColor(WHITE); gotoxy(17, 19); printf("   \\/");
									Sleep(500);
									setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 19); printf("                                                     ");
								}
								else
								{
									gold -= 80;
									for (int i = 0; i < 30; i++)
									{
										if (inventoryindex[i] == 0)
										{
											inventoryindex[i] = 42;
											break;
										}
									}
									setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
									setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
									setColor(WHITE); gotoxy(17, 17); printf("|                  탁월한 선택이야                 |");
									setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
									setColor(WHITE); gotoxy(17, 19); printf("   \\/");
									Sleep(500);
									setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 19); printf("                                                     ");
								}



								setColor(DAKR_YELLOW); gotoxy(110, 33); printf("%dgold", gold);
							}
						}

						if (shopnum == 2)
						{
							if (gold < 119)
							{
								setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
								setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
								setColor(WHITE); gotoxy(17, 17); printf("|           음? 가지고 있는 돈이 부족하군          |");
								setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
								setColor(WHITE); gotoxy(17, 19); printf("   \\/");
								Sleep(500);
								setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
								setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
								setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
								setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
								setColor(WHITE); gotoxy(17, 19); printf("                                                     ");
							}
							if (gold >= 120)
							{
								bool Emety = false;
								for (int i = 0; i < 30; i++) {
									if (inventoryindex[i] == 0) {
										Emety = true;
										break;
									}
								}
								if (inventoryindex[0] != 0 && inventoryindex[1] != 0 && inventoryindex[2] != 0 && inventoryindex[3] != 0 && inventoryindex[4] != 0 && inventoryindex[5] != 0 && inventoryindex[6] != 0 && inventoryindex[7] != 0 && inventoryindex[8] != 0 && inventoryindex[9] != 0 && inventoryindex[10] != 0 && inventoryindex[11] != 0 && inventoryindex[12] != 0 && inventoryindex[13] != 0 && inventoryindex[14] != 0 && inventoryindex[15] != 0 && inventoryindex[16] != 0 && inventoryindex[17] != 0 && inventoryindex[18] != 0 && inventoryindex[19] != 0 && inventoryindex[20] != 0 && inventoryindex[21] != 0 && inventoryindex[22] != 0 && inventoryindex[23] != 0 && inventoryindex[24] != 0 && inventoryindex[25] != 0 && inventoryindex[26] != 0 && inventoryindex[27] != 0 && inventoryindex[28] != 0 && inventoryindex[29] != 0)
								{
									setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
									setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
									setColor(WHITE); gotoxy(17, 17); printf("|           가방에 공간이 모자라는것 같은데?       |");
									setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
									setColor(WHITE); gotoxy(17, 19); printf("   \\/");
									Sleep(500);
									setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 19); printf("                                                     ");

								}
								else
								{
									gold -= 120;

									for (int i = 0; i < 30; i++)
									{
										if (inventoryindex[i] == 0)
										{
											inventoryindex[i] = 43;
											break;
										}
									}
									setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
									setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
									setColor(WHITE); gotoxy(17, 17); printf("|                  탁월한 선택이야                 |");
									setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
									setColor(WHITE); gotoxy(17, 19); printf("   \\/");
									Sleep(500);
									setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
									setColor(WHITE); gotoxy(17, 19); printf("                                                     ");
								}

								setColor(DAKR_YELLOW); gotoxy(110, 33); printf("%dgold", gold);
							}
						}

						if (shopnum == 2)
						{
							gotoxy(54, 33);
							printf(" ");
						}

						if (shopnum == 3)
						{
							gotoxy(59, 33);
							printf(" ");
						}

						if (shopnum == 4)
						{
							gotoxy(64, 33);
							printf(" ");
						}

						if (shopnum == 0)
						{
							//printf
						}
						else if (shopnum == 1) {


						}
						else if (shopnum == 3) {

							shop();
						}


						shopnum = 0;
					}


					if (_kbhit())
					{
						key = _getch();
						if (key == 224)
						{
							key = _getch();
							switch (key)
							{
							case 80:
								textnum++;
								shopnum++;//위
								break;
							case 72:
								textnum++;
								shopnum--;//아래
								break;
							}
						}
					}
				}
			}
			else if (shopnum == 3) {

				int itemnum = 0;
				int itemnum2 = 0;
				TextmainUI();
				gotoxy(51, 5); printf("________________________________________________");
				gotoxy(71, 5); printf("인벤토리");

				int pos = 7;
				for (int i = 0; i < 10; i++)
				{
					if (inventoryindex[i] == 0)
					{
						setColor(WHITE); gotoxy(55, pos); printf("                                         ");
						pos += 2;
					}
					if (inventoryindex[i] == 1)
					{
						setColor(WHITE); gotoxy(55, pos); printf("나무로 만든 단도 (150gold)     ");
						pos += 2;
					}

					if (inventoryindex[i] == 2)
					{
						setColor(WHITE); gotoxy(55, pos); printf("나무로 만든 대검 (200gold)   ");
						pos += 2;
					}
					if (inventoryindex[i] == 21)
					{
						setColor(WHITE); gotoxy(55, pos); printf("미미한 체력회복 물약 (300gold)   ");
						pos += 2;
					}
					if (inventoryindex[i] == 22)
					{
						setColor(WHITE); gotoxy(55, pos); printf("조금은 효과적인 체력회복 물약 (450gold)   ");
						pos += 2;
					}
					if (inventoryindex[i] == 41)
					{
						setColor(WHITE); gotoxy(55, pos); printf("허름한 가죽 (30gold)              ");
						pos += 2;
					}
					if (inventoryindex[i] == 42)
					{
						setColor(WHITE); gotoxy(55, pos); printf("작은 고블린의 이빨 (50gold)         ");
						pos += 2;
					}
					if (inventoryindex[i] == 43)
					{
						setColor(WHITE); gotoxy(55, pos); printf("사카밤파스피스  (80gold)         ");
						pos += 2;
					}
					setColor(RED); gotoxy(55, 26); printf("나가기");
				}

				int key = _getch();

				while (true)// 아이템 목록 고르기
				{
					if (itemnum2 == 0)
					{
						pos = 7;
						for (int i = 0; i < 10; i++)
						{
							if (inventoryindex[i] == 0)
							{
								setColor(WHITE); gotoxy(55, pos); printf("                                         ");
								pos += 2;
							}
							if (inventoryindex[i] == 1)
							{
								setColor(WHITE); gotoxy(55, pos); printf("나무로 만든 단도 (150gold)     ");
								pos += 2;
							}

							if (inventoryindex[i] == 2)
							{
								setColor(WHITE); gotoxy(55, pos); printf("나무로 만든 대검 (200gold)   ");
								pos += 2;
							}
							if (inventoryindex[i] == 21)
							{
								setColor(WHITE); gotoxy(55, pos); printf("미미한 체력회복 물약 (300gold)   ");
								pos += 2;
							}
							if (inventoryindex[i] == 22)
							{
								setColor(WHITE); gotoxy(55, pos); printf("조금은 효과적인 체력회복 물약 (450gold)   ");
								pos += 2;
							}
							if (inventoryindex[i] == 41)
							{
								setColor(WHITE); gotoxy(55, pos); printf("허름한 가죽 (30gold)              ");
								pos += 2;
							}
							if (inventoryindex[i] == 42)
							{
								setColor(WHITE); gotoxy(55, pos); printf("작은 고블린의 이빨 (50gold)         ");
								pos += 2;
							}
							if (inventoryindex[i] == 43)
							{
								setColor(WHITE); gotoxy(55, pos); printf("사카밤파스피스  (80gold)         ");
								pos += 2;
							}
							setColor(RED); gotoxy(55, 26); printf("나가기");
						}
					}
					if (itemnum2 == 1)
					{
						pos = 7;
						for (int i = 10; i < 20; i++)
						{
							if (inventoryindex[i] == 0)
							{
								setColor(WHITE); gotoxy(55, pos); printf("                                         ");
								pos += 2;
							}
							if (inventoryindex[i] == 1)
							{
								setColor(WHITE); gotoxy(55, pos); printf("나무로 만든 단도 (150gold)     ");
								pos += 2;
							}

							if (inventoryindex[i] == 2)
							{
								setColor(WHITE); gotoxy(55, pos); printf("나무로 만든 대검 (200gold)   ");
								pos += 2;
							}
							if (inventoryindex[i] == 21)
							{
								setColor(WHITE); gotoxy(55, pos); printf("미미한 체력회복 물약 (300gold)   ");
								pos += 2;
							}
							if (inventoryindex[i] == 22)
							{
								setColor(WHITE); gotoxy(55, pos); printf("조금은 효과적인 체력회복 물약 (450gold)   ");
								pos += 2;
							}
							if (inventoryindex[i] == 41)
							{
								setColor(WHITE); gotoxy(55, pos); printf("허름한 가죽 (30gold)              ");
								pos += 2;
							}
							if (inventoryindex[i] == 42)
							{
								setColor(WHITE); gotoxy(55, pos); printf("작은 고블린의 이빨 (50gold)         ");
								pos += 2;
							}
							if (inventoryindex[i] == 43)
							{
								setColor(WHITE); gotoxy(55, pos); printf("사카밤파스피스  (80gold)         ");
								pos += 2;
							}
						}
						setColor(RED); gotoxy(55, 26); printf("나가기");
					}

					if (itemnum2 == 2)
					{
						pos = 7;
						for (int i = 20; i < 30; i++)
						{
							if (inventoryindex[i] == 0)
							{
								setColor(WHITE); gotoxy(55, pos); printf("                                         ");
								pos += 2;
							}
							if (inventoryindex[i] == 1)
							{
								setColor(WHITE); gotoxy(55, pos); printf("나무로 만든 단도 (150gold)     ");
								pos += 2;
							}

							if (inventoryindex[i] == 2)
							{
								setColor(WHITE); gotoxy(55, pos); printf("나무로 만든 대검 (200gold)   ");
								pos += 2;
							}
							if (inventoryindex[i] == 21)
							{
								setColor(WHITE); gotoxy(55, pos); printf("미미한 체력회복 물약 (300gold)   ");
								pos += 2;
							}
							if (inventoryindex[i] == 22)
							{
								setColor(WHITE); gotoxy(55, pos); printf("조금은 효과적인 체력회복 물약 (450gold)   ");
								pos += 2;
							}
							if (inventoryindex[i] == 41)
							{
								setColor(WHITE); gotoxy(55, pos); printf("허름한 가죽 (30gold)              ");
								pos += 2;
							}
							if (inventoryindex[i] == 42)
							{
								setColor(WHITE); gotoxy(55, pos); printf("작은 고블린의 이빨 (50gold)         ");
								pos += 2;
							}
							if (inventoryindex[i] == 43)
							{
								setColor(WHITE); gotoxy(55, pos); printf("사카밤파스피스  (80gold)         ");
								pos += 2;
							}
						}
						setColor(RED); gotoxy(55, 26); printf("나가기");
					}

					if (itemnum == 0)
					{
						gotoxy(53, 7); setColor(WHITE); printf("→");
						num = 0;
					}
					else
					{
						gotoxy(53, 7); setColor(WHITE); printf("  ");
					}

					if (itemnum == 1)
					{
						gotoxy(53, 9); setColor(WHITE); printf("→");
						num = 1;
					}
					else
					{
						gotoxy(53, 9); setColor(WHITE); printf("  ");
					}

					if (itemnum == 2)
					{
						gotoxy(53, 11); setColor(WHITE); printf("→");
						num = 2;
					}
					else
					{
						gotoxy(53, 11); setColor(WHITE); printf("  ");
					}

					if (itemnum == 3)
					{
						gotoxy(53, 13); setColor(WHITE); printf("→");
						num = 3;
					}
					else
					{
						gotoxy(53, 13); setColor(WHITE); printf("  ");
					}

					if (itemnum == 4)
					{
						gotoxy(53, 15); setColor(WHITE); printf("→");
						num = 4;
					}
					else
					{
						gotoxy(53, 15); setColor(WHITE); printf("  ");
					}

					if (itemnum == 5)
					{
						gotoxy(53, 17); setColor(WHITE); printf("→");
						num = 5;
					}
					else
					{
						gotoxy(53, 17); setColor(WHITE); printf("  ");
					}

					if (itemnum == 6)
					{
						gotoxy(53, 19); setColor(WHITE); printf("→");
						num = 6;
					}
					else
					{
						gotoxy(53, 19); setColor(WHITE); printf("  ");
					}

					if (itemnum == 7)
					{
						gotoxy(53, 21); setColor(WHITE); printf("→");
						num = 7;
					}
					else
					{
						gotoxy(53, 21); setColor(WHITE); printf("  ");
					}

					if (itemnum == 8)
					{
						gotoxy(53, 23); setColor(WHITE); printf("→");
						num = 8;
					}
					else
					{
						gotoxy(53, 23); setColor(WHITE); printf("  ");
					}

					if (itemnum == 9)
					{
						gotoxy(53, 25); setColor(WHITE); printf("→");
						num = 9;
					}
					else
					{
						gotoxy(53, 25); setColor(WHITE); printf("  ");
					}

					if (itemnum == 10)
					{
						gotoxy(53, 26); setColor(WHITE); printf("→");
					}
					else
					{
						gotoxy(53, 26); setColor(WHITE); printf("  ");
					}

					if (itemnum >= 11)
					{
						itemnum = 0;
					}
					if (itemnum < 0)
					{
						itemnum = 10;
					}

					if (key == 13)
					{
						if (itemnum == 0)
						{
							page = 0;
							page1 = 10;
							page2 = 20;
						}
						if (itemnum == 1)
						{
							page = 1;
							page1 = 11;
							page2 = 21;
						}
						if (itemnum == 2)
						{
							page = 2;
							page1 = 12;
							page2 = 22;
						}
						if (itemnum == 3)
						{
							page = 3;
							page1 = 13;
							page2 = 23;
						}
						if (itemnum == 4)
						{
							page = 4;
							page1 = 14;
							page2 = 24;
						}
						if (itemnum == 5)
						{
							page = 5;
							page1 = 15;
							page2 = 25;
						}
						if (itemnum == 6)
						{
							page = 6;
							page1 = 16;
							page2 = 26;
						}
						if (itemnum == 7)
						{
							page = 7;
							page1 = 17;
							page2 = 27;
						}
						if (itemnum == 8)
						{
							page = 8;
							page1 = 18;
							page2 = 28;
						}
						if (itemnum == 9)
						{
							page = 9;
							page1 = 19;
							page2 = 29;
						}
						if (itemnum == num)
						{
							if (itemnum2 == 0)
							{
								if (inventoryindex[page] == 1)
								{
									gold += 150;
									gotoxy(110, 33); printf("%dgold", gold);
								}
								if (inventoryindex[page] == 2)
								{
									gold += 200;
									gotoxy(110, 33); printf("%dgold", gold);
								}
								if (inventoryindex[page] == 21)
								{
									gold += 300;
									gotoxy(110, 33); printf("%dgold", gold);
								}
								if (inventoryindex[page] == 22)
								{
									gold += 450;
									gotoxy(110, 33); printf("%dgold", gold);
								}
								if (inventoryindex[page] == 41)
								{

									gold += 30;
									gotoxy(110, 33); printf("%dgold", gold);
								}
								if (inventoryindex[page] == 42)
								{
									gold += 50;
									gotoxy(110, 33); printf("%dgold", gold);
								}
								if (inventoryindex[page] == 43)
								{
									gold += 80;
									gotoxy(110, 33); printf("%dgold", gold);
								}
								inventoryindex[page] = 0;

							}

							if (itemnum2 == 1)
							{
								if (inventoryindex[page1] == 1)
								{
									gold += 150;
									gotoxy(110, 33); printf("%dgold", gold);
								}
								if (inventoryindex[page1] == 2)
								{
									gold += 200;
									gotoxy(110, 33); printf("%dgold", gold);
								}
								if (inventoryindex[page1] == 21)
								{
									gold += 300;
									gotoxy(110, 33); printf("%dgold", gold);
								}
								if (inventoryindex[page1] == 22)
								{
									gold += 450;
									gotoxy(110, 33); printf("%dgold", gold);
								}
								if (inventoryindex[page1] == 41)
								{

									gold += 30;
									gotoxy(110, 33); printf("%dgold", gold);
								}
								if (inventoryindex[page1] == 42)
								{
									gold += 50;
									gotoxy(110, 33); printf("%dgold", gold);
								}
								if (inventoryindex[page1] == 43)
								{
									gold += 80;
									gotoxy(110, 33); printf("%dgold", gold);
								}
								inventoryindex[page1] = 0;

							}

							if (itemnum2 == 2)
							{
								if (inventoryindex[page2] == 1)
								{
									gold += 150;
									gotoxy(110, 33); printf("%dgold", gold);
								}
								if (inventoryindex[page2] == 2)
								{
									gold += 200;
									gotoxy(110, 33); printf("%dgold", gold);
								}
								if (inventoryindex[page2] == 21)
								{
									gold += 300;
									gotoxy(110, 33); printf("%dgold", gold);
								}
								if (inventoryindex[page2] == 22)
								{
									gold += 450;
									gotoxy(110, 33); printf("%dgold", gold);
								}
								if (inventoryindex[page2] == 41)
								{

									gold += 30;
									gotoxy(110, 33); printf("%dgold", gold);
								}
								if (inventoryindex[page2] == 42)
								{
									gold += 50;
									gotoxy(110, 33); printf("%dgold", gold);
								}
								if (inventoryindex[page2] == 43)
								{
									gold += 80;
									gotoxy(110, 33); printf("%dgold", gold);
								}
								inventoryindex[page2] = 0;

							}
						}

						if (itemnum == 10)
						{
							shop();
						}
					}

					if (_kbhit())
					{
						key = _getch();
						if (key == 224)
						{
							key = _getch();
							switch (key)
							{
							case 77:
								itemnum2++;//오른쪽
								break;
							case 75:
								itemnum2--;//왼쪽
								break;
							case 80:
								itemnum++;//위
								break;
							case 72:
								itemnum--;//아래
								break;
							}
						}
					}
					if (itemnum2 >= 3)
					{
						itemnum2 = 2;
					}
					if (itemnum2 < 0)
					{
						itemnum2 = 0;
					}
				}
				break;
			}
			else if (shopnum == 4) {

				petiavillage();
			}

			shopnum = 0;
		}

		if (key == 105)
		{
			playerinventoty();
			shop();
		}

		if (_kbhit())
		{
			key = _getch();
			if (key == 224)
			{
				key = _getch();
				switch (key)
				{
				case 77:
					textnum++;
					shopnum++;//오른쪽
					break;
				case 75:
					textnum++;
					shopnum--;//왼쪽
					break;
				}
			}
		}

		if (textnum == 0)
		{
			setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
			setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
			setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
			setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
			setColor(WHITE); gotoxy(17, 19); printf("                                                     ");

		}
		if (textnum == 3)
		{
			setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
			setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
			setColor(WHITE); gotoxy(17, 17); printf("|                        음...?                    |");
			setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
			setColor(WHITE); gotoxy(17, 19); printf("   \\/");
		}
		if (textnum == 6)
		{
			setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
			setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
			setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
			setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
			setColor(WHITE); gotoxy(17, 19); printf("                                                     ");

		}
		if (textnum == 18)
		{
			setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
			setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
			setColor(WHITE); gotoxy(17, 17); printf("|     내가 안보인다고? 너 지긍 나 놀리는거냐?      |");
			setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
			setColor(WHITE); gotoxy(17, 19); printf("   \\/");

		}
		if (textnum == 21)
		{
			setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
			setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
			setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
			setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
			setColor(WHITE); gotoxy(17, 19); printf("                                                     ");

		}
		if (textnum == 39)
		{
			setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
			setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
			setColor(WHITE); gotoxy(17, 17); printf("|        우리가게는 있는건 있고 없는건 없어        |");
			setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
			setColor(WHITE); gotoxy(17, 19); printf("   \\/");

		}
		if (textnum == 43)
		{
			setColor(WHITE); gotoxy(17, 15); printf("                                                     ");
			setColor(WHITE); gotoxy(17, 16); printf("                                                     ");
			setColor(WHITE); gotoxy(17, 17); printf("                                                     ");
			setColor(WHITE); gotoxy(17, 18); printf("                                                     ");
			setColor(WHITE); gotoxy(17, 19); printf("                                                     ");

		}
		if (textnum == 53)
		{
			setColor(WHITE); gotoxy(17, 15); printf(" __________________________________________________");
			setColor(WHITE); gotoxy(17, 16); printf("/                                                  \\");
			setColor(WHITE); gotoxy(17, 17); printf("|        어떄 친구 요즘은 얼굴이 좋아보이는군      |");
			setColor(WHITE); gotoxy(17, 18); printf("\\__  ______________________________________________/");
			setColor(WHITE); gotoxy(17, 19); printf("   \\/");
		}
		if (textnum == 56)
		{
			textnum = 0;
		}

	}

}

void shopimage() {

	setColor(WHITE); gotoxy(1, 1);  printf("                                                                                                                                            ");
	setColor(DAKR_YELLOW); gotoxy(4, 3);  printf("       \\___|__|__|__|__|__|__|__|__|__|___|__|__|__|__|__|__|__|__|__|___/              _______________________________________________     ");
	setColor(DAKR_YELLOW); gotoxy(4, 4);  printf("                 | |                                         | |                        |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 5);  printf("        _________|_|_________________________________________|_|_________               |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 6);  printf("        |           ___         ___         ___         ___             |               |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 7);  printf("        |          /\\  \\       /\\__\\       /\\  \\       /\\  \\            |               |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 8);  printf("        |         /..\\  \\     /./__/_     /..\\  \\     /..\\  \\           |               |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 9);  printf("        |        /\\.\\.\\__\\   /..\\/\\__\\   /./\\.\\__\\   /..\\.\\__\\          |               |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 10); printf("        |        \\.\\.\\/__/   \\/\\../  /   \\.\\/./  /   \\/\\../  /          |               |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 11); printf("        |         \\../  /      /./  /     \\../  /       \\/__/           |               |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 12); printf("        |          \\/__/       \\/__/       \\/__/                        |               |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 13); printf("        |_______________________________________________________________|               |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 14); printf("                                                                                        |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 15); printf("                                                                                        |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 16); printf("                                                                                        |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 17); printf("                                                                                        |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 18); printf("                                                                                        |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 19); printf("                                                                                        |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 20); printf("       ____________________________________________________________________             |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 21); printf("         |                                                              |               |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 22); printf("         |                                                              |               |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 23); printf("         |                                                              |               |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 24); printf("         |                                                              |               |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 25); printf("         |                                                              |               |                                             |     ");
	setColor(DAKR_YELLOW); gotoxy(4, 26); printf("         |                                                              |               |_____________________________________________|     ");
	setColor(DAKR_YELLOW); gotoxy(4, 27); printf("                                                                                                                                            ");

}

void playerinventoty() {

inventorystart:
	int itemnum = 0;
	int itemnum2 = 0;
	int num = 0;

	TextmainUI();
	gotoxy(51, 5); printf("________________________________________________");
	gotoxy(71, 5); printf("인벤토리");
	int pos = 7;

	for (int i = 0; i < 10; i++)
	{
		if (inventoryindex[i] == 0)
		{
			setColor(WHITE); gotoxy(55, pos); printf("                             ");
			pos += 2;
		}
		if (inventoryindex[i] == 1)
		{
			setColor(WHITE);
			if (weapon == 1)
			{
				setColor(SKYBLUE);
			}
			gotoxy(55, pos); printf("나무로 만든 단도            ");
			setColor(WHITE);
			pos += 2;
		}

		if (inventoryindex[i] == 2)
		{
			setColor(WHITE);
			if (weapon == 2)
			{
				setColor(SKYBLUE);
			}
			gotoxy(55, pos); printf("나무로 만든 대검            ");
			setColor(WHITE);
			pos += 2;
		}
		if (inventoryindex[i] == 21)
		{
			setColor(WHITE); gotoxy(55, pos); printf("미미한 체력회복 물약            ");
			pos += 2;
		}
		if (inventoryindex[i] == 22)
		{
			setColor(WHITE); gotoxy(55, pos); printf("조금은 효과적인 체력회복 물약    ");
			pos += 2;
		}
		if (inventoryindex[i] == 41)
		{
			setColor(WHITE); gotoxy(55, pos); printf("허름한 가죽                       ");
			pos += 2;
		}
		if (inventoryindex[i] == 42)
		{
			setColor(WHITE); gotoxy(55, pos); printf("작은 고블린의 이빨                ");
			pos += 2;
		}
		if (inventoryindex[i] == 43)
		{
			setColor(WHITE); gotoxy(55, pos); printf("사카밤파스피스                  ");
			pos += 2;
		}
		setColor(RED); gotoxy(55, 26); printf("나가기");
	}

	int key = _getch();

	while (true)// 아이템 목록 고르기
	{
		if (itemnum2 == 0)
		{
			pos = 7;
			for (int i = 0; i < 10; i++)
			{
				if (inventoryindex[i] == 0)
				{
					setColor(WHITE); gotoxy(55, pos); printf("                             ");
					pos += 2;
				}
				if (inventoryindex[i] == 1)
				{
					setColor(WHITE); gotoxy(55, pos);
					if (weapon == 1)
					{
						setColor(SKYBLUE);
					}
					printf("나무로 만든 단도          ");
					pos += 2;
				}

				if (inventoryindex[i] == 2)
				{
					setColor(WHITE); gotoxy(55, pos);
					if (weapon == 2)
					{
						setColor(SKYBLUE);
					}
					printf("나무로 만든 대검           ");
					pos += 2;
				}
				if (inventoryindex[i] == 21)
				{
					setColor(WHITE); gotoxy(55, pos); printf("미미한 체력회복 물약          ");
					pos += 2;
				}
				if (inventoryindex[i] == 22)
				{
					setColor(WHITE); gotoxy(55, pos); printf("조금은 효과적인 체력회복 물약            ");
					pos += 2;
				}
				if (inventoryindex[i] == 41)
				{
					setColor(WHITE); gotoxy(55, pos); printf("허름한 가죽                        ");
					pos += 2;
				}
				if (inventoryindex[i] == 42)
				{
					setColor(WHITE); gotoxy(55, pos); printf("작은 고블린의 이빨                  ");
					pos += 2;
				}
				if (inventoryindex[i] == 43)
				{
					setColor(WHITE); gotoxy(55, pos); printf("사카밤파스피스                  ");
					pos += 2;
				}
				setColor(RED); gotoxy(55, 26); printf("나가기");
			}
		}
		if (itemnum2 == 1)
		{
			pos = 7;
			for (int i = 10; i < 20; i++)
			{
				if (inventoryindex[i] == 0)
				{
					setColor(WHITE); gotoxy(55, pos); printf("                             ");
					pos += 2;
				}
				if (inventoryindex[i] == 1)
				{
					setColor(WHITE); gotoxy(55, pos);
					if (weapon == 1)
					{
						setColor(SKYBLUE);
					}
					printf("나무로 만든 단도          ");
					setColor(WHITE);
					pos += 2;
				}

				if (inventoryindex[i] == 2)
				{
					setColor(WHITE); gotoxy(55, pos);
					if (weapon == 2)
					{
						setColor(SKYBLUE);
					}
					printf("나무로 만든 대검          ");
					setColor(WHITE);
					pos += 2;
				}
				if (inventoryindex[i] == 21)
				{
					setColor(WHITE); gotoxy(55, pos); printf("미미한 체력회복 물약           ");
					pos += 2;
				}
				if (inventoryindex[i] == 22)
				{
					setColor(WHITE); gotoxy(55, pos); printf("조금은 효과적인 체력회복 물약             ");
					pos += 2;
				}
				if (inventoryindex[i] == 41)
				{
					setColor(WHITE); gotoxy(55, pos); printf("허름한 가죽                        ");
					pos += 2;
				}
				if (inventoryindex[i] == 42)
				{
					setColor(WHITE); gotoxy(55, pos); printf("작은 고블린의 이빨                 ");
					pos += 2;
				}
				if (inventoryindex[i] == 43)
				{
					setColor(WHITE); gotoxy(55, pos); printf("사카밤파스피스                  ");
					pos += 2;
				}
			}
			setColor(RED); gotoxy(55, 26); printf("나가기");
		}

		if (itemnum2 == 2)
		{
			pos = 7;
			for (int i = 20; i < 30; i++)
			{
				if (inventoryindex[i] == 0)
				{
					setColor(WHITE); gotoxy(55, pos); printf("                             ");
					pos += 2;
				}
				if (inventoryindex[i] == 1)
				{
					setColor(WHITE); gotoxy(55, pos);
					if (weapon == 1)
					{
						setColor(SKYBLUE);
					}
					printf("나무로 만든 단도          ");
					setColor(WHITE);
					pos += 2;
				}

				if (inventoryindex[i] == 2)
				{
					setColor(WHITE); gotoxy(55, pos);
					if (weapon == 2)
					{
						setColor(SKYBLUE);
					}
					printf("나무로 만든 대검          ");
					setColor(WHITE);
					pos += 2;
				}
				if (inventoryindex[i] == 21)
				{
					setColor(WHITE); gotoxy(55, pos); printf("미미한 체력회복 물약          ");
					pos += 2;
				}
				if (inventoryindex[i] == 22)
				{
					setColor(WHITE); gotoxy(55, pos); printf("조금은 효과적인 체력회복 물약            ");
					pos += 2;
				}
				if (inventoryindex[i] == 41)
				{
					setColor(WHITE); gotoxy(55, pos); printf("허름한 가죽                       ");
					pos += 2;
				}
				if (inventoryindex[i] == 42)
				{
					setColor(WHITE); gotoxy(55, pos); printf("작은 고블린의 이빨                  ");
					pos += 2;
				}
				if (inventoryindex[i] == 43)
				{
					setColor(WHITE); gotoxy(55, pos); printf("사카밤파스피스                  ");
					pos += 2;
				}

			}
			setColor(RED); gotoxy(55, 26); printf("나가기");
		}

		if (itemnum == 0)
		{
			gotoxy(54, 7); setColor(WHITE); printf("→");
			num = 0;
		}
		else
		{
			gotoxy(54, 7); setColor(WHITE); printf(" ");
		}

		if (itemnum == 1)
		{
			gotoxy(54, 9); setColor(WHITE); printf("→");
			num = 1;
		}
		else
		{
			gotoxy(54, 9); setColor(WHITE); printf(" ");
		}

		if (itemnum == 2)
		{
			gotoxy(54, 11); setColor(WHITE); printf("→");
			num = 2;
		}
		else
		{
			gotoxy(54, 11); setColor(WHITE); printf(" ");
		}

		if (itemnum == 3)
		{
			gotoxy(54, 13); setColor(WHITE); printf("→");
			num = 3;
		}
		else
		{
			gotoxy(54, 13); setColor(WHITE); printf(" ");
		}

		if (itemnum == 4)
		{
			gotoxy(54, 15); setColor(WHITE); printf("→");
			num = 4;
		}
		else
		{
			gotoxy(54, 15); setColor(WHITE); printf(" ");
		}

		if (itemnum == 5)
		{
			gotoxy(54, 17); setColor(WHITE); printf("→");
			num = 5;
		}
		else
		{
			gotoxy(54, 17); setColor(WHITE); printf(" ");
		}

		if (itemnum == 6)
		{
			gotoxy(54, 19); setColor(WHITE); printf("→");
			num = 6;
		}
		else
		{
			gotoxy(54, 19); setColor(WHITE); printf(" ");
		}

		if (itemnum == 7)
		{
			gotoxy(54, 21); setColor(WHITE); printf("→");
			num = 7;
		}
		else
		{
			gotoxy(54, 21); setColor(WHITE); printf(" ");
		}

		if (itemnum == 8)
		{
			gotoxy(54, 23); setColor(WHITE); printf("→");
			num = 8;
		}
		else
		{
			gotoxy(54, 23); setColor(WHITE); printf(" ");
		}

		if (itemnum == 9)
		{
			gotoxy(54, 25); setColor(WHITE); printf("→");
			num = 9;
		}
		else
		{
			gotoxy(54, 25); setColor(WHITE); printf(" ");
		}

		if (itemnum == 10)
		{
			gotoxy(54, 26); setColor(WHITE); printf("→");
		}
		else
		{
			gotoxy(54, 26); setColor(WHITE); printf(" ");
		}

		if (itemnum >= 11)
		{
			itemnum = 0;
		}
		if (itemnum < 0)
		{
			itemnum = 10;
		}
		//------------------------------------------------------------------------
		if (key == 13)
		{

			int page = 0, page1 = 0, page2 = 0;
			key = 0;
			if (itemnum == num)
			{
				if (itemnum == 0)
				{
					page = 0;
					page1 = 10;
					page2 = 20;
				}
				if (itemnum == 1)
				{
					page = 1;
					page1 = 11;
					page2 = 21;
				}
				if (itemnum == 2)
				{
					page = 2;
					page1 = 12;
					page2 = 22;
				}
				if (itemnum == 3)
				{
					page = 3;
					page1 = 13;
					page2 = 23;
				}
				if (itemnum == 4)
				{
					page = 4;
					page1 = 14;
					page2 = 24;
				}
				if (itemnum == 5)
				{
					page = 5;
					page1 = 15;
					page2 = 25;
				}
				if (itemnum == 6)
				{
					page = 6;
					page1 = 16;
					page2 = 26;
				}
				if (itemnum == 7)
				{
					page = 7;
					page1 = 17;
					page2 = 27;
				}
				if (itemnum == 8)
				{
					page = 8;
					page1 = 18;
					page2 = 28;
				}
				if (itemnum == 9)
				{
					page = 9;
					page1 = 19;
					page2 = 29;
				}

				if (itemnum2 == 0)
				{
					TextmainUImini();
					itemnum = 0;
					if (inventoryindex[page] >= 1 && inventoryindex[page] <= 20)
					{
						gotoxy(61, 8); setColor(WHITE); printf("장비");
					}
					if (inventoryindex[page] >= 21 && inventoryindex[page] <= 40)
					{
						gotoxy(61, 10); setColor(WHITE); printf("사용");
					}
					if (inventoryindex[page] >= 1 && inventoryindex[page] <= 60)
					{
						gotoxy(61, 12); setColor(WHITE); printf("상세");
					}
					while (true)
					{
						if (itemnum == 0)
						{
							gotoxy(60, 8); setColor(WHITE); printf("→");
						}
						else
						{
							gotoxy(60, 8); setColor(WHITE); printf(" ");
						}

						if (itemnum == 1)
						{
							gotoxy(60, 10); setColor(WHITE); printf("→");
						}
						else
						{
							gotoxy(60, 10); setColor(WHITE); printf(" ");
						}

						if (itemnum == 2)
						{
							gotoxy(60, 12); setColor(WHITE); printf("→");
						}
						else
						{
							gotoxy(60, 12); setColor(WHITE); printf(" ");
						}

						if (itemnum >= 3)
						{
							itemnum = 0;
						}
						if (itemnum < 0)
						{
							itemnum = 1;
						}

						if (key == 13)
						{
							key = 0;
							if (itemnum == 0)//장비
							{
								if (inventoryindex[page] == 1)
								{
									weapon = 1;
									playerweaponRerode();
								}
								if (inventoryindex[page] == 2)
								{
									weapon = 2;
									playerweaponRerode();
								}
								goto inventorystart;
							}
							if (itemnum == 1)//사용
							{
								if (inventoryindex[page] == 21)
								{
									PlayerHP += 3;
									if (PlayerHP > PlayerHPmax)
									{
										PlayerHP = PlayerHPmax;
									}
									inventoryindex[page] = 0;
								}
								if (inventoryindex[page] == 22)
								{
									PlayerHP += 5;
									if (PlayerHP > PlayerHPmax)
									{
										PlayerHP = PlayerHPmax;
									}
									inventoryindex[page] = 0;
								}
								goto inventorystart;
							}
							if (itemnum == 2)//상세
							{
								if (inventoryindex[page] == 1)
								{
									TextmainUI();
									gotoxy(55, 7); printf("나무로 만든 큰 대검이다.");
									gotoxy(55, 8); printf("초보자가 연습하기 좋은 검이다.");
									_getch();
								}
								if (inventoryindex[page] == 2)
								{
									TextmainUI();
									gotoxy(55, 7); printf("나무로 만든 큰 대검이다.");
									gotoxy(55, 8); printf("초보자가 연습하기 좋은 검이다.");
									_getch();
								}
								if (inventoryindex[page] == 21)
								{
									TextmainUI();
									gotoxy(55, 7); printf("미미한 체력회복 물약이다.");
									gotoxy(55, 8); printf("약간의(+3)HP를 회복시켜준다.");
									_getch();
								}
								if (inventoryindex[page] == 22)
								{
									TextmainUI();
									gotoxy(55, 7); printf("조금은 효과적인 체력회복 물약");
									gotoxy(55, 8); printf("어느정도의(+5)HP 를 회복시켜 준다.");
									_getch();
								}
								if (inventoryindex[page] == 41)
								{
									TextmainUI();
									gotoxy(55, 7); printf("허름한 가죽이다.");
									gotoxy(55, 8); printf("이걸로 무언가를 만들수도 있을것같다.");
									_getch();
								}
								if (inventoryindex[page] == 42)
								{
									TextmainUI();
									gotoxy(55, 7); printf("작은 고블린의 이빨");
									gotoxy(55, 8); printf("사용할곳을 찾아봐야겠다..");
									_getch();
								}
								if (inventoryindex[page] == 43)
								{
									TextmainUI();
									gotoxy(72, 7); printf("◎˙▼˙◎");
									gotoxy(65, 9); printf("맛있는지는 모르겠다");
									_getch();
								}
								goto inventorystart;
							}

						}

						if (_kbhit())
						{
							key = _getch();
							if (key == 224)
							{
								key = _getch();
								switch (key)
								{
								case 80:
									itemnum++;//위
									break;
								case 72:
									itemnum--;//아래
									break;
								}
							}
						}
					}
				}
				if (itemnum2 == 1)
				{
					TextmainUImini();
					itemnum = 0;
					if (inventoryindex[page1] >= 1 && inventoryindex[page1] <= 20)
					{
						gotoxy(61, 8); setColor(WHITE); printf("장비");
					}
					if (inventoryindex[page1] >= 21 && inventoryindex[page1] <= 40)
					{
						gotoxy(61, 10); setColor(WHITE); printf("사용");
					}
					if (inventoryindex[page1] >= 1 && inventoryindex[page1] <= 60)
					{
						gotoxy(61, 12); setColor(WHITE); printf("상세");
					}
					while (true)
					{
						if (itemnum == 0)
						{
							gotoxy(60, 8); setColor(WHITE); printf("→");
						}
						else
						{
							gotoxy(60, 8); setColor(WHITE); printf(" ");
						}

						if (itemnum == 1)
						{
							gotoxy(60, 10); setColor(WHITE); printf("→");
						}
						else
						{
							gotoxy(60, 10); setColor(WHITE); printf(" ");
						}

						if (itemnum == 2)
						{
							gotoxy(60, 12); setColor(WHITE); printf("→");
						}
						else
						{
							gotoxy(60, 12); setColor(WHITE); printf(" ");
						}

						if (itemnum >= 3)
						{
							itemnum = 0;
						}
						if (itemnum < 0)
						{
							itemnum = 1;
						}

						if (key == 13)
						{
							key = 0;
							if (itemnum == 0)//장비
							{
								if (inventoryindex[page1] == 1)
								{
									weapon = 1;
									playerweaponRerode();
								}
								if (inventoryindex[page1] == 2)
								{
									weapon = 2;
									playerweaponRerode();
								}
								goto inventorystart;
							}
							if (itemnum == 1)//사용
							{
								if (inventoryindex[page1] == 21)
								{
									PlayerHP += 3;
									if (PlayerHP > PlayerHPmax)
									{
										PlayerHP = PlayerHPmax;
									}
									inventoryindex[page1] = 0;
								}
								if (inventoryindex[page1] == 22)
								{
									PlayerHP += 5;
									if (PlayerHP > PlayerHPmax)
									{
										PlayerHP = PlayerHPmax;
									}
									inventoryindex[page1] = 0;
								}
								goto inventorystart;
							}
							if (itemnum == 2)//상세
							{
								if (inventoryindex[page1] == 1)
								{
									TextmainUI();
									gotoxy(55, 7); printf("나무로 만든 큰 대검이다.");
									gotoxy(55, 8); printf("초보자가 연습하기 좋은 검이다.");
									_getch();
								}
								if (inventoryindex[page1] == 2)
								{
									TextmainUI();
									gotoxy(55, 7); printf("나무로 만든 큰 대검이다.");
									gotoxy(55, 8); printf("초보자가 연습하기 좋은 검이다.");
									_getch();
								}
								if (inventoryindex[page1] == 21)
								{
									TextmainUI();
									gotoxy(55, 7); printf("미미한 체력회복 물약이다.");
									gotoxy(55, 8); printf("약간의(+3)HP를 회복시켜준다.");
									_getch();
								}
								if (inventoryindex[page1] == 22)
								{
									TextmainUI();
									gotoxy(55, 7); printf("조금은 효과적인 체력회복 물약");
									gotoxy(55, 8); printf("어느정도의(+5)HP 를 회복시켜 준다.");
									_getch();
								}
								if (inventoryindex[page1] == 41)
								{
									TextmainUI();
									gotoxy(55, 7); printf("허름한 가죽이다.");
									gotoxy(55, 8); printf("이걸로 무언가를 만들수도 있을것같다.");
									_getch();
								}
								if (inventoryindex[page1] == 42)
								{
									TextmainUI();
									gotoxy(55, 7); printf("작은 고블린의 이빨");
									gotoxy(55, 8); printf("사용할곳을 찾아봐야겠다..");
									_getch();
								}
								if (inventoryindex[page1] == 43)
								{
									TextmainUI();
									gotoxy(72, 7); printf("◎˙▼˙◎");
									gotoxy(65, 9); printf("맛있는지는 모르겠다");
									_getch();
								}
								goto inventorystart;
							}

						}

						if (_kbhit())
						{
							key = _getch();
							if (key == 224)
							{
								key = _getch();
								switch (key)
								{
								case 80:
									itemnum++;//위
									break;
								case 72:
									itemnum--;//아래
									break;
								}
							}
						}
					}
				}
				if (itemnum2 == 2)
				{
					TextmainUImini();
					itemnum = 0;
					if (inventoryindex[page2] >= 1 && inventoryindex[page2] <= 20)
					{
						gotoxy(61, 8); setColor(WHITE); printf("장비");
					}
					if (inventoryindex[page2] >= 21 && inventoryindex[page2] <= 40)
					{
						gotoxy(61, 10); setColor(WHITE); printf("사용");
					}
					if (inventoryindex[page2] >= 1 && inventoryindex[page2] <= 60)
					{
						gotoxy(61, 12); setColor(WHITE); printf("상세");
					}
					while (true)
					{
						if (itemnum == 0)
						{
							gotoxy(60, 8); setColor(WHITE); printf("→");
						}
						else
						{
							gotoxy(60, 8); setColor(WHITE); printf(" ");
						}

						if (itemnum == 1)
						{
							gotoxy(60, 10); setColor(WHITE); printf("→");
						}
						else
						{
							gotoxy(60, 10); setColor(WHITE); printf(" ");
						}

						if (itemnum == 2)
						{
							gotoxy(60, 12); setColor(WHITE); printf("→");
						}
						else
						{
							gotoxy(60, 12); setColor(WHITE); printf(" ");
						}

						if (itemnum >= 3)
						{
							itemnum = 0;
						}
						if (itemnum < 0)
						{
							itemnum = 1;
						}

						if (key == 13)
						{
							key = 0;
							if (itemnum == 0)//장비
							{
								if (inventoryindex[page2] == 1)
								{
									weapon = 1;
									playerweaponRerode();
								}
								if (inventoryindex[page2] == 2)
								{
									weapon = 2;
									playerweaponRerode();
								}
								goto inventorystart;
							}
							if (itemnum == 1)//사용
							{
								if (inventoryindex[page2] == 21)
								{
									PlayerHP += 3;
									if (PlayerHP > PlayerHPmax)
									{
										PlayerHP = PlayerHPmax;
									}
									inventoryindex[page2] = 0;
								}
								if (inventoryindex[page2] == 22)
								{
									PlayerHP += 5;
									if (PlayerHP > PlayerHPmax)
									{
										PlayerHP = PlayerHPmax;
									}
									inventoryindex[page2] = 0;
								}
								goto inventorystart;
							}
							if (itemnum == 2)//상세
							{
								if (inventoryindex[page2] == 1)
								{
									TextmainUI();
									gotoxy(55, 7); printf("나무로 만든 큰 대검이다.");
									gotoxy(55, 8); printf("초보자가 연습하기 좋은 검이다.");
									_getch();
								}
								if (inventoryindex[page2] == 2)
								{
									TextmainUI();
									gotoxy(55, 7); printf("나무로 만든 큰 대검이다.");
									gotoxy(55, 8); printf("초보자가 연습하기 좋은 검이다.");
									_getch();
								}
								if (inventoryindex[page2] == 21)
								{
									TextmainUI();
									gotoxy(55, 7); printf("미미한 체력회복 물약이다.");
									gotoxy(55, 8); printf("약간의(+3)HP를 회복시켜준다.");
									_getch();
								}
								if (inventoryindex[page2] == 22)
								{
									TextmainUI();
									gotoxy(55, 7); printf("조금은 효과적인 체력회복 물약");
									gotoxy(55, 8); printf("어느정도의(+5)HP 를 회복시켜 준다.");
									_getch();
								}
								if (inventoryindex[page2] == 41)
								{
									TextmainUI();
									gotoxy(55, 7); printf("허름한 가죽이다.");
									gotoxy(55, 8); printf("이걸로 무언가를 만들수도 있을것같다.");
									_getch();
								}
								if (inventoryindex[page2] == 42)
								{
									TextmainUI();
									gotoxy(55, 7); printf("작은 고블린의 이빨");
									gotoxy(55, 8); printf("사용할곳을 찾아봐야겠다..");
									_getch();
								}
								if (inventoryindex[page2] == 43)
								{
									TextmainUI();
									gotoxy(72, 7); printf("◎˙▼˙◎");
									gotoxy(65, 9); printf("맛있는지는 모르겠다");
									_getch();
								}
								goto inventorystart;
							}

						}

						if (_kbhit())
						{
							key = _getch();
							if (key == 224)
							{
								key = _getch();
								switch (key)
								{
								case 80:
									itemnum++;//위
									break;
								case 72:
									itemnum--;//아래
									break;
								}
							}
						}
					}
				}
			}
			if (itemnum == 10)
			{
				break;
			}

		}

		if (_kbhit())
		{
			key = _getch();
			if (key == 224)
			{
				key = _getch();
				switch (key)
				{
				case 77:
					itemnum2++;//오른쪽
					break;
				case 75:
					itemnum2--;//왼쪽
					break;
				case 80:
					itemnum++;//위
					break;
				case 72:
					itemnum--;//아래
					break;
				}
			}
		}
		if (itemnum2 >= 3)
		{
			itemnum2 = 2;
		}
		if (itemnum2 < 0)
		{
			itemnum2 = 0;
		}
	}
}

void playerweaponRerode() {
	if (weapon == 2)
	{
		weapolpower = 2;
		skillpower = 0;
	}
	if (weapon == 3)
	{
		weapolpower = 4;
		skillpower = 0;
	}
}

//UI

void userUImain1() {
	setColor(WHITE); gotoxy(1, 1);  printf("");
	setColor(WHITE); gotoxy(1, 2);  printf("  _______________________________________________________________________________________________________________________________________________");
	setColor(WHITE); gotoxy(1, 3);  printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 4);  printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 5);  printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 6);  printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 7);  printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 8);  printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 9);  printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 10); printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 11); printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 12); printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 13); printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 14); printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 15); printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 16); printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 17); printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 18); printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 19); printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 20); printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 21); printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 22); printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 23); printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 24); printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 25); printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 26); printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 27); printf(" ㅣ");
	setColor(WHITE); gotoxy(1, 28); printf(" ㅣ=============================================================================================================================================ㅣ");
	setColor(WHITE); gotoxy(1, 29); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 30); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 31); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 32); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 33); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 34); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 35); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 36); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 37); printf("  _______________________________________________________________________________________________________________________________________________ ");
	setColor(WHITE); gotoxy(1, 38); printf("");
	setColor(WHITE); gotoxy(145, 3); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 4); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 5); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 6); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 7); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 8); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 9); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 10); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 11); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 12); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 13); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 14); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 15); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 16); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 17); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 18); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 19); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 20); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 21); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 22); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 23); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 24); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 25); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 26); printf("ㅣ");
	setColor(WHITE); gotoxy(145, 27); printf("ㅣ\n\n\n\n\n\n\n\n\n\n\n\n");

}

void userUImain2() {
	setColor(WHITE); gotoxy(1, 1);  printf("");
	setColor(WHITE); gotoxy(1, 2);  printf("  _______________________________________________________________________________________________________________________________________________");
	setColor(WHITE); gotoxy(1, 3);  printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 4);  printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 5);  printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 6);  printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 7);  printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 8);  printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 9);  printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 10); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 11); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 12); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 13); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 14); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 15); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 16); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 17); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 18); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 19); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 20); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 21); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 22); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 23); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 24); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 25); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 26); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 27); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 28); printf(" ㅣ=============================================================================================================================================ㅣ");
	setColor(WHITE); gotoxy(1, 29); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 30); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 31); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 32); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 33); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 34); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 35); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 36); printf(" ㅣ                                                                                                                                             ㅣ");
	setColor(WHITE); gotoxy(1, 37); printf("  _______________________________________________________________________________________________________________________________________________ ");
	setColor(WHITE); gotoxy(1, 38); printf("");

}


void title() {
	int delay = 50;
	setColor(DAKR_YELLOW); gotoxy(20, 1);  printf("");
	setColor(DAKR_YELLOW); gotoxy(20, 2);  printf("  __       __                                               __");
	Sleep(delay);
	setColor(DAKR_YELLOW); gotoxy(20, 3);  printf(" /\\ \\__   /\\ \\                                             /\\ \\__    __ ");
	Sleep(delay);
	setColor(DAKR_YELLOW); gotoxy(20, 4);  printf(" \\ \\ ,_\\  \\ \\ \\___       __              _____      __     \\ \\ ,_\\  /\\_\\      __     ___      ___      __ ");
	Sleep(delay);
	setColor(DAKR_YELLOW); gotoxy(20, 5);  printf("  \\ \\ \\/   \\ \\  _ `\\   /'__`\\           /\\ '__`\\  /'__`\\    \\ \\ \\/  \\/\\ \\   /'__`\\ /' _ `\\   /'___\\  /'__`\\ ");
	Sleep(delay);
	setColor(DAKR_YELLOW); gotoxy(20, 6);  printf("   \\ \\ \\_   \\ \\ \\ \\ \\ /\\  __/           \\ \\ \\L\\ \\/\\ \\L\\.\\_   \\ \\ \\_  \\ \\ \\ /\\  __/ /\\ \\/\\ \\ /\\ \\__/ /\\  __/ ");
	Sleep(delay);
	setColor(DAKR_YELLOW); gotoxy(20, 7);  printf("    \\ \\__\\   \\ \\_\\ \\_\\\\ \\____\\           \\ \\ ,__/\\ \\__/.\\_\\   \\ \\__\\  \\ \\_\\\\ \\____\\\\ \\_\\ \\_\\\\ \\____\\\\ \\____\\ ");
	Sleep(delay);
	setColor(DAKR_YELLOW); gotoxy(20, 8);  printf("     \\/__/    \\/_/\\/_/ \\/____/  _______   \\ \\ \\/  \\/__/\\/_/    \\/__/   \\/_/ \\/____/ \\/_/\\/_/ \\/____/ \\/____/ ");
	Sleep(delay);
	setColor(DAKR_YELLOW); gotoxy(20, 9); printf("                               /\\______\\   \\ \\_\\ ");
	Sleep(delay);
	setColor(DAKR_YELLOW); gotoxy(20, 10); printf("                               \\/______/    \\/_/");
	Sleep(delay);
	setColor(DAKR_YELLOW); gotoxy(20, 12); printf("");
	Sleep(delay);
	setColor(DAKR_YELLOW); gotoxy(20, 13); printf("             ___                                ___                  __  ");
	Sleep(delay);
	setColor(DAKR_YELLOW); gotoxy(20, 14); printf("           /'___\\                              /\\_ \\                /\\ \\     __ ");
	Sleep(delay);
	setColor(DAKR_YELLOW); gotoxy(20, 15); printf("    ___   /\\ \\__/            _____      __     \\//\\ \\       __      \\_\\ \\   /\\_\\     ___  ");
	Sleep(delay);
	setColor(DAKR_YELLOW); gotoxy(20, 16); printf("   / __`\\ \\ \\ ,__\\          /\\ '__`\\  /'__`\\     \\ \\ \\    /'__`\\    /'_` \\  \\/\\ \\  /' _ `\\ ");
	Sleep(delay);
	setColor(DAKR_YELLOW); gotoxy(20, 17); printf("  /\\ \\L\\ \\ \\ \\ \\_/          \\ \\ \\L\\ \\/\\ \\L\\.\\_    \\_\\ \\_ /\\ \\L\\.\\_ /\\ \\L\\ \\  \\ \\ \\ /\\ \\/\\ \\ ");
	Sleep(delay);
	setColor(DAKR_YELLOW); gotoxy(20, 18); printf("  \\ \\____/  \\ \\_\\            \\ \\ ,__/\\ \\__/.\\_\\   /\\____\\\\ \\__/.\\_\\\\ \\___,_\\  \\ \\_\\\\ \\_\\ \\_\\ ");
	Sleep(delay);
	setColor(DAKR_YELLOW); gotoxy(20, 19); printf("   \\/___/    \\/_/   _______   \\ \\ \\/  \\/__/\\/_/   \\/____/ \\/__/\\/_/ \\/__,_ /   \\/_/ \\/_/\\/_/");
	Sleep(delay);
	setColor(DAKR_YELLOW); gotoxy(20, 20); printf("                   /\\______\\   \\ \\_\\ ");
	Sleep(delay);
	setColor(DAKR_YELLOW); gotoxy(20, 21); printf("                   \\/______/    \\/_/");
	Sleep(delay);
	setColor(DAKR_YELLOW); gotoxy(10, 30); printf("                                               아무키나 눌러 시작하시오");
	_getch();
	system("cls");
}

void map() {

	setColor(DAKR_YELLOW); gotoxy(1, 1);   printf("");
	setColor(DAKR_YELLOW); gotoxy(1, 2);   printf(" ┌──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐");
	setColor(DAKR_YELLOW); gotoxy(1, 3);   printf(" │                  │_                                                             │               ＼                                           │");
	setColor(DAKR_YELLOW); gotoxy(1, 4);   printf(" │                    ＼_____                                                    __/                │      __      ___________________          │");
	setColor(DAKR_YELLOW); gotoxy(1, 5);   printf(" │                           ＼______                                         __/                   ＼      ______/                   \\_____    │");
	setColor(DAKR_YELLOW); gotoxy(1, 6);   printf(" │                                   ￣￣￣＼_                            ___/                        │_    \\    |    플로리아 대륙    |    /   │");
	setColor(DAKR_YELLOW); gotoxy(1, 7);   printf(" │                                           │                        _/￣                             ＼    |----\\___________________/----|    │");
	setColor(DAKR_YELLOW); gotoxy(1, 8);   printf(" │                                           ＼_                    _/                                  │_  /_______\\'-------------'/_______\\   │");
	setColor(DAKR_YELLOW); gotoxy(1, 9);   printf(" │                                              ＼__               /                                     ＼__                 __                │");
	setColor(DAKR_YELLOW); gotoxy(1, 10);  printf(" │                                                │￣￣──── ___─ ￣                                          ＼                                 │");
	setColor(DAKR_YELLOW); gotoxy(1, 11);  printf(" │                                                /        │__                                                │_                                │");
	setColor(DAKR_YELLOW); gotoxy(1, 12);  printf(" │                                               │            ＼____                                            │      __                       │");
	setColor(DAKR_YELLOW); gotoxy(1, 13);  printf(" │                                               /                  ＼                                     ____ ＼                              │");
	setColor(DAKR_YELLOW); gotoxy(1, 14);  printf(" │                                             _/                    │                               _── ￣    ￣￣─ __                 __      │");
	setColor(DAKR_YELLOW); gotoxy(1, 15);  printf(" │                                            │                       ＼                          __/                 │                         │");
	setColor(DAKR_YELLOW); gotoxy(1, 16);  printf(" │__                                           ＼                      └ _                    ___/                    │_                        │");
	setColor(DAKR_YELLOW); gotoxy(1, 17);  printf(" │  ＼_                                         │                        │                  _/                         │            __          │");
	setColor(DAKR_YELLOW); gotoxy(1, 18);  printf(" │     ＼___  ____                             _/                         ＼_            __/                           │                        │");
	setColor(DAKR_YELLOW); gotoxy(1, 19);  printf(" │    __    ￣    ＼_                       __/                             │_          /                              │_     __                │");
	setColor(DAKR_YELLOW); gotoxy(1, 20);  printf(" │                   ＼_               ____/                                  ＼       /                                 ＼                     │");
	setColor(DAKR_YELLOW); gotoxy(1, 21);  printf(" │                      ＼_           │                                         ＼    /                                   │              __     │");
	setColor(DAKR_YELLOW); gotoxy(1, 22);  printf(" │ __          __          ＼      ___│                                           ＼ │                                    │    __               │");
	setColor(DAKR_YELLOW); gotoxy(1, 23);  printf(" │                           ￣￣￣    ＼                                           ─┤                                    /                     │");
	setColor(DAKR_YELLOW); gotoxy(1, 24);  printf(" │                            __        /                                            │                                 __＼          __         │");
	setColor(DAKR_YELLOW); gotoxy(1, 25);  printf(" │      __                            _/                                             │                              __/  ￣                     │");
	setColor(DAKR_YELLOW); gotoxy(1, 26);  printf(" │                    __           __/                                                ＼__                       __/         __                 │");
	setColor(DAKR_YELLOW); gotoxy(1, 27);  printf(" │            __                   ＼                ______  /￣＼_                   _/  ＼_                 __/                         __    │");
	setColor(DAKR_YELLOW); gotoxy(1, 28);  printf(" │    __                  __        / ____  ____/￣￣      ￣＼_   ＼__--____     ___/       ＼_      __    _/           __                     │");
	setColor(DAKR_YELLOW); gotoxy(1, 29);  printf(" │                                _/ /    ￣                    ＼_          ＼__/__            ￣￣￣  ＼_/        __                          │");
	setColor(DAKR_YELLOW); gotoxy(1, 30);  printf(" │       __                     _/ ￣                             │                 ￣￣＼____  ___       ＼                       __           │");
	setColor(DAKR_YELLOW); gotoxy(1, 31);  printf(" │                   __       _/                                  │_                          ￣   ￣＼   _/                 __                 │");
	setColor(DAKR_YELLOW); gotoxy(1, 32);  printf(" │               __         _/                                     ＼                                  ￣/     __                            __ │");
	setColor(DAKR_YELLOW); gotoxy(1, 33);  printf(" │                         │_                                       │                                   /                                       │");
	setColor(DAKR_YELLOW); gotoxy(1, 34);  printf(" │                    __    ＼_                                     │                                   ＼                     __               │");
	setColor(DAKR_YELLOW); gotoxy(1, 35);  printf(" │          __                ＼                                    /                                 ___/               __                     │");
	setColor(DAKR_YELLOW); gotoxy(1, 36);  printf(" │                             │                                   /                                  ＼       __                      __       │");
	setColor(DAKR_YELLOW); gotoxy(1, 37);  printf(" └──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘");
	setColor(DAKR_YELLOW); gotoxy(1, 38);  printf("");
	if (cangopetia == true)
	{
		setColor(DAKR_YELLOW); gotoxy(44, 33); printf("페티아");
	}
	else
	{
		setColor(DAKR_YELLOW); gotoxy(44, 33); printf("      ");
		setColor(DAKR_YELLOW); gotoxy(44, 33); printf("???");
	}

	if (cangohmilla == true)
	{
		setColor(DAKR_YELLOW); gotoxy(85, 33); printf("흐밀라");
	}
	else
	{
		setColor(DAKR_YELLOW); gotoxy(85, 33); printf("      ");
		setColor(DAKR_YELLOW); gotoxy(85, 33); printf("???");
	}

	if (can3 == true)
	{
		setColor(DAKR_YELLOW); gotoxy(105, 22); printf("인두스");
	}
	else
	{
		setColor(DAKR_YELLOW); gotoxy(105, 22); printf("      ");
		setColor(DAKR_YELLOW); gotoxy(105, 22); printf("???");
	}

	if (can4 == true)
	{
		setColor(DAKR_YELLOW); gotoxy(87, 12); printf("흐밀라");
	}
	else
	{
		setColor(DAKR_YELLOW); gotoxy(87, 12); printf("      ");
		setColor(DAKR_YELLOW); gotoxy(87, 12); printf("???");
	}

	if (can5 == true)
	{
		setColor(DAKR_YELLOW); gotoxy(44, 33); printf("페티아");
	}
}

void petiamap() {
	int petianum = 0;



	setColor(SKYBLUE); gotoxy(1, 2);  printf("  _______________________________________________________________________________________________________________________________________________");
	setColor(SKYBLUE); gotoxy(1, 3);  printf(" ㅣ         _   \\                                                                     __                        \\                \\____/\\____/   ㅣ");
	setColor(SKYBLUE); gotoxy(1, 4);  printf(" ㅣ   _          \\                                                                ___|__|                /\\      \\___            /          \\   ㅣ");
	setColor(SKYBLUE); gotoxy(1, 5);  printf(" ㅣ        _     /                                                             _ /   | \\_               /  \\         \\__         페티아  마을   ㅣ");
	setColor(SKYBLUE); gotoxy(1, 6);  printf(" ㅣ _   |>      /                             ╋                               |_|___●__|_|             /_||_\\       /\\  \\____    \\____  ____/   ㅣ");
	setColor(SKYBLUE); gotoxy(1, 7);  printf(" ㅣ     |    _ |                            _/^\\_                              /  __|    \\               ||        /  \\      \\__ /    \\/    \\   ㅣ");
	setColor(SKYBLUE); gotoxy(1, 8);  printf(" ㅣ_ \\=====/   |                           /^^^^^\\                             | |__|    |                        /_||_\\        \\               ㅣ");
	setColor(SKYBLUE); gotoxy(1, 9);  printf(" ㅣ      _    /                     ______|^^^^^^^|______                      |_________|                 /\\       ||           )         /    ㅣ");
	setColor(SKYBLUE); gotoxy(1, 10); printf(" ㅣ  _   ┲┲┲┲┲┲                    /^_    _      _    _ ^\\                                                /  \\                 _/     /         ㅣ");
	setColor(SKYBLUE); gotoxy(1, 11); printf(" ㅣ _    ┸┸┸┸┸┸                   /^/ \\  / \\    / \\  / \\ ^\\                      6.풍차                  /_||_\\          /\\   (                 ㅣ");
	setColor(SKYBLUE); gotoxy(1, 12); printf(" ㅣ     _    /                   |__|_|__|_|    |_|__|_|___|                                               ||           /  \\   \\_      /        ㅣ");
	setColor(SKYBLUE); gotoxy(1, 13); printf(" ㅣ   _     /     3.부두         |_________________________|                                                           /_||_\\    \\        /     ㅣ");
	setColor(SKYBLUE); gotoxy(1, 14); printf(" ㅣ_   ┲┲┲┲┲┲                                                                                                   /\\       ||       )             ㅣ");
	setColor(SKYBLUE); gotoxy(1, 15); printf(" ㅣ    ┸┸┸┸┸┸                           1.인내의 교회                                                          /  \\              /    /         ㅣ");
	setColor(SKYBLUE); gotoxy(1, 16); printf(" ㅣ _     /                                                                                             /\\    /_||_\\            |       /       ㅣ");
	setColor(SKYBLUE); gotoxy(1, 17); printf(" ㅣ   _  |                                                                                             /  \\     ||           __/                ㅣ");
	setColor(SKYBLUE); gotoxy(1, 18); printf(" ㅣ  _  /                                                                  ______                     /_||_\\               _/           /       ㅣ");
	setColor(SKYBLUE); gotoxy(1, 19); printf(" ㅣ _  |                                                                  /^^^^^^\\                      ||        /\\    __/       /             ㅣ");
	setColor(SKYBLUE); gotoxy(1, 20); printf(" ㅣ   /                                                                  /________\\                              /  \\  /                        ㅣ");
	setColor(SKYBLUE); gotoxy(1, 21); printf(" ㅣ   \\___        .                                                       |()|_|_|                 5.숲 외각길  /_||_\\(                    /    ㅣ");
	setColor(SKYBLUE); gotoxy(1, 22); printf(" ㅣ   _   \\    .                                                          |()|_|_|                        /\\      ||   |        /               ㅣ");
	setColor(SKYBLUE); gotoxy(1, 23); printf(" ㅣ _      |       .                                                      |______|                       /  \\      /\\   \\_                /     ㅣ");
	setColor(SKYBLUE); gotoxy(1, 24); printf(" ㅣ        |   .     .                                                           ______                 /_||_\\    /  \\    \\             /       ㅣ");
	setColor(SKYBLUE); gotoxy(1, 25); printf(" ㅣ     _  |  .   . .   .                                                       /^^^^^^\\                  ||     /_||_\\    |         /          ㅣ");
	setColor(SKYBLUE); gotoxy(1, 26); printf(" ㅣ  _     |  . .     .                                          2.인근 마을   /________\\                          ||      |                    ㅣ");
	setColor(SKYBLUE); gotoxy(1, 27); printf(" ㅣ         \\  . .  .   .  .                                                    |()|_|_|                    /\\           _/          /          ㅣ");
	setColor(SKYBLUE); gotoxy(1, 28); printf(" ㅣ     _    |  .   . .      4. 해변가                             ______       |()|_|_|                   /  \\         /                       ㅣ");
	setColor(SKYBLUE); gotoxy(1, 29); printf(" ㅣ        _  \\. .    .    .                                      /^^^^^^\\      |______|                  /_||_\\       |      /          /      ㅣ");
	setColor(SKYBLUE); gotoxy(1, 30); printf(" ㅣ            \\ . . .  .                                        /________\\                                 ||       _/                         ㅣ");
	setColor(SKYBLUE); gotoxy(1, 31); printf(" ㅣ  _   _      \\ . . .      .                                    |()|_|_|                                         _/                /          ㅣ");
	setColor(SKYBLUE); gotoxy(1, 32); printf(" ㅣ         _    \\  . .  .      .                                 |()|_|_|                               /\\      _/                             ㅣ");
	setColor(SKYBLUE); gotoxy(1, 33); printf(" ㅣ    _          \\ .  . .   .                                    |______|                              /  \\    /                  /            ㅣ");
	setColor(SKYBLUE); gotoxy(1, 34); printf(" ㅣ        _       \\  . .   .   .                                                                      /_||_\\  |         /              /       ㅣ");
	setColor(SKYBLUE); gotoxy(1, 35); printf(" ㅣ    _        _   \\.  . . .  .                                                                         ||   /                  /              ㅣ");
	setColor(SKYBLUE); gotoxy(1, 36); printf(" ㅣ           _      \\. .  .  .                                                                              /          /           /           ㅣ");
	setColor(SKYBLUE); gotoxy(1, 37); printf("  _______________________________________________________________________________________________________________________________________________ ");
	setColor(SKYBLUE); gotoxy(1, 38); printf("");

	int key = _getch();
	while (true)
	{
		key - 0;
		if (petianum == 0)
		{
			gotoxy(39, 15);
			setColor(WHITE); printf("→");
		}
		else {
			gotoxy(39, 15);
			printf("  ");
		}

		if (petianum == 1)
		{
			gotoxy(64, 26);
			setColor(WHITE); printf("→");
		}
		else {
			gotoxy(64, 26);
			printf("  ");
		}

		if (petianum == 2)
		{
			gotoxy(17, 13);
			setColor(WHITE); printf("→");
		}
		else {
			gotoxy(17, 13);
			printf("  ");
		}

		if (petianum == 3)
		{
			gotoxy(28, 28);
			setColor(WHITE); printf("→");
		}
		else {
			gotoxy(28, 28);
			printf("  ");
		}

		if (petianum == 4)
		{
			gotoxy(98, 21);
			setColor(WHITE); printf("→");
		}
		else {
			gotoxy(98, 21);
			printf("  ");
		}

		if (petianum == 5)
		{
			gotoxy(80, 11);
			setColor(WHITE); printf("→");
		}
		else {
			gotoxy(80, 11);
			printf("  ");
		}

		if (petianum >= 6)
		{
			petianum = 0;
		}
		if (petianum < 0)
		{
			petianum = 5;
		}

		if (key == 13)
		{
			gotoxy(5, 1);
			if (petianum == 0)
			{
				petiachurch();
				break;
			}
			else if (petianum == 1) {
				petiavillage();

				break;
			}
			else if (petianum == 2) {
				petiapier();

				break;
			}
			else if (petianum == 3) {
				if (canpetiaBeach == true)
				{
					petiaBeachimage();
					break;
				}
				else
				{
					gotoxy(50, 1); printf("지금은 들어가지 않아도 될것같다.");
					Sleep(1000);
					gotoxy(50, 1); printf("                                 ");
					petiamap();
				}
			}
			else if (petianum == 4) {
				PetiaForestRoad();
				break;
			}
			else if (petianum == 5) {
				if (canPetiaWindmil == true)
				{
					PetiaWindmill();
					break;
				}
				else
				{
					gotoxy(50, 1); printf("지금은 들어가지 않아도 될것같다.");
					Sleep(1000);
					gotoxy(50, 1); printf("                                 ");
					petiamap();
				}
			}
			petianum = 0;
		}

		if (key == 105)
		{
			playerinventoty();
			petiamap();
		}

		if (_kbhit())
		{
			key = _getch();
			if (key == 224)
			{
				key = _getch();
				switch (key)
				{
				case 77:
					petianum++;
					break;
				case 75:
					petianum--;
					break;
				}
			}
		}
	}
}

void petiavillageimage() {

	setColor(WHITE); gotoxy(1, 1);  printf("                                                                                                                             ");
	setColor(DAKR_YELLOW); gotoxy(4, 3);  printf("  ||\\                            \\ |/_________________/|  |     |  /|_/|_/|_/|_/\\//              \\\\|_/|_/|_/\\/    |               |          ");
	setColor(DAKR_YELLOW); gotoxy(4, 4);  printf("  || \\                            \\/_________________/ |  |_____|_/|_/|_/|_/|_/\\//                \\\\________/     |               |          ");
	setColor(DAKR_YELLOW); gotoxy(4, 5);  printf("  ||  \\                           /_________________/  |  |     |/|_/|_/|_/|_/\\//                  \\\\      |      |               |          ");
	setColor(DAKR_YELLOW); gotoxy(4, 6);  printf("  ||   \\                           |   |/\\/\\/|\\/\\/\\|   |  |_____/|_/|_/|_/|_/\\//                    \\\\_____|      |               |          ");
	setColor(DAKR_YELLOW); gotoxy(4, 7);  printf(" /||   /\\                          |   |_____|_____|   |       /|_/|_/|_/|_/\\//______________________\\\\____|______|_______________|          ");
	setColor(DAKR_YELLOW); gotoxy(4, 8);  printf("/ ||  // \\                        _|___________________|______/|_/|_/|_/|_/\\//________________________\\\\           \\____\\__________\\         ");
	setColor(DAKR_YELLOW); gotoxy(4, 9);  printf("__|| //   \\                     _/___________\\_|\\_|\\_|\\_|\\_| /|_/|_/|_/|_/\\//                          \\\\           \\______\\________\\        ");
	setColor(DAKR_YELLOW); gotoxy(4, 10); printf("  ||//_____\\                  _/_______________\\_|\\_|\\_|\\_| /|_/|_/|_/|_/\\//                            \\\\           \\________\\______\\       ");
	setColor(DAKR_YELLOW); gotoxy(4, 11); printf("  |//       \\________________/|________|________|\\_|\\_|\\_| /|_/|_/|_/|_/\\//             ___              \\\\           \__________\\____\\      ");
	setColor(DAKR_YELLOW); gotoxy(4, 12); printf("  ||           \\          _/  |        |        |  \\_|\\_| /_____________//             /_|_\\              \\\\           \\____________\\__\\     ");
	setColor(DAKR_YELLOW); gotoxy(4, 13); printf("  ||            \\       _/    |__ __ __|__ __ __|    \\_|\\_||           ||           __|__ __|__            ||          |                |    ");
	setColor(DAKR_YELLOW); gotoxy(4, 14); printf("  ||             \\     /______|__|__|__|__|__|__|______\\_|||           ||          |  |  |  |  |           ||__________|                |    ");
	setColor(DAKR_YELLOW); gotoxy(4, 15); printf("  ||              \\  /||_______________|_______________|| ||___________||__________|__|__|__|__|___________||          |                |    ");
	setColor(DAKR_YELLOW); gotoxy(4, 16); printf("  ||_______________\\/_|                |                | ||           ||               ____               ||          |                |    ");
	setColor(DAKR_YELLOW); gotoxy(4, 17); printf("  ||                  |                |                | ||           ||             _/ |  \\_             ||          |                |    ");
	setColor(DAKR_YELLOW); gotoxy(4, 18); printf("  ||                  |________________|________________| ||           ||           _/|  |  | \\_           ||          |                |    ");
	setColor(DAKR_YELLOW); gotoxy(4, 19); printf("  ||                  |                |                | ||           ||          /  |__|  |   \\          ||          |                |    ");
	setColor(DAKR_YELLOW); gotoxy(4, 20); printf("  ||                  |    _______     |     _____      | ||           ||          |  |  |  |___|          ||          |                |    ");
	setColor(DAKR_YELLOW); gotoxy(4, 21); printf("  ||                  |   /       \\    |    /     \\     | ||           ||          |  |  |__|   |          ||          |                |    ");
	setColor(DAKR_YELLOW); gotoxy(4, 22); printf("  ||                  |  |         |   |   |       |    | ||           ||          |  |  |  |   |          ||          |                |    ");
	setColor(DAKR_YELLOW); gotoxy(4, 23); printf("  ||                  |  |         |   |   |       |    | ||           ||          |__|  |  | ● |          ||______    |                |    ");
	setColor(DAKR_YELLOW); gotoxy(4, 24); printf("__||_                 |  |         |   |   |       |    | ||           ||          |  |__|  |   |          ||  \\___\\___|        ________|____");
	setColor(DAKR_YELLOW); gotoxy(4, 25); printf("     \\________________|__|_________|___|___|_______|_   | ||           ||          |  |  |__|   |          ||  ____\\____\\______/             ");
	setColor(DAKR_YELLOW); gotoxy(4, 26); printf("                                                     \\__|_||___________||__________|__|__|__|___|__________||_/                             ");
	setColor(DAKR_YELLOW); gotoxy(4, 27); printf("                                                                                                                                             ");

}

void petiavillage() {


	int petianum = 0;
	userUImain2();
	petiavillageimage();
	setColor(WHITE); gotoxy(4, 29); printf("%s는(은) 페티아에 있는 마을로 도착했다.", playername);
	setColor(WHITE); gotoxy(4, 30); printf("무엇을할까?");
	setColor(WHITE); gotoxy(46, 31); printf("상점");
	setColor(WHITE); gotoxy(91, 31); printf("나가기");
	int key = _getch();
	while (true)
	{
		if (petianum == 0)
		{
			gotoxy(43, 31);
			setColor(WHITE); printf("→");
		}
		else {
			gotoxy(43, 31);
			printf("  ");
		}

		if (petianum == 1)
		{
			gotoxy(89, 31);
			setColor(WHITE); printf("→");
		}
		else {
			gotoxy(89, 31);
			printf("  ");
		}

		if (petianum >= 2)
		{
			petianum = 0;
		}
		if (petianum < 0)
		{
			petianum = 1;
		}

		if (key == 13)
		{
			gotoxy(5, 1);
			if (petianum == 0)
			{
				shop();
				break;
			}
			else if (petianum == 1) {

				petiamap();
				break;
			}

			petianum = 0;
		}

		if (key == 105)
		{
			playerinventoty();
			petiavillage();
		}

		if (_kbhit())
		{
			key = _getch();
			if (key == 224)
			{
				key = _getch();
				switch (key)
				{
				case 77:
					petianum++;
					break;
				case 75:
					petianum--;
					break;
				}
			}
		}
	}

}

void petiachurchimage() {

	setColor(DAKR_YELLOW); gotoxy(1, 3);   printf("                                                                        ┏━┓                                                                              ");
	setColor(DAKR_YELLOW); gotoxy(1, 4);   printf("                                                                      ┏━┛ ┗━┓                                                                         ");
	setColor(DAKR_YELLOW); gotoxy(1, 5);   printf("                                                                      ┗━┓ ┏━┛                                                                         ");
	setColor(DAKR_YELLOW); gotoxy(1, 6);   printf("                                                                        ┃ ┃                                                                        ");
	setColor(DAKR_YELLOW); gotoxy(1, 7);   printf("                                                                  ┌─────┗━┛─────┐                                                                   ");
	setColor(DAKR_YELLOW); gotoxy(1, 8);  printf("                                                                  │             │                                                                  ");
	setColor(DAKR_YELLOW); gotoxy(1, 9);  printf("                                                          ===============================                                                                               ");
	setColor(DAKR_YELLOW); gotoxy(1, 11);  printf("                                                         /                               \\                                                                     ");
	setColor(DAKR_YELLOW); gotoxy(1, 10);  printf("                                                        /                                 \\                                                                ");
	setColor(DAKR_YELLOW); gotoxy(1, 11);  printf("                                                    ===========================================                                                           ");
	setColor(DAKR_YELLOW); gotoxy(1, 12);  printf("                                                    |                                         |                                                           ");
	setColor(DAKR_YELLOW); gotoxy(1, 13);  printf("                          __________________________|                                         |_________________________                                   ");
	setColor(DAKR_YELLOW); gotoxy(1, 14);  printf("                        _/u uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu\\_                                  ");
	setColor(DAKR_YELLOW); gotoxy(1, 15);  printf("                     __/u uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu u\\__                                       ");
	setColor(DAKR_YELLOW); gotoxy(1, 16);  printf("                   _/uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu \\_                         ");
	setColor(DAKR_YELLOW); gotoxy(1, 17);  printf("                  /uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu u\\                                ");
	setColor(DAKR_YELLOW); gotoxy(1, 18);  printf("                /uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu uu\\                          ");
	setColor(DAKR_YELLOW); gotoxy(1, 19);  printf("               /===================================================================================================================\\                    ");
	setColor(DAKR_YELLOW); gotoxy(1, 20);  printf("               │                                                     ▩▩▩▩▩                                                   │                            ");
	setColor(DAKR_YELLOW); gotoxy(1, 21);  printf("               │            ▩▩               ▩▩                ▩▩▩▩▩▩▩              ▩▩               ▩▩            │                       ");
	setColor(DAKR_YELLOW); gotoxy(1, 22);  printf("               │          ▩▩▩▩           ▩▩▩▩             ▩▩▩▩▩▩▩▩           ▩▩▩▩           ▩▩▩▩          │                               ");
	setColor(DAKR_YELLOW); gotoxy(1, 23);  printf("               │         ▩▩▩▩▩         ▩▩▩▩▩           ┌───────┬───────┐          ▩▩▩▩▩         ▩▩▩▩▩         │");
	setColor(DAKR_YELLOW); gotoxy(1, 24);  printf("               │         ▩▩▩▩▩         ▩▩▩▩▩           │━━━━━━━│━━━━━━━│          ▩▩▩▩▩         ▩▩▩▩▩         │                  ");
	setColor(DAKR_YELLOW); gotoxy(1, 25);  printf("               │         ▩▩▩▩▩         ▩▩▩▩▩         ♠│ →→→│ ←←←│ ♣       ▩▩▩▩▩         ▩▩▩▩▩         │             │           ");
	setColor(DAKR_YELLOW); gotoxy(1, 26);  printf("               │         ▩▩▩▩▩         ▩▩▩▩▩           │━━━━━━━│━━━━━━━│          ▩▩▩▩▩         ▩▩▩▩▩         │ ");
	setColor(DAKR_YELLOW); gotoxy(1, 27);  printf("               │         ▩▩▩▩▩         ▩▩▩▩▩         ♣│ →→→│ ←←←│ ♠       ▩▩▩▩▩         ▩▩▩▩▩         │             │ ");
	userUImain1();
}
void petiachurch() {
	petiachurchimage();
	userUImain1();
	int petianum = 0;
	setColor(WHITE); gotoxy(41, 31); printf("축복받기(50gold)");
	setColor(WHITE); gotoxy(91, 31); printf("나가기");
	int key = _getch();
	while (true)
	{
		if (petianum == 0)
		{
			gotoxy(39, 31);
			setColor(WHITE); printf("→");
		}
		else {
			gotoxy(39, 31);
			printf("  ");
		}

		if (petianum == 1)
		{
			gotoxy(89, 31);
			setColor(WHITE); printf("→");
		}
		else {
			gotoxy(89, 31);
			printf("  ");
		}

		if (petianum >= 2)
		{
			petianum = 0;
		}
		if (petianum < 0)
		{
			petianum = 1;
		}

		if (key == 13)
		{
			gotoxy(5, 1);
			if (petianum == 0)
			{
				if (gold <= 49)
				{
					TextmainUI();
					Sleep(500);
					setColor(WHITE); gotoxy(63, 15); printf("gold (이)가 부족하다."); Sleep(1500);
					petiamap();
				}
				else
				{
					TextmainUI();
					Sleep(500);
					setColor(WHITE); gotoxy(63, 15); printf("축복받았다 HP가 가득찼다."); Sleep(1500);
					PlayerHP = PlayerHPmax;
					petiamap();
					break;
				}
			}
			else if (petianum == 1) {

				petiamap();
				break;
			}

			petianum = 0;
		}

		if (key == 105)
		{
			playerinventoty();
			petiavillage();
		}

		if (_kbhit())
		{
			key = _getch();
			if (key == 224)
			{
				key = _getch();
				switch (key)
				{
				case 77:
					petianum++;
					break;
				case 75:
					petianum--;
					break;
				}
			}
		}
	}
}


void petiaBeachimage() {

	setColor(DAKR_YELLOW); gotoxy(1, 17);  printf("                                                                                                                                  ________  ___─│ ");
	setColor(DAKR_YELLOW); gotoxy(1, 18);  printf("                                                                                                              _____────── ￣￣￣￣        ￣    │ ");
	setColor(DAKR_YELLOW); gotoxy(1, 19);  printf("                                                                                                 ___───── ￣￣         .                        │ ");
	setColor(DAKR_YELLOW); gotoxy(1, 20);  printf("                                                                                         __─ ￣￣                                .              │ ");
	setColor(DAKR_YELLOW); gotoxy(1, 21);  printf("                                                                             __─── ￣￣￣                                                 .     │ ");
	setColor(DAKR_YELLOW); gotoxy(1, 22);  printf("                                                                ___───── ￣￣                           .                                       │ ");
	setColor(DAKR_YELLOW); gotoxy(1, 23);  printf("                      ___________________──────────── ￣￣￣￣￣                   .                                           .                │ ");
	setColor(DAKR_YELLOW); gotoxy(1, 24);  printf(" │______───── ￣￣￣￣                      .                                                                      .                            │ ");
	setColor(DAKR_YELLOW); gotoxy(1, 25);  printf(" │                                                         .                                 .                                          .       │ ");
	setColor(DAKR_YELLOW); gotoxy(1, 26);  printf(" │       .                  .                                                  .                        .                                       │ ");
	setColor(DAKR_YELLOW); gotoxy(1, 27);  printf(" │                                        .                                               .                                 .                   │ ");
	setColor(DAKR_YELLOW); gotoxy(1, 28);  printf(" │           .                                                      .                              .                              .             │ ");
	setColor(DAKR_YELLOW); gotoxy(1, 29);  printf(" │                .                                                                                                                             │ ");
	setColor(DAKR_YELLOW); gotoxy(1, 30);  printf(" │                                                     .                  .                                   .                                 │ ");
	setColor(DAKR_YELLOW); gotoxy(1, 31);  printf(" │   .                                       .                                           .                              .                       │ ");
	setColor(DAKR_YELLOW); gotoxy(1, 32);  printf(" │                     .           .                                       .                                                             .      │ ");
	setColor(DAKR_YELLOW); gotoxy(1, 33);  printf(" └──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘ ");


	setColor(BLUE); gotoxy(1, 3);       printf(" │                                                         ____________________________                                                         │ ");
	setColor(BLUE); gotoxy(1, 4);       printf(" │                    ___________─────────── ￣￣￣￣￣￣￣                            ￣￣￣￣￣￣￣─────────── ___________                    │ ");
	setColor(BLUE); gotoxy(1, 5);       printf(" │___──────── ￣￣￣￣                                                                                                      ￣￣￣￣─────────__ │");
	setColor(SKYBLUE); gotoxy(1, 6);      printf(" │                                                                                                         -                                    │ ");
	setColor(SKYBLUE); gotoxy(1, 7);      printf(" │       _                                                                                                                _                     │ ");
	setColor(SKYBLUE); gotoxy(1, 8);      printf(" │                                                                                      -                                                       │ ");
	setColor(SKYBLUE); gotoxy(1, 9);      printf(" │                               _                                                                                -               -             │ ");
	setColor(SKYBLUE); gotoxy(1, 10);      printf(" │                                                                _                                                                             │ ");
	setColor(SKYBLUE); gotoxy(1, 11);      printf(" │                                                                            _                                                            -    │ ");
	setColor(SKYBLUE); gotoxy(1, 12);      printf(" │                                                                                                     -              -                         │ ");
	setColor(SKYBLUE); gotoxy(1, 13);      printf(" │                                                _                                            -                                                │ ");
	setColor(SKYBLUE); gotoxy(1, 14);      printf(" │                  _                                                                                                                         - │ ");
	setColor(SKYBLUE); gotoxy(1, 15);      printf(" │                                                                                                  -                             -             │ ");
	setColor(SKYBLUE); gotoxy(1, 16);      printf(" │                                                                                                            _                                 │ ");
	setColor(SKYBLUE); gotoxy(1, 17);  printf(" │                                                                    -");
	setColor(SKYBLUE); gotoxy(1, 18);  printf(" │                             -                              -                           _");
	setColor(SKYBLUE); gotoxy(1, 19);  printf(" │   _");
	setColor(SKYBLUE); gotoxy(1, 20);  printf(" │                                                      _       ");
	setColor(SKYBLUE); gotoxy(1, 21);  printf(" │                                           _                    ");
	setColor(SKYBLUE); gotoxy(1, 22);  printf(" │              _                                  ");
	setColor(SKYBLUE); gotoxy(1, 23);  printf(" │                   ");
	userUImain1();
	_getch();
}

void petiapierimage() {

	setColor(DARK_SKYBLUE); gotoxy(1, 3);  printf(" │                                                                                         ▒ ▥                                *                │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 4);  printf(" │           *                                                 *                         ▒   ▥                                                 │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 5);  printf(" │                                                                            ~        ▒     ▥               *                                 │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 6);  printf(" │                                       *                                           ▒       ▥                                                 │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 7);  printf(" │                                                                                  ▒        ▥                            ~                    │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 8);  printf(" │                       ~                                                         ▒         ▥          ∼                                     │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 9);  printf(" │                                                                                 ▒        ▥                                                 │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 10); printf(" │                                                 ∼            ~                 ▒         ▥                                                 │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 11); printf(" │             *                                                                    ▒        ▥                  ~                              │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 12); printf(" │                                                                                   ▒       ▥                                                 │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 13); printf(" │                                                                                     ▒     ▥             ▤▤▤▤▤▤▤▤▤                  │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 14); printf(" │                                           ~                                     ∼    ▒   ▥            ▤▤▤▤▤▤▤▤▤         ~         │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 15); printf(" │                                                     ▤▤▤▤▤▤▤▤▤▤▤              ▒ ▥           ▤▤▤▤▤▤▤▤▤                    │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 16); printf(" │                                                           ▤▤▤▤▤▤▤▤▤▤▤          ▥          ▤▤▤▤▤▤▤▤▤                     │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 17); printf(" │    ~                                                          ▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤                       │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 18); printf(" │                       ~                 Ｈ____________Ｈ_        ▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤                          │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 19); printf(" │                                   Ｈ__─ ￣      Ｈ__─ Ｈ             ▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤                              │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 20); printf(" │                             Ｈ__─ ￣      Ｈ__─ Ｈ    Ｈ    ~            ▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤                                  │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 21); printf(" │                       Ｈ__─ ￣      Ｈ__─ Ｈ    Ｈ                        ~   ▤▤▤▤▤▤▤▤▤▤▤▤                            ~          │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 22); printf(" │                 Ｈ__─ ￣      Ｈ__─ Ｈ ~  Ｈ                                                             ∼                                  │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 23); printf(" │      ~      __─ ￣        __─ Ｈ    Ｈ                                                                                                       │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 24); printf(" │____        /  ￣￣￣￣￣￣ /  Ｈ                                      ~                          ~                                           │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 25); printf(" │    ￣￣───/               /   ~                                                                                                              │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 26); printf(" │          /               /￣￣￣￣￣── __                                     ~                                         ~                    │ ");
	setColor(DARK_SKYBLUE); gotoxy(1, 27); printf(" │          ￣￣￣￣￣￣￣￣                 ￣─ _                                                                                          ___─│ ");
	userUImain1();
}

void petiapier() {
	petiapierimage();
	userUImain1();

	int piernum = 0;
	setColor(WHITE); gotoxy(41, 31); printf("모험하기");
	setColor(WHITE); gotoxy(91, 31); printf("돌아가기");
	int key = _getch();
	while (true)
	{
		if (piernum == 0)
		{
			gotoxy(39, 31);
			setColor(WHITE); printf("→");
		}
		else {
			gotoxy(39, 31);
			printf("  ");
		}

		if (piernum == 1)
		{
			gotoxy(89, 31);
			setColor(WHITE); printf("→");
		}
		else {
			gotoxy(89, 31);
			printf("  ");
		}

		if (piernum >= 2)
		{
			piernum = 0;
		}
		if (piernum < 0)
		{
			piernum = 1;
		}

		if (key == 13)
		{
			if (piernum == 0)
			{
				TextmainUI();
				for (int i = 0; i < 2; i++)
				{
					setColor(WHITE); gotoxy(71, 15); printf("모험중.   "); Sleep(800);
					setColor(WHITE); gotoxy(71, 15); printf("모험중..  "); Sleep(800);
					setColor(WHITE); gotoxy(71, 15); printf("모험중... "); Sleep(800);
					setColor(WHITE); gotoxy(71, 15); printf("모험중...."); Sleep(800);

				}
				TextmainUI();
				setColor(WHITE); gotoxy(60, 15); printf("디버널스 (이)가 싸움을 걸어왔다!"); Sleep(1000);
				enemyreset(7, 1);
				background = 1;
				battel();
				petiapier();

			}
			if (piernum == 1)
			{
				petiamap();
				break;
			}
		}

		if (key == 105)
		{
			playerinventoty();
			petiapier();
		}

		if (_kbhit())
		{
			key = _getch();
			if (key == 224)
			{
				key = _getch();
				switch (key)
				{
				case 77:
					piernum++;
					break;
				case 75:
					piernum--;
					break;
				}
			}
		}
	}


}

void PetiaWindmillimage() {
	setColor(SKYBLUE); gotoxy(3, 3);   printf("                                                                     ▤   \\_             /▤   ▤                                             ");
	setColor(SKYBLUE); gotoxy(3, 4);   printf("                                                                    ▤    ▤\\_          /   ▤ /                                              ");
	setColor(SKYBLUE); gotoxy(3, 5);   printf("                                                                   ▤__  ▤   \\_       /     ▤                                               ");
	setColor(SKYBLUE); gotoxy(3, 6);   printf("                                                                       \\▤_  ▤ \\  ___/▤▤  /_                                               ");
	setColor(SKYBLUE); gotoxy(3, 7);   printf("                                                                           \\▤_/ \\/\\_/____▤/--\\_                     __¶__¶                  ");
	setColor(SKYBLUE); gotoxy(3, 8);   printf("                                                                               \\_/  \//_∪∪∪∪∪\\_                  /     ￣\\                ");
	setColor(SKYBLUE); gotoxy(3, 9);   printf("                                                                             _/_/\\\\//\\_\\_∪∪∪∪∪\\_               ┏━━━━━┳━━┓                ");
	setColor(SKYBLUE); gotoxy(3, 10);  printf("                                                                           ______/◎\\__\\_\\_∪∪∪∪∪\\_             ┗┯━━━━╀━┯┛                ");
	setColor(SKYBLUE); gotoxy(3, 11);  printf("                                                                      ____▤    _/─ \\ ▤___\\_∪∪∪∪∪\\_            │    │ │                 ");
	setColor(SKYBLUE); gotoxy(3, 12);  printf("                                                                  ___/▤    ▤_/━━━━ ▤    ▤_━━━━┯┯━┛ \\_\\_          │    / /                 ");
	setColor(SKYBLUE); gotoxy(3, 13);  printf("                                                                  \\▤   ▤  _▤─────── \\ ▤   ▤__││     \\_\\         │   │ │                  ");
	setColor(SKYBLUE); gotoxy(3, 14);  printf("                                                                   \\▤   ▤/ │         │▤    ▤ /││                 │   │ │                  ");
	setColor(SKYBLUE); gotoxy(3, 15);  printf("                                                                    \\▤ _/ │ └─────────┘ │\\ ▤  /─┟┷━━━━━━━━━━━━━━━━━┥   / /                  ");
	setColor(SKYBLUE); gotoxy(3, 16);  printf("                                                                     \\▤   │ ┌─────────┐ ││▤  /─ /━━━━━━━━━━━━━━━━━━┥  │ │                 ");
	setColor(SKYBLUE); gotoxy(3, 17);  printf("                                                                           │ ├━┓      ─┤ ││  \\/  / ∪∪∪∪∪∪∪∪∪│  │ │                   ");
	setColor(SKYBLUE); gotoxy(3, 18);  printf("                                                                           │ │ ┗━┓    ▩ ││     /∪∪∪∪∪∪∪∪∪∪│  │ │                     ");
	setColor(SKYBLUE); gotoxy(3, 19);  printf("                                                                           │ ├━━━┻━━━ ▩ ││    /∪∪∪∪∪∪∪∪∪∪//  │ │                    ");
	setColor(SKYBLUE); gotoxy(3, 20);  printf("                                                                           │ │       ┻━│ │\\_  /∪∪∪∪∪∪∪∪∪∪//│  │ │                   ");
	setColor(SKYBLUE); gotoxy(3, 21);  printf("                                                                           │ └─────────┤ ││ \\_∪∪∪∪∪∪∪∪∪∪// │  │ │                  ");
	setColor(SKYBLUE); gotoxy(3, 22);  printf("                                                                           └──┬─┬──────┤ └┴┐┐ \\_───────────────────┤─┤  │ │                   ");
	setColor(SKYBLUE); gotoxy(3, 23);  printf("                                                                              │ ├━ ====└┐ ┌┤┘━━ \\_━━━━━━━━━━━━━━━━━┤ │  │ │                   ");
	setColor(SKYBLUE); gotoxy(3, 24);  printf("                                                                              │ │   ▩▩│ ││      \\_       ▩▩    │ │  │ │                   ");
	setColor(SKYBLUE); gotoxy(3, 25);  printf("                                                                              │ │   ▩▩│ ││        \\      ▩▩    │ │  │ │                   ");
	setColor(SKYBLUE); gotoxy(3, 26);  printf("                                                                              │ ├━ =====│ ││━━━━━━━━━━━━━━━━━━━━━━━┤ │  │ │                   ");
	setColor(SKYBLUE); gotoxy(3, 27);  printf("                                                                              └─┘       │ ││                       ┘ │  │ │                   ");

	setColor(YELLOW); gotoxy(3, 24);   printf("‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰");
	setColor(YELLOW); gotoxy(127, 24); printf("‰ ‰ ‰ ‰ ‰");
	setColor(YELLOW); gotoxy(3, 25);   printf(" ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰");
	setColor(YELLOW); gotoxy(127, 25); printf(" ‰ ‰ ‰ ‰ ");
	setColor(YELLOW); gotoxy(3, 26);   printf("‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰");
	setColor(YELLOW); gotoxy(127, 26); printf("‰ ‰ ‰ ‰ ‰");
	setColor(YELLOW); gotoxy(3, 27);   printf(" ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰ ‰");
	setColor(YELLOW); gotoxy(127, 27); printf(" ‰ ‰ ‰ ‰ ");
}

void PetiaWindmill() {
	PetiaWindmillimage();
	userUImain1();
	Sleep(1500);

	TextmainUI();
	gotoxy(51, 5);  printf("%s:저기요..?", playername);
	_getch();
	gotoxy(51, 7);  printf("???:들어와..");
	_getch();
	gotoxy(51, 9);  printf("%s:무기를 가지러 왔습니다.", playername);
	_getch();
	gotoxy(51, 11); printf("???:저기 상자위에 올려놨어 가져가..");
	_getch();
	gotoxy(51, 13); printf("(나무로 만든 단도를 획득하셨습니다)");
	for (int i = 0; i < 30; i++)
	{
		if (inventoryindex[i] == 0)
		{
			inventoryindex[i] = 1;
			break;
		}
	}
	_getch();
	gotoxy(51, 15); printf("???:이제 나가");
	_getch();
	canPetiaWindmil = false;

	system("cls");
	setColor(VIOLET); gotoxy(68, 5); printf("설명");
	setColor(VIOLET); gotoxy(55, 7); printf("i키를 눌러 인벤토리를 열수 있습니다.");
	gotoxy(53, 9); printf("좌우 화살표를 눌러 이동하실수 있습니다.");
	gotoxy(48, 11); printf("위 아래 화살표룰 눌러서 아이템을 선택할수 있습니다.");

	setColor(WHITE); gotoxy(58, 35); printf("아무키나 눌러서 다음으로...");
	_getch();

	system("cls");
	setColor(WHITE); gotoxy(68, 5); printf("알림");
	setColor(WHITE); gotoxy(57, 7); printf("본게임은 베타 버전이므로");
	gotoxy(42, 9); printf("이 이후는 실력부족으로 인해 스토리가 구연되어 있지 않습니다.");
	gotoxy(48, 11); printf("그러나 전투를 비롯한 다른것을 즐길수는 있으니");
	gotoxy(47, 13); printf("재미있게 플레이 하시길 바랍니다 - 제작자 일동 -");
	Sleep(2500);

	setColor(WHITE); gotoxy(58, 35); printf("아무키나 눌러서 다음으로...");
	_getch();
	petiamap();

}

void PetiaForestRoadimage() {
	setColor(SKYBLUE); gotoxy(3, 3);   printf(" ＼ │    /           /                                                                                                          ＼ ＼_        ");
	setColor(SKYBLUE); gotoxy(3, 4);   printf("  ＼│   /      _____/                                                                                                            ＼_  ＼      ");
	setColor(SKYBLUE); gotoxy(3, 5);   printf("   /   /    __/                                                                                                                     ＼ ＼_    ");
	setColor(SKYBLUE); gotoxy(3, 6);   printf("  /   /____/                                                                                                                         ＼_  ＼  ");
	setColor(SKYBLUE); gotoxy(3, 7);   printf(" │   /                                                                                                        │                         ＼ ＼ ");
	setColor(SKYBLUE); gotoxy(3, 8);   printf("/   /│                                                                              ______         _________   ＼            │           ＼ ＼");
	setColor(SKYBLUE); gotoxy(3, 9);   printf("│  / │┐                     ____________                                                  ＼______/         ＼  │            /            ＼  ");
	setColor(SKYBLUE); gotoxy(3, 10);  printf("＼/  ││                 ___//    __                                                                          │  ＼          │         │    ＼ ");
	setColor(SKYBLUE); gotoxy(3, 11);  printf(" /   ││              __/___/    /                                                               ______________＼_＼         /         │     ＼");
	setColor(SKYBLUE); gotoxy(3, 12);  printf("/    ││             /__/  _____/                                                                                  ＼       /          /       ");
	setColor(SKYBLUE); gotoxy(3, 13);  printf("     │ ＼          ││  __//                │                                                                     _/＼     │          /        ");
	setColor(SKYBLUE); gotoxy(3, 14);  printf("      ＼＼        _/└─___/         │       │                                                           _________/___＼    │         /         ");
	setColor(SKYBLUE); gotoxy(3, 15);  printf("       │ │      _/_/￣             │  ＼   /                                                             ____/      ＼   │    ____/          ");
	setColor(SKYBLUE); gotoxy(3, 16);  printf("       │ │  ___/_/│      │/        │   ＼_/                                                            __/  ││       │＼   ＼ /               ");
	setColor(SKYBLUE); gotoxy(3, 17);  printf("       │ ＼/ __/ //  ____/  │ │/    ＼  ＼                                                                  //       │ ＼   │/                ");
	setColor(SKYBLUE); gotoxy(3, 18);  printf("        ＼│ │＼ // _/ ＼_   │ ││     ＼  /                                                                 ││         ＼＼  │                 ");
	setColor(SKYBLUE); gotoxy(3, 19);  printf("         │  │ │ ＼/      ＼ │ │/      ＼│                                                                  ││          │ ＼ │                ");
	setColor(SKYBLUE); gotoxy(3, 20);  printf("         │  │  ＼│         \\│ │         /                                                                  ││                                 ");
	setColor(SKYBLUE); gotoxy(3, 21);  printf("         │  │   ││          ＼│        │                                                                                                     ");
	setColor(SKYBLUE); gotoxy(3, 22);  printf("         │  │   ││            │        /                                                                                                      ");
	setColor(SKYBLUE); gotoxy(3, 23);  printf("         │  │   ││                                                                                                                           ");
	setColor(SKYBLUE); gotoxy(3, 24);  printf("         │  │   //                                                                                                                            ");
	setColor(SKYBLUE); gotoxy(3, 25);  printf("         │  │                                                                                                                                 ");
	setColor(SKYBLUE); gotoxy(3, 26);  printf("                                                                                                                                              ");
	setColor(SKYBLUE); gotoxy(3, 27);  printf("                                                                                                                                              ");

	setColor(DARK_GREEN); gotoxy(4, 3); printf("▶▶▶▶▶▶▶▶▶▶▶▶▶▶▶▶▶▶▶▶▶▶");
	setColor(DARK_GREEN); gotoxy(99, 3); printf("◀◀◀◀◀◀◀◀◀◀◀◀◀◀◀◀");
	setColor(DARK_GREEN); gotoxy(137, 3); printf("◀◀◀◀");
	setColor(DARK_GREEN); gotoxy(9, 4); printf("▶");
	setColor(DARK_GREEN); gotoxy(12, 4); printf("▶▶▶");
	setColor(DARK_GREEN); gotoxy(24, 4); printf("▶▶▶▶▶▶▶▶▶▶▶");
	setColor(DARK_GREEN); gotoxy(98, 4); printf("◀◀◀◀◀◀◀◀◀◀◀◀◀◀◀◀◀");
	setColor(DARK_GREEN); gotoxy(139, 4); printf("◀◀");
	setColor(DARK_GREEN); gotoxy(3, 5); printf("▶");
	setColor(DARK_GREEN); gotoxy(8, 5); printf("▶");
	setColor(DARK_GREEN); gotoxy(11, 5); printf("▶▶");
	setColor(DARK_GREEN); gotoxy(18, 5); printf("▶▶▶▶▶▶▶▶▶▶▶▶▶▶");
	setColor(DARK_GREEN); gotoxy(99, 5); printf("◀◀◀◀◀◀◀◀◀◀◀◀◀◀◀");
	setColor(DARK_GREEN); gotoxy(7, 6); printf("▶");
	setColor(DARK_GREEN); gotoxy(15, 6); printf("▶▶▶▶▶▶▶▶▶▶▶▶▶▶");
	setColor(DARK_GREEN); gotoxy(101, 6); printf("◀◀◀◀◀◀◀◀◀");
	setColor(DARK_GREEN); gotoxy(6, 7); printf("▶");
	setColor(DARK_GREEN); gotoxy(9, 7); printf("▶▶▶▶▶▶▶▶▶▶▶");
	setColor(DARK_GREEN); gotoxy(3, 8); printf("▶▶");
	setColor(DARK_GREEN); gotoxy(9, 8); printf("▶▶▶▶▶▶▶▶▶");
	setColor(DARK_GREEN); gotoxy(4, 9); printf("▶");
	setColor(DARK_GREEN); gotoxy(7, 9); printf("▶▶▶▶▶▶▶▶");
	setColor(DARK_GREEN); gotoxy(6, 10); printf("▶▶▶▶▶");

	setColor(DARK_GREEN); gotoxy(137, 20); printf("◀◀◀◀");
	setColor(DARK_GREEN); gotoxy(135, 21); printf("◀◀◀◀◀");
	setColor(DARK_GREEN); gotoxy(135, 22); printf("◀◀◀◀◀");
	setColor(DARK_GREEN); gotoxy(135, 23); printf("◀◀◀◀◀");
	setColor(DARK_GREEN); gotoxy(133, 24); printf("◀◀◀◀◀◀");
	setColor(DARK_GREEN); gotoxy(133, 25); printf("◀◀◀◀◀◀");
	setColor(DARK_GREEN); gotoxy(131, 26); printf("◀◀◀◀◀◀◀");
	setColor(DARK_GREEN); gotoxy(131, 27); printf("◀◀◀◀◀◀◀");

	setColor(DAKR_YELLOW); gotoxy(143, 4); printf("▲");
	setColor(DAKR_YELLOW); gotoxy(129, 5); printf("▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(141, 5); printf("▲▲");
	setColor(DAKR_YELLOW); gotoxy(41, 6); printf("▲");
	setColor(DAKR_YELLOW); gotoxy(120, 6); printf("▲▲▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(143, 6); printf("▲");
	setColor(DAKR_YELLOW); gotoxy(31, 7); printf("▲▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(109, 7); printf("▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(27, 8); printf("▲▲▲▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(106, 8); printf("▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(23, 9); printf("▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(43, 9); printf("▲▲");
	setColor(DAKR_YELLOW); gotoxy(107, 9); printf("▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(16, 10); printf("▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(38, 10); printf("▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(108, 10); printf("▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(5, 11); printf("▲▲");
	setColor(DAKR_YELLOW); gotoxy(10, 11); printf("▲▲▲▲▲▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(36, 11); printf("▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(115, 11); printf("▲▲▲▲▲▲▲▲▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(3, 12); printf("▲▲▲▲▲▲▲▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(33, 12); printf("▲▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(119, 12); printf("▲▲▲▲▲▲▲▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(4, 13); printf("▲▲▲▲▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(25, 13); printf("▲▲");
	setColor(DAKR_YELLOW); gotoxy(31, 13); printf("▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(127, 13); printf("▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(137, 13); printf("▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(5, 14); printf("▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(13, 14); printf("▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(29, 14); printf("▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(6, 15); printf("▲▲");
	setColor(DAKR_YELLOW); gotoxy(13, 15); printf("▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(23, 15); printf("▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(8, 16); printf("▲");
	setColor(DAKR_YELLOW); gotoxy(15, 16); printf("▲▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(133, 19); printf("▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(121, 20); printf("▲▲▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(111, 21); printf("▲▲▲▲▲▲▲▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(109, 22); printf("▲▲▲▲▲▲▲▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(109, 23); printf("▲▲▲▲▲▲▲▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(107, 24); printf("▲▲▲▲▲▲▲▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(107, 25); printf("▲▲▲▲▲▲▲▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(105, 26); printf("▲▲▲▲▲▲▲▲▲▲▲▲▲");
	setColor(DAKR_YELLOW); gotoxy(105, 27); printf("▲▲▲▲▲▲▲▲▲▲▲▲▲");

	setColor(GREEN); gotoxy(95, 3); printf("▼▼");
	setColor(GREEN); gotoxy(92, 4); printf("▼▼▼▼");
	setColor(GREEN); gotoxy(91, 5); printf("▼▼▼▼▼");
	setColor(GREEN); gotoxy(43, 6); printf("▼▼");
	setColor(GREEN); gotoxy(88, 6); printf("▼▼▼▼▼▼▼");
	setColor(GREEN); gotoxy(43, 7); printf("▼▼▼");
	setColor(GREEN); gotoxy(84, 7); printf("▼▼▼▼▼▼▼▼▼▼▼▼▼");
	setColor(GREEN); gotoxy(45, 8); printf("▼▼▼");
	setColor(GREEN); gotoxy(82, 8); printf("▼▼▼");
	setColor(GREEN); gotoxy(93, 8); printf("▼▼▼▼▼");
	setColor(GREEN); gotoxy(81, 9); printf("▼▼▼▼▼▼");
	setColor(GREEN); gotoxy(103, 9); printf("▼▼");
	setColor(GREEN); gotoxy(47, 9); printf("▼▼▼");
	setColor(GREEN); gotoxy(83, 10); printf("▼▼▼▼▼▼▼▼▼▼▼▼");
	setColor(GREEN); gotoxy(50, 10); printf(" ▼▼");
	setColor(GREEN); gotoxy(87, 11); printf("▼▼▼▼▼▼▼▼▼");
	setColor(GREEN); gotoxy(48, 11); printf("▼▼▼▼");
	setColor(GREEN); gotoxy(48, 13); printf("▼▼▼▼");
	setColor(GREEN); gotoxy(47, 12); printf("▼▼▼▼");
	setColor(GREEN); gotoxy(93, 12); printf("▼▼▼▼▼▼▼▼▼▼▼▼");
	setColor(GREEN); gotoxy(41, 13); printf("▼▼▼▼▼▼");
	setColor(GREEN); gotoxy(93, 13); printf("▼▼▼▼▼▼▼▼▼▼▼");
	setColor(GREEN); gotoxy(119, 13); printf("▼▼▼▼");
	setColor(GREEN); gotoxy(37, 14); printf("▼▼▼▼▼▼▼▼▼");
	setColor(GREEN); gotoxy(97, 14); printf("▼▼▼▼▼▼▼");
	setColor(GREEN); gotoxy(117, 14); printf("▼");
	setColor(GREEN); gotoxy(121, 14); printf("▼▼▼▼▼▼▼");
	setColor(GREEN); gotoxy(136, 14); printf("▼▼");
	setColor(GREEN); gotoxy(33, 15); printf("▼▼▼▼");
	setColor(GREEN); gotoxy(42, 15); printf("▼▼");
	setColor(GREEN); gotoxy(47, 15); printf("▼▼▼");
	setColor(GREEN); gotoxy(97, 15); printf("▼▼▼▼▼▼");
	setColor(GREEN); gotoxy(114, 15); printf("▼▼▼");
	setColor(GREEN); gotoxy(121, 15); printf("▼▼");
	setColor(GREEN); gotoxy(126, 15); printf("▼▼");
	setColor(GREEN); gotoxy(135, 15); printf("▼▼");
	setColor(GREEN); gotoxy(30, 16); printf("▼▼▼▼");
	setColor(GREEN); gotoxy(40, 16); printf("▼");
	setColor(GREEN); gotoxy(46, 16); printf("▼▼▼▼");
	setColor(GREEN); gotoxy(94, 16); printf("▼▼▼▼▼▼");
	setColor(GREEN); gotoxy(113, 16); printf("▼▼▼▼");
	setColor(GREEN); gotoxy(44, 17); printf("▼▼▼▼");
	setColor(GREEN); gotoxy(19, 17); printf("▼");
	setColor(GREEN); gotoxy(22, 17); printf("▼▼");
	setColor(GREEN); gotoxy(29, 17); printf("▼▼");
	setColor(GREEN); gotoxy(35, 17); printf("▼▼");
	setColor(GREEN); gotoxy(41, 17); printf("▼");
	setColor(GREEN); gotoxy(96, 17); printf("▼▼▼▼▼▼▼▼");
	setColor(GREEN); gotoxy(114, 17); printf("▼▼▼");
	setColor(GREEN); gotoxy(4, 18); printf("▼▼");
	setColor(GREEN); gotoxy(16, 18); printf("▼▼");
	setColor(GREEN); gotoxy(21, 18); printf("▼");
	setColor(GREEN); gotoxy(24, 18); printf("▼▼▼▼");
	setColor(GREEN); gotoxy(102, 18); printf("▼▼▼▼");
	setColor(GREEN); gotoxy(112, 18); printf("▼▼▼▼");
	setColor(GREEN); gotoxy(4, 19); printf("▼▼▼");
	setColor(GREEN); gotoxy(22, 19); printf("▼▼▼");
	setColor(GREEN); gotoxy(24, 19); printf("▼");
	setColor(GREEN); gotoxy(4, 20); printf("▼▼▼");
	setColor(GREEN); gotoxy(21, 20); printf("▼▼▼▼");
	setColor(GREEN); gotoxy(4, 21); printf("▼▼▼");
	setColor(GREEN); gotoxy(109, 21); printf("▼");
	setColor(GREEN); gotoxy(4, 22); printf("▼▼▼▼");
	setColor(GREEN); gotoxy(107, 22); printf("▼▼");
	setColor(GREEN); gotoxy(4, 23); printf("▼▼▼▼");
	setColor(GREEN); gotoxy(105, 23); printf("▼▼");
	setColor(GREEN); gotoxy(4, 24); printf("▼▼▼▼");
	setColor(GREEN); gotoxy(103, 24); printf("▼▼");
	setColor(GREEN); gotoxy(4, 25); printf("▼▼▼");
	setColor(GREEN); gotoxy(103, 25); printf("▼▼");
	setColor(GREEN); gotoxy(101, 26); printf("▼▼");
	setColor(GREEN); gotoxy(101, 27); printf("▼▼");

	setColor(GRAY); gotoxy(94, 20); printf("※※※※※※※※");
	setColor(GRAY); gotoxy(84, 21); printf("※※※※※※※※");
	setColor(GRAY); gotoxy(78, 22); printf("※※※※※※※※※");
	setColor(GRAY); gotoxy(74, 23); printf("※※※※※※※※※");
	setColor(GRAY); gotoxy(70, 24); printf("※※※※※※※※※※");
	setColor(GRAY); gotoxy(69, 25); printf("※※※※※※※※※※");
	setColor(GRAY); gotoxy(68, 26); printf("※※※※※※※※※※※※");
	setColor(GRAY); gotoxy(66, 27); printf("※※※※※※※※※※※※※※");
}

void PetiaForestRoad() {
	PetiaForestRoadimage();
	userUImain1();

	int piernum = 0;
	setColor(WHITE); gotoxy(41, 31); printf("모험하기");
	setColor(WHITE); gotoxy(91, 31); printf("돌아가기");
	int key = _getch();
	while (true)
	{
		if (piernum == 0)
		{
			gotoxy(39, 31);
			setColor(WHITE); printf("→");
		}
		else {
			gotoxy(39, 31);
			printf("  ");
		}

		if (piernum == 1)
		{
			gotoxy(89, 31);
			setColor(WHITE); printf("→");
		}
		else {
			gotoxy(89, 31);
			printf("  ");
		}

		if (piernum >= 2)
		{
			piernum = 0;
		}
		if (piernum < 0)
		{
			piernum = 1;
		}

		if (key == 13)
		{
			if (piernum == 0)
			{
				TextmainUI();
				for (int i = 0; i < 2; i++)
				{
					setColor(WHITE); gotoxy(71, 15); printf("모험중.   "); Sleep(800);
					setColor(WHITE); gotoxy(71, 15); printf("모험중..  "); Sleep(800);
					setColor(WHITE); gotoxy(71, 15); printf("모험중... "); Sleep(800);
					setColor(WHITE); gotoxy(71, 15); printf("모험중...."); Sleep(800);
				}
				TextmainUI();
				setColor(WHITE); gotoxy(60, 15); printf("나무정령 (이)가 싸움을 걸어왔다!"); Sleep(1000);
				enemyreset(10, 3);
				background = 2;
				battel();
				petiapier();

			}
			if (piernum == 1)
			{
				petiamap();
				break;
			}
		}

		if (key == 105)
		{
			playerinventoty();
			PetiaForestRoad();
		}

		if (_kbhit())
		{
			key = _getch();
			if (key == 224)
			{
				key = _getch();
				switch (key)
				{
				case 77:
					piernum++;
					break;
				case 75:
					piernum--;
					break;
				}
			}
		}
	}
}



void hmillamap() {
	setColor(GREEN); gotoxy(1, 1);  printf("");
	setColor(GREEN); gotoxy(1, 2);  printf("  _______________________________________________________________________________________________________________________________________________");
	setColor(GREEN); gotoxy(1, 3);  printf(" ㅣ   \\                  ______________                                               ____________                  ___/      \\_   \\____/\\____/ ㅣ");
	setColor(GREEN); gotoxy(1, 4);  printf(" ㅣ    \\___    _________/              \\_________________                ____________/            \\________     ___/      ♣    )  /          \\ ㅣ");
	setColor(GREEN); gotoxy(1, 5);  printf(" ㅣ        \\__/                           /\\             \\______________/ /\\                               \\___/  \\            |   흐밀라  마을 ㅣ");
	setColor(GREEN); gotoxy(1, 6);  printf(" ㅣ           \\____                      /  \\           /^^^^^^^^\\       /  \\                 /\\                   )    ♣    /    \\____  ____/ ㅣ");
	setColor(GREEN); gotoxy(1, 7);  printf(" ㅣ                \\__        /\\        /_||_\\     /\\  /**********\\     /_||_\\   /\\          /  \\                _/          /     /    \\/    \\ ㅣ");
	setColor(GREEN); gotoxy(1, 8);  printf(" ㅣ                   \\      /  \\         ||      /  \\/^^^^^^^^^^^^\\      ||    /  \\        /_||_\\            __/    ♣     /          _        ㅣ");
	setColor(GREEN); gotoxy(1, 9);  printf(" ㅣ                    )    /_||_\\               /_||/&&&&&&&&&&&&&&\\ /\\       /_||_\\         ||             /              |   _               ㅣ");
	setColor(GREEN); gotoxy(1, 10); printf(" ㅣ                  _/       ||      /\\           |/^^^^^^^^^^^^^^^^\\  \\        ||       /\\                /   ♣         (        _           ㅣ");
	setColor(GREEN); gotoxy(1, 11); printf(" ㅣ                 (                /  \\     /\\   /******************\\|_\\               /  \\               |               |                _  ㅣ");
	setColor(GREEN); gotoxy(1, 12); printf(" ㅣ                  \\_             /_||_\\   /  \\ /^^^^^^^^^^^^^^^^^^^^\\ <- 숨겨진 교회 /_||_\\             /          ♣     \\_          _      ㅣ");
	setColor(GREEN); gotoxy(1, 13); printf(" ㅣ                    \\              ||    /_||_/&&&&&&&&&&&&&&&&&&&&&&\\       /\\        ||              /                    \\                ㅣ");
	setColor(GREEN); gotoxy(1, 14); printf(" ㅣ                     )     /\\              ||/^^^^^^^^^^^^^^^^^^^^^^^^\\     /  \\                      /       ♣             \\            _  ㅣ");
	setColor(GREEN); gotoxy(1, 15); printf(" ㅣ                    /     /  \\              /**************************\\   /_||_\\                    |                        \\   _          ㅣ");
	setColor(GREEN); gotoxy(1, 16); printf(" ㅣ                   |     /_||_\\            /^^^^^^^^^^^^^^^^^^^^^^^^^^^^\\    ||              /\\     (   ♣                ♣   \\      _      ㅣ");
	setColor(GREEN); gotoxy(1, 17); printf(" ㅣ                __/    /\\  ||             /__&&&&&&&&&&&&&&&&&&&&&&&&&&__\\        /\\        /  \\     |           ♣             \\          _ ㅣ");
	setColor(GREEN); gotoxy(1, 18); printf(" ㅣ              _/      /  \\        /\\        /^^^^^^^^^^^^^^^^^^^^^^^^^^\\         /  \\      /_||_\\     \\     ♣                   \\   _       ㅣ");
	setColor(GREEN); gotoxy(1, 19); printf(" ㅣ           __/       /_||_\\      /  \\      /****************************\\       /_||_\\       ||        \\_          ♣             |          ㅣ");
	setColor(GREEN); gotoxy(1, 20); printf(" ㅣ          /            ||       /_||_\\    /^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\\        ||    /\\               )                         )     _   ㅣ");
	setColor(GREEN); gotoxy(1, 21); printf(" ㅣ         (                  /\\    ||     /********************************\\            /  \\             |     ♣              ♣  |          ㅣ");
	setColor(GREEN); gotoxy(1, 22); printf(" ㅣ          |      /\\        /  \\         /___^^^^^^^^^^^^^^^^^^^^^^^^^^^^___\\     /\\   /_||_\\           /               ♣        /       _   ㅣ");
	setColor(GREEN); gotoxy(1, 23); printf(" ㅣ           \\_   /  \\      /_||_\\           /&&&&&&&&&&&&&&&&&&&&&&&&&&&&\\       /  \\    ||            /                         /            ㅣ");
	setColor(GREEN); gotoxy(1, 24); printf(" ㅣ             \\ /_||_\\       ||            /^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\\     /_||_\\         /\\     /       ♣                /      _      ㅣ");
	setColor(GREEN); gotoxy(1, 25); printf(" ㅣ              |  ||  /\\                  /***********|{}{}={}{}|**********\\      ||          /  \\   |              ♣         |            _ ㅣ");
	setColor(GREEN); gotoxy(1, 26); printf(" ㅣ              |     /  \\                /____________|}{}{=}{}{|___________\\                /_||_\\ /                         (     _         ㅣ");
	setColor(GREEN); gotoxy(1, 27); printf(" ㅣ            _/     /_||_\\           /\\               |{}{}={}{}|                       /\\     ||  /      ♣                   |           _  ㅣ");
	setColor(GREEN); gotoxy(1, 28); printf(" ㅣ           /         ||            /  \\              |}{}{=}{}{|           /\\         /  \\       /             ♣              \\         _   ㅣ");
	setColor(GREEN); gotoxy(1, 29); printf(" ㅣ          |                       /_||_\\                                  /  \\       /_||_\\     /                     ♣        \\   _        ㅣ");
	setColor(GREEN); gotoxy(1, 30); printf(" ㅣ        _/             /\\           ||               1.숲의 중심         /_||_\\        ||      (        ♣      3.늪지           \\     _     ㅣ");
	setColor(GREEN); gotoxy(1, 31); printf(" ㅣ      _/         /\\   /  \\      /\\              /\\              /\\         ||                   \\                                 |          ㅣ");
	setColor(GREEN); gotoxy(1, 32); printf(" ㅣ    _/          /  \\ /_||_\\    /  \\    /\\      /  \\            /  \\           /\\                ┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳          ♣       )     _   ㅣ");
	setColor(GREEN); gotoxy(1, 33); printf(" ㅣ   /           /_||_\\  || /\\  /_||_\\  /  \\    /_||_\\      /\\  /_||_\\  /\\     /  \\      /\\       ┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻                  | _        ㅣ");
	setColor(GREEN); gotoxy(1, 34); printf(" ㅣ  |              ||      /  \\   ||   /_||_\\     ||       /  \\   ||   /  \\   /_||_\\    /  \\         \\               ♣            /       _   ㅣ");
	setColor(GREEN); gotoxy(1, 35); printf(" ㅣ /                      /_||_\\         ||               /_||_\\      /_||_\\    ||     /_||_\\         \\       ♣                  /    _       ㅣ");
	setColor(GREEN); gotoxy(1, 36); printf(" ㅣ/                         ||                              ||          ||               ||            \\                  ♣     /  _         _ㅣ");
	setColor(GREEN); gotoxy(1, 37); printf("  _______________________________________________________________________________________________________________________________________________ ");
	setColor(GREEN); gotoxy(1, 38); printf("");
}

void petiamapsuper() {
	int petianum = 0;


	setColor(SKYBLUE); gotoxy(1, 2);  printf("  _______________________________________________________________________________________________________________________________________________");
	setColor(SKYBLUE); gotoxy(1, 3);  printf(" ㅣ             \\                                                                     __                        \\                \\____/\\____/   ㅣ");
	setColor(SKYBLUE); gotoxy(1, 4);  printf(" ㅣ   _          \\                                                                ___|__|                /\\      \\___            /          \\   ㅣ");
	setColor(SKYBLUE); gotoxy(1, 5);  printf(" ㅣ        _     /                                                             _ /   | \\_               /  \\         \\__         페티아  마을   ㅣ");
	setColor(SKYBLUE); gotoxy(1, 6);  printf(" ㅣ _   |>      /                             ╋                               |_|___●__|_|             /_||_\\       /\\  \\____    \\____  ____/   ㅣ");
	setColor(SKYBLUE); gotoxy(1, 7);  printf(" ㅣ     |    _ |                            _/^\\_                              /  __|    \\               ||        /  \\      \\__ /    \\/    \\   ㅣ");
	setColor(SKYBLUE); gotoxy(1, 8);  printf(" ㅣ_ \\=====/   |                           /^^^^^\\                             | |__|    |                        /_||_\\        \\               ㅣ");
	setColor(SKYBLUE); gotoxy(1, 9);  printf(" ㅣ      _    /                     ______|^^^^^^^|______                      |_________|                 /\\       ||           )         /    ㅣ");
	setColor(SKYBLUE); gotoxy(1, 10); printf(" ㅣ  _   ┲┲┲┲┲┲                    /^_    _      _    _ ^\\                                                /  \\                 _/     /         ㅣ");
	setColor(SKYBLUE); gotoxy(1, 11); printf(" ㅣ _    ┸┸┸┸┸┸                   /^/ \\  / \\    / \\  / \\ ^\\                      6.풍차                  /_||_\\          /\\   (                 ㅣ");
	setColor(SKYBLUE); gotoxy(1, 12); printf(" ㅣ     _    /                   |__|_|__|_|    |_|__|_|___|                                               ||           /  \\   \\_      /        ㅣ");
	setColor(SKYBLUE); gotoxy(1, 13); printf(" ㅣ   _     /     3.부두         |_________________________|                                                           /_||_\\    \\        /     ㅣ");
	setColor(SKYBLUE); gotoxy(1, 14); printf(" ㅣ_   ┲┲┲┲┲┲                                                                                                   /\\       ||       )             ㅣ");
	setColor(SKYBLUE); gotoxy(1, 15); printf(" ㅣ    ┸┸┸┸┸┸                           1.인내의 교회                                                          /  \\              /    /         ㅣ");
	setColor(SKYBLUE); gotoxy(1, 16); printf(" ㅣ _     /                                                                                             /\\    /_||_\\            |       /       ㅣ");
	setColor(SKYBLUE); gotoxy(1, 17); printf(" ㅣ   _  |                                                                                             /  \\     ||           __/                ㅣ");
	setColor(SKYBLUE); gotoxy(1, 18); printf(" ㅣ  _  /                                                                  ______                     /_||_\\               _/           /       ㅣ");
	setColor(SKYBLUE); gotoxy(1, 19); printf(" ㅣ _  |                                                                  /^^^^^^\\                      ||        /\\    __/       /             ㅣ");
	setColor(SKYBLUE); gotoxy(1, 20); printf(" ㅣ   /                                                                  /________\\                              /  \\  /                        ㅣ");
	setColor(SKYBLUE); gotoxy(1, 21); printf(" ㅣ   \\___        .                                                       |()|_|_|                 5.숲 외각길  /_||_\\(                    /    ㅣ");
	setColor(SKYBLUE); gotoxy(1, 22); printf(" ㅣ   _   \\    .                                                          |()|_|_|                        /\\      ||   |        /               ㅣ");
	setColor(SKYBLUE); gotoxy(1, 23); printf(" ㅣ _      |       .                                                      |______|                       /  \\      /\\   \\_                /     ㅣ");
	setColor(SKYBLUE); gotoxy(1, 24); printf(" ㅣ        |   .     .                                                           ______                 /_||_\\    /  \\    \\             /       ㅣ");
	setColor(SKYBLUE); gotoxy(1, 25); printf(" ㅣ     _  |  .   . .   .                                                       /^^^^^^\\                  ||     /_||_\\    |         /          ㅣ");
	setColor(SKYBLUE); gotoxy(1, 26); printf(" ㅣ  _     |  . .     .                                          2.인근 마을   /________\\                          ||      |                    ㅣ");
	setColor(SKYBLUE); gotoxy(1, 27); printf(" ㅣ         \\  . .  .   .  .                                                    |()|_|_|                    /\\           _/          /          ㅣ");
	setColor(SKYBLUE); gotoxy(1, 28); printf(" ㅣ     _    |  .   . .      4. 해변가                             ______       |()|_|_|                   /  \\         /                       ㅣ");
	setColor(SKYBLUE); gotoxy(1, 29); printf(" ㅣ        _  \\. .    .    .                                      /^^^^^^\\      |______|                  /_||_\\       |      /          /      ㅣ");
	setColor(SKYBLUE); gotoxy(1, 30); printf(" ㅣ            \\ . . .  .                                        /________\\                                 ||       _/                         ㅣ");
	setColor(SKYBLUE); gotoxy(1, 31); printf(" ㅣ  _   _      \\ . . .      .                                    |()|_|_|                                         _/                /          ㅣ");
	setColor(SKYBLUE); gotoxy(1, 32); printf(" ㅣ         _    \\  . .  .      .                                 |()|_|_|                               /\\      _/                             ㅣ");
	setColor(SKYBLUE); gotoxy(1, 33); printf(" ㅣ    _          \\ .  . .   .                                    |______|                              /  \\    /                  /            ㅣ");
	setColor(SKYBLUE); gotoxy(1, 34); printf(" ㅣ        _       \\  . .   .   .                                                                      /_||_\\  |         /              /       ㅣ");
	setColor(SKYBLUE); gotoxy(1, 35); printf(" ㅣ    _        _   \\.  . . .  .                                                                         ||   /                  /              ㅣ");
	setColor(SKYBLUE); gotoxy(1, 36); printf(" ㅣ           _      \\. .  .  .                                                                              /          /           /           ㅣ");
	setColor(SKYBLUE); gotoxy(1, 37); printf("  _______________________________________________________________________________________________________________________________________________ ");
	setColor(SKYBLUE); gotoxy(1, 38); printf("");

	while (true)
	{
		gotoxy(15, 3); printf(" ");
		gotoxy(4, 3); printf("_");
		Sleep(500);
		gotoxy(4, 3); printf(" ");
		gotoxy(5, 3); printf("_");
		Sleep(500);
		gotoxy(5, 3); printf(" ");
		gotoxy(6, 3); printf("_");
		Sleep(500);
		gotoxy(6, 3); printf(" ");
		gotoxy(7, 3); printf("_");
		Sleep(500);
		gotoxy(7, 3); printf(" ");
		gotoxy(8, 3); printf("_");
		Sleep(500);
		gotoxy(8, 3); printf(" ");
		gotoxy(9, 3); printf("_");
		Sleep(500);
		gotoxy(9, 3); printf(" ");
		gotoxy(10, 3); printf("_");
		Sleep(500);
		gotoxy(10, 3); printf(" ");
		gotoxy(11, 3); printf("_");
		Sleep(500);
		gotoxy(11, 3); printf(" ");
		gotoxy(12, 3); printf("_");
		Sleep(500);
		gotoxy(12, 3); printf(" ");
		gotoxy(13, 3); printf("_");
		Sleep(500);
		gotoxy(13, 3); printf(" ");
		gotoxy(14, 3); printf("_");
		Sleep(500);
		gotoxy(14, 3); printf(" ");
		gotoxy(15, 3); printf("_");
	}
}

void TextmainUI() {
	setColor(WHITE); gotoxy(50, 3);  printf(" ________________________________________________");
	setColor(WHITE); gotoxy(50, 4);  printf("|                                                |");
	setColor(WHITE); gotoxy(50, 5);  printf("|                                                |");
	setColor(WHITE); gotoxy(50, 6);  printf("|                                                |");
	setColor(WHITE); gotoxy(50, 7);  printf("|                                                |");
	setColor(WHITE); gotoxy(50, 8);  printf("|                                                |");
	setColor(WHITE); gotoxy(50, 9);  printf("|                                                |");
	setColor(WHITE); gotoxy(50, 10); printf("|                                                |");
	setColor(WHITE); gotoxy(50, 11); printf("|                                                |");
	setColor(WHITE); gotoxy(50, 12); printf("|                                                |");
	setColor(WHITE); gotoxy(50, 13); printf("|                                                |");
	setColor(WHITE); gotoxy(50, 14); printf("|                                                |");
	setColor(WHITE); gotoxy(50, 15); printf("|                                                |");
	setColor(WHITE); gotoxy(50, 16); printf("|                                                |");
	setColor(WHITE); gotoxy(50, 17); printf("|                                                |");
	setColor(WHITE); gotoxy(50, 18); printf("|                                                |");
	setColor(WHITE); gotoxy(50, 19); printf("|                                                |");
	setColor(WHITE); gotoxy(50, 20); printf("|                                                |");
	setColor(WHITE); gotoxy(50, 21); printf("|                                                |");
	setColor(WHITE); gotoxy(50, 22); printf("|                                                |");
	setColor(WHITE); gotoxy(50, 23); printf("|                                                |");
	setColor(WHITE); gotoxy(50, 24); printf("|                                                |");
	setColor(WHITE); gotoxy(50, 25); printf("|                                                |");
	setColor(WHITE); gotoxy(50, 26); printf("|                                                |");
	setColor(WHITE); gotoxy(50, 27); printf("|________________________________________________|");
}

void TextmainUImini() {
	setColor(WHITE); gotoxy(58, 6);   printf(" _________________");
	setColor(WHITE); gotoxy(58, 7);   printf("|                 |");
	setColor(WHITE); gotoxy(58, 8);   printf("|                 |");
	setColor(WHITE); gotoxy(58, 9);   printf("|                 |");
	setColor(WHITE); gotoxy(58, 10);  printf("|                 |");
	setColor(WHITE); gotoxy(58, 11);  printf("|                 |");
	setColor(WHITE); gotoxy(58, 12);  printf("|                 |");
	setColor(WHITE); gotoxy(58, 13);  printf("|_________________|");
}

void Chapter1image() {
	char print[6][90] = { " ", };
	int speed = 500;

	strcpy_s(print[0], "  ______   __    __       ___      .______   .___________.  _______  .______        __  ");
	strcpy_s(print[1], " /      | |  |  |  |     /   \\     |   _  \\  |           | |   ____| |   _  \\      /_ |");
	strcpy_s(print[2], "|  ,----' |  |__|  |    /  ^  \\    |  |_)  | `---|  |----` |  |__    |  |_)  |      | | ");
	strcpy_s(print[3], "|  |      |   __   |   /  /_\\  \\   |   ___/      |  |      |   __|   |      /       | | ");
	strcpy_s(print[4], "|  `----. |  |  |  |  /  _____  \\  |  |          |  |      |  |____  |  |\\  \\--.    | | ");
	strcpy_s(print[5], " \\______| |__|  |__| /__/     \\__\\ | _|          |__|      |_______| | _| `.___|    |_| ");

	gotoxy(24, 6); printf(print[0]);
	Sleep(speed);
	gotoxy(24, 7); printf(print[1]);
	Sleep(speed);
	gotoxy(24, 8); printf(print[2]);
	Sleep(speed);
	gotoxy(24, 9); printf(print[3]);
	Sleep(speed);
	gotoxy(24, 10); printf(print[4]);
	Sleep(speed);
	gotoxy(24, 11); printf(print[5]);
	Sleep(speed);

}

void gameover() {
	int num = 0;
	system("cls");
	gotoxy(35, 1);  printf("                                                  .         .");
	gotoxy(35, 1);  printf("    ,o888888o.             .8.                   ,8.       ,8.          8 888888888888");
	gotoxy(35, 2);  printf("   8888     `88.          .888.                 ,888.     ,888.         8 8888        ");
	gotoxy(35, 3);  printf(",8 8888       `8.        :88888.               .`8888.   .`8888.        8 8888        ");
	gotoxy(35, 4);  printf("88 8888                 . `88888.             ,8.`8888. ,8.`8888.       8 8888        ");
	gotoxy(35, 5);  printf("88 8888                .8. `88888.           ,8'8.`8888,8^8.`8888.      8 888888888888");
	gotoxy(35, 6);  printf("88 8888               .8`8. `88888.         ,8' `8.`8888' `8.`8888.     8 8888        ");
	gotoxy(35, 7);  printf("88 8888   8888888    .8' `8. `88888.       ,8'   `8.`88'   `8.`8888.    8 8888        ");
	gotoxy(35, 8);  printf("`8 8888       .8'   .8'   `8. `88888.     ,8'     `8.`'     `8.`8888.   8 8888        ");
	gotoxy(35, 9);  printf("   8888     ,88'   .888888888. `88888.   ,8'       `8        `8.`8888.  8 8888        ");
	gotoxy(35, 10); printf("    `8888888P'    .8'       `8. `88888. ,8'         `         `8.`8888. 8 888888888888");

	gotoxy(39, 13);  printf("      ,o888888o.      `8.`888b           ,8'   8 8888888888      8 888888888o.   ");
	gotoxy(39, 14);  printf("   . 8888     `88.     `8.`888b         ,8'    8 8888            8 8888    `88.  ");
	gotoxy(39, 15);  printf("  ,8 8888       `8b     `8.`888b       ,8'     8 8888            8 8888     `88  ");
	gotoxy(39, 16);  printf("  88 8888        `8b     `8.`888b     ,8'      8 8888            8 8888     ,88  ");
	gotoxy(39, 17);  printf("  88 8888         88      `8.`888b   ,8'       8 888888888888    8 8888.   ,88'  ");
	gotoxy(39, 18);  printf("  88 8888         88       `8.`888b ,8'        8 8888            8 888888888P'   ");
	gotoxy(39, 19);  printf("  88 8888        ,8P        `8.`888b8'         8 8888            8 8888`8b       ");
	gotoxy(39, 20);  printf("  `8 8888       ,8P          `8.`888'          8 8888            8 8888 `8b.     ");
	gotoxy(39, 21); printf("    ` 8888     ,88'            `8.`8'           8 8888            8 8888   `8b.   ");
	gotoxy(39, 22); printf("       `8888888P'               `8.`            8 888888888888    8 8888     `88. ");

	gotoxy(55, 29); printf("당신은 죽으셨습니다.");
	gotoxy(55, 30); printf("죽은 사람은 살릴수 없습니다.");
	gotoxy(55, 31); printf("그래도 모험을 게속 하고 싶습니까?");
	gotoxy(62, 33); printf("예");
	gotoxy(71, 33); printf("아니요");
	int key = _getch();
	while (true)
	{
		if (num == 0)
		{
			gotoxy(61, 33); printf("→");
		}
		else
		{
			gotoxy(61, 33); printf(" ");
		}
		if (num == 1)
		{
			gotoxy(70, 33); printf("→");
		}
		else
		{
			gotoxy(70, 33); printf(" ");
		}

		if (num >= 2)
		{
			num = 0;
		}
		if (num < 0)
		{
			num = 1;
		}

		if (key == 13)
		{
			if (num == 0)
			{
				system("cls");
				for (int i = 0; i < 3; i++)
				{
					setColor(WHITE); gotoxy(66, 10); printf("영혼을 이동중입니다.   "); Sleep(800);
					setColor(WHITE); gotoxy(66, 10); printf("영혼을 이동중입니다.."); Sleep(800);
					setColor(WHITE); gotoxy(66, 10); printf("영혼을 이동중입니다..."); Sleep(800);
					setColor(WHITE); gotoxy(66, 10); printf("영혼을 이동중입니다...."); Sleep(800);
					setColor(WHITE); gotoxy(66, 10); printf("                            ");

				}
				for (int i = 0; i < 3; i++)
				{
					setColor(WHITE); gotoxy(66, 10); printf("육체를 생성중입니다.   "); Sleep(800);
					setColor(WHITE); gotoxy(66, 10); printf("육체를 생성중입니다.."); Sleep(800);
					setColor(WHITE); gotoxy(66, 10); printf("육체를 생성중입니다..."); Sleep(800);
					setColor(WHITE); gotoxy(66, 10); printf("육체를 생성중입니다...."); Sleep(800);
					setColor(WHITE); gotoxy(66, 10); printf("                            ");

				}
				for (int i = 0; i < 3; i++)
				{
					setColor(WHITE); gotoxy(55, 10); printf("영혼과 육체를 결합하는 중입니다.   "); Sleep(800);
					setColor(WHITE); gotoxy(55, 10); printf("영혼과 육체를 결합하는 중입니다.."); Sleep(800);
					setColor(WHITE); gotoxy(55, 10); printf("영혼과 육체를 결합하는 중입니다..."); Sleep(800);
					setColor(WHITE); gotoxy(55, 10); printf("영혼과 육체를 결합하는 중입니다...."); Sleep(800);
					setColor(WHITE); gotoxy(55, 10); printf("                                 ");

				}
				setColor(WHITE); gotoxy(68, 10); printf("세계를 재시작합니다."); Sleep(2000);
				system("cls");
				the_Patience_of_Paladin();
			}
			if (num == 1)
			{
				exit(0);
			}
		}

		if (_kbhit())
		{
			key = _getch();
			if (key == 224)
			{
				key = _getch();
				switch (key)
				{
				case 77:
					num++;
					break;
				case 75:
					num--;
					break;
				}
			}
		}
	}
}

void enemyreset(int HP, int power) {
	EnemyHP = HP;
	EnemyPower = power;
}
