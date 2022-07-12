#include "pch.h"
#include "AABB.h"
#include "Player.h"

// 2���� �������浹 �簢���� �޾Ƽ� �浹 ���� üũ
bool CheckCollision_AABB(RECT source, RECT target)
{
	if (source.left < target.right &&
		target.left < source.right)
	{
		if (source.top < target.bottom &&
			target.top < source.bottom)
		{
			return true;
		}
	}

	return false;
}

bool CheckCollision_AABB_X(RECT source, RECT target)
{
	if (source.left <= target.right &&
		target.left <= source.right)
	{
		//if (source.left < target.right)
		//{
		//	source.left = target.right;
		//	return true;
		//}
		//else if (target.left < source.right)
		//{
		//	source.right = target.left;
		//	return true;
		//}
		return true;
	}

	return false;
}

bool CheckCollision_AABB_Y(RECT source, RECT target)
{
	if (source.top <= target.bottom &&
		target.top <= source.bottom)
	{
		//if (source.top < target.bottom)
		//{
		//	source.top = target.bottom;
		//	return true;
		//}
		//else if (target.top < source.bottom)
		//{
		//	source.bottom = target.top;
		//	return true;
		//}
		return true;
	}

	return false;
}

// 
bool Check_Same_Y_axis(RECT source, RECT target)
{
	if (source.left == target.left &&
		source.right == target.right)
	{
		return true;
	}

	return false;
}