#pragma once
#include "ObjectBase.h"

// �ȼ� ������ ����
#define UP 1
#define DOWN 2
#define ONFLOOR 3

enum class Block;

class Map;

class TestScene;

// �÷��̾� Ŭ����
class Player : public ObjectBase
{
private:
	Sound* _sndJump;		// ������ �� ȿ����
	Sound* _sndSpringJump;	// ������ ������ �� ȿ����
	Sound* _sndLand;		// ���� ȿ����
	Sound* _sndDie;			// ���� ȿ����


	// Con/destructor
public:
	Player();
	~Player();

public:
	void PlayerAutoMove();				// �÷��̾� �ڵ� ������ �Լ�

	void PlayerGravity();				// �÷��̾� �߷� �Լ�

	void ChangeDirection();				// �¿� ���� ��ȯ �Լ�

	void PlayerJump();					// �÷��̾� ���� �Լ�

	void SpringJump();					// ������ ���� 

	void PlayerCheckWall(Map* Curboard);	// �� ���� �Լ�

	void PlayerCheckFloor(Map* Curboard);	// �ٴ� ���� �Լ�

	void PlayerCheckEmptyFloor(Map* Curboard);	// ���� ���� �Լ�

	void PlayerCheckUpTile(Map* Curboard);		// ������ �� ���� �Լ�

	void PlayerCheckSpring(Map* Curboard);		// ������ �Լ�

	void ConfinePlayerinMap();					// �ʿ� ĳ���� ���δ� �Լ� 

	void PlayerCheckKey(Map* Curboard);			// Ű�� ���ϰ� �ִ°�

	void PlayerCheckDoor(Map* Curboard);		// �� ���� �Լ�

	void PlayerCheckRoof(Map* Curboard);		// ���� ���� �Լ�

	void GetMapInfo(Map* Curboard);				// �� �ҷ����� �Լ�

	//void PlayerCheckFail(Map* Curboard);		// ���� �۾�

public:

	Map* m_pCurBoard;

	bool IsPlayerGotKey = FALSE;	// �÷��̾ Ű�� ��������

	int playerState = ONFLOOR;

	//bool Up;

	//bool OnFloor;

	float JumpPower = 0.0f;

	float MaxJumpPower = -38.f;

	float SpringJumpPower = -60.0f;

	int m_Speed = 8;	// �÷��̾� �ӵ�

	int xdir = 1;		// ���� ��ȯ�� ����

	float gravity = 2.0f;

	//bool _isDead;			// True -> Die / False -> Life
};