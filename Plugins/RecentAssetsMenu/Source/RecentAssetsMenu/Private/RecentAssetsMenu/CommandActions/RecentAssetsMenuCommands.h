﻿// Copyright 2023 Naotsun. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "Framework/Commands/UICommandList.h"
#include "Framework/Commands/UICommandInfo.h"

class FMenuBuilder;

namespace RecentAssetsMenu
{
	/**
	 * Class to register the shortcut key used in this plugin.
	 */
	class RECENTASSETSMENU_API FRecentAssetsMenuCommands : public TCommands<FRecentAssetsMenuCommands>
	{
	public:
		// Constructor.
		FRecentAssetsMenuCommands();

		// TCommands interface.
		virtual void RegisterCommands() override;
		// End of TCommands interface.

		// Is the command registered here bound.
		static bool IsBound();

		// Processing of command binding.
		static void Bind();
		
	protected:
		// Internal processing of command binding.
		virtual void BindCommands();

	public:
		// A list of shortcut keys used by this plugin.
		TSharedRef<FUICommandList> CommandBindings;
		
		// Instances of bound commands.
		static constexpr int32 MaxRecentAssets = 10;
		static const FName OpenRecentAssetBundle;
		TArray<TSharedPtr<FUICommandInfo>> OpenRecentAssetCommands;
		TSharedPtr<FUICommandInfo> ClearRecentAssetsCommand;

	private:
		// Is the command registered here bound.
		bool bIsBound;
	};
}
