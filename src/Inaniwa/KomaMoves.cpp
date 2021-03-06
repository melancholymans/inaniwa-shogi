﻿// 方向を示す定数。
int Direct[12]={
	17,1,-15,16,-16,15,-1,-17,14,-18,18,-14
};

// 成ることが出来る駒か？
int CanPromote[]={
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

// その方向に動けるか？その方向に飛んで動くものは入れてはいけない。
int CanMove[12][64]={
	{
	// Direct[0]=17,
	// |／
	//  ￣
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=1,
	// ↓
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,1,0,0,1,1,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=-15,
	// ＼|
	// ￣
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=16,
	// ←
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=-16,
	// →
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=15,
	//  __
	// |＼
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,1,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=-1,
	// ↑
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,1,1,1,1,1,1,0,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=-17
	// __
	// ／|
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,1,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=14,先手の桂馬
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=-18,先手の桂馬
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=-14,後手の桂馬
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=18,後手の桂馬
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	}
};

// その方向に飛んで動くことが出来るか？
// 飛車角香車と龍と馬しかそういう駒はない
int CanJump[12][64]={
	// Direct[0]=17,
	// ＼|
	// ￣
	{
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=1,
	// ↓
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=-15,
	// ＼|
	// ￣
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=16,
	// ←
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=-16,
	// →
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=15,
	//  __
	// |＼
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=-1,
	// ↑
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=-17
	// __
	// ／|
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=14,先手の桂馬飛び
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=-18,先手の桂馬飛び
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=-14,後手の桂馬飛び
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},{
	// Direct[0]=18,後手の桂馬飛び
//  空空空空空空空空空空空空空空空空空歩香桂銀金角飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//	空歩香桂銀金角飛王と杏圭全金馬龍壁空空空空空空空空空空空空空空空
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	}
};

// 駒の種類を表示するための文字列
const char *komaStr[]={
"   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ",
"   "," FU"," KY"," KE"," GI"," KI"," KA"," HI"," OU"," TO"," NY"," NK"," NG"," KI"," UM"," RY",
"   ","vFU","vKY","vKE","vGI","vKI","vKA","vHI","vOU","vTO","vNY","vNK","vNG","vKI","vUM","vRY",
" WA","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ",
};

// 駒の種類を表示するための文字列
const char *komaStr2[]={
"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ",
"  ","FU","KY","KE","GI","KI","KA","HI","OU","TO","NY","NK","NG","KI","UM","RY",
"  ","FU","KY","KE","GI","KI","KA","HI","OU","TO","NY","NK","NG","KI","UM","RY",
" WA","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ",
};

// SFEN形式における指し手の表示で、段の数字をアルファベットに変換する配列
const char *danSFENNameArray[] = {
	"", "a", "b", "c", "d", "e", "f", "g", "h", "i",
};

const char *mochiGomaSFENNameArray[]={
"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ",
"  ","P","L","N","S","G","B","R","","","","","","","","",
"  ","P","L","N","S","G","B","R","","","","","","","","",
"","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ",
};

int KomaValue[]={
//  空空空空空空空空空空空空空空空空空 歩  香  桂   銀   金   角   飛    王    と   杏  圭   全   金   馬   龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,100,600,700,1000,1200,1800,2000,10000,1200,1200,1200,1200,1200,2000,2200,
//	空  歩   香   桂    銀    金    角    飛     王    と    杏    圭    全    金    馬    龍 壁
	0,-100,-600,-700,-1000,-1200,-1800,-2000,-10000,-1200,-1200,-1200,-1200,-1200,-2000,-2200,0
};

int HandValue[]={
//  空空空空空空空空空空空空空空空空空 歩  香  桂   銀   金   角   飛王と杏圭全金馬龍
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,105,630,735,1050,1260,1890,2100,0,0,0,0,0,0,0,0,
//	空  歩   香   桂    銀    金    角    飛
	0,-105,-630,-735,-1050,-1260,-1890,-2100
};
