#include<bits/stdc++.h>

using namespace std;
string s;
string ans;
typedef unsigned long long ull;
const ull N = 9099099909999099999ULL;
void f0() {
	cout << "ONTAK 2010\n";
}

void f1()
{
	string S = "Godzilla terrorizes Bajtoly lower again. Every day a monster comes out of the ocean, slow movement of marching through the city to some of the skyscrapers and eats it with people who are in it. Eating one skyscraper takes the whole day, at dusk, it returns to its hiding place hidden in the depths. To make matters worse, going through the city, Godzilla wags its tail and destroys towers, near the passes. The prospect of becoming a meal for an underwater monster, to discourage some residents spent in uncomfort- tion in the city. During the night of each tower is derived as a resident and flees to the countryside. In Bajtogrodzie skyscrapers were built only at street crossings. At each intersection there is exactly one building. Junctions are connected by two-way streets. In addition, a the junction is just above the ocean, this is where Godzilla begins its destructive journey through the city. During the investigation, the monster moves only in the streets. Godzilla noted that he must hurry up with the consumption of residents and carefully choose the skyscrapers devouring and streets, which reaches them. Of course, choosing never previously consumed or destroyed- wanego skyscraper. What is the maximum number of people who can eat before the city completely desolate? Entrance The first line of standard input contains two integers him (1 n 100 000, 0 500 000 m) respectively denoting the number of intersections in the city and the number of connecting streets. Crossroads numbers are numbered from 1 to n, junction 1 is located on the shores of the ocean. Next row contains a sequence of integers n s (0 s 100 000) to describe population skyscrapers at various intersections. In each of the next m rows are the two integers ai and bi (1 ai, bi n, ai = bi), which means that there is a road junction connecting ai and bi. The crossing number One can reach any other intersection in the city. Exit Write to stdout the number of people who eat Godzilla for the optimum choice of meals and roads through the city every day. Example For input: the result is correct: 5 5 11 1 3 2 4 7 1 2 1 3 2 3 2 4 3 5";
	int cnt = 2932;
	vector<char> ans;
	for (int i = 0; i < S.length(); i++)
	{
		cout << string(cnt, S[i]);
		cnt -= (2 * i + 1) % 2932;
		if (cnt <= 0) cnt += 2932;
	}
	cout << "\n";
}

void f2()
{
	ull x1 = 1, x2 = 1;
	cout << "1, 1, ";
	for (int i = 0; i < 9998; i++)
	{
		ull x3 = (x1 + x2) % N;
		cout << x3 << ", ";
		x1 = x2;
		x2 = x3;
	}
	cout << "0.\n";
}

void f3()
{
	vector<string> s3;
	s3.push_back("#");
	string p[5] = {
		".####..##..##.######..##...##..##.....####...####..###..####.",
		"##..##.###.##...##...####..##.##.....##..##.##..##..##.##..##",
		"##..##.##.###...##..##..##.####.........##..##..##..##.##..##",
		"##..##.##..##...##..######.##.##......##....##..##..##.##..##",
		".####..##..##...##..##..##.##..##....######..####...##..####.",
	};

	for (int i = 1; i < 1024; i *= 2)
	{
		for (int j = 0; j < i; j++)
		{
			string now(s3[j]);
			s3.push_back(s3[j]);
			s3[j] = s3[j] + string(j, '.') + s3[j];
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < p[i].length(); j++)
		{
			s3[506 + i][449 + j] = p[i][j];
		}
	}
	for (int i = 0; i < 1024; i++)
	{
		cout << s3[i] << "\n";
	}
}

void f4()
{
	vector<int> p(400005);
	for (int i = 2; i < 400002; i++)
	{
		if (p[i] == 1)continue;
		for (int j = i * 2; j < 400002; j += i)
		{
			p[j] = 1;
		}
	}
	int f[20] = { 9,0,9,9,0,9,9,9,0,9,9,9,9,0,9,9,9,9,9 };
	for (int i = 2; i < 400002; i++)
	{
		if (i >= 266650 && i < 266669) p[i] = f[i - 266650];
		cout << p[i];
		if (i % 80 == 1) cout << '\n';
	}
}

string pol_num(int x)
{
	string pol[20] = { "", "pierwszy", "drugi", "trzeci", "czwarty", "piaty", "szosty", "siodmy", "osmy", "dziewiaty", "dziesiaty", "jedenasty", "dwunasty", "trzynasty", "czternasty", "pietnasty", "szesnasty", "siedemnasty", "osiemnasty", "dziewietnasty" };
	string pol10[10] = { "", "", "dwudziesty", "trzydziesty", "czterdziesty", "piecdziesiaty", "szescdziesiaty", "siedemdziesiaty", "osiemdziesiaty", "dziewiecdziesiaty" };
	string pol100ex[4] = { "","setny","dwusetny","trzysetny" };
	string pol100[4] = { "","sto","dwiescie","trzysta" };
	if (x < 20) return pol[x];
	if (x < 100)
	{
		if (x % 10 == 0) return pol10[x / 10];
		return pol10[x / 10] + " " + pol[x % 10];
	}
	if (x % 100 == 0) return pol100ex[x / 100];
	return pol100[x / 100] + " " + pol_num(x % 100);
}
void f5()
{
	string pol_month[13] = { "","stycznia","lutego","marca","kwietnia","maja","czerwca","lipca","sierpnia","wrzesnia","pazdziernika","listopada","grudnia" };
	string pol_year[21] = { "dwutysiecznego","tysiace pierwszego","tysiace drugiego","tysiace trzeciego","tysiace czwartego","tysiace piatego","tysiace szostego","tysiace siodmego","tysiace osmego","tysiace dziewiatego","tysiace dziesiatego","tysiace jedenastego","tysiace dwunastego","tysiace trzynastego","tysiace czternastego","tysiace pietnastego","tysiace szesnastego","tysiace siedemnastego","tysiace osiemnastego","tysiace dziewietnastego","tysiace dwudziestego" };

	int year = 2000, month = 1, day = 1, cnt = 1;
	int M[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	while (true)
	{
		string s;
		if (year == 2007 && month == 4 && day == 1)
		{
			cout << "Pierwszego kwietnia jest prima aprilis.\n";
		}
		else if (year == 2013 && month == 6 && day == 1)
		{
			cout << "Pierwszego czerwca jest dzien dziecka.\n";
		}
		else
		{
			string now = pol_num(day) + " " + pol_month[month] + " to " + pol_num(cnt) + " dzien roku " + (year == 2000 ? "" : "dwa ") + pol_year[year - 2000] + ".\n";
			now[0] -= 32;
			cout << now;
		}
		day++;
		cnt++;
		int monthday = M[month];
		if (month == 2 && year % 4 == 0) monthday++;
		if (day > monthday)
		{
			day = 1;
			month++;
			if (month > 12)
			{
				month = 1;
				cnt = 1;
				year++;
				if (year == 2021)
					break;
			}
		}
	}
	cout << "Koniec.\n";
}

void f6()
{
	ull fac[21] = { 1LL };
	for (int i = 1; i <= 20; i++) fac[i] = fac[i - 1] * i;

	for (int i = 1; i <= 20000; i++)
	{
		ull n = (ull)i * i * i * i;
		cout << "T[" << n << "]=\"";

		if (i != 10000)
		{
			int l;
			vector<char> c;
			for (l = 1; fac[l] < n; l++) n -= fac[l];
			for (int j = 0; j < l; j++) c.push_back(char('a' + j));
			for (int j = 0; j < l; j++)
			{
				int x = 1;
				for (; fac[l - j - 1] < n; x++) n -= fac[l - j - 1];
				cout << c[x - 1];
				c.erase(c.begin() + x - 1);
			}
		}
		else cout << N;

		cout << "\"\n";
	}
}

class Board
{
	vector<string> board;
	string d[7][5] = {
		{
			".####.",
			"##..##",
			"##..##",
			"##..##",
			".####.",
		},
		{
			"###",
			".##",
			".##",
			".##",
			".##",
		},
		{
			".####.",
			"##..##",
			"...##.",
			".##...",
			"######",
		},
		{
			"..",
			"..",
			"..",
			"##",
			".#",
		},
		{
			"..",
			"..",
			"..",
			"##",
			"##",
		},
		{
			"..",
			"..",
			"..",
			"..",
			"..",
		},
		{
			".####.",
			"##..##",
			".#####",
			"....##",
			".####.",
		},
	};

	int get_cidx(char c)
	{
		if (c >= '0' && c <= '2') return c - '0';
		if (c == ',') return 3;
		if (c == '.') return 4;
		if (c == ' ') return 5;
		return 6;
	}

public:
	Board()
	{
		board.push_back("");
		board.push_back("");
		board.push_back("");
		board.push_back("");
		board.push_back("");
	}
	void print(string s, bool newline = false)
	{
		int now_len = 0;
		for (int i = 0; i < s.length(); i++)
		{
			int c_idx = get_cidx(s[i]);
			now_len += d[c_idx][0].length() + 1;
		}
		if (now_len + board[board.size() - 1].length() > 1000)
		{
			board.push_back("");
			board.push_back("");
			board.push_back("");
			board.push_back("");
			board.push_back("");
			board.push_back("");
			if (newline)
				board.push_back("");
		}
		for (int i = 0; i < s.length(); i++)
		{
			int c_idx = get_cidx(s[i]);
			now_len += d[c_idx][0].length() + 1;
			for (int j = 0; j < 5; j++)
				board[board.size() - 5 + j] = board[board.size() - 5 + j] + d[c_idx][j] + ".";
		}
	}
	void out()
	{
		for (int i = 0; i < board.size(); i++)
		{
			string dots = "";
			dots.append(1000 - board[i].size(), '.');
			cout << board[i] + dots << "\n";
		}
	}
};
string twice(string n)
{
	int c = 0;
	string ret = "";
	for (int i = 0; i < n.length(); i++)
	{
		int num = c + (n[i] - '0') * 2;
		c = num / 3;
		num %= 3;
		ret.append(1, num + '0');
	}
	if (c != 0)
		ret.append(1, c + '0');
	return ret;
}
void f7() {
	Board board = Board();
	string t = "1";
	for (int i = 0; i < 171; i++)
	{
		board.print(t);
		board.print(", ");
		t = twice(t);
	}
	board.print("0.");
	string x[4] = {
		"01020102001020021020001020010200120000120001200102010200120120012001200102012001020102012001020102010102010201200120012012001220100200012002010201020102010200",
		"120012012001200120012001200120012001200120012012001201002000102001201200020020010020102001200001020102000120002010200102020000102001202002102001200202010201",
		"0201020010020201020201020200120010001200201200102012001200120102012002100002010200010200012022020012020102020102020102010909909990999909999902010200120012",
		"0012010201020102012001201201020120102012002001020012001200120012000120012001200210200120000120012001201200120102001001001001010100101000020102010200102001020001",
	};
	for (int i = 0; i < 4; i++)
		board.print(x[i], i == 0);
	board.out();
}

void f8()
{
	string X = R"(^K6I[6QJQJHc\JH[NHHa\NH]\ZHHFa\NHc\/INHFB]\NHH]\NJHHH66]\NNHB44[-IbJKH+HZH67IHE?4OKa/F?a5IKHa>HHHO0IH-HNJKc/OGN\\H0d\A?BcbHKHBZEHHOH4.[GZZZcPHO\G3BaNQHcGH3FB]ZF[HNb,IHH]H]Z3F-4OHKH66cJ3]\/IaJHHAFHcGaH]NZZAHZHcJcb5FFZN\NNcPJHc,46cb\JQJJHJ\5HHB[HBa\AFHHJJHHBIH6BH3aA4[c/IH-I-4FFa\ZHaP\346HHNHcb\H64aAHN\\Zc\ZH6HHH/444OJiG4O/.44HFHcG4OH]\3[5HHNHH0IHH6HFHZZN\NNH66ONHZN5FFBBa/I6O/.[34HHBc5[HHHFabGFZHJNZHHF4[HHHH34a5a/.I4[Z-IN3[5B6B4[HHHa5aAaGHHHHHHHa\JHHaGHH/4O/IH4[-IH-IZZ/a\\\NJHcbA4[\AaGFHHFHF4OJHB4aAFHHNJHH6[-IHHHHHHJ/[3[NNHH6BO\N/[\AFFB66B4[HH44[\\AFHHH664ONHHHFcGHHH-IJJJ-I6c54ONHJN34aAa5a/OHc5[N/[N\\5B66644.IHH6c566HFHHHJHHHHcb\/.IHHHH/O\\\/.Ic5[NJNZ-.[344aA4O/.IHcGa5]5abbG6HHHHFc5]\NHHcbGFHH/[ZZHH]\JJJHNHHJZZN/4[/[NNHHcb5]\\\\A466cGB666]\NHH6aA4BFFHHHHH6]\NJ-IHHHFHJHZZZZZZZHHHHBaA[/ON\344]56Ba544.IHB44O\\\\56cGB6B44..IHHHFHFcGHHH-I-I-IHHB6B44[-IN-.[3444a\/ONHHa\3[N/[N/44aAa5a\\NJNHHHB666666HFHHHHHHcGcb5]\NJHHHHHHJ/[/[NJHHc\\N/IJNZ-.[N/44[\\N/.IHHH6c5BaA4Ba5cGFHFcGB66a\/.IHHFaGF6HH-INHHHB4O/.IJHNHHZHNZZZN/[ZNZHJHHF6Ba\5[\\\A4Ba5666B]544[HHHBaA4aAabGBHH6Ha54O/.INHHHHH6HHJH-IN-IJ-IHHH6cbA44[N/[N/4444]5a\\\/[HHHa\\\\3O\\5a5BFa5B44[NJNHHHH6HBHFcGHHHHHHHJHH6H666]\/[NZHZHJN/[/4[\3[ZHHHB44[/[NN/[N/444444444[NN-IHH6HFBBBFFFFBcGHFHHBH6HFa5]\NJJHHHHHHHHNZZNZHHHHa\/OJ/IJN-IJNNN/[N\N\N/..I-IHBHFFa5]5aA4Ba566cGFBBBBa54O/IHHH666BB6HHHHHHHFBB44[JJJNHNHH-IH-IZHJJNNNNZHJHHHHB66]54444O\\\A4]5Ba5]5a\\/[HHHHaA4]\54B4666cGFFa544O/.INHHHHHHHcGHHH-IHZH-IH-IHBH6c5B4]3O/[ZNJ/O\3444444O\NNHHH6]\\\/4[/4O\A4aA4]5a\\3[NNZHHHHHcG6HF6HFHFHHHFHHHHHHFcbb5]5O\NN-I-IHJZZZN/[N/..IHHHa\\\/[N/..[ZN/[/O\/44[\N/[ZZH-IHBHB6cb56BFabbGFBcG6HBcGFBBaA4O\NZHHHHHBHHHHHHZHNHHH66a\\N/[Z-IJZHJZHJNNNJ/[ZNJJJJNHZHcGHFBBa5]54]A4]5]b5BBFab56]5a\/OJJHHH66BFa5666HBHcGHFBBa\\\3.[-IZHHNHHHH-IHZHZHJZHJZHZHHHHHBcbb5]A4O\\3O\\344]\5a\54]\\N/[HHHHa5]5444]\A4B4BBab5B4]A[\N/.IJHJHHHHFHHBHHHHB-IHHHHHNHH6HHBcbb5a\\/O/[ZZZZNN/O\3[\3O\NJJJHHHBa\5[\/O\N\3[\344444]\\\/O\ZNNZHHJHBHHF6HFB6cGBcG6HHFHHBHcGcGFBBaA44[/.IJHJHHHJHJZZZZZ-IJHNHc564]/O\NJ/....[ZZN/[N/O/O/O/.[Z-INHHHHcG6cb56BFa5Bab5666cGFFB6666BaA44O\ZZHHHHH6HFcGHHFHHHHHHHBBaA4[\NJ/IJN-IZHZHN-INZ-.IJJJJJN-IZHHHHH6HFFFa5a\54a\\54]AaAa5Ba5a5aA44O\NN-IHHBBFa5]5Bab566cGFB666B4]\\3[NNN-IZHHHHZHHHHHHHZHHNHZH-IH-IHHHFHBcb56aA444[\3[3[/4[\\\\\\\\\\3[J/INHHcb5B44]\\\\\\\\54]5]5aA4a\\3[/.[-INHHHHHHHBHHFHBHHBHHHHHHHcGHHHcGcGBBBaA444O/[NNNZZ-...[ZN/O/[NJJJJHHHHFa\54[\3[/[N/O/O/O\/44[\\3O\N\NNNN-IHZH6HH6HB6cGFFFBB6cGBcG6HBHFcGB6666B4]\\\N/.IZHHHHHHHZHHJ-INHJHHHHcb5]\\\/[N/.[-..IJJJNNJJ/[ZN/[ZNJJJJZHJHHHHHcG6cbb5Ba5Ba5a5Ba56BBFFabb56Ba5a\5O\N/.IHHHHHFB66cGBHFHBHH6H6cbb5]\\\/O/..IJNHJHJHZH-IHJ-IN-INZHJZHJHJHHHHHH6HFBBBa5a\54444444]\\54]5aA4a\5444[/[Z-IHHHBBa5B4B4]5]5Ba56BBFa5BaA4a/4O/[NNZHJHNHHHHHHHHHHHHHHHHHJHHHZHHHHHHcGHF6666B4]\\\/4[N\N/[3[3[/4[\/4[\3[N/.INHHHBB]5a\\\\\\34O\\\\\\544a\\\\\/O\NJJJJZH-IHHHcGH6H6H6HBHBH6HHBHH6HHHFHcG6HFBBBa5a\\\/OJ/.IJZHJZHJNNZZNNNNNNZHNHHH66Ba\5O\/O\N/[N/[ZN/[3[3[3[/O/O/[J/[Z-IJZHHHHHHHFcGB666666666666cbGFB6HFBB66666BaA4444[NJJNH-IHHHHHFHHHHHHHHHHHHHcb5B4a\3O\N/....IJNZ-IJZZ-.IJJJJJJJJJJNZHJHJHHHHH6H6cbbb56]5B4]5]5aAa5a5Ba5BFa5a5]5a\\\/O/..IHHHHHFBBBFFFFFFB6HFBcGFBBBa5]\5[\3[NJJJN-IZH-IHHJHHZHHZHHJHJHJHJHJH-IHHHHHHFHF6666B4B44]\\\344O\\\\\\\\54444]344[/[ZZHJHHHBBBa5a54]A4a\54]5]5]5BaA4]54444[/[NJJJNHJHZHHHHHHHBHHHH6HHHHHHHHHHHHHHHHFHHFcGBBBBa5a\\\\/O/[N/[ZNJ/[N/[3[3[N\N/.[ZHJHHHH66BaA4444O\/4[\3[\34[\\/4444[\\3[/[J/[Z-INHNHHHHHHBH6H6HF6HF6HF6HBHBHFHBHBHBcGBcbGab5B4]\P\\N/[ZZHJ-IHJHNHNHJZHJN-INHNHHHHBBBaA444O\3[N/[NN/..[ZNJ/[ZN/[N/[N/[ZNNJJNZHNHZHHHHBHcG6cGFFFFab5BBFab56BBBBBBBBBBBFa5Ba5a\\\\3[NJN-IHHHHHHFHFHBHH6HHHH6HHBcGFa5]5444[/O/.[ZZ-IJZ-IZHJZHJZHJN-IJNZ-IJN-INHNHH-IHBHH6HB6cb56BaAaA4a\54]A4]A4]5a5aAaA4]A4a\\/4[N/.INHHHHcGFab5BBa5BBabb566666BBa5B4]A4O\/O/[NNZZHJ-IHZHHH-IHHHHHJHHHZHHHJHHZHHHH-I6HHHcG6HFBBFa5aA4a\\/4O\/4[/4[\34O\\\/44O\/O\N/[ZHJHHHHcbb5]5a\5444]\\\\544]A4a\A44]\\\\3O\N/[ZZ-IJ-IHHJHHH6HHHcGHcGHHFHH6HHHHFHHHHFHH6HcG6cGFBFa5]5a\\\3O/[N/.........[ZNNJ/[ZNNNNN-IHHHHHFa5]54]\/4O\3[/O/O/O/O\3[/4[/4[/O\N\N/[ZNNNZHJHJHHHHHHcGHFcGBcGFB6cGFB6cGF6cGBcGB6HFB66666BB4B4]\\\3[J/..INHZHHHH-IHHHJH-IHZHHHHHHHcbb5B4]\\\3O/O/.[NNNNNNNNNNNNNJJJ/.[ZZNNNNNNNZHJ-IHNHHHHHBH6HB6cbbb56Ba5Ba5Ba5BBa5BFa56BFa5Ba5B4]54444O\NJJJNHHHHHHHBcGF6cGBcG6HBHBHF6cbbb5Ba\544O\3[NJ/..IJN-IZHNHNHNHNHNHNHJ-INHJ-IZHZH-IHH-IH6HHHFcGB666BF4BaA4a\\5444a\\\544]\54a\A444a/44O\N/[Z-IHHHHH6c56Ba5BaAa5a5]5Ba5Ba5Ba5B4]54]\\/4[/[NJJJJNZHZHHJHHHHHHZHHHHHHHHHHHHHHHHHZHHHHHFHHHBH6HFB666Ba5aA44444O\3[/O/[/[/[/O\3[/O\3[3[N/[NNZ-IHHHHcGabAaA4a\\\\\\\3444444444444444O\\/4[/[/.[ZZZ-INHZHHHHHHHHHFHcGHFHBHBH6H6HHFH6HHFH6HcGcG6HFB666BBa5a\544O\3[N/...IJNZ-IJZ-IJJNNZZ-IJNHJH-IHH6cbb5]5a\\\/4[/O\N/[N/[N/O/[N/[/[N\N/[/[N/.[ZNNZZHJZHHJHHHHHHFH6HBcGFB66cbbbbbbGFFFFBB66cbGFFFFFFab5BaAa\A44[\3[NNNZHJHHZHHHHHHHHHHHHHHHHHBHH6HFBBBa5a\\\\\3[N\ZNJJJJJJJNZ-.IJNZZ-IJJNNNZZ-.IJNZHJ-I-IHHJHHHFHHBHF6cbGab56Ba5a5]5]5]5]5B4BaAa5B4BaAaA4]544444O\N/[Z-I-IHHHcGBcbGFFFFFFBBB66cGFFBBBBFa5B4]\54[\/O/[NJJJJNZHJ-I-IHJH-IH-IHZHHNHHJHZH-IHZHH-IHHHHHHHHFH6HB6cbb56BaA4]544a\\\\344444O\\\\\\\\\\\\\34[/[N/..IJHHHHHcGFa56a5]5aA4aA4aA4aA4]5]5aA4a\544444[\3[N/.[Z-IJNHNH-IHHHHHHHHHHHH6HHHHHHHBHHHHHHHHHBHHH6HHFHF6HFFFFa5BaA44]\/4O\3[3[N/.[N/[ZN/[N/[N/[N/[ZNNNZ-IH-IHHF66BB4B4a\\\\\/4O\\3O\/4[\/4O\\34[\/4[/O\N\N/.[ZZZ-INHNHHNHHHH6HHHFHBHBHFcGBHF6HFcGBHFcG6HBHF6HF6cGFBBBFa5BaA4]\\\\3[3.[ZZZ-INHJHJHJHJHJ-IZHNHJHNHHHHHHHB66Ba5a\54O\\3[/[3[NJ/[NNJ/[ZNJ/[ZNJ/[NN/[ZNNJJJJJNZ-IZHZHHHHiGHHH6H6HB6cGFFBBBFFab56BBFabb566BBBFFab5BBa5Ba5aA44444O\3[NNNZHNHHHHHHHHcGHFH6HHBHHBHcGHFcGFBBBa5]54]\\3O\3[NJ/.[Z-.IJN-IJZHJZHJZ-IN-INZHJN-IN-IZHNHNHHNHHHHHH6HHBHF6cbbbb5Ba5B4B4]5a\5a\5a\5a\5aA4]A4]A4a\\544O\\3[N/..IJH-IHHcGB6cb566BFa56BFa56BBFab5BBa5B4B4a\\\\\/4[N/[NNNNNZHJ-I-IHNHHHJHHH-IHHHHNHHHHJHHHZHHHHHHHHHHHHH6HcG6HFBB6BBa5B4]544]\\/44O\\3O\/4[\34[\34[\/4[/O\N/[NJJJZHZHHHH6cbb5Ba5]54]A44a\\\5444]\\544]\\544444O\\3[/[N/[ZNZZ-INHNH-IHHHHHHHHHBHHHBHHcGHHFHH6HHHBHHcGHHFHcGcGcGB6cGFFFa5BaA4]\\\\\/O/O/[NNJ/....[ZZZZZNNNJJJJJJNN-IZHHHHHH6cbb5]5]A4444O\\3O\3[/O/O\N\3[/[/O\3[/[/O/[/[N/[ZNNNNZ-INHNHHJHHHHHcGHHFHFcG6HFBcGFB6cGFB6HFB6cGF6cGFB66cbbbbb5BF4BaA44]\/4O\N/[ZZ-IJ-IHJHHZHHHHNHHHNHHH-IHHHHHHBcGFFa5B4]A44O\\3[/[N/[NNJ/..[ZZZZZZZZZZZNNNNNNNNNNNNZ-IJN-IZH-IHH-IH6HHH6HcGBcGFBBBBBFa56Ba5BFa5Ba5Ba5BFa5Ba5Ba5BaAaA4]A44444[\N/[NNN-IHJHHHHH6HBHF6cGBcGBcGBcGBcGFB6666BBaAaA44444O\3[N/[NNNNNZ-IJZHJ-IZHNHNHNHJHJHJ-I-I-IZHZH-IHZHHHNHHHHHcGHHFHF6HFFBBFa5Ba5]5aA4a\A44a\\\5444]\\544a\\\\A4[\\\3O\N/[NNNZHNHHHHH6cGFFab5Ba5BaAa5]5BaAa5]5BaAa5aA4]A444444[\3[N/[NNNNNZHJZHZHHNHHHNHHHHHHHHHHHHHHHHHHZHHHHHHHHH6HHHHHFHcGcGBcGFFFFa5Ba5aA44a\\34O\/4[/[/O/O/O/O/O\N\N\N\N/[N/[ZZZ-INH-IHHHF6666BaAa\54]\\\\\\\\\\\/4444444O\\\\\34O\/O\3[N/[NJ/IJJNZHNHNHHNHHHHHHHFHHcGH6HHFHBH6H6HcGHFHBH6H6HcGcG6HBcGF66cbbb5BBaAaA44a\/4O\3[N/[ZNNZZZ-IJNZHJNZ-IJNZ-IN-INHNHHHHHHH6cbb5Ba54]\\\\\/4[/O\N/O/[N\N/[N/[N/[/[N/[N/[N/[ZNJ/....IJN-INHZHH-IHHHHFHH6HcG6HB6HFBB6cbbGFFFFFFBBBBB666666c56666BBa5Ba5]5aA44444[/O/[NNNNZHNHHJHHHHHHHHHHHHHHHHcGHHHFH6HF6666BB4B4a\\\\34[3[N\ZNJ/......IJJNNZ-.IJNZZ-IJNNZ-IJNZ-INZHNHJHJH-IHHHHHHHHFH6H6HFB6cbbb56Ba5Ba5BaAa5a5a5]5]5]5]5B4]5]5aA4]54a\\\\\3O\N/[NNNZHNHHHHHHHF6HFBB666cbbbbGFFFFFFBBFFab5Ba5]5a\5444[\/O/[/.[NNNNZ-IJZHJ-I-IHNH-IHNHHNHHJHHJH-IH-IH-IHHZHHHHHHHHHHH6HHBHBcGFB666BBa5B4]5a\54a\\\\\\\\\\/444444O\\\\\/44[\/O\3[N/[ZZZ-I-IHHHHHFB66BBa5Ba5aAa\5aA4]A4]A4]54]54]A44]\\\\\\\/4[/[/[NNJ/IJJNZHNHJHZHHH-IHHHHHHHHBHHHHHHHBHHHHHH6HHHHHcGHHcGHcGHBHFcGF66cb56Ba5BaA4a\\\\\/4[\N\N\N/[N/[ZN/[NJ/[N/[ZNJ/[ZZZZZ-IZH-IHHHHBcbbb5BaA4]54444444O\\/4O\/4[\/4[\3O\/4[\3O\3[/[/[N/[NJJ/.IJNZHJ-IHNHHHHHHHHHHcGH6HHFHFcG6HBcG6HF6HBcG6HF6HBcGB6HFB6cGFFFFFab5BaAaA44]\\\3O\3[NJ/...IJN-IZHNHNHNHNHNHNHNHZHHZHHHHHHHcGBBBBBaAa\544444[\3[)";

	vector<string> v;
	for (int i = 0; i < 1000; i++)
	{
		string x(1000, '.');
		v.push_back(x);
	}
	int dir[8][2] = { {0,1}, {1,1},{1,0},{1,-1}, {0,-1},{-1,-1}, {-1,0},{-1, 1} };
	v[500][500] = v[501][501] = '#';
	int x = 501, y = 501, idx = 0;
	for (int i = 0; i < X.length(); i++)
	{
		if (i % 1000 == 0)
		{
			x = x;
			y = y;
		}
		int P = X[i] - 32;
		for (int j = 0; j < 4; j++)
		{
			int d = P % 3 - 1;
			P /= 3;

			idx = (idx + d + 8) % 8;
			if (x == 502 && y == 502)idx++;
			if (x == 570 && y == 509)idx--;

			x += dir[idx][0];
			y += dir[idx][1];

			v[x][y] = '#';
		}
	}
	for (int i = 0; i < 1000; i++)
		cout << v[i] << "\n";


}

void f9()
{
	string X = R"x(]B @W7k!$ +G<5 eD)_2+TM^Weosi2\-Ql2P0;K 7?ShWU\q,3XOA/3=so23<sF33 \N93\+Rk Vunk 8TS7XuhCF3IK("!=(gDX@&SR3h+u.!;?3/! ]BMXG4jW3*L-Y3Y+_+Fgre^3.hO/FDC%ZX-MLk3b6WH!,>is3J;>)4F_7+43I\QF-sl[FQY@g!@!#/Yn\F>4A=>B45a=iF+nklFIkgG4#PRL4_'/[4^fDSYSj ^4 UA.GJiG.GmShTYhW/^45BP.G,_0^4OIQ.GfcS.G3NtTYDrU.G=I5^4-t UY"+X.GEk"UYjf].G7Q(UYJe3VYaO09"ml<VYHrr/GAIR_4qS#0G mDVY]_+0GV6a_4!g,0Gp=b_47N/0G<gPVYk\10GpuRVY)ng_45ZSVYIk30GN.UVY;Q90G@jZVY ]\9"preWY]2.?"p,/g4LWK_YQ(&;GHg4fYB"SJ",*%q4.0AT"I\OsYW&`V"e7`NGY\^\"S'&UG.P<15s\tXGonb_Gk6XbGT8#3Zp>ul"%FU4Z]oR>5BgVp"jV\F5N]i>Z?`KqGYHHrGBJiBZ[>('#3/J)#-Pg!H(]o'HU(-(Hte7(H<4>Y5(\i)Hh5<4#cZ?4#MS:+H*hD]5;1 a5\*7a5(++2H2!]3HpiB>#Wh_]Zk=/B#5l(<H2CoF#]VpG#9cfiZUM`GH#;SnZI$aHHV)h"6FQQS#Ir^U#C=&NH/[f [?GCSH&^5THY7Fc#@UY66N*_76@P+eHq3>gHc&T:[eX<u#_#ZmH/(CH6LbD#Ismr,$BAZJ[aZK/$`NR&IMq*0$l]*Y6]]C+I>qd5I's/\[_&W\[ =P@$6el=I3Q6BI[Tbu[1^DSI-Z]SIZTH.7;T UIjen.7p>EUIY@f%\<NU_$)3RVIR?%`$%/kVIY6`YI7;+*\0*<ZIUjE47q+F47:.M+\@Bq478Bl+\9a?e$`;)-\Qam\IH8+;7u5LcIArrgIN&6q$iZJq$c%hiI5Aqu$/b8nILO4*%R2sR79>..%3_K&Jkq9W7R&+N\'Rc'J"T>N\\&'(Jpj\W7'6\X7@aH2%"4]O\1H?)JHapO\frX)J"$nQ\)O39%pK70J#pP1JQnI2JFI_\\!7:c\13/e\3rDn7UK\o7U9Hf\k18@JT3Yf\)&AJ%fjXAJ&2nJ%%R?EJo3H 8QIUKJI-4MJ@KXMJNQBt\Ku((8"H?0842qb%r=c3]n(E4]0i2n% >tdJ!JT>8sjdo%p@RgJOH_A8sNM8]WLcB8jac9]=C^iJB\):]qt]:]Y is%hk_jJ-b"t%(omD8%,oD8^7oD8(R*E8ae4<]WPfL8`OSC]t$#(&diS)&)p(3&a_gQ]B#l4&R-F,Ku476&NaCS]/%H6&b6i7&FRD:&XQ!;&@sa2KajS<&Se;e82lm\]FA=A&D1>A&VQf@K%C!FK"pgP&aW)%9g?pU&b CNKB>gNK_MKOKHOlu]q0gOKZ22 ^_@#Z&RT+Z&li%+9 cPQKM*mQKV*uQKW13XKa'eYK hK*^ESCd&[BF.^omkh&g*Q?9ihr>^Mo+pK8\G&'a[9sKW6>M9utGM^En30L^;Q1L<J'2LY22f90o%@'!Y3g9*:C8L.r D'2lLo99too9 *+K'jNek^($5P'lU/#:B76q^Sa@T';7Zs^d!8 _b:"!_5\k]'sE'UL\GH%_o^4ULX`U%_ZS3&_4@T&_m[e_'@_j_'@H?4:#:p/_2R)0_Y( ;:/WTcLY6]m'XpE6_7t2hL4K#s'SfHE:a`9F:MNNmLlo5G:216G:CQ#"(,7WH:$DKB_u&jsL2YFtL/kR((&(E,([';J_h1=-( Ib$Mf<)V_"i]3M7!]=(6[E\_&g^7M;][8Mp5]E(m:DK(Z57l_PW.P(:n'!;-L)n_eAhGMNC3n_Yp`Q(C]*R(.DK";NAmHM7C8o_lgEo_SY[o_pYUR()(=S(t'7U(IV6MMYGbu_g?kX(0B6);sauPM3GhQME)QRM'XQRMpo/#`Hj?SMg4b#`q.RSM(:=](uoL$`Ou,TM.EU](`2)^(R`qTM7B>%`G3 UM;mfUMR[G/`&"T/`M\1m(P)s4`#D/5`\k.?;L@p5`P&$fM9(E6`IQa6`=dNfMak?p(il`p(FD+8`Mmqq(^r(9`qhVjMn?Gu(/W\ ).;E?`qOn?`KW= NepC.)Rru/)a/10)!i9P`;3?3)2N'Z;oY85)<](_`EcKb`rrJl;UE+F)cA\F)Y(\G)b%Ee`2aSAN[gDj`sILt;$$Lu;M<rKN`HZs`oRDNN@+K(<i.7u`7*rNNZj<u`GqS(<7F?u`]t#ON*_Du`#6$ONF Eu`1m\(<TW'ON-M^(<P7)ONck_(<S@Ku`bT-ON/?Nu`(l-ONKVNu` fc(<CP.ONd+k(<1l5ONH08ONkpXu`^m:ON+X[u`$/;ONV->ON#n^u`lj@ON9Uau`(2EONKreu`>5ku`a<hON,FYY)9<i a^jMPNc-o a3@0*<?,r a._UPN3"!!a&uXPNuK8*<"UZPNq+:*<8npY)O:<*<[&(!a3?_PNPV_PNkm_PN8X*!adD?*<To*!aY3gPNR`F*<opiPNt35!aMLlPN/XlPNE#L*<KolPN4q7!aP28!a'noPN,1;!a=UrPNBn=!aOr QNT5B!adBG!a)'<QNOqCQNHH#+</s;[)qrL[)YguRNC@B_)q96VNil"`)Y]%WN!J_WN=a_WNL;Ma)hPa(aV4la)&?[d)kn]e)e9%^NEA9A<RZ&t)PI;;a("AG<W'=BaOYKrNkRb&*c%`**QrJ$O4K0T<FBJ/*d.S(OEAI2*?bf*OT]iVauUY0O^W$Wa) C;*h+A>*<P-7O CK7OB/OA*lMIfaKKQM*4Mrs<G\*!=iiKGOo&UGOn>a!=eF`HOm/6oa[LX"=K!DoaB>$IOe(Eoa6n["=R/\"=;ZGS*==hpa0W2$=<CtpaGq4$=S] qai(VJOnA!qa'M@$=-ibJONWCU*pGXX*6ikOOo%C]*.#!1=RB-b**M-6=EFm:=>q`1btSQ<=II8m*PMo4bC7nm*/jisO,AZ(+]AUP=C5oHbLoS"P5qtHbD]i,+iBKJb6hcS=9F_3+"H*Z=\'%TbpRJ8+22l/Pq@4=+"L-d=d8=5PS0s[b_W>?+g[B@+B2O]bo;_A+"%K8P8F*h=[0K8PD2l^b=_K8P&al^bN--h=!dn^bSFN8P<Ho^b3eO8Prfp^b'?1h=Pur^becR8PNes^bcSS8P#u2h='[T8P=&4h=!+W8P`,"_bM39h= j$_b5XZ8PtY%_b3H[8PrI&_bdM;h=7.'_b-n]8PC9=h=?o>h=hO*_bb&`8P k?h=h?+_bIK+_bd/,_b#ta8Pbu,_b;kc8P$m._bsCd8P\E/_blE:j=4IhD+!Y^;Pl/Nk=$=#gbIVmI+Cs#APYC;K+8hHK+Rh`jbeZuDP3GIN+,sWN+#M>R++QBS+"1'qbdm,X+'Amo+MiQ8ci(6iP9s=iPujk9ca>!s+W\@;cE"H;c`]Wt+N;1u+tO3u+'kClPM_KlP'jr<cYK+=cPVq=cBA0I>ZMnoP]0[tPEd:p>hP[@Q*&LK,!^XhcNSiCQ!=TR,N<Z*?B+3TQspQ,dr R\Q9cB6?0g)^QohJ.d&m-^Qd\u8?r@eh,9 n3d`ZKq,.ZDB?_>4:dkeUs,:.:L?)(8Dd#u@0-$&*Nd:(o*R7U_5-rB1Yd0nV=- CB4Rso2?-'R08RT=\bdhh+G-cn2DRUMppdi"@U-=_dNRsFt!eS)e,@,Vr]-/#-%eLeh[RK%\-ep-%7@'AG]RK\W.e17#_R#s(_RbtI/eX$N/e+?H9@DjYi-A@j0e(2*1eBTOj-]8f1e[cd<@3+P:eGVut-i(R+.V*.-.K@^NeKX[Oe%Vi2SiQ,9S%5E:SXEa%A*6:bSET.gSP<,;/Da]aA#oB=/Z,M7Tql8&gnRF`/Com0BlOY'g<(>WT%*_'gtV>WT]X_'gs#?WT3Et0BulIWTJX8b/rbKc/;CV]geq;;URAk<U*m\HUU9Fk0/Y^5hagX?C@^-r0d)7r0:8gBC11H@h)L))1bhi-1Q[C11LY;-V\Rp2VofMAVKTg$D(B;Y12] ,i(=952tIE\DG*1Sid;o,W$]N\D[Z%92]R^92)x";
	vector<string> Z;
	int dir[4][2] = { {0,1},{1,0},{1,1},{1,-1} };
	for (int i = 0; i < 1003; i++)
	{
		string dots(1003, '.');
		Z.push_back(dots);
	}
	for (int i = 0; i < X.length(); i += 5)
	{
		long long z = 0;
		for (int j = 4; j >= 0; j--)
		{
			z *= 86LL;
			z += X[i + j] - 32LL;
		}
		int len = (int)(z % 1003), y = int(z / 1003) % 1003, x = int(z / 1003) / 1003 % 1003, d = int(z / 1003) / 1003 / 1003;
		for (int j = 0; j < len; j++)
		{
			Z[x + dir[d][0] * j][y + dir[d][1] * j] = '#';
		}
	}
	for (int i = 0; i < 1003; i++)
	{
		cout << Z[i] << "\n";
	}
}

vector<vector<int> > prod(vector<vector<int> >& x, vector<vector<int> >& y)
{
	int l = x.size();
	vector<vector<int> > ret(l);
	for (int i = 0; i < l; i++)
	{
		ret[i].resize(l);
		for (int j = 0; j < l; j++)
		{
			for (int k = 0; k < l; k++)
			{
				ret[i][j] = (ret[i][j] + x[i][k] * y[k][j]) % 2;
			}
		}
	}
	return ret;
}
void f10()
{
	cout << "a_i = a_{i-1} . a_{i-2}\n\n";
	string s[21];
	s[0] = "1";
	s[1] = "0";
	for (int i = 2; i <= 20; i++) s[i] = s[i - 1] + s[i - 2];
	for (int i = 1; i < 16; i++)
	{
		cout << "a_" << i << " =";
		int len = 5 + i / 10;
		for (int j = 0; j < s[i].length(); j++)
		{
			cout << " " << s[i][j];
			if (j % 40 == 39)
			{
				cout << " \n" << string(len, ' ');
			}
		}
		cout << "\n\n";
	}
	cout << "\n(A_i)^n = B_i (mod 2)\n\n";
	for (int i = 1; i <= 70; i++)
	{
		vector<vector<int>> A(i), P(i), B(i);
		for (int j = 0; j < i; j++)
		{
			A[j].resize(i);
			P[j].resize(i);
			B[j].resize(i);
			B[j][j] = 1;
			for (int k = 0; k < i; k++)
			{
				A[j][k] = P[j][k] = (int)(s[20][i * j + k] - '0');
			}
		}
		for (ull j = N; j; j /= 2)
		{
			if (j % 2 == 1) B = prod(B, P);
			P = prod(P, P);
		}
		string sp(5 + (i >= 10), ' ');
		for (int j = 0; j < i; j++)
		{
			if (j == i / 2)
			{
				cout << "A_" << i << " =";
			}
			else cout << sp;
			for (int k = 0; k < i; k++)
			{
				cout << " " << A[j][k];
			}

			cout << "   ";

			if (j == i / 2)
			{
				cout << "B_" << i << " =";
			}
			else cout << sp;
			for (int k = 0; k < i; k++)
			{
				cout << " " << B[j][k];
			}
			cout << "\n";
		}
		cout << "\n";
	}
}
int main() {
	int n;
	cin >> n;
	if (n == 0) f0();
	if (n == 1) f1();
	if (n == 2) f2();
	if (n == 3) f3();
	if (n == 4) f4();
	if (n == 5) f5();
	if (n == 6) f6();
	if (n == 7) f7();
	if (n == 8) f8();
	if (n == 9) f9();
	if (n == 10) f10();
	return 0;
}