#ifndef __DATASTRUCT__H_106A8FA3_F78F_4257_AC81_69AF2F5A6F9A
#define __DATASTRUCT__H_106A8FA3_F78F_4257_AC81_69AF2F5A6F9A
#pragma once
#include "../../pch.h"
namespace DataStruct
{
	//物品数据结构
	struct data_Item
	{
		/*
		[物品对象+90]+C 物品名称
		[物品对象+88]+4 物品名称
		[物品对象+80]+4 物品名称
		[物品对象+2b0]+4 物品名称\物品类型
		[物品对象+c]   物品id Dword
		[物品对象+18] 当前物品容量值 Dword
		[物品对象+1c] 当前物品最大容量值 Dword

		*/

		wchar_t Name[40];//第一个名字
		wchar_t Name1[40];//第二个名字
		wchar_t Name2[40];//第三个名字
		wchar_t Name3[40];//第四个名字
		wchar_t typeName[40];//物品类型
		DWORD id;//物品id
		DWORD cic;//当前物品容量
		DWORD cmic;//当前物品最大容量
		UINT index;//当前物品的下标

	};
	//本人玩家的角色属性信息
	struct data_OCInfo
	{
		wchar_t* 本人名称;
		DWORD id;
		QWORD 当前血量;
		QWORD 最大血量;
		QWORD 当前蓝量;
		QWORD 最大蓝量;
		float x坐标;
		float y坐标;
	};
    //本人玩家的技能属性信息
	struct data_Skills
	{
		PTCHAR skillsName;//技能名称
		DWORD id;//技能id
		DWORD cooldownTimer;//当前冷却值
		DWORD maximumCooldown;//最大冷却值
		BYTE  cooldownFlag;//冷却标志
	};
	//坐标
	struct data_Coordinates
	{
		float x;
		float z;
		float y;
	};
	//Npc对象的属性信息
	struct data_Npc
	{
		PTCHAR Name;//npc的名称
		DWORD id;//npc的id  
		PTCHAR nType; //npc的类型
		DWORD hp;//npc血量
		DWORD maxHp; //npc最大血量
		data_Coordinates coordinates;//npc的坐标
		float horizontalDistance;//水平距离
		float verticalDistance;//高度距离
	};
}

#endif





