//                                          csp-j 初赛答题卡
//省份：_________________________   分赛区：___________________________________  学校：________________________________________
//姓名:________________________________________________  性别：_____________________  准考证号：_______________________________
//-----------------------------------------------------------------------------------------------------------------------------
//|  01.[ A ] [ B ] [ C ] [ D ]  |  02.[ A ] [ B ] [ C ] [ D ]  |  03.[ A ] [ B ] [ C ] [ D ]  |  04.[ A ] [ B ] [ C ] [ D ]  |
//|  05.[ A ] [ B ] [ C ] [ D ]  |  06.[ A ] [ B ] [ C ] [ D ]  |  07.[ A ] [ B ] [ C ] [ D ]  |  08.[ A ] [ B ] [ C ] [ D ]  |
//|  09.[ A ] [ B ] [ C ] [ D ]  |  10.[ A ] [ B ] [ C ] [ D ]  |  11.[ A ] [ B ] [ C ] [ D ]  |  12.[ A ] [ B ] [ C ] [ D ]  |
//|  13.[ A ] [ B ] [ C ] [ D ]  |  14.[ A ] [ B ] [ C ] [ D ]  |  15.[ A ] [ B ] [ C ] [ D ]  |  16.[---] [ B ] [ C ] [ D ]  |
//-----------------------------------------------------------------------------------------------------------------------------
//|  17.[ A ] [ B ] [ C ] [ D ]  |  18.[ A ] [ B ] [ C ] [ D ]  |  19.[ A ] [ B ] [ C ] [ D ]  |  20.[ A ] [ B ] [ C ] [ D ]  |
//|  21.[ A ] [ B ] [ C ] [ D ]  |  22.[ A ] [ B ] [ C ] [ D ]  |  23.[ A ] [ B ] [ C ] [ D ]  |  24.[ A ] [ B ] [ C ] [ D ]  |
//|  25.[ A ] [ B ] [ C ] [ D ]  |  26.[ A ] [ B ] [ C ] [ D ]  |  27.[ A ] [ B ] [ C ] [ D ]  |  28.[ A ] [ B ] [ C ] [ D ]  |
//|  29.[ A ] [ B ] [ C ] [ D ]  |  30.[ A ] [ B ] [ C ] [ D ]  |  31.[ A ] [ B ] [ C ] [ D ]  |  32.[ A ] [ B ] [ C ] [ D ]  |
//-----------------------------------------------------------------------------------------------------------------------------
//答题卡，用时自取，不要加减行！只要前14行！用时可把注释去掉
#include<bits/stdc++.h>
#include<WINDOWS.H>
using namespace std;
string a,b,c,d,e,f,g,h,s1,s2,s3,s4,s5,s6;
int all_len,x,dui,cuo,fen,fs[33]= {0,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5};
//分数数组， 共32题，可自行编译
char da[33]= {'x','B','C','D','A','C','B','B','A','D','C','A','C','C','B','A','C','D','A','C','D','A','A','B','A','C','D','A','C','B','A','D','A'};
//答案数组，前导'x'不算， 共32题，可自行编译
char dc[33];
//答题情况数组，对则存为'A'，错则存为'W'
int main() {
	printf("欢");
	Sleep(800);
	printf("迎");
	Sleep(800);
	printf("来");
	Sleep(800);
	printf("到");
	Sleep(800);
	printf("测");
	Sleep(800);
	printf("评");
	Sleep(800);
	printf("机");
	Sleep(800);
	printf("6");
	Sleep(800);
	printf(".");
	Sleep(800);
	printf("0");
	Sleep(800);
	printf("!");
	Sleep(1200);
	system("cls");
//	招牌
	printf("请");
	Sleep(800);
	printf("输");
	Sleep(800);
	printf("入");
	Sleep(800);
	printf("答");
	Sleep(800);
	printf("题");
	Sleep(800);
	printf("卡");
	Sleep(800);
	printf("：");
	Sleep(800);
//	提示语
	getline(cin,s1);
	getline(cin,s2);
	getline(cin,s3);
	getline(cin,s4);
	getline(cin,a);
	getline(cin,b);
	getline(cin,c);
	getline(cin,d);
	getline(cin,s5);
	getline(cin,e);
	getline(cin,f);
	getline(cin,g);
	getline(cin,h);
	getline(cin,s6);
//	读入
	int w=0;
	system("cls");
	printf("正在读入       (%d%)",w);
	Sleep(100);
	system("cls");
	w+=16;
	printf("正在读入.      (%d%)",w);
	Sleep(1000);
	system("cls");
	w+=16;
	printf("正在读入..     (%d%)",w);
	Sleep(1000);
	system("cls");
	w+=17;
	printf("正在读入...    (%d%)",w);
	Sleep(900);
	system("cls");
	w+=17;
	printf("正在读入....   (%d%)",w);
	Sleep(900);
	system("cls");
	w+=17;
	printf("正在读入.....  (%d%)"),w;
	Sleep(900);
	system("cls");
	w+=17;
	printf("正在读入...... (%d%)"),w;
	Sleep(1000);
	system("cls");
//	做个样子
	all_len=a.size();
	int y=0;
//	从这里开始，8个for循环阅卷
//		如果是对的：dui++，dc[i]='A'
//		否则：cuo++，dc[i]='A'

//	跳过可跳至第429行
	for(int i=1; i<=all_len; i++) {
		if(a[i]=='.') {
			if(a[i+2]=='-') {
				if(da[++x]=='A') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(a[i+8]=='-') {
				if(da[++x]=='B') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(a[i+14]=='-') {
				if(da[++x]=='C') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(a[i+20]=='-') {
				if(da[++x]=='D') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			}
		}
	}
	for(int i=1; i<=all_len; i++) {
		if(b[i]=='.') {
			if(b[i+2]=='-') {
				if(da[++x]=='A') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(b[i+8]=='-') {
				if(da[++x]=='B') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(b[i+14]=='-') {
				if(da[++x]=='C') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(b[i+20]=='-') {
				if(da[++x]=='D') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			}
		}
	}
	for(int i=1; i<=all_len; i++) {
		if(c[i]=='.') {
			if(c[i+2]=='-') {
				if(da[++x]=='A') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(c[i+8]=='-') {
				if(da[++x]=='B') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(c[i+14]=='-') {
				if(da[++x]=='C') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(c[i+20]=='-') {
				if(da[++x]=='D') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			}
		}
	}
	for(int i=1; i<=all_len; i++) {
		if(d[i]=='.') {
			if(d[i+2]=='-') {
				if(da[++x]=='A') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(d[i+8]=='-') {
				if(da[++x]=='B') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(d[i+14]=='-') {
				if(da[++x]=='C') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(d[i+20]=='-') {
				if(da[++x]=='D') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			}
		}
	}
	for(int i=1; i<=all_len; i++) {
		if(e[i]=='.') {
			if(e[i+2]=='-') {
				if(da[++x]=='A') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(e[i+8]=='-') {
				if(da[++x]=='B') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(e[i+14]=='-') {
				if(da[++x]=='C') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(e[i+20]=='-') {
				if(da[++x]=='D') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			}
		}
	}
	for(int i=1; i<=all_len; i++) {
		if(f[i]=='.') {
			if(f[i+2]=='-') {
				if(da[++x]=='A') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(f[i+8]=='-') {
				if(da[++x]=='B') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(f[i+14]=='-') {
				if(da[++x]=='C') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(f[i+20]=='-') {
				if(da[++x]=='D') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			}
		}
	}
	for(int i=1; i<=all_len; i++) {
		if(g[i]=='.') {
			if(g[i+2]=='-') {
				if(da[++x]=='A') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(g[i+8]=='-') {
				if(da[++x]=='B') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(g[i+14]=='-') {
				if(da[++x]=='C') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(g[i+20]=='-') {
				if(da[++x]=='D') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			}
		}
	}
	for(int i=1; i<=all_len; i++) {
		if(h[i]=='.') {
			if(h[i+2]=='-') {
				if(da[++x]=='A') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(h[i+8]=='-') {
				if(da[++x]=='B') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(h[i+14]=='-') {
				if(da[++x]=='C') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			} else if(h[i+20]=='-') {
				if(da[++x]=='D') {
					fen+=fs[x];
					dui++;
					dc[++y]='A';
				} else {
					cuo++;
					dc[++y]='W';
				}
			}
		}
	}
	if(dui==0)
		cuo==32;
//	特判， 可省略
	int q=0,e=0;
	while(q<5) {
		q++;
		printf("阅卷中       (%d%)",e);
		Sleep(500);
		system("cls");
		e+=3;
		printf("阅卷中.      (%d%)",e);
		Sleep(500);
		system("cls");
		e+=4;
		printf("阅卷中..     (%d%)",e);
		Sleep(500);
		system("cls");
		e+=3;
		printf("阅卷中...    (%d%)",e);
		Sleep(500);
		system("cls");
		e+=4;
		printf("阅卷中....   (%d%)",e);
		Sleep(500);
		system("cls");
		e+=3;
		printf("阅卷中.....  (%d%)",e);
		Sleep(500);
		system("cls");
		e+=3;
		printf("阅卷中...... (%d%)",e);
		Sleep(500);
		system("cls");
	}
//	同上，做个样子
	printf("----------分数 = %d----------\n       对了%d题 错了%d题\n\n----------答题情况:----------\n",fen,dui,cuo);
//	输出成绩和对错题数
	for(int i=1; i<=32; i++) {
		if(dc[i]=='A')
			printf("第 %-2d 题：       正确\n正确答案：   %c\n\n",i,da[i]);
		else
			printf("第 %-2d 题：       错误\n正确答案：   %c\n\n",i,da[i]);
	}
//	遍历dc数组，等于'A'则输出 "正确"  ,否则输出 "错误"
	return 0;
}