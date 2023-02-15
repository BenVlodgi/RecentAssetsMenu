﻿// Copyright 2023 Naotsun. All Rights Reserved.

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "RecentAssetsMenu/RecentAssetsMenuGlobals.h"
#include "RecentAssetsMenu/CommandActions/RecentAssetsMenuCommands.h"
#include "RecentAssetsMenu/UIExtensions/ToolMenuExtender.h"

DEFINE_LOG_CATEGORY(LogRecentAssetsMenu);

namespace RecentAssetsMenu
{
	class FRecentAssetsMenuModule : public IModuleInterface
	{
	public:
		// IModuleInterface interface.
		virtual void StartupModule() override;
		virtual void ShutdownModule() override;
		// End of IModuleInterface interface.
	};

	void FRecentAssetsMenuModule::StartupModule()
	{
		// Register command actions.
		FRecentAssetsMenuCommands::Register();
		FRecentAssetsMenuCommands::Bind();
		
		// Register tool menu extension.
		FToolMenuExtender::Register();
	}

	void FRecentAssetsMenuModule::ShutdownModule()
	{
		// Unregister command actions.
		FRecentAssetsMenuCommands::Unregister();
	}
}

IMPLEMENT_MODULE(RecentAssetsMenu::FRecentAssetsMenuModule, RecentAssetsMenu)
