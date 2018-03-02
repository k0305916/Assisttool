// RouteTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

//大量的路段数据
struct Emroadseq
{
	std::string FID;
	std::string Name;
	double lng_s = 0.0;
	double lat_s = 0.0;
	double lng_e = 0.0;
	double lat_e = 0.0;
	double road_direc = 0.0;
	std::list<std::string> adjacency;
};

struct MyPoint
{
	double x = 0.0;
	double y = 0.0;
};

std::map<std::string, Emroadseq> m_emroadSeq;

double CalcDis(MyPoint p1, MyPoint p2)
{
	double result = 0.0;
	auto x = p1.x - p2.x;
	auto y = p1.y - p2.y;
	return sqrt(x * x + y * y);
}

double CalcDis(std::string road)
{
	MyPoint p1, p2;
	p1.x = m_emroadSeq[road].lng_s;
	p1.y = m_emroadSeq[road].lat_s;
	p2.x = m_emroadSeq[road].lng_e;
	p2.y = m_emroadSeq[road].lat_e;
	return CalcDis(p1, p2);
}

void findPaths(Emroadseq source, Emroadseq target,
	std::list<std::string> route, double length,
	std::list<std::list<std::string>>& match,
	std::list<double>& matchlength)
{
	length += CalcDis(source.FID);
	if (length >= 2000)
		return;

	route.push_back(source.FID);
	if (source.FID.compare(target.FID) == 0)
	{
		match.push_back(route);
		matchlength.push_back(length);
		return;
	}

	for (auto road : source.adjacency)
	{
		//跳过已经存在与route中的road，以免无限循环
		auto iter = std::find_if(route.begin(), route.end(), [road](std::string item) {
			if (item.compare(road) == 0) return true; return false;
		});
		if (iter != route.end())
			continue;
		
		auto roaditer = m_emroadSeq.find(road);
		if (roaditer == m_emroadSeq.end())
			continue;
		findPaths(m_emroadSeq[road], target, route, length, match, matchlength);
	}
}

std::list<std::list<std::string>> findPaths(Emroadseq from, Emroadseq to,
	std::list<double>& matchlength)
{
	std::list<std::list<std::string>> matchroadlist;
	std::list<std::string> route;
	double length = 0.0;
	findPaths(from, to, route, length, matchroadlist, matchlength);
	return std::move(matchroadlist);
}

std::list<std::string> findpath(Emroadseq from, Emroadseq to,
	double& minlength)
{
	std::list<double> matchlength;
	auto pathlist = findPaths(from, to, matchlength);
	if (pathlist.size() <= 0)
	{
		std::list<std::string> result;
		return std::move(result);
	}

	auto pathiter = pathlist.begin();
	auto iter = std::max_element(matchlength.begin(), matchlength.end(), [&pathiter](auto item1, auto item2) {
		if (item1 < item2) return false;
		else {
			pathiter++;
			return true;
		}
	});
	minlength = *iter;
	return *pathiter;
}

void init()
{
	Emroadseq road;
	road.FID = "0";
	road.lng_s = 113.8941118;
	road.lat_s = 22.55353053;
	road.lng_e = 113.8901444;
	road.lat_e = 22.55020577;
	std::string path[] = { "675", "676", "680", "40756", "40757" };
	std::list<std::string> roadlist;
	std::for_each(std::begin(path), std::end(path), [&roadlist](auto road) {
		roadlist.push_back(road);
	});
	road.adjacency = roadlist;
	m_emroadSeq[road.FID] = road;

	road.FID = "675";
	road.lng_s = 113.8901444;
	road.lat_s = 22.55020577;
	road.lng_e = 113.8880294;
	road.lat_e = 22.55225371;
	std::string path1[] = { "0", "66", "71", "676", "680", "16746" };
	roadlist.clear();
	std::for_each(std::begin(path1), std::end(path1), [&roadlist](auto road) {
		roadlist.push_back(road);
	});
	road.adjacency = roadlist;
	m_emroadSeq[road.FID] = road;

	road.FID = "676";
	road.lng_s = 113.8902133;
	road.lat_s = 22.5501397;
	road.lng_e = 113.8901444;
	road.lat_e = 22.55020577;
	std::string path2[] = { "0", "675", "71", "680", "57847" };
	roadlist.clear();
	std::for_each(std::begin(path2), std::end(path2), [&roadlist](auto road) {
		roadlist.push_back(road);
	});
	road.adjacency = roadlist;
	m_emroadSeq[road.FID] = road;

//to
	road.FID = "71";
	road.lng_s = 113.8880294;
	road.lat_s = 22.55225371;
	road.lng_e = 113.8879485;
	road.lat_e = 22.55233178;
	std::string path3[] = { "66", "72", "675", "16746", "23773", "23921" };
	roadlist.clear();
	std::for_each(std::begin(path3), std::end(path3), [&roadlist](auto road) {
		roadlist.push_back(road);
	});
	road.adjacency = roadlist;
	m_emroadSeq[road.FID] = road;

	road.FID = "78";
	road.lng_s = 113.880745;
	road.lat_s = 22.59039024;
	road.lng_e = 113.880811;
	road.lat_e = 22.5903243;
	std::string path4[] = { "59480", "59481", "59484", "59485", "61739", "61741" };
	roadlist.clear();
	std::for_each(std::begin(path4), std::end(path4), [&roadlist](auto road) {
		roadlist.push_back(road);
	});
	road.adjacency = roadlist;
	m_emroadSeq[road.FID] = road;
}


int main()
{
	init();

	Emroadseq from, to1,to2;
	from.FID = "0";
	from.lng_s = 113.8941118;
	from.lat_s = 22.55353053;
	from.lng_e = 113.8901444;
	from.lat_e = 22.55020577;
	std::string path[] = { "675", "676", "680", "40756", "40757" };
	std::list<std::string> roadlist;
	std::for_each(std::begin(path), std::end(path), [&roadlist](auto road) {
		roadlist.push_back(road);
	});
	from.adjacency = roadlist;

	//to
	to1.FID = "71";
	to1.lng_s = 113.8880294;
	to1.lat_s = 22.55225371;
	to1.lng_e = 113.8879485;
	to1.lat_e = 22.55233178;
	std::string path3[] = { "66", "72", "675", "16746", "23773", "23921" };
	roadlist.clear();
	std::for_each(std::begin(path3), std::end(path3), [&roadlist](auto road) {
		roadlist.push_back(road);
	});
	to1.adjacency = roadlist;

	to2.FID = "78";
	to2.lng_s = 113.880745;
	to2.lat_s = 22.59039024;
	to2.lng_e = 113.880811;
	to2.lat_e = 22.5903243;
	std::string path4[] = { "59480", "59481", "59484", "59485", "61739", "61741" };
	roadlist.clear();
	std::for_each(std::begin(path), std::end(path), [&roadlist](auto road) {
		roadlist.push_back(road);
	});
	to2.adjacency = roadlist;

//test
	double routelength = 0.0;
	auto result = findpath(from, to1, routelength);
	return 0;
}

