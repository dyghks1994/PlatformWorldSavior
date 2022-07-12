#include "pch.h"
#include "Player.h"
#include "Scene05_Ingame.h"



using namespace std;

// �������� ��ȣ
int g_stageNum = 1;

// ī�޶� ���� �÷���
bool g_editModeCameraReset = true;

Scene05_Ingame::Scene05_Ingame()
{
	_imgBg = nullptr;
	_imgBg02 = nullptr;
	_imgBg03 = nullptr;

	//���� Ű
	_imgKey = nullptr;
	_imgDoorClose = nullptr;
	_imgDoorOpen = nullptr;
	_imgSpring = nullptr;

	_imgWood = nullptr;
	_imgWoodL = nullptr;
	_imgWoodM = nullptr;
	_imgWoodR = nullptr;

	_imgFruit = nullptr;

	_imgWater = nullptr;
	_imgUWater = nullptr;

	_imgGrass02 = nullptr;
	_imgGrass03 = nullptr;
	_imgGrassL = nullptr;
	_imgGrassL2 = nullptr;
	_imgGrassR = nullptr;
	_imgGrassR2 = nullptr;

	_imgUnderGround02 = nullptr;
	_imgUnderGround03 = nullptr;

	// (��Ȱ��) ������ ȥ
	_imgWood_R = nullptr;
	_imgWoodL_R = nullptr;
	_imgWoodM_R = nullptr;
	_imgWoodR_R = nullptr;

	_imgGrass02_R = nullptr;
	_imgGrass03_R = nullptr;
	_imgGrassL_R = nullptr;
	_imgGrassL2_R = nullptr;
	_imgGrassR_R = nullptr;
	_imgGrassR2_R = nullptr;

	_imgUnderGround02_R = nullptr;
	_imgUnderGround03_R = nullptr;

	_imgWater_R = nullptr;
	_imgUWater_R = nullptr;

	_imgKey_R = nullptr;
	_imgDoorClose_R = nullptr;
	_imgDoorOpen_R = nullptr;
	_imgSpring_R = nullptr;

	// UI �̹��� 
	_imgBackBoard = nullptr;
	_imgRestart = nullptr;
	_imgReset = nullptr;
	_imgGoBack = nullptr;
	_imgNextStage = nullptr;

	// ��� Ǯ, �� �̹���
	_imgRock01 = nullptr;
	_imgRock02 = nullptr;
	_imgBush01 = nullptr;
	_imgBush02 = nullptr;
}

Scene05_Ingame::~Scene05_Ingame()
{

}

HRESULT Scene05_Ingame::Init(void)
{
	g_debugMode = false;

	// �ʱ�ȭ �� ���� Ÿ�̸Ӹ� 0���� ����
	_timer = 0.0f;
	
	
	/// �̹��� ����
	// ��׶��� �̹���
	_imgBg = IMAGEMANAGER->FindImage("BG_MOUNTAIN");
	_imgBg02 = IMAGEMANAGER->FindImage("BG_INGAME");
	_imgBg03 = IMAGEMANAGER->FindImage("BG_INGAME02");

	//���� Ű
	_imgKey				= IMAGEMANAGER->FindImage("KEY");
	_imgDoorClose		= IMAGEMANAGER->FindImage("DOOR_CLOSE");
	_imgDoorOpen		= IMAGEMANAGER->FindImage("DOOR_OPEN");
	_imgSpring			= IMAGEMANAGER->FindImage("SPRING");

	_imgWood			= IMAGEMANAGER->FindImage("WOOD_TRUNK");
	_imgWoodL			= IMAGEMANAGER->FindImage("WOOD_TRUNK_L");
	_imgWoodM			= IMAGEMANAGER->FindImage("WOOD_TRUNK_M");
	_imgWoodR			= IMAGEMANAGER->FindImage("WOOD_TRUNK_R");

	_imgFruit			= IMAGEMANAGER->FindImage("FRUIT");

	_imgWater			= IMAGEMANAGER->FindImage("WATER");
	_imgUWater			= IMAGEMANAGER->FindImage("WATER_IN");

	_imgGrass02			= IMAGEMANAGER->FindImage("GRASS_02");
	_imgGrass03			= IMAGEMANAGER->FindImage("GRASS_03");
	_imgGrassL			= IMAGEMANAGER->FindImage("GRASS_ROUND_L01");
	_imgGrassL2			= IMAGEMANAGER->FindImage("GRASS_ROUND_L02");
	_imgGrassR			= IMAGEMANAGER->FindImage("GRASS_ROUND_R01");
	_imgGrassR2			= IMAGEMANAGER->FindImage("GRASS_ROUND_R02");

	_imgUnderGround02	= IMAGEMANAGER->FindImage("GROUND_02");
	_imgUnderGround03	= IMAGEMANAGER->FindImage("GROUND_03");

	// (��Ȱ��) ������ ȥ�� �̹���
	_imgWood_R			= IMAGEMANAGER->FindImage("WOOD_TRUNK_RED");
	_imgWoodL_R			= IMAGEMANAGER->FindImage("WOOD_TRUNK_L_RED");
	_imgWoodM_R			= IMAGEMANAGER->FindImage("WOOD_TRUNK_M_RED");
	_imgWoodR_R			= IMAGEMANAGER->FindImage("WOOD_TRUNK_R_RED");
	
	_imgGrass02_R		= IMAGEMANAGER->FindImage("GRASS_02_RED");
	_imgGrass03_R		= IMAGEMANAGER->FindImage("GRASS_03_RED");
	_imgGrassL_R		= IMAGEMANAGER->FindImage("GRASS_ROUND_L01_RED");
	_imgGrassL2_R		= IMAGEMANAGER->FindImage("GRASS_ROUND_L02_RED");
	_imgGrassR_R		= IMAGEMANAGER->FindImage("GRASS_ROUND_R01_RED");
	_imgGrassR2_R		= IMAGEMANAGER->FindImage("GRASS_ROUND_R02_RED");
	
	_imgUnderGround02_R	= IMAGEMANAGER->FindImage("GROUND_02_RED");
	_imgUnderGround03_R	= IMAGEMANAGER->FindImage("GROUND_03_RED");	

	_imgWater_R			= IMAGEMANAGER->FindImage("WATER_RED");
	_imgUWater_R		= IMAGEMANAGER->FindImage("WATER_IN_RED");

	_imgKey_R			= IMAGEMANAGER->FindImage("KEY_RED");				// Ű
	_imgDoorClose_R		= IMAGEMANAGER->FindImage("DOOR_CLOSE_RED");		// ���� ��
	_imgDoorOpen_R		= IMAGEMANAGER->FindImage("DOOR_OPEN_RED");			// ���� ��
	_imgSpring_R		= IMAGEMANAGER->FindImage("SPRING_RED");

	// UI �̹��� 
	_imgBackBoard		= IMAGEMANAGER->FindImage("UI_BG_04");
	_imgRestart			= IMAGEMANAGER->FindImage("UI_BUTTON_RESTART");
	_imgReset			= IMAGEMANAGER->FindImage("UI_BUTTON_RESET");
	_imgGoBack			= IMAGEMANAGER->FindImage("UI_BUTTON_GOBACK");
	_imgNextStage		= IMAGEMANAGER->FindImage("UI_BUTTON_NEXTSTAGE");
	// ��� Ǯ, �� �̹���
	_imgRock01 = IMAGEMANAGER->FindImage("ROCK_01");
	_imgRock02 = IMAGEMANAGER->FindImage("ROCK_02");
	_imgBush01 = IMAGEMANAGER->FindImage("BUSH_01");
	_imgBush02 = IMAGEMANAGER->FindImage("BUSH_02");

	/// ���� ����
	// �ΰ��� bgm �ݺ� ���
	_sndBG = SOUNDMANAGER->FindSound("BGM_INGAME");		// bgm ����
	_sndBG->soundSeek(0);
	_sndBG->soundPlayLooping();

	/// Die ����
	_sndDie = SOUNDMANAGER->FindSound("DIE");

	/// ��ư Ŭ�� ����(���� ������ ������� ����)
	_sndBtnClick = SOUNDMANAGER->FindSound("BUTTON_CLICK");

	/// �� �ʱ�ȭ
	if (!m_pMap)
	{
		m_pMap = new Map();
		m_pMap->Initialize();
	}

	/// �÷��̾� �ʱ�ȭ
	if (!_player)
	{
		_player = new Player;
	}

	_cameraX = _player->m_PosX - (WINSIZEX / 2);
	_cameraY = _player->m_PosY - (WINSIZEY / 2);

	// �������� ��ȣ�� ���缭 �� ����
	switch (g_stageNum)
	{
		case 0:
			cout << "���� ��������(0) Init\n\n";
			Init_Stage_Sample();
			break;

		case 1:
			cout << "�������� 01 Init\n\n";
			Init_Stage01();
			break;

		case 2:
			cout << "�������� 02 Init\n\n";
			Init_Stage02();
			break;

		case 3:
			cout << "�������� 03 Init\n\n";
			Init_Stage03();
			break;
	}

	_player->PlayerGravity();
	_player->JumpPower = 0.0f;
	_player->playerState = ONFLOOR;


	return S_OK;
}

void Scene05_Ingame::Init_Stage_Sample()
{
	InputBoardData(0);

	/// �迭�� ���� ��ȣ�� �������� ��ǥ�� �� ĳ������ ���� ��ġ�� ��� ���
	// ĳ������ ���� Ÿ�� ���ϱ�
	//POINT pos = CalcCharSetPos(8, MAPSIZE_Y - 9);
	//_startPosX = pos.x;
	//_startPosY = pos.y;
	///

	/// �迭�� �ִ� ��(����) �߿� ù -1�� ã�Ƽ� �÷��̾��� ������ġ�� ��� ���
	for (int y = 0; y < MAPSIZE_Y; y++)
	{
		for (int x = 0; x < MAPSIZE_X; x++)
		{
			if (m_pMap->GetType(x, y) == Block::CHAR_START_POS)
			{
				_startPosX = x * TILESIZE;
				_startPosY = (y * TILESIZE) - TILESIZE; // y��ǥ�� ��ĭ ��������� �Ѵ�.

				break;
			}
		}
	}

	// ������ġ�� ����
	_player->Initialize(TILESIZE, _startPosX, _startPosY);

	// Ű�� �Ȱ��� ���·� �׻� �ʱ�ȭ
	_player->IsPlayerGotKey = FALSE;

	// ������ �̵� �̹����� ����
	_player->_img = IMAGEMANAGER->FindImage("PLAYER_MOVE_R");

	printf_s("ĳ���� ��ġ[%f,%f] \n\n", _player->m_PosX, _player->m_PosY);

	/// ���� �߿�

	// ī�޶� ��ġ ����
	MoveCamera();

	// �ΰ��� ���콺 ��ǥ ����
	MappingMousePoint();

	MappingUI();

	_gameState = Game_State::Edit;	
}

void Scene05_Ingame::Init_Stage01()
{
	InputBoardData(1);
	SetLimitTime();

	/// �迭�� ���� ��ȣ�� �������� ��ǥ�� �� ĳ������ ���� ��ġ�� ��� ���
	// ĳ������ ���� Ÿ�� ���ϱ�
	//POINT pos = CalcCharSetPos(8, MAPSIZE_Y - 9);
	//_startPosX = pos.x;
	//_startPosY = pos.y;
	///

	/// �迭�� �ִ� ��(����) �߿� ù -1�� ã�Ƽ� �÷��̾��� ������ġ�� ��� ���
	for (int y = 0; y < MAPSIZE_Y; y++)
	{
		for (int x = 0; x < MAPSIZE_X; x++)
		{
			if (m_pMap->GetType(x, y) == Block::CHAR_START_POS)
			{
				_startPosX = x * TILESIZE;
				_startPosY = (y * TILESIZE) - TILESIZE; // y��ǥ�� ��ĭ ��������� �Ѵ�.
				
				break;
			}	
		}
	}	

	// ������ġ�� ����
	_player->Initialize(TILESIZE, _startPosX, _startPosY);
	_player->xdir = 1;

	// Ű�� �Ȱ��� ���·� �׻� �ʱ�ȭ
	_player->IsPlayerGotKey = FALSE;

	// ������ �̵� �̹����� ����
	_player->_img = IMAGEMANAGER->FindImage("PLAYER_MOVE_R");
	
	printf_s("ĳ���� ��ġ[%f,%f] \n\n", _player->m_PosX, _player->m_PosY);

	/// ���� �߿�

	// ī�޶� ��ġ ����
	MoveCamera();

	// �ΰ��� ���콺 ��ǥ ����
	MappingMousePoint();	

	// UI ��ǥ ����
	MappingUI();

	// ���۽ÿ� ��ġ���� ����
	_gameState = Game_State::Edit;
}

void Scene05_Ingame::Init_Stage02()
{
	InputBoardData(2);
	SetLimitTime();

	/// �迭�� ���� ��ȣ�� �������� ��ǥ�� �� ĳ������ ���� ��ġ�� ��� ���
	// ĳ������ ���� Ÿ�� ���ϱ�
	//POINT pos = CalcCharSetPos(8, MAPSIZE_Y - 9);
	//_startPosX = pos.x;
	//_startPosY = pos.y;
	///

	/// �迭�� �ִ� ��(����) �߿� ù -1�� ã�Ƽ� �÷��̾��� ������ġ�� ��� ���
	for (int y = 0; y < MAPSIZE_Y; y++)
	{
		for (int x = 0; x < MAPSIZE_X; x++)
		{
			if (m_pMap->GetType(x, y) == Block::CHAR_START_POS)
			{
				_startPosX = x * TILESIZE;
				_startPosY = (y * TILESIZE) - TILESIZE; // y��ǥ�� ��ĭ ��������� �Ѵ�.

				break;
			}
		}
	}

	// ������ġ�� ����
	_player->Initialize(TILESIZE, _startPosX, _startPosY);
	_player->xdir = 1;

	// Ű�� �Ȱ��� ���·� �׻� �ʱ�ȭ
	_player->IsPlayerGotKey = FALSE;

	// ������ �̵� �̹����� ����
	_player->_img = IMAGEMANAGER->FindImage("PLAYER_MOVE_R");

	printf_s("ĳ���� ��ġ[%f,%f] \n\n", _player->m_PosX, _player->m_PosY);

	/// ���� �߿�

	// ī�޶� ��ġ ����
	MoveCamera();

	// �ΰ��� ���콺 ��ǥ ����
	MappingMousePoint();

	// UI ��ǥ ����
	MappingUI();

	// ���۽ÿ� ��ġ���� ����
	_gameState = Game_State::Edit;
}

void Scene05_Ingame::Init_Stage03()
{
	InputBoardData(3);
	SetLimitTime();

	/// �迭�� ���� ��ȣ�� �������� ��ǥ�� �� ĳ������ ���� ��ġ�� ��� ���
	// ĳ������ ���� Ÿ�� ���ϱ�
	//POINT pos = CalcCharSetPos(8, MAPSIZE_Y - 9);
	//_startPosX = pos.x;
	//_startPosY = pos.y;
	///

	/// �迭�� �ִ� ��(����) �߿� ù -1�� ã�Ƽ� �÷��̾��� ������ġ�� ��� ���
	for (int y = 0; y < MAPSIZE_Y; y++)
	{
		for (int x = 0; x < MAPSIZE_X; x++)
		{
			if (m_pMap->GetType(x, y) == Block::CHAR_START_POS)
			{
				_startPosX = x * TILESIZE;
				_startPosY = (y * TILESIZE) - TILESIZE; // y��ǥ�� ��ĭ ��������� �Ѵ�.

				cout << y << "  " << x << "\n\n";

				break;
			}

		}
	}

	// ������ġ�� ����
	_player->Initialize(TILESIZE, _startPosX, _startPosY);
	_player->xdir = 1;

	// Ű�� �Ȱ��� ���·� �׻� �ʱ�ȭ
	_player->IsPlayerGotKey = FALSE;

	// ������ �̵� �̹����� ����
	_player->_img = IMAGEMANAGER->FindImage("PLAYER_MOVE_R");

	printf_s("ĳ���� ��ġ[%f,%f] \n\n", _player->m_PosX, _player->m_PosY);

	/// ���� �߿�

	// ī�޶� ��ġ ����
	MoveCamera();

	// �ΰ��� ���콺 ��ǥ ����
	MappingMousePoint();

	// UI ��ǥ ����
	MappingUI();

	// ���۽ÿ� ��ġ���� ����
	_gameState = Game_State::Edit;
}

void Scene05_Ingame::Release(void)
{
	SAFE_DELETE(_player);
	SAFE_DELETE(m_pMap);
}

void Scene05_Ingame::Update(void)
{
	/// ���� ��ũ��(DC)�� �������Ե� ���� ����(ī�޶� �̵�)
	MoveCamera();

	/// ���� ��ġ�� ������(â) ���̿� ����� ��ǥ ���� ����
	MappingMousePoint();
	MappingUI();

	/// ����� Ű �Է�
	/// �ӵ�, ������, ���� ��ȯ ���� ��..
	DebugingKeyInput();

	switch (_gameState)
	{
		/// �÷��� ���
		case Game_State::Play:
		{
			/// Ÿ�̸�
			_timer += TIMEMANAGER->GetElaspedTimeSec();

			// Ȥ�� ������ �������̿��ٸ� ���������Ѵ�
			_isSelectMode = false;
			PickedMouseBlockType = Block::BLOCK_MOUSEEMPTY;
			
			if (IsChangeMode())
			{
				g_editModeCameraReset = true;

				_player->PlayerGravity();
				_player->JumpPower = 0.0f;
				_player->playerState = ONFLOOR;

				// ��尡 �ٲ������ �����ϰ� �ٽ� �������� ������
				return;
			}

			if (KEYMANAGER->IsOnceKeyDown(VK_LBUTTON))
			{
				DebugShowMouseClickState();
				CheckCurrentBoard(_ptMouse.x, _ptMouse.y);
			}

			_player->GetMapInfo(m_pMap);

			// �� ���� ��Ż ����
			CheckPlayerPos(_player->m_PosX, _player->m_PosY);

			_player->PlayerAutoMove();

			CheckStageClear();

			_player->PlayerGravity();

			_player->PlayerCheckUpTile(m_pMap);

			_player->PlayerCheckSpring(m_pMap);

			_player->PlayerCheckEmptyFloor(m_pMap);

			_player->PlayerCheckFloor(m_pMap);

			_player->PlayerCheckKey(m_pMap);

			_player->PlayerCheckDoor(m_pMap);

			_player->PlayerCheckWall(m_pMap);

			_player->PlayerCheckRoof(m_pMap);

			break;
		}

		case Game_State::Edit:
		{
			// ����Ʈ -> �÷���
			if (IsChangeMode())
			{
				/// Ÿ�̸� ����
				_timer = 0.0f;
				
				/// ĳ���� ��ġ ����
				_player->xdir = 1;
				_player->m_PosX = _startPosX;
				_player->m_PosY = _startPosY;
				/// ������ �̵� �̹����� ����
				_player->_img = IMAGEMANAGER->FindImage("PLAYER_MOVE_R");
				
				g_editModeCameraReset = false;
				
				_player->IsPlayerGotKey = FALSE;

				_player->playerState = ONFLOOR;


				for (int y = 0; y  < MAPSIZE_Y; y++)
				{
					for (int x = 0; x < MAPSIZE_X; x++)
					{
						if (g_stageNum == 2)
						{
							// �������� 02�� �����Ϳ��� ���踦 ã�Ƽ� ���� ��ġ�� ã��
							if (m_StageTwoData[y][x] == (int)Block::BLOCK_KEY)
							{
								_keyStartX = x;
								_keyStartY = y;

								m_pMap->SetType(_keyStartX, _keyStartY, Block::BLOCK_KEY);

								break;
							}

							if (m_StageTwoData[y][x] == (int)Block::BLOCK_DOOR_CLOSE)
							{

								// ����(2) * ����(3) ĭ�� ���� (��) ����� �ִ´�.
								m_pMap->SetType(_doorStartX + 0, _doorStartY + 0, Block::BLOCK_DOOR_CLOSE);
								m_pMap->SetType(_doorStartX + 1, _doorStartY + 0, Block::BLOCK_DOOR_CLOSE);
								m_pMap->SetType(_doorStartX + 0, _doorStartY + 1, Block::BLOCK_DOOR_CLOSE);
								m_pMap->SetType(_doorStartX + 1, _doorStartY + 1, Block::BLOCK_DOOR_CLOSE);
								m_pMap->SetType(_doorStartX + 0, _doorStartY + 2, Block::BLOCK_DOOR_CLOSE);
								m_pMap->SetType(_doorStartX + 1, _doorStartY + 2, Block::BLOCK_DOOR_CLOSE);						

								break;
							}


						}
					}
				}

				// ��尡 �ٲ������ �����ϰ� �ٽ� �������� ������
				return;
			}

			// ���콺 �� Ŭ���� ������
			if (KEYMANAGER->IsOnceKeyDown(VK_LBUTTON))
			{
				cout << "���콺 ��Ŭ�� \n\n";
				SelectButton();
			}

			// ���콺 ����Ŭ�� �ϸ�
			if (KEYMANAGER->IsOnceKeyDown(VK_RBUTTON))
			{
				// ���� ����
				cout << "���콺 ����Ŭ�� \n\n";
				PickedMouseBlockType = Block::BLOCK_MOUSEEMPTY;
				_isSelectMode = false;
			}

			break;
		}

		case Game_State::Stop:
		{
			/// Ÿ�̸ӿ� ���� Ŭ����� ���� 
			SetClearLevel();

			cout << "�������� Ŭ����. Ŭ���� ���� = " << g_clearLevel << "\n\n";
			
			/// ���� ��� ���� (���� ��ư ���� ���� ����)
			_sndBG->soundPause();

			SCENEMANAGER->ChangeScene("_resultScene");
			return;
		}
	}// end of switch
}

void Scene05_Ingame::Render()
{
	// ����� ���� �׸���.
	//_imgBg->Render(g_backBuffer->GetMemDC(), 0, 0);
	_imgBg02->Render(g_backBuffer->GetMemDC(), 0, 0);
	//_imgBg03->Render(g_backBuffer->GetMemDC(), 0, 0);


	// �÷��̾ �׸���.(������ �ִϸ��̼�)
	_player->_img->FrameRender(g_backBuffer->GetMemDC(), _player->m_PosX, _player->m_PosY);

	// Ÿ��(���)�� �׸���.
	RenderTile();


	// ����� ��尡 ���� ������ 
	if(g_debugMode) DebugShowInfo();

	// ��ġ��� UI ����
	if (_gameState == Game_State::Edit)
	{
		//. ���� ���� �׸���
		m_pMap->DrawGrid();
		
		RenderUI();
	}

	if (_isSelectMode)
	{
		switch (PickedMouseBlockType)
		{
			// 1ĭ ����� ���� ���� ��
			case Block::BLOCK_WOOD:
			{
				_imgWood->Render(g_backBuffer->GetMemDC(), _ptMouse.x - TILESIZE / 2, _ptMouse.y - TILESIZE / 2);
				break;
			}

			// 5ĭ ����� ���� ���� ��
			case Block::BLOCK_WOOD_L:
			{
				if (g_stageNum == 1 || g_stageNum == 0)
				{
					_imgWoodL->Render(g_backBuffer->GetMemDC(), _ptMouse.x - TILESIZE / 2 + TILESIZE * 0, _ptMouse.y - TILESIZE / 2);
					_imgWoodM->Render(g_backBuffer->GetMemDC(), _ptMouse.x - TILESIZE / 2 + TILESIZE * 1, _ptMouse.y - TILESIZE / 2);
					_imgWoodM->Render(g_backBuffer->GetMemDC(), _ptMouse.x - TILESIZE / 2 + TILESIZE * 2, _ptMouse.y - TILESIZE / 2);
					_imgWoodM->Render(g_backBuffer->GetMemDC(), _ptMouse.x - TILESIZE / 2 + TILESIZE * 3, _ptMouse.y - TILESIZE / 2);
					_imgWoodR->Render(g_backBuffer->GetMemDC(), _ptMouse.x - TILESIZE / 2 + TILESIZE * 4, _ptMouse.y - TILESIZE / 2);
				}

				else
				{
					_imgWoodL->Render(g_backBuffer->GetMemDC(), _ptMouse.x - TILESIZE / 2 + TILESIZE * 0, _ptMouse.y - TILESIZE / 2);
					_imgWoodM->Render(g_backBuffer->GetMemDC(), _ptMouse.x - TILESIZE / 2 + TILESIZE * 1, _ptMouse.y - TILESIZE / 2);
					_imgWoodR->Render(g_backBuffer->GetMemDC(), _ptMouse.x - TILESIZE / 2 + TILESIZE * 2, _ptMouse.y - TILESIZE / 2);
				}
				
				break;
			}

			// ������ ����� ���� ���� ��
			case Block::BLOCK_SPRING:
			{
				_imgSpring->Render(g_backBuffer->GetMemDC(), _ptMouse.x - TILESIZE / 2, _ptMouse.y - TILESIZE / 2);
				break;
			}

		}// end of switch
	}

	// ī�޶� ����
	g_backBuffer->Render(g_backBuffer->GetMemDC(), 0, 0, _cameraX, _cameraY, BACKDCSIZEX, BACKDCSIZEY);
}

void Scene05_Ingame::InputBoardData(int mapData)
{
	switch (mapData)
	{
		/// �����ο� ���� �� �ʱ�ȭ
		case 0:
		{
			for (int y = 0; y < MAPSIZE_Y; y++)
			{
				for (int x = 0; x < MAPSIZE_X; x++)
				{
					m_pMap->SetType(x, y, (Block)m_SampleData[y][x]);
				}
			}
			
			break;
		}

		/// �������� 1 ����
		case 1:
		{
			for (int y = 0; y < MAPSIZE_Y; y++)
			{
				for (int x = 0; x < MAPSIZE_X; x++)
				{
					m_pMap->SetType(x, y, (Block)m_StageOneData[y][x]);
				}
			}
			
			break;
		}

		/// �������� 2 ����
		case 2:
		{
			for (int y = 0; y < MAPSIZE_Y; y++)
			{
				for (int x = 0; x < MAPSIZE_X; x++)
				{
					m_pMap->SetType(x, y, (Block)m_StageTwoData[y][x]);
				}
			}

			break;
		}

		/// �������� 3 ����
		case 3:
		{
			for (int y = 0; y < MAPSIZE_Y; y++)
			{
				for (int x = 0; x < MAPSIZE_X; x++)
				{
					m_pMap->SetType(x, y, (Block)m_StageThreeData[y][x]);
				}
			}

			break;
		}
	}	
}

void Scene05_Ingame::MoveCamera()
{
	//  �÷��� ��忡�� ĳ���� ��ġ�� ���� �ڵ� �̵�
	if (_gameState == Game_State::Play)
	{
		// ī�޶� ��ǥ ����
		_cameraX = _player->m_PosX - (WINSIZEX / 2);
		_cameraY = _player->m_PosY - (WINSIZEY / 2);

		// ********* ī�޶� ���� ����� �ʵ��� ��ġ ���� **********************

	// ĳ���Ͱ� ���� ���� ������� ī�޶� �������� �̵��ϸ� �ȵ� ��
		if (_player->m_PosX - WINSIZEX / 2 <= 0) _cameraX = 0;

		// ĳ���Ͱ� ���� ���� ������� ī�޶� �������� �̵��ϸ� �ȵ� ��
		if (_player->m_PosY - WINSIZEY / 2 <= 0) _cameraY = 0;

		// ĳ���Ͱ� ������ ���� ������� ī�޶� ���������� �̵��ϸ� �ȵ� ��
		//if (_player->m_PosX + WINSIZEX / 2 > _imgBg->GetWidth()) _cameraX = _imgBg->GetWidth() - WINSIZEX;
		if (_player->m_PosX + WINSIZEX / 2 > 2800) _cameraX = 2800 - WINSIZEX;

		// ĳ���Ͱ� �Ʒ��� ���� ������� ī�޶� �Ʒ������� �̵��ϸ� �ȵ� ��
		if (_player->m_PosY + WINSIZEY / 2 > _imgBg->GetHeight()) _cameraY = _imgBg->GetHeight() - WINSIZEY;
	}
	

	// ��ġ��忡�� WASD Ű �Է½� ī�޶� �̵�
	if (_gameState == Game_State::Edit)
	{
		if (!g_editModeCameraReset)
		{
			_cameraX = _player->m_PosX - (WINSIZEX / 2);
			_cameraY = _player->m_PosY - (WINSIZEY / 2);

			g_editModeCameraReset = true;
		}
		
		if (KEYMANAGER->IsStayKeyDown('W'))
		{
			_cameraY -= 20.0f;
		}

		if (KEYMANAGER->IsStayKeyDown('S'))
		{
			_cameraY += 20.0f;
		}

		if (KEYMANAGER->IsStayKeyDown('A'))
		{
			_cameraX -= 20.0f;
		}

		if (KEYMANAGER->IsStayKeyDown('D'))
		{
			_cameraX += 20.0f;
		}

		if (_cameraX <= 0) _cameraX = 0;
		if (_cameraY <= 0) _cameraY = 0;

		if (_cameraX + WINSIZEX > _imgBg->GetWidth()) _cameraX = _imgBg->GetWidth() - WINSIZEX ;
		if (_cameraY + WINSIZEY > _imgBg->GetHeight()) _cameraY = _imgBg->GetHeight() - WINSIZEY;		
	}
}

void Scene05_Ingame::MappingMousePoint()
{
	_ptMouse.x = g_ptMouse.x + _cameraX;
	_ptMouse.y = g_ptMouse.y + _cameraY;
}

void Scene05_Ingame::MappingUI()
{
	// ���� UI �� ��ư ����
	_imgBackBoard->SetX(_cameraX + 20);
	_imgBackBoard->SetY(_cameraY + WINSIZEY - 250);

	_imgReset->SetX(_cameraX+WINSIZEX-130);
	_imgReset->SetY(_imgBackBoard->GetY()-100);

	_imgGoBack->SetX(_cameraX + 20);
	_imgGoBack->SetY(_imgBackBoard->GetY() - 100);


	/// ���� ��ư���� ��ġ�� ���� �Ѵ�.
	// 1ĭ ����
	_imgWood->SetX(0);
	_imgWood->SetY(-70);

	// 5 ĭ ����(��)
	_imgWoodL->SetX(0);
	_imgWoodL->SetY(-70);

	// 5 ĭ ����(�߰�)
	_imgWoodM->SetX(0);
	_imgWoodM->SetY(-70);

	// 5 ĭ ����(��)
	_imgWoodR->SetX(0);
	_imgWoodR->SetY(-70);

	// ������
	_imgSpring->SetX(0);
	_imgSpring->SetY(-70);

	// Ű
	_imgKey->SetX(0);
	_imgKey->SetY(-70);

	// ���� ��
	_imgDoorClose->SetX(0);
	_imgDoorClose->SetY(-70);

	switch (g_stageNum)
	{
		// ������ �� ���� ���� ��ư ����
	case 0:
		_imgWood->SetX(_cameraX + 70);
		_imgWood->SetY(_cameraY + 980);

		_imgWoodL->SetX(_cameraX + 300);
		_imgWoodL->SetY(_cameraY + 980);

		_imgWoodM->SetX(_cameraX + 370);
		_imgWoodM->SetY(_cameraY + 980);

		_imgWoodR->SetX(_cameraX + 570);
		_imgWoodR->SetY(_cameraY + 980);

		_imgSpring->SetX(_cameraX + 700);
		_imgSpring->SetY(_cameraY + 980);

		_imgKey->SetX(_cameraX + 850);
		_imgKey->SetY(_cameraY + 980);

		_imgDoorClose->SetX(_cameraX + 1000);
		_imgDoorClose->SetY(_cameraY + 890);
		break;

		// �������� 01 ��ư ����
	case 1:
		_imgWood->SetX(_cameraX + 420);
		_imgWood->SetY(_cameraY + 980);

		_imgWoodL->SetX(_cameraX + 700);
		_imgWoodL->SetY(_cameraY + 980);

		_imgWoodM->SetX(_imgWoodL->GetX() + 70);
		_imgWoodM->SetY(_cameraY + 980);


		_imgWoodR->SetX(_imgWoodM->GetX() + 200);
		_imgWoodR->SetY(_cameraY + 980);

		break;

	case 2:
		_imgWood->SetX(_cameraX + 420);
		_imgWood->SetY(_cameraY + 980);
		
		_imgWoodL->SetX(_cameraX + 800);
		_imgWoodL->SetY(_cameraY + 980);
		
		_imgWoodM->SetX(_imgWoodL->GetX() + TILESIZE);
		_imgWoodM->SetY(_imgWoodL->GetY());
		
		_imgWoodR->SetX(_imgWoodM->GetX() + TILESIZE);
		_imgWoodR->SetY(_imgWoodM->GetY());
		
		break;

	case 3:
		_imgSpring->SetX(_cameraX + 420);
		_imgSpring->SetY(_cameraY + 980);

		_imgWoodL->SetX(_cameraX + 800);
		_imgWoodL->SetY(_cameraY + 980);

		_imgWoodM->SetX(_imgWoodL->GetX() + TILESIZE);
		_imgWoodM->SetY(_imgWoodL->GetY());

		_imgWoodR->SetX(_imgWoodM->GetX() + TILESIZE);
		_imgWoodR->SetY(_imgWoodM->GetY());
		break;
	}
	
}

// �迭���� 0������ size-1 �� ��ǥ�� �Է��Ͻÿ�.
// 0 ~ MAPSIZE - 1
POINT Scene05_Ingame::CalcCharSetPos(int x, int y)
{
	POINT pos;

	pos.x = x * TILESIZE;
	pos.y = (y * TILESIZE) - TILESIZE;	// ĳ���Ͱ� Ÿ�� ������ ���� 1*2 �������(70px,140px) y�� 70��ŭ ���� ������ ��

	return pos;
}

bool Scene05_Ingame::CheckPlayerPos(float x, float y)
{
	int PlayerPosX = _player->m_PosX + TILESIZE / 2;				// �߽� ��ǥ
	int PlayerPosY = _player->m_PosY + TILESIZE + TILESIZE / 2;

	// �� ���ʿ� ����� �� ���� ��ȯ
	if (PlayerPosX < 0)
	{
		// ������ �ٲٰ� �ʹٸ� ���⸦
		_player->ChangeDirection();

		// ĳ������ ��ġ�� �����ϰ� �ٽ� �÷����Ϸ��� ���⸦
		//this->ResetCharPos();
	}

	// �� ���� �հ� �ö� �� �Ʒ��� �����Ѵ�.
	if (PlayerPosY < (0 + 200))
	{
		_player->m_PosY += TILESIZE;
	}
	// �� �����ʿ� ����� �� 
	if (PlayerPosX > (MAPSIZE_X * TILESIZE - TILESIZE / 2))
	{
		// ������ȯ
		_player->ChangeDirection();
	}

	if (PlayerPosY > (MAPSIZE_Y * TILESIZE - (TILESIZE * 5)) )
	{
		this->ResetCharPos();
	}

	return false;
}

void Scene05_Ingame::ResetCharPos()
{
	bool findDoorStartPos = false;

	for (int y = 0; y < MAPSIZE_Y; y++)
	{
		for (int x = 0; x < MAPSIZE_X; x++)
		{
			// ���� ���� �������ش�
			if (m_pMap->m_pGameBoard[y][x]->m_Type == Block::BLOCK_DOOR_OPEN ||
				m_pMap->m_pGameBoard[y][x]->m_Type == Block::BLOCK_DOOR_CLOSE)
			{
				//m_pMap->m_pGameBoard[y][x]->m_Type = Block::BLOCK_EMPTY;
			}

			if (g_stageNum == 1)
			{
				//// �������� 01�� �����Ϳ��� ���踦 ã�Ƽ� ���� ��ġ�� ã��
				//if (m_StageOneData[y][x] == (int)Block::BLOCK_KEY)
				//{
				//	//cout << " ã�� " 
				//	_keyStartX = x;
				//	_keyStartY = y;
				//
				//	break;
				//}
				//
				//// �������� 01�� �����Ϳ��� ���� ���� ��ġ�� ã�Ƽ� �����Ѵ�
				//if (m_StageOneData[y][x] == (int)Block::BLOCK_DOOR_CLOSE && findDoorStartPos == false)
				//{
				//	findDoorStartPos = true;
				//
				//	_doorStartX = x;
				//	_doorStartY = y;
				//	cout << "ù ���� �׸��� X = " << _doorStartX << " Y= " << _doorStartY << endl;
				//
				//	break;
				//}
			}
			
			if (g_stageNum == 2)
			{
				// �������� 02�� �����Ϳ��� ���踦 ã�Ƽ� ���� ��ġ�� ã��
				if (m_StageTwoData[y][x] == (int)Block::BLOCK_KEY)
				{
					_keyStartX = x;
					_keyStartY = y;

					m_pMap->SetType(_keyStartX, _keyStartY, Block::BLOCK_KEY);

					break;
				}

				// �������� 02�� �����Ϳ��� ���� ���� ��ġ�� ã�Ƽ� �����Ѵ�
				if (m_StageTwoData[y][x] == (int)Block::BLOCK_DOOR_CLOSE && findDoorStartPos == false)
				{
					_doorStartX = x;
					_doorStartY = y;
					cout << "ù ���� �׸��� X = " << _doorStartX << " Y= " << _doorStartY << endl;

					// ����(2) * ����(3) ĭ�� ���� (��) ����� �ִ´�.
					m_pMap->SetType(_doorStartX + 0, _doorStartY + 0, Block::BLOCK_DOOR_CLOSE);
					m_pMap->SetType(_doorStartX + 1, _doorStartY + 0, Block::BLOCK_DOOR_CLOSE);	
					m_pMap->SetType(_doorStartX + 0, _doorStartY + 1, Block::BLOCK_DOOR_CLOSE);
					m_pMap->SetType(_doorStartX + 1, _doorStartY + 1, Block::BLOCK_DOOR_CLOSE);
					m_pMap->SetType(_doorStartX + 0, _doorStartY + 2, Block::BLOCK_DOOR_CLOSE);
					m_pMap->SetType(_doorStartX + 1, _doorStartY + 2, Block::BLOCK_DOOR_CLOSE);

					findDoorStartPos = true;

					break;
				}
			}

			if (g_stageNum == 3)
			{
				// �������� 03�� �����Ϳ��� �������� ã�Ƽ� ���� ��ġ�� ã��
				if (m_StageThreeData[y][x] == (int)Block::BLOCK_KEY)
				{
					_keyStartX = x;
					_keyStartY = y;
				
					break;
				}
				
				// �������� 03�� �����Ϳ��� ���� ���� ��ġ�� ã�Ƽ� �����Ѵ�
				if (m_StageThreeData[y][x] == (int)Block::BLOCK_DOOR_CLOSE && findDoorStartPos == false)
				{
					findDoorStartPos = true;
				
					_doorStartX = x;
					_doorStartY = y;
					cout << "ù ���� �׸��� X = " << _doorStartX << " Y= " << _doorStartY << endl;
				
					break;
				}
			}
		}
	}		

	/// �迭�� �ִ� ��(����) �߿� ù -1�� ã�Ƽ� �÷��̾��� ������ġ�� ��� ���
	for (int y = 0; y < MAPSIZE_Y; y++)
	{
		for (int x = 0; x < MAPSIZE_X; x++)
		{
			if (m_pMap->GetType(x, y) == Block::CHAR_START_POS)
			{
				_startPosX = x * TILESIZE;
				_startPosY = (y * TILESIZE) - TILESIZE; // y��ǥ�� ��ĭ ��������� �Ѵ�.

				cout << y << "  " << x << "\n\n";

				break;
			}

		}
	}

	_player->xdir = 1;

	_gameState = Game_State::Edit;
	_player->m_PosX = _startPosX;
	_player->m_PosY = _startPosY - TILESIZE;
	
	// ���� ���� ���
	_sndDie->soundSeek(0);
	_sndDie->soundPlay();

	_player->IsPlayerGotKey = FALSE;

	g_editModeCameraReset = false;

	// ī�޶� ��ǥ ����
	_cameraX = _player->m_PosX - (WINSIZEX / 2);
	_cameraY = _player->m_PosY - (WINSIZEY / 2);
}

// Ŭ����� ȭ�� ����
void Scene05_Ingame::CheckStageClear()
{
	int PlayerGridX = (int)(_player->m_PosX + TILESIZE / 2)/TILESIZE;				// �߽� ��ǥ
	int PlayerGridY = (int)(_player->m_PosY + TILESIZE + TILESIZE / 2)/TILESIZE;

	if (m_pMap->m_pGameBoard[PlayerGridY+1][PlayerGridX]->m_Type == Block::BLOCK_FRUIT)
	{
		_gameState = Game_State::Stop;

	}

}

void Scene05_Ingame::SetClearLevel()
{
	if (_timer < _limitTime[0])
	{
		// �� 3�� 
		g_clearLevel = 3;
	}

	else if (_timer < _limitTime[1])
	{
		// �� 2��
		g_clearLevel = 2;
	}

	else
	{
		// �� 1��
		g_clearLevel = 1;
	}

	cout << "���� �ð� : " << _limitTime[0] << "\n";
	cout << "���� �ð� : " << _limitTime[1] << "\n";
	cout << "Ŭ���� Ÿ�� : " << _timer << "\n\n";

}

void Scene05_Ingame::SetLimitTime()
{
	/// ���� Ŭ���� ���ѽð� ����
	switch (g_stageNum)
	{
	case 1:
		_limitTime[0] = 4.0f;
		_limitTime[1] = 8.0f;
		break;


	case 2:
		_limitTime[0] = 4.0f;
		_limitTime[1] = 7.5f;
		break;

	case 3:
		_limitTime[0] = 3.4f;
		_limitTime[1] = 5.0f;
		break;

	}
}

void Scene05_Ingame::DebugingKeyInput()
{
	/// �ΰ��� �� ĳ���� �Ӽ� ����
	if (KEYMANAGER->IsOnceKeyDown(VK_UP))
	{
		_player->MaxJumpPower -= 1;
	}

	if (KEYMANAGER->IsOnceKeyDown(VK_DOWN))
	{
		_player->MaxJumpPower += 1.0;
	}

	if (KEYMANAGER->IsOnceKeyDown(VK_LEFT))
	{
		_player->m_Speed -= 1;
	}

	if (KEYMANAGER->IsOnceKeyDown(VK_RIGHT))
	{
		_player->m_Speed += 1.0;
	}

	if (KEYMANAGER->IsOnceKeyDown('T'))
	{
		_player->SpringJumpPower -= 1.0f;
	}

	if (KEYMANAGER->IsOnceKeyDown('G'))
	{
		_player->SpringJumpPower += 1.0f;
	}

	if (KEYMANAGER->IsOnceKeyDown(VK_CONTROL))
	{
		cout << "�÷��̾� ������ȯ \n\n";
		_player->ChangeDirection();
	}

	if (KEYMANAGER->IsOnceKeyDown('R'))
	{
		ResetStage();
	}

	if (KEYMANAGER->IsOnceKeyDown('Q'))
	{
		g_debugMode = !g_debugMode;
	}

	////////////////////////////////////////////////////////////
}

void Scene05_Ingame::DebugDrawPlayerCollisionBox()
{
	int CurPosInTileX = ((int)(_player->m_PosX + TILESIZE / 2) / TILESIZE) * TILESIZE;
	int CurPosInTileY = ((int)(_player->m_PosY + TILESIZE / 2 + TILESIZE) / TILESIZE) * TILESIZE;

	DrawRectangleForDebug(g_backBuffer->GetMemDC(),		// ���� �Ҽ� �׸��� �Ķ� �ڽ�
		CurPosInTileX,				// left
		CurPosInTileY,				// top
		CurPosInTileX + TILESIZE,	// right 
		CurPosInTileY + TILESIZE,	// bottom
		RGB(0, 0, 255));

	DrawRectangleForDebug(g_backBuffer->GetMemDC(),		// �߽� ��ǥ ��� �ڽ�
		_player->m_PosX,
		_player->m_PosY + TILESIZE,
		_player->m_PosX + TILESIZE,
		_player->m_PosY + TILESIZE * 2,
		RGB(255, 255, 0));

	DrawRectangleForDebug(g_backBuffer->GetMemDC(),		// �߽� ��ǥ ������ ��
		_player->m_PosX + TILESIZE / 2 - 1,
		_player->m_PosY + TILESIZE + TILESIZE / 2 - 1,
		_player->m_PosX + TILESIZE / 2 + 1,
		_player->m_PosY + TILESIZE + TILESIZE / 2 + 1,
		RGB(255, 0, 255));
}

void Scene05_Ingame::DebugShowInfo()
{
	int PosGridX = _player->m_PosX + TILESIZE / 2;				// �߽� ��ǥ
	int PosGridY = _player->m_PosY + TILESIZE + TILESIZE / 2;

	TCHAR PosGridInfo[100];
	wsprintf(PosGridInfo, TEXT("���� �÷��̾� ��ġ �迭 X ��ǥ = %d, �迭 Y ��ǥ = %d"),
		(PosGridX / TILESIZE), (PosGridY / TILESIZE));
	TextOut(g_backBuffer->GetMemDC(), 10 + _cameraX, 10 + _cameraY, PosGridInfo, lstrlen(PosGridInfo));

	// ���� ���콺 ��ǥ
	TCHAR mouseInfo[100];
	wsprintf(mouseInfo, TEXT("���콺 X ��ǥ = %d, ���콺 Y ��ǥ = %d"), _ptMouse.x, _ptMouse.y);
	TextOut(g_backBuffer->GetMemDC(), 10 + _cameraX, 30 + _cameraY, mouseInfo, lstrlen(mouseInfo));

	// ���� ���콺�� Ŭ���� �迭 Ÿ�� ��
	TCHAR mousePickedBlockInfo[100];
	wsprintf(mousePickedBlockInfo, TEXT("���콺 Picked Block_Type = %d"), PickedMouseBlockType);
	TextOut(g_backBuffer->GetMemDC(), 10 + _cameraX, 50 + _cameraY, mousePickedBlockInfo, lstrlen(mousePickedBlockInfo));

	// ���� ĳ���� ����
	// �̵��ӵ�
	TCHAR playerSpeed[100];
	wsprintf(playerSpeed, TEXT("ĳ���� Speed = %d"), _player->m_Speed);
	TextOut(g_backBuffer->GetMemDC(), 10 + _cameraX, 70 + _cameraY, playerSpeed, lstrlen(playerSpeed));

	// ���� �����Ŀ�
	TCHAR current_playerJumpPower[100];
	wsprintf(current_playerJumpPower, TEXT("ĳ���� JumpPower = %d"), static_cast<int>(_player->JumpPower));
	TextOut(g_backBuffer->GetMemDC(), 10 + _cameraX, 90 + _cameraY, current_playerJumpPower, lstrlen(current_playerJumpPower));

	// �Ϲ� �����Ŀ�
	TCHAR Max_playerJumpPower[150];
	wsprintf(Max_playerJumpPower, TEXT("ĳ���� JumpPower = %d"), static_cast<int>(_player->MaxJumpPower));
	TextOut(g_backBuffer->GetMemDC(), 10 + _cameraX, 110 + _cameraY, Max_playerJumpPower, lstrlen(Max_playerJumpPower));

	// ������ �����Ŀ�
	TCHAR springJumpPower[150];
	wsprintf(springJumpPower, TEXT("ĳ���� ������ JumpPower = %d"), static_cast<int>(_player->SpringJumpPower));
	TextOut(g_backBuffer->GetMemDC(), 10 + _cameraX, 130 + _cameraY, springJumpPower, lstrlen(springJumpPower));

	//

	TextOut(g_backBuffer->GetMemDC(), 10 + _cameraX, 150 + _cameraY, L"�Ϲ�   ���ǵ� ���� [�� ��]", lstrlen(L"�Ϲ�   ���ǵ� ���� [�� ��]"));
	TextOut(g_backBuffer->GetMemDC(), 10 + _cameraX, 170 + _cameraY, L"�Ϲ�   ������ ���� [�� �Ʒ�]", lstrlen(L"�Ϲ�   ������ ���� [�� �Ʒ�]"));
	TextOut(g_backBuffer->GetMemDC(), 10 + _cameraX, 190 + _cameraY, L"������ ������ ���� [T G]", lstrlen(L"������ ������ ���� [T G]"));
	TextOut(g_backBuffer->GetMemDC(), 10 + _cameraX, 210 + _cameraY, L"���� ��ȯ [��Ʈ��Ctrl]", lstrlen(L"���� ��ȯ [��Ʈ��Ctrl]"));
	TextOut(g_backBuffer->GetMemDC(), 10 + _cameraX, 230 + _cameraY, L"�������� ���� [R]", lstrlen(L"�������� ���� [R]"));
	
	// Ÿ�̸� ���
	TCHAR time[150];
	wsprintf(time, TEXT("Ÿ�̸� : %d"), static_cast<int>(_timer));
	TextOut(g_backBuffer->GetMemDC(), 10 + _cameraX, 270 + _cameraY, time, lstrlen(time));


	//cout << "ĳ���� JumpPower = " << _player->JumpPower << "\n\n";
}

void Scene05_Ingame::DebugShowMouseClickState()
{
	cout << "[���콺 ��Ŭ��] \n";
	cout << "_ptMouse.x = " << _ptMouse.x << "\n";
	cout << "_ptMouse.y = " << _ptMouse.y << "\n";
	cout << "���� ���� xĭ = " << _ptMouse.x / TILESIZE << "\n";
	cout << "���� ���� yĭ = " << _ptMouse.y / TILESIZE << "\n\n";

	//
	cout << "m_CurPickedGameBoard = " << m_CurPickedGameBoard << "\n";
	cout << "PickedMouseBlockType = " << (int)PickedMouseBlockType << "\n\n";

	// ���� ���� ������ ���
	cout << "[���� m_FirstGameBoard] \n";
	for (int j = 0; j < MAPSIZE_Y; j++)
	{
		for (int i = 0; i < MAPSIZE_X; i++)
		{
			cout << (int)m_pMap->GetType(i, j) << " ";	/// �𸣰���...;;
		}
		cout << "\n\n";
	}
}

void Scene05_Ingame::CheckCurrentBoard(int x, int y)
{
	int CurMouseX = _ptMouse.x / TILESIZE;
	int CurMouseY = _ptMouse.y / TILESIZE;

	m_CurPickedGameBoard = m_pMap->GetBoardSet(CurMouseX, CurMouseY);
}

bool Scene05_Ingame::IsChangeMode()
{
	// SPACE �Է½� ��� ��ȯ
	if (KEYMANAGER->IsOnceKeyDown(VK_SPACE))
	{
		// ���Ӹ�� ��ȯ�ϰ�
		if (_gameState == Game_State::Play)
		{
			cout << "Game Mode Change! [Play -> Edit]\n\n";
			_gameState = Game_State::Edit;
		}

		else if (_gameState == Game_State::Edit)
		{
			cout << "Game Mode Change! [Edit -> Play]\n\n";
			_gameState = Game_State::Play;
		}

		// ���� true
		return true;
	}

	// ���Ӹ�尡 �ٲ��� �ʾ���. ���� ��� ����..
	return false;
}

void Scene05_Ingame::SelectButton()
{
	cout << "[SelectButtocn]\n";

	/// ��ư Ŭ�� ���� ���(���� ����)
	//_sndBtnClick->soundSeek(0);
	//_sndBtnClick->soundPlay();

	// 1ĭ ���� ��ư
	RECT btnWood = _imgWood->GetCollisionBox();

	// 3ĭ ���� ��ư
	RECT btnWood03 = _imgWoodL->GetCollisionBox();
	btnWood03.right += TILESIZE * 2;

	// 5ĭ ������ WoodL�� 1ĭ ¥���Ƿ� right�� 4ĭ �� �����Ѵ�.
	RECT btnWood05 = _imgWoodL->GetCollisionBox();
	btnWood05.right += TILESIZE * 4;

	// ������ ��ư
	RECT btnSpring = _imgSpring->GetCollisionBox();

	// Ű(����) ��ư
	RECT btnKey = _imgKey->GetCollisionBox();

	// ���� �� ��ư
	RECT btnDoorClose = _imgDoorClose->GetCollisionBox();

	// �ڷΰ��� ��ư
	RECT btnGoBack = _imgGoBack->GetCollisionBox();

	// ���� ��ư
	RECT btnReset = _imgReset->GetCollisionBox();

	if (PtInRect(&btnGoBack, _ptMouse))
	{
		// �������� ������
		// �ڷ� ����
		
		//g_editModeCameraReset = true;
		g_editModeCameraReset = false;

		SCENEMANAGER->ChangeScene("_stageScene");

		_sndBG->soundPause();

		return;
	}

	// ���� ��ư
	if (PtInRect(&btnReset, _ptMouse))
	{
		ResetStage();
	}


	// ���� ��尡 �ƴ� �� 
	if (!_isSelectMode)
	{
		int x = static_cast<int>(_ptMouse.x / TILESIZE);
		int y = static_cast<int>(_ptMouse.y / TILESIZE);
		//Block typeOfCurBoard = m_pMap->GetType(x, y);

		/// �������� ��ȣ�� ���� �ش� ���������� �ʱ� ���� ���忡�� �ش��ϴ� ������ Ÿ����
		/// EMPTY ��� �װ��� EMPTY�� ������ش�.(�ٽ� �� �������� �����)
		switch (g_stageNum)
		{
		case 0:
			if (m_SampleData[y][x] == (int)Block::BLOCK_EMPTY)
			{
				m_pMap->SetType(x, y, Block::BLOCK_EMPTY);
				cout << "���õ� ��� �ı�!\n\n";
			}
			break;

		case 1:
			if (m_StageOneData[y][x] == (int)Block::BLOCK_EMPTY)
			{
				m_pMap->SetType(x, y, Block::BLOCK_EMPTY);
				cout << "���õ� ��� �ı�!\n\n";
			}
			break;

		case 2:
			if (m_StageTwoData[y][x] == (int)Block::BLOCK_EMPTY)
			{
				m_pMap->SetType(x, y, Block::BLOCK_EMPTY);
				cout << "���õ� ��� �ı�!\n\n";
			}
			break;

		case 3:
			if (m_StageThreeData[y][x] == (int)Block::BLOCK_EMPTY)
			{
				m_pMap->SetType(x, y, Block::BLOCK_EMPTY);
				cout << "���õ� ��� �ı�!\n\n";
			}
			break;
		}

		// ���� �������� �ƴѵ� ��ư01�� Ŭ���߳�?
		if (PtInRect(&btnWood, _ptMouse))
		{
			// ���� Ÿ���� �������� ���·� ����
			_isSelectMode = true;

			// ��ư01�� Ÿ��(WOOD) ����
			PickedMouseBlockType = Block::BLOCK_WOOD;

			cout << "��ư 01 Ŭ��\n";
			cout << "���� ���õ� ��� = " << static_cast<int>(PickedMouseBlockType) << "\n";
		}

		// ���� �������� �ƴѵ� ��ư02�� Ŭ���߳�?
		if (PtInRect(&btnWood05, _ptMouse))
		{
			// ���� Ÿ���� �������� ���·� ����
			_isSelectMode = true;

			// ��ư02�� Ÿ�� ����
			PickedMouseBlockType = Block::BLOCK_WOOD_L;

			cout << "��ư 02 Ŭ��\n";
			cout << "���� ���õ� ��� = " << static_cast<int>(PickedMouseBlockType) << "\n";
		}

		// ���� �������� �ƴѵ� ��ư03�� Ŭ���߳�?
		if (PtInRect(&btnSpring, _ptMouse))
		{
			// ���� Ÿ���� �������� ���·� ����
			_isSelectMode = true;

			// ��ư03�� Ÿ�� ����
			PickedMouseBlockType = Block::BLOCK_SPRING;

			cout << "��ư 03 Ŭ��\n";
			cout << "���� ���õ� ��� = " << static_cast<int>(PickedMouseBlockType) << "\n";
		}

		// ���� �������� �ƴѵ� ��ư04�� Ŭ���߳�?
		if (PtInRect(&btnKey, _ptMouse))
		{
			// ���� Ÿ���� �������� ���·� ����
			_isSelectMode = true;

			// ��ư04�� Ÿ�� ����
			PickedMouseBlockType = Block::BLOCK_KEY;

			cout << "��ư 04 Ŭ��\n";
			cout << "���� ���õ� ��� = " << static_cast<int>(PickedMouseBlockType) << "\n";
		}

		// 3ĭ ���� ����� �����߳�?
		if (PtInRect(&btnWood03, _ptMouse))
		{
			// ���� Ÿ���� �������� ���·� ����
			_isSelectMode = true;

			// ��ư05�� Ÿ�� ����
			PickedMouseBlockType = Block::BLOCK_WOOD_L;

			cout << "3ĭ ���� ��ư Ŭ��\n";
			cout << "���� ���õ� ��� = " << static_cast<int>(PickedMouseBlockType) << "\n";
		}

		// ������ ��ư Ŭ��
		if (PtInRect(&btnDoorClose, _ptMouse))
		{
			// ���� Ÿ���� �������� ���·� ����
			_isSelectMode = true;

			// ��ư05�� Ÿ�� ����
			PickedMouseBlockType = Block::BLOCK_DOOR_CLOSE;

			cout << "������ ��ư Ŭ��\n";
			cout << "���� ���õ� ��� = " << static_cast<int>(PickedMouseBlockType) << "\n";
		}

	}

	/// �������̾��� �� ��������
	else
	{
		// ���콺�� ��ǥ�� �迭 ��ҷ� ���ø� �Ѵ�
		int CurMouseX = _ptMouse.x / TILESIZE;
		int CurMouseY = _ptMouse.y / TILESIZE;

		/// ���� ���忡�� ���� ������ ���� Ÿ���� ���´�.
		/// �Ʒ� �� ������ �ٸ��� �м� �ʿ�
		Block temp = m_pMap->GetType(CurMouseX, CurMouseY);

		cout << "Ŭ���� ���� ��� Ÿ���� -> " << static_cast<int>(temp) << "\n\n";

		// Ŭ���� ���� ����ִ� Ÿ��(EMPTY)�̸�
		if (temp == Block::BLOCK_EMPTY)
		{
			// ���� ���� ����� Ÿ���� 1ĭ¥�� ����̸�
			if (PickedMouseBlockType == Block::BLOCK_WOOD)
			{
				// �� Ÿ��(ĭ)�� ��ĭ¥�� ����� �ִ´�.
				m_pMap->SetType(CurMouseX, CurMouseY, Block::BLOCK_WOOD);


				printf("��ġ ��ġ = [%d,%d] / ��ġ Ÿ�� = [%d]\n\n", CurMouseX, CurMouseY, Block::BLOCK_WOOD);

				// �ٽ� �ƹ� ��(���)�� ��� ���� �ʴ� ���·� ����
				PickedMouseBlockType = Block::BLOCK_MOUSEEMPTY;
			}

			// ���� ���� ����� Ÿ���� 5ĭ¥�� ����̸�
			if (PickedMouseBlockType == Block::BLOCK_WOOD_L && (g_stageNum == 0 || g_stageNum == 1))
			{
				/// ������ ĭ���� ���������� 5ĭ�� Ÿ���� �˾ƿͼ� ��ġ�������� �Ǵ��Ѵ�
				for (int x = CurMouseX; x < CurMouseX + 5; x++)
				{
					if (m_pMap->GetType(x, CurMouseY) != Block::BLOCK_EMPTY)
					{
						cout << "�� ������ ��ġ �� �� ����!\n\n";
						return;
					}
				}

				/// ��ġ�� �� �ִٰ� �Ǵ� �Ǹ�
				// �� ���� ��� ��ġ(L, M, M, M, R)
				m_pMap->SetType(CurMouseX + 0, CurMouseY, Block::BLOCK_WOOD_L);
				m_pMap->SetType(CurMouseX + 1, CurMouseY, Block::BLOCK_WOOD_M);
				m_pMap->SetType(CurMouseX + 2, CurMouseY, Block::BLOCK_WOOD_M);
				m_pMap->SetType(CurMouseX + 3, CurMouseY, Block::BLOCK_WOOD_M);
				m_pMap->SetType(CurMouseX + 4, CurMouseY, Block::BLOCK_WOOD_R);
				
				printf("��ġ ��ġ = [%d,%d] / ��ġ Ÿ�� = [%d]\n\n", CurMouseX + 0, CurMouseY, Block::BLOCK_WOOD_L);
				printf("��ġ ��ġ = [%d,%d] / ��ġ Ÿ�� = [%d]\n\n", CurMouseX + 1, CurMouseY, Block::BLOCK_WOOD_M);
				printf("��ġ ��ġ = [%d,%d] / ��ġ Ÿ�� = [%d]\n\n", CurMouseX + 2, CurMouseY, Block::BLOCK_WOOD_M);
				printf("��ġ ��ġ = [%d,%d] / ��ġ Ÿ�� = [%d]\n\n", CurMouseX + 3, CurMouseY, Block::BLOCK_WOOD_M);
				printf("��ġ ��ġ = [%d,%d] / ��ġ Ÿ�� = [%d]\n\n", CurMouseX + 4, CurMouseY, Block::BLOCK_WOOD_R);

				// �ٽ� �ƹ� ��(���)�� ��� ���� �ʴ� ���·� ����
				PickedMouseBlockType = Block::BLOCK_MOUSEEMPTY;
			}

			// ���� ���� ����� Ÿ���� 3ĭ¥�� ����̸�
			// �������� 2, 3 �� 3ĭ���� ó��
			if (PickedMouseBlockType == Block::BLOCK_WOOD_L && ( g_stageNum == 2 || g_stageNum == 3))
			{
				/// ������ ĭ���� ���������� 3ĭ�� Ÿ���� �˾ƿͼ� ��ġ�������� �Ǵ��Ѵ�
				for (int x = CurMouseX; x < CurMouseX + 3; x++)
				{
					if (m_pMap->GetType(x, CurMouseY) != Block::BLOCK_EMPTY)
					{
						cout << "�� ������ ��ġ �� �� ����!\n\n";
						return;
					}
				}

				/// ��ġ�� �� �ִٰ� �Ǵ� �Ǹ�
				// �� ���� ��� ��ġ(L, M, M, M, R)
				m_pMap->SetType(CurMouseX + 0, CurMouseY, Block::BLOCK_WOOD_L);
				m_pMap->SetType(CurMouseX + 1, CurMouseY, Block::BLOCK_WOOD_M);
				m_pMap->SetType(CurMouseX + 2, CurMouseY, Block::BLOCK_WOOD_R);

				printf("��ġ ��ġ = [%d,%d] / ��ġ Ÿ�� = [%d]\n\n", CurMouseX + 0, CurMouseY, Block::BLOCK_WOOD_L);
				printf("��ġ ��ġ = [%d,%d] / ��ġ Ÿ�� = [%d]\n\n", CurMouseX + 1, CurMouseY, Block::BLOCK_WOOD_M);
				printf("��ġ ��ġ = [%d,%d] / ��ġ Ÿ�� = [%d]\n\n", CurMouseX + 2, CurMouseY, Block::BLOCK_WOOD_R);

				// �ٽ� �ƹ� ��(���)�� ��� ���� �ʴ� ���·� ����
				PickedMouseBlockType = Block::BLOCK_MOUSEEMPTY;
			}

			// ���� ���� ����� Ÿ���� ������ ����̸�
			if (PickedMouseBlockType == Block::BLOCK_SPRING)
			{
				// ������ ����� ��� �ְ� 
				// 1ĭ �Ʒ��� ���� �����鼭
				// 1ĭ �Ʒ��� �������� �ƴ� ��
				if (m_pMap->GetType(CurMouseX, CurMouseY) == Block::BLOCK_EMPTY &&
					m_pMap->GetType(CurMouseX, CurMouseY + 1) != Block::BLOCK_EMPTY &&
					m_pMap->GetType(CurMouseX, CurMouseY + 1) != Block::BLOCK_SPRING)
				{
					// �� Ÿ��(ĭ)�� ������ ����� �ִ´�.
					m_pMap->SetType(CurMouseX, CurMouseY, Block::BLOCK_SPRING);

					printf("��ġ ��ġ = [%d,%d] / ��ġ Ÿ�� = [%d]\n\n", CurMouseX, CurMouseY, Block::BLOCK_SPRING);

					// �ٽ� �ƹ� ��(���)�� ��� ���� �ʴ� ���·� ����
					PickedMouseBlockType = Block::BLOCK_MOUSEEMPTY;
				}
				else
				{
					cout << "�� ������ ��ġ �� �� ����!\n\n";
					return;
				}
			}

			// ���� ���� ����� Ÿ���� ����(Ű) ����̸�
			if (PickedMouseBlockType == Block::BLOCK_KEY)
			{
				// �� Ÿ��(ĭ)�� ����(Ű) ����� �ִ´�.
				m_pMap->SetType(CurMouseX, CurMouseY, Block::BLOCK_KEY);


				printf("��ġ ��ġ = [%d,%d] / ��ġ Ÿ�� = [%d]\n\n", CurMouseX, CurMouseY, Block::BLOCK_KEY);

				// �ٽ� �ƹ� ��(���)�� ��� ���� �ʴ� ���·� ����
				PickedMouseBlockType = Block::BLOCK_MOUSEEMPTY;
			}

			// ���� ���� ����� Ÿ���� ���� (��) ����̸�
			if (PickedMouseBlockType == Block::BLOCK_DOOR_CLOSE)
			{
				for (int y = CurMouseY; y < CurMouseY + 3; y++)
				{
					for (int x = CurMouseX; x < CurMouseX + 2; x++)
					{
						if (m_pMap->GetType(x, y) != Block::BLOCK_EMPTY)
						{
							cout << "�װ����� ���� ��ġ �� �� ����\n\n";
							return;
						}
					}
				}

				// ������ ���� ���� �ϰ�
				for (int y = 0; y < MAPSIZE_Y; y++)
				{
					for (int x = 0; x < MAPSIZE_X; x++)
					{
						if (m_pMap->GetType(x, y) == Block::BLOCK_DOOR_CLOSE)
						{
							m_pMap->SetType(x, y, Block::BLOCK_EMPTY);
						}
					}
				}

				// ����(2) * ����(3) ĭ�� ���� (��) ����� �ִ´�.
				m_pMap->SetType(CurMouseX + 0, CurMouseY + 0, Block::BLOCK_DOOR_CLOSE);
				m_pMap->SetType(CurMouseX + 1, CurMouseY + 0, Block::BLOCK_DOOR_CLOSE);
				m_pMap->SetType(CurMouseX + 0, CurMouseY + 1, Block::BLOCK_DOOR_CLOSE);
				m_pMap->SetType(CurMouseX + 1, CurMouseY + 1, Block::BLOCK_DOOR_CLOSE);
				m_pMap->SetType(CurMouseX + 0, CurMouseY + 2, Block::BLOCK_DOOR_CLOSE);
				m_pMap->SetType(CurMouseX + 1, CurMouseY + 2, Block::BLOCK_DOOR_CLOSE);

				printf("��ġ ��ġ = [%d,%d] / ��ġ Ÿ�� = [%d]\n\n", CurMouseX, CurMouseY, Block::BLOCK_KEY);

				// �ٽ� �ƹ� ��(���)�� ��� ���� �ʴ� ���·� ����
				PickedMouseBlockType = Block::BLOCK_MOUSEEMPTY;
			}

			_isSelectMode = false;
			cout << "���ø�� ����~~~~\n\n";
		}

		/// ���ø�� �߿� �� ĭ�� �ƴ� ���� Ŭ���ؼ� ��ġ�� �Ұ����� ���
		else
		{
			cout << "��ġ �Ұ�(��� ���ø��) \n";
		}

	}
}

void Scene05_Ingame::RenderTile()
{
	bool isDrawDoor = false;	// fals�� ���� �׸� 2 * 3 , true�� �� �׸�

	Block checkBlockType = Block::BLOCK_EMPTY;
	int renderPosX = 0;
	int renderPosY = 0;

	for (int y = 0; y < MAPSIZE_Y; y++)
	{
		for (int x = 0; x < MAPSIZE_X; x++)
		{
			checkBlockType = m_pMap->GetType(x, y);
			renderPosX = m_pMap->GetBox(x, y).left;
			renderPosY = m_pMap->GetBox(x, y).top;

			// ��ġ���̸� ���� ���� �̹����� �׸�
			if (_gameState == Game_State::Edit)
			{
				switch (checkBlockType)
				{
					// ���� Ÿ���� ����ִ� ���̸�
					case Block::BLOCK_EMPTY:
					{
						// �ƹ��͵� �� �׸�
						break;
					}

					case Block::BLOCK_KEY:
					{
						_imgKey_R->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}
					case Block::BLOCK_DOOR_CLOSE:
					{
						// ���� �׸��� �ʾ��� ���� �׸�
						if (!isDrawDoor)
						{
							_imgDoorClose_R->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);
							isDrawDoor = true;
						}
						break;
					}
					case Block::BLOCK_DOOR_OPEN:
					{
						// ���� �׸��� �ʾ��� ���� �׸�
						if (!isDrawDoor)
						{
							_imgDoorOpen_R->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);
							isDrawDoor = true;
						}
						break;
					}

					case Block::BLOCK_SPRING:
					{
						_imgSpring_R->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_FRUIT:
					{
						_imgFruit->FrameRender(g_backBuffer->GetMemDC(), renderPosX-70, renderPosY);

						break;
					}

					case Block::BLOCK_WATER:
					{
						_imgWater_R->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);
						break;
					}

					case Block::BLOCK_UWATER:
					{
						_imgUWater_R->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_UNDERGROUND02:
					{
						_imgUnderGround02_R->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_UNDERGROUND03:
					{
						_imgUnderGround03_R->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_WOOD:
					{
						_imgWood_R->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_WOOD_L:
					{
						_imgWoodL_R->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_WOOD_M:
					{
						_imgWoodM_R->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_WOOD_R:
					{
						_imgWoodR_R->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_GRASS_02:
					{
						_imgGrass02_R->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_GRASS_03:
					{
						_imgGrass03_R->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_GRASS_L:
					{
						_imgGrassL_R->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_GRASS_L2:
					{
						_imgGrassL2_R->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_GRASS_R:
					{
						_imgGrassR_R->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_GRASS_R2:
					{
						_imgGrassR2_R->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}
				}// end of Switch
			}

			// ��ġ���� �ƴϸ� �Ϲ� ���� �̹����� �׸�
			else
			{
				switch (checkBlockType)
				{
					// ���� Ÿ���� ����ִ� ���̸�
					case Block::BLOCK_EMPTY:
					{
						// �ƹ��͵� �� �׸�
						break;
					}

					case Block::BLOCK_UNDERGROUND02:
					{
						_imgUnderGround02->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_UNDERGROUND03:
					{
						_imgUnderGround03->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_KEY:
					{
						_imgKey->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}
					case Block::BLOCK_DOOR_CLOSE:
					{
						// ���� �׸��� �ʾ��� ���� �׸�
						if (!isDrawDoor)
						{
							_imgDoorClose->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);
							isDrawDoor = true;
						}
						break;
					}
					case Block::BLOCK_DOOR_OPEN:
					{
						// ���� �׸��� �ʾ��� ���� �׸�
						if (!isDrawDoor)
						{
							_imgDoorOpen->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);
							isDrawDoor = true;
						}
						break;
					}

					case Block::BLOCK_SPRING:
					{
						_imgSpring->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_WOOD:
					{
						_imgWood->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_WOOD_L:
					{
						_imgWoodL->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_WOOD_M:
					{
						_imgWoodM->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_WOOD_R:
					{
						_imgWoodR->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_FRUIT:
					{
						_imgFruit->FrameRender(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_WATER:
					{
						_imgWater->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);
						break;
					}

					case Block::BLOCK_UWATER:
					{
						_imgUWater->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_GRASS_02:
					{
						_imgGrass02->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_GRASS_03:
					{
						_imgGrass03->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_GRASS_L:
					{
						_imgGrassL->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_GRASS_L2:
					{
						_imgGrassL2->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_GRASS_R:
					{
						_imgGrassR->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_GRASS_R2:
					{
						_imgGrassR2->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}
					
					case Block::BLOCK_ROCK_01:
					{
						_imgRock01->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}
					
					case Block::BLOCK_ROCK_02:
					{
						_imgRock02->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_BUSH_01:
					{
						_imgBush01->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}

					case Block::BLOCK_BUSH_02:
					{
						_imgBush02->Render(g_backBuffer->GetMemDC(), renderPosX, renderPosY);

						break;
					}
				}// end of Switch
			}			
		}
	}
}

void Scene05_Ingame::RenderUI()
{
	// ���� UI ����
	_imgBackBoard->Render(g_backBuffer->GetMemDC(), _imgBackBoard->GetX(), _imgBackBoard->GetY());
	_imgReset->Render(g_backBuffer->GetMemDC(), _imgReset->GetX(), _imgReset->GetY());
	_imgGoBack->Render(g_backBuffer->GetMemDC(), _imgGoBack->GetX(), _imgGoBack->GetY());

	// �������� 00(�� ��) ��ư ����
	if (g_stageNum == 0)
	{
		_imgWood->Render(g_backBuffer->GetMemDC(), _imgWood->GetX(), _imgWood->GetY());

		_imgWoodL->Render(g_backBuffer->GetMemDC(), _imgWoodL->GetX(), _imgWoodL->GetY());
		_imgWoodM->Render(g_backBuffer->GetMemDC(), _imgWoodM->GetX(), _imgWoodM->GetY());
		_imgWoodM->Render(g_backBuffer->GetMemDC(), _imgWoodM->GetX() + 70, _imgWoodM->GetY());
		_imgWoodM->Render(g_backBuffer->GetMemDC(), _imgWoodM->GetX() + 140, _imgWoodM->GetY());
		_imgWoodR->Render(g_backBuffer->GetMemDC(), _imgWoodR->GetX(), _imgWoodL->GetY());

		_imgSpring->Render(g_backBuffer->GetMemDC(), _imgSpring->GetX(), _imgSpring->GetY());
		_imgKey->Render(g_backBuffer->GetMemDC(), _imgKey->GetX(), _imgKey->GetY());
		_imgDoorClose->Render(g_backBuffer->GetMemDC(), _imgDoorClose->GetX(), _imgDoorClose->GetY());
	}

	// �������� 01 ��ư ����
	if (g_stageNum == 1)
	{
		_imgWood->Render(g_backBuffer->GetMemDC(), _imgWood->GetX(), _imgWood->GetY());

		_imgWoodL->Render(g_backBuffer->GetMemDC(), _imgWoodL->GetX(), _imgWoodL->GetY());
		_imgWoodM->Render(g_backBuffer->GetMemDC(), _imgWoodM->GetX(), _imgWoodM->GetY());
		_imgWoodM->Render(g_backBuffer->GetMemDC(), _imgWoodM->GetX() + 70, _imgWoodM->GetY());
		_imgWoodM->Render(g_backBuffer->GetMemDC(), _imgWoodM->GetX() + 140, _imgWoodM->GetY());
		_imgWoodR->Render(g_backBuffer->GetMemDC(), _imgWoodR->GetX(), _imgWoodR->GetY());
	}

	// �������� 02 ��ư ����
	if (g_stageNum == 2)
	{
		_imgWood->Render(g_backBuffer->GetMemDC(), _imgWood->GetX(), _imgWood->GetY());

		_imgWoodL->Render(g_backBuffer->GetMemDC(), _imgWoodL->GetX(), _imgWoodL->GetY());
		_imgWoodM->Render(g_backBuffer->GetMemDC(), _imgWoodM->GetX(), _imgWoodM->GetY());
		_imgWoodR->Render(g_backBuffer->GetMemDC(), _imgWoodR->GetX(), _imgWoodR->GetY());
	}

	// �������� 03 ��ư ����
	if (g_stageNum == 3)
	{
		_imgSpring->Render(g_backBuffer->GetMemDC(), _imgSpring->GetX(), _imgSpring->GetY());

		_imgWoodL->Render(g_backBuffer->GetMemDC(), _imgWoodL->GetX(), _imgWoodL->GetY());
		_imgWoodM->Render(g_backBuffer->GetMemDC(), _imgWoodM->GetX(), _imgWoodM->GetY());
		_imgWoodR->Render(g_backBuffer->GetMemDC(), _imgWoodR->GetX(), _imgWoodR->GetY());
	}
}

void Scene05_Ingame::ResetStage()
{
	cout << "�������� �ʱ�ȭ!!\n\n";

	// �������� �ʱ�ȭ
	this->Init();

	//  ī�޶� ��ġ ����
	_cameraX = _player->m_PosX - (WINSIZEX / 2);
	_cameraY = _player->m_PosY - (WINSIZEY / 2);


}
