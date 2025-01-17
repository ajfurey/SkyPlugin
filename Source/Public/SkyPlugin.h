// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "SkyManager.h"

DECLARE_LOG_CATEGORY_EXTERN(SkyPlugin, Log, All);

class FSkyPlugin : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void EnforceSingletonActor(UWorld* World);
	ASkyManager* SpawnSingletonActor(UWorld* World);
	void InitSingletonActor(UWorld* World, const UWorld::InitializationValues IVS);

	ASkyManager* GetSingletonActor(UObject* WorldContextObject);

	/**
	* Singleton-like access to this module's interface.  This is just for convenience!
	* Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	*
	* @return Returns singleton instance, loading the module on demand if needed
	*/
	static inline FSkyPlugin& Get()
	{
		return FModuleManager::LoadModuleChecked< FSkyPlugin >("SkyPlugin");
	}

	/**
	* Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	*
	* @return True if the module is loaded and ready to use
	*/
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("SkyPlugin");
	}
};
