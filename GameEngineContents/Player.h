#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class PlayerState
{
	IDLE,
	MOVE,
	JUMPDOWN,
	JUMPUP,
	JUMPMOVEDOWN,
	JUMPMOVEUP,
	UP,
	UPMOVE,
	UPJUMPMOVE,
	DOWN,
	IDLEDOWN,
	IDLEATTACK,
	MOVEATTACK,
	JUMPUPATTACK,
	JUMPDOWNATTACK,
	JUMPMOVEDOWNATTACK,
	JUMPMOVEUPATTACK,
	UPRIGHTATTACK,
	UPATTACK,
	UPMOVEATTACK,
	UPJUMPATTACK,
	UPJUMPDOWNATTACK,
	UPJUMPMOVEATTACK,
	UPJUMPMOVEDOWNATTACK,
	THROW,
	THROWMOVE
};

// 설명 :
class Player : public GameEngineActor
{
public:
	static Player* MainPlayer;

	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;
	void RightSetBody(float4 reg)
	{
		this->body.x = reg.x + 11;
		this->body.y = reg.y - 35;
		
	}
	void LeftSetBody(float4 reg)
	{
		this->body.x = reg.x - 11;
		this->body.y = reg.y - 35;
	}
	float4 GetCameraDir()
	{
		return CameraDir; 
	}

	bool test23 = false;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;
	

private:
	bool a = true;
	
	float AccTime = 0.0f;
	int StartFrame = 0;
	float MoveSpeed = 300.0f;
	float JumpSpeed = 800.0f;
	std::string DirString = "Right_";
	PlayerState StateValue = PlayerState::IDLE;
	float4 MoveDir = float4::Zero;
	float4 MoveDir1 = float4::Zero;
	float4 CameraDir = float4::Zero;
	int d = 0;
	GameEngineRender* AnimationBodyRender = nullptr;
	GameEngineRender* AnimationRegRender = nullptr;
	GameEngineCollision* BodyCollision = nullptr;
	GameEngineCollision* BackGroundCollision = nullptr;
	void DirCheck(const std::string_view& _AnimationName);
	void DirCheck(const std::string_view& _AnimationName, const std::string_view& _AnimationName1);
	void  JumpDirCheck(const std::string_view& _AnimationName, const std::string_view& _AnimationName1);
	
	// State
    //void CameraCheck(); 
	void ChangeState(PlayerState _State);
	void UpdateState(float _Time);
	void Movecalculation(float _DeltaTime);
	// FSM 내가 어떤일을 할때 이동하면서 가만히 있을수 없다.
	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void UpStart();
	void UpMoveStart();
	void UpAttackStart(); 
	void UpMoveAttackStart();
	void UpJumpAttackStart();
	void UpJumpDownAttackStart(); 
	void UpJumpMoveAttackStart();
	void UpJumpMoveDownAttackStart(); 

	void UpUpdate(float _Time);
	void UpMoveUpdate(float _Time);
	void UpMoveAttackUpdate(float _Time);
	void UpAttackJumpMoveUpdate(float _Time);
	
	
	void JumpUpStart();
	void JumpDownStart();
	void JumpMoveUpStart(); 
	void JumpMoveDownStart();
	void JumpUpdate(float _Time);
	void JumpMoveUpdate(float _Time);
	void test2(float _Time);

	void MoveStart();
	void MoveUpdate(float _Time);
	void MoveEnd();

	void DownStart();
	void DownIdleStart(); 

	void AttackStart(); 
	void AttackMoveStart(); 
	void AttackJumpUpStart();
	void AttackJumpDownStart();
	void AttackJumpMoveUpStart();
	void AttackJumpMoveDownStart();
	

	void AttackIdleUpdate(float _Time);
	void AttackMoveUpdate(float _Time);
	void AttackJumpUpdate(float _Time);
	void AttackJumpMoveUpdate(float _Time);
	 
	void ThrowStart();
	void ThrowMoveStart();

	void ThrowUpdate(float _Time);
	void ThrowMoveUpdate(float _Time);

	float TimeCheck = 0;
	bool test = false;
	bool test1 = false;
	float4 body = { 0,0 };
	float4 Reg = { 0,0 };
	float4 gravity = float4::Zero;
	
	bool CameraCheck = false;
	float4 PosCheck = { 0,0 }; 
	
	
};

