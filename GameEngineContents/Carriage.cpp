#include "Carriage.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase/GameEngineTime.h>
#include "ContentsEnums.h"
#include "Player.h"

Carriage::Carriage()
{

}

Carriage::~Carriage()
{

}
void Carriage::Start()
{
	{
		AnimationRender = CreateRender(MetalSlugOrder::NPC);
		AnimationRender->SetScale({ 800,800 });

		AnimationRender->CreateAnimation({ .AnimationName = "Carriage",  .ImageName = "Carriage.bmp", .Start = 0, .End = 11, .InterTime = 0.5f,.Loop = true });
		AnimationRender->CreateAnimation({ .AnimationName = "CarriageDestory",  .ImageName = "CarriageDestory.bmp", .Start = 0, .End = 5, .InterTime = 0.1f ,.Loop = false });
		AnimationRender->CreateAnimation({ .AnimationName = "CarriageMove",  .ImageName = "CarriageMove.bmp", .Start = 0, .End = 3, .InterTime = 0.1f,.Loop = true });
	}

	{
		Exploision = CreateRender(MetalSlugOrder::Exploision);
		Exploision->SetScale({ 700,700 });
		Exploision->SetPosition({ 112,-290 });
		Exploision->CreateAnimation({ .AnimationName = "Exploision",  .ImageName = "MiddleExploision.bmp", .Start = 0, .End = 25, .InterTime = 0.05f,.Loop = false });
	}

	Exploision->ChangeAnimation("Exploision"); 
	Exploision->Off(); 


	ChangeState(CarriageState::IDLE); 

	{
		MonsterCollision = CreateCollision(MetalSlugOrder::NPC);
		MonsterCollision->SetScale({ 300,100 });
	}


}






void Carriage::Movecalculation(float _DeltaTime)
{

	MoveDir += float4::Down * 1500.0f * _DeltaTime;

	if (50.0f <= abs(MoveDir.x))
	{
		if (0 > MoveDir.x)
		{
			MoveDir.x = -200.0f;
		}
		else
		{
			MoveDir.x = 200.0f;
		}
	}

	//if (450.0f <= abs(MoveDir.x))
	//{
	//	if (0 > MoveDir.x)
	//	{
	//		MoveDir.x = -450.0f;
	//	}
	//	else
	//	{
	//		MoveDir.x = 450.0f;
	//	}
	//}




	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("Map11.BMP");

	if (nullptr == ColImage)
	{
		MsgAssert("�浹�� �� �̹����� �����ϴ�.");
	}

	bool Check = true;
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;





	if ((RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)) || RGB(0, 250, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 250, 0))))
	{
		

		Check = false;
	}




	if (false == Check)
	{
		while (true)
		{
			MoveDir.y -= 1;
			float4 NextPos = GetPos() + MoveDir * _DeltaTime;
			if ((RGB(0, 255, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 255, 0)) || RGB(0, 250, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 250, 0))))
			{
				continue;
			}

			if (50.0f <= abs(MoveDir.y))
			{
				if (0 > MoveDir.y)
				{
					MoveDir.y = -100.0f;
				}
				else
				{
					MoveDir.y = 0.0f;
				}
			}
			Check = true;
			break;
		}
	}

	SetMove(MoveDir * _DeltaTime);


}

void Carriage::DirCheck(const std::string_view& _AnimationName)
{
	AnimationRender->ChangeAnimation(_AnimationName);
}




void Carriage::Update(float _DeltaTime)
{

	if (nullptr != MonsterCollision && StateValue == CarriageState::STOP)
	{
		std::vector<GameEngineCollision*> collision;
		if (true == MonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::Bullet), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{
			Exploision->On(); 
			ChangeState(CarriageState::DEATH);

		}
	}
	if (nullptr != MonsterCollision )
	{
		std::vector<GameEngineCollision*> collision;
		if (true == MonsterCollision->Collision({ .TargetGroup = static_cast<int>(MetalSlugOrder::PlayerReg), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, collision))
		{
			
			Player::MainPlayer->SetMove({ -2,0 });

			if (GetPos().y < Player::MainPlayer->GetPos().y)
			{
				Player::MainPlayer->SetMove({ 2,-2 });
			}
	
		}
	}


	Movecalculation(_DeltaTime);

	UpdateState(_DeltaTime);
}

void Carriage::Render(float _Time)
{
	MonsterCollision->DebugRender();

}