#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "BossSmallMonster.h"
enum class BossState
{

	IDLE,
	SMOKEPRE,
	SMOKE,
	ATTACKPRE,
	ATTACK,


};

// ���� :
class Boss : public GameEngineActor
{
public:
	static Boss* boss;

	// constrcuter destructer
	Boss();
	~Boss();
	// delete Function
	Boss(const Boss& _Other) = delete;
	Boss(Boss&& _Other) noexcept = delete;
	Boss& operator=(const Boss& _Other) = delete;
	Boss& operator=(Boss&& _Other) noexcept = delete;

	void Movecalculation(float _DeltaTime);
	//void DirCheck(const std::string_view& _AnimationName);

	void UpdateState(float _Time);
	void ChangeState(BossState _State);

	

	void IdleStart();
	void IdleUpdate(float _Time);

	void SmokePreStart();
	void SmokePreUpdate(float _Time);

	void SmokeStart();
	void SmokeUpdate(float _Time);

	void AttackPreStart();
	void AttackPreUpdate(float _Time);

	void AttackStart();
	void AttackUpdate(float _Time);

	void AnimationCheck();


	bool GetAttackCheck()
	{
		return AttackCheck;
	}

	GameEngineCollision* MonsterCollision = nullptr;
	float4 MoveDir = float4::Zero;
protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	BossState StateValue = BossState::IDLE;

	GameEngineRender* Mainbody = nullptr;

	GameEngineRender* LeftWing = nullptr;
	GameEngineRender* RightWing = nullptr;

	GameEngineRender* LeftGroundEffect = nullptr;
	GameEngineRender* RightGroundEffect = nullptr;

	GameEngineRender* LeftBoom = nullptr;
	GameEngineRender* RightBoom = nullptr;

	GameEngineRender* LeftEngine = nullptr;
	GameEngineRender* RightEngine = nullptr;


	
	float4 MoveDirGroundEffect = float4::Zero;
	float MoveTime = 0;
	float ads = 0;
	float ChangeTime = 0; 
	int a = 0;
	float AttackPreTime = 0; 
	float Hp = 100; 
	float Time = 0; 
	float MonsterTime = 0; 
	bool AttackCheck = false;
	BossSmallMonster* SmallMonster = nullptr;
	bool LeftRightCheck = false;
	bool Idle = false;

	

};


