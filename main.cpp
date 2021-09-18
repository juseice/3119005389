#include<cstdio>
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>

using std::string;
using std::vector;
vector<string> refer;	//record the id of each charater
vector<string> all;

std::vector<std::string> textSegmentation(std::string s)
{
	vector<string> res;
	/*
	for (auto it : s)
	{
		res.push_back(string(1,it));	//unigram
	}
	*/
	int n(s.size());
	for (int i = 0; i < n - 1; ++i)
	{
		res.push_back(s.substr(i, 2));	//bigram
	}
	return res;
}

std::vector<int> vecConstruct(std::vector<std::string> vec)
{
	vector<int> res;
	res.resize(refer.size(), 0);
	for (auto it : vec)
	{
		int id(std::lower_bound(refer.begin(), refer.end(), it) - refer.begin());	//get the position of 1 of this charater
		++res[id];
	}
	return res;
}

double calcDistance(std::vector<int> vec1,std::vector<int> vec2)	//Euler distance
{
	double res(0.0);
	int n(vec1.size());
	for (int i = 0; i < n; ++i)
	{
		res += (long double(vec1[i]) - vec2[i]) * (long double(vec1[i]) - vec2[i]);
	}
	res = sqrt(res);
	return res;
}

int main(int argc, char** argv)
{
	char buff[1024];
	if (argc < 4)
	{
		puts("Not Enough Arguments!");
		return 0;
	}
	else if (argc > 4)
	{
		puts("Too many Arguments!");
		return 0;
	}
	std::ifstream fori(argv[1]);
	if (!fori.is_open())
	{
		printf("%s is not exist or cannot open!",argv[1]);
		return 0;
	}
	std::ifstream fdis(argv[2]);
	if (!fdis.is_open())
	{
		printf("%s is not exist or cannot open!", argv[2]);
		return 0;
	}
	std::ofstream fout(argv[3]);
	string ori, dis;
	while (fori.getline(buff, 1024))
	{
		ori += buff;
	}
	while (fdis.getline(buff, 1024))
	{
		dis += buff;
	}
	/*	test if i/o works properly
	fout << ori + dis;
	std::cout << ori + dis;
	*/
//	string ori("Hello."), dis("Greeting.");
	auto vsori(textSegmentation(ori)), vsdis(textSegmentation(dis));

	for (auto it : vsori) refer.push_back(it), all.push_back(it);
	for (auto it : vsdis) refer.push_back(it), all.push_back(it);			//join two set
	std::sort(refer.begin(), refer.end());
	refer.erase(std::unique(refer.begin(), refer.end()), refer.end());		//Discretization
	auto vecAll(vecConstruct(all));
	double overall(calcDistance(vecAll, vector<int>(refer.size(), 0)));

	auto vecori(vecConstruct(vsori)), vecdis(vecConstruct(vsdis));

	double ori_0(calcDistance(vecori,vector<int> (refer.size(),0))), ori_dis(calcDistance(vecori,vecdis));
	double ans(1.0 - ori_dis / ori_0);
	fout.precision(0.01);
	fout << "Text similarity: \n";
	fout << std::fixed << std::setprecision(2);
	fout << "\t" << ans * 100.00 << "%";
	fori.close();
	fdis.close();
	fout.close();
	//std::cout << "Text similarity: \n";
	//std::cout << "\t" << ans * 100.00 << "%";
	return 0;
}
