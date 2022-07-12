#include "pch.h"
#include "Player.h"
#include "AABB.h"
//#include "TestScene.h"
#include "Map.h"

Player::Player()
{

	// ���� ����
	_sndJump		= SOUNDMANAGER->FindSound("JUMP");
	_sndSpringJump	= SOUNDMANAGER->FindSound("SPRINGJUMP");
	_sndLand		= SOUNDMANAGER->FindSound("LAND");
	_sndDie			= SOUNDMANAGER->FindSound("DIE");
}

Player::~Player()
{

}

// �÷��̾� �ڵ� ������ �Լ�
void Player::PlayerAutoMove()
{
	m_PosX += m_Speed * xdir;
}

// �÷��̾� �߷� �Լ�
void Player::PlayerGravity()
{
	if (JumpPower > 0)
	{
		playerState = DOWN;

		gravity = 2.0f;
	}
	else if (JumpPower < 0)
	{
		playerState = UP;

		gravity = 2.0f;
	}

	if (playerState == UP || playerState == DOWN)
	{
		JumpPower += gravity;

		m_PosY = m_PosY + JumpPower;
	}
}

// �¿� ���� ��ȯ �Լ�
void Player::ChangeDirection()
{
	xdir = xdir * -1;

	if (xdir == 1)
	{
		_img = IMAGEMANAGER->FindImage("PLAYER_MOVE_R");
		_img->SetCurFrameX(0);
	}

	if (xdir == -1)
	{
		_img = IMAGEMANAGER->FindImage("PLAYER_MOVE_L");
		_img->SetCurFrameX(0);
	}
}

// �÷��̾� ���� �Լ�
/// �м� �ʿ�
void Player::PlayerJump()
{
	playerState = UP;

	JumpPower = MaxJumpPower;

	// ��������Ʈ �̹��� ����	
	if (xdir == 1)
	{
		_img = IMAGEMANAGER->FindImage("PLAYER_JUMP_R");
		_img->SetCurFrameX(0);
	}
	
	if (xdir == -1)
	{
		_img = IMAGEMANAGER->FindImage("PLAYER_JUMP_L");
		_img->SetCurFrameX(0);
	}

	// ���� ���� ���
	_sndJump->soundSeek(0);
	cout << _sndJump->soundPlay();
	cout << "�븻 ����" << "\n";
}

void Player::SpringJump()
{
	playerState = UP;

	JumpPower = SpringJumpPower;

	//m_Speed = 4;

	// ��������Ʈ �̹��� ����
	if (xdir == 1)
	{
		_img = IMAGEMANAGER->FindImage("PLAYER_JUMP_R");
		_img->SetCurFrameX(0);
	}

	if (xdir == -1)
	{
		_img = IMAGEMANAGER->FindImage("PLAYER_JUMP_L");
		_img->SetCurFrameX(0);
	}

	// ���� ���� ���
	_sndSpringJump->soundSeek(0);
	cout << _sndSpringJump->soundPlay();
	cout << "������ ����" << "\n";
}



// �� ���� �Լ�
void Player::PlayerCheckWall(Map* Curboard)
{
	int GridX_3 = (int)(m_PosX + TILESIZE) / TILESIZE;
	int GridX_1 = (int)(m_PosX + TILESIZE - TILESIZE) / TILESIZE;

	int GridY_3 = (int)(m_PosY + TILESIZE + TILESIZE / 2) / TILESIZE;

	if ((Curboard->m_pGameBoard[GridY_3][GridX_3]->m_Type != Block::BLOCK_EMPTY &&
		Curboard->m_pGameBoard[GridY_3][GridX_3]->m_Type != Block::BLOCK_KEY &&
		Curboard->m_pGameBoard[GridY_3][GridX_3]->m_Type != Block::BLOCK_SPRING &&
		Curboard->m_pGameBoard[GridY_3][GridX_3]->m_Type != Block::BLOCK_DOOR_OPEN &&
		Curboard->m_pGameBoard[GridY_3][GridX_3]->m_Type != Block::CHAR_START_POS &&
		Curboard->m_pGameBoard[GridY_3][GridX_3]->m_Type != Block::BLOCK_EMPTY &&
		Curboard->m_pGameBoard[GridY_3][GridX_3]->m_Type != Block::BLOCK_WATER &&
		Curboard->m_pGameBoard[GridY_3][GridX_3]->m_Type != Block::BLOCK_UWATER &&

		xdir == 1) || (
			Curboard->m_pGameBoard[GridY_3][GridX_1]->m_Type != Block::BLOCK_EMPTY &&
			Curboard->m_pGameBoard[GridY_3][GridX_1]->m_Type != Block::BLOCK_KEY &&
			Curboard->m_pGameBoard[GridY_3][GridX_1]->m_Type != Block::BLOCK_SPRING &&
			Curboard->m_pGameBoard[GridY_3][GridX_1]->m_Type != Block::BLOCK_DOOR_OPEN &&
			Curboard->m_pGameBoard[GridY_3][GridX_1]->m_Type != Block::CHAR_START_POS &&
			Curboard->m_pGameBoard[GridY_3][GridX_1]->m_Type != Block::BLOCK_UWATER &&
			Curboard->m_pGameBoard[GridY_3][GridX_1]->m_Type != Block::BLOCK_WATER &&
			xdir == -1))
	{
		ChangeDirection();
	}
}

// �ٴ� ���� �Լ�
void Player::PlayerCheckFloor(Map* Curboard)
{
	int GridX_2 = (int)(m_PosX + (TILESIZE / 2)) / TILESIZE;
	int GridY_4 = (int)(m_PosY + 2 * TILESIZE + TILESIZE / 2) / TILESIZE;

	if (Curboard->m_pGameBoard[GridY_4][GridX_2]->m_Type != Block::BLOCK_EMPTY &&
		Curboard->m_pGameBoard[GridY_4][GridX_2]->m_Type != Block::CHAR_START_POS && 
		Curboard->m_pGameBoard[GridY_4][GridX_2]->m_Type != Block::BLOCK_WATER &&
		Curboard->m_pGameBoard[GridY_4][GridX_2]->m_Type != Block::BLOCK_UWATER &&
		Curboard->m_pGameBoard[GridY_4][GridX_2]->m_Type != Block::BLOCK_DOOR_OPEN &&
		Curboard->m_pGameBoard[GridY_4][GridX_2]->m_Type != Block::BLOCK_SPRING &&
		playerState == DOWN)
	{
		playerState = ONFLOOR;

		// ���� ���� ���
		_sndLand->soundSeek(0);
		cout << _sndLand->soundPlay();
		cout << "����!" << "\n";

		gravity = 0.0f;

		JumpPower = 0;

		//m_Speed = 7;

		m_PosY = (int)((m_PosY + TILESIZE / 2) / TILESIZE) * TILESIZE;

		if (xdir == 1)
		{
			_img = IMAGEMANAGER->FindImage("PLAYER_MOVE_R");
			_img->SetCurFrameX(0);
		}

		if (xdir == -1)
		{
			_img = IMAGEMANAGER->FindImage("PLAYER_MOVE_L");
			_img->SetCurFrameX(0);
		}
	}
}

// ���� ���� �Լ�
void Player::PlayerCheckEmptyFloor(Map* Curboard)
{
	int GridX_2 = (int)(m_PosX + (TILESIZE / 2)) / TILESIZE;
	int GridY_4 = (int)(m_PosY + 2 * TILESIZE + TILESIZE / 2) / TILESIZE;

	if (Curboard->m_pGameBoard[GridY_4][GridX_2]->m_Type == Block::BLOCK_EMPTY ||
		Curboard->m_pGameBoard[GridY_4][GridX_2]->m_Type == Block::BLOCK_WATER ||
		Curboard->m_pGameBoard[GridY_4][GridX_2]->m_Type == Block::BLOCK_UWATER ||
		Curboard->m_pGameBoard[GridY_4][GridX_2]->m_Type == Block::CHAR_START_POS)
	{
		playerState = DOWN;

		gravity = 2.0;

		// ��������Ʈ �̹��� ����
		if (xdir == 1)
		{
			_img = IMAGEMANAGER->FindImage("PLAYER_FALL_R");
			_img->SetCurFrameX(0);
		}

		if (xdir == -1)
		{
			_img = IMAGEMANAGER->FindImage("PLAYER_FALL_L");
			_img->SetCurFrameX(0);
		}
	}
}

// ���� ���� �Լ�
void Player::PlayerCheckUpTile(Map* Curboard)
{
	int GridX_0 = (int)(m_PosX + TILESIZE / 2 - 3 * TILESIZE) / TILESIZE;				// X ��ǥ
	int GridX_4 = (int)(m_PosX + TILESIZE / 2 + 3 * TILESIZE) / TILESIZE;
	int GridY_0 = (int)((m_PosY + TILESIZE + TILESIZE / 2) - 3 * TILESIZE) / TILESIZE;	// Y ��ǥ
	

	if ((Curboard->m_pGameBoard[GridY_0][GridX_0]->m_Type != Block::BLOCK_EMPTY &&
		Curboard->m_pGameBoard[GridY_0][GridX_0]->m_Type != Block::BLOCK_DOOR_CLOSE &&
		Curboard->m_pGameBoard[GridY_0][GridX_0 + 1]->m_Type == Block::BLOCK_EMPTY &&
		Curboard->m_pGameBoard[GridY_0][GridX_0 + 2]->m_Type == Block::BLOCK_EMPTY &&
		xdir == -1 && playerState == ONFLOOR) ||
		(Curboard->m_pGameBoard[GridY_0][GridX_4]->m_Type != Block::BLOCK_EMPTY &&
			Curboard->m_pGameBoard[GridY_0][GridX_4]->m_Type != Block::BLOCK_DOOR_CLOSE &&
			Curboard->m_pGameBoard[GridY_0][GridX_4 - 1]->m_Type == Block::BLOCK_EMPTY &&
			Curboard->m_pGameBoard[GridY_0][GridX_4 - 2]->m_Type == Block::BLOCK_EMPTY &&
			xdir == 1 && playerState == ONFLOOR))
	{
		PlayerJump();
	}
}

// ������ Ȯ�� �Լ� 
void Player::PlayerCheckSpring(Map* Curboard)	/// �߰� ����
{
	int PosGridX = (int)(m_PosX + (TILESIZE / 2)) / TILESIZE;
	int PosGridY = (int)(m_PosY + TILESIZE + TILESIZE / 2) / TILESIZE;

	if (Curboard->m_pGameBoard[PosGridY][PosGridX]->m_Type == Block::BLOCK_SPRING &&
		playerState == ONFLOOR)
	{
		SpringJump();
	}
}

// �÷��̾� �ʿ� ���α�
void Player::ConfinePlayerinMap()
{
	int PlayerPosX = m_PosX + TILESIZE / 2;				// �߽� ��ǥ
	int PlayerPosY = m_PosY + TILESIZE + TILESIZE / 2;

	if (PlayerPosX < TILESIZE / 2)
	{
		ChangeDirection();
	}
	if (PlayerPosX > WINSIZEX - TILESIZE / 2)
	{
		ChangeDirection();
	}
	if (PlayerPosY < 0)
	{
		m_PosY = m_PosY + TILESIZE + TILESIZE / 2;
	}
	if (PlayerPosY > MAPSIZE_Y)
	{
		m_PosY = WINSIZEY;
	}
}

// Ű ����ִ��� Ȯ��
void Player::PlayerCheckKey(Map* Curboard)
{
	int PlayerPosX = (int)(m_PosX + (TILESIZE / 2)) / TILESIZE;
	int PlayerPosY = (int)(m_PosY + TILESIZE + TILESIZE / 2) / TILESIZE;

	if (Curboard->m_pGameBoard[PlayerPosY][PlayerPosX]->m_Type == Block::BLOCK_KEY)
	{
		IsPlayerGotKey = TRUE;

		Curboard->m_pGameBoard[PlayerPosY][PlayerPosX]->m_Type = Block::BLOCK_EMPTY;
	}
}

// ���� ����ϱ� ���� ���� Ȯ��
void Player::PlayerCheckDoor(Map* Curboard)
{
	int GridX_3 = (int)(m_PosX + TILESIZE) / TILESIZE;				// X ��ǥ
	int GridX_1 = (int)((m_PosX + TILESIZE) - TILESIZE) / TILESIZE;

	int GridY_0 = (int)(m_PosY + TILESIZE + TILESIZE / 2) / TILESIZE;	// Y ��ǥ

	if (Curboard->m_pGameBoard[GridY_0][GridX_3]->m_Type == Block::BLOCK_DOOR_CLOSE &&
		IsPlayerGotKey == TRUE)
	{
		// ���� ������ ��� ��(5)�� ����.
		for (int y = 0; y < MAPSIZE_Y; y++)
		{
			for (int x = 0; x < MAPSIZE_X; x++)
			{
				if (Curboard->m_pGameBoard[y][x]->m_Type == Block::BLOCK_DOOR_CLOSE)
				{
					Curboard->m_pGameBoard[y][x]->m_Type = Block::BLOCK_DOOR_OPEN;
					cout << "��� �� (����) \n\n";
				}
			}
		}		
	}

	if (Curboard->m_pGameBoard[GridY_0][GridX_1]->m_Type == Block::BLOCK_DOOR_CLOSE &&
		IsPlayerGotKey == TRUE)
	{
		// ���� ������ ��� ��(5)�� ����.
		for (int y = 0; y < MAPSIZE_Y; y++)
		{
			for (int x = 0; x < MAPSIZE_X; x++)
			{
				if (Curboard->m_pGameBoard[y][x]->m_Type == Block::BLOCK_DOOR_CLOSE)
				{
					Curboard->m_pGameBoard[y][x]->m_Type = Block::BLOCK_DOOR_OPEN;
					cout << "��� �� (����) \n\n";
				}
			}
		}
	}
}

// ���� ���� �Լ�
void Player::PlayerCheckRoof(Map* Curboard)
{
	int GridX_2 = (int)(m_PosX + TILESIZE / 2) / TILESIZE;
	int GridY_2 = (int)(m_PosY + TILESIZE / 2) / TILESIZE;

	if (Curboard->m_pGameBoard[GridY_2][GridX_2]->m_Type == Block::BLOCK_WOOD ||
		Curboard->m_pGameBoard[GridY_2][GridX_2]->m_Type == Block::BLOCK_WOOD_L||
		Curboard->m_pGameBoard[GridY_2][GridX_2]->m_Type == Block::BLOCK_WOOD_M ||
		Curboard->m_pGameBoard[GridY_2][GridX_2]->m_Type == Block::BLOCK_WOOD_R ||
		Curboard->m_pGameBoard[GridY_2][GridX_2]->m_Type == Block::BLOCK_GRASS_02 ||
		Curboard->m_pGameBoard[GridY_2][GridX_2]->m_Type == Block::BLOCK_GRASS_03 ||
		Curboard->m_pGameBoard[GridY_2][GridX_2]->m_Type == Block::BLOCK_GRASS_L ||
		Curboard->m_pGameBoard[GridY_2][GridX_2]->m_Type == Block::BLOCK_GRASS_L2 ||
		Curboard->m_pGameBoard[GridY_2][GridX_2]->m_Type == Block::BLOCK_GRASS_R ||
		Curboard->m_pGameBoard[GridY_2][GridX_2]->m_Type == Block::BLOCK_GRASS_R2)
	{
		playerState = DOWN;
		JumpPower = 0;
		m_PosY = m_PosY /* / TILESIZE) * TILESIZE*/;
	}
}

// ������ ��������
void Player::GetMapInfo(Map* CurBoard)
{
	m_pCurBoard = CurBoard;
}
