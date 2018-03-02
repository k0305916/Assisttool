// RouteTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

std::map<std::string, Emroadseq> m_emroadSeq;

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

struct Emtrip
{
	std::string TripID;
	std::string VehicleID;
	long RecordID = 0;
	std::string RecordTime;
	double longitude = 0.0;
	double latitude = 0.0;
	short speed = 0;
	double direction = 0;
	int Type = -1;//相同路段的比值必须同时>一个阈值（）的情况下，同类。
};

struct MyPoint
{
	double x = 0.0;
	double y = 0.0;
};

double CalcDis(std::string road)
{
	MyPoint p1, p2;
	p1.x = m_emroadSeq[road].lng_s;
	p1.y = m_emroadSeq[road].lat_s;
	p2.x = m_emroadSeq[road].lng_e;
	p2.y = m_emroadSeq[road].lat_e;
	return CalcDis(p1, p2);
}

double CalcDis(MyPoint p1, MyPoint p2)
{
	double result = 0.0;
	return result;
}

std::list<std::list<std::string>> findPaths(Emroadseq from, Emroadseq to,
	std::list<double> matchlength)
{
	std::list<std::list<std::string>> matchroadlist;
	std::list<std::string> route;
	double length = 0.0;
	findPaths(from, to, route, length, matchroadlist, matchlength);
	return std::move(matchroadlist);
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
		findPaths(m_emroadSeq[road], target, route, length, match, matchlength);
	}
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
	m_emroadSeq[]
}


int main()
{
	return 0;
}

