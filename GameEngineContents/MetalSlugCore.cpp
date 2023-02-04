#include "StudyGameCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>

#include "PlayLevel.h"
#include "TitleLevel.h"
#include "SelectLevel.h"

MetalSlugCore MetalSlugCore::Core;

MetalSlugCore::MetalSlugCore() 
{
}

MetalSlugCore::~MetalSlugCore() 
{
}

void MetalSlugCore::Start()
{
	
	GameEngineWindow::SettingWindowSize({960.0f, 800.0f});

	new int();

	CreateLevel<TitleLevel>("TitleLevel");
	CreateLevel<SelectLevel>("SelectLevel");
	CreateLevel<PlayLevel>("PlayLevel");
	ChangeLevel("TitleLevel");

	
}

void MetalSlugCore::Update()
{
	
}
void MetalSlugCore::End() 
{
	
}